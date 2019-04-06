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


#ifndef SYSTEM_LINK_COMMON_H_
#define SYSTEM_LINK_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */

/*******************************************************************************
 *  Enums
 *******************************************************************************
 */

/*******************************************************************************
 *  Data structure's
 *******************************************************************************
 */

/**
 *******************************************************************************
 *  \brief Callback to handle user defined commands
 *
 *  \param cmd [IN] Command that needs to be handled
 *  \param pPrm [IN/OUT] Parameters for this command
 *
 *******************************************************************************
 */
typedef Void (*SystemLink_CmdHandler)(UInt32 cmd, Void *pPrm);

/**
 *******************************************************************************
 *
 *  \brief System Common: Print CPU load, Task Load and Heap Staus..
 *
 *   Defines System Common parameters that are passed when system statistics
 *   print is requested..
 *
 *******************************************************************************
*/

typedef struct {

    UInt32 printCpuLoad;
    /**< [IN] Print CPU load of each core */

    UInt32 printTskLoad;
    /**< [IN] Print CPU loading of each Task*/

    UInt32 printHeapStatus;
    /**< [IN] Print Current Heap status of core*/

} SystemCommon_PrintStatus;


/**
 *******************************************************************************
 *
 *  \brief IP address of system
 *
 *******************************************************************************
 */
typedef struct {

    char ipAddr[32U];
    /**< IP address of the system as string */

} SystemCommon_IpAddr;

/**
 *******************************************************************************
 *
 *  \brief SystemCommon_AllocBuffer defines parameters used to
 *         allocates buffer from IPU managed heap
 *
 *******************************************************************************
 */
typedef struct {
    UInt32 bufferPtr;
    /**< [OUT] pointer to allocated buffer */
    UInt32 heapId;
    /**< [IN] Heap id of the heap to allocate from */
    UInt32 size;
    /**< [IN] Size of the buffer to be allocated */
    UInt32 align;
    /**< [IN] Alignment of the allocated buffer */
} SystemCommon_AllocBuffer;

/**
 *******************************************************************************
 *
 *  \brief SystemCommon_AllocBuffer defines parameters used to
 *         free buffer from IPU managed heap
 *
 *******************************************************************************
 */
typedef struct {
    UInt32 bufferPtr;
    /**< [IN] pointer to allocated buffer */
    UInt32 heapId;
    /**< [IN] Heap id of the heap to allocate from */
    UInt32 size;
    /**< [IN] Size of the buffer to be allocated */
} SystemCommon_FreeBuffer;

/**
 *******************************************************************************
 *
 *  \brief IP address of system
 *
 *******************************************************************************
 */
typedef struct {

    UInt32 procId;
    /**< procId where NDK is running */

} SystemCommon_NetProcId;


/**
 *******************************************************************************
 *
 *  \brief 64-bit Global timer counter value
 *
 *******************************************************************************
 */
typedef struct {

    UInt32 timeH;
    /**< 32bit high value of timer coutner */
    UInt32 timeL;
    /**< 32bit low value of timer coutner */
} SystemCommon_GlobalTime;


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/*@}*/


