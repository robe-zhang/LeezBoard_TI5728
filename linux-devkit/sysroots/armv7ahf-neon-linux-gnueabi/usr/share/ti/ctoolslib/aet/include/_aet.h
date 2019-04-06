/*
 * _aet.h
 *
 * AET Library public API Definitions 
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/ 
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
 *  =================================_aet.h====================================
 *  Revision Information
 *   Changed: $LastChangedDate: 2013-01-18 15:47:09 -0600 (Fri, 18 Jan 2013) $
 *   Revision: $LastChangedRevision: 10598 $
 *   Last Update By: $Author: KarthikRamanaSankar $ 
 *  ===========================================================================
 */

/*
 * Overview of Preprocessor Definitions
 *
 * Preprocessor Symbols generated based on compile switches.  These are taken
 * directly from the C6000 C Compiler Users Guide. (SPRU187)
 *
 * _TMS320C6X Always defined
 * _TMS320C6200 Defined if target is C6200
 * _TMS320C6400 Defined if target is C6400, C6400+, C6740, or C6600
 * _TMS320C6400_PLUS Defined if target is C6400+, C6740, or C6600
 * _TMS320C6600 Defined if target is C6600
 * _TMS320C6700 Defined if target is C6700, C6700+, C6740, or C6600
 * _TMS320C6700_PLUS Defined if target is C6700+, C6740, or C6600
 * _TMS320C6740 Defined if target is C6740 or C6600
 * __TMS320C6X__ Always defined for use as alternate name for _TMS320C6x
 *
 */

#ifndef __AET_H
#define __AET_H

/*
 #include directives 
 */
#include <stdio.h>
#include <aet.h>




 #ifdef __cplusplus
 extern "C" {
 #endif

/* 
 #define directives and enums
 */

#ifdef _DEBUG
#define _AET_IAR_PRINTF(x, y) printf("Reg: %s, value: 0x%x\n", x, y);
#define _AET_PRINTF(x) printf(x);
#define _AET_PRINTF_1(x, y) printf(x, y);
#define _AET_BANNER(x,y) printf("---%s Job Program %s---\n",x,y);
#define _AET_AEGSEL(x,y) printf("Reg: AEGSEL#%d, value: 0x%08x\n",x,y);
#else
#define _AET_IAR_PRINTF(x, y)
#define _AET_PRINTF(x)
#define _AET_PRINTF_1(x, y)
#define _AET_BANNER(x,y)
#define _AET_AEGSEL(x,y)
#endif

 
/* 
 *  First we define the special word for each platform: 
 *  On 55x we add a NOP to guard against small possibility that 
 *  long instruction pipeline causes debugger to stop at next C src line
 *  instead of currently executing C src statement. We also ensure this 
 *  works on both 55x mnemonic (default) and algebraic 55x assembler.
 *  Note that asm statement is a single execution context to maintain
 *  pre-processor consistency.
 */
 
#if   defined( _54_ ) 
    #define _AET_STOPOPCODE asm( "  ESTOP" )
#elif defined( _55_ )
    #define _AET_STOPOPCODE asm(" ;\n .if (.MNEMONIC)\n ESTOP_1\n .else\n ESTOP_1()\n .endif\n NOP")
#elif defined ( _28_ )
    #define _AET_STOPOPCODE asm(" ESTOP0")
#elif defined( _TMS320C6400_ )
	#if defined(_TMS320C6400_PLUS_) /* 64x+ And 66x Cores */
    	#define _AET_STOPOPCODE asm( "    SWBP 0")
	#else	/* 64x Core */
    	#define _AET_STOPOPCODE asm( "    NOP\n    .word 0x10000000" )
	#endif
#else
    /* If it is none of the above */
    #define _AET_STOPOPCODE
#endif
 
 
/* _AET_ASSERTS is intended to be set to 1 in debug builds */
#ifdef _AET_ASSERTS
#define _AET_assert(c) if (!(c)) { \
        for (;;) _AET_STOPOPCODE; }            /**< Assert a logical condition to be TRUE. */
 
#define _AET_require _AET_assert  /**< Assert a precondition to be TRUE. */
#define _AET_ensure  _AET_assert  /**< Assert a postcondition to be TRUE. */
 
#else
 
#define _AET_assert(c)   /**< Assert a logical condition to be TRUE. */
#define _AET_require(c)  /**< Assert a precondition to be TRUE. */
#define _AET_ensure(c)   /**< Assert a postcondition to be TRUE. */
 
#endif

#define _AET_DISABLE_TBS() _AET_iregWrite(AET_indexof(CSL_Aet_iarRegs, TB_ENA), 0x0);

/* Define the number of each resource supported on the target */
#define AET_NUM_AEG		    	4
#define AET_NUM_COUNTER			2
#define AET_NUM_TB_7WIDE		2
#define AET_NUM_TB_3WIDE		6
#define AET_NUM_TB_1WIDE		6
#define AET_NUM_DCMP			2
#define AET_NUM_AEGMUXLINE		8
#define AET_NUM_2_STATEMACHINE 	2

#define AET_TB_ORS_LENGTH		16
#define AET_TB_LUT_LENGTH		16

#ifdef _TMS320C6400_PLUS
#define AET_NUM_ACMP		6
#else
#define AET_NUM_ACMP		4
#endif
#define AET_NUM_DATA_ACMP 	4

#ifdef _TMS320C6400_PLUS
#define AET_ACMP_ORDER (uint8_t)5,(uint8_t)4,(uint8_t)3,(uint8_t)2,(uint8_t)1,(uint8_t)0
#else
#define AET_ACMP_ORDER (uint8_t)3,(uint8_t)2,(uint8_t)1,(uint8_t)0
#endif


/* Trigger Builder Enable Locations */
#define _AET_TB_ENA_1_WIDE_START 0
#define _AET_TB_ENA_1_WIDE_END 23
#define _AET_TB_ENA_3_WIDE_START 26
#define _AET_TB_ENA_3_WIDE_END 31
#define _AET_TB_ENA_7_WIDE_START 24
#define _AET_TB_ENA_7_WIDE_END 25
#define _AET_MAX_CONCURRENT_JOBS 16

/* Trigger Builder Input Lines */
/* 
 These define the bits that need to be set
 in the TB_ORS register in order to connect
 the signal into the OR input
 */
#define _AET_TB_INPUT_COMPARATOR_0 0
#define _AET_TB_INPUT_COMPARATOR_1 1
#define _AET_TB_INPUT_COMPARATOR_2 2
#define _AET_TB_INPUT_COMPARATOR_3 3
#define _AET_TB_INPUT_COMPARATOR_4 4
#define _AET_TB_INPUT_COMPARATOR_5 5
#define _AET_TB_INPUT_HWBP_0_NI 6
#define _AET_TB_INPUT_HWBP_1_NI 7
#define _AET_TB_INPUT_HWBP_2_NI 8
#define _AET_TB_INPUT_HWBP_3_NI 9
#define _AET_TB_INPUT_SAE_0 10
#define _AET_TB_INPUT_OAEG_1 11
#define _AET_TB_INPUT_OAEG_2 12
#define _AET_TB_INPUT_OAEG_3 13
#define _AET_TB_INPUT_OAEG_4 14
#define _AET_TB_INPUT_RESERVED 15

/* Trigger Builder Lookup Table Masks */
/* D  C  B  A 
   -  -  -  -
   0  0  0  0 
   0  0  0  1
   0  0  1  0
   0  0  1  1
   0  1  0  0
   0  1  0  1
   0  1  1  0
   0  1  1  1 
   1  0  0  0 
   1  0  0  1
   1  0  1  0
   1  0  1  1
   1  1  0  0
   1  1  0  1
   1  1  1  0
   1  1  1  1
*/
									
#define _AET_TB_EVT_NONE 0x0000
#define _AET_TB_EVT_A 0xAAAA        
#define _AET_TB_EVT_B 0xCCCC
#define _AET_TB_EVT_C 0xF0F0
#define _AET_TB_EVT_D 0xFF00

#define _AET_STATE_MACHINE_QUAL_MASK _AET_TB_EVT_D
#define _AET_COUNTER_ZERO_QUAL_MASK  _AET_TB_EVT_C

#ifdef _DEBUG
#define _AET_DEBUG_TABLE \
	{"DRC_0_CNTL"},			/* 0x0 */\
	{"DRC_0_AREF"},\
	{"DRC_0_DCQ_DREFL"},\
	{"DRC_0_DCQ_MREFL"},\
	{"DRC_0_DCQ_DREFH"},\
	{"DRC_0_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_1_CNTL"},			/* 0x8 */\
	{"DRC_1_AREF"},\
	{"DRC_1_DCQ_DREFL"}, \
	{"DRC_1_DCQ_MREFL"},\
	{"DRC_1_DCQ_DREFH"},\
	{"DRC_1_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_2_CNTL"},			/* 0x10 */\
	{"DRC_2_AREF"},\
	{"DRC_2_DCQ_DREFL"},\
	{"DRC_2_DCQ_MREFL"},\
	{"DRC_2_DCQ_DREFH"},\
	{"DRC_2_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_3_CNTL"},			/* 0x18 */\
	{"DRC_3_AREF"},\
	{"DRC_3_DCQ_DREFL"},\
	{"DRC_3_DCQ_MREFL"},\
	{"DRC_3_DCQ_DREFH"},\
	{"DRC_3_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_4_CNTL"},			/* 0x20 */\
	{"DRC_4_AREF"},\
	{"DRC_4_DCQ_DREFL"},\
	{"DRC_4_DCQ_MREFL"},\
	{"DRC_4_DCQ_DREFH"},\
	{"DRC_4_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_5_CNTL"},			/* 0x28 */\
	{"DRC_5_AREF"},\
	{"DRC_5_DCQ_DREFL"},\
	{"DRC_5_DCQ_MREFL"},\
	{"DRC_5_DCQ_DREFH"},\
	{"DRC_5_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_6_CNTL"},			/* 0x30 */\
	{"DRC_6_AREF"},\
	{"DRC_6_DCQ_DREFL"},\
	{"DRC_6_DCQ_MREFL"},\
	{"DRC_6_DCQ_DREFH"},\
	{"DRC_6_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_7_CNTL"},			/* 0x38 */\
	{"DRC_7_AREF"},\
	{"DRC_7_DCQ_DREFL"},\
	{"DRC_7_DCQ_MREFL"},\
	{"DRC_7_DCQ_DREFH"},\
	{"DRC_7_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_8_CNTL"},			/* 0x40 */\
	{"DRC_8_AREF"},\
	{"DRC_8_DCQ_DREFL"},\
	{"DRC_8_DCQ_MREFL"},\
	{"DRC_8_DCQ_DREFH"},\
	{"DRC_8_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_9_CNTL"},			/* 0x48 */\
	{"DRC_9_AREF"},\
	{"DRC_9_DCQ_DREFL"},\
	{"DRC_9_DCQ_MREFL"},\
	{"DRC_9_DCQ_DREFH"},\
	{"DRC_9_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_A_CNTL"},			/* 0x50 */\
	{"DRC_A_AREF"},\
	{"DRC_A_DCQ_DREFL"},\
	{"DRC_A_DCQ_MREFL"},\
	{"DRC_A_DCQ_DREFH"},\
	{"DRC_A_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_B_CNTL"},			/* 0x58 */\
	{"DRC_B_AREF"},\
	{"DRC_B_DCQ_DREFL"},\
	{"DRC_B_DCQ_MREFL"},\
	{"DRC_B_DCQ_DREFH"},\
	{"DRC_B_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_C_CNTL"},			/* 0x60 */\
	{"DRC_C_AREF"},\
	{"DRC_C_DCQ_DREFL"},\
	{"DRC_C_DCQ_MREFL"},\
	{"DRC_C_DCQ_DREFH"},\
	{"DRC_C_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_D_CNTL"},			/* 0x68 */\
	{"DRC_D_AREF"},\
	{"DRC_D_DCQ_DREFL"},\
	{"DRC_D_DCQ_MREFL"},\
	{"DRC_D_DCQ_DREFH"},\
	{"DRC_D_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_E_CNTL"},			/* 0x70 */\
	{"DRC_E_AREF"},\
	{"DRC_E_DCQ_DREFL"},\
	{"DRC_E_DCQ_MREFL"},\
	{"DRC_E_DCQ_DREFH"},\
	{"DRC_E_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"DRC_F_CNTL"},			/* 0x78 */\
	{"DRC_F_AREF"},\
	{"DRC_F_DCQ_DREFL"},\
	{"DRC_F_DCQ_MREFL"},\
	{"DRC_F_DCQ_DREFH"},\
	{"DRC_F_DCQ_MREFH"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"PIN_OBSV"},			/* 0x80 */\
	{"PIN_MGR0"},\
	{"PIN_MGR1"},\
	{"RESERVED"},\
	{"TB_ENA"},\
	{"TB_DM"},\
	{"FUNC_CNTL"},\
	{"CIS_BUS_SEL"},\
	{"AUX_SAE_CNTL"},		/* 0x88 */\
	{"AUX_SAE_ENA"},\
	{"AUX_EVT_1_CNTL"},\
	{"AUX_1_ENA"},\
	{"AUX_EVT_2_CNTL"},\
	{"AUX_2_ENA"},\
	{"AUX_EVT_3_CNTL"},\
	{"AUX_3_ENA"},\
	{"TR_CNTL"},			/* 0x90 */\
	{"TR_COUNTER"},\
	{"RSVD_TF_SETUP"},\
	{"RSVD_TF_SETUP"},\
	{"TF_CNTL"},\
	{"RSVD_LO_SETUP"},\
	{"RSVD_LO_SETUP"},\
	{"RSVD_LO_SETUP"},\
	{"RESERVED"},			/* 0x98 */\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},			/* 0xA0 */\
	{"RESERVED"},\
	{"RESERVED"},\
	{"RESERVED"},\
	{"TB_3W_2_ORS"},\
	{"TB_3W_2_CNTL"},\
	{"TB_3W_2_CEXP"},\
	{"TB_3W_3_ORS"},\
	{"TB_3W_3_CNTL"},		/* 0xA8 */\
	{"TB_3W_3_CEXP"},\
	{"TB_3W_4_ORS"},\
	{"TB_3W_4_CNTL"},\
	{"TB_3W_4_CEXP"},\
	{"TB_3W_5_ORS"},\
	{"TB_3W_5_CNTL"},\
	{"TB_3W_5_CEXP"},\
	{"CNT_0_RLD"},			/* 0xB0 */\
	{"CNT_1_RLD"},\
	{"CNT_2_RLD"},\
	{"CNT_3_RLD"},\
	{"TB_SEXT_0"},\
	{"TB_SEXT_1"},\
	{"TB_SEXT_2"},\
	{"TB_SEXT_3"},\
	{"TB_SEXT_4"},			/* 0xB8 */\
	{"TB_SEXT_5"},\
	{"TB_SEXT_6"},\
	{"TB_SEXT_7"},\
	{"TB_SEXT_8"},\
	{"TB_SEXT_9"},\
	{"TB_SEXT_10"},\
	{"TB_SEXT_11"},\
	{"TB_7W_0_ORS"},		/* 0xC0 */\
	{"TB_7W_0_CNTL_1"},\
	{"TB_7W_0_CEXT_2"},\
	{"TB_7W_0_CEXT_3"},\
	{"TB_7W_0_CEXT_4"},\
	{"TB_7W_0_CEXT_5"},\
	{"TB_7W_0_CEXT_6"},\
	{"TB_7W_0_CEXT_7"},\
	{"TB_7W_1_ORS"},		/* 0xC8 */\
	{"TB_7W_1_CNTL_1"},\
	{"TB_7W_1_CEXT_2"},\
	{"TB_7W_1_CEXT_3"},\
	{"TB_7W_1_CEXT_4"},\
	{"TB_7W_1_CEXT_5"},\
	{"TB_7W_1_CEXT_6"},\
	{"TB_7W_1_CEXT_7"},\
	{"TB_3W_0_ORS"},		/* 0xD0 */\
	{"TB_3W_0_CNTL_1"},\
	{"TB_3W_0_CEXT_2"},\
	{"TB_3W_0_CEXT_3"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"TB_3W_1_ORS"},		/* 0xD8 */\
	{"TB_3W_1_CNTL_1"},\
	{"TB_3W_1_CEXT_2"},\
	{"TB_3W_1_CEXT_3"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0xE0 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0xE8 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0xF0 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0xF8 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x100 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x108 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x110 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x118 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x120 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x128 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x130 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},	/* 0x138 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"TB_1W_0_ORS"},		/* 0x140 */\
	{"TB_1W_0_CNTL"},\
	{"TB_1W_1_ORS"},\
	{"TB_1W_1_CNTL"},\
	{"TB_1W_2_ORS"},\
	{"TB_1W_2_CNTL"},\
	{"TB_1W_3_ORS"},\
	{"TB_1W_3_CNTL"},\
	{"TB_1W_4_ORS"},		/* 0x148 */\
	{"TB_1W_4_CNTL"},\
	{"TB_1W_5_ORS"},\
	{"TB_1W_5_CNTL"},\
	{"TB_0_6_ORS"},\
	{"TB_0_6_CNTL"},\
	{"TB_0_7_ORS"},\
	{"TB_0_7_CNTL"},\
	{"TB_0_8_ORS"},			/* 0x150 */\
	{"TB_0_8_CNTL"},\
	{"TB_0_9_ORS"},\
	{"TB_0_9_CNTL"},\
	{"TB_0_10_ORS"},\
	{"TB_0_10_CNTL"},\
	{"TB_0_11_ORS"},\
	{"TB_0_11_CNTL"},\
	{"TB_0_12_ORS"},		/* 0x158 */\
	{"TB_0_12_CNTL"},\
	{"TB_0_13_ORS"},\
	{"TB_0_13_CNTL"},\
	{"TB_0_14_ORS"},\
	{"TB_0_14_CNTL"},\
	{"TB_0_15_ORS"},\
	{"TB_0_15_CNTL"},\
	{"TB_0_16_ORS"},		/* 0x160 */\
	{"TB_0_16_CNTL"},\
	{"TB_0_17_ORS"},\
	{"TB_0_17_CNTL"},\
	{"TB_0_18_ORS"},\
	{"TB_0_18_CNTL"},\
	{"TB_0_19_ORS"},\
	{"TB_0_19_CNTL"},\
	{"TB_0_20_ORS"},		/* 0x168 */\
	{"TB_0_20_CNTL"},\
	{"TB_0_21_ORS"},\
	{"TB_0_21_CNTL"},\
	{"TB_0_22_ORS"},\
	{"TB_0_22_CNTL"},\
	{"TB_0_23_ORS"},\
	{"TB_0_23_CNTL"},\
	{"TB_1_0_ORS"},			/* 0x170 */\
	{"TB_1_0_CNTL"},\
	{"TB_1_1_ORS"},\
	{"TB_1_1_CNTL"},\
	{"TB_1_2_ORS"},\
	{"TB_1_2_CNTL"},\
	{"TB_1_3_ORS"},\
	{"TB_1_3_CNTL"},\
	{"TB_1_4_ORS"},			/* 0x178 */\
	{"TB_1_4_CNTL"},\
	{"TB_1_5_ORS"},\
	{"TB_1_5_CNTL"},\
	{"TB_1_6_ORS"},\
	{"TB_1_6_CNTL"},\
	{"TB_1_7_ORS"},\
	{"TB_1_7_CNTL"},\
	{"TB_1_8_ORS"},			/* 0x180 */\
	{"TB_1_8_CNTL"},\
	{"TB_1_9_ORS"},\
	{"TB_1_9_CNTL"},\
	{"TB_1_10_ORS"},\
	{"TB_1_10_CNTL"},\
	{"TB_1_11_ORS"},\
	{"TB_1_11_CNTL"},\
	{"TB_1_12_ORS"},			/* 0x188 */\
	{"TB_1_12_CNTL"},\
	{"TB_1_13_ORS"},\
	{"TB_1_13_CNTL"},\
	{"TB_1_14_ORS"},\
	{"TB_1_14_CNTL"},\
	{"TB_1_15_ORS"},\
	{"TB_1_15_CNTL"},\
	{"TB_1_16_ORS"},			/* 0x190 */\
	{"TB_1_16_CNTL"},\
	{"TB_1_17_ORS"},\
	{"TB_1_17_CNTL"},\
	{"TB_1_18_ORS"},\
	{"TB_1_18_CNTL"},\
	{"TB_1_19_ORS"},\
	{"TB_1_19_CNTL"},\
	{"TB_1_20_ORS"},			/* 0x198 */\
	{"TB_1_20_CNTL"},\
	{"TB_1_21_ORS"},\
	{"TB_1_21_CNTL"},\
	{"TB_1_22_ORS"},\
	{"TB_1_22_CNTL"},\
	{"TB_1_23_ORS"},\
	{"TB_1_23_CNTL"},\
	{"TB_2_0_ORS"},				/* 0x1A0 */\
	{"TB_2_0_CNTL"},\
	{"TB_2_1_ORS"},\
	{"TB_2_1_CNTL"},\
	{"TB_2_2_ORS"},\
	{"TB_2_2_CNTL"},\
	{"TB_2_3_ORS"},\
	{"TB_2_3_CNTL"},\
	{"TB_2_4_ORS"},				/* 0x1A8 */\
	{"TB_2_4_CNTL"},\
	{"TB_2_5_ORS"},\
	{"TB_2_5_CNTL"},\
	{"TB_2_6_ORS"},\
	{"TB_2_6_CNTL"},\
	{"TB_2_7_ORS"},\
	{"TB_2_7_CNTL"},\
	{"TB_2_8_ORS"},				/* 0x1B0 */\
	{"TB_2_8_CNTL"},\
	{"TB_2_9_ORS"},\
	{"TB_2_9_CNTL"},\
	{"TB_2_10_ORS"},\
	{"TB_2_10_CNTL"},\
	{"TB_2_11_ORS"},\
	{"TB_2_11_CNTL"},\
	{"TB_2_12_ORS"},			/* 0x1B8 */\
	{"TB_2_12_CNTL"},\
	{"TB_2_13_ORS"},\
	{"TB_2_13_CNTL"},\
	{"TB_2_14_ORS"},\
	{"TB_2_14_CNTL"},\
	{"TB_2_15_ORS"},\
	{"TB_2_15_CNTL"},\
	{"TB_2_16_ORS"},			/* 0x1C0 */\
	{"TB_2_16_CNTL"},\
	{"TB_2_17_ORS"},\
	{"TB_2_17_CNTL"},\
	{"TB_2_18_ORS"},\
	{"TB_2_18_CNTL"},\
	{"TB_2_19_ORS"},\
	{"TB_2_19_CNTL"},\
	{"TB_2_20_ORS"},			/* 0x1C8 */\
	{"TB_2_20_CNTL"},\
	{"TB_2_21_ORS"},\
	{"TB_2_21_CNTL"},\
	{"TB_2_22_ORS"},\
	{"TB_2_22_CNTL"},\
	{"TB_2_23_ORS"},\
	{"TB_2_23_CNTL"},\
	{"TB_3_0_ORS"},				/* 0x1D0 */\
	{"TB_3_0_CNTL"},\
	{"TB_3_1_ORS"},\
	{"TB_3_1_CNTL"},\
	{"TB_3_2_ORS"},\
	{"TB_3_2_CNTL"},\
	{"TB_3_3_ORS"},\
	{"TB_3_3_CNTL"},\
	{"TB_3_4_ORS"},				/* 0x1D8 */\
	{"TB_3_4_CNTL"},\
	{"TB_3_5_ORS"},\
	{"TB_3_5_CNTL"},\
	{"TB_3_6_ORS"},\
	{"TB_3_6_CNTL"},\
	{"TB_3_7_ORS"},\
	{"TB_3_7_CNTL"},\
	{"TB_3_8_ORS"},				/* 0x1E0 */\
	{"TB_3_8_CNTL"},\
	{"TB_3_9_ORS"},\
	{"TB_3_9_CNTL"},\
	{"TB_3_10_ORS"},\
	{"TB_3_10_CNTL"},\
	{"TB_3_11_ORS"},\
	{"TB_3_11_CNTL"},\
	{"TB_3_12_ORS"},			/* 0x1E8 */\
	{"TB_3_12_CNTL"},\
	{"TB_3_13_ORS"},\
	{"TB_3_13_CNTL"},\
	{"TB_3_14_ORS"},\
	{"TB_3_14_CNTL"},\
	{"TB_3_15_ORS"},\
	{"TB_3_15_CNTL"},\
	{"TB_3_16_ORS"},			/* 0x1F0 */\
	{"TB_3_16_CNTL"},\
	{"TB_3_17_ORS"},\
	{"TB_3_17_CNTL"},\
	{"TB_3_18_ORS"},\
	{"TB_3_18_CNTL"},\
	{"TB_3_19_ORS"},\
	{"TB_3_19_CNTL"},\
	{"TB_3_20_ORS"},			/* 0x1F8 */\
	{"TB_3_20_CNTL"},\
	{"TB_3_21_ORS"},\
	{"TB_3_21_CNTL"},\
	{"TB_3_22_ORS"},\
	{"TB_3_22_CNTL"},\
	{"TB_3_23_ORS"},\
	{"TB_3_23_CNTL"},\
	{"NOT_IMPLEMENTED"},		/* 0x200 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x208 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x210 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x218 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x220 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x228 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x230 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x238 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x240 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x248 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x250 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},		/* 0x258 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},			/* 0x260 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},			/* 0x268 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},			/* 0x270 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},			/* 0x278 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},			/* 0x280 */\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"AUX_EVT_4_CNTL"},			/* 0x288 */\
	{"AUX_4_ENA"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"},\
	{"NOT_IMPLEMENTED"}
#else
	#define _AET_DEBUG_TABLE {"NO_DATA"}
#endif

#define AET_indexof(_type, _ident) 	(offsetof(_type, _ident) >> 2)

typedef enum {
	AET_FALSE = 0,
	AET_TRUE = 1
}_AET_BOOL;

typedef enum {
	AET_CMP_FALSE = 0,
	AET_CMP_TRUE = 1
}_AET_addrCmpBool;

typedef enum {
	AET_EVENT_TYPE_MEMORY = 0,
	AET_EVENT_TYPE_STALL = 1,
	AET_EVENT_TYPE_MISC = 2,
	AET_EVENT_TYPE_UNINITIALIZED = 3,
	AET_EVENT_TYPE_INVALID = 4
}_AET_aegEventClass;
/* 
 Structure Definitions and Typedefs 
 */

typedef enum {
	AET_INITIALIZED = -10,
	AET_UNINITIALIZED 
}_AET_initStatus;

typedef enum {
	AET_DRC_REF_ACCESS_BYTE = 0,
	AET_DRC_REF_ACCESS_HALFWORD = 1,
	AET_DRC_REF_ACCESS_WORD = 2,
	AET_DRC_REF_ACCESS_DOUBLEWORD = 3
}_AET_drcRefSize;

typedef enum {
	AET_DRC_ACCESS_NONE = 0x0,
	AET_DRC_ACCESS_BYTE = 0x1,
	AET_DRC_ACCESS_HALFWORD = 0x2,
	AET_DRC_ACCESS_HALFWORD_BYTE = 0x3,
	AET_DRC_ACCESS_WORD = 0x4,
	AET_DRC_ACCESS_WORD_BYTE = 0x5,
	AET_DRC_ACCESS_WORD_HALFWORD = 0x6,
	AET_DRC_ACCESS_WORD_HALFWORD_BYTE = 0x7,
	AET_DRC_ACCESS_DOUBLEWORD = 0x8,
	AET_DRC_ACCESS_DOUBLEWORD_BYTE = 0x9,
	AET_DRC_ACCESS_DOUBLEWORD_HALFWORD = 0xA,
	AET_DRC_ACCESS_DOUBLEWORD_HALFWORD_BYTE = 0xB,
	AET_DRC_ACCESS_DOUBLEWORD_WORD = 0xC,
	AET_DRC_ACCESS_DOUBLEWORD_WORD_BYTE = 0xD, 
	AET_DRC_ACCESS_DOUBLEWORD_WORD_HALFWORD = 0xE,
	AET_DRC_ACCESS_DOUBLEWORD_WORD_HALFWORD_BYTE = 0xF,
	AET_DRC_ACCESS_ANY = 0xF
}_AET_drcAccessSize;

typedef enum {
	AET_DRC_DATAQUAL_NO_QUALIFY = 0x0,
	AET_DRC_DATAQUAL_QUALIFY = 0x1
}_AET_drcDataQualify;

typedef enum {
	AET_COUNTER_ACTION_START = 0x0,
	AET_COUNTER_ACTION_STOP = 0x1
}_AET_counterAction;

typedef enum {
	AET_COUNTER_OP_MODE_GENERIC,
	AET_COUNTER_OP_MODE_MIN_WM,
	AET_COUNTER_OP_MODE_MAX_WM
}_AET_counterOpMode;

typedef enum {
	AET_COUNTER_CNT_MODE_COUNTER,
	AET_COUNTER_CNT_MODE_EVENT,
	AET_COUNTER_CNT_MODE_CONTINUOUS,
	AET_COUNTER_CNT_MODE_ONESHOT
}_AET_counterCntMode;



typedef enum {
	AET_STATE_AVAIL = 0,
	AET_STATE_CLAIMED,
	AET_STATE_DISABLED,
	AET_STATE_ENABLED
}_AET_state;

/* 
 This type of structure is placed in a global array used
 as a lookup table for Trigger Builders
 */
typedef enum {
	_AET_TB_1_WIDE,
	_AET_TB_3_WIDE,
	_AET_TB_7_WIDE,
	_AET_TB_NONE
}_AET_triggerBuilderType;



typedef uint8_t _AET_drcByteEnable;

/* This structure makes up the configuration words for each
   job and for the resource management functions
 */
typedef struct {
	unsigned AEG:AET_NUM_AEG;
	unsigned CNT:AET_NUM_COUNTER;
	unsigned TB7:AET_NUM_TB_7WIDE;
	unsigned TB3:AET_NUM_TB_3WIDE;
	unsigned TB1:AET_NUM_TB_1WIDE;
	unsigned DCMP:AET_NUM_DCMP;
	unsigned ACMP:AET_NUM_ACMP;
	unsigned AEGMUX:AET_NUM_AEGMUXLINE;
	unsigned SM:AET_NUM_2_STATEMACHINE;
	uint8_t initTbNumber;
	_AET_triggerBuilderType initTbType;

}_AET_resourceStruct;

typedef struct {
	uint16_t entriesUsed;
	_AET_resourceStruct table[_AET_MAX_CONCURRENT_JOBS];
}_AET_jobTable;

typedef struct _AET_globalRegisters {
	int32_t cisBusSel;
	int32_t tbEnable;
	int32_t tbDomain;
	int32_t cntFuncCntl;
}_AET_globalRegs;

typedef struct {
	AET_triggerType trigType;
	_AET_triggerBuilderType tbType;
	uint8_t triggerBuilderNo;
	uint8_t outputCntl;
	uint8_t triggerNo;
	uint8_t triggerSelectionOrder;
}_AET_triggerBuilderInfo;

typedef struct {
	_AET_resourceStruct AET_usedResources;
	unsigned short AET_claimed;
	_AET_initStatus initStatus;
	_AET_globalRegs globRegs;
	_AET_jobTable jobTable;
	AET_counterConfig cntConfig[AET_NUM_AET_CNT];
	_AET_state aetState;
}_AET_globalVars;



typedef struct {
	char regName[16];
}_AET_debugInfo;

typedef struct {
	uint16_t size;
	uint16_t cmpBaseIndex;
	AET_refSize accessRefSize;
	_AET_drcDataQualify dataQualify; 
	AET_watchReadWrite readWrite;
	_AET_drcAccessSize accessType;
	uint8_t byteEnableMask;
	uint8_t eventSenseMask;
	_AET_addrCmpBool cmpGreater;
	_AET_addrCmpBool cmpLess;
	int32_t addressReference;
}_AET_drcCntlParams;

typedef struct {
	uint16_t size;
	uint32_t tbOrsValue;
	uint16_t tbBaseIndex;
	uint16_t boolOutput;
	_AET_triggerBuilderType tbType;
	AET_traceTrigger triggers;
	_AET_trigBldrEventCSelect evtCSelect;
	uint8_t outputCntl;
	uint8_t tbNo;
}_AET_tbCntlParams;

/*
 Static data definitions
 */

/* 
 Static function prototypes
 */

/*
 Module Function Definintions
 */

/* 
 Static (internal) function definitions
 */
AET_jobIndex _AET_insertJobIntoTable(_AET_resourceStruct);
AET_error _AET_removeJobFromTable(AET_jobIndex, _AET_resourceStruct*);
int32_t _AET_iregRead(uint16_t index);
void _AET_iregWrite(uint16_t, int32_t);
_AET_drcByteEnable _AET_getByteEnableValue(int32_t, AET_refSize);
void _AET_pgmDrcCntlReg(_AET_drcCntlParams*, AET_jobParams*);
void _AET_pgmDrcArefReg(_AET_drcCntlParams*);
uint16_t _AET_getAegBaseIndex(uint8_t);
AET_error _AET_triggerCexpAdd(uint8_t, uint8_t, int32_t);
AET_error _AET_programAegMux(uint8_t, uint8_t);
void _AET_clearGlobalParams(void);

/*******************************************************************************
* Legacy CSL Field Make Macros 
********************************************************************************/
/* the Field MaKe macro */
#define AET_FMK(PER_REG_FIELD, val)                                         \
    (((val) << CSL_##PER_REG_FIELD##_SHIFT) & CSL_##PER_REG_FIELD##_MASK)

/* the Field EXTract macro */
#define AET_FEXT(reg, PER_REG_FIELD)                                        \
    (((reg) & CSL_##PER_REG_FIELD##_MASK) >> CSL_##PER_REG_FIELD##_SHIFT)

/* the Field INSert macro */
#define AET_FINS(reg, PER_REG_FIELD, val)                                   \
    ((reg) = ((reg) & CSL_##PER_REG_FIELD##_MASK)                          \
    | AET_FMK(PER_REG_FIELD, val))


/* the "token" macros */

/* the Field MaKe (Token) macro */
#define AET_FMKT(PER_REG_FIELD, TOKEN)                                      \
    AET_FMK(PER_REG_FIELD, CSL_##PER_REG_FIELD##_##TOKEN)

/* the Field INSert (Token) macro */
#define AET_FINST(reg, PER_REG_FIELD, TOKEN)                                \
    AET_FINS((reg), PER_REG_FIELD, CSL_##PER_REG_FIELD##_##TOKEN)


/* the "raw" macros */

/* the Field MaKe (Raw) macro */
#define AET_FMKR(msb, lsb, val)                                             \
    (((val) & ((1 << ((msb) - (lsb) + 1)) - 1)) << (lsb))

/* the Field EXTract (Raw) macro */
#define AET_FEXTR(reg, msb, lsb)                                            \
    (((reg) >> (lsb)) & ((1 << ((msb) - (lsb) + 1)) - 1))

/* the Field INSert (Raw) macro */
#define AET_FINSR(reg, msb, lsb, val)                                       \
    ((reg) = ((reg) &~ (((1 << ((msb) - (lsb) + 1)) - 1) << (lsb)))         \
    | AET_FMKR(msb, lsb, val))


/* 
  Revision History
  - Initial Revision - September 2006 
  - AETLIB 4.0 - To remove dependency on CSL, added the CSL field make macros 
    here and renamed them to AET field make macros.  here and throughout the library source
 */
 

#ifdef __cplusplus
}
#endif


#endif
