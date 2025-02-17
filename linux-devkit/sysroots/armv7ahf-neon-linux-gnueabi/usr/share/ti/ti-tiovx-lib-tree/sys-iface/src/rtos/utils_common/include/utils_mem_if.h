/*
 *******************************************************************************
 *
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
 */

/**
 *******************************************************************************
 *
 * \ingroup UTILS_API
 * \defgroup UTILS_MEM_API External/Internal Memory allocator API
 *
 * \brief  APIs to allocate system buffer memory from a predefined memory pool
 *
 * @{
 *
 *******************************************************************************
*/

/**
 *******************************************************************************
 *
 * \file utils_mem_if.h
 *
 * \brief External/Internal Memory allocator API
 *
 * \version 0.0 First version
 * \version 0.1 Updates as per code review comments
 *
 *******************************************************************************
*/

#ifndef UTILS_MEM_IF_H_
#define UTILS_MEM_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */
#include <include/link_api/systemLink_common_if.h>

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */


/**
 *******************************************************************************
 * \brief Heap ID
 *******************************************************************************
*/
typedef enum
{
    UTILS_HEAPID_DDR_NON_CACHED_SR0 = SYSTEM_HEAPID_DDR_NON_CACHED_SR0,
    /**< Heap ID of heap in DDR
     *   - This is non-cached memory
     *   - This is shared across all CPUs
     *   - Recommended to be used for small information structures, that need to be
     *     shared across CPUs
     */

    UTILS_HEAPID_DDR_CACHED_SR = SYSTEM_HEAPID_DDR_CACHED_SR1,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC disabled and QM access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     */

    UTILS_HEAPID_DDR_CACHED_SR_NON_ECC_QM = SYSTEM_HEAPID_DDR_CACHED_SR1,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC disabled and QM access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     */

    UTILS_HEAPID_OCMC_SR = SYSTEM_HEAPID_OCMC_SR2,
    /**< Heap ID of heap in DDR
     *   - This is cached or non-cached memory depending on CPU MMU setting
     *   - This is shared across all CPUs
     *   - Recommended to be used as fast access temporary memory by algorithms
     */

    UTILS_HEAPID_DDR_CACHED_LOCAL = SYSTEM_HEAPID_RESERVED1,
    /**< Heap ID of heap in DDR
     *   - This is cached memory
     *   - This is only visible to the local CPUs
     *   - Recommended to be used for small information, that is needed by the
     *     local algorithm
     */

    UTILS_HEAPID_L2_LOCAL = SYSTEM_HEAPID_RESERVED2,
    /**< Heap ID of heap in L2 Memory
     *   - This is cached or non-cached memory depending on CPU MMU setting
     *   - This is only visible to the local CPU
     *   - Recommended to be used as fast access temporary memory by algorithms
     */


    UTILS_HEAPID_DDR_CACHED_SR_ECC_ASIL = SYSTEM_HEAPID_DDR_CACHED_SR1_ECC_ASIL,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC enabled and ASIL access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     *   - Valid only when ECC_FFI_INCLUDE is defined.
     *     Else will map to UTILS_HEAPID_DDR_CACHED_SR
     */

    UTILS_HEAPID_DDR_CACHED_SR_ECC_QM = SYSTEM_HEAPID_DDR_CACHED_SR1_ECC_QM,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC enabled and QM access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     *   - Valid only when ECC_FFI_INCLUDE is defined.
     *     Else will map to UTILS_HEAPID_DDR_CACHED_SR
     */

    UTILS_HEAPID_DDR_CACHED_SR_NON_ECC_ASIL = SYSTEM_HEAPID_DDR_CACHED_SR1_NON_ECC_ASIL,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC disabled and ASIL access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     *   - Valid only when ECC_FFI_INCLUDE is defined.
     *     Else will map to UTILS_HEAPID_DDR_CACHED_SR
     */

    UTILS_HEAPID_MAXNUMHEAPS = SYSTEM_HEAPID_MAXNUMHEAPS
    /**< max Heap ID */

} Utils_HeapId;

/**
 *******************************************************************************
 * \brief Information related to a heap
 *******************************************************************************
*/
typedef struct {

    char   heapName[32];
    /**< Name of heap */

    UInt32 heapId;
    /**< Heap ID */

    UInt32 heapAddr;
    /**< Physical base address of heap */

    UInt32 heapSize;
    /**< Total size of heap in bytes */

    UInt32 freeSize;
    /**< Free space in heap in bytes */

} Utils_MemHeapStats;


/*******************************************************************************
 *  Functions
 *******************************************************************************
*/

Ptr   Utils_memAlloc(Utils_HeapId heapId, UInt32 size, UInt32 align);

Int32 Utils_memFree(Utils_HeapId heapId, Ptr addr, UInt32 size);

Int32 Utils_memClearOnAlloc(Bool enable);

Int32 Utils_memGetHeapStats(Utils_HeapId heapId, Utils_MemHeapStats *pStats);

Void *Utils_memPhysToVirt (UInt32 ph_addr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/* @} */
