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
 *  ======== main_Dsp1.c ========
 *
 */

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MultiProc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "Server.h"
#include "rsc_table.h"

#ifdef OPENVX_INCLUDE
#include <TI/tivx.h>
#include <include/link_api/system_common.h>
#include <include/link_api/system_if.h>
#include <src/rtos/links_common/system/system_priv_openvx.h>
#endif

/* private functions */
static Void smain(UArg arg0, UArg arg1);
extern Void Server_expectMsgFxn(UArg arg0, UArg arg1);
extern System_openVxNotifyHandler govx_notifyCb;
/************************************************************************************/
Int DSP1_ID = -1;
Int DSP2_ID = -1;
/************************************************************************************/
Void Identify_allParticipants(Void)
{
UInt16 i, base_of_cluster, end_of_cluster, num_procs;

base_of_cluster = MultiProc_getBaseIdOfCluster();
num_procs       = MultiProc_getNumProcessors();
end_of_cluster = base_of_cluster + num_procs;
Log_print0(Diags_INFO, "MULTIPROC cluster");
for (i = base_of_cluster; i < end_of_cluster; i ++)
{
   if(i == MultiProc_self()) {
     Log_print2(Diags_INFO, "=>Proc:%02d name=%s", i, MultiProc_getName(i));
   } else {
     Log_print2(Diags_INFO, "Proc:%02d name=%s", i, MultiProc_getName(i));
   }
   if(strcmp(MultiProc_getName(i), "DSP1") == 0) DSP1_ID = (Int)i;
   if(strcmp(MultiProc_getName(i), "DSP2") == 0) DSP2_ID = (Int)i;
}
Log_print2(Diags_INFO, "======DSP1_ID=%d DSP2_ID=%d===============", DSP1_ID, DSP2_ID);

}
/************************************************************************************/
Void System_report(char *report_log)
{
  Log_print0(Diags_INFO, report_log);
}
/************************************************************************************/
static Void Server_setupRxMsgTask(Void)
{
    /*******************************************************/
    Task_Params params;
    /* Create N threads to correspond with host side N thread test app: */
    Task_Params_init(&params);
    params.priority = 3;
    params.arg0     = 0;
    params.stackSize = 0x2000;
    Log_print1(Diags_INFO, "TASK_CREATE setupRxMsgTask=%08x", (UInt32)Task_create(Server_expectMsgFxn, &params, NULL));
}
/************************************************************************************/
Int Server_prepareIpc(void)
{
Int status = 0;
   Log_print0(Diags_INFO,"MainDsp: Before DSP2 attach");
   /* Attach to other slave */
   do {
     if(MultiProc_self() == DSP1_ID) {
       status = Ipc_attach(MultiProc_getId("DSP2"));
     } else {
       status = Ipc_attach(MultiProc_getId("DSP1"));
     }
     Task_sleep(1);
   } while (status == Ipc_E_NOTREADY);

   if (status < 0) {
       Log_print0(Diags_INFO,"smain: attach failed");
       return -1;
   }
   Log_print0(Diags_INFO,"MainDsp: attached now to remote DSP");

   /* Start RX task */
   Server_setupRxMsgTask();
   Server_create();
   Log_print0(Diags_INFO, "smain: prepareIpc DONE");
   return 0;
}
/************************************************************************************/
Int Server_attachIpc(System_openVxNotifyHandler notifyCb)
{
Int status = 0;
   status = Server_prepareIpc();
   govx_notifyCb = notifyCb;
   Log_print1(Diags_INFO, "smain: notifyCB function:%08x", (UInt32)notifyCb);
   return status;
}
/************************************************************************************/
/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    Error_Block     eb;
    Task_Params     taskParams;

    Log_print0(Diags_ENTRY, "--> main:");
    /* must initialize the error block before using it */
    Error_init(&eb);

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "smain";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x2000;
    Log_print1(Diags_INFO, "TASK_CREATE setupRxMsgTask=%08x", (UInt32)Task_create(smain, &taskParams, &eb));
    if (Error_check(&eb)) {
        System_abort("main: failed to create application startup thread");
    }
    /* start scheduler, this never returns */
    BIOS_start();

    /* should never get here */
    return (0);
}


/*
 *  ======== smain ========
 */
Void smain(UArg arg0, UArg arg1)
{
    Int                 status = 0;
    Error_Block         eb;

    Log_print0(Diags_ENTRY | Diags_INFO, "--> smain:");

    Error_init(&eb);
    /* turn on Diags_INFO trace */
    Diags_setMask("Server+F");
    Log_print0(Diags_ENTRY | Diags_INFO, "--> tivx dsp2 entering...:");
    Task_sleep(50);
    Identify_allParticipants();
    /* initialize modules */
    Server_init();

    Diags_setMask("Server+F");
    Log_print0(Diags_INFO,"MainDsp: Entering main loop");
    /* loop forever */
         Log_print0(Diags_INFO,"MainDsp: Before tivxInit!");
         tivxInit();
         for ( ; ; )
         {
           Task_sleep(1);
         }
        /* server shutdown phase */
        status = Server_delete();
        if (status < 0) {
            goto leave;
        }
        /* END server phase */
        /* Detach from other slave */
        Log_print0(Diags_INFO, "About to detach from remote DSP");
        do {
            if(MultiProc_self() == DSP1_ID) {
              status = Ipc_detach(MultiProc_getId("DSP2"));
            } else {
              status = Ipc_detach(MultiProc_getId("DSP1"));
            }
        } while (status == Ipc_E_NOTREADY);
        if (status < 0) {
            Log_print0(Diags_INFO,"smain: detach failed");
            goto leave;
        }
        Log_print0(Diags_INFO, "About to detach from IPU1");
        do {
            status = Ipc_detach(MultiProc_getId("IPU1"));
        } while (status == Ipc_E_NOTREADY);

        if (status < 0) {
            Log_print0(Diags_INFO,"smain: detach failed");
            goto leave;
        }
        Task_sleep(3000); 
        /* Detach from other slave */

    /* finalize modules */
    Server_exit();

leave:
    Log_print1(Diags_EXIT, "<-- smain: %d", (IArg)status);
    return;
}
