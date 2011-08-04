#include <aros/atomic.h>
#include <asm/io.h>
#include <exec/execbase.h>
#include <exec/memory.h>
#include <proto/exec.h>

#include "kernel_base.h"
#include "kernel_debug.h"
#include "kernel_intern.h"
#include "kernel_syscall.h"
#include "apic.h"
#include "smp.h"

#define D(x) x

extern const void *_binary_smpbootstrap_start;
extern const void *_binary_smpbootstrap_size;

static void smp_Entry(IPTR stackBase, UBYTE *apicready)
{
    /*
     * This is the entry point for secondary cores.
     * KernelBase is already set up by the primary CPU, so we can use it.
     */
    IPTR _APICBase;
    UWORD _APICID;
    UBYTE _APICNO;

    /* Enable fxsave/fxrstor */ 
    wrcr(cr4, rdcr(cr4) | _CR4_OSFXSR | _CR4_OSXMMEXCPT);
     
    _APICBase = core_APIC_GetBase(KernelBase->kb_PlatformData);
    _APICID  = core_APIC_GetID(KernelBase->kb_PlatformData, _APICBase);
    _APICNO  = core_APICGetNumber(KernelBase->kb_PlatformData);

    D(bug("[Kernel] smp_Entry[%d]: launching on AP APIC ID %d, base @ %p\n", _APICID, _APICID, _APICBase));
    D(bug("[Kernel] smp_Entry[%d]: KernelBootPrivate 0x%p, stack base 0x%p\n", _APICID, __KernBootPrivate, stackBase));

    /* Set up GDT and LDT for our core */
    core_CPUSetup(_APICID, stackBase);

    bug("[Kernel] APIC No. %d of %d Going IDLE (Halting)...\n", _APICNO, KernelBase->kb_PlatformData->kb_APIC_Count);

    /* Signal the bootstrap core that we are running */
    *apicready = 1;

    /*
     * Unfortunately at the moment we have nothing more to do.
     * The rest of AROS is not SMP-capable. :-(
     */
    while (1) asm volatile("hlt");
}

int smp_Setup(IPTR num)
{
    struct PlatformData *pdata = KernelBase->kb_PlatformData;
    /* Low memory header is in the tail of memory list - see kernel_startup.c */
    struct MemHeader *lowmem = (struct MemHeader *)SysBase->MemList.lh_TailPred;
    UWORD *idmap;
    IPTR *basemap;
    APTR smpboot;
    struct SMPBootstrap *bs;

    D(bug("[SMP] Setup for %lu cores\n", num));

    idmap = AllocMem(num * sizeof(UWORD), MEMF_CLEAR);
    if (!idmap)
    	return 0;

    basemap = AllocMem(num * sizeof(IPTR), MEMF_CLEAR);
    if (!basemap)
    	return 0;

    D(bug("[SMP] Allocated IDMap @ %p, BaseMap @ %p\n", idmap, basemap));

    /*
     * Allocate space for SMP bootstrap code in low memory. Its address must be page-aligned.
     * Every CPU starts up in real mode (DAMN CRAP!!!)
     */
    smpboot = Allocate(lowmem, (unsigned long)&_binary_smpbootstrap_size + PAGE_SIZE - 1);
    if (!smpboot)
    {
    	D(bug("[SMP] Failed to allocate space for SMP bootstrap\n"));
    	return 0;
    }

    /* Old maps have only one entry - for boot CPU */
    idmap[0]   = pdata->kb_APIC_IDMap[0];
    basemap[0] = pdata->kb_APIC_BaseMap[0];

    /* Replace maps */
    FreeMem(pdata->kb_APIC_IDMap, sizeof(UWORD));
    FreeMem(pdata->kb_APIC_BaseMap, sizeof(IPTR));

    pdata->kb_APIC_IDMap   = idmap;
    pdata->kb_APIC_BaseMap = basemap;

    /* Install SMP bootstrap code */
    bs = (APTR)AROS_ROUNDUP2((IPTR)smpboot, PAGE_SIZE);
    CopyMem(&_binary_smpbootstrap_start, bs, (unsigned long)&_binary_smpbootstrap_size);
    pdata->kb_APIC_TrampolineBase = bs;

    D(bug("[SMP] Copied APIC bootstrap code to %p\n", bs));

    /* Store constant arguments in bootstrap's data area */
    bs->PML4 = (unsigned long)__KernBootPrivate->PML4;
    bs->IP   = smp_Entry;

    /* 40:67 set to pdata->kb_APIC_TrampolineBase so that APIC recieves it in CS:IP */
/*  D(bug("[SMP] Setting vector for trampoline @ %p ..\n", pdata->kb_APIC_TrampolineBase));
    *((volatile unsigned short *)0x469) = (IPTR)bs >> 4;
    *((volatile unsigned short *)0x467) = (IPTR)bs & 0xf;*/

    return 1;
}

/*
 * Here we wake up our secondary cores.
 */
int smp_Wake(void)
{
    struct PlatformData *pdata = KernelBase->kb_PlatformData;
    struct SMPBootstrap *bs = pdata->kb_APIC_TrampolineBase;
    APTR _APICStackBase;
    IPTR wakeresult;
    UBYTE i;
    volatile UBYTE apicready;

    /* Core number 0 is our bootstrap core, so we start from No 1 */
    for (i = 1; i < pdata->kb_APIC_Count; i++)
    {
	/* Less significant byte of our IDMap entry holds logical ID. */
    	UBYTE apic_id = pdata->kb_APIC_IDMap[i];

    	D(bug("[SMP] Launching APIC %u (ID 0x%04X)\n", i, apic_id));
 
	/*
	 * First we need to allocate a stack for our CPU.
	 * We allocate the same three stacks as in core_CPUSetup().
	 */
	_APICStackBase = AllocMem(STACK_SIZE * 3, MEMF_CLEAR);
	D(bug("[SMP] Allocated STACK for APIC ID %d @ %p ..\n", apic_id, _APICStackBase));
	if (!_APICStackBase)
		return 0;

	/* Give the stack to the CPU */
	bs->Arg1 = (IPTR)_APICStackBase;
	bs->Arg2 = (IPTR)&apicready;
	bs->SP   = _APICStackBase + STACK_SIZE;

	/* Initialize 'ready' flag to zero before launching the core */
	apicready = 0;

	D(bug("[SMP] Setting warm reset code ..\n"));
	outb(0xf, 0x70);
	outb(0xa, 0x71);

	/* Flush TLB (we are supervisor here) */
	do
	{
	    unsigned long scratchreg;

	    asm volatile(
        	"movq %%cr3, %0\n\t"
            	"movq %0, %%cr3":"=r"(scratchreg)::"memory");
    	} while (0);

	/* Start IPI sequence */
	wakeresult = core_APIC_Wake(bs, apic_id, pdata);
	D(bug("[SMP] core_APIC_Wake() returns %d\n", wakeresult));

	/* wakeresult != 0 means error */
	if (!wakeresult)
	{
	    /*
	     * Before we proceed we need to make sure that the core has picked up
	     * its stack and we can reload bootstrap argument area with another one.
	     * We use a very simple spinlock in order to perform this waiting.
	     * Previously we have set apicready to 0. When the core starts up,
	     * it writes 1 there.
	     */
	    D(bug("[SMP] Waiting for APIC %u to initialise ..\n", i));
	    while (!apicready);
	}
    }

    D(bug("[SMP] Done\n"));
    return 1;
}
