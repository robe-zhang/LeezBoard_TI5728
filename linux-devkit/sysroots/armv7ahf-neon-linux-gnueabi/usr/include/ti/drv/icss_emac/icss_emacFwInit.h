/**
 *   @file  icss_emacFwInit.h
 *
 *   @brief
 *      Contains Include file for PRU Initialization routines
 */
 
/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
 
#ifndef ICSS_EMAC_FWINIT__H
#define ICSS_EMAC_FWINIT__H

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/icss_emac/icss_emacDrv.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief IOCTL command members for configuring switch/EMAC
 */
typedef struct ICSSEMAC_IoctlCmd_s {
    uint8_t command;
    void *ioctlVal;
}ICSSEMAC_IoctlCmd;



/** @brief ICSS_EMAC_IOCTL_PORT_CTRL options */

/**Generic IOCTL Enable macro*/
#define ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE                   (0u)

/**Generic IOCTL Disable macro*/
#define ICSS_EMAC_IOCTL_PORT_CTRL_ENABLE                    (1u)

/** @brief ICSS_EMAC_IOCTL_STORM_PREV_CTRL options */

/**IOCTL Storm Control Enable command*/
#define ICSS_EMAC_STORM_PREV_CTRL_ENABLE                    (0u)
/**IOCTL Storm Control Disable command*/
#define ICSS_EMAC_STORM_PREV_CTRL_DISABLE                   (1u)
/**IOCTL Storm Control set credit command */
#define ICSS_EMAC_STORM_PREV_CTRL_SET_CREDITS               (2u)
/**IOCTL Storm Control initialize command */
#define ICSS_EMAC_STORM_PREV_CTRL_INIT                      (3u)
/**IOCTL Storm Control reset command */
#define ICSS_EMAC_STORM_PREV_CTRL_RESET                     (4u)

/** @brief ICSS_EMAC_IOCTL_LEARNING_CTRL options */

/**IOCTL Learning Table update command */
#define ICSS_EMAC_LEARN_CTRL_UPDATE_TABLE                   (0u)
/**IOCTL Learning Table clear table command */
#define ICSS_EMAC_LEARN_CTRL_CLR_TABLE                      (1u)
/**IOCTL Learning Table age out entry command */
#define ICSS_EMAC_LEARN_CTRL_AGEING                         (2u)
/**IOCTL Learning Table find port from MAC ID command */
#define ICSS_EMAC_LEARN_CTRL_FIND_MAC                       (3u)
/**IOCTL Learning Table remove a MAC ID from table command */
#define ICSS_EMAC_LEARN_CTRL_REMOVE_MAC                     (4u)
/**IOCTL Learning Table increment counters (for ageing) command */
#define ICSS_EMAC_LEARN_CTRL_INC_COUNTER                    (5u)
/**IOCTL Learning Table initialize command */
#define ICSS_EMAC_LEARN_CTRL_INIT_TABLE                     (6u)
/**IOCTL Learning Table set port state command */
#define ICSS_EMAC_LEARN_CTRL_SET_PORTSTATE                  (7u)

/** @brief ICSS_EMAC_IOCTL_PORT_CTRL options */

/**IOCTL Statistics get from PRU command */
#define ICSS_EMAC_IOCTL_STAT_CTRL_GET                   (0u)
/**IOCTL Statistics clear all counters command */
#define ICSS_EMAC_IOCTL_STAT_CTRL_CLEAR                 (1u)

/** @brief EMAC IOCTL Commands for selecting a module*/

/**IOCTL select port control API's command */
#define ICSS_EMAC_IOCTL_PORT_CTRL                           (0u)
/**IOCTL select learning Table API's command */
#define ICSS_EMAC_IOCTL_LEARNING_CTRL                       (1u)
/**IOCTL select Storm Prevention API's command */
#define ICSS_EMAC_IOCTL_STORM_PREV_CTRL                     (2u)
/**IOCTL select Statistics API's command */
#define ICSS_EMAC_IOCTL_STATS_CTRL                          (3u)
/**IOCTL select Time Triggered Send API's command */
#define ICSS_EMAC_IOCTL_TTS_CTRL   	                        (4u)
/**IOCTL select Time Triggered Send Get Status API's command */
#define ICSS_EMAC_IOCTL_TTS_STATUS_CTRL   	                (5u)
/**IOCTL select Promiscuous Mode API's command */
#define ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL   	                (6u)

/**Load Forward table*/
#define STATIC_FORWARD_TABLE (0U)
/**Load receive table*/
#define STATIC_RECEIVE_TABLE (1U)

#ifndef NULL
#define NULL            ((void*)0)
#endif

#define IEP_GLOBAL_CFG_REG_VAL          (0x0551U)

/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacInit API to initialize and configure ICSS in MAC/Switch Mode
 *  @details API to initialize and configure ICSS in MAC/Switch Mode
 *  @param[in]  ICSS_EmacHandle  handle to ICSS_EMAC instance
 *  @param[in]  pruss_intc_initdata INTC mapping structure pointer
*   @param[in]  emacMode Switch mode or mac mode
*
 *  @retval     0 on sucess
 */
uint8_t ICSS_EmacInit(ICSS_EmacHandle icssEmacHandle,
                           const PRUICSS_IntcInitData *pruss_intc_initdata,uint8_t emacMode);

/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacDeInit API to stop MAC/Switch Mode
 *
 *  @param[in]  ICSS_EmacHandle  handle to ICSS_EMAC instance
*   @param[in]  emacMode Switch mode or mac mode
*
 *  @retval     0 on sucess
 */
uint8_t ICSS_EmacDeInit(ICSS_EmacHandle icssEmacHandle,uint8_t emacMode);

/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacSwitchInit API to initialize and configure ICSS
 *  @details API to initialize and configure ICSS
 *  @param[in]  ICSS_EmacHandle  handle to ICSS_EMAC instance
 *  @param[in]  pruIcssHandle handle to PRUICSS instance

 *  @retval     0 on sucess
 */
int8_t ICSS_EmacSwitchInit(ICSS_EmacHandle icssEmacHandle,
        const PRUICSS_IntcInitData *pruss_intc_initdata);


/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacIoctl API to enable and disable Physical ports
 *  @details API to to enable and disable Physical ports
 *
 *  @param[in]  icssEmacHandle  EMAC Handle
 *  @param[in]  ioctlCommand    Command for EMAC_IOCTL
 *  @param[in]  portNo          Port number for IOCTL
 *  @params[in|out] ioctlParams Any data required for Command to execute.
 *  @retval     S_PASS on sucess or <0 on failure
 */
int8_t ICSS_EmacIoctl(ICSS_EmacHandle icssEmacHandle, uint32_t ioctlCommand, uint8_t portNo, void *ioctlParams);

/**
* @brief  Function to  Load ICSS Switch params to pru memory
*
* @internal
*
* @param pruIcssHandle Provides PRUSS memory map
*
* @retval 0 on success
*/
uint8_t ICSSMacConfig(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);

/**
 *  @brief Function to  Load ICSS Switch params to pru memory for Host
 *
 * @param icssEmacHandle Provides PRUSS memory map
 *
 *  @return 0 on success
 *
 */
uint8_t ICSSHostConfig(ICSS_EmacHandle icssEmacHandle);

#ifdef __cplusplus
}
#endif

#endif /* __ICSS_EMAC_FWINIT_H_ */



