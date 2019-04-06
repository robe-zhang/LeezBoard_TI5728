/*
 * aet_aeg_manager.h
 *
 * AET Library Public Definitions 
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
 *
 *  =============================aet_aeg_manager.h=============================
 *  Revision Information
 *   Changed: $LastChangedDate: 2013-01-18 15:47:09 -0600 (Fri, 18 Jan 2013) $
 *   Revision: $LastChangedRevision: 10598 $
 *   Last Update By: $Author: KarthikRamanaSankar $ 
 *  ===========================================================================
 */

#ifndef _AET_AEG_MANAGER
#define _AET_AEG_MANAGER

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
typedef struct {
	uint16_t evtNo;
	uint8_t numUsers;
}_AET_aegAllocation;

typedef struct {
	_AET_aegEventClass eventClass;
	_AET_aegAllocation aegAlloc[AET_NUM_AEG];
}_AET_aegDatabase;
/*
 Static data definitions
 */

/* 
 Static function prototypes
 */

/*
 Module Function Definintions
 */
AET_error _AET_allocateAllAegs(AET_jobParams*, uint8_t*);
AET_error _AET_allocateSingleAeg(uint16_t, uint8_t*, AET_evtTrigConfig);
AET_error _AET_deAllocateAllAegs(uint8_t);
AET_error _AET_deAllocateSingleAeg(uint8_t);
_AET_aegEventClass _AET_getEventClass(uint16_t);
void _AET_initAegResourceMgr();
AET_error _AET_programAeg(uint8_t, uint16_t, AET_evtTrigConfig);
void _AET_reclaimAegs(uint8_t aegsUsed);
AET_error _AET_validateAegParams(AET_jobParams*, _AET_aegEventClass*);


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
