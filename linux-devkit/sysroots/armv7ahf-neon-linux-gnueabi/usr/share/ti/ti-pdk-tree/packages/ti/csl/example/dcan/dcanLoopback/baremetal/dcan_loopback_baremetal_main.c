/*
 *  Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file     dcan_loopback_baremetal_main.c
 *
 *  \brief    This file contains the bare-metal specific implementation for
 *			  executing the DCAN test
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/example/dcan/dcanLoopback/dcan_loopback_app.h>

/* ========================================================================== */
/*                         Global Variables                                   */
/* ========================================================================== */

extern char gMainMenuOption;
extern volatile uint32_t testDone;
uint32_t gDcanAppInstance;

#if defined (SOC_TDA3XX)
extern dcanEccErrStatus_t     gErrClr;
extern uint32_t               gMsgObjSBE;
extern uint32_t               gMsgObjDBE;
#endif
#if defined (SOC_TDA2EX) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX)
extern uint32_t               gMsgObj;
extern uint32_t               gWordNum;
#endif

#if defined (SOC_TDA2EX) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA3XX)
/**
 * \brief   DCAN Parity Error Interrupt Service Routine. This function checks
 *          and handles parity error.
 *
 */
static void DCANAppParityIsr();
#endif

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

extern void padConfig_prcmEnable(void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 *  ======== main ========
 */
int main(void)
{
    int32_t retVal   = STW_SOK;

    retVal = execTest();

    while (testDone);
    return retVal;
}

#if defined (SOC_TDA3XX) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX)
/*
 *  ======== DCAN Parity Error interrupt Configuration ========
 */
void DCANAppConfigParityIntr(void)
{
    CSL_XbarIrq intrSource;

    if (gDcanAppInstance == DCAN1_APP_INST)
    {
        intrSource = CSL_XBAR_DCAN1_IRQ_PARITY;
    }
    else
    {
        intrSource = CSL_XBAR_DCAN2_IRQ_PARITY;
    }
    /* XBar configuration */
    CSL_xbarIrqConfigure(XBAR_CPU,XBAR_INST,intrSource);

    Intc_Init();
    Intc_IntEnable(APP_DCAN_INT);
    Intc_IntRegister(APP_DCAN_INT, (IntrFuncPtr) DCANAppParityIsr, (void *) 0);
    Intc_IntPrioritySet(APP_DCAN_INT, 1, 0);
    Intc_SystemEnable(APP_DCAN_INT);
}

/*
 *  ======== DCAN Parity Error Interrupt Service Routine ========
 */
static void DCANAppParityIsr()
{
    uint32_t errStatus;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    errStatus = DCANGetEccErrStatus(gDcanAppInstance);

    gErrClr.singleBitErr = (errStatus & DCAN_ECC_CSR_SE_FLAG_MASK);
    gErrClr.doubleBitErr = ((errStatus & DCAN_ECC_CSR_DE_FLAG_MASK) >>
                            DCAN_ECC_CSR_DE_FLAG_SHIFT);

    DCANClrEccErrStatus(gDcanAppInstance, &gErrClr);

    if (gErrClr.singleBitErr)
    {
        gMsgObjSBE = DCANGetMsgObjBitErrDetected(gDcanAppInstance);
    }

    if (gErrClr.doubleBitErr)
    {
        errStatus  = DCANGetParityErrStatus(gDcanAppInstance);
        gMsgObjDBE = (errStatus & DCAN_PERR_MESSAGE_NUMBER_MASK);
    }
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_DRA72x) || defined (SOC_DRA75x)
    errStatus = DCANGetParityErrStatus(gDcanAppInstance);
    gMsgObj   = (errStatus & DCAN_PERR_MESSAGE_NUMBER_MASK);
    gWordNum  = ((errStatus & DCAN_PERR_WORD_NUMBER_MASK) >>
                 DCAN_PERR_WORD_NUMBER_SHIFT);
#endif

    DCANClrParityIntrStatus(gDcanAppInstance);
}
#endif
/********************************* End of file ******************************/
