/*
 * aet_trigger_builders.h
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
 *  Created on: Jul 1, 2011
 *  =========================aet_trigger_builders.h=============================
 *  Revision Information
 *   Changed: $LastChangedDate: 2011-06-02 11:50:41 -0400 (Thu, 02 Jun 2011) $
 *   Revision: $LastChangedRevision: 10237 $
 *   Last Update By: $Author: DanRinkes $ 
 */

/*       1         2         3         4         5         6         7
12345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

/*
 #include directives
 */
#include <_aet.h>
#include <aet_resource.h>

#ifndef _AET_TRIGGER_BUILDERS
#define _AET_TRIGGER_BUILDERS


#ifdef __cplusplus
extern "C" {
#endif

/*
 #define directives
 */
#define _AET_NUM_TRIGGERS sizeof(AET_triggerBuilderDatabase)/sizeof(_AET_triggerBuilderInfo)

/*
 Structure Definitions and Typedefs
 */
typedef struct {
	uint32_t tbCntlValue;
	uint32_t tbOrsValue;
	uint16_t initLutValue;
	uint8_t trigsUsed;
}TB_SETTINGS;

typedef struct {
	TB_SETTINGS common;	// Common Settings
	uint16_t lutValue[1];
}TB_1_WIDE_SETTINGS;

typedef struct {
	TB_SETTINGS common;	// Common Settings
	uint16_t lutValue[3];
}TB_3_WIDE_SETTINGS;

typedef struct {
	TB_SETTINGS common;	// Common Settings
	uint16_t lutValue[7];
}TB_7_WIDE_SETTINGS;

typedef struct{
	TB_7_WIDE_SETTINGS tb_7_wide_settings[2];
	TB_3_WIDE_SETTINGS tb_3_wide_settings[6];
	TB_1_WIDE_SETTINGS tb_1_wide_settings[6];
}TB_SETTING_DATABASE;

/*
 Static data definitions
 */


/*
 Static function prototypes
 */

/*
 Module Function Definintions
 */
void _AET_initTbSettingsDB(void);
AET_error _AET_pgmTrigBldr(
					_AET_tbCntlParams*,
					AET_jobParams*
					);
uint16_t _AET_getTbBaseIndex(_AET_triggerBuilderType, uint8_t);
uint8_t _AET_getNumCexp(_AET_triggerBuilderType);
AET_error _AET_markTrigBldrForEnable(const _AET_triggerBuilderInfo*);
AET_error _AET_markEnableTb(const _AET_triggerBuilderInfo*);
AET_error enableTriggerBuilders();
AET_error _AET_pgmTbAddTrigger(_AET_tbCntlParams*, AET_jobParams*);
AET_error _AET_setTrigBldrBits(_AET_resourceStruct*,_AET_triggerBuilderType,uint8_t);
AET_error _AET_getTriggerBuilder(AET_triggerType, const _AET_triggerBuilderInfo**);
_AET_BOOL _AET_checkForTriggerOnJobTbs(AET_triggerType,
							_AET_resourceStruct*,
							_AET_triggerBuilderInfo*);
_AET_BOOL _AET_checkForTriggerOnTb(AET_triggerType,
							_AET_triggerBuilderType,
							uint8_t,
							_AET_triggerBuilderInfo*);

/*
 Static (internal) function definitions
 */


/*
 Revision History
 07/01/2011 - Initial Revision
 */

#ifdef __cplusplus
}
#endif


#endif
