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
 * \ingroup FRAMEWORK_MODULE_API
 * \defgroup SYSTEM_LINK_API System Link API
 *
 *
 * @{
 *******************************************************************************
*/

/**
 *******************************************************************************
 *
 * \file   system_if.h
 *
 * \brief  System Link API
 *
 *   The APIs defined in this module are used to create links and connect
 *   them to each other to form a chain
 *
 *   A unique 32-bit link ID is used to send commands to specific links.
 *
 *******************************************************************************
 */

#ifndef SYSTEM_IF_H_
#define SYSTEM_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes 
 *******************************************************************************
 */

/* None */


/*******************************************************************************
 *  Defines
 *******************************************************************************
 */

/* None */


/*******************************************************************************
 *  Data structures
 *******************************************************************************
 */

/*******************************************************************************
 *  Functions Prototypes
 *******************************************************************************
 */

/**
 *******************************************************************************
 *
 * \brief Return Proc ID of the processor this code is running.
 *
 *        Note,
 *        Syslink/IPC Proc ID could be different from Proc ID
 *        and framework does not rely on
 *        syslink/IPC Proc ID and Proc ID being same.
 *
 * \return Proc ID. SYSTEM_PROC_INVALID if there is an error in getting
 *         the Proc ID.
 *
 *******************************************************************************
 */
uint32_t System_getSelfProcId(void);
int32_t System_openvxIsProcEnabled(uint32_t);
//void *System_physToVirt (uint32_t);
#ifdef  __cplusplus
}
#endif

#endif

/*@}*/


