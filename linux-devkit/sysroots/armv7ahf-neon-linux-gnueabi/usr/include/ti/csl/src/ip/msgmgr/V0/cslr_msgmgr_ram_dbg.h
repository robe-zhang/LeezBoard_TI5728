/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_MSGMGRRAMDBG_H_
#define CSLR_MSGMGRRAMDBG_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 NEXT_INDEX_REG[128];
} CSL_MsgmgrRamDbgRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* This register holds the contexts (next index) of index m where m is 0 to
 * 127. */
#define CSL_MSGMGRRAMDBG_NEXT_INDEX_REG(i)                      (0x0U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* NEXT_INDEX_REG */

#define CSL_MSGMGRRAMDBG_NEXT_INDEX_REG_VAL_MASK                (0x00000FFFU)
#define CSL_MSGMGRRAMDBG_NEXT_INDEX_REG_VAL_SHIFT               (0U)
#define CSL_MSGMGRRAMDBG_NEXT_INDEX_REG_VAL_RESETVAL            (0x00000000U)
#define CSL_MSGMGRRAMDBG_NEXT_INDEX_REG_VAL_MAX                 (0x00000fffU)

#define CSL_MSGMGRRAMDBG_NEXT_INDEX_REG_RESETVAL                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
