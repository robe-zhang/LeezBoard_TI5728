/* ======================================================================= */
/* DSPF_sp_autocor.h -- Autocorrelation                                    */
/*              Optimized C Implementation (w/ Intrinsics)                 */
/*                                                                         */
/* Rev 0.0.1                                                               */
/*                                                                         */
/* Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/  */ 
/*                                                                         */
/*                                                                         */
/*  Redistribution and use in source and binary forms, with or without     */
/*  modification, are permitted provided that the following conditions     */
/*  are met:                                                               */
/*                                                                         */
/*    Redistributions of source code must retain the above copyright       */
/*    notice, this list of conditions and the following disclaimer.        */
/*                                                                         */
/*    Redistributions in binary form must reproduce the above copyright    */
/*    notice, this list of conditions and the following disclaimer in the  */
/*    documentation and/or other materials provided with the               */
/*    distribution.                                                        */
/*                                                                         */
/*    Neither the name of Texas Instruments Incorporated nor the names of  */
/*    its contributors may be used to endorse or promote products derived  */
/*    from this software without specific prior written permission.        */
/*                                                                         */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
/*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT   */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
/*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
/*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
/*                                                                         */
/* ======================================================================= */

#ifndef DSPF_SP_AUTOCOR_H_
#define DSPF_SP_AUTOCOR_H_

#ifndef __TI_COMPILER_VERSION__           // for non TI compiler
#include "assert.h"                       // intrinsics prototypes
#include "C6xSimulator.h"                 // intrinsics prototypes
#include "C6xSimulator_type_modifiers.h"  // define/undefine typing keywords
#endif

/** @ingroup CORRELATION */
/* @{ */

/** @defgroup  DSPF_sp_autocor */
/** @ingroup DSPF_sp_autocor */
/* @{ */

/**
 *   This routine performs the autocorrelation of the input array x. 
 *   It is assumed that the length of the input array, x, is a multiple
 *   of 4 and the length of the output array, r, is a multiple of 4. 
 *   It is assumed that input vector x is padded with nr no of zeros in the
 *   beginning.
 *                                                                           
 *         @param r   Pointer to output array of autocorrelation of length nr
 *         @param x   Pointer to input array of length nx+nr
 *                    Input data must be padded with nr consecutive zeros at the beginning
 *         @param nx  Length of autocorrelation vector
 *         @param nr  Length of lags
 *
 * @par Algorithm:
 * DSPF_sp_autocor_cn.c is the natural C equivalent of the optimized
 * linear assembly code without restrictions. Note that the linear
 * assembly code is optimized and restrictions may apply.  
 * 
 * @par Assumptions:
 *     nx is a multiple of 4 and greater than or equal to 4 <BR>
 *     nr is a multiple of 4 and greater than or equal to 4 <BR>
 *     nx is greater than or equal to nr <BR>
 *     x is double-word aligned <BR>
 *
 * @par Implementation Notes:
 * @b Interruptibility: The code is interruptible. <BR>
 * @b Endian Support: The code supports both big and little endian modes. <BR> 
 *
 */

void DSPF_sp_autocor(float *restrict r,
    float *restrict x, const int nx, const int nr);

#endif /* DSPF_SP_AUTOCOR_H_ */

/* ======================================================================= */
/*  End of file:  DSPF_sp_autocor.h                                        */
/* ----------------------------------------------------------------------- */
/*            Copyright (c) 2011 Texas Instruments, Incorporated.          */
/*                           All Rights Reserved.                          */
/* ======================================================================= */

