/*
 * aet_add_trigger.h
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
 *  Created on: Jun 13, 2011
 *  ==============================aet_add_trigger.h=============================
 *  Revision Information
 *   Changed: $LastChangedDate: 2011-06-02 11:50:41 -0400 (Thu, 02 Jun 2011) $
 *   Revision: $LastChangedRevision: 10237 $
 *   Last Update By: $Author: DanRinkes $ 
 */

/*       1         2         3         4         5         6         7
12345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _AET_ADD_TRIGGER
#define _AET_ADD_TRIGGER

/*
 #include directives
 */
#include <aet_resource.h>


 #ifdef __cplusplus
 extern "C" {
 #endif

/*
 #define directives
 */

/*
 Structure Definitions and Typedefs
 */
typedef struct{
	const _AET_triggerBuilderInfo *trigBldr;	// Pointer to the trigger builder
	_AET_BOOL newTriggerBuilder;				// Add to an existing TB ?
	AET_jobParams* jobParams;
}AET_addTriggerResources;
/*
 Static data definitions
 */

/*
 Static function prototypes
 */

/*
 Module Function Definintions
 */
 AET_error _AET_addTrigger(AET_jobParams*);
 AET_error _AET_pgmAddTrigger(
		 AET_jobParams*,
		 AET_addTriggerResources*,
		 TB_SETTINGS*,
		 uint16_t*,
		 _AET_triggerBuilderInfo*
		 );


/*
 Static (internal) function definitions
 */

/*
 Revision History
 */

#ifdef __cplusplus
}
#endif


#endif
