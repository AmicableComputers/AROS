#include <dos/dos.h>
#include <proto/dos.h>

#include <errno.h>

#include "__time.h"
#include "__errno.h"

#include <sys/stat.h>

static mode_t __prot_a2u(ULONG protect);
static uid_t  __amiga2unixid(UWORD id);

int stat(const char *path, struct stat *sb)
{
    BPTR lock;
    struct FileInfoBlock *fib;

    fib = AllocDosObject(DOS_FIB, NULL);
    if (!fib)
    {
        errno = IoErr2errno(IoErr());
	return -1;
    }
    memset(fib, 0, sizeof(*fib));

    lock = Lock(path, SHARED_LOCK);
    if (!lock)
    {
	if  (IoErr() == ERROR_OBJECT_IN_USE)
	{
	    /* the file is already locked exclusively, so the only way to get
	       infos about it is to find it in the parent directoy with the ExNext() function
            */

	    /* return an error for now */
	    FreeDosObject(DOS_FIB, fib);
	    errno = EACCES;
	    return -1;
        }

	FreeDosObject(DOS_FIB, fib);
	errno = IoErr2errno(IoErr());
	return -1;
    }
    else
    if (!Examine(lock, fib))
    {
        errno = IoErr2errno(IoErr());
	FreeDosObject(DOS_FIB, fib);
	UnLock(lock);
	return -1;
    }

    sb->st_dev     = (dev_t)((struct FileHandle *)lock)->fh_Device;
    sb->st_ino     = (ino_t)fib->fib_DiskKey;
    sb->st_size    = (off_t)fib->fib_Size;
    sb->st_blksize = 1024; /* I'll implement it later */
    sb->st_blocks  = (long)fib->fib_NumBlocks;
    sb->st_atime   =
    sb->st_ctime   =
    sb->st_mtime   = (fib->fib_Date.ds_Days * 24*60 + fib->fib_Date.ds_Minute + __gmtoffset) * 60 +
	              fib->fib_Date.ds_Tick / TICKS_PER_SECOND + OFFSET_FROM_1970;
    sb->st_uid     = __amiga2unixid(fib->fib_OwnerUID);
    sb->st_gid     = __amiga2unixid(fib->fib_OwnerGID);
    sb->st_mode    = __prot_a2u(fib->fib_Protection);

    switch (fib->fib_DirEntryType)
    {
    	case ST_PIPEFILE:
	    /* don't use S_IFIFO, we don't have a mkfifo() call ! */
	    sb->st_mode |= S_IFCHR;
	    break;
	case ST_ROOT:
    	case ST_USERDIR:
	    sb->st_nlink = 2;
	    sb->st_mode |= S_IFDIR;
     	    break;
	case ST_SOFTLINK:
	    sb->st_nlink = 1;
	    sb->st_mode |= S_IFLNK;
	    break;
    	case ST_LINKDIR:
	    sb->st_nlink = 3;
	    sb->st_mode |= S_IFDIR;
	    break;
    	case ST_LINKFILE:
	    sb->st_nlink = 2;
    	case ST_FILE:
	default:
	    sb->st_mode |= S_IFREG;
    }

    FreeDosObject(DOS_FIB, fib);
    UnLock(lock);

    return 0;
}

static mode_t __prot_a2u(ULONG protect)
{
    mode_t uprot = 0000;

    if ((protect & FIBF_SCRIPT))
	uprot |= 0111;
    /* The following three flags are low-active! */
    if (!(protect & FIBF_EXECUTE))
	uprot |= 0100;
    if (!(protect & FIBF_WRITE))
	uprot |= 0200;
    if (!(protect & FIBF_READ))
	uprot |= 0400;
    if ((protect & FIBF_GRP_EXECUTE))
	uprot |= 0010;
    if ((protect & FIBF_GRP_WRITE))
	uprot |= 0020;
    if ((protect & FIBF_GRP_READ))
	uprot |= 0040;
    if ((protect & FIBF_OTR_EXECUTE))
	uprot |= 0001;
    if ((protect & FIBF_OTR_WRITE))
	uprot |= 0002;
    if ((protect & FIBF_OTR_READ))
	uprot |= 0004;

    return uprot;
}

static uid_t __amiga2unixid(UWORD id)
{
    switch(id)
    {
	case (UWORD)-1:
	    return 0;
 	case (UWORD)-2:
	    return (UWORD)-1;
    	case 0:
	    return (UWORD)-2;
	default:
	    return id;
    }
}
