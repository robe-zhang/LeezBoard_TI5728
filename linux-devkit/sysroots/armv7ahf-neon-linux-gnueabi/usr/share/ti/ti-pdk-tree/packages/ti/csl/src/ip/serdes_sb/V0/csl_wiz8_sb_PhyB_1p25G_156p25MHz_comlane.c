/**
* File: csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane
*
* Version: SnowBushRel_PHY_B_18.2_20150626 - Change VREGg/h
*
* Brief:
*  Autogenerated SERDES CONFIG Functions.
*
*  It contains the various enumerations, structure definitions and function
*  declarations
*
*  
*  ============================================================================
*  (C) Copyright 2014, Texas Instruments, Inc.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifndef CSL_WIZ8_SB_PHYB_1P25G_156P25MHZ_COMLANE_C
#define CSL_WIZ8_SB_PHYB_1P25G_156P25MHZ_COMLANE_C

#include <stdint.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl.h>

/*for misra warning*/
void csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane(uint32_t base_addr);
void csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane(uint32_t base_addr)
  {
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00),15, 8, (uint32_t)0x08);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a84), 7, 0, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a90),23,16, (uint32_t)0xa0);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a90),31,24, (uint32_t)0x77);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a94), 7, 0, (uint32_t)0x77);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a94),15, 8, (uint32_t)0x77);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b08),23,16, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b08),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b0c), 7, 0, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b0c),15, 8, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b0c),23,16, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b10),31,24, (uint32_t)0xbe);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b14), 7, 0, (uint32_t)0xff);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b18), 7, 0, (uint32_t)0x14);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b5c),23,16, (uint32_t)0x1b);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b5c),31,24, (uint32_t)0x98);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b64),15, 8, (uint32_t)0x11);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b78),15, 8, (uint32_t)0x0c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0abc),31,24, (uint32_t)0xff);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0ac0), 7, 0, (uint32_t)0x8b);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a48),15, 8, (uint32_t)0x8c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a48),23,16, (uint32_t)0xfd);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a54), 7, 0, (uint32_t)0x72);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a54),15, 8, (uint32_t)0xec);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a54),23,16, (uint32_t)0x2f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a58),15, 8, (uint32_t)0x21);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a58),23,16, (uint32_t)0xf9);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a58),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c), 7, 0, (uint32_t)0x60);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c),15, 8, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c),23,16, (uint32_t)0x04);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60), 7, 0, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60),15, 8, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60),23,16, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64), 7, 0, (uint32_t)0x20);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64),15, 8, (uint32_t)0x12);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64),23,16, (uint32_t)0x58);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64),31,24, (uint32_t)0x0c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68), 7, 0, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68),15, 8, (uint32_t)0x06);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68),23,16, (uint32_t)0x3b);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68),31,24, (uint32_t)0xe1);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c), 7, 0, (uint32_t)0xc1);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c),15, 8, (uint32_t)0x4c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c),23,16, (uint32_t)0x07);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c),31,24, (uint32_t)0xb8);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70), 7, 0, (uint32_t)0x89);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70),15, 8, (uint32_t)0xe9);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70),23,16, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70),31,24, (uint32_t)0x3f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a74), 7, 0, (uint32_t)0x01);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0ba4),31,24, (uint32_t)0x37);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0ba8), 7, 0, (uint32_t)0x5d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0ba8),23,16, (uint32_t)0x37);
  }
#endif
