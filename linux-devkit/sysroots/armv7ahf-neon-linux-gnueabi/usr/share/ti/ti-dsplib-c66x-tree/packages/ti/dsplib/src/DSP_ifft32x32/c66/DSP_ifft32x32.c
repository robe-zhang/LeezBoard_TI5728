/* ======================================================================= */
/*  TEXAS INSTRUMENTS, INC.                                                */
/*                                                                         */
/*  DSPLIB  DSP Signal Processing Library                                  */
/*                                                                         */
/*  This library contains proprietary intellectual property of Texas       */
/*  Instruments, Inc.  The library and its source code are protected by    */
/*  various copyrights, and portions may also be protected by patents or   */
/*  other legal protections.                                               */
/*                                                                         */
/*  This software is licensed for use with Texas Instruments TMS320        */
/*  family DSPs.  This license was provided to you prior to installing     */
/*  the software.  You may review this license by consulting the file      */
/*  TI_license.PDF which accompanies the files in this library.            */
/*                                                                         */
/* ----------------------------------------------------------------------- */
/*                                                                         */
/*  NAME                                                                   */
/*      DSP_ifft32x32 -- ifft32x32                                         */
/*                                                                         */
/*       USAGE                                                             */
/*           This routine is C-callable and can be called as:              */
/*                                                                         */
/*          void DSP_ifft32x32 (                                           */
/*      (                                                                  */
/*          const int * w,                                                 */
/*          int nx,                                                        */
/*          int * x,                                                       */
/*          int * y                                                        */
/*      )                                                                  */
/*                                                                         */
/*      w[2*nx]:    Pointer to vector of Q.31 FFT coefficients of size     */
/*                  2*nx elements.                                         */
/*                                                                         */
/*      nx:         Number of complex elements in vector x.                */
/*                                                                         */
/*      x[2*nx]:    Pointer to input vector of size 2*nx elements.         */
/*                                                                         */
/*      y[2*nx]:    Pointer to output vector of size 2*nx elements.        */
/*                                                                         */
/*                                                                         */
/*  DESCRIPTION                                                            */
/*                                                                         */
/*      This code performs a Radix-4 IFFT with digit reversal.  The code   */
/*      uses a special ordering of twiddle factors and memory accesses     */
/*      to improve performance in the presence of cache.  It operates      */
/*      largely in-place, but the final digit-reversed output is written   */
/*      out-of-place.                                                      */
/*                                                                         */
/*      This code requires a special sequence of twiddle factors stored    */
/*      in Q1.31 fixed-point format.  The following C code illustrates     */
/*      one way to generate the desired twiddle-factor array:              */
/*                                                                         */
/*      #include <math.h>                                                  */
/*                                                                         */
/*      #ifndef PI                                                         */
/*      # define PI (3.14159265358979323846)                               */
/*      #endif                                                             */
/*                                                                         */
/*                                                                         */
/*      static int d2i(double d)                                           */
/*      {                                                                  */
/*         if (d >=  2147483647.0) return (int)0x7FFFFFFF;                 */
/*         if (d <= -2147483648.0) return (int)0x80000000;                 */
/*         return (int)d;                                                  */
/*      }                                                                  */
/*                                                                         */
/*                                                                         */
/*      int gen_twiddle_ifft32x32(int *w, int n, double scale)             */
/*      {                                                                  */
/*          int i, j, k, s=0, t;                                           */
/*                                                                         */
/*          for (j = 1, k = 0; j < n >> 2; j = j << 2, s++)                */
/*          {                                                              */
/*              for (i = t=0; i < n >> 2; i += j, t++)                     */
/*              {                                                          */
/*                 w[k +  5] =   d2i(scale * cos(6.0 * PI * i / n));       */
/*                 w[k +  4] = - d2i(scale * sin(6.0 * PI * i / n));       */
/*                                                                         */
/*                 w[k +  3] =   d2i(scale * cos(4.0 * PI * i / n));       */
/*                 w[k +  2] = - d2i(scale * sin(4.0 * PI * i / n));       */
/*                                                                         */
/*                 w[k +  1] =   d2i(scale * cos(2.0 * PI * i / n));       */
/*                 w[k +  0] = - d2i(scale * sin(2.0 * PI * i / n));       */
/*                                                                         */
/*                 k += 6;                                                 */
/*                 }                                                       */
/*             }                                                           */
/*                                                                         */
/*          return k;                                                      */
/*        }                                                                */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/*  TECHNIQUES                                                             */
/*                                                                         */
/*      The following C code represents an implementation of the Cooley    */
/*      Tukey radix 4 DIF IFFT. It accepts the inputs in normal order and  */
/*      produces the outputs in digit reversed order. The natural C code   */
/*      shown in this file on the other hand, accepts the inputs in nor-   */
/*      mal order and produces the outputs in normal order.                */
/*                                                                         */
/*      Several transformations have been applied to the original Cooley   */
/*      Tukey code to produce the natural C code description shown here.   */
/*      In order to understand these it would first be educational to      */
/*      understand some of the issues involved in the conventional Cooley  */
/*      Tukey FFT code.                                                    */
/*                                                                         */
/*      void radix4(int n, short x[], short wn[])                          */
/*      {                                                                  */
/*          int    n1,  n2,  ie,   ia1,  ia2, ia3;                         */
/*          int    i0,  i1,  i2,    i3,    i, j,     k;                    */
/*          short  co1, co2, co3,  si1,  si2, si3;                         */
/*          short  xt0, yt0, xt1,  yt1,  xt2, yt2;                         */
/*          short  xh0, xh1, xh20, xh21, xl0, xl1,xl20,xl21;               */
/*                                                                         */
/*          n2 = n;                                                        */
/*          ie = 1;                                                        */
/*          for (k = n; k > 1; k >>= 2)                                    */
/*          {                                                              */
/*              n1 = n2;                                                   */
/*              n2 >>= 2;                                                  */
/*              ia1 = 0;                                                   */
/*                                                                         */
/*              for (j = 0; j < n2; j++)                                   */
/*              {                                                          */
/*                   ia2 = ia1 + ia1;                                      */
/*                   ia3 = ia2 + ia1;                                      */
/*                                                                         */
/*                   co1 = wn[2 * ia1    ];                                */
/*                   si1 = wn[2 * ia1 + 1];                                */
/*                   co2 = wn[2 * ia2    ];                                */
/*                   si2 = wn[2 * ia2 + 1];                                */
/*                   co3 = wn[2 * ia3    ];                                */
/*                   si3 = wn[2 * ia3 + 1];                                */
/*                   ia1 = ia1 + ie;                                       */
/*                                                                         */
/*                   for (i0 = j; i0< n; i0 += n1)                         */
/*                   {                                                     */
/*                       i1 = i0 + n2;                                     */
/*                       i2 = i1 + n2;                                     */
/*                       i3 = i2 + n2;                                     */
/*                                                                         */
/*                                                                         */
/*                       xh0  = x[2 * i0    ] + x[2 * i2    ];             */
/*                       xh1  = x[2 * i0 + 1] + x[2 * i2 + 1];             */
/*                       xl0  = x[2 * i0    ] - x[2 * i2    ];             */
/*                       xl1  = x[2 * i0 + 1] - x[2 * i2 + 1];             */
/*                                                                         */
/*                       xh20 = x[2 * i1    ] + x[2 * i3    ];             */
/*                       xh21 = x[2 * i1 + 1] + x[2 * i3 + 1];             */
/*                       xl20 = x[2 * i1    ] - x[2 * i3    ];             */
/*                       xl21 = x[2 * i1 + 1] - x[2 * i3 + 1];             */
/*                                                                         */
/*                       x[2 * i0    ] = xh0 + xh20;                       */
/*                       x[2 * i0 + 1] = xh1 + xh21;                       */
/*                                                                         */
/*                       xt0  = xh0 - xh20;                                */
/*                       yt0  = xh1 - xh21;                                */
/*                       xt1  = xl0 - xl21;                                */
/*                       yt2  = xl1 - xl20;                                */
/*                       xt2  = xl0 + xl21;                                */
/*                       yt1  = xl1 + xl20;                                */
/*                                                                         */
/*                       x[2 * i1    ] = (xt1 * co1 + yt1 * si1) >> 15;    */
/*                       x[2 * i1 + 1] = (yt1 * co1 - xt1 * si1) >> 15;    */
/*                       x[2 * i2    ] = (xt0 * co2 + yt0 * si2) >> 15;    */
/*                       x[2 * i2 + 1] = (yt0 * co2 - xt0 * si2) >> 15;    */
/*                       x[2 * i3    ] = (xt2 * co3 + yt2 * si3) >> 15;    */
/*                       x[2 * i3 + 1] = (yt2 * co3 - xt2 * si3) >> 15;    */
/*                   }                                                     */
/*             }                                                           */
/*                                                                         */
/*             ie <<= 2;                                                   */
/*         }                                                               */
/*     }                                                                   */
/*                                                                         */
/*      The conventional Cooley Tukey FFT, is written using three loops.   */
/*      The outermost loop "k" cycles through the stages. There are log    */
/*      N to the base 4 stages in all. The loop "j" cycles through the     */
/*      groups of butterflies with different twiddle factors, loop "i"     */
/*      reuses the twiddle factors for the different butterflies within    */
/*      a stage. It is interesting to note the following:                  */
/*                                                                         */
/* ----------------------------------------------------------------------- */
/*      Stage#     #Groups     # Butterflies with common     #Groups*Bflys */
/*                               twiddle factors                           */
/* ----------------------------------------------------------------------- */
/*       1         N/4          1                            N/4           */
/*       2         N/16         4                            N/4           */
/*       ..                                                                */
/*       logN      1            N/4                          N/4           */
/* ----------------------------------------------------------------------- */
/*                                                                         */
/*      The following statements can be made based on above observations:  */
/*                                                                         */
/*      a) Inner loop "i0" iterates a variable number of times. In         */
/*      particular the number of iterations quadruples every time from     */
/*      1..N/4. Hence software pipelining a loop that iterates a variable  */
/*      number of times is not profitable.                                 */
/*                                                                         */
/*      b) Outer loop "j" iterates a variable number of times as well.     */
/*      However the number of iterations is quartered every time from      */
/*      N/4 ..1. Hence the behaviour in (a) and (b) are exactly opposite   */
/*      to each other.                                                     */
/*                                                                         */
/*      c) If the two loops "i" and "j" are colaesced together then they   */
/*      will iterate for a fixed number of times namely N/4. This allows   */
/*      us to combine the "i" and "j" loops into 1 loop. Optimized impl-   */
/*      ementations will make use of this fact.                            */
/*                                                                         */
/*      In addition the Cooley Tukey FFT accesses three twiddle factors    */
/*      per iteration of the inner loop, as the butterflies that re-use    */
/*      twiddle factors are lumped together. This leads to accessing the   */
/*      twiddle factor array at three points each sepearted by "ie". Note  */
/*      that "ie" is initially 1, and is quadrupled with every iteration.  */
/*      Therfore these three twiddle factors are not even contiguous in    */
/*      the array.                                                         */
/*                                                                         */
/*      In order to vectorize the FFT, it is desirable to access twiddle   */
/*      factor array using double word wide loads and fetch the twiddle    */
/*      factors needed. In order to do this a modified twiddle factor      */
/*      array is created, in which the factors WN/4, WN/2, W3N/4 are       */
/*      arranged to be contiguous. This eliminates the seperation between  */
/*      twiddle factors within a butterfly. However this implies that as   */
/*      the loop is traversed from one stage to another, that we maintain  */
/*      a redundant version of the twiddle factor array. Hence the size    */
/*      of the twiddle factor array increases as compared to the normal    */
/*      Cooley Tukey FFT.  The modified twiddle factor array is of size    */
/*      "2 * N" where the conventional Cooley Tukey FFT is of size"3N/4"   */
/*      where N is the number of complex points to be transformed. The     */
/*      routine that generates the modified twiddle factor array was       */
/*      presented earlier. With the above transformation of the FFT,       */
/*      both the input data and the twiddle factor array can be accessed   */
/*      using double-word wide loads to enable packed data processing.     */
/*                                                                         */
/*      The final stage is optimised to remove the multiplication as       */
/*      w0 = 1.  This stage also performs digit reversal on the data,      */
/*      so the final output is in natural order.                           */
/*                                                                         */
/*      The fft() code shown here performs the bulk of the computation     */
/*      in place. However, because digit-reversal cannot be performed      */
/*      in-place, the final result is written to a separate array, y[].    */
/*                                                                         */
/*      There is one slight break in the flow of packed processing that    */
/*      needs to be comprehended. The real part of the complex number is   */
/*      in the lower half, and the imaginary part is in the upper half.    */
/*      The flow breaks in case of "xl0" and "xl1" because in this case    */
/*      the real part needs to be combined with the imaginary part because */
/*      of the multiplication by "j". This requires a packed quantity like */
/*      "xl21xl20" to be rotated as "xl20xl21" so that it can be combined  */
/*      using add2's and sub2's. Hence the natural version of C code       */
/*      shown below is transformed using packed data processing as shown:  */
/*                                                                         */
/*                       xl0  = x[2 * i0    ] - x[2 * i2    ];             */
/*                       xl1  = x[2 * i0 + 1] - x[2 * i2 + 1];             */
/*                       xl20 = x[2 * i1    ] - x[2 * i3    ];             */
/*                       xl21 = x[2 * i1 + 1] - x[2 * i3 + 1];             */
/*                                                                         */
/*                       xt1  = xl0 + xl21;                                */
/*                       yt2  = xl1 + xl20;                                */
/*                       xt2  = xl0 - xl21;                                */
/*                       yt1  = xl1 - xl20;                                */
/*                                                                         */
/*                       xl1_xl0   = _sub2(x21_x20, x21_x20)               */
/*                       xl21_xl20 = _sub2(x32_x22, x23_x22)               */
/*                       xl20_xl21 = _rotl(xl21_xl20, 16)                  */
/*                                                                         */
/*                       yt2_xt1   = _add2(xl1_xl0, xl20_xl21)             */
/*                       yt1_xt2   = _sub2(xl1_xl0, xl20_xl21)             */
/*                                                                         */
/*      Also notice that xt1, yt1 endup on seperate words, these need to   */
/*      be packed together to take advantage of the packed twiddle fact    */
/*      ors that have been loaded. In order for this to be achieved they   */
/*      are re-aligned as follows:                                         */
/*                                                                         */
/*      yt1_xt1 = _packhl2(yt1_xt2, yt2_xt1)                               */
/*      yt2_xt2 = _packhl2(yt2_xt1, yt1_xt2)                               */
/*                                                                         */
/*      The packed words "yt1_xt1" allows the loaded"sc" twiddle factor    */
/*      to be used for the complex multiplies. The real part os the        */
/*      complex multiply is implemented using _dotp2. The imaginary        */
/*      part of the complex multiply is implemented using _dotpn2          */
/*      after the twiddle factors are swizzled within the half word.       */
/*                                                                         */
/*      (X + jY) ( C + j S) = (XC + YS) + j (YC - XS).                     */
/*                                                                         */
/*      The actual twiddle factors for the FFT are cosine, - sine. The     */
/*      twiddle factors stored in the table are csine and sine, hence      */
/*      the sign of the "sine" term is comprehended during multipli-       */
/*      cation as shown above.                                             */
/*                                                                         */
/*                                                                         */
/*  ASSUMPTIONS                                                            */
/*                                                                         */
/*      The size of the IFFT, n, must be a power of 4 and greater than     */
/*      or equal to 16 and less than 32768.                                */
/*                                                                         */
/*      The arrays 'x[]', 'y[]', and 'w[]' all must be aligned on a        */
/*      double-word boundary for the "optimized" implementations.          */
/*                                                                         */
/*      The input and output data are complex, with the real/imaginary     */
/*      components stored in adjacent locations in the array.  The real    */
/*      components are stored at even array indices, and the imaginary     */
/*      components are stored at odd array indices.                        */
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

#pragma CODE_SECTION(DSP_ifft32x32, ".text:optimized");

#include "DSP_ifft32x32.h"

static inline void radix_2(int *restrict ptr_x, int *restrict ptr_y, int npoints);
static inline void radix_4(int *restrict ptr_x, int *restrict ptr_y, int npoints);

#ifdef _LITTLE_ENDIAN
void DSP_ifft32x32 (
    const int * restrict ptr_w,
    int npoints,
    int * restrict ptr_x,
    int * restrict ptr_y
)
{
    int * restrict w;
    int * restrict x, * restrict x2;
    int i, j, l1, l2, h2, predj, tw_offset, stride, fft_jmp, radix;

    long long xh21_0_xh20_0, xh21_1_xh20_1, xh1_0_xh0_0, xh1_1_xh0_1; 
    long long xl21_0_xl20_0, xl21_1_xl20_1, xl1_0_xl0_0, xl1_1_xl0_1; 
    long long yt0_0_xt0_0,   yt0_1_xt0_1,   yt1_0_xt1_0;
    long long yt1_1_xt1_1,   yt2_0_xt2_0,   yt2_1_xt2_1; 
    long long x_1o_x_0o,     xl1_1o_xl1_0o, x_3o_x_2o,     xl1_3o_xl1_2o; 
    long long xh2_1o_xh2_0o, xl2_1o_xl2_0o, xh2_3o_xh2_2o, xl2_3o_xl2_2o;  
 
    long long x_10, x_32, x_l1_10, x_l1_32, x_l2_10, x_l2_32, x_h2_10,x_h2_32;
    long long co10_si10, co20_si20, co30_si30, co11_si11, co21_si21, co31_si31;
    long long xt2_0_xt1_0, yt1_0_yt2_0, xt2_1_xt1_1, yt1_1_yt2_1; 

    /*---------------------------------------------------------------------*/
    /* Determine the magnitude od the number of points to be transformed.  */
    /* Check whether we can use a radix4 decomposition or a mixed radix    */
    /* transformation, by determining modulo 2.                            */
    /*---------------------------------------------------------------------*/
    radix = _norm(npoints) & 1 ? 2 : 4;

    /*----------------------------------------------------------------------*/
    /* The stride is quartered with every iteration of the outer loop. It   */
    /* denotes the seperation between any two adjacent inputs to the butter */
    /* -fly. This should start out at N/4, hence stride is initially set to */
    /* N. For every stride, 6*stride twiddle factors are accessed. The      */
    /* "tw_offset" is the offset within the current twiddle factor sub-     */
    /* table. This is set to zero, at the start of the code and is used to  */
    /* obtain the appropriate sub-table twiddle pointer by offseting it     */
    /* with the base pointer "ptr_w".                                       */
    /*----------------------------------------------------------------------*/ 
    stride = npoints;
    tw_offset = 0;
    fft_jmp = 6 * stride;

    _nassert(stride > 4);
    #pragma MUST_ITERATE(1,,1);
    while (stride > 4) {
        /*-----------------------------------------------------------------*/
        /* At the start of every iteration of the outer loop, "j" is set   */
        /* to zero, as "w" is pointing to the correct location within the  */
        /* twiddle factor array. For every iteration of the inner loop     */
        /* 6 * stride twiddle factors are accessed. For eg,                */
        /*                                                                 */
        /* #Iteration of outer loop  # twiddle factors    #times cycled    */
        /*  1                          6 N/4               1               */
        /*  2                          6 N/16              4               */
        /*  ...                                                            */
        /*-----------------------------------------------------------------*/  
        j =  0;
        fft_jmp >>= 2;

        /*-----------------------------------------------------------------*/
        /* Set up offsets to access "N/4", "N/2", "3N/4" complex point or  */
        /* "N/2", "N", "3N/2" half word                                    */
        /*-----------------------------------------------------------------*/ 
        h2 = stride >> 1;
        l1 = stride;
        l2 = stride + (stride >> 1);

        /*-----------------------------------------------------------------*/
        /*  Reset "x" to point to the start of the input data array.       */
        /* "tw_offset" starts off at 0, and increments by "6 * stride"     */
        /*  The stride quarters with every iteration of the outer loop     */
        /*-----------------------------------------------------------------*/
        x = ptr_x;
        w = (int *)ptr_w + tw_offset;
        tw_offset += fft_jmp;

        stride >>= 2;

        /*----------------------------------------------------------------*/
        /* The following loop iterates through the different butterflies, */
        /* within a given stage. Recall that there are logN to base 4     */
        /* stages. Certain butterflies share the twiddle factors. These   */
        /* are grouped together. On the very first stage there are no     */
        /* butterflies that share the twiddle factor, all N/4 butter-     */
        /* flies have different factors. On the next stage two sets of    */
        /* N/8 butterflies share the same twiddle factor. Hence after     */
        /* half the butterflies are performed, j the index into the       */
        /* factor array resets to 0, and the twiddle factors are reused.  */
        /* When this happens, the data pointer 'x' is incremented by the  */
        /* fft_jmp amount.                                                */
        /*----------------------------------------------------------------*/
        _nassert((int)(w) % 8 == 0);
        _nassert((int)(x) % 8 == 0);
        _nassert(h2 % 8 == 0);
        _nassert(l1 % 8 == 0);
        _nassert(l2 % 8 == 0);
        _nassert(npoints >= 16);
        #pragma MUST_ITERATE(2,,2);
        for (i = 0; i < (npoints >> 3); i++) {
            /*------------------------------------------------------------*/
            /*  Read the first six twiddle factor values. This loop       */
            /*  computes two radix 4 butterflies at a time.               */
            /* si10 = w[0] co10 = w[1]  si20 = w[2]  co20 = w[3]          */
            /* si30 = w[4] co30 = w[5]  si11 = w[6]  co11 = w[7]          */
            /* si21 = w[8] co21 = w[9]  si31 = w[a]  co31 = w[b]          */
            /*------------------------------------------------------------*/
            co10_si10 = _amem8_const(&w[j]);
            co20_si20 = _cmpy32r1(co10_si10, co10_si10);
            co30_si30 = _cmpy32r1(co20_si20, co10_si10);

            co11_si11 = _amem8_const(&w[j + 6]);
            co21_si21 = _cmpy32r1(co11_si11, co11_si11);
            co31_si31 = _cmpy32r1(co21_si21, co11_si11);

            /*-------------------------------------------------------------*/
            /* Read in the data elements for the eight inputs of two       */
            /* radix4 butterflies.                                         */
            /*  x[0]       x[1]       x[2]       x[3]                      */
            /*  x[h2+0]    x[h2+1]    x[h2+2]    x[h2+3]                   */
            /*  x[l1+0]    x[l1+1]    x[l1+2]    x[l1+3]                   */
            /*  x[l2+0]    x[l2+1]    x[l2+2]    x[l2+3]                   */
            /*-------------------------------------------------------------*/
            x_10    = _amem8(&x[0]);
            x_32    = _amem8(&x[2]);
            x_l1_10 = _amem8(&x[l1]);
            x_l1_32 = _amem8(&x[l1 + 2]);
            x_l2_10 = _amem8(&x[l2]);
            x_l2_32 = _amem8(&x[l2 + 2]);
            x_h2_10 = _amem8(&x[h2]);
            x_h2_32 = _amem8(&x[h2 + 2]);

            /*-------------------------------------------------------------*/
            /* xh0_0 = x[0] + x[l1];    xh1_0 = x[1] + x[l1+1]             */
            /* xh0_1 = x[2] + x[l1+2];  xh1_1 = x[3] + x[l1+3]             */
            /* xl0_0 = x[0] - x[l1];    xl1_0 = x[1] - x[l1+1]             */
            /* xl0_1 = x[2] - x[l1+2];  xl1_1 = x[3] - x[l1+3]             */
            /*-------------------------------------------------------------*/
            xh1_0_xh0_0 = _dadd(x_10, x_l1_10);
            xl1_0_xl0_0 = _dsub(x_10, x_l1_10);
            xh1_1_xh0_1 = _dadd(x_32, x_l1_32);
            xl1_1_xl0_1 = _dsub(x_32, x_l1_32);

            /*------------------------------------------------------------*/
            /* xh20_0 = x[h2  ] + x[l2  ]; xh21_0 = x[h2+1] + x[l2+1]     */
            /* xh20_1 = x[h2+2] + x[l2+2]; xh21_1 = x[h2+3] + x[l2+3]     */
            /* xl20_0 = x[h2  ] - x[l2  ]; xl21_0 = x[h2+1] - x[l2+1]     */
            /* xl20_1 = x[h2+2] - x[l2+2]; xl21_1 = x[h2+3] - x[l2+3]     */
            /*------------------------------------------------------------*/
            xh21_0_xh20_0 = _dadd(x_h2_10, x_l2_10);
            xl21_0_xl20_0 = _dsub(x_h2_10, x_l2_10);
            xh21_1_xh20_1 = _dadd(x_h2_32, x_l2_32);
            xl21_1_xl20_1 = _dsub(x_h2_32, x_l2_32);

            /*-------------------------------------------------------------*/
            /*    x_0o  = xh0_0 + xh20_0;    x_1o  = xh1_0 + xh21_0;       */
            /*    x_2o  = xh0_1 + xh20_1;    x_3o  = xh1_1 + xh21_1;       */
            /*    xt0_0 = xh0_0 - xh20_0;    yt0_0 = xh1_0 - xh21_0;       */
            /*    xt0_1 = xh0_1 - xh20_1;    yt0_1 = xh1_1 - xh21_1;       */
            /*-------------------------------------------------------------*/
            x_1o_x_0o = _dadd(xh1_0_xh0_0, xh21_0_xh20_0);
            x_3o_x_2o = _dadd(xh1_1_xh0_1, xh21_1_xh20_1);

            yt0_0_xt0_0 = _dsub(xh1_0_xh0_0, xh21_0_xh20_0);
            yt0_1_xt0_1 = _dsub(xh1_1_xh0_1, xh21_1_xh20_1);

            /*-------------------------------------------------------------*/
            /*    xt1_0 = xl0_0 - xl21_0;    yt2_0 = xl1_0 - xl20_0;       */
            /*    xt1_1 = xl0_1 - xl21_1;    yt2_1 = xl1_1 - xl20_1;       */
            /*    xt2_0 = xl0_0 + xl21_0;    yt1_0 = xl1_0 + xl20_0;       */
            /*    xt2_1 = xl0_1 + xl21_1;    yt1_1 = xl1_1 + xl20_1;       */
            /*-------------------------------------------------------------*/
            xt2_0_xt1_0 = _addsub(_loll(xl1_0_xl0_0), _hill(xl21_0_xl20_0));
            yt1_0_yt2_0 = _addsub(_hill(xl1_0_xl0_0), _loll(xl21_0_xl20_0));
            xt2_1_xt1_1 = _addsub(_loll(xl1_1_xl0_1), _hill(xl21_1_xl20_1));
            yt1_1_yt2_1 = _addsub(_hill(xl1_1_xl0_1), _loll(xl21_1_xl20_1));

            yt1_0_xt1_0 = _itoll(_hill(yt1_0_yt2_0), _loll(xt2_0_xt1_0));
            yt1_1_xt1_1 = _itoll(_hill(yt1_1_yt2_1), _loll(xt2_1_xt1_1));

            yt2_0_xt2_0 = _itoll(_loll(yt1_0_yt2_0), _hill(xt2_0_xt1_0));
            yt2_1_xt2_1 = _itoll(_loll(yt1_1_yt2_1), _hill(xt2_1_xt1_1));

            /*-------------------------------------------------------------*/
            /*   x2[h2  ] = (si10 * yt1_0 + co10 * xt1_0) >> 15            */
            /*   x2[h2+1] = (co10 * yt1_0 - si10 * xt1_0) >> 15            */
            /*   x2[h2+2] = (si11 * yt1_1 + co11 * xt1_1) >> 15            */
            /*   x2[h2+3] = (co11 * yt1_1 - si11 * xt1_1) >> 15            */
            /*-------------------------------------------------------------*/
            xh2_1o_xh2_0o = _cmpy32r1(co10_si10, yt1_0_xt1_0);
            xh2_3o_xh2_2o = _cmpy32r1(co11_si11, yt1_1_xt1_1);

            /*-------------------------------------------------------------*/
            /*   x2[l1  ] = (si20 * yt0_0 + co20 * xt0_0) >> 15            */
            /*   x2[l1+1] = (co20 * yt0_0 - si20 * xt0_0) >> 15            */
            /*   x2[l1+2] = (si21 * yt0_1 + co21 * xt0_1) >> 15            */
            /*   x2[l1+3] = (co21 * yt0_1 - si21 * xt0_1) >> 15            */
            /*-------------------------------------------------------------*/
            xl1_1o_xl1_0o = _cmpy32r1(co20_si20, yt0_0_xt0_0);
            xl1_3o_xl1_2o = _cmpy32r1(co21_si21, yt0_1_xt0_1);

            /*-------------------------------------------------------------*/
            /*   x2[l2  ] = (si30 * yt2_0 + co30 * xt2_0) >> 15            */
            /*   x2[l2+1] = (co30 * yt2_0 - si30 * xt2_0) >> 15            */
            /*   x2[l2+2] = (si31 * yt2_1 + co31 * xt2_1) >> 15            */
            /*   x2[l2+3] = (co31 * yt2_1 - si31 * xt2_1) >> 15            */
            /*-------------------------------------------------------------*/
            xl2_1o_xl2_0o = _cmpy32r1(co30_si30, yt2_0_xt2_0);
            xl2_3o_xl2_2o = _cmpy32r1(co31_si31, yt2_1_xt2_1);

            /*-----------------------------------------------------------*/
            /* Derive output pointers using the input pointer "x"        */
            /*-----------------------------------------------------------*/
            x2 = x;

            /*-------------------------------------------------------------*/
            /*  Store eight outputs - four legs of each butterfly          */
            /*-------------------------------------------------------------*/
            _amem8(&x2[0])    = x_1o_x_0o;
            _amem8(&x2[2])    = x_3o_x_2o;

            _amem8(&x2[h2])   = xh2_1o_xh2_0o;
            _amem8(&x2[h2+2]) = xh2_3o_xh2_2o;

            _amem8(&x2[l1])   = xl1_1o_xl1_0o;
            _amem8(&x2[l1+2]) = xl1_3o_xl1_2o;

            _amem8(&x2[l2])   = xl2_1o_xl2_0o;
            _amem8(&x2[l2+2]) = xl2_3o_xl2_2o;

            /*-----------------------------------------------------------*/
            /* When the twiddle factors are not to be re-used, j is      */
            /* incremented by 12, to reflect the fact that 6 words       */
            /* are consumed in every iteration. The input data pointer   */
            /* increments by 4. Note that within a stage, the stride     */
            /* does not change and hence the offsets for the other three */
            /* legs, 0, h2, l1, l2.                                      */
            /*-----------------------------------------------------------*/
            j += 12;
            x += 4;
            predj = (j - fft_jmp);
            if (!predj) x += fft_jmp;
            if (!predj) j = 0;
        }
    }

    if (radix == 2)
        radix_2(ptr_x, ptr_y, npoints);
    else
        radix_4(ptr_x, ptr_y, npoints);

}

void radix_2 (
    int * restrict ptr_x,
    int * restrict ptr_y,
    int npoints
)
{
    int * restrict x0, * restrict x2;
    int * restrict y0, * restrict y1, * restrict y2, * restrict y3;
    int * restrict yb0, * restrict yb1, * restrict yb2, * restrict yb3;
    int n0, j, i, h2, l1;
    long long n01_n00, n11_n10, n21_n20, n31_n30;
    long long n03_n02, n13_n12, n23_n22, n33_n32;

    long long x10, x32, x54, x76, x98, xBA, xDC, xFE;

    /*-----------------------------------------------------------------*/
    /* The following code performs either a standard radix4 pass or a  */
    /* radix2 pass. Two pointers are used to access the input data.    */
    /* The input data is read "N/4" complex samples apart or "N/2"     */
    /* words apart using pointers "x0" and "x2". This produces out-    */
    /* puts that are 0, N/8, N/2, 3N/8 for radix 2.                    */
    /*-----------------------------------------------------------------*/
    y0 = ptr_y;
    y2 = ptr_y + (int)npoints;
    x0 = ptr_x;
    x2 = ptr_x + (int)(npoints >> 1);

    /*----------------------------------------------------------------*/
    /* The pointers are set at the following locations which are half */
    /* the offsets of a radix4 FFT.                                   */
    /*----------------------------------------------------------------*/
    y1 = y0 + (int)(npoints >> 2);
    y3 = y2 + (int)(npoints >> 2);
    l1 = _norm(npoints) + 1;
    n0 = npoints >> 1;

    yb0 = y0 + 2;
    yb1 = y1 + 2;
    yb2 = y2 + 2;
    yb3 = y3 + 2;

    /*--------------------------------------------------------------------*/
    /* The following code reads data identically for either a radix 4     */
    /* or a radix 2 style decomposition. It writes out at different       */
    /* locations though. It checks if either half the points, or a        */
    /* quarter of the complex points have been exhausted to jump to       */
    /* pervent double reversal.                                           */
    /*--------------------------------------------------------------------*/
    j = 0;

    _nassert((int)(npoints) % 4  == 0);
    _nassert((int)(ptr_x) % 8 == 0);
    _nassert((int)(ptr_y) % 8 == 0);
    _nassert((int)(x0) % 8 == 0);
    _nassert((int)(x2) % 8 == 0);
    _nassert((int)(y0) % 8 == 0);
    #pragma MUST_ITERATE(2,,2);
    for (i = 0; i < npoints; i += 8) {
        /*----------------------------------------------------------------*/
        /* Digit reverse the index starting from 0. The increment to "j"  */
        /* is either by 4, or 8.                                          */
        /*----------------------------------------------------------------*/
        h2 = _deal(j);
        h2 = _bitr(h2);
        h2 = _rotl(h2, 16);
        h2 = _shfl(h2);
        h2 >>= l1;

        /*----------------------------------------------------------------*/
        /* Read in the input data. These are transformed as a radix 2.    */
        /*----------------------------------------------------------------*/
        x10 = _amem8(&x0[0]);
        x32 = _amem8(&x0[2]);
        x54 = _amem8(&x0[4]);
        x76 = _amem8(&x0[6]);
        x0 += 8;

        x98 = _amem8(&x2[0]);
        xBA = _amem8(&x2[2]);
        xDC = _amem8(&x2[4]);
        xFE = _amem8(&x2[6]);
        x2 += 8;

        /*-------------------------------------------------------------*/
        /* Perform radix2 style decomposition.                         */
        /*-------------------------------------------------------------*/
        n01_n00 = _dadd(x10, x32);
        n21_n20 = _dsub(x10, x32);
        n11_n10 = _dadd(x54, x76);
        n31_n30 = _dsub(x54, x76);

        n03_n02 = _dadd(x98, xBA);
        n23_n22 = _dsub(x98, xBA);
        n13_n12 = _dadd(xDC, xFE);
        n33_n32 = _dsub(xDC, xFE);

        /*-----------------------------------------------------------------*/
        /* Points that are read from succesive locations map to y, y[N/8]  */
        /* y[N/2],y[5N/8] in a radix2 scheme.                              */
        /*-----------------------------------------------------------------*/
        _amem8(&y0[2*h2])  = n01_n00;
        _amem8(&y1[2*h2])  = n11_n10;
        _amem8(&y2[2*h2])  = n21_n20;
        _amem8(&y3[2*h2])  = n31_n30;

        _amem8(&yb0[2*h2]) = n03_n02;
        _amem8(&yb1[2*h2]) = n13_n12;
        _amem8(&yb2[2*h2]) = n23_n22;
        _amem8(&yb3[2*h2]) = n33_n32;

        j += 8;
        if (j == n0) {
            j  += n0;
            x0 += (int)npoints >> 1;
            x2 += (int)npoints >> 1;
        }
    }
}

void radix_4 (
    int * restrict ptr_x,
    int * restrict ptr_y,
    int npoints
)
{
    int * restrict x0, * restrict x2;
    int * restrict y0, * restrict y1, * restrict y2, * restrict y3;
    int * restrict yb0, * restrict yb1, * restrict yb2, * restrict yb3;
    int n0, j, i, h2, l1;
    int n11, n10, n31, n30;

    long long x10, x32, x54, x76, x98, xba, xdc, xfe;
    long long xh1_0_xh0_0, xh1_1_xh0_1, xl1_0_xl0_0, xl1_1_xl0_1;
    long long n01_n00, n21_n20;

    /*-----------------------------------------------------------------*/
    /* The following code performs either a standard radix2 pass. Two  */
    /* pointers are used to access the input data. The input data is   */
    /* read "N/4" complex samples apart or "N/2" words apart using     */
    /* pointers "x0" and "x2". This produces outputs that are 0, N/4,  */
    /* N/2, 3N/4 for a radix4 FFT.                                     */
    /*-----------------------------------------------------------------*/
    y0 = ptr_y;
    y2 = ptr_y + (int)npoints;
    x0 = ptr_x;
    x2 = ptr_x + (int)(npoints >> 1);

    /*----------------------------------------------------------------*/
    /* The pointers are set at the following locations                */
    /*----------------------------------------------------------------*/
    y1 = y0 + (int)(npoints >> 1);
    y3 = y2 + (int)(npoints >> 1);
    l1 = _norm(npoints) + 2;
    n0 = npoints >> 2;

    yb0 = y0 + 2;
    yb1 = y1 + 2;
    yb2 = y2 + 2;
    yb3 = y3 + 2;
   
    /*--------------------------------------------------------------------*/
    /* The following code reads data identically for either a radix 4     */
    /* or a radix 2 style decomposition. It writes out at different       */
    /* locations though. It checks if either half the points, or a        */
    /* quarter of the complex points have been exhausted to jump to       */
    /* pervent double reversal.                                           */
    /*--------------------------------------------------------------------*/
    j = 0;
    
    _nassert((int)(npoints) % 4  == 0);
    _nassert((int)(x0) % 8 == 0);
    _nassert((int)(x2) % 8 == 0);
    _nassert((int)(y0) % 8 == 0);
    _nassert(npoints >= 16);
    #pragma MUST_ITERATE(2,,2);
    for (i = 0; i < npoints; i += 8) {
        /*----------------------------------------------------------------*/
        /* Digit reverse the index starting from 0. The increment to "j"  */
        /* is either by 4, or 8.                                          */
        /*----------------------------------------------------------------*/
        h2 = _deal(j);
        h2 = _bitr(h2);
        h2 = _rotl(h2, 16);
        h2 = _shfl(h2);
        h2 >>= l1;

        /*----------------------------------------------------------------*/
        /* Read in the input data, from the first eight locations. These  */
        /* are transformed as a radix4.                                   */
        /*----------------------------------------------------------------*/
        x10 = _amem8(&x0[0]);
        x32 = _amem8(&x0[2]);
        x54 = _amem8(&x0[4]);
        x76 = _amem8(&x0[6]);
        x0 += 8;

        xh1_0_xh0_0 = _dadd(x10, x54);
        xh1_1_xh0_1 = _dadd(x32, x76);
        xl1_0_xl0_0 = _dsub(x10, x54);
        xl1_1_xl0_1 = _dsub(x32, x76);

        n01_n00 = _dadd(xh1_0_xh0_0, xh1_1_xh0_1);
        n21_n20 = _dsub(xh1_0_xh0_0, xh1_1_xh0_1);
        n11 = _hill(xl1_0_xl0_0) + _loll(xl1_1_xl0_1);
        n10 = _loll(xl1_0_xl0_0) - _hill(xl1_1_xl0_1);
        n31 = _hill(xl1_0_xl0_0) - _loll(xl1_1_xl0_1);
        n30 = _loll(xl1_0_xl0_0) + _hill(xl1_1_xl0_1);

        _amem8(&y0[2*h2]) = n01_n00;
        _amem8(&y1[2*h2]) = _itoll(n11, n10);
        _amem8(&y2[2*h2]) = n21_n20;
        _amem8(&y3[2*h2]) = _itoll(n31, n30);

        /*----------------------------------------------------------------*/
        /* Read in the next eight inputs and perform radix4 decomposition */
        /*----------------------------------------------------------------*/
        x98 = _amem8(&x2[0]);
        xba = _amem8(&x2[2]);
        xdc = _amem8(&x2[4]);
        xfe = _amem8(&x2[6]);
        x2 += 8;

        xh1_0_xh0_0 = _dadd(x98, xdc);
        xh1_1_xh0_1 = _dadd(xba, xfe);
        xl1_0_xl0_0 = _dsub(x98, xdc);
        xl1_1_xl0_1 = _dsub(xba, xfe);

        n01_n00 = _dadd(xh1_0_xh0_0, xh1_1_xh0_1);
        n21_n20 = _dsub(xh1_0_xh0_0, xh1_1_xh0_1);
        n11 = _hill(xl1_0_xl0_0) + _loll(xl1_1_xl0_1);
        n10 = _loll(xl1_0_xl0_0) - _hill(xl1_1_xl0_1);
        n31 = _hill(xl1_0_xl0_0) - _loll(xl1_1_xl0_1);
        n30 = _loll(xl1_0_xl0_0) + _hill(xl1_1_xl0_1);

        /*-----------------------------------------------------------------*/
        /* Points that are read from succesive locations map to y, y[N/4]  */
        /* y[N/2], y[3N/4] in a radix4 scheme.                             */
        /*-----------------------------------------------------------------*/
        _amem8(&yb0[2*h2]) = n01_n00;
        _amem8(&yb1[2*h2]) = _itoll(n11, n10);
        _amem8(&yb2[2*h2]) = n21_n20;
        _amem8(&yb3[2*h2]) = _itoll(n31, n30);

        j += 4;
        if (j == n0) {
            j += n0;
            x0 += (int)npoints >> 1;
            x2 += (int)npoints >> 1;
        }
    }
}
#else
void DSP_ifft32x32 (
    const int * restrict ptr_w,
    int npoints,
    int * restrict ptr_x,
    int * restrict ptr_y
)
{
    int * restrict w;
    int * restrict x, * restrict x2;
    int i, j, l1, l2, h2, predj, tw_offset, stride, fft_jmp, radix;

    long long xh20_0_xh21_0, xh20_1_xh21_1, xh0_0_xh1_0, xh0_1_xh1_1; 
    long long xl20_0_xl21_0, xl20_1_xl21_1, xl0_0_xl1_0, xl0_1_xl1_1; 
    long long xt0_0_yt0_0,   xt0_1_yt0_1,   xt1_0_yt1_0;
    long long xt1_1_yt1_1,   xt2_0_yt2_0,   xt2_1_yt2_1; 
    long long x_0o_x_1o,     xl1_0o_xl1_1o, x_2o_x_3o,     xl1_2o_xl1_3o; 
    long long xh2_0o_xh2_1o, xl2_0o_xl2_1o, xh2_2o_xh2_3o, xl2_2o_xl2_3o;  
 
    long long x_01, x_23, x_l1_01, x_l1_23, x_l2_01, x_l2_23, x_h2_01,x_h2_23;
    long long co10_si10, co20_si20, co30_si30, co11_si11, co21_si21, co31_si31;
    long long xt2_0_xt1_0, yt1_0_yt2_0, xt2_1_xt1_1, yt1_1_yt2_1; 

    /*---------------------------------------------------------------------*/
    /* Determine the magnitude od the number of points to be transformed.  */
    /* Check whether we can use a radix4 decomposition or a mixed radix    */
    /* transformation, by determining modulo 2.                            */
    /*---------------------------------------------------------------------*/
    radix = _norm(npoints) & 1 ? 2 : 4;

    /*----------------------------------------------------------------------*/
    /* The stride is quartered with every iteration of the outer loop. It   */
    /* denotes the seperation between any two adjacent inputs to the butter */
    /* -fly. This should start out at N/4, hence stride is initially set to */
    /* N. For every stride, 6*stride twiddle factors are accessed. The      */
    /* "tw_offset" is the offset within the current twiddle factor sub-     */
    /* table. This is set to zero, at the start of the code and is used to  */
    /* obtain the appropriate sub-table twiddle pointer by offseting it     */
    /* with the base pointer "ptr_w".                                       */
    /*----------------------------------------------------------------------*/ 
    stride = npoints;
    tw_offset = 0;
    fft_jmp = 6 * stride;

    _nassert(stride > 4);
    #pragma MUST_ITERATE(1,,1);
    while (stride > 4) {
        /*-----------------------------------------------------------------*/
        /* At the start of every iteration of the outer loop, "j" is set   */
        /* to zero, as "w" is pointing to the correct location within the  */
        /* twiddle factor array. For every iteration of the inner loop     */
        /* 6 * stride twiddle factors are accessed. For eg,                */
        /*                                                                 */
        /* #Iteration of outer loop  # twiddle factors    #times cycled    */
        /*  1                          6 N/4               1               */
        /*  2                          6 N/16              4               */
        /*  ...                                                            */
        /*-----------------------------------------------------------------*/  
        j =  0;
        fft_jmp >>= 2;

        /*-----------------------------------------------------------------*/
        /* Set up offsets to access "N/4", "N/2", "3N/4" complex point or  */
        /* "N/2", "N", "3N/2" half word                                    */
        /*-----------------------------------------------------------------*/ 
        h2 = stride >> 1;
        l1 = stride;
        l2 = stride + (stride >> 1);

        /*-----------------------------------------------------------------*/
        /*  Reset "x" to point to the start of the input data array.       */
        /* "tw_offset" starts off at 0, and increments by "6 * stride"     */
        /*  The stride quarters with every iteration of the outer loop     */
        /*-----------------------------------------------------------------*/
        x = ptr_x;
        w = (int *)ptr_w + tw_offset;
        tw_offset += fft_jmp;

        stride >>= 2;

        /*----------------------------------------------------------------*/
        /* The following loop iterates through the different butterflies, */
        /* within a given stage. Recall that there are logN to base 4     */
        /* stages. Certain butterflies share the twiddle factors. These   */
        /* are grouped together. On the very first stage there are no     */
        /* butterflies that share the twiddle factor, all N/4 butter-     */
        /* flies have different factors. On the next stage two sets of    */
        /* N/8 butterflies share the same twiddle factor. Hence after     */
        /* half the butterflies are performed, j the index into the       */
        /* factor array resets to 0, and the twiddle factors are reused.  */
        /* When this happens, the data pointer 'x' is incremented by the  */
        /* fft_jmp amount.                                                */
        /*----------------------------------------------------------------*/
        _nassert((int)(w) % 8 == 0);
        _nassert((int)(x) % 8 == 0);
        _nassert(h2 % 8 == 0);
        _nassert(l1 % 8 == 0);
        _nassert(l2 % 8 == 0);
        _nassert(npoints >= 16);
        #pragma MUST_ITERATE(2,,2);
        for (i = 0; i < (npoints >> 3); i++) {
            /*------------------------------------------------------------*/
            /*  Read the first six twiddle factor values. This loop       */
            /*  computes two radix 4 butterflies at a time.               */
            /* si10 = w[0] co10 = w[1]  si20 = w[2]  co20 = w[3]          */
            /* si30 = w[4] co30 = w[5]  si11 = w[6]  co11 = w[7]          */
            /* si21 = w[8] co21 = w[9]  si31 = w[a]  co31 = w[b]          */
            /*------------------------------------------------------------*/
            co10_si10 = _amem8_const(&w[j]);
            co20_si20 = _cmpy32r1(co10_si10, co10_si10);
            co30_si30 = _cmpy32r1(co20_si20, co10_si10);

            co11_si11 = _amem8_const(&w[j + 6]);
            co21_si21 = _cmpy32r1(co11_si11, co11_si11);
            co31_si31 = _cmpy32r1(co21_si21, co11_si11);

            /*-------------------------------------------------------------*/
            /* Read in the data elements for the eight inputs of two       */
            /* radix4 butterflies.                                         */
            /*  x[0]       x[1]       x[2]       x[3]                      */
            /*  x[h2+0]    x[h2+1]    x[h2+2]    x[h2+3]                   */
            /*  x[l1+0]    x[l1+1]    x[l1+2]    x[l1+3]                   */
            /*  x[l2+0]    x[l2+1]    x[l2+2]    x[l2+3]                   */
            /*-------------------------------------------------------------*/
            x_01    = _amem8(&x[0]);
            x_23    = _amem8(&x[2]);
            x_l1_01 = _amem8(&x[l1]);
            x_l1_23 = _amem8(&x[l1 + 2]);
            x_l2_01 = _amem8(&x[l2]);
            x_l2_23 = _amem8(&x[l2 + 2]);
            x_h2_01 = _amem8(&x[h2]);
            x_h2_23 = _amem8(&x[h2 + 2]);

            /*-------------------------------------------------------------*/
            /* xh0_0 = x[0] + x[l1];    xh1_0 = x[1] + x[l1+1]             */
            /* xh0_1 = x[2] + x[l1+2];  xh1_1 = x[3] + x[l1+3]             */
            /* xl0_0 = x[0] - x[l1];    xl1_0 = x[1] - x[l1+1]             */
            /* xl0_1 = x[2] - x[l1+2];  xl1_1 = x[3] - x[l1+3]             */
            /*-------------------------------------------------------------*/
            xh0_0_xh1_0 = _dadd(x_01, x_l1_01);
            xl0_0_xl1_0 = _dsub(x_01, x_l1_01);
            xh0_1_xh1_1 = _dadd(x_23, x_l1_23);
            xl0_1_xl1_1 = _dsub(x_23, x_l1_23);

            /*------------------------------------------------------------*/
            /* xh20_0 = x[h2  ] + x[l2  ]; xh21_0 = x[h2+1] + x[l2+1]     */
            /* xh20_1 = x[h2+2] + x[l2+2]; xh21_1 = x[h2+3] + x[l2+3]     */
            /* xl20_0 = x[h2  ] - x[l2  ]; xl21_0 = x[h2+1] - x[l2+1]     */
            /* xl20_1 = x[h2+2] - x[l2+2]; xl21_1 = x[h2+3] - x[l2+3]     */
            /*------------------------------------------------------------*/
            xh20_0_xh21_0 = _dadd(x_h2_01, x_l2_01);
            xl20_0_xl21_0 = _dsub(x_h2_01, x_l2_01);
            xh20_1_xh21_1 = _dadd(x_h2_23, x_l2_23);
            xl20_1_xl21_1 = _dsub(x_h2_23, x_l2_23);

            /*-------------------------------------------------------------*/
            /*    x_0o  = xh0_0 + xh20_0;    x_1o  = xh1_0 + xh21_0;       */
            /*    x_2o  = xh0_1 + xh20_1;    x_3o  = xh1_1 + xh21_1;       */
            /*    xt0_0 = xh0_0 - xh20_0;    yt0_0 = xh1_0 - xh21_0;       */
            /*    xt0_1 = xh0_1 - xh20_1;    yt0_1 = xh1_1 - xh21_1;       */
            /*-------------------------------------------------------------*/
            x_0o_x_1o = _dadd(xh0_0_xh1_0, xh20_0_xh21_0);
            x_2o_x_3o = _dadd(xh0_1_xh1_1, xh20_1_xh21_1);

            xt0_0_yt0_0 = _dsub(xh0_0_xh1_0, xh20_0_xh21_0);
            xt0_1_yt0_1 = _dsub(xh0_1_xh1_1, xh20_1_xh21_1);
            /*-------------------------------------------------------------*/
            /*    xt1_0 = xl0_0 - xl21_0;    yt2_0 = xl1_0 - xl20_0;       */
            /*    xt1_1 = xl0_1 - xl21_1;    yt2_1 = xl1_1 - xl20_1;       */
            /*    xt2_0 = xl0_0 + xl21_0;    yt1_0 = xl1_0 + xl20_0;       */
            /*    xt2_1 = xl0_1 + xl21_1;    yt1_1 = xl1_1 + xl20_1;       */
            /*-------------------------------------------------------------*/
            xt2_0_xt1_0 = _addsub(_hill(xl0_0_xl1_0), _loll(xl20_0_xl21_0));
            yt1_0_yt2_0 = _addsub(_loll(xl0_0_xl1_0), _hill(xl20_0_xl21_0));
            xt2_1_xt1_1 = _addsub(_hill(xl0_1_xl1_1), _loll(xl20_1_xl21_1));
            yt1_1_yt2_1 = _addsub(_loll(xl0_1_xl1_1), _hill(xl20_1_xl21_1));

            xt1_0_yt1_0 = _itoll(_loll(xt2_0_xt1_0), _hill(yt1_0_yt2_0));
            xt1_1_yt1_1 = _itoll(_loll(xt2_1_xt1_1), _hill(yt1_1_yt2_1));

            xt2_0_yt2_0 = _itoll(_hill(xt2_0_xt1_0), _loll(yt1_0_yt2_0));
            xt2_1_yt2_1 = _itoll(_hill(xt2_1_xt1_1), _loll(yt1_1_yt2_1));
       
            /*-------------------------------------------------------------*/
            /*   x2[h2  ] = (si10 * yt1_0 + co10 * xt1_0) >> 15            */
            /*   x2[h2+1] = (co10 * yt1_0 - si10 * xt1_0) >> 15            */
            /*   x2[h2+2] = (si11 * yt1_1 + co11 * xt1_1) >> 15            */
            /*   x2[h2+3] = (co11 * yt1_1 - si11 * xt1_1) >> 15            */
            /*-------------------------------------------------------------*/
            xh2_0o_xh2_1o = _cmpy32r1(co10_si10, xt1_0_yt1_0);
            xh2_2o_xh2_3o = _cmpy32r1(co11_si11, xt1_1_yt1_1);

            /*-------------------------------------------------------------*/
            /*   x2[l1  ] = (si20 * yt0_0 + co20 * xt0_0) >> 15            */
            /*   x2[l1+1] = (co20 * yt0_0 - si20 * xt0_0) >> 15            */
            /*   x2[l1+2] = (si21 * yt0_1 + co21 * xt0_1) >> 15            */
            /*   x2[l1+3] = (co21 * yt0_1 - si21 * xt0_1) >> 15            */
            /*-------------------------------------------------------------*/
            xl1_0o_xl1_1o = _cmpy32r1(co20_si20, xt0_0_yt0_0);
            xl1_2o_xl1_3o = _cmpy32r1(co21_si21, xt0_1_yt0_1);

            /*-------------------------------------------------------------*/
            /*   x2[l2  ] = (si30 * yt2_0 + co30 * xt2_0) >> 15            */
            /*   x2[l2+1] = (co30 * yt2_0 - si30 * xt2_0) >> 15            */
            /*   x2[l2+2] = (si31 * yt2_1 + co31 * xt2_1) >> 15            */
            /*   x2[l2+3] = (co31 * yt2_1 - si31 * xt2_1) >> 15            */
            /*-------------------------------------------------------------*/
            xl2_0o_xl2_1o = _cmpy32r1(co30_si30, xt2_0_yt2_0);
            xl2_2o_xl2_3o = _cmpy32r1(co31_si31, xt2_1_yt2_1);

            /*-----------------------------------------------------------*/
            /* Derive output pointers using the input pointer "x"        */
            /*-----------------------------------------------------------*/
            x2 = x;

            /*-------------------------------------------------------------*/
            /*  Store eight outputs - four legs of each butterfly          */
            /*-------------------------------------------------------------*/
            _amem8(&x2[0])    = x_0o_x_1o;
            _amem8(&x2[2])    = x_2o_x_3o;

            _amem8(&x2[h2])   = xh2_0o_xh2_1o;
            _amem8(&x2[h2+2]) = xh2_2o_xh2_3o;

            _amem8(&x2[l1])   = xl1_0o_xl1_1o;
            _amem8(&x2[l1+2]) = xl1_2o_xl1_3o;

            _amem8(&x2[l2])   = xl2_0o_xl2_1o;
            _amem8(&x2[l2+2]) = xl2_2o_xl2_3o;

            /*-----------------------------------------------------------*/
            /* When the twiddle factors are not to be re-used, j is      */
            /* incremented by 12, to reflect the fact that 6 words       */
            /* are consumed in every iteration. The input data pointer   */
            /* increments by 4. Note that within a stage, the stride     */
            /* does not change and hence the offsets for the other three */
            /* legs, 0, h2, l1, l2.                                      */
            /*-----------------------------------------------------------*/
            j += 12;
            x += 4;
            predj = (j - fft_jmp);
            if (!predj) x += fft_jmp;
            if (!predj) j = 0;
        }
    }

    if (radix == 2)
        radix_2(ptr_x, ptr_y, npoints);
    else
        radix_4(ptr_x, ptr_y, npoints);

}

void radix_2 (
    int * restrict ptr_x,
    int * restrict ptr_y,
    int npoints
)
{
    int * restrict x0, * restrict x2;
    int * restrict y0, * restrict y1, * restrict y2, * restrict y3;
    int * restrict yb0, * restrict yb1, * restrict yb2, * restrict yb3;
    int n0, j, i, h2, l1;
    long long n00_n01, n10_n11, n20_n21, n30_n31;
    long long n02_n03, n12_n13, n22_n23, n32_n33;

    long long x01, x23, x45, x67, x89, xAB, xCD, xEF;

    /*-----------------------------------------------------------------*/
    /* The following code performs either a standard radix4 pass or a  */
    /* radix2 pass. Two pointers are used to access the input data.    */
    /* The input data is read "N/4" complex samples apart or "N/2"     */
    /* words apart using pointers "x0" and "x2". This produces out-    */
    /* puts that are 0, N/8, N/2, 3N/8 for radix 2.                    */
    /*-----------------------------------------------------------------*/
    y0 = ptr_y;
    y2 = ptr_y + (int)npoints;
    x0 = ptr_x;
    x2 = ptr_x + (int)(npoints >> 1);

    /*----------------------------------------------------------------*/
    /* The pointers are set at the following locations which are half */
    /* the offsets of a radix4 FFT.                                   */
    /*----------------------------------------------------------------*/
    y1 = y0 + (int)(npoints >> 2);
    y3 = y2 + (int)(npoints >> 2);
    l1 = _norm(npoints) + 1;
    n0 = npoints >> 1;

    yb0 = y0 + 2;
    yb1 = y1 + 2;
    yb2 = y2 + 2;
    yb3 = y3 + 2;

    /*--------------------------------------------------------------------*/
    /* The following code reads data identically for either a radix 4     */
    /* or a radix 2 style decomposition. It writes out at different       */
    /* locations though. It checks if either half the points, or a        */
    /* quarter of the complex points have been exhausted to jump to       */
    /* pervent double reversal.                                           */
    /*--------------------------------------------------------------------*/
    j = 0;

    _nassert((int)(npoints) % 4  == 0);
    _nassert((int)(ptr_x) % 8 == 0);
    _nassert((int)(ptr_y) % 8 == 0);
    _nassert((int)(x0) % 8 == 0);
    _nassert((int)(x2) % 8 == 0);
    _nassert((int)(y0) % 8 == 0);
    #pragma MUST_ITERATE(2,,2);
    for (i = 0; i < npoints; i += 8) {
        /*----------------------------------------------------------------*/
        /* Digit reverse the index starting from 0. The increment to "j"  */
        /* is either by 4, or 8.                                          */
        /*----------------------------------------------------------------*/
        h2 = _deal(j);
        h2 = _bitr(h2);
        h2 = _rotl(h2, 16);
        h2 = _shfl(h2);
        h2 >>= l1;

        /*----------------------------------------------------------------*/
        /* Read in the input data. These are transformed as a radix 2.    */
        /*----------------------------------------------------------------*/
        x01 = _amem8(&x0[0]);
        x23 = _amem8(&x0[2]);
        x45 = _amem8(&x0[4]);
        x67 = _amem8(&x0[6]);
        x0 += 8;

        x89 = _amem8(&x2[0]);
        xAB = _amem8(&x2[2]);
        xCD = _amem8(&x2[4]);
        xEF = _amem8(&x2[6]);
        x2 += 8;

        /*-------------------------------------------------------------*/
        /* Perform radix2 style decomposition.                         */
        /*-------------------------------------------------------------*/
        n00_n01 = _dadd(x01, x23);
        n20_n21 = _dsub(x01, x23);
        n10_n11 = _dadd(x45, x67);
        n30_n31 = _dsub(x45, x67);

        n02_n03 = _dadd(x89, xAB);
        n22_n23 = _dsub(x89, xAB);
        n12_n13 = _dadd(xCD, xEF);
        n32_n33 = _dsub(xCD, xEF);

        /*-----------------------------------------------------------------*/
        /* Points that are read from succesive locations map to y, y[N/8]  */
        /* y[N/2],y[5N/8] in a radix2 scheme.                              */
        /*-----------------------------------------------------------------*/
        _amem8(&y0[2*h2])  = n00_n01;
        _amem8(&y1[2*h2])  = n10_n11;
        _amem8(&y2[2*h2])  = n20_n21;
        _amem8(&y3[2*h2])  = n30_n31;

        _amem8(&yb0[2*h2]) = n02_n03;
        _amem8(&yb1[2*h2]) = n12_n13;
        _amem8(&yb2[2*h2]) = n22_n23;
        _amem8(&yb3[2*h2]) = n32_n33;

        j += 8;
        if (j == n0) {
            j  += n0;
            x0 += (int)npoints >> 1;
            x2 += (int)npoints >> 1;
        }
    }
}

void radix_4 (
    int * restrict ptr_x,
    int * restrict ptr_y,
    int npoints
)
{
    int * restrict x0, * restrict x2;
    int * restrict y0, * restrict y1, * restrict y2, * restrict y3;
    int * restrict yb0, * restrict yb1, * restrict yb2, * restrict yb3;
    int n0, j, i, h2, l1;
    int n11, n10, n31, n30;

    long long x01, x23, x45, x67, x89, xab, xcd, xef;
    long long xh0_0_xh1_0, xh0_1_xh1_1, xl0_0_xl1_0, xl0_1_xl1_1;
    long long n00_n01, n20_n21;
                              
    /*-----------------------------------------------------------------*/
    /* The following code performs either a standard radix2 pass. Two  */
    /* pointers are used to access the input data. The input data is   */
    /* read "N/4" complex samples apart or "N/2" words apart using     */
    /* pointers "x0" and "x2". This produces outputs that are 0, N/4,  */
    /* N/2, 3N/4 for a radix4 FFT.                                     */
    /*-----------------------------------------------------------------*/
    y0 = ptr_y;
    y2 = ptr_y + (int)npoints;
    x0 = ptr_x;
    x2 = ptr_x + (int)(npoints >> 1);

    /*----------------------------------------------------------------*/
    /* The pointers are set at the following locations                */
    /*----------------------------------------------------------------*/
    y1 = y0 + (int)(npoints >> 1);
    y3 = y2 + (int)(npoints >> 1);
    l1 = _norm(npoints) + 2;
    n0 = npoints >> 2;

    yb0 = y0 + 2;
    yb1 = y1 + 2;
    yb2 = y2 + 2;
    yb3 = y3 + 2;
   
    /*--------------------------------------------------------------------*/
    /* The following code reads data identically for either a radix 4     */
    /* or a radix 2 style decomposition. It writes out at different       */
    /* locations though. It checks if either half the points, or a        */
    /* quarter of the complex points have been exhausted to jump to       */
    /* pervent double reversal.                                           */
    /*--------------------------------------------------------------------*/
    j = 0;
    
    _nassert((int)(npoints) % 4  == 0);
    _nassert((int)(x0) % 8 == 0);
    _nassert((int)(x2) % 8 == 0);
    _nassert((int)(y0) % 8 == 0);
    _nassert(npoints >= 16);
    #pragma MUST_ITERATE(2,,2);
    for (i = 0; i < npoints; i += 8) {
        /*----------------------------------------------------------------*/
        /* Digit reverse the index starting from 0. The increment to "j"  */
        /* is either by 4, or 8.                                          */
        /*----------------------------------------------------------------*/
        h2 = _deal(j);
        h2 = _bitr(h2);
        h2 = _rotl(h2, 16);
        h2 = _shfl(h2);
        h2 >>= l1;

        /*----------------------------------------------------------------*/
        /* Read in the input data, from the first eight locations. These  */
        /* are transformed as a radix4.                                   */
        /*----------------------------------------------------------------*/
        x01 = _amem8(&x0[0]);
        x23 = _amem8(&x0[2]);
        x45 = _amem8(&x0[4]);
        x67 = _amem8(&x0[6]);
        x0 += 8;

        xh0_0_xh1_0 = _dadd(x01, x45);
        xh0_1_xh1_1 = _dadd(x23, x67);
        xl0_0_xl1_0 = _dsub(x01, x45);
        xl0_1_xl1_1 = _dsub(x23, x67);

        n00_n01 = _dadd(xh0_0_xh1_0, xh0_1_xh1_1);
        n20_n21 = _dsub(xh0_0_xh1_0, xh0_1_xh1_1);
        n11 = _loll(xl0_0_xl1_0) + _hill(xl0_1_xl1_1);
        n10 = _hill(xl0_0_xl1_0) - _loll(xl0_1_xl1_1);
        n31 = _loll(xl0_0_xl1_0) - _hill(xl0_1_xl1_1);
        n30 = _hill(xl0_0_xl1_0) + _loll(xl0_1_xl1_1);

        _amem8(&y0[2*h2]) = n00_n01;
        _amem8(&y1[2*h2]) = _itoll(n10, n11);
        _amem8(&y2[2*h2]) = n20_n21;
        _amem8(&y3[2*h2]) = _itoll(n30, n31);

        /*----------------------------------------------------------------*/
        /* Read in the next eight inputs and perform radix4 decomposition */
        /*----------------------------------------------------------------*/
        x89 = _amem8(&x2[0]);
        xab = _amem8(&x2[2]);
        xcd = _amem8(&x2[4]);
        xef = _amem8(&x2[6]);
        x2 += 8;

        xh0_0_xh1_0 = _dadd(x89, xcd);
        xh0_1_xh1_1 = _dadd(xab, xef);
        xl0_0_xl1_0 = _dsub(x89, xcd);
        xl0_1_xl1_1 = _dsub(xab, xef);

        n00_n01 = _dadd(xh0_0_xh1_0, xh0_1_xh1_1);
        n20_n21 = _dsub(xh0_0_xh1_0, xh0_1_xh1_1);
        n11 = _loll(xl0_0_xl1_0) + _hill(xl0_1_xl1_1);
        n10 = _hill(xl0_0_xl1_0) - _loll(xl0_1_xl1_1);
        n31 = _loll(xl0_0_xl1_0) - _hill(xl0_1_xl1_1);
        n30 = _hill(xl0_0_xl1_0) + _loll(xl0_1_xl1_1);

        /*-----------------------------------------------------------------*/
        /* Points that are read from succesive locations map to y, y[N/4]  */
        /* y[N/2], y[3N/4] in a radix4 scheme.                             */
        /*-----------------------------------------------------------------*/
        _amem8(&yb0[2*h2]) = n00_n01;
        _amem8(&yb1[2*h2]) = _itoll(n10, n11);
        _amem8(&yb2[2*h2]) = n20_n21;
        _amem8(&yb3[2*h2]) = _itoll(n30, n31);

        j += 4;
        if (j == n0) {
            j += n0;
            x0 += (int)npoints >> 1;
            x2 += (int)npoints >> 1;
        }
    }
}
#endif
/* ======================================================================== */
/*  End of file: DSP_ifft32x32.c                                            */
/* ------------------------------------------------------------------------ */
/*          Copyright (C) 2011 Texas Instruments, Incorporated.             */
/*                          All Rights Reserved.                            */
/* ======================================================================== */

