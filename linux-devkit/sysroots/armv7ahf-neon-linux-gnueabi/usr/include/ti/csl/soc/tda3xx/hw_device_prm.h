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
 *  \file   hw_device_prm.h
 *
 *  \brief  Register-level header file for PRCM
 *
**/

#ifndef HW_DEVICE_PRM_H_
#define HW_DEVICE_PRM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define PRM_RSTCTRL                                            (0x0U)
#define PRM_RSTST                                                   (0x4U)
#define PRM_RSTTIME                                            (0x8U)
#define PRM_CLKREQCTRL                                         (0xcU)
#define PRM_VOLTCTRL                                                (0x10U)
#define PRM_PWRREQCTRL                                         (0x14U)
#define PRM_PSCON_COUNT                                             (0x18U)
#define PRM_IO_COUNT                                           (0x1cU)
#define PRM_IO_PMCTRL                                          (0x20U)
#define PRM_VOLTSETUP_WARMRESET                                (0x24U)
#define PRM_VOLTSETUP_CORE_OFF                                 (0x28U)
#define PRM_VOLTSETUP_MM_OFF                                   (0x30U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP                           (0x34U)
#define PRM_VOLTSETUP_MM_RET_SLEEP                             (0x3cU)
#define PRM_SRAM_COUNT                                         (0xbcU)
#define PRM_SRAM_WKUP_SETUP                                    (0xc0U)
#define PRM_SLDO_CORE_SETUP                                    (0xc4U)
#define PRM_SLDO_CORE_CTRL                                     (0xc8U)
#define PRM_BANDGAP_SETUP                                      (0xecU)
#define PRM_DEVICE_OFF_CTRL                                         (0xf0U)
#define PRM_PHASE1_CNDP                                        (0xf4U)
#define PRM_PHASE2A_CNDP                                       (0xf8U)
#define PRM_PHASE2B_CNDP                                       (0xfcU)
#define PRM_MODEM_IF_CTRL                                      (0x100U)
#define PRM_VOLTST_MM                                          (0x114U)
#define PRM_SLDO_DSPEVE_SETUP                                  (0x118U)
#define PRM_ABBLDO_DSPEVE_CTRL                                 (0x120U)
#define PRM_SLDO_DSPEVE_CTRL                                   (0x128U)
#define PRM_ABBLDO_DSPEVE_SETUP                                (0x130U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW_SHIFT                                       (0U)
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW_MASK                                        (0x00000001U)
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW_0X0                                          (0U)
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW_0X1                                          (1U)

#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW_SHIFT                                       (1U)
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW_MASK                                        (0x00000002U)
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW_0X0                                          (0U)
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW_0X1                                          (1U)

#define PRM_RSTST_GLOBAL_COLD_RST_SHIFT                                                                     (0U)
#define PRM_RSTST_GLOBAL_COLD_RST_MASK                                                                      (0x00000001U)
#define PRM_RSTST_GLOBAL_COLD_RST_0X0                                                                        (0U)
#define PRM_RSTST_GLOBAL_COLD_RST_0X1                                                                        (1U)
#define PRM_RSTST_GLOBAL_WARM_SW_RST_SHIFT                                              (1U)
#define PRM_RSTST_GLOBAL_WARM_SW_RST_MASK                                               (0x00000002U)
#define PRM_RSTST_GLOBAL_WARM_SW_RST_0X0                                                 (0U)
#define PRM_RSTST_GLOBAL_WARM_SW_RST_0X1                                                 (1U)

#define PRM_RSTST_EXTERNAL_WARM_RST_SHIFT                                               (5U)
#define PRM_RSTST_EXTERNAL_WARM_RST_MASK                                                (0x00000020U)
#define PRM_RSTST_EXTERNAL_WARM_RST_0X0                                                  (0U)
#define PRM_RSTST_EXTERNAL_WARM_RST_0X1                                                  (1U)

#define PRM_RSTST_SECURE_WDT_RST_SHIFT                                                  (4U)
#define PRM_RSTST_SECURE_WDT_RST_MASK                                                   (0x00000010U)
#define PRM_RSTST_SECURE_WDT_RST_0X0                                                     (0U)
#define PRM_RSTST_SECURE_WDT_RST_0X1                                                     (1U)

#define PRM_RSTST_VDD_MM_VOLT_MGR_RST_SHIFT                                             (7U)
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST_MASK                                              (0x00000080U)
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST_0X0                                                (0U)
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST_0X1                                                (1U)

#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST_SHIFT                                           (8U)
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST_MASK                                            (0x00000100U)
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST_0X0                                              (0U)
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST_0X1                                              (1U)

#define PRM_RSTST_ICEPICK_RST_SHIFT                                                     (9U)
#define PRM_RSTST_ICEPICK_RST_MASK                                                      (0x00000200U)
#define PRM_RSTST_ICEPICK_RST_0X0                                                        (0U)
#define PRM_RSTST_ICEPICK_RST_0X1                                                        (1U)

#define PRM_RSTST_C2C_RST_SHIFT                                                         (10U)
#define PRM_RSTST_C2C_RST_MASK                                                          (0x00000400U)
#define PRM_RSTST_C2C_RST_0X0                                                            (0U)
#define PRM_RSTST_C2C_RST_0X1                                                            (1U)

#define PRM_RSTST_TSHUT_MM_RST_SHIFT                                                    (12U)
#define PRM_RSTST_TSHUT_MM_RST_MASK                                                     (0x00001000U)
#define PRM_RSTST_TSHUT_MM_RST_0X0                                                       (0U)
#define PRM_RSTST_TSHUT_MM_RST_0X1                                                       (1U)

#define PRM_RSTST_TSHUT_CORE_RST_SHIFT                                                  (13U)
#define PRM_RSTST_TSHUT_CORE_RST_MASK                                                   (0x00002000U)
#define PRM_RSTST_TSHUT_CORE_RST_0X0                                                     (0U)
#define PRM_RSTST_TSHUT_CORE_RST_0X1                                                     (1U)

#define PRM_RSTST_LLI_RST_SHIFT                                                         (14U)
#define PRM_RSTST_LLI_RST_MASK                                                          (0x00004000U)
#define PRM_RSTST_LLI_RST_0X0                                                            (0U)
#define PRM_RSTST_LLI_RST_0X1                                                            (1U)

#define PRM_RSTTIME_RSTTIME1_SHIFT                                                 (0U)
#define PRM_RSTTIME_RSTTIME1_MASK                                                  (0x000003ffU)
#define PRM_RSTTIME_RSTTIME1_RESERVED                                               (0U)

#define PRM_RSTTIME_RSTTIME2_SHIFT                                                 (10U)
#define PRM_RSTTIME_RSTTIME2_MASK                                                  (0x00007c00U)
#define PRM_RSTTIME_RSTTIME2_RESERVED                                               (0U)

#define PRM_CLKREQCTRL_CLKREQ_COND_SHIFT                                           (0U)
#define PRM_CLKREQCTRL_CLKREQ_COND_MASK                                            (0x00000007U)
#define PRM_CLKREQCTRL_CLKREQ_COND_NEVER                                            (0U)
#define PRM_CLKREQCTRL_CLKREQ_COND_OFF                                              (1U)
#define PRM_CLKREQCTRL_CLKREQ_COND_RET                                              (2U)
#define PRM_CLKREQCTRL_CLKREQ_COND_SLEEP                                            (3U)
#define PRM_CLKREQCTRL_CLKREQ_COND_ON                                               (4U)
#define PRM_CLKREQCTRL_CLKREQ_COND_RESERVED_5                                       (5U)
#define PRM_CLKREQCTRL_CLKREQ_COND_RESERVED_6                                       (6U)
#define PRM_CLKREQCTRL_CLKREQ_COND_RESERVED_7                                       (7U)

#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_SHIFT                                         (0U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_MASK                                          (0x00000003U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_DISABLED                                       (0U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_AUTO_SLEEP                                                         (1U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_AUTO_RET                                                           (2U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_RESERVED                                       (3U)

#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_SHIFT                                           (4U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_MASK                                            (0x00000030U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_DISABLED                                         (0U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_AUTO_SLEEP                                                           (1U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_AUTO_RET                                                             (2U)
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_RESERVED                                         (3U)

#define PRM_VOLTCTRL_VDD_MM_PRESENCE_SHIFT                                              (9U)
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_MASK                                               (0x00000200U)
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_VOLTAGE_PRESENT                                     (1U)
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_VOLTAGE_ABSENT                                      (0U)

#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_SHIFT                                         (12U)
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_MASK                                          (0x00001000U)
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_I2C_ENABLED                                                        (0U)
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_I2C_DISABLED                                                       (1U)

#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_SHIFT                                           (14U)
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_MASK                                            (0x00004000U)
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_I2C_ENABLED                                                          (0U)
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_I2C_DISABLED                                                         (1U)

#define PRM_PWRREQCTRL_PWRREQ_COND_SHIFT                                           (0U)
#define PRM_PWRREQCTRL_PWRREQ_COND_MASK                                            (0x00000003U)
#define PRM_PWRREQCTRL_PWRREQ_COND_NEVER                                            (0U)
#define PRM_PWRREQCTRL_PWRREQ_COND_SLEEP                                            (1U)
#define PRM_PWRREQCTRL_PWRREQ_COND_RET                                              (2U)
#define PRM_PWRREQCTRL_PWRREQ_COND_OFF                                              (3U)

#define PRM_PSCON_COUNT_PONOUT_2_PGOODIN_TIME_SHIFT                                     (8U)
#define PRM_PSCON_COUNT_PONOUT_2_PGOODIN_TIME_MASK                                      (0x0000ff00U)

#define PRM_PSCON_COUNT_HG_PONOUT_2_PGOODIN_TIME_SHIFT                                  (16U)
#define PRM_PSCON_COUNT_HG_PONOUT_2_PGOODIN_TIME_MASK                                   (0x00ff0000U)

#define PRM_IO_COUNT_ISO_2_ON_TIME_SHIFT                                           (0U)
#define PRM_IO_COUNT_ISO_2_ON_TIME_MASK                                            (0x000000ffU)

#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_SHIFT                                        (0U)
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_MASK                                         (0x00000001U)
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE                                    (0U)
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_OVERRIDE                                                               (1U)

#define PRM_IO_PMCTRL_ISOCLK_STATUS_SHIFT                                          (1U)
#define PRM_IO_PMCTRL_ISOCLK_STATUS_MASK                                           (0x00000002U)

#define PRM_IO_PMCTRL_WUCLK_CTRL_SHIFT                                             (8U)
#define PRM_IO_PMCTRL_WUCLK_CTRL_MASK                                              (0x00000100U)
#define PRM_IO_PMCTRL_WUCLK_CTRL_LOW                                                (0U)
#define PRM_IO_PMCTRL_WUCLK_CTRL_HIGH                                               (1U)

#define PRM_IO_PMCTRL_WUCLK_STATUS_SHIFT                                           (9U)
#define PRM_IO_PMCTRL_WUCLK_STATUS_MASK                                            (0x00000200U)

#define PRM_IO_PMCTRL_GLOBAL_WUEN_SHIFT                                            (16U)
#define PRM_IO_PMCTRL_GLOBAL_WUEN_MASK                                             (0x00010000U)
#define PRM_IO_PMCTRL_GLOBAL_WUEN_DISABLED                                          (0U)
#define PRM_IO_PMCTRL_GLOBAL_WUEN_ENABLED                                           (1U)

#define PRM_IO_PMCTRL_ISOOVR_EXTEND_SHIFT                                          (4U)
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_MASK                                           (0x00000010U)
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_NOOVERRIDE                                      (0U)
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_OVERRIDE                                        (1U)

#define PRM_IO_PMCTRL_IO_ON_STATUS_SHIFT                                                                    (5U)
#define PRM_IO_PMCTRL_IO_ON_STATUS_MASK                                                                     (0x00000020U)
#define PRM_IO_PMCTRL_IO_ON_STATUS_LOW                                                                       (0U)
#define PRM_IO_PMCTRL_IO_ON_STATUS_HIGH                                                                      (1U)

#define PRM_VOLTSETUP_WARMRESET_STABLE_COUNT_SHIFT                                 (0U)
#define PRM_VOLTSETUP_WARMRESET_STABLE_COUNT_MASK                                  (0x0000003fU)

#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_SHIFT                               (8U)
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_MASK                                (0x00000300U)
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X32                                  (0U)
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X256                                 (1U)
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X2048                                (2U)
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X16384                               (3U)

#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_COUNT_SHIFT                                 (0U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_COUNT_MASK                                  (0x0000003fU)

#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_SHIFT                               (8U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_MASK                                (0x00000300U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X64                                  (0U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X256                                 (1U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X512                                 (2U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X2048                                (3U)

#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_COUNT_SHIFT                               (16U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_COUNT_MASK                                (0x003f0000U)

#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_SHIFT                             (24U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_MASK                              (0x03000000U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X64                                (0U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X256                               (1U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X512                               (2U)
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X2048                              (3U)

#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_COUNT_SHIFT                                   (0U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_COUNT_MASK                                    (0x0000003fU)

#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_SHIFT                                 (8U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_MASK                                  (0x00000300U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X64                                    (0U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X256                                   (1U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X512                                   (2U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X2048                                  (3U)

#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_COUNT_SHIFT                                 (16U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_COUNT_MASK                                  (0x003f0000U)

#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_SHIFT                               (24U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_MASK                                (0x03000000U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X64                                  (0U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X256                                 (1U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X512                                 (2U)
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X2048                                (3U)

#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_COUNT_SHIFT                           (0U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_COUNT_MASK                            (0x0000003fU)

#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_SHIFT                         (8U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_MASK                          (0x00000300U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X64                            (0U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X256                           (1U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X512                           (2U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X2048                          (3U)

#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_COUNT_SHIFT                         (16U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_COUNT_MASK                          (0x003f0000U)

#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_SHIFT                       (24U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_MASK                        (0x03000000U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X64                          (0U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X256                         (1U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X512                         (2U)
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X2048                        (3U)

#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_COUNT_SHIFT                             (0U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_COUNT_MASK                              (0x0000003fU)

#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_SHIFT                           (8U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_MASK                            (0x00000300U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X64                              (0U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X256                             (1U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X512                             (2U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X2048                            (3U)

#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_COUNT_SHIFT                           (16U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_COUNT_MASK                            (0x003f0000U)

#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_SHIFT                         (24U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_MASK                          (0x03000000U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X64                            (0U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X256                           (1U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X512                           (2U)
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X2048                          (3U)

#define PRM_SRAM_COUNT_PCHARGECNT_VALUE_SHIFT                                      (0U)
#define PRM_SRAM_COUNT_PCHARGECNT_VALUE_MASK                                       (0x0000003fU)

#define PRM_SRAM_COUNT_VSETUPCNT_VALUE_SHIFT                                       (8U)
#define PRM_SRAM_COUNT_VSETUPCNT_VALUE_MASK                                        (0x0000ff00U)

#define PRM_SRAM_COUNT_SLPCNT_VALUE_SHIFT                                          (16U)
#define PRM_SRAM_COUNT_SLPCNT_VALUE_MASK                                           (0x00ff0000U)

#define PRM_SRAM_COUNT_STARTUP_COUNT_SHIFT                                                                  (24U)
#define PRM_SRAM_COUNT_STARTUP_COUNT_MASK                                                                   (0xff000000U)

#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_SHIFT                                       (0U)
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_MASK                                        (0x00000001U)
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_RTA_ENABLED                                                           (1U)
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_RTA_DISABLED                                                          (0U)

#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_SHIFT                                       (1U)
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_MASK                                        (0x00000002U)
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS                                                       (0U)
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR                                                      (1U)

#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_SHIFT                                     (2U)
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_MASK                                      (0x00000004U)
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS                            (0U)
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR                           (1U)

#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_SHIFT                                       (0U)
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_MASK                                        (0x00000001U)
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_RTA_ENABLED                                                           (1U)
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_RTA_DISABLED                                                          (0U)

#define PRM_SLDO_CORE_SETUP_ENFUNC1_SHIFT                                          (3U)
#define PRM_SLDO_CORE_SETUP_ENFUNC1_MASK                                           (0x00000008U)
#define PRM_SLDO_CORE_SETUP_ENFUNC1_SHORT_PROT_DISABLED                             (0U)
#define PRM_SLDO_CORE_SETUP_ENFUNC1_SHORT_PROT_ENABLED                              (1U)

#define PRM_SLDO_CORE_SETUP_ENFUNC2_SHIFT                                          (4U)
#define PRM_SLDO_CORE_SETUP_ENFUNC2_MASK                                           (0x00000010U)
#define PRM_SLDO_CORE_SETUP_ENFUNC2_EXT_CAP                                         (0U)
#define PRM_SLDO_CORE_SETUP_ENFUNC2_NO_EXT_CAP                                      (1U)

#define PRM_SLDO_CORE_SETUP_ENFUNC3_SHIFT                                          (5U)
#define PRM_SLDO_CORE_SETUP_ENFUNC3_MASK                                           (0x00000020U)
#define PRM_SLDO_CORE_SETUP_ENFUNC3_SUB_REGUL_DISABLED                              (0U)
#define PRM_SLDO_CORE_SETUP_ENFUNC3_SUB_REGUL_ENABLED                               (1U)

#define PRM_SLDO_CORE_SETUP_ENFUNC4_SHIFT                                          (6U)
#define PRM_SLDO_CORE_SETUP_ENFUNC4_MASK                                           (0x00000040U)
#define PRM_SLDO_CORE_SETUP_ENFUNC4_EXT_CLOCK                                       (0U)
#define PRM_SLDO_CORE_SETUP_ENFUNC4_NO_EXT_CLOCK                                    (1U)

#define PRM_SLDO_CORE_SETUP_ENFUNC5_SHIFT                                          (7U)
#define PRM_SLDO_CORE_SETUP_ENFUNC5_MASK                                           (0x00000080U)
#define PRM_SLDO_CORE_SETUP_ENFUNC5_ONE_STEP                                        (0U)
#define PRM_SLDO_CORE_SETUP_ENFUNC5_TWO_STEP                                        (1U)

#define PRM_SLDO_CORE_SETUP_AIPOFF_SHIFT                                           (8U)
#define PRM_SLDO_CORE_SETUP_AIPOFF_MASK                                            (0x00000100U)
#define PRM_SLDO_CORE_SETUP_AIPOFF_NO_OVERRIDE                                      (0U)
#define PRM_SLDO_CORE_SETUP_AIPOFF_OVERRIDE                                         (1U)

#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_SHIFT                                    (8U)
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_MASK                                     (0x00000100U)
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_ACTIVE                                    (0U)
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_RETENTION                                 (1U)

#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_SHIFT                                (9U)
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_MASK                                 (0x00000200U)
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_IDLE                                  (0U)
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION                                                  (1U)

#define PRM_SLDO_CORE_CTRL_RETMODE_ENABLE_SHIFT                                    (0U)
#define PRM_SLDO_CORE_CTRL_RETMODE_ENABLE_MASK                                     (0x00000001U)
#define PRM_SLDO_CORE_CTRL_RETMODE_ENABLE_DISABLED                                  (0U)

#define PRM_BANDGAP_SETUP_STARTUP_COUNT_SHIFT                                      (0U)
#define PRM_BANDGAP_SETUP_STARTUP_COUNT_MASK                                       (0x000000ffU)

#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_SHIFT                                                         (0U)
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_MASK                                                          (0x00000001U)
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_DISABLED                                                       (0U)
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_ENABLED                                                        (1U)

#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_SHIFT                                 (8U)
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_MASK                                  (0x00000100U)
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_DISABLED                               (1U)
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_ENABLED                                (0U)

#define PRM_PHASE1_CNDP_PHASE1_CNDP_SHIFT                                                                   (0U)
#define PRM_PHASE1_CNDP_PHASE1_CNDP_MASK                                                                    (0xffffffffU)

#define PRM_PHASE2A_CNDP_PHASE2A_CNDP_SHIFT                                                                 (0U)
#define PRM_PHASE2A_CNDP_PHASE2A_CNDP_MASK                                                                  (0xffffffffU)

#define PRM_PHASE2B_CNDP_PHASE2B_CNDP_SHIFT                                                                 (0U)
#define PRM_PHASE2B_CNDP_PHASE2B_CNDP_MASK                                                                  (0xffffffffU)

#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_SHIFT                                                              (8U)
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_MASK                                                               (0x00000100U)
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_ACTIVE                                                              (1U)
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_INACTIVE                                                            (0U)

#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_SHIFT                                                          (9U)
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_MASK                                                           (0x00000200U)
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_ACTIVE                                                          (1U)
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_INACTIVE                                                        (0U)

#define PRM_VOLTST_MM_VOLTSTATEST_SHIFT                                            (0U)
#define PRM_VOLTST_MM_VOLTSTATEST_MASK                                             (0x00000003U)
#define PRM_VOLTST_MM_VOLTSTATEST_OFF                                               (0U)
#define PRM_VOLTST_MM_VOLTSTATEST_RET                                               (1U)
#define PRM_VOLTST_MM_VOLTSTATEST_SLEEP                                             (2U)
#define PRM_VOLTST_MM_VOLTSTATEST_ON                                                (3U)

#define PRM_VOLTST_MM_INTRANSITION_SHIFT                                           (20U)
#define PRM_VOLTST_MM_INTRANSITION_MASK                                            (0x00100000U)
#define PRM_VOLTST_MM_INTRANSITION_NO                                               (0U)
#define PRM_VOLTST_MM_INTRANSITION_ONGOING                                          (1U)

#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_SHIFT                                     (1U)
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_MASK                                      (0x00000002U)
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS                                                     (0U)
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR                                                    (1U)

#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_SHIFT                                   (2U)
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_MASK                                    (0x00000004U)
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS                          (0U)
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR                         (1U)

#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_SHIFT                                        (6U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_MASK                                         (0x00000040U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_EXT_CLOCK                                     (0U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_NO_EXT_CLOCK                                  (1U)

#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_SHIFT                                        (7U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_MASK                                         (0x00000080U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_ONE_STEP                                      (0U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_TWO_STEP                                      (1U)

#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_SHIFT                                         (8U)
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_MASK                                          (0x00000100U)
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_NO_OVERRIDE                                    (0U)
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_OVERRIDE                                       (1U)

#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_SHIFT                                     (0U)
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_MASK                                      (0x00000001U)
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_RTA_ENABLED                                                         (1U)
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_RTA_DISABLED                                                        (0U)

#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_SHIFT                                        (3U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_MASK                                         (0x00000008U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_SHORT_PROT_DISABLED                           (0U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_SHORT_PROT_ENABLED                            (1U)

#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_SHIFT                                        (4U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_MASK                                         (0x00000010U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_EXT_CAP                                       (0U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_NO_EXT_CAP                                    (1U)

#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_SHIFT                                        (5U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_MASK                                         (0x00000020U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_SUB_REGUL_DISABLED                            (0U)
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_SUB_REGUL_ENABLED                             (1U)

#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_SHIFT                                       (0U)
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_MASK                                        (0x00000003U)
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_DEFAULT_NOMINAL                              (0U)
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_FASTOPP                                      (1U)
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_NOMINALOPP                                   (2U)
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_SLOWOPP                                      (3U)

#define PRM_ABBLDO_DSPEVE_CTRL_OPP_CHANGE_SHIFT                                    (2U)
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_CHANGE_MASK                                     (0x00000004U)

#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_SHIFT                                    (3U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_MASK                                     (0x00000018U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_BYPASS                                    (0U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_RESERVED1                                 (1U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_RESERVED                                  (3U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_FBB                                       (2U)

#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_SHIFT                             (6U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_MASK                              (0x00000040U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_IDLE                               (0U)
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_INTRANSITION                       (1U)

#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_SHIFT                                  (8U)
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_MASK                                   (0x00000100U)
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_ACTIVE                                  (0U)
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_RETENTION                               (1U)

#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_SHIFT                              (9U)
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_MASK                               (0x00000200U)
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_IDLE                                (0U)
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION                                                (1U)

#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_SHIFT                                  (0U)
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_MASK                                   (0x00000001U)
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_DISABLED                                (0U)
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_ENABLED                                 (1U)

#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_SHIFT                                        (0U)
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_MASK                                         (0x00000001U)
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_BYPASS                                        (0U)
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_FUNCTIONAL                                    (1U)

#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_SHIFT                               (2U)
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_MASK                                (0x00000004U)
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_BYPASS                               (0U)
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_FBB                                                           (1U)

#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_SHIFT                                        (4U)
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_MASK                                         (0x00000010U)
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_CAP                                           (0U)
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_NOCAP                                                                  (1U)

#define PRM_ABBLDO_DSPEVE_SETUP_SR2_WTCNT_VALUE_SHIFT                              (8U)
#define PRM_ABBLDO_DSPEVE_SETUP_SR2_WTCNT_VALUE_MASK                               (0x0000ff00U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_DEVICE_PRM_H_ */

