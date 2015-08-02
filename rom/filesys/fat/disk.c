/*
 * fat-handler - FAT12/16/32 filesystem handler
 *
 * Copyright � 2006 Marek Szyprowski
 * Copyright � 2007-2015 The AROS Development Team
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the same terms as AROS itself.
 *
 * $Id$
 */

#define USE_INLINE_STDARG

#include <exec/types.h>
#include <exec/errors.h>

#include <dos/dos.h>
#include <dos/dosextens.h>
#include <dos/filehandler.h>
#include <devices/newstyle.h>
#include <devices/trackdisk.h>
#include <devices/inputevent.h>

#include <proto/exec.h>
#include <proto/dos.h>

#include <string.h>
#include <stdio.h>

#include "fat_fs.h"
#include "fat_protos.h"

#define DEBUG DEBUG_MISC
#include "debug.h"

#ifndef ID_BUSY
#define ID_BUSY 0x42555359
#endif

/* TD64 commands */
#ifndef TD_READ64
#define TD_READ64  24
#define TD_WRITE64 25
#endif

void FillDiskInfo(struct InfoData *id, struct Globals *glob)
{
    struct DosEnvec *de = BADDR(glob->fssm->fssm_Environ);

    id->id_NumSoftErrors = 0;
    id->id_UnitNumber = glob->fssm->fssm_Unit;
    id->id_DiskState = ID_VALIDATED;

    if (glob->sb)
    {
        id->id_NumBlocks = glob->sb->total_sectors;
        id->id_NumBlocksUsed = glob->sb->total_sectors
            - (glob->sb->free_clusters << glob->sb->cluster_sectors_bits);
        id->id_BytesPerBlock = glob->sb->sectorsize;

        id->id_DiskType = ID_DOS_DISK;

        id->id_VolumeNode = MKBADDR(glob->sb->doslist);
        id->id_InUse = (IsListEmpty(&glob->sb->info->locks)
            && IsListEmpty(&glob->sb->info->notifies)) ? DOSFALSE : DOSTRUE;
    }

    else
    {
        id->id_NumBlocks = de->de_Surfaces * de->de_BlocksPerTrack
            * (de->de_HighCyl + 1 - de->de_LowCyl) / de->de_SectorPerBlock;
        id->id_NumBlocksUsed = id->id_NumBlocks;
        id->id_BytesPerBlock = de->de_SizeBlock << 2;

        id->id_DiskState = ID_VALIDATED;

        if (glob->disk_inhibited)
            id->id_DiskType = ID_BUSY;
        else if (glob->disk_inserted)
            id->id_DiskType = ID_NOT_REALLY_DOS;        //ID_UNREADABLE_DISK;
        else
            id->id_DiskType = ID_NO_DISK_PRESENT;

        id->id_VolumeNode = BNULL;
        id->id_InUse = DOSFALSE;
    }
}

void SendVolumePacket(struct DosList *vol, ULONG action,
    struct Globals *glob)
{
    struct DosPacket *dospacket;

    dospacket = AllocDosObject(DOS_STDPKT, TAG_DONE);
    dospacket->dp_Type = ACTION_DISK_CHANGE;
    dospacket->dp_Arg1 = ID_FAT_DISK;
    dospacket->dp_Arg2 = (IPTR) vol;
    dospacket->dp_Arg3 = action;
    dospacket->dp_Port = NULL;

    PutMsg(glob->ourport, dospacket->dp_Link);
}

void DoDiskInsert(struct Globals *glob)
{
    struct FSSuper *sb;
    ULONG err;
    struct DosList *dl;
    struct VolumeInfo *vol_info = NULL;
    struct GlobalLock *global_lock;
    struct ExtFileLock *ext_lock;
    struct MinNode *lock_node;
    APTR pool;
    struct NotifyNode *nn;
    struct DosList *newvol = NULL;

    if (glob->sb == NULL
        && (sb = AllocVecPooled(glob->mempool, sizeof(struct FSSuper))))
    {
        memset(sb, 0, sizeof(struct FSSuper));

        sb->glob = glob;
        err = ReadFATSuper(sb);
        if (err == 0)
        {

            /* Scan volume list for a matching volume (would be better to
             * match by serial number) */
            dl = LockDosList(LDF_VOLUMES | LDF_WRITE);
            dl = FindDosEntry(dl, sb->volume.name + 1,
                LDF_VOLUMES | LDF_WRITE);
            UnLockDosList(LDF_VOLUMES | LDF_WRITE);

            if (dl != NULL &&
                CompareDates(&dl->dol_misc.dol_volume.dol_VolumeDate,
                    &sb->volume.create_time) != 0)
                dl = NULL;

            if (dl != NULL)
            {
                dl->dol_Task = glob->ourport;
                sb->doslist = dl;

                D(bug("\tFound old volume.\n"));

                vol_info = BADDR(dl->dol_misc.dol_volume.dol_LockList);

#if 0    /* No point until we match volumes by serial number */
                /* Update name */
#ifdef AROS_FAST_BPTR
                /* ReadFATSuper() sets a null byte after the
                 * string, so this should be fine */
                CopyMem(sb->volume.name + 1, dl->dol_Name,
                    sb->volume.name[0] + 1);
#else
                CopyMem(sb->volume.name, dl->dol_Name,
                    sb->volume.name[0] + 2);
#endif
#endif

                /* Patch locks and notifications to match this handler
                 * instance */
                ForeachNode(&vol_info->locks, global_lock)
                {
                    ForeachNode(&global_lock->locks, lock_node)
                    {
                        ext_lock = LOCKFROMNODE(lock_node);
                        D(bug("[fat] Patching adopted lock %p. old port = %p,"
                            " new port = %p\n", ext_lock,
                            ext_lock->fl_Task, glob->ourport));
                        ext_lock->fl_Task = glob->ourport;
                        ext_lock->sb = sb;
                        ext_lock->ioh.sb = sb;
                    }
                }

                ForeachNode(&vol_info->root_lock.locks, lock_node)
                {
                    ext_lock = LOCKFROMNODE(lock_node);
                    D(bug("[fat] Patching adopted ROOT lock %p. old port = %p,"
                        " new port = %p\n", ext_lock, ext_lock->fl_Task,
                        glob->ourport));
                    ext_lock->fl_Task = glob->ourport;
                    ext_lock->sb = sb;
                    ext_lock->ioh.sb = sb;
                }

                ForeachNode(&vol_info->notifies, nn)
                    nn->nr->nr_Handler = glob->ourport;
            }
            else
            {
                D(bug("\tCreating new volume.\n"));

                /* Create transferable core volume info */
                pool =
                    CreatePool(MEMF_PUBLIC, DEF_POOL_SIZE,
                    DEF_POOL_THRESHOLD);
                if (pool != NULL)
                {
                    vol_info =
                        AllocVecPooled(pool, sizeof(struct VolumeInfo));
                    if (vol_info != NULL)
                    {
                        vol_info->mem_pool = pool;
                        vol_info->id = sb->volume_id;
                        NEWLIST(&vol_info->locks);
                        NEWLIST(&vol_info->notifies);

                        vol_info->root_lock.dir_cluster = FAT_ROOTDIR_MARK;
                        vol_info->root_lock.dir_entry = FAT_ROOTDIR_MARK;
                        vol_info->root_lock.access = SHARED_LOCK;
                        vol_info->root_lock.first_cluster = 0;
                        vol_info->root_lock.attr = ATTR_DIRECTORY;
                        vol_info->root_lock.size = 0;
                        CopyMem(sb->volume.name, vol_info->root_lock.name,
                            sb->volume.name[0] + 1);
                        NEWLIST(&vol_info->root_lock.locks);
                    }

                    if ((newvol =
                        AllocVecPooled(pool, sizeof(struct DosList))))
                    {
                        newvol->dol_Next = BNULL;
                        newvol->dol_Type = DLT_VOLUME;
                        newvol->dol_Task = glob->ourport;
                        newvol->dol_Lock = BNULL;

                        CopyMem(&sb->volume.create_time,
                            &newvol->dol_misc.dol_volume.dol_VolumeDate,
                            sizeof(struct DateStamp));

                        newvol->dol_misc.dol_volume.dol_LockList =
                            MKBADDR(vol_info);

                        newvol->dol_misc.dol_volume.dol_DiskType =
                            (sb->type == 12) ? ID_FAT12_DISK :
                            (sb->type == 16) ? ID_FAT16_DISK :
                            (sb->type == 32) ? ID_FAT32_DISK :
                            ID_FAT12_DISK;

                        if ((newvol->dol_Name = MKBADDR(
                            AllocVecPooled(pool, FAT_MAX_SHORT_NAME + 2))))
                        {
#ifdef AROS_FAST_BPTR
                            /* ReadFATSuper() sets a null byte after the
                             * string, so this should be fine */
                            CopyMem(sb->volume.name + 1, newvol->dol_Name,
                                sb->volume.name[0] + 1);
#else
                            CopyMem(sb->volume.name,
                                BADDR(newvol->dol_Name),
                                sb->volume.name[0] + 2);
#endif

                            sb->doslist = newvol;
                        }
                    }
                    if (vol_info == NULL || newvol == NULL)
                        DeletePool(pool);
                }
            }

            sb->info = vol_info;
            glob->last_num = -1;

            if (dl != NULL)
                SendEvent(IECLASS_DISKINSERTED, glob);
            else
                SendVolumePacket(newvol, ACTION_VOLUME_ADD, glob);

            D(bug("\tDisk successfully initialised\n"));

            return;
        }

        FreeVecPooled(glob->mempool, sb);
    }

    SendEvent(IECLASS_DISKINSERTED, glob);

    return;
}

BOOL AttemptDestroyVolume(struct FSSuper *sb)
{
    struct Globals *glob = sb->glob;
    BOOL destroyed = FALSE;

    D(bug("[fat] Attempting to destroy volume\n"));

    /* Check if the volume can be removed */
    if (IsListEmpty(&sb->info->locks) && IsListEmpty(&sb->info->notifies))
    {
        D(bug("\tRemoving volume completely\n"));

        if (sb == glob->sb)
            glob->sb = NULL;
        else
            Remove((struct Node *)sb);

        SendVolumePacket(sb->doslist, ACTION_VOLUME_REMOVE, glob);

        FreeFATSuper(sb);
        FreeVecPooled(glob->mempool, sb);
        destroyed = TRUE;
    }

    return destroyed;
}

void DoDiskRemove(struct Globals *glob)
{

    if (glob->sb)
    {
        struct FSSuper *sb = glob->sb;

        if (!AttemptDestroyVolume(sb))
        {
            sb->doslist->dol_Task = NULL;
            glob->sb = NULL;
            D(bug("\tMoved in-memory super block to spare list. "
                "Waiting for locks and notifications to be freed\n"));
            AddTail((struct List *)&glob->sblist, (struct Node *)sb);
            SendEvent(IECLASS_DISKREMOVED, glob);
        }
    }
}

void ProcessDiskChange(struct Globals *glob)
{
    D(bug("\nGot disk change request\n"));

    if (glob->disk_inhibited)
    {
        D(bug("Disk is inhibited, ignoring disk change\n"));
        return;
    }

    glob->diskioreq->iotd_Req.io_Command = TD_CHANGESTATE;
    glob->diskioreq->iotd_Req.io_Data = NULL;
    glob->diskioreq->iotd_Req.io_Length = 0;
    glob->diskioreq->iotd_Req.io_Flags = IOF_QUICK;
    DoIO((struct IORequest *)glob->diskioreq);

    if (glob->diskioreq->iotd_Req.io_Error == 0
        && glob->diskioreq->iotd_Req.io_Actual == 0)
    {
        /* Disk has been inserted. */
        D(bug("\tDisk has been inserted\n"));
        glob->disk_inserted = TRUE;
        DoDiskInsert(glob);
    }
    else
    {
        /* Disk has been removed. */
        D(bug("\tDisk has been removed\n"));
        glob->disk_inserted = FALSE;
        DoDiskRemove(glob);
    }

    D(bug("Done\n"));
}

void UpdateDisk(struct Globals *glob)
{
    if (glob->sb)
        Cache_Flush(glob->sb->cache);

    glob->diskioreq->iotd_Req.io_Command = CMD_UPDATE;
    DoIO((struct IORequest *)glob->diskioreq);

    /* Turn off motor (where applicable) if nothing has happened during the
     * last timer period */
    if (!glob->restart_timer)
    {
        D(bug("Stopping drive motor\n"));
        glob->diskioreq->iotd_Req.io_Command = TD_MOTOR;
        glob->diskioreq->iotd_Req.io_Length = 0;
        DoIO((struct IORequest *)glob->diskioreq);
    }
}

/* Probe the device to determine 64-bit support */
void Probe_64bit_support(struct Globals *glob)
{
    struct NSDeviceQueryResult nsd_query;
    UWORD *nsd_cmd;

    glob->readcmd = CMD_READ;
    glob->writecmd = CMD_WRITE;

    /* Probe TD64 */
    glob->diskioreq->iotd_Req.io_Command = TD_READ64;
    glob->diskioreq->iotd_Req.io_Offset = 0;
    glob->diskioreq->iotd_Req.io_Length = 0;
    glob->diskioreq->iotd_Req.io_Actual = 0;
    glob->diskioreq->iotd_Req.io_Data = 0;

    if (DoIO((struct IORequest *)glob->diskioreq) != IOERR_NOCMD)
    {
        D(bug("Probe_64bit_support:"
            " device supports 64-bit trackdisk extensions\n"));
        glob->readcmd = TD_READ64;
        glob->writecmd = TD_WRITE64;
    }

    /* Probe NSD */
    glob->diskioreq->iotd_Req.io_Command = NSCMD_DEVICEQUERY;
    glob->diskioreq->iotd_Req.io_Length =
        sizeof(struct NSDeviceQueryResult);
    glob->diskioreq->iotd_Req.io_Data = (APTR) &nsd_query;

    if (DoIO((struct IORequest *)glob->diskioreq) == 0)
        for (nsd_cmd = nsd_query.SupportedCommands; *nsd_cmd != 0;
            nsd_cmd++)
        {
            if (*nsd_cmd == NSCMD_TD_READ64)
            {
                D(bug("Probe_64bit_support:"
                    " device supports NSD 64-bit trackdisk extensions\n"));
                glob->readcmd = NSCMD_TD_READ64;
                glob->writecmd = NSCMD_TD_WRITE64;
                break;
            }
        }
}

/* N.B. returns an Exec error code, not a DOS error code! */
LONG AccessDisk(BOOL do_write, ULONG num, ULONG nblocks, ULONG block_size,
    UBYTE *data, APTR priv)
{
    struct Globals *glob = priv;
    UQUAD off;
    ULONG err;
    ULONG start, end;
    BOOL retry = TRUE;
    TEXT vol_name[100];

#if DEBUG_CACHESTATS > 1
    ErrorMessage("Accessing %lu sector(s) starting at %lu.\n"
        "First volume sector is %lu, sector size is %lu.\n", "OK", nblocks,
         num, glob->sb->first_device_sector, block_size);
#endif

    /* Adjust parameters if range is partially outside boundaries, or
     * warn user and bale out if completely outside boundaries */
    if (glob->sb)
    {
        start = glob->sb->first_device_sector;
        if (num + nblocks <= glob->sb->first_device_sector)
        {
            if (num != glob->last_num)
            {
                glob->last_num = num;
                ErrorMessage("A handler attempted to %s %lu sector(s)\n"
                    "starting from %lu, before the actual volume space.\n"
                    "First volume sector is %lu, sector size is %lu.\n"
                    "Either your disk is damaged or it is a bug in\n"
                    "the handler. Please check your disk and/or\n"
                    "report this problem to the developers team.", "OK",
                    (IPTR) (do_write ? "write" : "read"), nblocks, num,
                    glob->sb->first_device_sector, block_size);
            }
            return IOERR_BADADDRESS;
        }
        else if (num < start)
        {
            nblocks -= start - num;
            data += (start - num) * block_size;
            num = start;
        }

        end = glob->sb->first_device_sector + glob->sb->total_sectors;
        if (num >= end)
        {
            if (num != glob->last_num)
            {
                glob->last_num = num;
                ErrorMessage("A handler attempted to %s %lu sector(s)\n"
                    "starting from %lu, beyond the actual volume space.\n"
                    "Last volume sector is %lu, sector size is %lu.\n"
                    "Either your disk is damaged or it is a bug in\n"
                    "the handler. Please check your disk and/or\n"
                    "report this problem to the developers team.", "OK",
                    (IPTR) (do_write ? "write" : "read"), nblocks, num,
                    end - 1, block_size);
            }
            return IOERR_BADADDRESS;
        }
        else if (num + nblocks > end)
            nblocks = end - num;
    }

    off = ((UQUAD) num) * block_size;

    while (retry)
    {
        glob->diskioreq->iotd_Req.io_Offset = off & 0xFFFFFFFF;
        glob->diskioreq->iotd_Req.io_Actual = off >> 32;

        glob->diskioreq->iotd_Req.io_Length = nblocks * block_size;
        glob->diskioreq->iotd_Req.io_Data = data;
        glob->diskioreq->iotd_Req.io_Command =
            do_write ? glob->writecmd : glob->readcmd;

        err = DoIO((struct IORequest *)glob->diskioreq);

        if (err != 0)
        {
            if (glob->sb && glob->sb->volume.name[0] != '\0')
                snprintf(vol_name, 100, "Volume %s",
                    glob->sb->volume.name + 1);
            else
                snprintf(vol_name, 100, "Device %s",
                    AROS_BSTR_ADDR(glob->devnode->dol_Name));

            if (nblocks > 1)
                retry = ErrorMessage("%s\nhas a %s error\n"
                    "in the block range\n%lu to %lu",
                    "Retry|Cancel", (IPTR)vol_name,
                    (IPTR)(do_write ? "write" : "read"), num,
                    num + nblocks - 1);
            else
                retry = ErrorMessage("%s\nhas a %s error\n"
                    "on block %lu",
                    "Retry|Cancel", (IPTR)vol_name,
                    (IPTR)(do_write ? "write" : "read"), num);
        }
        else
            retry = FALSE;
    }

    return err;
}
