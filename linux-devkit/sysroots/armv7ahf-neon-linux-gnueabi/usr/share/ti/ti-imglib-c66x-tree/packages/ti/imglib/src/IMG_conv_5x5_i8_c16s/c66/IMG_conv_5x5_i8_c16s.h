/* ======================================================================== *
 * IMGLIB -- TI Image and Video Processing Library                          *
 *                                                                          *
 *                                                                          *
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/   *
 *                                                                          *
 *                                                                          *
 *  Redistribution and use in source and binary forms, with or without      *
 *  modification, are permitted provided that the following conditions      *
 *  are met:                                                                *
 *                                                                          *
 *    Redistributions of source code must retain the above copyright        *
 *    notice, this list of conditions and the following disclaimer.         *
 *                                                                          *
 *    Redistributions in binary form must reproduce the above copyright     *
 *    notice, this list of conditions and the following disclaimer in the   *
 *    documentation and/or other materials provided with the                *
 *    distribution.                                                         *
 *                                                                          *
 *    Neither the name of Texas Instruments Incorporated nor the names of   *
 *    its contributors may be used to endorse or promote products derived   *
 *    from this software without specific prior written permission.         *
 *                                                                          *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     *
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       *
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   *
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    *
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   *
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        *
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   *
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   *
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     *
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   *
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    *
 * ======================================================================== */

#ifndef IMG_CONV_5X5_I8_C16S_H_
#define IMG_CONV_5X5_I8_C16S_H_ 1

/** @defgroup IMG_conv_5x5_i8_c16s */
/** @ingroup  IMG_conv_5x5_i8_c16s */
/* @{ */

/**
 * @par Description:
 *  The convolution kernel accepts five rows of 'pitch' input pixels 
 *  and produces one row of 'width' output pixels using the five pixel
 *  square filter mask provided on input.  The input and output image 
 *  pixels are provided in 8-bit unsigned format and the mask is in 
 *   16-bit signed format.
 * @par
 *  The input mask is rotated 180 degrees prior to calculating the 
 *  convolution sum.  The convolution sum is calculated as a point by 
 *  point multiplication of the rotated mask with the input image. The 
 *  25 resulting multiplications are summed together to produce a 32-bit 
 *  intermediate sum. Overflow during accumulation is not prevented,
 *  though assumptions may be applied to filter gain to avoid overflow.
 * @par
 *  The user defined shift value is used to shift the convolution sum 
 *  down to a 8-bit range prior to storing in the output array. The 
 *  stored result is saturated accordingly. The mask is moved one column 
 *  at a time, advancing the mask over the image until the entire 'width'  
 *  is covered.  
 * @par 
 *    @param imgin_ptr    Pointer to an input image of 8-bit pixels
 *    @param imgout_ptr   Pointer to an output image of 8-bit pixels         
 *    @param width        Number of output pixels                    
 *    @param pitch        Number of columns in the image             
 *    @param mask_ptr     Pointer to a 16-bit filter mask             
 *    @param shift        User specified right shift on sum
 *
 *
 * @par Algorithm:
 *  The natural C implementation has no restrictions. The optimized     
 *  intrinsic C code has restrictions as noted in Assumptions below.    
 *
 *
 * @par Assumptions:
 *    - The input and output arrays should not overlap  
 *    - The output array must be 32-bit aligned
 *    - The mask array must be 16-bit aligned
 *    - The width parameter must be a non-zero multiple of 2
 *    - The image pitch must be greater than or equal to the width 
 *
 *
 * @par Implementation Notes:
 *    - This code is fully interruptible
 *    - This code is compatible with C66x processors
 *
 *
 * @par Benchmarks:
 *  See IMGLIB_Test_Report.html for cycle and memory information.
 *
 */

void IMG_conv_5x5_i8_c16s
(
    const unsigned char *restrict  imgin_ptr,
          unsigned char *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const          short *restrict  mask_ptr,
    short                              shift
);

/** @} */

#endif

/* ======================================================================== */
/*  End of file:  IMG_conv_5x5_i8_c16s.h                                    */
/* ======================================================================== */
