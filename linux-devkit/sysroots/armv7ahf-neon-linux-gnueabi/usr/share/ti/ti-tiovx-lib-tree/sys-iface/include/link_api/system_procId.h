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
 *  \ingroup SYSTEM_LINK_API
 *  \defgroup SYSTEM_LINK_ID  System Link ID's
 *
 *  The unique 32-bit Link ID for the links present in the system are defined
 *  in this module
 *
 *  @{
*/

/**
 *******************************************************************************
 *
 *  \file system_procId.h
 *  \brief  System Proc ID's
 *
 *******************************************************************************
*/

#ifndef SYSTEM_PROC_ID_H_
#define SYSTEM_PROC_ID_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */

/* @{ */

/**
 *******************************************************************************
 *
 * \brief IPU1 Core 0 Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_IPU1_0      (0U)

/**
 *******************************************************************************
 *
 * \brief IPU Core 1 Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_IPU1_1      (1U)

/**
 *******************************************************************************
 *
 * \brief MPU Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_A15_0       (2U)

/**
 *******************************************************************************
 *
 * \brief DSP Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_DSP1        (3U)
/**
 *******************************************************************************
 *
 * \brief DSP Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_DSP2        (4U)

/**
 *******************************************************************************
 *
 * \brief EVE Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_EVE1        (5U)

/**
 *******************************************************************************
 *
 * \brief EVE Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_EVE2        (6U)

/**
 *******************************************************************************
 *
 * \brief EVE Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_EVE3        (7U)

/**
 *******************************************************************************
 *
 * \brief EVE Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_EVE4        (8U)

/**
 *******************************************************************************
 *
 * \brief IPU Core 1 Proc ID
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_IPU2        (9U)

/**
 *******************************************************************************
 *
 * \brief Max supported processors
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_MAX         (10U)

/**
 *******************************************************************************
 *
 * \brief Invalid proc Id, if received indicates some corruption
 *
 *******************************************************************************
*/
#define SYSTEM_PROC_INVALID     (0xFFFFU)

/* @} */


#ifdef  __cplusplus
}
#endif

#endif

/*@}*/

