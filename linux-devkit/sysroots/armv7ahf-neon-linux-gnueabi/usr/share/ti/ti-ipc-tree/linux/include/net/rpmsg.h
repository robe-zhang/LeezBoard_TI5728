/*
 * Remote processor messaging sockets
 *
 * Copyright (c) 2011-2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Ohad Ben-Cohen <ohad@wizery.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __NET_RPMSG_H
#define __NET_RPMSG_H

#include <linux/types.h>
#include <sys/socket.h>

/* user space needs this */
#ifndef AF_RPMSG
#ifdef IPC_BUILDOS_ANDROID
#include <uapi/linux/version.h>
#else
#include <linux/version.h>
#endif
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,9,0)
#define AF_RPMSG        40
#elif LINUX_VERSION_CODE < KERNEL_VERSION(4,6,0)
#define AF_RPMSG        41
#elif LINUX_VERSION_CODE < KERNEL_VERSION(4,7,0)
#define AF_RPMSG        42
#elif LINUX_VERSION_CODE < KERNEL_VERSION(4,11,0)
#define AF_RPMSG        43
#else
#define AF_RPMSG        44
#endif /* LINUX_VERSION_CODE */
#endif /* AF_RPMSG */

/* Connection and socket states */
enum {
        RPMSG_CONNECTED = 1, /* wait_for_packet() wants this... */
        RPMSG_OPEN,
        RPMSG_LISTENING,
        RPMSG_CLOSED,
};

struct sockaddr_rpmsg {
        sa_family_t family;
        __u32 vproc_id;
        __u32 addr;
};

#define RPMSG_LOCALHOST ((__u32) ~0UL)

#endif /* __NET_RPMSG_H */
