/* ======================================================================= */
/*  TEXAS INSTRUMENTS, INC.                                                */
/*                                                                         */
/*  NAME                                                                   */
/*      DSP_fft16x16_imre_cn -- fft16x16_imre                              */
/*                                                                         */
/*      USAGE                                                              */
/*           This routine is C-callable and can be called as:              */
/*                                                                         */
/*          void DSP_fft16x16_imre_cn (                                    */
/*              const short * ptr_w,                                       */
/*              int npoints,                                               */
/*              short * ptr_x,                                             */
/*              short * ptr_y                                              */
/*          );                                                             */
/*                                                                         */
/*            ptr_w   =  input twiddle factors                             */
/*            npoints =  number of points                                  */
/*            ptr_x   =  transformed data reversed                         */
/*            ptr_y   =  linear transformed data                           */
/*                                                                         */
/*                                                                         */
/*  DESCRIPTION                                                            */
/*    The following code performs a mixed radix FFT for "npoints" which    */
/*    is either a multiple of 4 or 2. It uses logN4 - 1 stages of radix4   */
/*    transform and performs either a radix2 or radix4 transform on the    */
/*    last stage depending on "npoints". If "npoints" is a multiple of 4,  */
/*    then this last stage is also a radix4 transform, otherwise it is a   */
/*    radix2 transform.                                                    */
/*                                                                         */
/*   input to this routine is in Imaginary/Real order instead of the       */
/*      traditional Real/Imaginary order.                                  */
/*                                                                         */
/* int gen_twiddle_fft16x16(short *w, int n)                               */
/*                                                                         */
/*    int i, j, k;                                                         */
/*     double M = 32767.5;                                                 */
/*                                                                         */
/*    for (j = 1, k = 0; j < n >> 2; j = j << 2)                           */
/*    {                                                                    */
/*        for (i = 0; i < n >> 2; i += j << 1)                             */
/*        {                                                                */
/*                                                                         */
/*          w[k +  3] = d2s(M * cos(2.0 * PI * (i + j) / n));              */
/*          w[k +  2] = -d2s(M * sin(2.0 * PI * (i + j) / n));             */
/*          w[k +  1] = d2s(M * cos(2.0 * PI * (i    ) / n));              */
/*          w[k +  0] = -d2s(M * sin(2.0 * PI * (i    ) / n));             */
/*                                                                         */
/*          k += 4;                                                        */
/*                                                                         */
/*      }                                                                  */
/*    }                                                                    */
/*                                                                         */
/*    return k;                                                            */
/*                                                                         */
/*      The final stage is optimised to remove the multiplication as       */
/*      w0 = 1.  This stage also performs digit reversal on the data,      */
/*      so the final output is in natural order.                           */
/*                                                                         */
/*      The fft() code shown here performs the bulk of the computation     */
/*      in place. However, because digit-reversal cannot be performed      */
/*      in-place, the final result is written to a separate array, y[].    */
/*                                                                         */
/*                                                                         */
/*  ASSUMPTIONS                                                            */
/*      This code works for  both "npoints" a multiple of 2 or 4.          */
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


#pragma CODE_SECTION(DSP_fft16x16_imre_cn, ".text:ansi");

#include "DSP_fft16x16_imre_cn.h"

#if 0
# define DIG_REV(i, m, j) ((j) = (_shfl(_rotl(_bitr(_deal(i)), 16)) >> (m)))
#else
# define DIG_REV(i, m, j)                                                   \
    do {                                                                    \
        unsigned _ = (i);                                                   \
        _ = ((_ & 0x33333333) <<  2) | ((_ & ~0x33333333) >>  2);           \
        _ = ((_ & 0x0F0F0F0F) <<  4) | ((_ & ~0x0F0F0F0F) >>  4);           \
        _ = ((_ & 0x00FF00FF) <<  8) | ((_ & ~0x00FF00FF) >>  8);           \
        _ = ((_ & 0x0000FFFF) << 16) | ((_ & ~0x0000FFFF) >> 16);           \
        (j) = _ >> (m);                                                     \
    } while (0)
#endif

void DSP_fft16x16_imre_cn (
    const short * ptr_w,
    int npoints,
    short * ptr_x,
    short * ptr_y
)
{
    const short * w;
    short * x, * x2, * x0;
    short * y0, * y1, * y2, * y3;

    short xt0_0, yt0_0, xt1_0, yt1_0, xt2_0, yt2_0;
    short xt0_1, yt0_1, xt1_1, yt1_1, xt2_1, yt2_1;
    short xh0_0, xh1_0, xh20_0, xh21_0, xl0_0, xl1_0, xl20_0, xl21_0;
    short xh0_1, xh1_1, xh20_1, xh21_1, xl0_1, xl1_1, xl20_1, xl21_1;
    short x_0, x_1, x_2, x_3, x_l1_0, x_l1_1, x_l1_2, x_l1_3, x_l2_0, x_l2_1;
    short xh0_2, xh1_2, xl0_2, xl1_2, xh0_3, xh1_3, xl0_3, xl1_3;
    short x_4, x_5, x_6, x_7, x_l2_2, x_l2_3, x_h2_0, x_h2_1, x_h2_2, x_h2_3;
    short x_8, x_9, x_a, x_b, x_c, x_d, x_e, x_f;
    short si10, si20, si30, co10, co20, co30;
    short si11, si21, si31, co11, co21, co31;
    short n00, n10, n20, n30, n01, n11, n21, n31;
    short n02, n12, n22, n32, n03, n13, n23, n33;
    short n0, j0;

    int i, j, l1, l2, h2, predj, tw_offset, stride, fft_jmp, tw_jmp;
    int radix, m, norm;

    /*---------------------------------------------------------------------*/
    /* Determine the magnitude od the number of points to be transformed.  */
    /* Check whether we can use a radix4 decomposition or a mixed radix    */
    /* transformation, by determining modulo 2.                            */
    /*---------------------------------------------------------------------*/
    for (i = 31, m = 1; (npoints & (1 << i)) == 0; i--, m++)
        ;
    radix = m & 1 ? 2 : 4;
    norm = m - 2;

    /*----------------------------------------------------------------------*/
    /* The stride is quartered with every iteration of the outer loop. It   */
    /* denotes the seperation between any two adjacent inputs to the butter */
    /* -fly. This should start out at N/4, hence stride is initially set to */
    /* N. For every stride, 2*stride twiddle factors are accessed. The      */
    /* "tw_offset" is the offset within the current twiddle factor sub-     */
    /* table. This is set to zero, at the start of the code and is used to  */
    /* obtain the appropriate sub-table twiddle pointer by offseting it     */
    /* with the base pointer "ptr_w".                                       */
    /*----------------------------------------------------------------------*/
    stride = npoints;
    tw_offset = 0;
    fft_jmp = 6 * stride;
    tw_jmp  = 2 * stride;

    #ifndef NOASSUME
    _nassert(stride > 4);
    #pragma MUST_ITERATE(1,,1);
    #endif

    while (stride > 4) {
        /*-----------------------------------------------------------------*/
        /* At the start of every iteration of the outer loop, "j" is set   */
        /* to zero, as "w" is pointing to the correct location within the  */
        /* twiddle factor array. For every iteration of the inner loop     */
        /* 2 * stride twiddle factors are accessed. For eg,                */
        /*                                                                 */
        /* #Iteration of outer loop  # twiddle factors    #times cycled    */
        /*  1                          2 N/4               1               */
        /*  2                          2 N/16              4               */
        /*  ...                                                            */
        /*-----------------------------------------------------------------*/
        j = 0;
        fft_jmp >>= 2;
        tw_jmp  >>= 2;

        /*-----------------------------------------------------------------*/
        /* Set up offsets to access "N/4", "N/2", "3N/4" complex point or  */
        /* "N/2", "N", "3N/2" half word                                    */
        /*-----------------------------------------------------------------*/
        h2 = stride >> 1;
        l1 = stride;
        l2 = stride + (stride >> 1);

        /*-----------------------------------------------------------------*/
        /*  Reset "x" to point to the start of the input data array.       */
        /* "tw_offset" starts off at 0, and increments by "2 * stride"     */
        /*  The stride quarters with every iteration of the outer loop     */
        /*-----------------------------------------------------------------*/
        x = ptr_x;
        w = ptr_w + tw_offset;
        tw_offset += tw_jmp;
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
        /* fft_jmp amount. In addition the following code is unrolled to  */
        /* perform "2" radix4 butterflies in parallel.                    */
        /*----------------------------------------------------------------*/
        #ifndef NOASSUME
        _nassert((int)(w) % 8 == 0);
        _nassert((int)(x) % 8 == 0);
        _nassert(h2 % 8 == 0);
        _nassert(l1 % 8 == 0);
        _nassert(l2 % 8 == 0);
        #pragma MUST_ITERATE(1, , 1);
        #endif

        for (i = 0; i < (npoints >> 3); i++) {
            /*------------------------------------------------------------*/
            /* Read the first 4 twiddle factors, two of which are used    */
            /* for one radix 4 butterfly and two of which are used for    */
            /* next one.                                                  */
            /*------------------------------------------------------------*/

            /* twiddle factors for first butterfly */
#ifdef _LITTLE_ENDIAN            
            co10 = w[j+1];
            si10 = w[j+0];
#else
            co10 = w[j+0];
            si10 =-w[j+1];
#endif            
            co20 = (co10 * co10 - si10 * si10 + 0x4000) >> 15;
            si20 = (co10 * si10 + co10 * si10 + 0x4000) >> 15;
            co30 = (co10 * co20 - si10 * si20 + 0x4000) >> 15;
            si30 = (co10 * si20 + co20 * si10 + 0x4000) >> 15;

            /* twiddle factors for second butterfly */
#ifdef _LITTLE_ENDIAN            
            co11 = w[j+3];
            si11 = w[j+2];
#else
            co11 = w[j+2];
            si11 =-w[j+3];
#endif            
            co21 = (co11 * co11 - si11 * si11 + 0x4000) >> 15;
            si21 = (co11 * si11 + co11 * si11 + 0x4000) >> 15;
            co31 = (co11 * co21 - si11 * si21 + 0x4000) >> 15;
            si31 = (co11 * si21 + co21 * si11 + 0x4000) >> 15;

            /*------------------------------------------------------------*/
            /* Read in the first complex input for the butterflies.       */
            /* 1st complex input to 1st butterfly: x[0] + jx[1]           */
            /* 1st complex input to 2nd butterfly: x[2] + jx[3]           */
            /*------------------------------------------------------------*/
            x_0 = x[1];  /* Re[x(k)]         */
            x_1 = x[0];  /* Im[x(k)]         */
            x_2 = x[3];  /* second butterfly */
            x_3 = x[2];

            /*------------------------------------------------------------*/
            /* Read in the complex inputs for the butterflies. Each of the*/
            /* successive complex inputs of the butterfly are seperated   */
            /* by a fixed amount known as stride. The stride starts out   */
            /* at N/4, and quarters with every stage.                     */
            /*------------------------------------------------------------*/
            x_l1_0 = x[l1+1];  /* Re[x(k+N/2)]     */
            x_l1_1 = x[l1  ];  /* Im[x(k+N/2)]     */
            x_l1_2 = x[l1+3];  /* second butterfly */
            x_l1_3 = x[l1+2];

            x_l2_0 = x[l2+1];  /* Re[x(k+3*N/2)]   */
            x_l2_1 = x[l2  ];  /* Im[x(k+3*N/2)]   */
            x_l2_2 = x[l2+3];  /* second butterfly */
            x_l2_3 = x[l2+2];

            x_h2_0 = x[h2+1];  /* Re[x(k+N/4)]     */
            x_h2_1 = x[h2  ];  /* Im[x(k+N/4)]     */
            x_h2_2 = x[h2+3];  /* second butterfly */
            x_h2_3 = x[h2+2];

            /*-----------------------------------------------------------*/
            /* Two butterflies are evaluated in parallel. The following  */
            /* results will be shown for one butterfly only, although    */
            /* both are being evaluated in parallel.                     */
            /*                                                           */
            /* Perform radix2 style DIF butterflies.                     */
            /*-----------------------------------------------------------*/
            xh0_0 = x_0 + x_l1_0;    xh1_0 = x_1 + x_l1_1;
            xh0_1 = x_2 + x_l1_2;    xh1_1 = x_3 + x_l1_3;

            xl0_0 = x_0 - x_l1_0;    xl1_0 = x_1 - x_l1_1;
            xl0_1 = x_2 - x_l1_2;    xl1_1 = x_3 - x_l1_3;

            xh20_0 = x_h2_0 + x_l2_0;    xh21_0 = x_h2_1 + x_l2_1;
            xh20_1 = x_h2_2 + x_l2_2;    xh21_1 = x_h2_3 + x_l2_3;

            xl20_0 = x_h2_0 - x_l2_0;    xl21_0 = x_h2_1 - x_l2_1;
            xl20_1 = x_h2_2 - x_l2_2;    xl21_1 = x_h2_3 - x_l2_3;

            /*-----------------------------------------------------------*/
            /* Derive output pointers using the input pointer "x"        */
            /*-----------------------------------------------------------*/
            x0 = x;
            x2 = x0;

            /*-----------------------------------------------------------*/
            /* When the twiddle factors are not to be re-used, j is      */
            /* incremented by 4, to reflect the fact that 4 half words   */
            /* are consumed in every iteration. The input data pointer   */
            /* increments by 4. Note that within a stage, the stride     */
            /* does not change and hence the offsets for the other three */
            /* legs, 0, h2, l1, l2.                                      */
            /*-----------------------------------------------------------*/
            j += 4;
            x += 4;

            predj = (3*j - fft_jmp);
            if (!predj) x += fft_jmp;
            if (!predj) j = 0;

            /*----------------------------------------------------------*/
            /* These four partial results can be re-written to show     */
            /* the underlying DIF structure similar to radix2 as        */
            /* follows:                                                 */
            /*                                                          */
            /* X(4k)  = (x(n)+x(n + N/2)) + (x(n+N/4)+ x(n + 3N/4))     */
            /* X(4k+1)= (x(n)-x(n + N/2)) -j(x(n+N/4) - x(n + 3N/4))    */
            /* x(4k+2)= (x(n)+x(n + N/2)) - (x(n+N/4)+ x(n + 3N/4))     */
            /* X(4k+3)= (x(n)-x(n + N/2)) +j(x(n+N/4) - x(n + 3N/4))    */
            /*                                                          */
            /* which leads to the real and imaginary values as foll:    */
            /*                                                          */
            /* y0r = x0r + x2r +  x1r +  x3r    =  xh0 + xh20           */
            /* y0i = x0i + x2i +  x1i +  x3i    =  xh1 + xh21           */
            /* y1r = x0r - x2r + (x1i -  x3i)   =  xl0 + xl21           */
            /* y1i = x0i - x2i - (x1r -  x3r)   =  xl1 - xl20           */
            /* y2r = x0r + x2r - (x1r +  x3r)   =  xh0 - xh20           */
            /* y2i = x0i + x2i - (x1i +  x3i    =  xh1 - xh21           */
            /* y3r = x0r - x2r - (x1i -  x3i)   =  xl0 - xl21           */
            /* y3i = x0i - x2i + (x1r -  x3r)   =  xl1 + xl20           */
            /* ---------------------------------------------------------*/
            x0[1] = (xh0_0 + xh20_0 + 1) >> 1; //Re
            x0[0] = (xh1_0 + xh21_0 + 1) >> 1; //Im
            x0[3] = (xh0_1 + xh20_1 + 1) >> 1; //Re
            x0[2] = (xh1_1 + xh21_1 + 1) >> 1; //Im

            xt0_0 = xh0_0 - xh20_0;
            yt0_0 = xh1_0 - xh21_0;
            xt0_1 = xh0_1 - xh20_1;
            yt0_1 = xh1_1 - xh21_1;

            xt1_0 = xl0_0 + xl21_0;
            yt2_0 = xl1_0 + xl20_0;
            xt2_0 = xl0_0 - xl21_0;
            yt1_0 = xl1_0 - xl20_0;

            xt1_1 = xl0_1 + xl21_1;
            yt2_1 = xl1_1 + xl20_1;
            xt2_1 = xl0_1 - xl21_1;
            yt1_1 = xl1_1 - xl20_1;

            /*---------------------------------------------------------*/
            /* Perform twiddle factor multiplies of three terms,top    */
            /* term does not have any multiplies. Note the twiddle     */
            /* factors for a normal FFT are C + j (-S). Since the      */
            /* factors that are stored are C + j S, this is            */
            /* corrected for in the multiplies.                        */
            /*                                                         */
            /* Y1 = (xt1 + jyt1) (c + js) = (xc + ys) + (yc -xs)       */
            /*                                                         */
            /* Following equations REQUIRE SIN = -SIN in twiddle       */
            /* table                                                   */
            /*---------------------------------------------------------*/
            x2[l1+1] = (co20 * xt0_0 - si20 * yt0_0 + 0x8000) >> 16;
            x2[l1  ] = (co20 * yt0_0 + si20 * xt0_0 + 0x8000) >> 16;

            x2[l1+3] = (co21 * xt0_1 - si21 * yt0_1 + 0x8000) >> 16;
            x2[l1+2] = (co21 * yt0_1 + si21 * xt0_1 + 0x8000) >> 16;

            x2[h2+1] = (co10 * xt1_0 - si10 * yt1_0 + 0x8000) >> 16;
            x2[h2  ] = (co10 * yt1_0 + si10 * xt1_0 + 0x8000) >> 16;

            x2[h2+3] = (co11 * xt1_1 - si11 * yt1_1 + 0x8000) >> 16;
            x2[h2+2] = (co11 * yt1_1 + si11 * xt1_1 + 0x8000) >> 16;

            x2[l2+1] = (co30 * xt2_0 - si30 * yt2_0 + 0x8000) >> 16;
            x2[l2  ] = (co30 * yt2_0 + si30 * xt2_0 + 0x8000) >> 16;

            x2[l2+3] = (co31 * xt2_1 - si31 * yt2_1 + 0x8000) >> 16;
            x2[l2+2] = (co31 * yt2_1 + si31 * xt2_1 + 0x8000) >> 16;
        }
    }

    /*-----------------------------------------------------------------*/
    /* The following code performs either a standard radix4 pass or a  */
    /* radix2 pass. Two pointers are used to access the input data.    */
    /* The input data is read "N/4" complex samples apart or "N/2"     */
    /* words apart using pointers "x0" and "x2". This produces out-    */
    /* puts that are 0, N/4, N/2, 3N/4 for a radix4 FFT, and 0, N/8    */
    /* N/2, 3N/8 for radix 2.                                          */
    /*-----------------------------------------------------------------*/  
    y0 = ptr_y;
    y2 = ptr_y + (int)npoints;
    x0 = ptr_x;
    x2 = ptr_x + (int)(npoints >> 1);

    if (radix == 2) {
        /*----------------------------------------------------------------*/
        /* The pointers are set at the following locations which are half */
        /* the offsets of a radix4 FFT.                                   */
        /*----------------------------------------------------------------*/
        y1 = y0 + (int)(npoints >> 2);
        y3 = y2 + (int)(npoints >> 2);
        l1 = norm + 1;
        j0 = 8;
        n0 = npoints >> 1;
    }
    else {
        y1 = y0 + (int)(npoints >> 1);
        y3 = y2 + (int)(npoints >> 1);
        l1 = norm + 2;
        j0 = 4;
        n0 = npoints >> 2;
    }

    /*--------------------------------------------------------------------*/
    /* The following code reads data indentically for either a radix 4    */
    /* or a radix 2 style decomposition. It writes out at different       */
    /* locations though. It checks if either half the points, or a        */
    /* quarter of the complex points have been exhausted to jump to       */
    /* pervent double reversal.                                           */
    /*--------------------------------------------------------------------*/
    j = 0;

    #ifndef NOASSUME
    _nassert((int)(n0) % 4 == 0);
    _nassert((int)(x0) % 8 == 0);
    _nassert((int)(x2) % 8 == 0);
    _nassert((int)(y0) % 8 == 0);
    #pragma MUST_ITERATE(2,,2);
    #endif

    for (i = 0; i < npoints; i += 8) {
        /*----------------------------------------------------------------*/
        /* Digit reverse the index starting from 0. The increment to "j"  */
        /* is either by 4, or 8.                                          */
        /*----------------------------------------------------------------*/
        DIG_REV(j, l1, h2);

        /*----------------------------------------------------------------*/
        /* Read in the input data, from the first eight locations. These  */
        /* are transformed either as a radix4 or as a radix 2.            */
        /*----------------------------------------------------------------*/
        x_0 = x0[1]; //Re
        x_1 = x0[0]; //Im
        x_2 = x0[3];
        x_3 = x0[2];
        x_4 = x0[5];
        x_5 = x0[4];
        x_6 = x0[7];
        x_7 = x0[6];
        x0 += 8;

        xh0_0 = x_0 + x_4;
        xh1_0 = x_1 + x_5;
        xl0_0 = x_0 - x_4;
        xl1_0 = x_1 - x_5;
        xh0_1 = x_2 + x_6;
        xh1_1 = x_3 + x_7;
        xl0_1 = x_2 - x_6;
        xl1_1 = x_3 - x_7;

        n00 = xh0_0 + xh0_1;
        n01 = xh1_0 + xh1_1;
        n10 = xl0_0 + xl1_1;
        n11 = xl1_0 - xl0_1;
        n20 = xh0_0 - xh0_1;
        n21 = xh1_0 - xh1_1;
        n30 = xl0_0 - xl1_1;
        n31 = xl1_0 + xl0_1;

        if (radix == 2) {
            /*-------------------------------------------------------------*/
            /* Perform radix2 style decomposition.                         */
            /*-------------------------------------------------------------*/
            n00 = x_0 + x_2;
            n01 = x_1 + x_3;
            n20 = x_0 - x_2;
            n21 = x_1 - x_3;
            n10 = x_4 + x_6;
            n11 = x_5 + x_7;
            n30 = x_4 - x_6;
            n31 = x_5 - x_7;
        }

        y0[2*h2+1] = n00;  //Re
        y0[2*h2] = n01;    //Im
        y1[2*h2+1] = n10;  //Re
        y1[2*h2] = n11;    //Im
        y2[2*h2+1] = n20;  //Re
        y2[2*h2] = n21;    //Im
        y3[2*h2+1] = n30;
        y3[2*h2] = n31;

        /*----------------------------------------------------------------*/
        /* Read in ht enext eight inputs, and perform radix4 or radix2    */
        /* decomposition.                                                 */
        /*----------------------------------------------------------------*/

        x_8 = x2[1];   //Re
        x_9 = x2[0];   //Im
        x_a = x2[3];
        x_b = x2[2];
        x_c = x2[5];
        x_d = x2[4];
        x_e = x2[7];
        x_f = x2[6];
        x2 += 8;

        xh0_2 = x_8 + x_c; xh1_2  = x_9 + x_d;
        xl0_2 = x_8 - x_c; xl1_2  = x_9 - x_d;
        xh0_3 = x_a + x_e; xh1_3 = x_b + x_f;
        xl0_3 = x_a - x_e; xl1_3 = x_b - x_f;

        n02 = xh0_2 + xh0_3; n03 = xh1_2 + xh1_3;
        n12 = xl0_2 + xl1_3; n13 = xl1_2 - xl0_3;
        n22 = xh0_2 - xh0_3; n23 = xh1_2 - xh1_3;
        n32 = xl0_2 - xl1_3; n33 = xl1_2 + xl0_3;

        if (radix == 2) {
            n02 = x_8 + x_a;    n03 = x_9 + x_b;
            n22 = x_8 - x_a;    n23 = x_9 - x_b;
            n12 = x_c + x_e;    n13 = x_d + x_f;
            n32 = x_c - x_e;    n33 = x_d - x_f;
        }

        /*-----------------------------------------------------------------*/
        /* Points that are read from succesive locations map to y, y[N/4]  */
        /* y[N/2], y[3N/4] in a radix4 scheme, y, y[N/8], y[N/2],y[5N/8]   */
        /*-----------------------------------------------------------------*/
        y0[2*h2+3] = n02; //Re
        y0[2*h2+2] = n03; //Im

        y1[2*h2+3] = n12;
        y1[2*h2+2] = n13;

        y2[2*h2+3] = n22;
        y2[2*h2+2] = n23;

        y3[2*h2+3] = n32;
        y3[2*h2+2] = n33;

        j += j0;
        if (j == n0) {
            j  += n0;
            x0 += (int)npoints >> 1;
            x2 += (int)npoints >> 1;
        }
    }
}

/* ======================================================================== */
/*  End of file: DSP_fft16x16_imre_cn.c                                     */
/* ------------------------------------------------------------------------ */
/*          Copyright (C) 2011 Texas Instruments, Incorporated.             */
/*                          All Rights Reserved.                            */
/* ======================================================================== */

