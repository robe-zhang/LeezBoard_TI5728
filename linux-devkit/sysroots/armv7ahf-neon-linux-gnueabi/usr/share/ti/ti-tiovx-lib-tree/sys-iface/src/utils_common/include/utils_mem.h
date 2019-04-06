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
 * \file utils_mem.h
 *
 * \brief External/Internal Memory allocator API
 *
 * \version 0.0 First version
 * \version 0.1 Updates as per code review comments
 *
 *******************************************************************************
*/

#ifndef UTILS_MEM_H_
#define UTILS_MEM_H_

/*******************************************************************************
 *  INCLUDE FILES
 *******************************************************************************
 */
#include <include/link_api/systemLink_common.h>
#include <src/rtos/utils_common/include/utils_mem_if.h>


/*******************************************************************************
 *  Defines
 *******************************************************************************
 */



/**
 *******************************************************************************
 * \brief Utility define for Kilobyte, i.e 1024 bytes
 *******************************************************************************
*/
#ifndef KB
#define KB ((UInt32)1024U)
#endif

/**
 *******************************************************************************
 * \brief Utility define for Megabyte, i.e 1024*1024 bytes
 *******************************************************************************
*/
#ifndef MB
#define MB (KB*KB)
#endif




/*******************************************************************************
 *  Functions
 *******************************************************************************
*/
Int32 Utils_memInit(void);

Int32 Utils_memDeInit(void);

//Int32 Utils_memAllocSR(SystemCommon_AllocBuffer *pPrm);
//Int32 Utils_memFreeSR(SystemCommon_FreeBuffer *pPrm);
//Int32 Utils_memGetHeapStatsSR(Utils_MemHeapStats *pPrm);

#endif

/* @} */
