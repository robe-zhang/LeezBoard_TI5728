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
 *  \file system_linkId.h
 *  \brief  System Link ID's
 *
 *******************************************************************************
*/

#ifndef SYSTEM_LINK_ID_H_
#define SYSTEM_LINK_ID_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <include/link_api/system_procId.h>

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */

/**
 *******************************************************************************
 *
 * \brief Max possible Link ID
 *
 *******************************************************************************
 */
#define SYSTEM_LINK_ID_MAX                  (128U)

/**
 *******************************************************************************
 *
 * \brief Invalid Link ID
 *
 *******************************************************************************
 */
#define SYSTEM_LINK_ID_INVALID              (0xFFFFFFFFU)

/**
 *******************************************************************************
 *
 * \brief Set the IPU primary core depends on what is set from Rules.make
 *
 *******************************************************************************
*/
#ifdef IPU_PRIMARY_CORE_IPU2
#define SYSTEM_IPU_PROC_PRIMARY (SYSTEM_PROC_IPU2)
#else
#define SYSTEM_IPU_PROC_PRIMARY (SYSTEM_PROC_IPU1_0)
#endif


#define SYSTEM_IPC_PAYLOAD_ROUTE_BIT_MASK    (0x1u)
#define SYSTEM_IPC_PAYLOAD_ROUTE_BIT_SHIFT   (31u)
#define SYSTEM_IPC_PAYLOAD_NOTIFY_TYPE_MASK  (0x7u)
#define SYSTEM_IPC_PAYLOAD_NOTIFY_TYPE_SHIFT (28u)
#define SYSTEM_IPC_PAYLOAD_DST_CPU_ID_MASK   (0xFu)
#define SYSTEM_IPC_PAYLOAD_DST_CPU_ID_SHIFT  (24u)
#define SYSTEM_IPC_PAYLOAD_LINK_ID_MASK      (0xFFFFFFu)

/**
 *******************************************************************************
 *
 * \brief Create link id which indicates the link & processor in which it
 *        resides
 *
 *******************************************************************************
*/
#if defined (IPU_PRIMARY_CORE_IPU1)
#define SYSTEM_MAKE_LINK_ID(p, x) (\
               (((UInt32)((p) & (SYSTEM_IPC_PAYLOAD_DST_CPU_ID_MASK)) << (SYSTEM_IPC_PAYLOAD_DST_CPU_ID_SHIFT))\
                   | ((x) & (SYSTEM_IPC_PAYLOAD_LINK_ID_MASK))\
               )\
           )
#endif
#if defined (IPU_PRIMARY_CORE_IPU2)
#define SYSTEM_MAKE_LINK_ID(p, x) (\
               (((UInt32)(((p == SYSTEM_PROC_IPU1_0)? SYSTEM_PROC_IPU2:p)\
                   & (SYSTEM_IPC_PAYLOAD_DST_CPU_ID_MASK)) << (SYSTEM_IPC_PAYLOAD_DST_CPU_ID_SHIFT))\
                   | ((x) & (SYSTEM_IPC_PAYLOAD_LINK_ID_MASK))\
               )\
           )
#endif

/**
 *******************************************************************************
 *
 * \brief Get the link id - strip off proc id
 *
 *******************************************************************************
*/
#define SYSTEM_GET_LINK_ID(x)     ((x) & SYSTEM_IPC_PAYLOAD_LINK_ID_MASK)

/**
 *******************************************************************************
 *
 * \brief Get the proc id - strip off link id
 *
 *******************************************************************************
*/
#define SYSTEM_GET_PROC_ID(x)     (((x) >> SYSTEM_IPC_PAYLOAD_DST_CPU_ID_SHIFT) & (SYSTEM_IPC_PAYLOAD_DST_CPU_ID_MASK))

/**
 *******************************************************************************
 *
 * \brief Set route bit - bit 32 of LinkId is used as route bit
 *        This is used only when message needs to be routed through
 *        some other core.
 *
 *******************************************************************************
*/
#define SYSTEM_LINK_ID_SET_ROUTE_BIT(x)    ((x) |= (1U << SYSTEM_IPC_PAYLOAD_ROUTE_BIT_SHIFT))

/**
 *******************************************************************************
 *
 * \brief Clear route bit
 *
 *******************************************************************************
*/
#define SYSTEM_LINK_ID_CLEAR_ROUTE_BIT(x)  ((x) &= ~((1U) << SYSTEM_IPC_PAYLOAD_ROUTE_BIT_SHIFT))

/**
 *******************************************************************************
 *
 * \brief Test route bit
 *
 *******************************************************************************
*/
#define SYSTEM_LINK_ID_TEST_ROUTE_BIT_TRUE(x)  ((x) & (1U << SYSTEM_IPC_PAYLOAD_ROUTE_BIT_SHIFT))

#define SYSTEM_LINK_ID_NOTIFY_TYPE_OPENVX          (3U)
/**
 *******************************************************************************
 *
 * \brief Set route bit - bit 32 of LinkId is used as route bit
 *        This is used only when message needs to be routed through
 *        some other core.
 *
 *******************************************************************************
*/
#define SYSTEM_LINK_ID_MAKE_NOTIFY_TYPE(dest_p, src_p, t)       \
    ( SYSTEM_MAKE_LINK_ID((dest_p), (src_p)) | ( (UInt32)( (t) & SYSTEM_IPC_PAYLOAD_NOTIFY_TYPE_MASK ) << SYSTEM_IPC_PAYLOAD_NOTIFY_TYPE_SHIFT) )

/**
 *******************************************************************************
 *
 * \brief Test route bit
 *
 *******************************************************************************
*/
#define SYSTEM_LINK_ID_GET_NOTIFY_TYPE(x)    (((x) >> SYSTEM_IPC_PAYLOAD_NOTIFY_TYPE_SHIFT) & SYSTEM_IPC_PAYLOAD_NOTIFY_TYPE_MASK)

#ifdef  __cplusplus
}
#endif

#endif

/*@}*/

