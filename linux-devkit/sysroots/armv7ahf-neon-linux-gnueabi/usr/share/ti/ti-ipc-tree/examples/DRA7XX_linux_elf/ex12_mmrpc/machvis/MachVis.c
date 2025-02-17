/*
 * Copyright (c) 2013-2015, Texas Instruments Incorporated
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
 *  ======== MachVis.c ========
 */
#include <stdio.h>
#include <assert.h>

#include <ti/ipc/mm/MmRpc.h>

#include "MachVis.h"
#include "MachVis_skel.h"

/* hande used for remote communication */
static MmRpc_Handle MachVis_mmrpc = NULL;

#define MachVis_OFFSET(base, member) ((uint_t)(member) - (uint_t)(base))

/*
 *  ======== MachVis_initialize ========
 */
int MachVis_initialize(void)
{
    int status;
    MmRpc_Params args;

    /* create remote server insance */
    MmRpc_Params_init(&args);

    status = MmRpc_create(MachVis_SERVICE, &args, &MachVis_mmrpc);

    if (status < 0) {
        printf("MachVis_initialize: Error: MmRpc_create failed (%d)\n", status);
        status = -1;
    }
    else {
        status = 0;
    }

    return(status);
}

/*
 *  ======== MachVis_finalize ========
 */
void MachVis_finalize(void)
{
    /* delete remote server instance */
    if (MachVis_mmrpc != NULL) {
        MmRpc_delete(&MachVis_mmrpc);
    }
}

/*
 *  ======== MachVis_add ========
 */
int32_t MachVis_add(int32_t a, int32_t b)
{
    MmRpc_FxnCtx *fxnCtx;
    int32_t fxnRet;
    char send_buf[512] = {0};
    int status;

    assert(MachVis_mmrpc != NULL);

    /* marshall function arguments into the send buffer */
    fxnCtx = (MmRpc_FxnCtx *)send_buf;

    fxnCtx->fxn_id = MachVis_FxnId_add;
    fxnCtx->num_params = 2;
    fxnCtx->params[0].type = MmRpc_ParamType_Scalar;
    fxnCtx->params[0].param.scalar.size = sizeof(int);
    fxnCtx->params[0].param.scalar.data = a;
    fxnCtx->params[1].type = MmRpc_ParamType_Scalar;
    fxnCtx->params[1].param.scalar.size = sizeof(int);
    fxnCtx->params[1].param.scalar.data = b;
    fxnCtx->num_xlts = 0;

    /* invoke the remote function call */
    status = MmRpc_call(MachVis_mmrpc, fxnCtx, &fxnRet);

    if (status < 0) {
        printf("MachVis_add: Error: MmRpc_call failed\n");
        fxnRet = -1;
    }

    return(fxnRet);
}

/*
 *  ======== MachVis_compute ========
 */
int32_t MachVis_compute(MachVis_Compute *compute)
{
    MmRpc_FxnCtx *fxnCtx;
    MmRpc_Xlt xltAry[2];
    int32_t fxnRet;
    char send_buf[512] = {0};
    int status;

    /* marshall function arguments into the send buffer */
    fxnCtx = (MmRpc_FxnCtx *)send_buf;

    fxnCtx->fxn_id = MachVis_FxnId_compute;
    fxnCtx->num_params = 1;
    fxnCtx->params[0].type = MmRpc_ParamType_Ptr;
    fxnCtx->params[0].param.ptr.size = sizeof(MachVis_Compute);
    fxnCtx->params[0].param.ptr.addr = (size_t)compute;
    fxnCtx->params[0].param.ptr.handle = 0;
#if !defined(OS_QNX)
    /* In Linux, set this to a valid allocator handle */
//  fxnCtx->params[0].param.ptr.handle = ...;
    assert(fxnCtx->params[0].param.ptr.handle != 0);
#endif

    fxnCtx->num_xlts = 2;
    fxnCtx->xltAry = xltAry;

    fxnCtx->xltAry[0].index = 0;
    fxnCtx->xltAry[0].offset = MmRpc_OFFSET(compute, &compute->inBuf);
    fxnCtx->xltAry[0].handle = 0;
#if !defined(OS_QNX)
    /* In Linux, set this to a valid allocator handle */
//  fxnCtx->xltAry[0].handle = ...;
    assert(fxnCtx->xltAry[0].handle != 0);
#endif

    fxnCtx->xltAry[1].index = 0;
    fxnCtx->xltAry[1].offset = MmRpc_OFFSET(compute, &compute->outBuf);
    fxnCtx->xltAry[1].handle = 0;
#if !defined(OS_QNX)
    /* In Linux, set this to a valid allocator handle */
//  fxnCtx->xltAry[1].handle = ...;
    assert(fxnCtx->xltAry[1].handle != 0);
#endif

    /* invoke the remote function call */
    status = MmRpc_call(MachVis_mmrpc, fxnCtx, &fxnRet);

    if (status < 0) {
        printf("MachVis_compute: Error: MmRpc_call failed\n");
        fxnRet = -1;
    }

    return(fxnRet);
}
