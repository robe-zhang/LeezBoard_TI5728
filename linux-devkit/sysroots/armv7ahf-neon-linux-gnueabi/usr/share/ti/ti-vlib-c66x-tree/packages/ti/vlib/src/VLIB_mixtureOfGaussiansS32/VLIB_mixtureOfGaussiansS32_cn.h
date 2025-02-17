/*******************************************************************************
**+--------------------------------------------------------------------------+**
**|                            ****                                          |**
**|                            ****                                          |**
**|                            ******o***                                    |**
**|                      ********_///_****                                   |**
**|                      ***** /_//_/ ****                                   |**
**|                       ** ** (__/ ****                                    |**
**|                           *********                                      |**
**|                            ****                                          |**
**|                            ***                                           |**
**|                                                                          |**
**|         Copyright (c) 2007-2012 Texas Instruments Incorporated           |**
**|                        ALL RIGHTS RESERVED                               |**
**|                                                                          |**
**| Permission to use, copy, modify, or distribute this software,            |**
**| whether in part or in whole, for any purpose is forbidden without        |**
**| a signed licensing agreement and NDA from Texas Instruments              |**
**| Incorporated (TI).                                                       |**
**|                                                                          |**
**| TI makes no representation or warranties with respect to the             |**
**| performance of this computer program, and specifically disclaims         |**
**| any responsibility for any damages, special or consequential,            |**
**| connected with the use of this program.                                  |**
**|                                                                          |**
**+--------------------------------------------------------------------------+**
*******************************************************************************/

#ifndef VLIB_MIXTUREOFGAUSSIANSS32_CN_H_
#define VLIB_MIXTUREOFGAUSSIANSS32_CN_H_ 1

int32_t VLIB_mixtureOfGaussiansS32_cn(const uint8_t *restrict Im,
                                      int16_t *restrict wt,
                                      int32_t *restrict mu,
                                      int32_t *restrict var,
                                      uint8_t *restrict compNum,
                                      uint8_t *restrict updateMask8,
                                      uint32_t *restrict Im_mask,
                                      const int32_t im_size,
                                      const int16_t alpha,
                                      const int32_t rho,
                                      const int32_t delta,
                                      const int16_t T,
                                      const int16_t ini_wt,
                                      const int32_t ini_var);

#endif

/* ======================================================================== */
/*  End of file:  VLIB_mixtureOfGaussiansS32_cn.h                           */
/* ======================================================================== */

