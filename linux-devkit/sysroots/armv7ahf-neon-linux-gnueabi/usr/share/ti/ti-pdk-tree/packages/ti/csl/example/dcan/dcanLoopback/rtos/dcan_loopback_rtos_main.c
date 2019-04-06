/*
 *  Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 *  \file     dcan_loopback_rtos_main.c
 *
 *  \brief    This file contains the RTOS specific implementation for
 *			  executing the DCAN test
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/osal/RegisterIntr.h>

#include <ti/csl/example/dcan/dcanLoopback/dcan_loopback_app.h>

/* ========================================================================== */
/*                         Global Variables                                   */
/* ========================================================================== */

extern volatile uint32_t testDone;
uint32_t gDcanAppInstance;
uint32_t msgLstErrCnt, dataMissMatchErrCnt, dcanRxErr = STW_EFAIL;
volatile uint32_t dcanRxDone;
uint32_t intrRegister;
extern int32_t  count;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configure the DCAN interrupts to interrupt controller.
 *
 */
void DCANAppConfigIntr(void);

/**
 * \brief   DCAN Interrupt 0 line service routine. This function will clear the
 *          status of the Tx/Rx message object interrupts. Handles the transmit
 *          interrupts and load the received data in buffer. Also checks for
 *          valid received data.
 *
 */
static void DCANAppIsr();

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 *  ======== DCANAppConfigIntr ========
 */
void DCANAppConfigIntr(void)
{
    CSL_XbarIrq intrSource;
    OsalRegisterIntrParams_t interruptRegParams;
    HwiP_Handle hwiPHandlePtr;
    int32_t retVal = 0;

    if (gDcanAppInstance == DCAN1_APP_INST)
    {
        /* Interrupt source for DCAN instance1 */
        intrSource = CSL_XBAR_DCAN1_IRQ_INT0;
    }
    else
    {
        /* Interrupt source for DCAN instance2 */
        intrSource = CSL_XBAR_DCAN2_IRQ_INT0;
    }
    /* XBar configuration */
#if defined (__ARM_ARCH_7A__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_50, intrSource);
#elif defined (__TI_ARM_V7M4__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_30, intrSource);
#elif defined (_TMS320C6X)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_XBAR_INST_DSP1_IRQ_50, intrSource);
#endif

        /* Initialize with defaults */
        Osal_RegisterInterrupt_initParams(&interruptRegParams);

        /* Populate the interrupt parameters */
        interruptRegParams.corepacConfig.arg = NULL;
        interruptRegParams.corepacConfig.name = NULL;
        interruptRegParams.corepacConfig.isrRoutine = DCANAppIsr;
        interruptRegParams.corepacConfig.priority = 0x20U;
#if defined (__ARM_ARCH_7A__) /* Interrupt Parameters specific to ARM core */
        interruptRegParams.corepacConfig.triggerSensitivity =  OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
        interruptRegParams.corepacConfig.intVecNum = 82; /* Corresponds to MPU_IRQ_50 (32 + MPU_IRQ_50) */
        interruptRegParams.corepacConfig.corepacEventNum = 0;
#elif defined (__TI_ARM_V7M4__) /* Interrupt Parameters specific to M4 core */
        interruptRegParams.corepacConfig.intVecNum = 30; /* Corresponds to IPU1_IRQ_30 */
        interruptRegParams.corepacConfig.corepacEventNum = 0;
#elif defined (_TMS320C6X) /* Interrupt Parameters specific to DSP core */
        interruptRegParams.corepacConfig.intVecNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
        interruptRegParams.corepacConfig.corepacEventNum = 50; /* Corresponds to DSP1_IRQ_50 */
#endif
        /* Register interrupts */
        if( !intrRegister )
        {
        retVal = Osal_RegisterInterrupt(&interruptRegParams, &hwiPHandlePtr);
        if(retVal != OSAL_INT_SUCCESS) {
            PRINT_MSG("\n\nError: Osal_RegisterInterrupt Failed!!!");
        }
        else
            intrRegister = (uint32_t) TRUE;
        }
}
/*
 *  ======== DCANAppIsr ========
 */
static void DCANAppIsr(void)
{
    int32_t retVal = STW_EFAIL;

    msgLstErrCnt = 0U;
    dataMissMatchErrCnt = 0U;
    dcanRxErr = STW_EFAIL;

    if(DCANHasRxMsgArrived(gDcanAppInstance, DCAN_RX_MSG_OBJ) == TRUE)
    {
        retVal = dcanReceiveData(msgLstErrCnt, dataMissMatchErrCnt, count);
        if (retVal == STW_SOK)
        {
            DCANGetErrStatus(gDcanAppInstance);
        }
        dcanRxErr = retVal;
        /* Set the Receive complete Flag */
        dcanRxDone = (uint32_t) TRUE;
    }
}

/*
 *  ======== dcanTestTask ========
 */
Void dcanTestTask(UArg a0, UArg a1)
{
    int32_t retVal = STW_EFAIL;

    /* DCAN Test function call*/
    retVal = execTest();
    if(retVal == STW_SOK)
        while (testDone) ;
}

/*
 *  ======== main ========
 */
Int main()
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);
    /* Create Task to run the DCAN Loopback Test */
    task = Task_create(dcanTestTask, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
    BIOS_start();    /* does not return */
    return(0);
}

/********************************* End of file ******************************/
