/*
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   hw_coreaon_prm.h
 *
 *  \brief  Register-level header file for PRCM
 *
**/

#ifndef HW_COREAON_PRM_H_
#define HW_COREAON_PRM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP                        (0x0U)
#define RM_COREAON_SMARTREFLEX_MPU_CONTEXT                      (0x4U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP                       (0x10U)
#define RM_COREAON_SMARTREFLEX_CORE_CONTEXT                     (0x14U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP                        (0x30U)
#define RM_COREAON_SMARTREFLEX_GPU_CONTEXT                      (0x34U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP                     (0x40U)
#define RM_COREAON_SMARTREFLEX_DSPEVE_CONTEXT                   (0x44U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP                      (0x50U)
#define RM_COREAON_SMARTREFLEX_IVAHD_CONTEXT                    (0x54U)
#define RM_COREAON_DUMMY_MODULE1_CONTEXT                        (0x84U)
#define RM_COREAON_DUMMY_MODULE2_CONTEXT                        (0x94U)
#define RM_COREAON_DUMMY_MODULE3_CONTEXT                        (0xa4U)
#define RM_COREAON_DUMMY_MODULE4_CONTEXT                        (0xb4U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_MPU_SHIFT  (0U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_MPU_MASK  (0x00000001U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_MPU_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_MPU_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU2_SHIFT  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU2_MASK  (0x00000002U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP1_SHIFT  (2U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP1_MASK  (0x00000004U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU1_SHIFT  (4U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU1_MASK  (0x00000010U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_IPU1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP2_SHIFT  (5U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP2_MASK  (0x00000020U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_DSP2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE1_SHIFT  (6U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE1_MASK  (0x00000040U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE2_SHIFT  (7U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE2_MASK  (0x00000080U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE3_SHIFT  (8U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE3_MASK  (0x00000100U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE3_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE3_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE4_SHIFT  (9U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE4_MASK  (0x00000200U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE4_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_MPU_WKDEP_WKUPDEP_SMARTREFLEX_MPU_EVE4_DISABLED  (0U)

#define RM_COREAON_SMARTREFLEX_MPU_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_SMARTREFLEX_MPU_CONTEXT_LOSTCONTEXT_DFF_MASK  (0x00000001U)
#define RM_COREAON_SMARTREFLEX_MPU_CONTEXT_LOSTCONTEXT_DFF_LOST  (1U)
#define RM_COREAON_SMARTREFLEX_MPU_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_MPU_SHIFT  (0U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_MPU_MASK  (0x00000001U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_MPU_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_MPU_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU2_SHIFT  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU2_MASK  (0x00000002U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP1_SHIFT  (2U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP1_MASK  (0x00000004U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU1_SHIFT  (4U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU1_MASK  (0x00000010U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_IPU1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP2_SHIFT  (5U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP2_MASK  (0x00000020U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_DSP2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE1_SHIFT  (6U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE1_MASK  (0x00000040U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE2_SHIFT  (7U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE2_MASK  (0x00000080U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE3_SHIFT  (8U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE3_MASK  (0x00000100U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE3_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE3_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE4_SHIFT  (9U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE4_MASK  (0x00000200U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE4_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_CORE_WKDEP_WKUPDEP_SMARTREFLEX_CORE_EVE4_DISABLED  (0U)

#define RM_COREAON_SMARTREFLEX_CORE_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_SMARTREFLEX_CORE_CONTEXT_LOSTCONTEXT_DFF_MASK  (0x00000001U)
#define RM_COREAON_SMARTREFLEX_CORE_CONTEXT_LOSTCONTEXT_DFF_LOST  (1U)
#define RM_COREAON_SMARTREFLEX_CORE_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_MPU_SHIFT  (0U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_MPU_MASK  (0x00000001U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_MPU_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_MPU_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP1_SHIFT  (2U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP1_MASK  (0x00000004U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU2_SHIFT  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU2_MASK  (0x00000002U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU1_SHIFT  (4U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU1_MASK  (0x00000010U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_IPU1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP2_SHIFT  (5U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP2_MASK  (0x00000020U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_DSP2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE1_SHIFT  (6U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE1_MASK  (0x00000040U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE2_SHIFT  (7U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE2_MASK  (0x00000080U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE3_SHIFT  (8U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE3_MASK  (0x00000100U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE3_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE3_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE4_SHIFT  (9U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE4_MASK  (0x00000200U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE4_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_GPU_WKDEP_WKUPDEP_SMARTREFLEX_GPU_EVE4_DISABLED  (0U)

#define RM_COREAON_SMARTREFLEX_GPU_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_SMARTREFLEX_GPU_CONTEXT_LOSTCONTEXT_DFF_MASK  (0x00000001U)
#define RM_COREAON_SMARTREFLEX_GPU_CONTEXT_LOSTCONTEXT_DFF_LOST  (1U)
#define RM_COREAON_SMARTREFLEX_GPU_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_MPU_SHIFT  (0U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_MPU_MASK  (0x00000001U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_MPU_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_MPU_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP1_SHIFT  (2U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP1_MASK  (0x00000004U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU2_SHIFT  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU2_MASK  (0x00000002U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_SDMA_SHIFT  (3U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_SDMA_MASK  (0x00000008U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_SDMA_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_SDMA_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU1_SHIFT  (4U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU1_MASK  (0x00000010U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_IPU1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP2_SHIFT  (5U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP2_MASK  (0x00000020U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_DSP2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE1_SHIFT  (6U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE1_MASK  (0x00000040U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE2_SHIFT  (7U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE2_MASK  (0x00000080U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE3_SHIFT  (8U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE3_MASK  (0x00000100U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE3_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE3_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE4_SHIFT  (9U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE4_MASK  (0x00000200U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE4_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_DSPEVE_WKDEP_WKUPDEP_SMARTREFLEX_DSPEVE_EVE4_DISABLED  (0U)

#define RM_COREAON_SMARTREFLEX_DSPEVE_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_SMARTREFLEX_DSPEVE_CONTEXT_LOSTCONTEXT_DFF_MASK  (0x00000001U)
#define RM_COREAON_SMARTREFLEX_DSPEVE_CONTEXT_LOSTCONTEXT_DFF_LOST  (1U)
#define RM_COREAON_SMARTREFLEX_DSPEVE_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_MPU_SHIFT  (0U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_MPU_MASK  (0x00000001U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_MPU_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_MPU_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP1_SHIFT  (2U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP1_MASK  (0x00000004U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU2_SHIFT  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU2_MASK  (0x00000002U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU1_SHIFT  (4U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU1_MASK  (0x00000010U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_IPU1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP2_SHIFT  (5U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP2_MASK  (0x00000020U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_DSP2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE1_SHIFT  (6U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE1_MASK  (0x00000040U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE1_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE1_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE2_SHIFT  (7U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE2_MASK  (0x00000080U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE2_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE2_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE3_SHIFT  (8U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE3_MASK  (0x00000100U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE3_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE3_DISABLED  (0U)

#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE4_SHIFT  (9U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE4_MASK  (0x00000200U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE4_ENABLED  (1U)
#define PM_COREAON_SMARTREFLEX_IVAHD_WKDEP_WKUPDEP_SMARTREFLEX_IVAHD_EVE4_DISABLED  (0U)

#define RM_COREAON_SMARTREFLEX_IVAHD_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_SMARTREFLEX_IVAHD_CONTEXT_LOSTCONTEXT_DFF_MASK  (0x00000001U)
#define RM_COREAON_SMARTREFLEX_IVAHD_CONTEXT_LOSTCONTEXT_DFF_LOST  (1U)
#define RM_COREAON_SMARTREFLEX_IVAHD_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define RM_COREAON_DUMMY_MODULE1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_DUMMY_MODULE1_CONTEXT_LOSTCONTEXT_DFF_MASK   (0x00000001U)
#define RM_COREAON_DUMMY_MODULE1_CONTEXT_LOSTCONTEXT_DFF_LOST    (1U)
#define RM_COREAON_DUMMY_MODULE1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define RM_COREAON_DUMMY_MODULE2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_DUMMY_MODULE2_CONTEXT_LOSTCONTEXT_DFF_MASK   (0x00000001U)
#define RM_COREAON_DUMMY_MODULE2_CONTEXT_LOSTCONTEXT_DFF_LOST    (1U)
#define RM_COREAON_DUMMY_MODULE2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define RM_COREAON_DUMMY_MODULE3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_DUMMY_MODULE3_CONTEXT_LOSTCONTEXT_DFF_MASK   (0x00000001U)
#define RM_COREAON_DUMMY_MODULE3_CONTEXT_LOSTCONTEXT_DFF_LOST    (1U)
#define RM_COREAON_DUMMY_MODULE3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#define RM_COREAON_DUMMY_MODULE4_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (0U)
#define RM_COREAON_DUMMY_MODULE4_CONTEXT_LOSTCONTEXT_DFF_MASK   (0x00000001U)
#define RM_COREAON_DUMMY_MODULE4_CONTEXT_LOSTCONTEXT_DFF_LOST    (1U)
#define RM_COREAON_DUMMY_MODULE4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (0U)

#ifdef __cplusplus
}
#endif

#endif /* HW_COREAON_PRM_H_ */

