/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */

/*
 * ======== GENERATED SECTIONS ========
 *
 *     PROLOGUE
 *     INCLUDES
 *
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sdo_ipc_family_dm6446_InterruptDsp__include
#define ti_sdo_ipc_family_dm6446_InterruptDsp__include

#ifndef __nested__
#define __nested__
#define ti_sdo_ipc_family_dm6446_InterruptDsp__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_ipc_family_dm6446_InterruptDsp___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sdo/ipc/family/dm6446/package/package.defs.h>

#include <ti/sdo/ipc/notifyDrivers/IInterrupt.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* IntInfo */
typedef ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo ti_sdo_ipc_family_dm6446_InterruptDsp_IntInfo;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0 ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0 (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1 ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1 (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2 ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2 (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4 ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4 (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8 ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8 (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count (ti_sdo_ipc_family_dm6446_InterruptDsp_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap (ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof (ti_sdo_ipc_family_dm6446_InterruptDsp_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table;
__extern __FAR__ const CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table__C;
#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table__CR
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table__C (*((CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table*)(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table__C_offset)))
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table (ti_sdo_ipc_family_dm6446_InterruptDsp_Object__table__C)
#endif


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_ipc_family_dm6446_InterruptDsp_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Void (*intEnable)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
    xdc_Void (*intDisable)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
    xdc_Void (*intRegister)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo, xdc_Fxn func, xdc_UArg arg);
    xdc_Void (*intUnregister)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
    xdc_Void (*intSend)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo, xdc_UArg arg);
    xdc_Void (*intPost)(xdc_UInt16 srcProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo, xdc_UArg arg);
    xdc_UInt (*intClear)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef ti_sdo_ipc_family_dm6446_InterruptDsp_Module__FXNS__CR

/* Module__FXNS__C */
__extern const ti_sdo_ipc_family_dm6446_InterruptDsp_Fxns__ ti_sdo_ipc_family_dm6446_InterruptDsp_Module__FXNS__C;
#else
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module__FXNS__C (*(xdcRomConstPtr + ti_sdo_ipc_family_dm6446_InterruptDsp_Module__FXNS__C_offset))
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_Module__startupDone__S, "ti_sdo_ipc_family_dm6446_InterruptDsp_Module__startupDone__S")
__extern xdc_Bool ti_sdo_ipc_family_dm6446_InterruptDsp_Module__startupDone__S( void );

/* intEnable__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intEnable ti_sdo_ipc_family_dm6446_InterruptDsp_intEnable__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intEnable__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intEnable")
__extern xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_intEnable__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intDisable__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intDisable ti_sdo_ipc_family_dm6446_InterruptDsp_intDisable__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intDisable__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intDisable")
__extern xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_intDisable__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intRegister__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intRegister ti_sdo_ipc_family_dm6446_InterruptDsp_intRegister__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intRegister__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intRegister")
__extern xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_intRegister__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_Fxn func, xdc_UArg arg );

/* intUnregister__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intUnregister ti_sdo_ipc_family_dm6446_InterruptDsp_intUnregister__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intUnregister__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intUnregister")
__extern xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_intUnregister__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intSend__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intSend ti_sdo_ipc_family_dm6446_InterruptDsp_intSend__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intSend__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intSend")
__extern xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_intSend__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg );

/* intPost__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intPost ti_sdo_ipc_family_dm6446_InterruptDsp_intPost__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intPost__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intPost")
__extern xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_intPost__E( xdc_UInt16 srcProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg );

/* intClear__E */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_intClear ti_sdo_ipc_family_dm6446_InterruptDsp_intClear__E
xdc__CODESECT(ti_sdo_ipc_family_dm6446_InterruptDsp_intClear__E, "ti_sdo_ipc_family_dm6446_InterruptDsp_intClear")
__extern xdc_UInt ti_sdo_ipc_family_dm6446_InterruptDsp_intClear__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_Module ti_sdo_ipc_family_dm6446_InterruptDsp_Module_upCast(void);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_Module ti_sdo_ipc_family_dm6446_InterruptDsp_Module_upCast(void)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_Module)&ti_sdo_ipc_family_dm6446_InterruptDsp_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt ti_sdo_ipc_family_dm6446_InterruptDsp_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module_startupDone() ti_sdo_ipc_family_dm6446_InterruptDsp_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Object_heap() ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__C

/* Module_heap */
#define ti_sdo_ipc_family_dm6446_InterruptDsp_Module_heap() ti_sdo_ipc_family_dm6446_InterruptDsp_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id ti_sdo_ipc_family_dm6446_InterruptDsp_Module_id(void);
static inline CT__ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id ti_sdo_ipc_family_dm6446_InterruptDsp_Module_id( void ) 
{
    return ti_sdo_ipc_family_dm6446_InterruptDsp_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_ipc_family_dm6446_InterruptDsp_Module_hasMask(void);
static inline xdc_Bool ti_sdo_ipc_family_dm6446_InterruptDsp_Module_hasMask(void) 
{
    return (xdc_Bool)(ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_ipc_family_dm6446_InterruptDsp_Module_getMask(void);
static inline xdc_Bits16 ti_sdo_ipc_family_dm6446_InterruptDsp_Module_getMask( void ) 
{
    return ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C != NULL ? *ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_sdo_ipc_family_dm6446_InterruptDsp_Module_setMask(xdc_Bits16 mask)
{
    if (ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C != NULL) {
        *ti_sdo_ipc_family_dm6446_InterruptDsp_Module__diagsMask__C = mask;
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_ipc_family_dm6446_InterruptDsp__top__
#undef __nested__
#endif

#endif /* ti_sdo_ipc_family_dm6446_InterruptDsp__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_ipc_family_dm6446_InterruptDsp__internalaccess))

#ifndef ti_sdo_ipc_family_dm6446_InterruptDsp__include_state
#define ti_sdo_ipc_family_dm6446_InterruptDsp__include_state


#endif /* ti_sdo_ipc_family_dm6446_InterruptDsp__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_ipc_family_dm6446_InterruptDsp__nolocalnames)

#ifndef ti_sdo_ipc_family_dm6446_InterruptDsp__localnames__done
#define ti_sdo_ipc_family_dm6446_InterruptDsp__localnames__done

/* module prefix */
#define InterruptDsp_IntInfo ti_sdo_ipc_family_dm6446_InterruptDsp_IntInfo
#define InterruptDsp_intEnable ti_sdo_ipc_family_dm6446_InterruptDsp_intEnable
#define InterruptDsp_intDisable ti_sdo_ipc_family_dm6446_InterruptDsp_intDisable
#define InterruptDsp_intRegister ti_sdo_ipc_family_dm6446_InterruptDsp_intRegister
#define InterruptDsp_intUnregister ti_sdo_ipc_family_dm6446_InterruptDsp_intUnregister
#define InterruptDsp_intSend ti_sdo_ipc_family_dm6446_InterruptDsp_intSend
#define InterruptDsp_intPost ti_sdo_ipc_family_dm6446_InterruptDsp_intPost
#define InterruptDsp_intClear ti_sdo_ipc_family_dm6446_InterruptDsp_intClear
#define InterruptDsp_Module_name ti_sdo_ipc_family_dm6446_InterruptDsp_Module_name
#define InterruptDsp_Module_id ti_sdo_ipc_family_dm6446_InterruptDsp_Module_id
#define InterruptDsp_Module_startup ti_sdo_ipc_family_dm6446_InterruptDsp_Module_startup
#define InterruptDsp_Module_startupDone ti_sdo_ipc_family_dm6446_InterruptDsp_Module_startupDone
#define InterruptDsp_Module_hasMask ti_sdo_ipc_family_dm6446_InterruptDsp_Module_hasMask
#define InterruptDsp_Module_getMask ti_sdo_ipc_family_dm6446_InterruptDsp_Module_getMask
#define InterruptDsp_Module_setMask ti_sdo_ipc_family_dm6446_InterruptDsp_Module_setMask
#define InterruptDsp_Object_heap ti_sdo_ipc_family_dm6446_InterruptDsp_Object_heap
#define InterruptDsp_Module_heap ti_sdo_ipc_family_dm6446_InterruptDsp_Module_heap
#define InterruptDsp_Module_upCast ti_sdo_ipc_family_dm6446_InterruptDsp_Module_upCast
#define InterruptDsp_Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt ti_sdo_ipc_family_dm6446_InterruptDsp_Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt

#endif /* ti_sdo_ipc_family_dm6446_InterruptDsp__localnames__done */
#endif
