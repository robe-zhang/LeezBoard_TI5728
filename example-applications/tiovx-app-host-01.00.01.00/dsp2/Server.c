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
#include <xdc/runtime/Memory.h>

/* package header files */
#include <ti/ipc/Notify.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Ipc.h>
#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/SharedRegion.h>

#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/syncs/SyncSem.h>
#include <ti/ipc/remoteproc/Resource.h>

#include <string.h>
/* local header files */
#include "../shared/AppCommon.h"
#include <include/link_api/system_common.h>
#include <include/link_api/system_if.h>
#include <src/rtos/links_common/system/system_priv_openvx.h>

/* module header file */
#include "Server.h"

extern Int DSP1_ID, DSP2_ID;
//This should be set to ocmc3 virtual address, after receiving host CFG message
Uint32 gTivxProcSdkDescShmEntry = 0x88000000;
Uint32 gTivxProcSdkDescShmSize  = 512 * 1024;

System_openVxNotifyHandler govx_notifyCb = NULL;
/* module structure */
typedef struct {
    UInt16              hostProcId;         // host processor id
    MessageQ_Handle     rxQue;              // created locally
    MessageQ_QueueId    remoteDsp_queId;   // Opened queue handle
    MessageQ_QueueId    remoteIpu1_queId;   // Opened queue handle
    MessageQ_QueueId    remoteHost_queId;   // Opened queue handle
    UInt32              msgSize;
    HeapBufMP_Handle    srHeapHandle;

    Semaphore_Handle    sem;
    Semaphore_Handle    semRcv;
} Server_Module;

/* private data */
Registry_Desc               Registry_CURDESC;
static Server_Module        Module;
/*******************************/
static Void Server_setupSharedRegion(UInt32 baseSR, UInt32 sizeSR)
{ /* Owner first needs to create shared region, via setEntry! */
 int retval = 0;
 unsigned int va;
    SharedRegion_Entry shEntry;
    SharedRegion_entryInit(&shEntry);
    Resource_physToVirt(baseSR, &va);
    shEntry.base = (Ptr)va;
    shEntry.len  = sizeSR;
    shEntry.ownerProcId = 4; //DSP1
    shEntry.isValid     = 1;
    shEntry.cacheEnable = 1;
    shEntry.cacheLineSize = 128; //512?
    shEntry.createHeap = TRUE;
    shEntry.name = "TIOVX_SR";
    retval = SharedRegion_setEntry(2, &shEntry);
    Log_print4(Diags_INFO, "ShReg_setEntry return:%d (baseSR=%08x, virtSR=%08x, size=%08x)", retval, baseSR, va, sizeSR);
}
/***********/
static void Server_dumpSharedRegions(void)
{
int i, cnt;
  SharedRegion_Entry shEntry;
  Log_print1(Diags_INFO,"Total number of shared regions:%d", cnt = SharedRegion_getNumRegions());
    for (i = 0; i < cnt; i ++) {
       SharedRegion_getEntry(i, &shEntry);
       Log_print5(Diags_INFO, "[%d] base=%08x len=%08x owner=%d isValid=%d", i, 
                  (unsigned int)shEntry.base, (unsigned int)shEntry.len, (unsigned short)shEntry.ownerProcId, (int)shEntry.isValid); 
       Log_print5(Diags_INFO, "[%d] cacheEnable=%d cacheLineSize=%d createHeap=%d name=%s", i, 
                  (int)shEntry.cacheEnable, (unsigned int)shEntry.cacheLineSize, (int)shEntry.createHeap, (int)shEntry.name); 
    }
}
/*
 *  ======== Server_configure =======
 */
Int Server_configure (UInt32 *payload)
{
Int status;
UInt32 ddr_phaddr, ddr_va, ddr_size;
UInt32 ocmc3_phaddr, ocmc3_va, ocmc3_size;

   Log_print1(Diags_INFO, "Server_expect: CFG message, with payload:%08x", payload[0]);
   ddr_phaddr = payload[2];
   ddr_size   = payload[3];
   status = Resource_physToVirt(ddr_phaddr, &ddr_va);
   Log_print3(Diags_INFO, "Server_expect: ddr physAddres %08x -> virtAddress %08x, size=%08x ", ddr_phaddr, ddr_va, ddr_size);
   ocmc3_phaddr = payload[0];
   ocmc3_size   = payload[1];
   status = Resource_physToVirt(ocmc3_phaddr, &ocmc3_va);
#if 0
   // Set shared memory segment base address and size
   gTivxProcSdkDescShmEntry = ocmc3_va;
   gTivxProcSdkDescShmSize  = ocmc3_size;
#endif
   Log_print3(Diags_INFO, "Server_expect: ddr physAddres %08x -> virtAddress %08x, size=%08x ", ocmc3_phaddr, ocmc3_va, ocmc3_size);

   /* open HOST message queue */
   do {
     status = MessageQ_open(TIOVX_RxHost, &Module.remoteHost_queId);
     Task_sleep(1);
   } while (status == MessageQ_E_NOTFOUND);

   if (status < 0) {
     Log_print0(Diags_INFO,"Server_expect: Failed opening MessageQ to HOST");
     return -1;
   }
   Server_setupSharedRegion(ddr_phaddr, ddr_size);
   Log_print0(Diags_INFO,"Server_expect: remoteHOST que opened");
   return 0;
}

/*
 *  ======== Server_expectMsgFxn ========
 */
Void Server_expectMsgFxn(UArg arg0, UArg arg1)
{
    MessageQ_Params     msgqParams;
    tiovxMsg_t         *msg;
    Int status = 0;
    UInt32 payload[MAX_PAYLOAD], cmd;

    /* create local message queue (inbound messages) */
    MessageQ_Params_init(&msgqParams);
    if(MultiProc_self() == DSP1_ID) {
      Module.rxQue = MessageQ_create(TIOVX_RxDsp1, &msgqParams);
      Log_print2(Diags_INFO, "Thread loopbackFxn: %d queName=%s", arg0, TIOVX_RxDsp1);
    } else {
      Module.rxQue = MessageQ_create(TIOVX_RxDsp2, &msgqParams);
      Log_print2(Diags_INFO, "Thread loopbackFxn: %d queName=%s", arg0, TIOVX_RxDsp2);
    }
    if (Module.rxQue == NULL) return;

    
    while(1)
    {
        status = MessageQ_get(Module.rxQue, (MessageQ_Msg *)&msg, MessageQ_FOREVER);
        if (status < 0) {
          Log_print1(Diags_INFO, "Server_expect: MessageQ_get returned bad status:%d", status);
          continue;
        }
        cmd = msg->cmd;
        memcpy (payload, msg->payload, MAX_PAYLOAD * sizeof(UInt32));
        MessageQ_free((MessageQ_Msg)msg);
        if(cmd == App_CMD_CFG) {
          Server_configure(payload);
        } else {
          if(govx_notifyCb) {
            Log_print2(Diags_INFO, "Server_expect: Received, cmd:%08x payload:%08x ", cmd, payload[0]);
            govx_notifyCb(payload[0]);
          }
        }
    }
    Log_print0(Diags_INFO, "Thread loopbackFxn EXIT");
}

/***********/
Int Server_setupDsp2DspMsgHeap(Void)
{
    HeapBufMP_Params    heapBufParams;
    Int status = 0;
    /* enable some log events */
    /*
     *  Create the heap that will be used to allocate messages for DSP2DSP communication.
     */
    if(MultiProc_self() == MultiProc_getId("DSP1"))
    {
      Log_print0(Diags_INFO,"Creating HeapBufMP...");
      HeapBufMP_Params_init(&heapBufParams);
      heapBufParams.regionId       = 0;
      heapBufParams.name           = App_SrHeapName;
      heapBufParams.numBlocks      = 4;
      heapBufParams.blockSize      = sizeof(tiovxMsg_t);
      Module.srHeapHandle = HeapBufMP_create(&heapBufParams);
      if (Module.srHeapHandle == NULL) {
        Log_print0(Diags_INFO,"HeapBufMP_create failed\n" );
        return -1;
      }
      Log_print0(Diags_INFO,"Done with creating HeapBufMP...");
    } else {
      Log_print0(Diags_INFO,"Opening HeapBufMP...");
      /* Open the heap created by the other processor. Loop until opened. */
      do {
        status = HeapBufMP_open(App_SrHeapName, &Module.srHeapHandle);
        /*
         *  Sleep for 1 clock tick to avoid inundating remote processor
         *  with interrupts if open failed
         */
        if (status < 0) {
            Task_sleep(1);
        }
      } while (status < 0);
    }
    return 0;
}
/***********/
static unsigned int log_offset = 0;
Int Server_sendNotify(UInt32 cpuId, UInt32 payload)
{
    tiovxMsg_t *msgSnd;
    msgSnd = (tiovxMsg_t *)MessageQ_alloc(App_SrHeapId, Module.msgSize);
    msgSnd->cmd     = App_CMD_TEST;
    msgSnd->payload[0] = payload;
    /* Send message to another CPU */
    /** This is mimicking VISIONSDK CPU encodings, as defined in ./include/VSDK/include/link_api/system_procId.h */
    if(cpuId == 4) {
      Log_print0(Diags_INFO, "...to DSP2 ...");
      MessageQ_put(Module.remoteDsp_queId, (MessageQ_Msg)msgSnd);
    } else if(cpuId == 3) {
      Log_print0(Diags_INFO, "...to DSP1 ...");
      MessageQ_put(Module.remoteDsp_queId, (MessageQ_Msg)msgSnd);
    } else if(cpuId == 0) {
      Log_print0(Diags_INFO, "...to IPU1 ...");
      MessageQ_put(Module.remoteIpu1_queId, (MessageQ_Msg)msgSnd);
    } else if(cpuId == 2) {
      Log_print0(Diags_INFO, "...to HOST ...");
      MessageQ_put(Module.remoteHost_queId, (MessageQ_Msg)msgSnd);
    } else {
      Log_print0(Diags_INFO, "...non routable!!! ...");
      return -1;
    }
    return 0;
}
/*
 *  ======== Server_init ========
 */
Void Server_init(Void)
{
    Int status = 0;
    Registry_Result result;

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* initialize module object state */
    Module.hostProcId = MultiProc_getId("HOST");
    Module.msgSize = sizeof(tiovxMsg_t);
    Module.srHeapHandle = NULL;
    Module.rxQue = NULL;
    //memset ((char *)gTivxProcSdkDescShmEntry, 0, 512 * 1024);
    Server_dumpSharedRegions();
}
/*
 *  ======== Server_create ========
 */
Int Server_create()
{
    Int                 status = 0;
    MessageQ_Params     msgqParams;
    Semaphore_Params    semP;
    if(Server_setupDsp2DspMsgHeap() < 0) goto leave;

    /* Register this heap with MessageQ */
    MessageQ_registerHeap((IHeap_Handle)Module.srHeapHandle, App_SrHeapId);

    Log_print0(Diags_INFO,"Server_create: heap registered");
    /* open the other DSP slave's message queue */
    do {
      if(MultiProc_self() == DSP1_ID) {
        status = MessageQ_open(TIOVX_RxDsp2, &Module.remoteDsp_queId);
      } else {
        status = MessageQ_open(TIOVX_RxDsp1, &Module.remoteDsp_queId);
      }
      Task_sleep(1);
    } while (status == MessageQ_E_NOTFOUND);

    if (status < 0) {
      Log_print0(Diags_INFO,"Server_exec: Failed opening MessageQ to remote DSP");
      goto leave;
    }
    Log_print0(Diags_INFO,"Server_create: remoteDSP que opened");
leave:
    Log_print1(Diags_EXIT, "<-- Server_create: %d", (IArg)status);
    return (status);
}


/*
 *  ======== Server_delete ========
 */
Int Server_delete()
{
    Int         status;

    Log_print0(Diags_ENTRY, "--> Server_delete:");
    /* close remote message queue */
    status = MessageQ_close(&Module.remoteDsp_queId);
    if (status < 0) {
        goto leave;
    }

    /* delete the local message queue */
    status = MessageQ_delete(&Module.rxQue);
    if (status < 0) {
        goto leave;
    }

    /* Unregister the SR heap from MessageQ module */
    status = MessageQ_unregisterHeap(App_SrHeapId);
    if (status < 0) {
        goto leave;
    }

    status = HeapBufMP_delete(&Module.srHeapHandle);
    if (status < 0) {
        goto leave;
    }

leave:
    if (status < 0) {
        Log_error1("Server_finish: error=0x%x", (IArg)status);
    }

    /* disable log events */
    Log_print1(Diags_EXIT, "<-- Server_delete: %d", (IArg)status);
    Diags_setMask(MODULE_NAME"-EXF");

    return(status);
}
/*
 *  ======== Server_exit ========
 */
Void Server_exit(Void)
{
    /*
     * Note that there isn't a Registry_removeModule() yet:
     *     https://bugs.eclipse.org/bugs/show_bug.cgi?id=315448
     *
     * ... but this is where we'd call it.
     */
    Log_print0(Diags_INFO, "<-- Server_exit:");

}
