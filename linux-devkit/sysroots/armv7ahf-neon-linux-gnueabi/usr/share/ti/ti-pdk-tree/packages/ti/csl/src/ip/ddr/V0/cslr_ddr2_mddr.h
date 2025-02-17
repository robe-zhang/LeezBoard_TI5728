/*
 * cslr_ddr2_mddr.h
 *
 * This file contains the macros for Register Chip Support Library (CSL) which 
 * can be used for operations on the respective underlying hardware/peripheral
 *
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
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


#ifndef CSLR_DDR2_MDDR_H_
#define CSLR_DDR2_MDDR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 4 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVID;
    volatile Uint32 SDRSTAT;
    volatile Uint32 SDCR;
    volatile Uint32 SDRCR;
    volatile Uint32 SDTIMR1;
    volatile Uint32 SDTIMR2;
    volatile Uint32 RSVD0;
    volatile Uint32 SDCR2;
    volatile Uint32 PBBPR;
    volatile Uint32 RSVD1[7];
    volatile Uint32 PC1;
    volatile Uint32 PC2;
    volatile Uint32 PCC;
    volatile Uint32 PCMRS;
    volatile Uint32 PCT;
    volatile Uint32 RSVD2[27];
    volatile Uint32 IRR;
    volatile Uint32 IMR;
    volatile Uint32 IMSR;
    volatile Uint32 IMCR;
    volatile Uint32 RSVD3[5];
    volatile Uint32 DRPYC1R;
} CSL_Ddr2_MddrRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_Ddr2_MddrRegs  *CSL_Ddr2_MddrRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVID */

#define CSL_DDR2_MDDR_REVID_ID_MASK         (0xFFFFFFFFu)
#define CSL_DDR2_MDDR_REVID_ID_SHIFT        (0x00000000u)
#define CSL_DDR2_MDDR_REVID_ID_RESETVAL     (0x40311B1Fu)

#define CSL_DDR2_MDDR_REVID_RESETVAL        (0x40311B1Fu)

/* SDRSTAT */


#define CSL_DDR2_MDDR_SDRSTAT_DUALCLK_MASK  (0x40000000u)
#define CSL_DDR2_MDDR_SDRSTAT_DUALCLK_SHIFT (0x0000001Eu)
#define CSL_DDR2_MDDR_SDRSTAT_DUALCLK_RESETVAL (0x00000001u)


#define CSL_DDR2_MDDR_SDRSTAT_PHYRDY_MASK   (0x00000004u)
#define CSL_DDR2_MDDR_SDRSTAT_PHYRDY_SHIFT  (0x00000002u)
#define CSL_DDR2_MDDR_SDRSTAT_PHYRDY_RESETVAL (0x00000000u)
/*----PHYRDY Tokens----*/
#define CSL_DDR2_MDDR_SDRSTAT_PHYRDY_DEASSERTED (0x00000000u)
#define CSL_DDR2_MDDR_SDRSTAT_PHYRDY_ASSERTED (0x00000001u)


#define CSL_DDR2_MDDR_SDRSTAT_RESETVAL      (0x40000000u)

/* SDCR */


#define CSL_DDR2_MDDR_SDCR_DDR2TERM1_MASK   (0x08000000u)
#define CSL_DDR2_MDDR_SDCR_DDR2TERM1_SHIFT  (0x0000001Bu)
#define CSL_DDR2_MDDR_SDCR_DDR2TERM1_RESETVAL (0x00000001u)
/*----DDR2TERM1 Tokens----*/
/* Tokens shown below should be used in conjunction with tokens for DDR2TERM0 to
 * generate the required temination resistor settings.                          
 * For example: 
 * To disable termination the required value is 00 (binary), which would
 * require DDR2TERM0 to be 0 and DDR2TERM1 to be 0. This could be generated as
 * shown below:
 * ((CSL_DDR2_MDDR_SDCR_DDR2TERM0_CLEAR | CSL_DDR2_MDDR_SDCR_DDR2TERM0_SHIFT) |
 *  (CSL_DDR2_MDDR_SDCR_DDR2TERM1_CLEAR | CSL_DDR2_MDDR_SDCR_DDR2TERM1_SHIFT))
 */
#define CSL_DDR2_MDDR_SDCR_DDR2TERM1_SET     (0x00000001u)
#define CSL_DDR2_MDDR_SDCR_DDR2TERM1_CLEAR   (0x00000000u)
 
#define CSL_DDR2_MDDR_SDCR_IBANK_POS_MASK   (0x04000000u)
#define CSL_DDR2_MDDR_SDCR_IBANK_POS_SHIFT  (0x0000001Au)
#define CSL_DDR2_MDDR_SDCR_IBANK_POS_RESETVAL (0x00000000u)
/*----IBANK_POS Tokens----*/
#define CSL_DDR2_MDDR_SDCR_IBANK_POS_DDR_ADDR_SCHM (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_IBANK_POS_MDDR_ADDR_SCHM (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_MSDRAMEN_MASK    (0x02000000u)
#define CSL_DDR2_MDDR_SDCR_MSDRAMEN_SHIFT   (0x00000019u)
#define CSL_DDR2_MDDR_SDCR_MSDRAMEN_RESETVAL (0x00000000u)
/*----MSDRAMEN Tokens----*/
#define CSL_DDR2_MDDR_SDCR_MSDRAMEN_MSDR_DIS (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_MSDRAMEN_MSDR_EN (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_DDRDRIVE1_MASK   (0x01000000u)
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE1_SHIFT  (0x00000018u)
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE1_RESETVAL (0x00000000u)
/*----DDRDRIVE1 Tokens----*/
/* Tokens shown below should be used in conjunction with tokens for DDRDRIVE1 to
 * generate the required temination resistor settings.                          
 * For example: 
 * For the case of weak driver streangth for DDR2 or 1/2 driver strength for mDDR
 * setting the required value is 01 (binary), which would require DDRDRIVE0 to 
 * be 1 and DDRDRIVE1 to be 0. This could be generated as shown below:
 * ((CSL_DDR2_MDDR_SDCR_DDRDRIVE0_SET | CSL_DDR2_MDDR_SDCR_DDRDRIVE0_SHIFT) |
 *  (CSL_DDR2_MDDR_SDCR_DDRDRIVE1_CLEAR | CSL_DDR2_MDDR_SDCR_DDRDRIVE1_SHIFT))
 */
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE1_SET     (0x00000001u)
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE1_CLEAR   (0x00000000u)

#define CSL_DDR2_MDDR_SDCR_BOOTUNLOCK_MASK  (0x00800000u)
#define CSL_DDR2_MDDR_SDCR_BOOTUNLOCK_SHIFT (0x00000017u)
#define CSL_DDR2_MDDR_SDCR_BOOTUNLOCK_RESETVAL (0x00000000u)
/*----BOOTUNLOCK Tokens----*/
#define CSL_DDR2_MDDR_SDCR_BOOTUNLOCK_NOCHANGE (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_BOOTUNLOCK_CHANGE (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_DDR2DDQS_MASK    (0x00400000u)
#define CSL_DDR2_MDDR_SDCR_DDR2DDQS_SHIFT   (0x00000016u)
#define CSL_DDR2_MDDR_SDCR_DDR2DDQS_RESETVAL (0x00000000u)
/*----DDR2DDQS Tokens----*/
#define CSL_DDR2_MDDR_SDCR_DDR2DDQS_SDQS    (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_DDR2DDQS_DDQS    (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_DDR2TERM0_MASK   (0x00200000u)
#define CSL_DDR2_MDDR_SDCR_DDR2TERM0_SHIFT  (0x00000015u)
#define CSL_DDR2_MDDR_SDCR_DDR2TERM0_RESETVAL (0x00000000u)
/*----DDR2TERM0 Tokens----*/
/* Tokens shown below should be used in conjunction with tokens for DDR2TERM1 to
 * generate the required temination resistor settings.                          
 * For example: 
 * For disable termination the required value is 00 (binary), which would
 * require DDR2TERM0 to be 0 and DDR2TERM1 to be 0. This could be generated as
 * shown below:
 * ((CSL_DDR2_MDDR_SDCR_DDR2TERM0_CLEAR | CSL_DDR2_MDDR_SDCR_DDR2TERM0_SHIFT) |
 *  (CSL_DDR2_MDDR_SDCR_DDR2TERM1_CLEAR | CSL_DDR2_MDDR_SDCR_DDR2TERM1_SHIFT))
 */
#define CSL_DDR2_MDDR_SDCR_DDR2TERM0_SET     (0x00000001u)
#define CSL_DDR2_MDDR_SDCR_DDR2TERM0_CLEAR   (0x00000000u)

#define CSL_DDR2_MDDR_SDCR_DDR2EN_MASK      (0x00100000u)
#define CSL_DDR2_MDDR_SDCR_DDR2EN_SHIFT     (0x00000014u)
#define CSL_DDR2_MDDR_SDCR_DDR2EN_RESETVAL  (0x00000001u)
/*----DDR2EN Tokens----*/
#define CSL_DDR2_MDDR_SDCR_DDR2EN_DDR2_DIS  (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_DDR2EN_DDR2_EN   (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_DDRDLL_DIS_MASK  (0x00080000u)
#define CSL_DDR2_MDDR_SDCR_DDRDLL_DIS_SHIFT (0x00000013u)
#define CSL_DDR2_MDDR_SDCR_DDRDLL_DIS_RESETVAL (0x00000000u)
/*----DDRDLL_DIS Tokens----*/
#define CSL_DDR2_MDDR_SDCR_DDRDLL_DIS_ENABLE_DLL (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_DDRDLL_DIS_DISABLE_DLL (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_DDRDRIVE0_MASK   (0x00040000u)
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE0_SHIFT  (0x00000012u)
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE0_RESETVAL (0x00000000u)

/*----DDRDRIVE0 Tokens----*/
/* Tokens shown below should be used in conjunction with tokens for DDRDRIVE0 to
 * generate the required temination resistor settings.                          
 * For example: 
 * For the case of weak driver streangth for DDR2 or 1/2 driver strength for mDDR
 * setting the required value is 01 (binary), which would require DDRDRIVE0 to 
 * be 1 and DDRDRIVE1 to be 0. This could be generated as shown below:
 * ((CSL_DDR2_MDDR_SDCR_DDRDRIVE0_SET | CSL_DDR2_MDDR_SDCR_DDRDRIVE0_SHIFT) |
 *  (CSL_DDR2_MDDR_SDCR_DDRDRIVE1_CLEAR | CSL_DDR2_MDDR_SDCR_DDRDRIVE1_SHIFT))
 */
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE0_SET     (0x00000001u)
#define CSL_DDR2_MDDR_SDCR_DDRDRIVE0_CLEAR   (0x00000000u)

#define CSL_DDR2_MDDR_SDCR_DDREN_MASK       (0x00020000u)
#define CSL_DDR2_MDDR_SDCR_DDREN_SHIFT      (0x00000011u)
#define CSL_DDR2_MDDR_SDCR_DDREN_RESETVAL   (0x00000001u)
/*----DDREN Tokens----*/
#define CSL_DDR2_MDDR_SDCR_DDREN_DDR_DIS    (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_DDREN_DDR_EN     (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_SDRAMEN_MASK     (0x00010000u)
#define CSL_DDR2_MDDR_SDCR_SDRAMEN_SHIFT    (0x00000010u)
#define CSL_DDR2_MDDR_SDCR_SDRAMEN_RESETVAL (0x00000001u)
/*----SDRAMEN Tokens----*/
#define CSL_DDR2_MDDR_SDCR_SDRAMEN_SDR_DIS  (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_SDRAMEN_SDR_EN   (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_TIMUNLOCK_MASK   (0x00008000u)
#define CSL_DDR2_MDDR_SDCR_TIMUNLOCK_SHIFT  (0x0000000Fu)
#define CSL_DDR2_MDDR_SDCR_TIMUNLOCK_RESETVAL (0x00000000u)
/*----TIMUNLOCK Tokens----*/
#define CSL_DDR2_MDDR_SDCR_TIMUNLOCK_CLEAR  (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_TIMUNLOCK_SET    (0x00000001u)

#define CSL_DDR2_MDDR_SDCR_NM_MASK          (0x00004000u)
#define CSL_DDR2_MDDR_SDCR_NM_SHIFT         (0x0000000Eu)
#define CSL_DDR2_MDDR_SDCR_NM_RESETVAL      (0x00000000u)
/*----NM Tokens----*/
#define CSL_DDR2_MDDR_SDCR_NM_32BIT         (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_NM_16BIT         (0x00000001u)


#define CSL_DDR2_MDDR_SDCR_CL_MASK          (0x00000E00u)
#define CSL_DDR2_MDDR_SDCR_CL_SHIFT         (0x00000009u)
#define CSL_DDR2_MDDR_SDCR_CL_RESETVAL      (0x00000005u)
/*----CL Tokens----*/
#define CSL_DDR2_MDDR_SDCR_CL_TWO           (0x00000002u)
#define CSL_DDR2_MDDR_SDCR_CL_THREE         (0x00000003u)
#define CSL_DDR2_MDDR_SDCR_CL_FOUR          (0x00000004u)
#define CSL_DDR2_MDDR_SDCR_CL_FIVE          (0x00000005u)


#define CSL_DDR2_MDDR_SDCR_IBANK_MASK       (0x00000070u)
#define CSL_DDR2_MDDR_SDCR_IBANK_SHIFT      (0x00000004u)
#define CSL_DDR2_MDDR_SDCR_IBANK_RESETVAL   (0x00000002u)
/*----IBANK Tokens----*/
#define CSL_DDR2_MDDR_SDCR_IBANK_ONE        (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_IBANK_TWO        (0x00000001u)
#define CSL_DDR2_MDDR_SDCR_IBANK_FOUR       (0x00000002u)
#define CSL_DDR2_MDDR_SDCR_IBANK_EIGHT      (0x00000003u)


#define CSL_DDR2_MDDR_SDCR_PAGESIZE_MASK    (0x00000007u)
#define CSL_DDR2_MDDR_SDCR_PAGESIZE_SHIFT   (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_PAGESIZE_RESETVAL (0x00000000u)
/*----PAGESIZE Tokens----*/
#define CSL_DDR2_MDDR_SDCR_PAGESIZE_256WORD (0x00000000u)
#define CSL_DDR2_MDDR_SDCR_PAGESIZE_512WORD (0x00000001u)
#define CSL_DDR2_MDDR_SDCR_PAGESIZE_1024WORD (0x00000002u)
#define CSL_DDR2_MDDR_SDCR_PAGESIZE_2048WORD (0x00000003u)

#define CSL_DDR2_MDDR_SDCR_RESETVAL         (0x08130A20u)

/* SDRCR */

#define CSL_DDR2_MDDR_SDRCR_LPMODEN_MASK    (0x80000000u)
#define CSL_DDR2_MDDR_SDRCR_LPMODEN_SHIFT   (0x0000001Fu)
#define CSL_DDR2_MDDR_SDRCR_LPMODEN_RESETVAL (0x00000000u)
/*----LPMODEN Tokens----*/
#define CSL_DDR2_MDDR_SDRCR_LPMODEN_LPMODE  (0x00000000u)
#define CSL_DDR2_MDDR_SDRCR_LPMODEN_NO_LPMODE (0x00000001u)

#define CSL_DDR2_MDDR_SDRCR_MCLKSTOPEN_MASK (0x40000000u)
#define CSL_DDR2_MDDR_SDRCR_MCLKSTOPEN_SHIFT (0x0000001Eu)
#define CSL_DDR2_MDDR_SDRCR_MCLKSTOPEN_RESETVAL (0x00000000u)
/*----MCLKSTOPEN Tokens----*/
#define CSL_DDR2_MDDR_SDRCR_MCLKSTOPEN_MCLKSTOP_DIS (0x00000000u)
#define CSL_DDR2_MDDR_SDRCR_MCLKSTOPEN_MCLKSTOP_EN (0x00000001u)


#define CSL_DDR2_MDDR_SDRCR_SR_PD_MASK      (0x00800000u)
#define CSL_DDR2_MDDR_SDRCR_SR_PD_SHIFT     (0x00000017u)
#define CSL_DDR2_MDDR_SDRCR_SR_PD_RESETVAL  (0x00000000u)
/*----SR_PD Tokens----*/
#define CSL_DDR2_MDDR_SDRCR_SR_PD_SELF_REFRESH (0x00000000u)
#define CSL_DDR2_MDDR_SDRCR_SR_PD_POWER_DOWN (0x00000001u)


#define CSL_DDR2_MDDR_SDRCR_RR_MASK         (0x0000FFFFu)
#define CSL_DDR2_MDDR_SDRCR_RR_SHIFT        (0x00000000u)
#define CSL_DDR2_MDDR_SDRCR_RR_RESETVAL     (0x00000884u)

#define CSL_DDR2_MDDR_SDRCR_RESETVAL        (0x00000884u)

/* SDTIMR1 */

#define CSL_DDR2_MDDR_SDTIMR1_T_RFC_MASK    (0xFE000000u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RFC_SHIFT   (0x00000019u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RFC_RESETVAL (0x0000000Fu)

#define CSL_DDR2_MDDR_SDTIMR1_T_RP_MASK     (0x01C00000u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RP_SHIFT    (0x00000016u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RP_RESETVAL (0x00000002u)

#define CSL_DDR2_MDDR_SDTIMR1_T_RCD_MASK    (0x00380000u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RCD_SHIFT   (0x00000013u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RCD_RESETVAL (0x00000002u)

#define CSL_DDR2_MDDR_SDTIMR1_T_WR_MASK     (0x00070000u)
#define CSL_DDR2_MDDR_SDTIMR1_T_WR_SHIFT    (0x00000010u)
#define CSL_DDR2_MDDR_SDTIMR1_T_WR_RESETVAL (0x00000002u)

#define CSL_DDR2_MDDR_SDTIMR1_T_RAS_MASK    (0x0000F800u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RAS_SHIFT   (0x0000000Bu)
#define CSL_DDR2_MDDR_SDTIMR1_T_RAS_RESETVAL (0x00000006u)

#define CSL_DDR2_MDDR_SDTIMR1_T_RC_MASK     (0x000007C0u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RC_SHIFT    (0x00000006u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RC_RESETVAL (0x00000009u)

#define CSL_DDR2_MDDR_SDTIMR1_T_RRD_MASK    (0x00000038u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RRD_SHIFT   (0x00000003u)
#define CSL_DDR2_MDDR_SDTIMR1_T_RRD_RESETVAL (0x00000001u)


#define CSL_DDR2_MDDR_SDTIMR1_T_WTR_MASK    (0x00000003u)
#define CSL_DDR2_MDDR_SDTIMR1_T_WTR_SHIFT   (0x00000000u)
#define CSL_DDR2_MDDR_SDTIMR1_T_WTR_RESETVAL (0x00000001u)

#define CSL_DDR2_MDDR_SDTIMR1_RESETVAL      (0x1E923249u)

/* SDTIMR2 */


#define CSL_DDR2_MDDR_SDTIMR2_T_RAS_MAX_MASK (0x78000000u)
#define CSL_DDR2_MDDR_SDTIMR2_T_RAS_MAX_SHIFT (0x0000001Bu)
#define CSL_DDR2_MDDR_SDTIMR2_T_RAS_MAX_RESETVAL (0x00000008u)

#define CSL_DDR2_MDDR_SDTIMR2_T_XP_MASK     (0x06000000u)
#define CSL_DDR2_MDDR_SDTIMR2_T_XP_SHIFT    (0x00000019u)
#define CSL_DDR2_MDDR_SDTIMR2_T_XP_RESETVAL (0x00000002u)


#define CSL_DDR2_MDDR_SDTIMR2_T_XSNR_MASK   (0x007F0000u)
#define CSL_DDR2_MDDR_SDTIMR2_T_XSNR_SHIFT  (0x00000010u)
#define CSL_DDR2_MDDR_SDTIMR2_T_XSNR_RESETVAL (0x00000032u)

#define CSL_DDR2_MDDR_SDTIMR2_T_XSRD_MASK   (0x0000FF00u)
#define CSL_DDR2_MDDR_SDTIMR2_T_XSRD_SHIFT  (0x00000008u)
#define CSL_DDR2_MDDR_SDTIMR2_T_XSRD_RESETVAL (0x000000A7u)

#define CSL_DDR2_MDDR_SDTIMR2_T_RTP_MASK    (0x000000E0u)
#define CSL_DDR2_MDDR_SDTIMR2_T_RTP_SHIFT   (0x00000005u)
#define CSL_DDR2_MDDR_SDTIMR2_T_RTP_RESETVAL (0x00000001u)

#define CSL_DDR2_MDDR_SDTIMR2_T_CKE_MASK    (0x0000001Fu)
#define CSL_DDR2_MDDR_SDTIMR2_T_CKE_SHIFT   (0x00000000u)
#define CSL_DDR2_MDDR_SDTIMR2_T_CKE_RESETVAL (0x00000002u)

#define CSL_DDR2_MDDR_SDTIMR2_RESETVAL      (0x4532A722u)

/* SDCR2 */


#define CSL_DDR2_MDDR_SDCR2_PASR_MASK       (0x00070000u)
#define CSL_DDR2_MDDR_SDCR2_PASR_SHIFT      (0x00000010u)
#define CSL_DDR2_MDDR_SDCR2_PASR_RESETVAL   (0x00000000u)
/*----PASR Tokens----*/
#define CSL_DDR2_MDDR_SDCR2_PASR_4BNK       (0x00000000u)
#define CSL_DDR2_MDDR_SDCR2_PASR_2BNK       (0x00000001u)
#define CSL_DDR2_MDDR_SDCR2_PASR_1BNK       (0x00000002u)
#define CSL_DDR2_MDDR_SDCR2_PASR_HALFBNK    (0x00000005u)
#define CSL_DDR2_MDDR_SDCR2_PASR_QRTRBNK    (0x00000006u)


#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_MASK    (0x00000007u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_SHIFT   (0x00000000u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_RESETVAL (0x00000000u)
/*----ROWSIZE Tokens----*/
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_9ROW    (0x00000000u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_10ROW   (0x00000001u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_11ROW   (0x00000002u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_12ROW   (0x00000003u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_13ROW   (0x00000004u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_14ROW   (0x00000005u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_15ROW   (0x00000006u)
#define CSL_DDR2_MDDR_SDCR2_ROWSIZE_16ROW   (0x00000007u)

#define CSL_DDR2_MDDR_SDCR2_RESETVAL        (0x00000000u)

/* PBBPR */


#define CSL_DDR2_MDDR_PBBPR_PR_OLD_COUNT_MASK (0x000000FFu)
#define CSL_DDR2_MDDR_PBBPR_PR_OLD_COUNT_SHIFT (0x00000000u)
#define CSL_DDR2_MDDR_PBBPR_PR_OLD_COUNT_RESETVAL (0x000000FFu)

#define CSL_DDR2_MDDR_PBBPR_RESETVAL        (0x000000FFu)

/* PC1 */

#define CSL_DDR2_MDDR_PC1_COUNTER1_MASK     (0xFFFFFFFFu)
#define CSL_DDR2_MDDR_PC1_COUNTER1_SHIFT    (0x00000000u)
#define CSL_DDR2_MDDR_PC1_COUNTER1_RESETVAL (0x00000000u)

#define CSL_DDR2_MDDR_PC1_RESETVAL          (0x00000000u)

/* PC2 */

#define CSL_DDR2_MDDR_PC2_COUNTER2_MASK     (0xFFFFFFFFu)
#define CSL_DDR2_MDDR_PC2_COUNTER2_SHIFT    (0x00000000u)
#define CSL_DDR2_MDDR_PC2_COUNTER2_RESETVAL (0x00000000u)

#define CSL_DDR2_MDDR_PC2_RESETVAL          (0x00000000u)

/* PCC */

#define CSL_DDR2_MDDR_PCC_CNTR2_MSTID_EN_MASK (0x80000000u)
#define CSL_DDR2_MDDR_PCC_CNTR2_MSTID_EN_SHIFT (0x0000001Fu)
#define CSL_DDR2_MDDR_PCC_CNTR2_MSTID_EN_RESETVAL (0x00000000u)
/*----CNTR2_MSTID_EN Tokens----*/
#define CSL_DDR2_MDDR_PCC_CNTR2_MSTID_EN_DISABLE (0x00000000u)
#define CSL_DDR2_MDDR_PCC_CNTR2_MSTID_EN_ENABLE (0x00000001u)

#define CSL_DDR2_MDDR_PCC_CNTR2_REGION_EN_MASK (0x40000000u)
#define CSL_DDR2_MDDR_PCC_CNTR2_REGION_EN_SHIFT (0x0000001Eu)
#define CSL_DDR2_MDDR_PCC_CNTR2_REGION_EN_RESETVAL (0x00000000u)
/*----CNTR2_REGION_EN Tokens----*/
#define CSL_DDR2_MDDR_PCC_CNTR2_REGION_EN_DISABLE (0x00000000u)
#define CSL_DDR2_MDDR_PCC_CNTR2_REGION_EN_ENABLE (0x00000001u)


#define CSL_DDR2_MDDR_PCC_CNTR2_CFG_MASK    (0x000F0000u)
#define CSL_DDR2_MDDR_PCC_CNTR2_CFG_SHIFT   (0x00000010u)
#define CSL_DDR2_MDDR_PCC_CNTR2_CFG_RESETVAL (0x00000001u)

#define CSL_DDR2_MDDR_PCC_CNTR1_MSTID_EN_MASK (0x00008000u)
#define CSL_DDR2_MDDR_PCC_CNTR1_MSTID_EN_SHIFT (0x0000000Fu)
#define CSL_DDR2_MDDR_PCC_CNTR1_MSTID_EN_RESETVAL (0x00000000u)
/*----CNTR1_MSTID_EN Tokens----*/
#define CSL_DDR2_MDDR_PCC_CNTR1_MSTID_EN_DISABLE (0x00000000u)
#define CSL_DDR2_MDDR_PCC_CNTR1_MSTID_EN_ENABLE (0x00000001u)

#define CSL_DDR2_MDDR_PCC_CNTR1_REGION_EN_MASK (0x00004000u)
#define CSL_DDR2_MDDR_PCC_CNTR1_REGION_EN_SHIFT (0x0000000Eu)
#define CSL_DDR2_MDDR_PCC_CNTR1_REGION_EN_RESETVAL (0x00000000u)
/*----CNTR1_REGION_EN Tokens----*/
#define CSL_DDR2_MDDR_PCC_CNTR1_REGION_EN_DISABLE (0x00000000u)
#define CSL_DDR2_MDDR_PCC_CNTR1_REGION_EN_ENABLE (0x00000001u)


#define CSL_DDR2_MDDR_PCC_CNTR1_CFG_MASK    (0x0000000Fu)
#define CSL_DDR2_MDDR_PCC_CNTR1_CFG_SHIFT   (0x00000000u)
#define CSL_DDR2_MDDR_PCC_CNTR1_CFG_RESETVAL (0x00000000u)

#define CSL_DDR2_MDDR_PCC_RESETVAL          (0x00010000u)

/* PCMRS */

#define CSL_DDR2_MDDR_PCMRS_MST_ID2_MASK    (0xFF000000u)
#define CSL_DDR2_MDDR_PCMRS_MST_ID2_SHIFT   (0x00000018u)
#define CSL_DDR2_MDDR_PCMRS_MST_ID2_RESETVAL (0x00000000u)


#define CSL_DDR2_MDDR_PCMRS_REGION_SEL2_MASK (0x000F0000u)
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL2_SHIFT (0x00000010u)
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL2_RESETVAL (0x00000000u)
/*----REGION_SEL2 Tokens----*/
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL2_DDRACCESS (0x00000000u)
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL2_MMRACCESS (0x00000007u)

#define CSL_DDR2_MDDR_PCMRS_MST_ID1_MASK    (0x0000FF00u)
#define CSL_DDR2_MDDR_PCMRS_MST_ID1_SHIFT   (0x00000008u)
#define CSL_DDR2_MDDR_PCMRS_MST_ID1_RESETVAL (0x00000000u)


#define CSL_DDR2_MDDR_PCMRS_REGION_SEL1_MASK (0x0000000Fu)
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL1_SHIFT (0x00000000u)
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL1_RESETVAL (0x00000000u)
/*----REGION_SEL1 Tokens----*/
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL1_DDRACCESS (0x00000000u)
#define CSL_DDR2_MDDR_PCMRS_REGION_SEL1_MMRACCESS (0x00000007u)

#define CSL_DDR2_MDDR_PCMRS_RESETVAL        (0x00000000u)

/* PCT */

#define CSL_DDR2_MDDR_PCT_TOTAL_TIME_MASK   (0xFFFFFFFFu)
#define CSL_DDR2_MDDR_PCT_TOTAL_TIME_SHIFT  (0x00000000u)
#define CSL_DDR2_MDDR_PCT_TOTAL_TIME_RESETVAL (0x00000000u)

#define CSL_DDR2_MDDR_PCT_RESETVAL          (0x00000000u)


/* IRR */


#define CSL_DDR2_MDDR_IRR_LT_MASK           (0x00000004u)
#define CSL_DDR2_MDDR_IRR_LT_SHIFT          (0x00000002u)
#define CSL_DDR2_MDDR_IRR_LT_RESETVAL       (0x00000000u)
/*----LT Tokens----*/
#define CSL_DDR2_MDDR_IRR_LT_CLEAR          (0x00000001u)


#define CSL_DDR2_MDDR_IRR_RESETVAL          (0x00000000u)

/* IMR */


#define CSL_DDR2_MDDR_IMR_LTM_MASK          (0x00000004u)
#define CSL_DDR2_MDDR_IMR_LTM_SHIFT         (0x00000002u)
#define CSL_DDR2_MDDR_IMR_LTM_RESETVAL      (0x00000000u)
/*----LTM Tokens----*/
#define CSL_DDR2_MDDR_IMR_LTM_CLEAR         (0x00000001u)


#define CSL_DDR2_MDDR_IMR_RESETVAL          (0x00000000u)

/* IMSR */


#define CSL_DDR2_MDDR_IMSR_LTMSET_MASK      (0x00000004u)
#define CSL_DDR2_MDDR_IMSR_LTMSET_SHIFT     (0x00000002u)
#define CSL_DDR2_MDDR_IMSR_LTMSET_RESETVAL  (0x00000000u)
/*----LTMSET Tokens----*/
#define CSL_DDR2_MDDR_IMSR_LTMSET_SET       (0x00000001u)


#define CSL_DDR2_MDDR_IMSR_RESETVAL         (0x00000000u)

/* IMCR */


#define CSL_DDR2_MDDR_IMCR_LTMCLR_MASK      (0x00000004u)
#define CSL_DDR2_MDDR_IMCR_LTMCLR_SHIFT     (0x00000002u)
#define CSL_DDR2_MDDR_IMCR_LTMCLR_RESETVAL  (0x00000000u)
/*----LTMCLR Tokens----*/
#define CSL_DDR2_MDDR_IMCR_LTMCLR_CLEAR     (0x00000001u)


#define CSL_DDR2_MDDR_IMCR_RESETVAL         (0x00000000u)

/* DRPYC1R */


#define CSL_DDR2_MDDR_DRPYC1R_LBCKSEL_MASK  (0x00800000u)
#define CSL_DDR2_MDDR_DRPYC1R_LBCKSEL_SHIFT (0x00000017u)
#define CSL_DDR2_MDDR_DRPYC1R_LBCKSEL_RESETVAL (0x00000000u)
/*----LBCKSEL Tokens----*/
#define CSL_DDR2_MDDR_DRPYC1R_LBCKSEL_CK0   (0x00000000u)
#define CSL_DDR2_MDDR_DRPYC1R_LBCKSEL_CK1   (0x00000001u)


#define CSL_DDR2_MDDR_DRPYC1R_VTP_DYN_UPDT_MASK (0x00008000u)
#define CSL_DDR2_MDDR_DRPYC1R_VTP_DYN_UPDT_SHIFT (0x0000000Fu)
#define CSL_DDR2_MDDR_DRPYC1R_VTP_DYN_UPDT_RESETVAL (0x00000000u)
/*----VTP _DYN_UPDT Tokens----*/
#define CSL_DDR2_MDDR_DRPYC1R_VTP_DYN_UPDT_STATIC (0x00000000u)
#define CSL_DDR2_MDDR_DRPYC1R_VTP_DYN_UPDT_DYNAMIC (0x00000001u)

#define CSL_DDR2_MDDR_DRPYC1R_DLLMODE_MASK  (0x00007000u)
#define CSL_DDR2_MDDR_DRPYC1R_DLLMODE_SHIFT (0x0000000Cu)
#define CSL_DDR2_MDDR_DRPYC1R_DLLMODE_RESETVAL (0x00000000u)


#define CSL_DDR2_MDDR_DRPYC1R_EXT_STRBEN_MASK (0x00000080u)
#define CSL_DDR2_MDDR_DRPYC1R_EXT_STRBEN_SHIFT (0x00000007u)
#define CSL_DDR2_MDDR_DRPYC1R_EXT_STRBEN_RESETVAL (0x00000000u)
/*----EXT_STRBEN Tokens----*/
#define CSL_DDR2_MDDR_DRPYC1R_EXT_STRBEN_INT_STRB (0x00000000u)
#define CSL_DDR2_MDDR_DRPYC1R_EXT_STRBEN_EXT_STRB (0x00000001u)

#define CSL_DDR2_MDDR_DRPYC1R_PWRDNEN_MASK  (0x00000040u)
#define CSL_DDR2_MDDR_DRPYC1R_PWRDNEN_SHIFT (0x00000006u)
#define CSL_DDR2_MDDR_DRPYC1R_PWRDNEN_RESETVAL (0x00000001u)
/*----PWRDNEN Tokens----*/
#define CSL_DDR2_MDDR_DRPYC1R_PWRDNEN_NO_PWRDN (0x00000000u)
#define CSL_DDR2_MDDR_DRPYC1R_PWRDNEN_PWREN (0x00000001u)


#define CSL_DDR2_MDDR_DRPYC1R_RL_MASK       (0x00000007u)
#define CSL_DDR2_MDDR_DRPYC1R_RL_SHIFT      (0x00000000u)
#define CSL_DDR2_MDDR_DRPYC1R_RL_RESETVAL   (0x00000007u)

#define CSL_DDR2_MDDR_DRPYC1R_RESETVAL      (0x00000047u)

#ifdef __cplusplus
}
#endif

#endif
