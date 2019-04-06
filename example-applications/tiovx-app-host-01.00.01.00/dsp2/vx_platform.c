/*
 * Copyright (c) 2013-2014, Texas Instruments Incorporated
 * All rights reserved.
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

/*
 *  ======== Server.c ========
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC Test__Desc
#define MODULE_NAME "Server"

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/IHeap.h>
#include <ti/ipc/Notify.h>

/* package header files */
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Ipc.h>
#include <ti/ipc/HeapBufMP.h>

#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/syncs/SyncSem.h>
#include <ti/ipc/remoteproc/Resource.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* local header files */
#include "../shared/AppCommon.h"
#include <include/link_api/system_procId.h>
#include <include/link_api/system_common.h>
#include <src/utils_common/include/utils_mem.h>
#include <src/rtos/links_common/system/system_priv_openvx.h>

extern Int Server_attachIpc(System_openVxNotifyHandler notifyCb);
extern Int Server_sendNotify(UInt32 cpuId, UInt32 payload);
extern Void System_report(char *report_log);
extern Uint32 gTivxProcSdkDescShmEntry;
extern Uint32 gTivxProcSdkDescShmSize;
/**
 *******************************************************************************

 *******************************************************************************
 */
//Void *System_getProcSdkDescShmEntry(void)
Void *System_openvxGetObjDescShm(unsigned int *shm_size)
{
   *shm_size = gTivxProcSdkDescShmSize;
   return (Void *)gTivxProcSdkDescShmEntry;
}
/**
 *******************************************************************************
 *
 * \brief Returns processor ID on which function is called.
 *
 *        Returns the processor id on which this function is getting called.
 *        Suppose code on DSP calls this function it returns processor id as
 *        DSP
 *
 * \return  ProcessorId for valid processor else SYSTEM_PROC_INVALID
 *
 *******************************************************************************
 */
UInt32 System_getSelfProcId(void)
{
    static UInt32 selfProcId = SYSTEM_PROC_INVALID;
    UInt16 syslinkProcId;
    String procName;

    if(selfProcId!=SYSTEM_PROC_INVALID)
    {
        /*  find self proc ID only once, since it never changes run-time
        *  Doing this optimization since, this API is called for every
        *  System_linkXxxx API
        */
    }
    else
    {
        syslinkProcId = MultiProc_self();
        procName = MultiProc_getName(syslinkProcId);

        if((procName==NULL) || (syslinkProcId >= SYSTEM_PROC_MAX))
        {
            selfProcId = SYSTEM_PROC_INVALID;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_DSP1)==0)
        {
            selfProcId = SYSTEM_PROC_DSP1;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_DSP2)==0)
        {
            selfProcId = SYSTEM_PROC_DSP2;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_EVE1)==0)
        {
            selfProcId = SYSTEM_PROC_EVE1;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_EVE2)==0)
        {
            selfProcId = SYSTEM_PROC_EVE2;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_EVE3)==0)
        {
            selfProcId = SYSTEM_PROC_EVE3;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_EVE4)==0)
        {
            selfProcId = SYSTEM_PROC_EVE4;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_IPU1_0)==0)
        {
            selfProcId = SYSTEM_PROC_IPU1_0;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_IPU1_1)==0)
        {
            selfProcId = SYSTEM_PROC_IPU1_1;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_IPU2)==0)
        {
            selfProcId = SYSTEM_PROC_IPU2;
        }
        else if(strcmp(procName, SYSTEM_IPC_PROC_NAME_A15_0)==0)
        {
            selfProcId = SYSTEM_PROC_A15_0;
        }
        else
        {
            selfProcId = SYSTEM_PROC_INVALID;
        }
    }
    return selfProcId;
}

Int32 System_openvxIsProcEnabled(UInt32 cpu_enabled)
{
Int32 retval = 0;

    switch(cpu_enabled)
    {
      case SYSTEM_PROC_DSP1:
      case SYSTEM_PROC_DSP2:
      case SYSTEM_PROC_A15_0:
        retval = 1;
        break;
        
      case SYSTEM_PROC_EVE1:
      case SYSTEM_PROC_EVE2:
      case SYSTEM_PROC_EVE3:
      case SYSTEM_PROC_EVE4:
      case SYSTEM_PROC_IPU1_0:
      case SYSTEM_PROC_IPU1_1:
      case SYSTEM_PROC_IPU2:
      default:
        retval = 0;
        break;
    }
    return retval;
}

Int32 System_openVxSendNotify(UInt32 cpuId, UInt32 payload)
{
  //System_report("VXSENDNOTIFY");
  return Server_sendNotify (cpuId, payload);
}

Void System_registerOpenVxNotifyCb(System_openVxNotifyHandler notifyCb)
{ 
UInt32 phaddr;

  Utils_memInit();

  if(Server_attachIpc(notifyCb) < 0) {
     System_report("VPXINIT DSP failed");
  }

  //Resource_virtToPhys(0x950c0000, &phaddr);
  //Log_print1(Diags_INFO, "FIND PHYSADDR OF 0x950c0000: %08x", phaddr);

  System_report("VPXINIT DSP success");
}
Void System_openvxActivate(void)
{
}
Void System_openvxDeactivate(void)
{
}

