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

#ifndef VLIB_NONMAXSUPPRESS_U16_IDAT_H

#define VLIB_NONMAXSUPPRESS_U16_IDAT_H

#include "../common/VLIB_test.h"

typedef struct {
    uint8_t   testPattern;  /* 0: constant, 1: sequential, 2: random, 3: static array, 4: file, etc */
    uint16_t *staticIn;
    int16_t  *staticOut;
    int32_t   w;
    int32_t   h;
    int32_t   filterWidth;
    uint16_t  threshold;
} nonMaxSuppressU16_testParams_t;

void nonMaxSuppressU16_getTestParams(nonMaxSuppressU16_testParams_t * *params, int32_t *numTests);

#endif /* define VLIB_NONMAXSUPPRESS_U16_IDAT_H */

/* ======================================================================== */
/*  End of file:  VLIB_nonMaxSuppress_U16_idat.h                            */
/* ======================================================================== */

