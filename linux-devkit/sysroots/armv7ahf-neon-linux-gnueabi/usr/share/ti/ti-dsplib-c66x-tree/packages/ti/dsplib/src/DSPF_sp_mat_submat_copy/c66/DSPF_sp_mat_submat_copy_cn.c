/* ======================================================================= */
/* DSPF_sp_mat_submat_copy_cn.c -- Sub_Matrix Copy                         */
/*                 Natural C Implementation                                */
/*                                                                         */
/* Rev 0.0.2                                                               */
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

#pragma CODE_SECTION(DSPF_sp_mat_submat_copy_cn, ".text:ansi");

#include "DSPF_sp_mat_submat_copy_cn.h"

void DSPF_sp_mat_submat_copy_cn(float* x, int rows, int cols, int st, int n, 
  float* y, int dir)
{
  int i, j;
  
  for (i = st; i < st + n; i++) {
    for (j = 0; j < cols; j++) {
      if (!dir)
        y[(i - st) + j * n] = x[i + j * rows];
      else
        x[i + j * rows] = y[(i - st) + j * n]; 
    }
  }
}

/* ======================================================================= */
/*  End of file:  DSPF_sp_mat_submat_copy_cn.c                             */
/* ----------------------------------------------------------------------- */
/*            Copyright (c) 2011 Texas Instruments, Incorporated.          */
/*                           All Rights Reserved.                          */
/* ======================================================================= */

