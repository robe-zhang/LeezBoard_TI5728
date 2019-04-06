/*
 * aet.h
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
 *  =================================aet.h=====================================
 *  Revision Information
 *   Changed: $LastChangedDate: 2013-01-18 15:47:09 -0600 (Fri, 18 Jan 2013) $
 *   Revision: $LastChangedRevision: 10598 $
 *   Last Update By: $Author: KarthikRamanaSankar $
 *   
 *   Comment: updated the AET_ENABLE_RTOS_INT() macro to resolve a conflict with
 *            DSPTraceLib on claiming the TCU_CNTL unit
 *  ===========================================================================
 */
/**
 *  @file       aet.h
 *
 *  @brief      Application Access to Advanced Event Triggering Hardware
 */

/**
 *  @defgroup   AETLIB AETLIB - AET programming module
 *
 * <b> Platforms Supported </b>
 *   
 * - C6400
 * - C6400 Plus
 *
 *    
 * <b> Description </b>
 * 
 * This module allows users to program Advanced Event Triggering hardware 
 * from their application at run time.  This enables creation of trigger
 * events based on behavior of the application.  
 * 
 * 1. Usage Notes
 * - Typical call sequence
        - AET_init()  // Initialize module
        - AET_claim()   // Claims the AET unit for use
        - AET_setupJob()  // Submits an AET Job to be programmed
        - AET_enable()  // Enables programmed jobs
        - AET_releaseJob() // Clears a specified job
        - AET_release() // Releases the AET unit for use by the debugger  
 *
 *
 * 2. Resource Management
 *  The AET target library does some dynamic resource management to allow 
 *  multiple jobs to be programmed concurrently without resource conflicts.  The
 *  dynamic resource management is limited to allocation of Comparators and 
 *  Trigger Builders in watchpoint scenarios.  More complex jobs with various 
 *  resources are still statically assigned.  In order to most effectlvey use
 *  the resources available, it is wise to program the more complex jobs early, 
 *  and allow the dynamic resource allocation to fill in the less complex jobs.
 *
 * 2.a Triggering on Events (64x+)
 *  There are a number of events that can be triggered on in the 64x+ world.  
 *  These events can be useful for scenarios like capturing a PC with trace
 *  whenever an L2 data cache miss occurs. These events are listed in the 
 *  AET_eventNumber enumeration.  There are 3 categories of events, Memory,
 *  Stall, Miscellaneous.  A fourth category, System Events, is actually a 
 *  subset of miscellaneous events. However, only one of these 3 categories can
 *  be used at a time.  If a job is programmed using the Miscellanous events, 
 *  subsequently programming a job that uses a memory event will fail.  in order 
 *  to use a memory event, the job that uses the miscellaneous event must be 
 *  released using the AET_releaseJob function.  These categories are managed
 *  automatically on a forst programmed category basis.  For example: If a 
 *  memory event job is programmed first, all subsequent jobs must use memory 
 *  events until all existing memory event jobs are released. The return status
 *  will be AET_FINVALIDEVTCLASS for this failure scenario.
 * 
 * 3. Summary of Available Resources
 @verbatim
   =============================================================================
   |  RESOURCE                                                 |  64x  |  64x+ |
   =============================================================================
   | ADDRESS COMPARATOR                                        |   4   |   6*  |
   | DATA COMPARATOR                                           |   2   |   2   |
   | 1-WIDE TRIGGER BUILDER                                    |   6   |   6   |
   | 3-WIDE TRIGGER BUILDER                                    |   6   |   6   |
   | 7-WIDE TRIGGER BUILDER                                    |   2   |   2   |
   | COUNTER/TIMER                                             |   2   |   2   |
   | AUXILLIARY EVENT GENERATOR                                |   1   |   4   |
   | STATE MACHINE                                             |  1/2**|  1/2**|
   =============================================================================
   
   * On the 64x+, Address Comparators 4 & 5 are Program Address only
   ** The State Machines can be configured as 1 4-state machine or 2 2-state 
      machines
   
 @endverbatim
 *
 *
 * 4. Tools
 *
 * The following tools were used to build and test these libraries.
 @verbatim
  Software Tools:
  Codegen: v7.3.1
  Code Composer Studio 5.1.1
  
  Hardware:
   Spectrum Digital 6416DSK (64x)
   Spectrum Digital 6455DSK (64x+)
   Advantech EVMC6678L (66x)
 @endverbatim
 *  
 */
#ifndef _AET_H
#define _AET_H

/*@{*/

// Note - the version definitions must have the end of line immediately after the value (packaging script requirement)
#define AET_MAJOR_VERSION        (0x4)
                                               /*!< Major version number - Incremented for API changes*/
#define AET_MINOR_VERSION        (0x12)
                                               /*!< Minor version number - Incremented for bug fixes  */

/*
 #include directives 
 */
#include <stddef.h>
#include <stdint.h>
#include <c6x.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifndef _AET_DISABLE_TI_STD_TYPES
#ifndef _TI_STD_TYPES
typedef int8_t    Int8;
typedef uint8_t   Uint8;
typedef int16_t   Int16;
typedef uint16_t  Uint16;
typedef int32_t   Int32;
typedef uint32_t  Uint32;
typedef int40_t   Int40;
typedef uint40_t  Uint40;
typedef int64_t   Int64;
typedef uint64_t  Uint64;
typedef char      Char;
typedef int       Int;
typedef char      *String;
typedef void      *Ptr;
typedef unsigned short Bool;
#endif
#endif

/* 
 #define directives and enums 
 */

/*! \def ECU_CNTL
 *	@brief 
 */

#if defined(_TMS320C6400_PLUS) || defined(_TMS320C6600)
#define ECU_CNTL TCU_CNTL
#else
#define ECU_CNTL (*(int32_t*)0x1bc0134)
#endif

//
//#ifdef _TMS320C6400
//	#define ECU_CNTL (*(int32_t*)0x1bc0134)
//#endif


/*! \def AET_ENABLE_RTOS_INT()
	@brief Enables the AET RTOS Interrupt.  
 */

/*! \def AET_DISABLE_RTOS_INT()
	@brief Disables the AET Rtos Interrupt.
 */

/*! \def AET_CLEAR_RTOS_INT()
	@brief Clears the AET RTOS interrupt bit in the AET Interrupt Flag Register
 */

#define AET_ENABLE_RTOS_INT()                      \
{                                                \
    if ( (ECU_CNTL & 3) == 0 ) ECU_CNTL = 0x1;   \
    if ( (ECU_CNTL & 3) == 1 ) ECU_CNTL = 0x2;   \
    ECU_CNTL = 0x000A0000;                       \
}


#define AET_DISABLE_RTOS_INT()		                    \
{							    \
    ECU_CNTL = ((ECU_CNTL & ~0x00020000) | (0x00080000));   \
}

#define AET_CLEAR_RTOS_INT() 							\
{														\
	ECU_CNTL = 0x00A00000;							 	\
	*(int32_t*)0x1bc0020 = 0x00200000;					\
}


/* 
   ==========================================================================
    	                     TRACE STREAM CONTROLS 
   ========================================================================== 
*/

/* ==START TRIGGERS==*/
/**
	\def AET_TRACE_NONE
	No Triggers Specified
*/

/**
	\def AET_TRACE_TIMING
	Generate a Start Timing Trace Trigger
*/

/**
	\def AET_TRACE_PA
	Generate Start PC Trace Trigger
*/

/**
	\def AET_TRACE_RA
	Generate Start Read Address Trace Trigger
*/

/**
	\def AET_TRACE_WA
	Generate Start Write Address Trace Trigger
*/

/**
	\def AET_TRACE_RD
	Generate Start Read Data Trace Trigger
*/

/**
	\def AET_TRACE_WD
	Generate Start Write Data Trace Trigger
*/

/**
	\def AET_TRACE_PCTAG
	Generate Start PCTAG Trace Trigger
*/

/* 
 These two sets of triggers  (TRACE and TRACE STOP are completely separate and 
 should not be combined.  
 */

/*---------TRACE TRIGGERS---------------*/
#define AET_TRACE_NONE 			(0x0u)
#define AET_TRACE_TIMING 		(0x1u)
#define AET_TRACE_PA 	 		(0x2u)
#define AET_TRACE_RA 			(0x4u)
#define	AET_TRACE_WA 			(0x8u)
#define AET_TRACE_RD 			(0x10u)
#define AET_TRACE_WD 			(0x20u)
#define	AET_TRACE_PCTAG 		(0x40u)

/* ==STOP TRIGGERS==*/

/**
	\def AET_TRACE_STOP_PC
	Generate Stop PC Trace Trigger
*/

/**
	\def AET_TRACE_STOP_TIMING
	Generate Stop Timing Trace Trigger
*/

/**
	\def AET_TRACE_STOP_DATA
	Generate Stop Data Trace Trigger
*/
/*------TRACE STOP TRIGGERS-------------*/
#define	AET_TRACE_STOP_PC		(0x1u)
#define	AET_TRACE_STOP_TIMING	(0x2u)
#define AET_TRACE_STOP_DATA 	(0x4u)

/**
	\def AET_TRACE_STRM_ENBL_NONE
	Enable no streams
*/

/**
	\def AET_TRACE_STRM_ENBL_TIMING
	Enable the Trace Timing Stream
*/

/**
	\def AET_TRACE_STRM_ENBL_PC
	Enable the Program Address Trace Stream
*/

/**
	\def AET_TRACE_STRM_ENBL_MEM_RD
	Enable the Data Read Trace Stream
*/

/**
	\def AET_TRACE_STRM_ENBL_MEM_WT
	Enable the Data Write Trace Stream

	** Note that the stream enable configurations will NOT work when using 
	PIN trace through the XDS560 Trace cable.  This is only usable when 
	dumping the trace output to an Embedded Trace Buffer.  
*/

/* ==STREAM ENABLES== */
#define AET_TRACE_STRM_ENBL_NONE			(0x0u)
#define AET_TRACE_STRM_ENBL_TIMING		 	(0x1u)
#define AET_TRACE_STRM_ENBL_PC				(0x2u)
#define AET_TRACE_STRM_ENBL_MEM_RD			(0x4u)
#define AET_TRACE_STRM_ENBL_MEM_WT			(0x8u)

/**
	\def AET_TRACE_STRM_PRES_NONE
	No Streams are Present
*/

/**
	\def AET_TRACE_STRM_PRES_RD_DAT
	Read Data Stream Present
*/

/**
	\def AET_TRACE_STRM_PRES_RD_ADDR
	Read Address Stream Present
*/

/**
	\def AET_TRACE_STRM_PRES_RD_PC
	Read Program Counter Stream Present
*/

/**
	\def AET_TRACE_STRM_PRES_WT_DAT
	Write Data Stream Present
*/

/**
	\def AET_TRACE_STRM_PRES_WT_ADDR
	Write Address Stream Present
*/

/**
	\def AET_TRACE_STRM_PRES_WT_PC
	Write Program Counter Stream Present
*/

/* == STREAM PRESENT== */
#define AET_TRACE_STRM_PRES_NONE			(0x00u)
#define AET_TRACE_STRM_PRES_RD_DAT			(0x01u)
#define AET_TRACE_STRM_PRES_RD_ADDR			(0x02u)
#define AET_TRACE_STRM_PRES_RD_PC			(0x0Cu)
#define AET_TRACE_STRM_PRES_WT_DAT			(0x10u)
#define AET_TRACE_STRM_PRES_WT_ADDR			(0x20u)
#define AET_TRACE_STRM_PRES_WT_PC			(0x40u)


/**
 AET_traceTrigger
 Specifies the bitfields according to which triggers will be enabled
*/
typedef uint16_t AET_traceTrigger;

/* 
 The following assignments are used to return status
 when AET programmation is called
 */

/**
 * AET_error enumeration
 * Specifies a lise of potential error codes that the library can 
 * return to the user
 */
typedef enum {  
  AET_SOK = 0,      /*!< Programmation Succeeded */
  AET_FNOCLAIM,     /*!< Could not Claim AET Unit */
  AET_FNORELEASE,     /*!< Failed to Release AET Unit */
  AET_FNOTENABLED,    /*!< Failed to enable AET Unit */
  AET_FNOTAVAIL = 10,   /*!< Resources Not Available */
  AET_FNOTAVAILACMP,    /*!< Insufficient Address comparators */
  AET_FNOTAVAILAEG,   /*!< Insufficient Event Generators */
  AET_FNOTAVAILCNT,   /*!< Insufficient Counters */
  AET_FNOTAVAILDCMP,    /*!< Insufficient Data Comparators */
  AET_FNOTAVAILSM,    /*!< Insufficient State Machines */
  AET_FNOTAVAILTB1,   /*!< Insufficient 1-Wide Trigger Builders */
  AET_FNOTAVAILTB3,   /*!< Insufficient 3-Wide Trigger Builders */
  AET_FNOTAVAILTB7,   /*!< Insufficient 7-Wide Trigger Builders */
  AET_FNOTCLAIMED,    /*!< User has not claimed AET */
  AET_FNOCOUNTER,     /*!< Specified counter does not exist */
  AET_FNOJOBIMPLEMENTED,  /*!< This job type has not been implemented */ 
  AET_FMODENOTSUPPORTED,  /*!< Watermark timer mode not supported in 64x */
  AET_FJOBNOTPROGRAMMED,  /*!< Job specified does not exist */
  AET_FINVALIDCNTMODE,  /*!< Invalid counter mode has been specified */
  AET_FCNTNOTCONFIG,    /*!< The counter has not been configured */
  AET_FCNTCONFIGINVALID,  /*!< The counter is incorrectly configured */
  AET_FCNTNUMBERINVALID,  /*!< Invalid counter number specified */
  AET_FINVALIDTRIGBUILDER, /*!< Invalid Trigger Builder Specified */
  AET_FINVALIDTRIGMASK, /*!< Invalid trig mask calculated.  Should never happen */
  AET_FINVALIDREADWRITETYPE, /*!<Invalid Read/Write Type */
  AET_FJOBNOTSUPPORTED,   /*!< Job is not supported on this hardware */
  AET_FNOTAVAILAEGMUX,	/*!< Not enough available lines in AEGMUX */
  AET_FSIGNALOUTOFRANGE, /*!< The signal number passed is out of range */
  AET_FINVALIDTRACEOPT,	/*!< The trace option is invalid */
  AET_FNOTPCNTLCLAIM, /*!< Could not claim the Trace Port Control Register */
  AET_FINVALIDSIGVAL, /*!< Invalid signal number requested */
  AET_FNOEVENTSPECIFIED, /*!< No events specified in the AET_Params structure */
  AET_FINVALIDEVTCOMBO, /*!< The events specified are not all of the same class */
  AET_FINVALIDEVTCLASS, /*!< The event class does not match current setting */
  AET_FINVALIDEVTSPEC, /*!< One or more of the events specified is invalid */
  AET_FNOAEGUSERS,	/*!< Can't deallocate the AEG because there are no users */
  AET_NUM_FAIL_CODES    /*!< Number of implemented fail codes */
}AET_error;

/**
 AET_jobType enumerationn
 Specififes a list of Jobs that can be passed to the AET_setupJob
 function.  Not all of these jobs are currently implemented.
 */
typedef enum {
  AET_JOB_START_TRACE_NO_TRIGGER = 0,       
  AET_JOB_STOP_TRACE_NO_TRIGGER,
  AET_JOB_START_STOP_TRACE_ON_PC,
		  /*!< Trigger to Start/Stop Trace on a particular PC */
  AET_JOB_TRACE_IN_PC_RANGE,
		  /*!< Make Trace Active/Inactive in a PC Range */
  AET_JOB_TRACE_IN_DATA_RANGE,
		  /*!< Make Trace Active/Inactive when accessing a Data Range */
  AET_JOB_TRACE_ON_EVENTS,
		  /*!< Make Trace Active/Inactive when a specific event is high */
  AET_JOB_TRACE_BETWEEN_SEQ_EVENTS,
		  /*!< Make Trace Active/Inactive between two different sequential events */
  AET_JOB_TRIG_ON_PC,
          /*!< Watchpoint Trigger on Program Address */ 
  AET_JOB_TRIG_ON_PC_RANGE,
		  /*!< Watchpoint Trigger on Range of Program Addresses */
  AET_JOB_TRIG_ON_DATA,
          /*!< Watchpoint Trigger on Data Read/Write*/
  AET_JOB_TRIG_ON_DATA_RANGE,
          /*!< Watchpoint Trigger on Data Range Read/Write*/
  AET_JOB_TRIG_ON_DATA_WITH_VALUE,
          /*!< Watchpoint Trigger on Data Read/Write qualified by value*/
  AET_JOB_TRIG_ON_DATA_RANGE_WITH_VALUE,
		  /*!< Watchpoint Trigger on Data Range Read/Write qualified by value */
  AET_JOB_TRIG_ON_TIMER_ZERO,
		  /*!< Generate a trigger when one of the timers goes to zero */
  AET_JOB_TRIG_ON_EVENTS,
		  /*!< Generate a trigger when event(s) occur(s) */
  AET_JOB_ADD_TRIGGER,
  	  	  /*!< Add a trigger to an existing AET Job */
  AET_JOB_INTR_ON_STALL,
  	  	  /*!< Generate AET RTOS Interrupt on stall for user specified num of cycles */
  AET_JOB_COUNT_STALLS,
  	  	  /*!< Count number of stalls which exceed user specified num of cycles */
  AET_JOB_INTR_STALL_DURATION,
  	  	  /*!< Generate AET RTOS Interrupt on stall for user specified num of cycles,
  	  	   *   Inside AET ISR, one can exactly determine the duration of this stall
  	  	   *   whose duration is greater than user specified num of cycles */
#ifdef _TMS320C6400_PLUS
  AET_JOB_FUNC_PROFILE,
		  /*!< Generate a trace oneshot trigger on AEG events and a store 
		  	   sample on Write to address */
  AET_JOB_TIMER_START_ON_EVT,
          /*!< Start Timer on Specific Event*/
  AET_JOB_TIMER_STOP_ON_EVT,
          /*!< Stop Timer on Specific Event*/
  AET_JOB_WATERMARK_START_END,
          /*!< Start/Stop Watermark Window on specific event*/
#endif
  AET_JOB_NUM_JOBTYPES
}AET_jobType;

/**
 AET_triggerType enumerationn
 Specififes a list of events that can be triggered by AET
 */
typedef enum {
  AET_TRIG_NONE,		 /*!< No trigger Generated */
  AET_TRIG_HALT_CPU,        /*!<Halt the CPU */
  AET_TRIG_AINT,          /*!<RTOS Interrupt */
  AET_TRIG_WM0START,        /*!<Start Watermark 0 */
  AET_TRIG_WM0STOP,       /*!<Stop Watermark 0 */
  AET_TRIG_WM1START,        /*!<Start Watermark 1 */
  AET_TRIG_WM1STOP,       /*!<Stop Watermark 1 */
  AET_TRIG_CNT0_START,      /*!<Start Counter 0 */
  AET_TRIG_CNT0_STOP,       /*!<Stop Counter 0 */
  AET_TRIG_CNT1_START,      /*!<Start Counter 1 */
  AET_TRIG_CNT1_STOP,       /*!<Stop Counter 1 */
  AET_TRIG_ET0,         /*!<External Trigger 0 */
  AET_TRIG_ET1,         /*!<External Trigger 1 */
  AET_TRIG_TRACE_TRIGGER,     /*!<Trace Trigger */
  AET_TRIG_TRACE_END,       /*!<Trace End */
  AET_TRIG_TRACE_PCSTOP,      /*!<Stop PC Trace */
  AET_TRIG_TRACE_TIMINGSTOP,    /*!<Stop Timing Trace */
  AET_TRIG_TRACE_DATASTOP,     /*!<Stop Data Trace */
  AET_TRIG_STATE_0_TO_1,	/*!< State Machine 0-1 */
  AET_TRIG_STATE_0_TO_2,	/*!< State Machine 0-2 */
  AET_TRIG_STATE_0_TO_3,	/*!< State Machine 0-3 */
  AET_TRIG_STATE_1_TO_0,	/*!< State Machine 1-0 */
  AET_TRIG_STATE_1_TO_2,	/*!< State Machine 1-2 */
  AET_TRIG_STATE_1_TO_3,	/*!< State Machine 1-3 */
  AET_TRIG_STATE_2_TO_0,	/*!< State Machine 2-0 */
  AET_TRIG_STATE_2_TO_1,	/*!< State Machine 2-1 */
  AET_TRIG_STATE_2_TO_3,	/*!< State Machine 2-3 */
  AET_TRIG_STATE_3_TO_0,	/*!< State Machine 3-0 */
  AET_TRIG_STATE_3_TO_1,	/*!< State Machine 3-1 */
  AET_TRIG_STATE_3_TO_2,		/*!< State Machine 3-2 */
  AET_TRIG_TRACE_STORE_TIMING,
  AET_TRIG_TRACE_STORE_PC,
  AET_TRIG_TRACE_STORE_RA,
  AET_TRIG_TRACE_STORE_WA,
  AET_TRIG_TRACE_STORE_RD,
  AET_TRIG_TRACE_STORE_WD,
  AET_TRIG_TRACE_STORE_PCTAG,
  AET_TRIG_TRACE_START_TIMING,
  AET_TRIG_TRACE_START_PC,
  AET_TRIG_TRACE_START_RA,
  AET_TRIG_TRACE_START_WA,
  AET_TRIG_TRACE_START_RD,
  AET_TRIG_TRACE_START_WD,
  AET_TRIG_TRACE_START_PCTAG,
  AET_TRIG_TRACE_PCSUSPEND,
  AET_TRIG_TRACE_TIMINGSUSPEND,
  AET_TRIG_TRACE_DATASUSPEND
}AET_triggerType;


/**
  AET_refSize enumeration
  Specifies the reference size when using a trigger on data scenario or 
  trigger on data range scenario.  The triggers are set up to catch any
  size read or write.  The reference size determines the distance from 
  the given address that will generate a trigger
  
  @verbatim


  Examples:
  Address = 0x80010000, Reference Size = Byte
  Trigger Generated on Read/Write access to byte address 0x80010000 only

  Address = 0x80010000, Reference Size = Halfword
  Trigger Generated on Read/Write access to byte addresses 0x80010000-0x80010001

  Address = 0x80010000, Reference Size = Word
  Trigger Generated on Read/Write access to byte addresses 0x80010000-0x80010003

  Address = 0x80010000, Reference Size = Double Word
  Trigger Generated on Read/Write access to byte addresses 0x80010000-0x80010007
  @endverbatim
  */

typedef enum {
  AET_REF_SIZE_BYTE = 0x0,    /*!<8-bits */
  AET_REF_SIZE_HALFWORD = 0x1,  /*!<16-bits */
  AET_REF_SIZE_WORD = 0x2,    /*!<32-bits */
  AET_REF_SIZE_DOUBLEWORD = 0x3 /*!<64-bits */
}AET_refSize;

/**
 AET_watchReadWrite enumeration
 Specifies reads/writes in watchpoint scenarios
 */
typedef enum {
  AET_WATCH_WRITE = 0,      /*!<Watch for a write */
  AET_WATCH_READ = 1        /*!<Watch for a read */
}AET_watchReadWrite;

/**
 AET_counterConfig enumeration
 Allows specification of both the operating mode and the timer/counter mode of 
 the counter/timer resource.  This has been added to replace separate 
 configurations.
 */
typedef enum {
  AET_COUNTER_TRAD_COUNTER = 0,
      /*!<Traditional Operating Mode + Counter Mode */
  AET_COUNTER_TRAD_EVENT,
      /*!<Traditional Operating Mode + Event Counter Mode */
  AET_COUNTER_TRAD_CONTINUOUS,
      /*!<Traditional Operating Mode + Countiuous Timer Mode */
  AET_COUNTER_TRAD_ONESHOT,
      /*!<Traditional Operating Mode + One Shot Timer Mode */
  AET_COUNTER_MINWM_COUNTER,
      /*!<MIN Watermark Operating Mode + Counter Mode */
  AET_COUNTER_MINWM_EVENT,
      /*!<MIN Watermark Operating Mode + Event Counter Mode */
  AET_COUNTER_MINWM_CONTINUOUS,
      /*!<MIN Watermark Operating Mode + Continuous Timer Mode*/
  AET_COUNTER_MINWM_ONESHOT,
      /*!<MIN Watermark Operating Mode + One Shot Timer Mode */
  AET_COUNTER_MAXWM_COUNTER,
      /*!<MAX Watermark Operating Mode + Counter Mode */
  AET_COUNTER_MAXWM_EVENT,
      /*!<MAX Watermark Operating Mode + Event Counter Mode */
  AET_COUNTER_MAXWM_CONTINUOUS,
      /*!<MAX Watermark Operating Mode + Continuous Timer Mode*/
  AET_COUNTER_MAXWM_ONESHOT,
      /*!<MAX Watermark Operating Mode + One Shot Timer Mode */
  AET_COUNTER_NOTCONFIGURED,
      /*!<Counter Not Currently Configured */
  AET_NUM_COUNTER_CONFIGS
      /*!<Total Number of Counter Configurations */
}AET_counterConfig;

/**
 AET_traceCacheProfilingMode enumeration
 Allows specification of the Cache Progiling mode for Trace.  The default mode
 is normal mode.  
 */
typedef enum {
	AET_TRACE_CACHE_PROFILING_NORMAL = 0, 	/*!<Normal Mode */
	AET_TRACE_CACHE_PROFILING_EXTERNAL,		/*!<External Event Profiling */
	AET_TRACE_CACHE_PROFILING_PREDICATION, 	/*!<Predication Event Profiling */
	AET_TRACE_CACHE_PROFILING_RSVD_3, 		/*!<Reserved */
	AET_TRACE_CACHE_PROFILING_GENERIC, 		/*!<Generic: LSS/AEP mode only */
	AET_TRACE_CACHE_PROFILING_PRIORITIZED, 	/*!<Prioritized: LSS/AEP mode only */
	AET_TRACE_CACHE_PROFILING_RSVD_6, 		/*!<Reserved */
	AET_TRACE_CACHE_PROFILING_RSVD_7 		/*!<Reserved */
}AET_traceCacheProfilingMode;

/** AET_counters
 Lists the names of the counters/timers available to AET.  
 */
typedef enum {
  AET_CNT_0 = 0,  /*!<Counter 0 */
  AET_CNT_1 = 1,  /*!<Counter 1 */
  AET_NUM_AET_CNT 
}AET_counters;


/** AET_watermarkAction
 Specifies the action for the watermark counter to perform.
 */
typedef enum {
  AET_WATERMARK_START = 0,  /*!<Start the Watermark Window */
  AET_WATERMARK_STOP      /*!<Stop the Watermark Window */
}AET_watermarkAction;


/** AET_traceActive
 Specifies whether to start or stop tracing 
 */
typedef enum {
  AET_TRACE_INACTIVE = 0,		/* Make Trace Inactve */
  AET_TRACE_ACTIVE				/* Make Trace Active  */
}AET_traceActive;



/** AET_triggerLogicOrientation
 Specifies if the logic for the trigger builder is straightforward or
 inverted.  (eg. for Trigger on PC in range, Straighforward triggers
 when the PC is in range.  Inverted triggers when the PC is outside of the range
 */
typedef enum {
  AET_TRIG_LOGIC_STRAIGHTFORWARD,
  AET_TRIG_LOGIC_INVERTED
}AET_triggerLogicOrientation;

typedef enum {
	AET_EVT_TRIG_EDGE_TO_HI = 0x2cc,
	AET_EVT_TRIG_EDGE_TO_LO = 0x2aa,
	AET_EVT_TRIG_BOTH_EDGES = 0x2ee,
	AET_EVT_TRIG_LEVEL_HI = 0x0cc,
	AET_EVT_TRIG_LEVEL_LO = 0x0aa,
	AET_EVT_TRIG_LEVEL_DEFAULT = 0x244
}AET_evtTrigConfig;

/** AET_stateQual
 Specifies a state machine state to qualify the job with
 */
typedef enum {
  AET_STATEQUAL_STATE0 = 0x0,
  AET_STATEQUAL_STATE1,
  AET_STATEQUAL_STATE2,
  AET_STATEQUAL_STATE3,
  AET_STATEQUAL_NONE
}AET_stateQual;

#ifdef _TMS320C6400_PLUS
typedef enum {
	AET_TB_ESAC_CNT0 = 0,
	AET_TB_ESAC_CNT1,
	AET_TB_EXAC_TRCTRIG
}_AET_trigBldrEventCSelect;


#else
typedef enum {
	AET_TB_ESAC_NONE = 0,
	AET_TB_ESAC_CNT0 = 4,
	AET_TB_ESAC_CNT1,
	AET_TB_ESAC_AUX0,
	AET_TB_ESAC_TRIG
}_AET_trigBldrEventCSelect;

#endif



/**
	\def AET_NUMSYSEVTS
	Number of total possible system events
*/

/**
	\def AET_NUMGEMEVTS
	Number of total possible GEM events
*/

/**
	\def AET_NUMGEMMEMEVTS
	Number of total possible GEMMemory Events
*/

/**
	\def AET_NUMGEMSTALLEVTS
	Number of total possible GEM Stall events
*/

/**
	\def AET_NUMGEMMISCEVTS
	Number of total possible GEM Miscellaneous events
*/

/**
	\def AET_NUM_EXT_EVTS
	Number of total possible External GEM events
*/

/**
	\def AET_GEM_EVT_START
	Index where Gem Events Start
*/

/**
	\def AET_GEM_EVT_END
	Index where Gem Events End
*/

/**
	\def AET_GEM_MEM_EVT_START
	Index where Gem Memory Events Start
*/

/**
	\def AET_GEM_MEM_EVT_END
	Index where Gem Memory Events End
*/

/**
	\def AET_GEM_STALL_EVT_START
	Index where Gem Stall Events Start
*/

/**
	\def AET_GEM_STALL_EVT_END
	Index where Gem Stall Events End
*/

/**
	\def AET_GEM_MISC_EVT_START
	Index where Gem Miscellaneous Events Start
*/

/**
	\def AET_GEM_MISC_EVT_END
	Index where Gem Events End
*/

/**
	\def AET_EVT_NONE
	No Event
*/

#define AET_NUMSYSEVTS    	128
#define AET_NUMGEMEVTS		128
#define AET_NUMGEMMEMEVTS 	32
#define AET_NUMGEMSTALLEVTS 	32
#define AET_NUMGEMMISCEVTS  	32
#define AET_NUM_EXT_EVTS 	AET_NUMSYSEVTS + AET_NUMGEMEVTS

#define AET_GEM_EVT_START 	AET_NUMSYSEVTS 
#define AET_GEM_EVT_END		AET_GEM_EVT_START + AET_NUMGEMEVTS-1 

#define AET_GEM_MEM_EVT_START   AET_GEM_EVT_START+AET_NUMGEMEVTS
#define AET_GEM_MEM_EVT_END	AET_GEM_MEM_EVT_START+AET_NUMGEMMEMEVTS-1

#define AET_GEM_STALL_EVT_START AET_GEM_MEM_EVT_START+AET_NUMGEMMEMEVTS
#define AET_GEM_STALL_EVT_END 	AET_GEM_STALL_EVT_START+AET_NUMGEMSTALLEVTS-1

#define AET_GEM_MISC_EVT_START  AET_GEM_STALL_EVT_START+AET_NUMGEMSTALLEVTS
#define AET_GEM_MISC_EVT_END	AET_GEM_MISC_EVT_START+AET_NUMGEMMISCEVTS-1
#define AET_EVT_NONE			0xFFFF

/*******************************************************************************
                                GEM Events
*******************************************************************************/
#define AET_GEM_EVT_EXCEP							(AET_GEM_EVT_START + 64)
/**
	\def AET_GEM_EVT_EXCEP
	CPU Exception
*/		
#define AET_GEM_EVT_NMI								(AET_GEM_EVT_START + 65)
/**
	\def AET_GEM_EVT_NMI
	Non-maskable CPU Interrupt
*/
#define AET_GEM_CPUINT_4							(AET_GEM_EVT_START + 68)
/**
	\def AET_GEM_CPUINT_4 
	CPU Interrupt 4
*/
#define AET_GEM_CPUINT_5							(AET_GEM_EVT_START + 69)
/**
	\def AET_GEM_CPUINT_5 
	CPU Interrupt 5
*/
#define AET_GEM_CPUINT_6							(AET_GEM_EVT_START + 70)
/**
	\def AET_GEM_CPUINT_6
	CPU Interrupt 6
*/
#define AET_GEM_CPUINT_7							(AET_GEM_EVT_START + 71)
/**
	\def AET_GEM_CPUINT_7
	CPU Interrupt 7
*/
#define AET_GEM_CPUINT_8							(AET_GEM_EVT_START + 72)
/**
	\def AET_GEM_CPUINT_8
	CPU Interrupt 8
*/
#define AET_GEM_CPUINT_9							(AET_GEM_EVT_START + 73)
/**
	\def AET_GEM_CPUINT_9
	CPU Interrupt 9
*/
#define AET_GEM_CPUINT_10							(AET_GEM_EVT_START + 74)
/**
	\def AET_GEM_CPUINT_10
	CPU Interrupt 10
*/
#define AET_GEM_CPUINT_11							(AET_GEM_EVT_START + 75)
/**
	\def AET_GEM_CPUINT_11
	CPU Interrupt 11
*/
#define AET_GEM_CPUINT_12							(AET_GEM_EVT_START + 76)
/**
	\def AET_GEM_CPUINT_12
	CPU Interrupt 12
*/
#define AET_GEM_CPUINT_13							(AET_GEM_EVT_START + 77)
/**
	\def AET_GEM_CPUINT_13
	CPU Interrupt 13
*/
#define AET_GEM_CPUINT_14							(AET_GEM_EVT_START + 78)
/**
	\def AET_GEM_CPUINT_14
	CPU Interrupt 14
*/
#define AET_GEM_CPUINT_15							(AET_GEM_EVT_START + 79)
/**
	\def AET_GEM_CPUINT_15
	CPU Interrupt 15
*/
#define AET_GEM_IACK								(AET_GEM_EVT_START + 96)
/**
	\def AET_GEM_IACK
	Interrupt Acknowledge (Any Interrupt)
*/
#define AET_GEM_EACK								(AET_GEM_EVT_START + 97)
/**
	\def AET_GEM_EACK
	Exception Acknowledge for either EXCEP or NMI
*/
#define AET_GEM_IACK_4								(AET_GEM_EVT_START + 100)
/**
	\def AET_GEM_IACK_4
	Interrupt Acknowledge for CPU Interrupt 4
*/
#define AET_GEM_IACK_5								(AET_GEM_EVT_START + 101)
/**
	\def AET_GEM_IACK_5
	Interrupt Acknowledge for CPU Interrupt 5
*/
#define AET_GEM_IACK_6								(AET_GEM_EVT_START + 102)
/**
	\def AET_GEM_IACK_6
	Interrupt Acknowledge for CPU Interrupt 6
*/
#define AET_GEM_IACK_7								(AET_GEM_EVT_START + 103)
/**
	\def AET_GEM_IACK_7
	Interrupt Acknowledge for CPU Interrupt 7
*/
#define AET_GEM_IACK_8								(AET_GEM_EVT_START + 104)
/**
	\def AET_GEM_IACK_8
	Interrupt Acknowledge for CPU Interrupt 8
*/
#define AET_GEM_IACK_9								(AET_GEM_EVT_START + 105)
/**
	\def AET_GEM_IACK_9
	Interrupt Acknowledge for CPU Interrupt 9
*/
#define AET_GEM_IACK_10								(AET_GEM_EVT_START + 106)
/**
	\def AET_GEM_IACK_10
	Interrupt Acknowledge for CPU Interrupt 10
*/
#define AET_GEM_IACK_11								(AET_GEM_EVT_START + 107)
/**
	\def AET_GEM_IACK_11
	Interrupt Acknowledge for CPU Interrupt 11
*/
#define AET_GEM_IACK_12								(AET_GEM_EVT_START + 108)
/**
	\def AET_GEM_IACK_12
	Interrupt Acknowledge for CPU Interrupt 12
*/
#define AET_GEM_IACK_13								(AET_GEM_EVT_START + 109)
/**
	\def AET_GEM_IACK_13
	Interrupt Acknowledge for CPU Interrupt 13
*/
#define AET_GEM_IACK_14								(AET_GEM_EVT_START + 110)
/**
	\def AET_GEM_IACK_14
	Interrupt Acknowledge for CPU Interrupt 14
*/
#define AET_GEM_IACK_15								(AET_GEM_EVT_START + 111)
/**
	\def AET_GEM_IACK_15
	Interrupt Acknowledge for CPU Interrupt 15
*/

/*******************************************************************************
                              Memory Events
*******************************************************************************/
#define AET_EVT_MEM_L1D_RH_SRAM_A                   (AET_GEM_MEM_EVT_START + 0)
/**
	\def AET_EVT_MEM_L1D_RH_SRAM_A
	L1D Read Hit SRAM A
*/
#define AET_EVT_MEM_L1D_RH_SRAM_B                   (AET_GEM_MEM_EVT_START + 1)
/**
	\def AET_EVT_MEM_L1D_RH_SRAM_B
	L1D Read Hit SRAM B
*/
#define AET_EVT_MEM_L1D_RH_CACHE_A                  (AET_GEM_MEM_EVT_START + 2)
/**
	\def AET_EVT_MEM_L1D_RH_CACHE_A
	L1D Read Hit Cache A
*/
#define AET_EVT_MEM_L1D_RH_CACHE_B                  (AET_GEM_MEM_EVT_START + 3)
/**
	\def AET_EVT_MEM_L1D_RH_CACHE_B
	L1D Read Hit Cache B
*/
#define AET_EVT_MEM_L1D_WH_BUF_NOT_FULL_A           (AET_GEM_MEM_EVT_START + 4)
/**
	\def AET_EVT_MEM_L1D_WH_BUF_NOT_FULL_A
	L1D Write Hit, Tag Buffer Not Full A
*/
#define AET_EVT_MEM_L1D_WH_BUF_NOT_FULL_B           (AET_GEM_MEM_EVT_START + 5)
/**
	\def AET_EVT_MEM_L1D_WH_BUF_NOT_FULL_B
	L1D Write Hit, Tag Buffer Not Full B
*/
#define AET_EVT_MEM_L1D_WH_BUF_FULL_A               (AET_GEM_MEM_EVT_START + 6)
/**
	\def AET_EVT_MEM_L1D_WH_BUF_FULL_A
	L1D Write Hit, Tag Buffer Full A
*/
#define AET_EVT_MEM_L1D_WH_BUF_FULL_B		    (AET_GEM_MEM_EVT_START + 7)
/**
	\def AET_EVT_MEM_L1D_WH_BUF_FULL_B
	L1D Write Hit, Tag Buffer Full B
*/
#define AET_EVT_MEM_L1D_RM_HITS_L2_SRAM_A           (AET_GEM_MEM_EVT_START + 8)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_L2_SRAM_A
	L1D Read Miss, Hits L2 SRAM A
*/
#define AET_EVT_MEM_L1D_RM_HITS_L2_SRAM_B           (AET_GEM_MEM_EVT_START + 9)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_L2_SRAM_B
	L1D Read Miss, Hits L2 SRAM B
*/
#define AET_EVT_MEM_L1D_RM_HITS_L2_CACHE_A          (AET_GEM_MEM_EVT_START + 10)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_L2_CACHE_A
	L1D Read Miss, Hits L2 Cache A
*/
#define AET_EVT_MEM_L1D_RM_HITS_L2_CACHE_B          (AET_GEM_MEM_EVT_START + 11)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_L2_CACHE_B
	L1D Read Miss, Hits L2 Cache B
*/
#define AET_EVT_MEM_L1D_RM_HITS_EXT_CABLE_A         (AET_GEM_MEM_EVT_START + 12)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_EXT_CABLE_A
	L1D Read Miss, Hits External, Cacheable A
*/
#define AET_EVT_MEM_L1D_RM_HITS_EXT_CABLE_B         (AET_GEM_MEM_EVT_START + 13)	
/**
	\def AET_EVT_MEM_L1D_RM_HITS_EXT_CABLE_B
	L1D Read Miss, Hits External, Cacheable B
*/
#define AET_EVT_MEM_L1D_RM_HITS_EXT_NON_CABLE_A     (AET_GEM_MEM_EVT_START + 14)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_EXT_NON_CABLE_A
	L1D Read Miss, Hits External, Non Cacheable A
*/
#define AET_EVT_MEM_L1D_RM_HITS_EXT_NON_CABLE_B     (AET_GEM_MEM_EVT_START + 15)
/**
	\def AET_EVT_MEM_L1D_RM_HITS_EXT_NON_CABLE_B
	L1D Read Miss, Hits External, Non Cacheable B
*/
#define AET_EVT_MEM_L1D_WM_WRT_BUF_NOT_FULL_A       (AET_GEM_MEM_EVT_START + 16)
/**
	\def AET_EVT_MEM_L1D_WM_WRT_BUF_NOT_FULL_A
	L1D Write Miss, Write Buffer Not Full A
*/
#define AET_EVT_MEM_L1D_WM_WRT_BUF_NOT_FULL_B       (AET_GEM_MEM_EVT_START + 17)
/**
	\def AET_EVT_MEM_L1D_WM_WRT_BUF_NOT_FULL_B
	L1D Write Miss, Write Buffer Not Full B
*/
#define AET_EVT_MEM_L1D_WM_WRT_BUF_FULL_A           (AET_GEM_MEM_EVT_START + 18)
/**
	\def AET_EVT_MEM_L1D_WM_WRT_BUF_FULL_A
	L1D Write Miss, Write Buffer Full A
*/
#define AET_EVT_MEM_L1D_WM_WRT_BUF_FULL_B           (AET_GEM_MEM_EVT_START + 19)
/**
	\def AET_EVT_MEM_L1D_WM_WRT_BUF_FULL_B
	L1D Write Miss, Write Buffer Full B
*/
#define AET_EVT_MEM_L1D_WM_TAG_VIC_WRT_BUF_FLUSH_A  (AET_GEM_MEM_EVT_START + 20)
/**
	\def AET_EVT_MEM_L1D_WM_TAG_VIC_WRT_BUF_FLUSH_A
	L1D Write Miss, Tag/Victim/Write Buffer Flush A
*/
#define AET_EVT_MEM_L1D_WM_TAG_VIC_WRT_BUF_FLUSH_B  (AET_GEM_MEM_EVT_START + 21)
/**
	\def AET_EVT_MEM_L1D_WM_TAG_VIC_WRT_BUF_FLUSH_B
	L1D Write Miss, Tag/Victim/Write Buffer Flush B
*/
#define AET_EVT_MEM_CPU_CPU_BANK_CONFLICT           (AET_GEM_MEM_EVT_START + 22)
/**
	\def AET_EVT_MEM_CPU_CPU_BANK_CONFLICT
	CPU - CPU Bank Conflict
*/
#define AET_EVT_MEM_CPU_SNOOP_CONFLICT              (AET_GEM_MEM_EVT_START + 23)
/**
	\def AET_EVT_MEM_CPU_SNOOP_CONFLICT
	CPU - Snoop/Coherence Conflict (A or B)
*/
#define AET_EVT_MEM_CPU_IDMA_EDMA_BANK_CONFLICT     (AET_GEM_MEM_EVT_START + 24)
/**
	\def AET_EVT_MEM_CPU_IDMA_EDMA_BANK_CONFLICT
	CPU - iDMA/EDMA Bank Conflict (A or B)
*/
#define AET_EVT_MEM_L1P_RH_SRAM                     (AET_GEM_MEM_EVT_START + 25)
/**
	\def AET_EVT_MEM_L1P_RH_SRAM
	L1P Read Hit SRAM
*/
#define AET_EVT_MEM_L1P_RH_CACHE                    (AET_GEM_MEM_EVT_START + 26)
/**
	\def AET_EVT_MEM_L1P_RH_CACHE
	L1P Read Hit Cache
*/
#define AET_EVT_MEM_L1P_RM_HITS_L2_SRAM             (AET_GEM_MEM_EVT_START + 27)
/**
	\def AET_EVT_MEM_L1P_RM_HITS_L2_SRAM
	L1P Read Miss, Hits L2 SRAM
*/
#define AET_EVT_MEM_L1P_RM_HITS_L2_CACHE            (AET_GEM_MEM_EVT_START + 28)
/**
	\def AET_EVT_MEM_L1P_RM_HITS_L2_CACHE
	L1P Read Miss, Hits L2 Cache
*/
#define AET_EVT_MEM_L1P_RM_HITS_EXT_CABLE           (AET_GEM_MEM_EVT_START + 29)
/**
	\def AET_EVT_MEM_L1P_RM_HITS_EXT_CABLE
	L1P Read Miss, Hits External Cacheable
*/

/*
#define AET_EVT_MEM_RESERVED_30                     (AET_GEM_MEM_EVT_START + 30)
#define AET_EVT_MEM_RESERVED_31                     (AET_GEM_MEM_EVT_START + 31)
*/

/*******************************************************************************
                              StallEvents
*******************************************************************************/
#define AET_EVT_STALL_CPU_PIPELINE                (AET_GEM_STALL_EVT_START + 0)
/**
	\def AET_EVT_STALL_CPU_PIPELINE
	CPU Stall Cycles
*/
#define AET_EVT_STALL_CROSS_PATH                  (AET_GEM_STALL_EVT_START + 1)
/**
	\def AET_EVT_STALL_CROSS_PATH
	Stall Due to a Cross path
*/
#define AET_EVT_STALL_BRANCH_TO_SPAN_EXEC_PKT     (AET_GEM_STALL_EVT_START + 2)
/**
	\def AET_EVT_STALL_BRANCH_TO_SPAN_EXEC_PKT
	Stall due to a branch to an execute packet that spans two fetch packets
*/
#define AET_EVT_STALL_EXT_FUNC_IFACE              (AET_GEM_STALL_EVT_START + 3)
/**
	\def AET_EVT_STALL_EXT_FUNC_IFACE
	Stall due to an External Functional Interface
*/
#define AET_EVT_STALL_MVC                         (AET_GEM_STALL_EVT_START + 4)
/**
	\def AET_EVT_STALL_MVC
	Stall Conditions:
	   1) AMR write followed by addressing mode instruction and src2 register is 
	      affected by AMR Values
	   2) Read of emulation registers in the ECM
*/
#define AET_EVT_STALL_L1P_OTHER                   (AET_GEM_STALL_EVT_START + 5)
/**
	\def AET_EVT_STALL_L1P_OTHER
	Any other stall not prwviously listed
*/
#define AET_EVT_STALL_L1P_WAIT_STATE              (AET_GEM_STALL_EVT_START + 6)
/**
	\def AET_EVT_STALL_L1P_WAIT_STATE 
	Stall due to Wait states in L1P Memory
*/
/*
#define AET_EVT_STALL_RESERVED_7                  (AET_GEM_STALL_EVT_START + 7)
*/
#define AET_EVT_STALL_L1P_MISS                    (AET_GEM_STALL_EVT_START + 8)
/**
	\def AET_EVT_STALL_L1P_MISS 
	Execute Packed held off due to a Cache Miss
*/
/*
#define AET_EVT_STALL_RESERVED_9                  (AET_GEM_STALL_EVT_START + 9)
*/
#define AET_EVT_STALL_L1D_OTHER                   (AET_GEM_STALL_EVT_START + 10)
/**
	\def AET_EVT_STALL_L1D_OTHER 
	Any other L1D Stall not previosuly listed
*/
#define AET_EVT_STALL_L1D_BANK_CONFLICT           (AET_GEM_STALL_EVT_START + 11)
/**
	\def AET_EVT_STALL_L1D_BANK_CONFLICT 
	Stall on a memory bank conflict between A and B
*/
#define AET_EVT_STALL_L1D_DMA_CONFLICT            (AET_GEM_STALL_EVT_START + 12)
/**
	\def AET_EVT_STALL_L1D_DMA_CONFLICT 
	Stall while CPU access is held off by a DMA Access
*/
#define AET_EVT_STALL_L1D_WRITE_BUFFER_FULL       (AET_GEM_STALL_EVT_START + 13)
/**
	\def AET_EVT_STALL_L1D_WRITE_BUFFER_FULL 
	Stall on a write miss on A or B while the Write Buffer is Full
*/
#define AET_EVT_STALL_L1D_TAG_UD_BUF_FULL         (AET_GEM_STALL_EVT_START + 14)
/**
	\def AET_EVT_STALL_L1D_TAG_UD_BUF_FULL 
	Stall on a Write Hit with a tag update on either A or B while the tag update
	buffer is full
*/
#define AET_EVT_STALL_L1D_LINE_FILL_B             (AET_GEM_STALL_EVT_START + 15)
/**
	\def AET_EVT_STALL_L1D_LINE_FILL_B 
  Stall on a read miss on B while the read miss data is being fetched from the 
  lower memory level
*/
#define AET_EVT_STALL_L1D_LINE_FILL_A             (AET_GEM_STALL_EVT_START + 16)
/**
	\def AET_EVT_STALL_L1D_LINE_FILL_A
  Stall on a read miss on A while the read miss data is being fetched from the 
  lower memory level
*/
#define AET_EVT_STALL_L1D_WRT_BUF_FLUSH           (AET_GEM_STALL_EVT_START + 17)
/**
	\def AET_EVT_STALL_L1D_WRT_BUF_FLUSH
  Stall on a read Miss on Either A or B while the Write Buffer is being flushed
*/
#define AET_EVT_STALL_L1D_VICTIM_BUF_FLUSH        (AET_GEM_STALL_EVT_START + 18)
/**
	\def AET_EVT_STALL_L1D_VICTIM_BUF_FLUSH
  Stall on a read miss on either A or B while the Victim Buffer is being flushed
*/
/*
#define AET_EVT_STALL_RESERVED_19                 (AET_GEM_STALL_EVT_START + 19)
*/
#define AET_EVT_STALL_L1D_TAG_UD_BUF_FLUSH        (AET_GEM_STALL_EVT_START + 20)
/**
	\def AET_EVT_STALL_L1D_TAG_UD_BUF_FLUSH
  Stall on a read miss on either A or B while the Tag Update Buffer is being 
  flushed
*/
#define AET_EVT_STALL_L1D_SNOOP_CONFLICT          (AET_GEM_STALL_EVT_START + 21)
/**
	\def AET_EVT_STALL_L1D_SNOOP_CONFLICT
  Stall while a CPU access is held off by a Snoop access
*/
#define AET_EVT_STALL_L1D_COH_OP_CONFLICT         (AET_GEM_STALL_EVT_START + 22)
/**
	\def AET_EVT_STALL_L1D_COH_OP_CONFLICT
  Stall while a CPU access is held off by a block cache coherence operation 
  access
*/
/*
#define AET_EVT_STALL_RESERVED_23                 (AET_GEM_STALL_EVT_START + 23)
#define AET_EVT_STALL_RESERVED_24                 (AET_GEM_STALL_EVT_START + 24)
#define AET_EVT_STALL_RESERVED_25                 (AET_GEM_STALL_EVT_START + 25)
#define AET_EVT_STALL_RESERVED_26                 (AET_GEM_STALL_EVT_START + 26)
#define AET_EVT_STALL_RESERVED_27                 (AET_GEM_STALL_EVT_START + 27)
#define AET_EVT_STALL_RESERVED_28                 (AET_GEM_STALL_EVT_START + 28)
#define AET_EVT_STALL_RESERVED_29                 (AET_GEM_STALL_EVT_START + 29)
#define AET_EVT_STALL_RESERVED_30                 (AET_GEM_STALL_EVT_START + 30)
#define AET_EVT_STALL_RESERVED_31                 (AET_GEM_STALL_EVT_START + 31)
*/

/*******************************************************************************
                          Miscellaneous Events
*******************************************************************************/
#define AET_EVT_MISC_EXEC_CYCLES                  (AET_GEM_MISC_EVT_START + 0)
/**
	\def AET_EVT_MISC_EXEC_CYCLES
	Execute Cycle Event
*/
#define AET_EVT_MISC_STALL_PIPELINE               (AET_GEM_MISC_EVT_START + 1)
/**
	\def AET_EVT_MISC_STALL_PIPELINE
	Pipeline Stall Event
*/
#define AET_EVT_MISC_MARK_INS_0                   (AET_GEM_MISC_EVT_START + 2)
/**
	\def AET_EVT_MISC_MARK_INS_0
	Mark Instruction Id 0 Event
*/
#define AET_EVT_MISC_MARK_INS_1                   (AET_GEM_MISC_EVT_START + 3)
/**
	\def AET_EVT_MISC_MARK_INS_1
	Mark Instruction Id 1 Event
*/
#define AET_EVT_MISC_MARK_INS_2                   (AET_GEM_MISC_EVT_START + 4)
/**
	\def AET_EVT_MISC_MARK_INS_2
	Mark Instruction Id 2 Event
*/
#define AET_EVT_MISC_MARK_INS_3                   (AET_GEM_MISC_EVT_START + 5)
/**
	\def AET_EVT_MISC_MARK_INS_3
	Mark Instruction Id 3 Event
*/
#define AET_EVT_MISC_ET0                          (AET_GEM_MISC_EVT_START + 6)
/**
	\def AET_EVT_MISC_ET0
	External Trigger 0
*/
#define AET_EVT_MISC_ET1                          (AET_GEM_MISC_EVT_START + 7)
/**
	\def AET_EVT_MISC_ET1
	External Trigger 1
*/
#define AET_EVT_MISC_IACK                         (AET_GEM_MISC_EVT_START + 8)
/**
	\def AET_EVT_MISC_IACK
	Interrupt Acknowledge Event
*/
#define AET_EVT_MISC_AEGEVT0                      (AET_GEM_MISC_EVT_START + 9)
/**
	\def AET_EVT_MISC_AEGEVT0
	System Event connected through Interrupt Controller to AEGEVT0
*/
#define AET_EVT_MISC_AEGEVT1                      (AET_GEM_MISC_EVT_START + 10)
/**
	\def AET_EVT_MISC_AEGEVT1
	System Event connected through Interrupt Controller to AEGEVT1 
*/
#define AET_EVT_MISC_AEGEVT2                      (AET_GEM_MISC_EVT_START + 11)
/**
	\def AET_EVT_MISC_AEGEVT2
	System Event connected through Interrupt Controller to AEGEVT2 
*/
#define AET_EVT_MISC_AEGEVT3                      (AET_GEM_MISC_EVT_START + 12)
/**
	\def AET_EVT_MISC_AEGEVT3
	System Event connected through Interrupt Controller to AEGEVT3 
*/
#define AET_EVT_MISC_AEGEVT4                      (AET_GEM_MISC_EVT_START + 13)
/**
	\def AET_EVT_MISC_AEGEVT4
	System Event connected through Interrupt Controller to AEGEVT4 
*/
#define AET_EVT_MISC_AEGEVT5                      (AET_GEM_MISC_EVT_START + 14)
/**
	\def AET_EVT_MISC_AEGEVT5
	System Event connected through Interrupt Controller to AEGEVT5 
*/
#define AET_EVT_MISC_AEGEVT6                      (AET_GEM_MISC_EVT_START + 15)
/**
	\def AET_EVT_MISC_AEGEVT6
	System Event connected through Interrupt Controller to AEGEVT6 
*/
#define AET_EVT_MISC_AEGEVT7                      (AET_GEM_MISC_EVT_START + 16)
/**
	\def AET_EVT_MISC_AEGEVT7
	System Event connected through Interrupt Controller to AEGEVT7 
*/
#define AET_EVT_MISC_EXCEP                        (AET_GEM_MISC_EVT_START + 17)
/**
	\def AET_EVT_MISC_EXCEP
	Exception
*/
#define AET_EVT_MISC_EXC                          (AET_GEM_MISC_EVT_START + 18)
/**
	\def AET_EVT_MISC_EXC
	Exception Acknowledge
*/
#define AET_EVT_MISC_NMI                          (AET_GEM_MISC_EVT_START + 19)
/**
	\def AET_EVT_MISC_NMI
	Non Maskable Interrupt
*/
#define AET_EVT_MISC_RTDX_RX_END                  (AET_GEM_MISC_EVT_START + 20)
/**
	\def AET_EVT_MISC_RTDX_RX_END
	HS-RTDX Receive Completed
*/
#define AET_EVT_MISC_RTDX_TX_END                  (AET_GEM_MISC_EVT_START + 21)
/**
	\def AET_EVT_MISC_RTDX_TX_END
	HS-RTDX Transmit Completed
*/
#define AET_EVT_MISC_DTDMA_END                    (AET_GEM_MISC_EVT_START + 22)

/**
	\def AET_EVT_MISC_DTDMA_END
	DT-DMA Upload Completed
*/
#define AET_EVT_MISC_L1D_WM_HIT_L2SRAM            (AET_GEM_MISC_EVT_START + 23)
/**
	\def AET_EVT_MISC_L1D_WM_HIT_L2SRAM
	L1D write miss, hits L2 SRAM
*/
#define AET_EVT_MISC_L1D_WM_HIT_L2CACHE           (AET_GEM_MISC_EVT_START + 24)
/**
	\def AET_EVT_MISC_L1D_WM_HIT_L2CACHE
	L1D write miss, hits L2 Cache
*/
#define AET_EVT_MISC_L1D_WM_HIT_EXT_CABLE         (AET_GEM_MISC_EVT_START + 25)
/**
	\def AET_EVT_MISC_L1D_WM_HIT_EXT_CABLE
	L1D write miss, hits external, cacheable
*/
#define AET_EVT_MISC_L1D_WM_HIT_EXT_NONCABLE      (AET_GEM_MISC_EVT_START + 26)
/**
	\def AET_EVT_MISC_L1D_WM_HIT_EXT_NONCABLE
	L1D write miss, hits external, non-cacheable
*/
#define AET_EVT_MISC_DIRTY_VICTIM_WRITEBACK_L2    (AET_GEM_MISC_EVT_START + 27)
/**
	\def AET_EVT_MISC_DIRTY_VICTIM_WRITEBACK_L2
	Dirty Victim writeback from L2
*/
#define AET_EVT_MISC_DMA_SNOOP_READ               (AET_GEM_MISC_EVT_START + 28)
/**
	\def AET_EVT_MISC_DMA_SNOOP_READ
	DMA Snoop Read
*/
#define AET_EVT_MISC_DMA_SNOOP_WRITE              (AET_GEM_MISC_EVT_START + 29)
/**
	\def AET_EVT_MISC_DMA_SNOOP_WRITE
	DMA Snoop Write
*/
#define AET_EVT_MISC_TAG_UD_QUEUED_TAG_UD_BUF     (AET_GEM_MISC_EVT_START + 30)
/**
	\def AET_EVT_MISC_TAG_UD_QUEUED_TAG_UD_BUF
	Tag Update Queued Tag Update Buffer
*/
#define AET_EVT_MISC_DIRTY_VICTIM_WRITEBACK_L1D   (AET_GEM_MISC_EVT_START + 31)
/**
	\def AET_EVT_MISC_DIRTY_VICTIM_WRITEBACK_L1D
	Dirty Vistim Writeback from L1D
*/








/* 
 Structure Definitions and Typedefs 
 */

/*! \var typedef uint8_t AET_jobIndex
  \brief Type returned in the data parameters structures which indicates
  which entry in the jobs database that the job programmed occupies.

  When a job is programmed, a configWord structure is generated which
  records which resources are used by that job.  This structure is 
  stored in an array, and the index to that array can be acquired 
  by the calling application.  The calling application can clear the 
  job by passing the index number to the AET_releaseJob function
 */
typedef uint8_t AET_jobIndex;

/*! \struct AET_jobParams
   \brief Structure that holds the parameters needed to be passed
   to the AET_setupJob Function

  A structure of this type should be created by the host application, 
  and a pointer to this structure should be passed to the AET_setupJob
  function.

  The following is a table of Jobs and the valid associated parameters.
  @verbatim
  ==============================================================================
                          |   |   |   |   |   |   |   |   |   |   |   |   |   |
                          |   |   |   | T |   |   |   |   |   |   |   |   |   |
                          |   |   |   | R |   |   |   |   |   |   |   |   |   |
                          |   |   |   | I |   |   |   | T |   |   |   |   |   |
                          |   |   |   | G |   |   | W | R |   |   |   |   |   |
                          |   |   |   |   |   |   | A | A |   | T |   |   |   |
                          |   |   | T | O | T |   | T | C |   | R |   |   |   |
                          |   |   | R | N | I | T | E | E | T | A |   |   |   |
                          |   |   | I |   | M | I | R |   | R | C |   | T |   |
                          |   |   | G | D | E | M | M | S | A | E |   | R |   |
                          |   |   |   | A | R | E | A | T | C |   | T | I |   |
                          |   |   | O | T |   | R | R | A | E | I | R | G |   |
                          |   | T | N | A | S |   | K | R |   | N | A | G |   |
                          |   | R |   |   | T | S |   | T | I |   | C | E | A |
                          | T | I | D | W | A | T | S | S | N | D | E | R | D |
                          | R | G | A | I | R | O | T | T |   | A |   |   | D |
                          | I |   | T | T | T | P | A | O | P | T | O | O |   |
                          | G | O | A | H |   |   | R | P | C | A | N | N | T |
                          |   | N |   |   | O | O | T |   |   |   |   |   | R |
                          | O |   | R | V | N | N |   | O | R | R | E | E | I |
                          | N | D | A | A |   |   | S | N | A | A | V | V | G |
                          |   | A | N | L | E | E | T |   | N | N | E | E | G |
                          | P | T | G | U | V | V | O | P | G | G | N | N | E |
                          | C | A | E | E | T | T | P | C | E | E | T | T | R |
  =============================================================================
  triggerType             | X | X | X | X | X | X | X |   |   |   |   | X | X |
  -----------------------------------------------------------------------------
  programAddress          | X |   |   |   |   |   |   | X |   |   |   |   |   |
  -----------------------------------------------------------------------------
  dataAddress             |   | X |   | X |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  dataStartAddress        |   |   | X |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  dataEndAddress          |   |   | X |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  refSize                 |   | X | X | X |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  readWrite               |   | X | X | X |   |   |   |   |   | X |   |   |   |
  -----------------------------------------------------------------------------
  value                   |   |   |   | X |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  valueMask               |   |   |   | X |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  eventNumber             |   |   |   |   | X | X | X |   |   |   | X | X |   |
  -----------------------------------------------------------------------------
  startEventNumber        |   |   |   |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  endEventNumber          |   |   |   |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  startStop               |   |   |   |   |   |   | X |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  counterNumber           |   |   |   |   | X | X | X |   |   |   |   |   |   |
  -----------------------------------------------------------------------------
  traceTriggers           |   |   |   |   |   |   |   |   | X | X | X |   |   |
  -----------------------------------------------------------------------------
  traceStartAddress       |   |   |   |   |   |   |   |   | X | X |   |   |   |
  -----------------------------------------------------------------------------
  traceEndAddress         |   |   |   |   |   |   |   |   | X | X |   |   |   |
  -----------------------------------------------------------------------------
  traceActive             |   |   |   |   |   |   |   | X | X | X | X |   |   |
  -----------------------------------------------------------------------------
  triggerLogicOrientation |   |   |   |   |   |   |   |   |   |   |   |   | X |
  -----------------------------------------------------------------------------
  jobIndex                | X | X | X | X | X | X | X | X | X | X | X | X | X |
  -----------------------------------------------------------------------------

  @endverbatim

 */

typedef struct {
  uint16_t size;
		  //!< Must be first field of all params structures		
  AET_triggerType triggerType;
          //!< Type of trigger to be generated 
  uint32_t programAddress;
          //!< Desired Program Address to generate trigger 
  uint32_t programRangeStartAddress;
		  //!< Program Address at start of range
  uint32_t programRangeEndAddress;
		  //!< Program Address at end of range
  uint32_t dataAddress;
          //!< Address of the read/write to generate trigger
  uint32_t dataStartAddress;
          //!< Start Address of the interested range 
  uint32_t dataEndAddress;
          //!< End Address of the interested range 
  uint32_t traceStartAddress;
		  //!< Program Address to begin Trace Job
  uint32_t traceEndAddress;
		  //!< Program Address to End Trace Job
  AET_refSize refSize;
          //!< Size of data read/write 
  AET_watchReadWrite readWrite;
          //!< Specify watch on read or watch on write 
  uint64_t value;
          //!< Value to qualify the Read/Write with 
  uint64_t valueMask;
          //!< Bitmask for specified value
  uint16_t eventNumber[4];
          //!< Specify the number of the First Event
  uint16_t startEventNumber;
          //!< Specify the number of the Miscellaneous Start Event
  uint16_t endEventNumber;
          //!< Specify the number of the Miscellaneous End Event
  AET_evtTrigConfig eventTriggerConfig;
  	  	  //!< Specify the type of triggering (Edge to high, Level Low, etc)
  AET_watermarkAction startStop;
          //!< Specify whether this event starts or stops the counter
  AET_counters counterNumber;
          //!< Specify which counter to use 
  AET_traceActive traceActive;
		  //!< Specify whether to start or stop trace
  AET_traceTrigger traceTriggers;
		  //!< Specify which Trace Triggers to generate
  AET_triggerLogicOrientation logicOrientation;
		  //!< Specify whether the trigger logic should be inverted
  AET_stateQual stateQual;
		  //!< Specify which state to qualify job with
  AET_jobIndex jobIndex;
          //!< Index of the programmed job in the job table
}AET_jobParams;

typedef struct {
  uint16_t size;
		  //!< Must be first field of all params structures	
  AET_counters counterNumber;
          /*!<Specify which counter to configure */
  AET_counterConfig configMode;
          /*!<Specify the configuration mode */
  int32_t reloadValue;
          /*!<Specify the reload value for the counter */
}AET_counterConfigParams;


/*
 Static data definitions
 */
extern far const AET_jobParams AET_JOBPARAMS;
extern far const AET_counterConfigParams AET_COUNTERCONFIGPARAMS;

/* 
 Static function prototypes
 */

/*
 Module Function Definintions
 */

/**
 *\brief Claims the AET unit for use by the application.  
 *
 * This function must be called prior to the following functions
 @verbatim
  AET_setupJob
  AET_enable
  AET_release
  AET_counterConfig
 @endverbatim
 * It must be called after AET_init
 *
 * The AET unit is shared between the application and the debugger.  Calling 
 * this function claims it for use by the application. After claim has been
 * executed, the debugger has no access to the AET resources until AET_release
 * has been called.  If AET is already claimed by the debugger, the AET_claim
 * call will fail
 */
AET_error AET_claim(void);
/**
 *\brief Configures the Counters used with AET
 *
 * This function will set the counter mode, operating mode, and reload value
 * for one of the counters.  This function must be called prior to calling
 * AET_setupJob for any of the counter related jobs.
 * 
 * 
 * @param *params Pointer to the configuration structure for 
 *          counter configuration
 *
 * @return AET_SUCCESS if success, AET_ERR_XXX if failure
 */
AET_error AET_configCounter(AET_counterConfigParams* params);
/**
 *\brief Disables the AET jobs that have been programmed
 *
 * AET_disable can be called at any time in the application to temporarily 
 * disable any jobs that have been programmed.    
 */

AET_error AET_clearCounters();
/**
 * \brief Clears all existing Counter configurations.
 */

AET_error AET_disable(void);
/**
 *\brief Enables the AET jobs that have been programmed
 *
 * AET_enable must be called by the target application after programmation of 
 * a job.  Programming the job(s) will set all of the register values correctly,
 * but the jobs will not be enabled until the user calls this function.  The 
 * hardware does not provide an analogous way to disable the AET.  In order to 
 * disable the AET jobs, the user must execute an AET_release, and then re-issue
 * AET_claim.  This functionality is not provided by the library because there
 * is a slight risk that the debugger could claim AET before the application can
 * claim it again.  
 */
AET_error AET_enable(void);
/**
 *\brief Initializes the application
 *
 * AET_init must be called prior to executing any of the other AET API's It 
 * should only be called once.  It initializes global variables and some data 
 * that the library uses.  All of the other API's will fail if the library is 
 * not properly initialized
 */
void AET_init(void);
/**
 *\brief Read counter value
 *
 * AET_readCounter is called to read the value of the specified counter.  
 * It simply returns the  value in the counter register
 */
int32_t AET_readCounter(AET_counters);
/**
 *\brief Release ownership of the AET resources
 *
 * AET_release returns the status of the AET block to available.  At this point, 
 * it can be claimed by the debugger, or it can be reclaimed by the application. 
 */
AET_error AET_release(void);
/**
 *\brief Clear an AET job
 *
 * AET_releaseJob releases the resources used by a previously programmed AET 
 * job. It removes the references to the AET job in the job table.
 *
 * @param jobIndex Index to an existing job in the job table.
 *
 * @return AET_SUCCESS if success, AET_FAIL_XXX if failure
 */
AET_error AET_releaseJob(AET_jobIndex jobIndex);
/**
 *\brief Programs specified AET jobs
 *
 * AET_setupJob programs the AET registers for the job that is specified.  
 * Resource management will attempt to use available resources for the job, and 
 * will keep track of the resources used.  Resource usage is stored by the 
 * application.  A job id can be acquired by the application by referencing the 
 * jobIndex member of the parameters structure after sucessfully executing the 
 * AET_setupJob function.
 * 
 * @param jobType Enumeration for the type of job being progammed
 * @param *params Pointer to a configuration structure for the job type selected
 *
 * @return AET_SUCCESS if success, AET_FAIL_XXX if failure
 */
AET_error AET_setupJob(AET_jobType jobType, AET_jobParams* params);

/**
 *\brief Enables EMU0 and EMU1 pins for ET0/1 input/output
 *
 * AET_enableEmuPins programs the pin manager to expose ET0 and ET1 to the pins
 * EMU0 and EMU1 respectively.
 */
AET_error AET_enableEmuPins(void);
/**
 *\brief Disables EMU0 and EMU1 pins for ET0/1 input/output
 *
 * AET_disableEmuPins programs the pin manager to disconnect ET0 and ET1 from
 * the EMU0 and EMU1 pins respectively.  
 */
AET_error AET_disableEmuPins(void);

/* 
 Static (internal) function definitions
 */

/* 
 Revision History
 */
/*@}*/

#ifdef __cplusplus
}
#endif


#endif
