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
 *
 *  \ingroup FRAMEWORK_MODULE_API
 *  \defgroup PROCESSOR_LINK_API Processor Link API
 *
 *   Processor Link is a link which is created on every processor to handle
 *   generic commands which do not fall into any specific pre-defined link
 *   category like capture or display. This interface allows user/developer to
 *   extend new commands in the system without having to create a new link
 *   everytime. Normally this link does not exchange frames and usually
 *   handles control commands only.
 *
 *******************************************************************************
*/

/**
 *******************************************************************************
 *
 *   \ingroup PROCESSOR_LINK_API
 *   \defgroup SYSTEM_COMMON_LINK_API Processor Link API: Common Interfaces
 *
 *   This module defines the control commands that are applicable to
 *   all processors running in the system.
 *
 *   @{
*/

/**
 *
 *******************************************************************************
 *
 *   \file systemLink_common.h
*   \brief Processor Link API: Common Interfaces
 *
 *******************************************************************************
*/


#ifndef SYSTEM_LINK_COMMON_IF_H_
#define SYSTEM_LINK_COMMON_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */

/* None */

/*******************************************************************************
 *  Enums
 *******************************************************************************
 */


/**
 *******************************************************************************
 * \brief Heap ID
 *******************************************************************************
*/
typedef enum
{
    SYSTEM_HEAPID_DDR_NON_CACHED_SR0 = 0,
    /**< Heap ID of heap in DDR
     *   - This is non-cached memory
     *   - This is shared across all CPUs
     *   - Recommended to be used for small information structures, that need to be
     *     shared across CPUs
     */

    SYSTEM_HEAPID_DDR_CACHED_SR1 = 1,
    /**< Heap ID of heap in DDR
     *   - This is cached memory
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     */

    SYSTEM_HEAPID_DDR_CACHED_SR1_NON_ECC_QM = 1,
    /**< Heap ID of heap in DDR
     *   - This is cached memory wih ECC disabled and QM access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     */

    SYSTEM_HEAPID_OCMC_SR2 = 2,
    /**< Heap ID of heap in DDR
     *   - This is cached or non-cached memory depending on CPU MMU setting
     *   - This is shared across all CPUs
     *   - Recommended to be used as fast access temporary memory by algorithms
     */

    SYSTEM_HEAPID_RESERVED1 = 3,
    /**< Heap ID of heap in DDR
     *   - This is cached memory
     *   - This is only visible to the local CPUs
     *   - Recommended to be used for small information, that is needed by the
     *     local algorithm
     */

    SYSTEM_HEAPID_RESERVED2 = 4,
    /**< Heap ID of heap in L2 Memory
     *   - This is cached or non-cached memory depending on CPU MMU setting
     *   - This is only visible to the local CPU
     *   - Recommended to be used as fast access temporary memory by algorithms
     */

    SYSTEM_HEAPID_DDR_CACHED_SR1_ECC_ASIL = 5,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC enabled and ASIL access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     *   - Valid only when ECC_FFI_INCLUDE is defined.
     *     Else will map to SYSTEM_HEAPID_DDR_CACHED_SR1
     */

    SYSTEM_HEAPID_DDR_CACHED_SR1_ECC_QM = 6,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC enabled and QM access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     *   - Valid only when ECC_FFI_INCLUDE is defined.
     *     Else will map to SYSTEM_HEAPID_DDR_CACHED_SR1
     */

    SYSTEM_HEAPID_DDR_CACHED_SR1_NON_ECC_ASIL = 7,
    /**< Heap ID of heap in DDR
     *   - This is cached memory with ECC disabled and ASIL access permissions
     *   - This is shared across all CPUs
     *   - Recommended to be used for big buffer allocations, that need to be shared
     *     across CPUs
     *   - Valid only when ECC_FFI_INCLUDE is defined.
     *     Else will map to SYSTEM_HEAPID_DDR_CACHED_SR1
     */

    SYSTEM_HEAPID_MAXNUMHEAPS = 8,
    /**< max Heap ID */

    SYSTEM_HEAPID_FORCE32BITS = 0x7FFFFFFFU
    /**< This should be the last value after the max enumeration value.
     *   This is to make sure enum size defaults to 32 bits always regardless
     *   of compiler.
     */

} System_HeapId;

/**
 *******************************************************************************
 *
 * \brief Floor
 *
 * \param val         [IN]   Value to be rounded off
 *
 * \param align       [IN]   Value to which val to be rounded
 *
 * \return aligned value of val
 *
 *******************************************************************************
 */
static inline UInt32 SystemUtils_floor(UInt32 val, UInt32 align)
{
    return (((val) / (align)) * (align));
}


/**
 *******************************************************************************
 *
 * \brief Align to power of two
 *
 * \param val         [IN]   Value to be rounded off
 *
 * \param align       [IN]   Value to which val to be rounded
 *
 * \return aligned value of val
 *
 *******************************************************************************
 */
static inline UInt32 SystemUtils_align(UInt32 val, UInt32 align)
{
    UInt32 retVal;
    retVal = SystemUtils_floor(((val) + ((align)- 1U)), (align));

    return retVal;
}


/*******************************************************************************
 *  Data structure's
 *******************************************************************************
 */

/* None*/

/*******************************************************************************
 *  Function's
 *******************************************************************************
 */

/* None*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/*@}*/
