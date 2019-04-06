/*
 *******************************************************************************
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
*/

/**
 *******************************************************************************
 * \file utils_mem.c
 *
 * \brief  This file has the implementataion of Display Control Driver Calls
 *
 *         This file implements the calls to display controller driver.
 *         Calls to driver create, control commands, deletion is done in this
 *         file. Conversion / population of FVID2 parameters based on
 *         parameters of link API structures happen here.|
 *
 * \version 0.0 (Jun 2013) : [PS] First version
 * \version 0.1 (Jul 2013) : [PS] Updates as per code review comments
 *
 *******************************************************************************
*/

/*******************************************************************************
 *  INCLUDE FILES
 *******************************************************************************
*/
/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/IHeap.h>
#include <ti/ipc/HeapBufMP.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/Cache.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/syncs/SyncSem.h>
#include <ti/ipc/remoteproc/Resource.h>

#include <src/utils_common/src/utils_mem_priv.h>

#include <string.h>
#include <stdio.h>

#define SYSTEM_LINK_STATUS_SOK (0)
#define SYSTEM_LINK_STATUS_FAIL (-1)
#define SYSTEM_LINK_STATUS_EINVALID_PARAMS (-2)

/**
 *******************************************************************************
 * \brief Macro to enable the memory/Heap debug
 *******************************************************************************
*/

#ifdef ENABLE_HEAP_L2

/**
 *******************************************************************************
 * \brief L2 heap memory
 *******************************************************************************
*/
/* MISRA.PRAGMA
 * MISRAC_2004 Rule_3.4
 * MISRAC_WAIVER:
 * KW tool cannot understand the pragma supported by CGTools like
 * DATA_ALIGN and DATA_SECTION. But these are valid pragmas.
 */
#pragma DATA_ALIGN(gUtils_memHeapL2, 4)
/* MISRA.PRAGMA
 * MISRAC_2004 Rule_3.4
 * Non-documented pragma directive.
 * KW State: Fixed in Later Release -> Waiver
 * MISRAC_WAIVER:
 * KW tool cannot understand the pragma supported by CGTools like
 * DATA_ALIGN and DATA_SECTION. But these are valid pragmas.
 */
#pragma DATA_SECTION(gUtils_memHeapL2, ".bss:L2memHeap")
UInt8 gUtils_memHeapL2[UTILS_MEM_HEAP_L2_SIZE];

Utils_MemHeapObj gUtils_memHeapObj[UTILS_HEAPID_MAXNUMHEAPS];

#endif
/**
 *******************************************************************************
 *
 * \brief One time system init of memory allocator
 *
 *        Should be called by application before using allocate APIs
 *
 * \return SYSTEM_LINK_STATUS_SOK on sucess, else SYSTEM_LINK_STATUS_EFAIL
 *
 *******************************************************************************
*/
Int32 Utils_memInit(void)
{
    extern const IHeap_Handle Memory_defaultHeapInstance;
    Utils_MemHeapStats memStats;
    Utils_HeapId       heapId;

    Log_print0(Diags_INFO, "Utils_memInit");
    memset ( gUtils_memHeapL2, 0, UTILS_MEM_HEAP_L2_SIZE);
    memset(gUtils_memHeapObj, 0, sizeof(gUtils_memHeapObj));

    heapId = UTILS_HEAPID_L2_LOCAL;
    gUtils_memHeapObj[heapId].heapHandle = NULL;
    gUtils_memHeapObj[heapId].heapAddr = (UInt32)gUtils_memHeapL2;
    gUtils_memHeapObj[heapId].heapAllocOffset = 0;
    gUtils_memHeapObj[heapId].isClearBufOnAlloc = (Bool)FALSE;
    gUtils_memHeapObj[heapId].heapSize   = sizeof(gUtils_memHeapL2);

    return SYSTEM_LINK_STATUS_SOK;
}

Int32 Utils_memGetHeapStats(Utils_HeapId heapId, Utils_MemHeapStats *pStats)
{
    IHeap_Handle heapHandle;
    Memory_Stats stats;
    Int32 status = SYSTEM_LINK_STATUS_SOK;

    memset(pStats, 0, sizeof(Utils_MemHeapStats));
    pStats->heapId = heapId;

    if(UTILS_HEAPID_DDR_CACHED_LOCAL == heapId)
    {
        heapHandle = gUtils_memHeapObj[heapId].heapHandle;
        if(NULL != heapHandle)
        {
           Memory_getStats(heapHandle, &stats);
           pStats->heapSize = stats.totalSize;
           pStats->freeSize = stats.totalFreeSize;
        }
        else
        {
           status = SYSTEM_LINK_STATUS_EINVALID_PARAMS;
        }
    } else if (UTILS_HEAPID_L2_LOCAL == heapId)
    {
      pStats->heapSize = gUtils_memHeapObj[heapId].heapSize;
      pStats->freeSize = gUtils_memHeapObj[heapId].heapSize - gUtils_memHeapObj[heapId].heapAllocOffset;
    } else status = SYSTEM_LINK_STATUS_EINVALID_PARAMS;
    return status;
}
/**
 *******************************************************************************
 *
 * \brief One time system de-init of memory allocator
 *
 *        Should be called by application at system de-init
 *
 * \return SYSTEM_LINK_STATUS_SOK on sucess, else SYSTEM_LINK_STATUS_EFAIL
 *
 *******************************************************************************
*/
Int32 Utils_memDeInit(void)
{
    Log_print0(Diags_INFO, "Utils_memDeInit");
    memset(gUtils_memHeapObj, 0, sizeof(gUtils_memHeapObj));
    return SYSTEM_LINK_STATUS_SOK;
}


/**
 *******************************************************************************
 *
 * \brief Allocate memory from Frame buffer memory pool
 *
 * \param heapId   [IN] Heap ID
 * \param size     [IN] size in bytes
 * \param align    [IN] alignment in bytes
 *
 * \return NULL or error, else memory pointer
 *
 *******************************************************************************
*/
Ptr Utils_memAlloc(Utils_HeapId heapId, UInt32 size, UInt32 align)
{
    Ptr addr;
    Log_print2(Diags_INFO, "Utils_memAlloc: heapId=%d size=%d", heapId, size);

    if(UTILS_HEAPID_L2_LOCAL == heapId)
    {
      UInt32 offset;
      UInt32 oldIntState;

      oldIntState = Hwi_disable();

      offset = SystemUtils_align( gUtils_memHeapObj[heapId].heapAllocOffset, align);

      if( (offset + size) > gUtils_memHeapObj[heapId].heapSize)
      {
           addr = NULL;
      }
      else
      {
           UInt32 tempAddr = gUtils_memHeapObj[heapId].heapAddr + offset;
           addr = (Ptr)tempAddr;
           gUtils_memHeapObj[heapId].heapAllocOffset = offset + size;
      }
      Hwi_restore(oldIntState);
    } else {
      IHeap_Handle heap = (IHeap_Handle)SharedRegion_getHeap(2);  // get the heap
      Memory_Stats stats;
      Memory_getStats(heap, &stats);
      Log_print2(Diags_INFO, "HeapStats: size %08x free %08x", stats.totalSize, stats.totalFreeSize);
      addr =  Memory_alloc(heap, size, align, NULL);  // alloc memory from heap
      Log_print1(Diags_INFO, "ptrValue=%08x", (unsigned int)addr);
    }
    return addr;
}

/**
 *******************************************************************************
 *
 * \brief Free previously allocate Frame buffer memory pointer
 *
 * \param heapId   [IN] Heap ID;
 * \param addr     [IN] memory pointer to free
 * \param size     [IN] size of memory pointed to by the memory pointer
 *
 * \return  SYSTEM_LINK_STATUS_SOK on success else SYSTEM_LINK_STATUS_EFAIL
 *
 *******************************************************************************
*/
Int32 Utils_memFree(Utils_HeapId heapId, Ptr addr, UInt32 size)
{
    IHeap_Handle heapHandle;
    Int32 status = SYSTEM_LINK_STATUS_SOK;

    if(UTILS_HEAPID_L2_LOCAL == heapId)
    {
       UInt32 oldIntState;
            oldIntState = Hwi_disable();
            gUtils_memHeapObj[heapId].heapAllocOffset = 0;
            Hwi_restore(oldIntState);
            return status;
    }
    Log_print3(Diags_INFO, "Utils_memFree: heapId=%d addr=%08x size=%d", heapId, addr, size);
    IHeap_Handle heap = (IHeap_Handle)SharedRegion_getHeap(2);  // get the heap
    Memory_free(heap, addr, size);
    return status;
}
/*******************************************************************************
 *
 * \brief Returns virtual DSP address using physical address as input
 *
 *        ONLY if DSP MMU is configured to work in 1-to-1 mapping, return value
 *        will be same as input value.
 *
 * \return  Virtual DSP address returned
 **/
void *Utils_memPhysToVirt (unsigned int phys_addr)
{
  unsigned int va;
  Resource_physToVirt(phys_addr, &va);
  return (void *)va;
}
/*** nothing past this point ***/
