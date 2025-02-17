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
#ifndef CSLR_PRCM_MPU_DEVICE_H
#define CSLR_PRCM_MPU_DEVICE_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 PRM_RSTST_REG;
    volatile Uint32 PRM_PSCON_COUNT_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 PRM_FRAC_INCREMENTER_NUMERATOR_REG;
    volatile Uint32 PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG;
} CSL_prcm_mpu_deviceRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register logs the global reset sources. Each bit is set upon release
 * of the domain reset signal. Must be cleared by software. This register is
 * insensitive to global warm reset. */
#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG                       (0x0U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST         (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG)


/* Programmable Precharge count for L1Cache */
#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG                 (0x4U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT   (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG)


/* Fractional incrementor */
#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG  (0x10U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_NUMERATOR  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG)


/* reload command and denominator to be used infractional incrementor. */
#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG  (0x14U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* MPU_PRM_RSTST_REG */

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_COLD_RST_MASK                (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST_SHIFT  (0U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_COLD_RST_SHIFT               (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_COLD_RST__0x0                (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST__0X0)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_COLD_RST__0x1                (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_COLD_RST__0X1)


#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_WARM_RST_MASK                (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST_SHIFT  (1U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_WARM_RST_SHIFT               (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_WARM_RST__0x0                (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST__0X0)

#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define MPU_PRM_RSTST_GLOBAL_WARM_RST__0x1                (CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_GLOBAL_WARM_RST__0X1)


#define CSL_PRCM_MPU_DEVICE_PRM_RSTST_REG_RESETVAL              (0x00000001U)

/* MPU_PRM_PSCON_COUNT_REG */

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_PCHARGE_TIME_MASK  (0x000000FFU)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_PCHARGE_TIME_MASK             (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_PCHARGE_TIME_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_PCHARGE_TIME_RESETVAL  (0x00000017U)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_PCHARGE_TIME_SHIFT  (0U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_PCHARGE_TIME_SHIFT            (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_PCHARGE_TIME_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_PCHARGE_TIME_MAX  (0x000000ffU)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGDOODIN_TIME_MASK  (0x00FF0000U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_PONOUT_2_PGDOODIN_TIME_MASK  (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGDOODIN_TIME_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGDOODIN_TIME_RESETVAL  (0x00000030U)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGDOODIN_TIME_SHIFT  (16U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_PONOUT_2_PGDOODIN_TIME_SHIFT  (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGDOODIN_TIME_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGDOODIN_TIME_MAX  (0x000000ffU)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_RAMPUP_MASK                (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_SHIFT  (25U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_RAMPUP_SHIFT               (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_SLOW  (0x00000000U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_RAMPUP_Slow                (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_SLOW)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_FAST  (0x00000001U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_RAMPUP_Fast                (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_RAMPUP_FAST)


#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_MASK      (0x01000000U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_EN_MASK                    (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_SHIFT     (24U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_EN_SHIFT                   (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_HG_DISABLE  (0x00000000U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_EN_HG_disable              (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_HG_DISABLE)

#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_HG_ENABLE  (0x00000001U)
/* Below define for backward compatibility */
#define MPU_PRM_PSCON_COUNT_HG_EN_HG_enable               (CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_HG_EN_HG_ENABLE)


#define CSL_PRCM_MPU_DEVICE_PRM_PSCON_COUNT_REG_RESETVAL        (0x00300017U)

/* MPU_PRM_FRAC_INCREMENTER_NUMERATOR_REG */

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_SYS_MODE_NUMERATOR_MASK  (0x00000FFFU)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_NUMERATOR_SYS_MODE_NUMERATOR_MASK  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_SYS_MODE_NUMERATOR_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_SYS_MODE_NUMERATOR_RESETVAL  (0x00000208U)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_SYS_MODE_NUMERATOR_SHIFT  (0U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_NUMERATOR_SYS_MODE_NUMERATOR_SHIFT  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_SYS_MODE_NUMERATOR_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_SYS_MODE_NUMERATOR_MAX  (0x00000fffU)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_ABE_LP_MODE_NUMERATOR_MASK  (0x0FFF0000U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_NUMERATOR_ABE_LP_MODE_NUMERATOR_MASK  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_ABE_LP_MODE_NUMERATOR_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_ABE_LP_MODE_NUMERATOR_RESETVAL  (0x00000659U)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_ABE_LP_MODE_NUMERATOR_SHIFT  (16U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_NUMERATOR_ABE_LP_MODE_NUMERATOR_SHIFT  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_ABE_LP_MODE_NUMERATOR_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_ABE_LP_MODE_NUMERATOR_MAX  (0x00000fffU)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_NUMERATOR_REG_RESETVAL  (0x06590208U)

/* MPU_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG */

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_DENOMINATOR_MASK  (0x00000FFFU)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_DENOMINATOR_MASK  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_DENOMINATOR_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_DENOMINATOR_RESETVAL  (0x00000cb2U)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_DENOMINATOR_SHIFT  (0U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_DENOMINATOR_SHIFT  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_DENOMINATOR_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_DENOMINATOR_MAX  (0x00000fffU)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RELOAD_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_RELOAD_MASK  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RELOAD_MASK)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RELOAD_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RELOAD_SHIFT  (16U)
/* Below define for backward compatibility */
#define MPU_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_RELOAD_SHIFT  (CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RELOAD_SHIFT)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RELOAD_MAX  (0x00000001U)

#define CSL_PRCM_MPU_DEVICE_PRM_FRAC_INCREMENTER_DENUMERATOR_RELOAD_REG_RESETVAL  (0x00000cb2U)

#ifdef __cplusplus
}
#endif
#endif
