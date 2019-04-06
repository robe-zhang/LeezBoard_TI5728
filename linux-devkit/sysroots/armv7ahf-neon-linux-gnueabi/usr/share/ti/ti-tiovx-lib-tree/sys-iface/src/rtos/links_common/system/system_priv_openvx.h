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
 * \defgroup SYSTEM_IMPL   System framework implementation
 *
 * @{
 *
 *******************************************************************************
 */

/**
 *******************************************************************************
 * \file system_priv_openvx.h
 *
 * \brief  Header file for all system link internal APIs.
 *
 *******************************************************************************
 */

#ifndef SYSTEM_PRIV_OPENVX_H_
#define SYSTEM_PRIV_OPENVX_H_

/*******************************************************************************
 *  INCLUDE FILES
 *******************************************************************************
 */
/* None */

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */

/**
 *******************************************************************************
 *  \brief  OpenVX Descriptor ID mask
 *******************************************************************************
*/
#define SYSTEM_OPENVX_DESC_ID_MASK          (0xFFFFU)
/**
 *******************************************************************************
 *  \brief  OpenVX Descriptor ID shift
 *******************************************************************************
*/
#define SYSTEM_OPENVX_DESC_ID_SHIFT         (12U)


/*******************************************************************************
 *  declaration for openvx notify handler, implemented in openvx layer.
 *******************************************************************************
 */
typedef Void(*System_openVxNotifyHandler) (UInt32 payload);


/*******************************************************************************
 *  Data structure's
 *******************************************************************************
 */

/*******************************************************************************
 *  Function Declaration
 *******************************************************************************
 */

Int32 System_openVxSendNotify(UInt32 cpuId, UInt32 payload);
Void System_registerOpenVxNotifyCb(System_openVxNotifyHandler notifyCb);
Void System_openVxIpcHandler(UInt32 payload, Ptr arg);

Void System_openvxActivate(void);
Void System_openvxDeactivate(void);

Void *System_openvxGetObjDescShm(unsigned int *shm_size);
#endif

/* @} */
