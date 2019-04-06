/*
 *******************************************************************************
 *
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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
typedef void(*System_openVxNotifyHandler) (unsigned int payload);


/*******************************************************************************
 *  Data structure's
 *******************************************************************************
 */

/*******************************************************************************
 *  Function Declaration
 *******************************************************************************
 */

int System_openVxSendNotify(unsigned int cpuId, unsigned int payload);
void System_registerOpenVxNotifyCb(System_openVxNotifyHandler notifyCb);
void System_openVxIpcHandler(unsigned int payload, void *arg);
unsigned int System_ovxPhys2Virt(unsigned int phys_addr);
unsigned int System_ovxVirt2Phys(unsigned int virt_addr);
unsigned int System_ovxCacheWb(unsigned int virt_addr, unsigned int length);
unsigned int System_ovxCacheInv(unsigned int virt_addr, unsigned int length);
unsigned int System_ovxIsValidCMemPhysAddr(unsigned int physAddr);
unsigned int System_ovxIsValidCMemVirtAddr(unsigned int virt_addr);
unsigned int System_ovxGetObjDescShm();

#endif

/* @} */
