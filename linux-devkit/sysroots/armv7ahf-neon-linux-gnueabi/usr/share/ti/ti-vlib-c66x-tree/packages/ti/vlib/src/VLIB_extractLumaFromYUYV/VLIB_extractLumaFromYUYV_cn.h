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
**|         Copyright (c) 2007-2014 Texas Instruments Incorporated           |**
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

#ifndef VLIB_EXTRACTLUMAFROMYUYV_CN_H_
#define VLIB_EXTRACTLUMAFROMYUYV_CN_H_ 1

int32_t VLIB_extractLumaFromYUYV_cn(uint8_t *restrict pInYxYx,
                                    uint16_t inCols, uint16_t inPitch,
                                    uint16_t inRows,
                                    uint8_t *restrict pOutY);


#endif

/* ======================================================================== */
/*  End of file:  VLIB_extractLumaFromYUYV_cn.h                             */
/* ======================================================================== */

