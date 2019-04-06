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
 *     CREATE ARGS
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
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

#ifndef ti_sdo_ipc_gates_GateHWSpinlock__include
#define ti_sdo_ipc_gates_GateHWSpinlock__include

#ifndef __nested__
#define __nested__
#define ti_sdo_ipc_gates_GateHWSpinlock__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_ipc_gates_GateHWSpinlock___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sdo/ipc/gates/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <ti/sdo/ipc/interfaces/IGateMPSupport.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define ti_sdo_ipc_gates_GateHWSpinlock_Q_BLOCKING (1)

/* Q_PREEMPTING */
#define ti_sdo_ipc_gates_GateHWSpinlock_Q_PREEMPTING (2)


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sdo_ipc_gates_GateHWSpinlock_Args__create {
    xdc_runtime_IGateProvider_Handle localGate;
} ti_sdo_ipc_gates_GateHWSpinlock_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled (ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded (ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask (ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj (ti_sdo_ipc_gates_GateHWSpinlock_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms (ti_sdo_ipc_gates_GateHWSpinlock_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__id;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__id ti_sdo_ipc_gates_GateHWSpinlock_Module__id__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__id__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__id__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__id*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__id__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__id (ti_sdo_ipc_gates_GateHWSpinlock_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0 ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0 (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1 ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1 (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2 ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2 (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4 ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4 (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8 ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8 (ti_sdo_ipc_gates_GateHWSpinlock_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__count;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__count ti_sdo_ipc_gates_GateHWSpinlock_Object__count__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Object__count__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__count__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__count*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Object__count__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__count (ti_sdo_ipc_gates_GateHWSpinlock_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__heap;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__heap ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__heap*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__heap (ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof (ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__table;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__table ti_sdo_ipc_gates_GateHWSpinlock_Object__table__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_Object__table__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__table__C (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_Object__table*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Object__table__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Object__table (ti_sdo_ipc_gates_GateHWSpinlock_Object__table__C)
#endif

/* LM_enter */
typedef xdc_runtime_Log_Event CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_enter;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_enter ti_sdo_ipc_gates_GateHWSpinlock_LM_enter__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_LM_enter__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_enter (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_enter*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_LM_enter__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_enter (ti_sdo_ipc_gates_GateHWSpinlock_LM_enter__C)
#endif

/* LM_leave */
typedef xdc_runtime_Log_Event CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_leave;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_leave ti_sdo_ipc_gates_GateHWSpinlock_LM_leave__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_LM_leave__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_leave (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_leave*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_LM_leave__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_leave (ti_sdo_ipc_gates_GateHWSpinlock_LM_leave__C)
#endif

/* LM_create */
typedef xdc_runtime_Log_Event CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_create;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_create ti_sdo_ipc_gates_GateHWSpinlock_LM_create__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_LM_create__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_create (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_create*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_LM_create__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_create (ti_sdo_ipc_gates_GateHWSpinlock_LM_create__C)
#endif

/* LM_open */
typedef xdc_runtime_Log_Event CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_open;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_open ti_sdo_ipc_gates_GateHWSpinlock_LM_open__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_LM_open__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_open (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_open*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_LM_open__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_open (ti_sdo_ipc_gates_GateHWSpinlock_LM_open__C)
#endif

/* LM_delete */
typedef xdc_runtime_Log_Event CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_delete;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_delete ti_sdo_ipc_gates_GateHWSpinlock_LM_delete__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_LM_delete__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_delete (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_delete*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_LM_delete__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_delete (ti_sdo_ipc_gates_GateHWSpinlock_LM_delete__C)
#endif

/* LM_close */
typedef xdc_runtime_Log_Event CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_close;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_close ti_sdo_ipc_gates_GateHWSpinlock_LM_close__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_LM_close__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_close (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_LM_close*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_LM_close__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_LM_close (ti_sdo_ipc_gates_GateHWSpinlock_LM_close__C)
#endif

/* A_invSpinLockNum */
typedef xdc_runtime_Assert_Id CT__ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum (ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum__C)
#endif

/* baseAddr */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateHWSpinlock_baseAddr;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_baseAddr ti_sdo_ipc_gates_GateHWSpinlock_baseAddr__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_baseAddr__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_baseAddr (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_baseAddr*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_baseAddr__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_baseAddr (ti_sdo_ipc_gates_GateHWSpinlock_baseAddr__C)
#endif

/* numLocks */
typedef xdc_UInt CT__ti_sdo_ipc_gates_GateHWSpinlock_numLocks;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_numLocks ti_sdo_ipc_gates_GateHWSpinlock_numLocks__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_numLocks__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_numLocks (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_numLocks*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_numLocks__C_offset)))
#else
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_numLocks__D
#define ti_sdo_ipc_gates_GateHWSpinlock_numLocks (ti_sdo_ipc_gates_GateHWSpinlock_numLocks__D)
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_numLocks (ti_sdo_ipc_gates_GateHWSpinlock_numLocks__C)
#endif
#endif

/* reservedMaskArr */
typedef xdc_Bits32 __T1_ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr;
typedef xdc_Bits32 *__ARRAY1_ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr;
typedef const xdc_Bits32 *__CARRAY1_ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr;
typedef __CARRAY1_ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr __TA_ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr;
typedef __CARRAY1_ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr CT__ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr__C;
#ifdef ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr__CR
#define ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr (*((CT__ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr__C_offset)))
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr (ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr__C)
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sdo_ipc_gates_GateHWSpinlock_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_UInt resourceId;
    xdc_Bool openFlag;
    xdc_UInt16 regionId;
    xdc_Ptr sharedAddr;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sdo_ipc_gates_GateHWSpinlock_Struct {
    const ti_sdo_ipc_gates_GateHWSpinlock_Fxns__ *__fxns;
    xdc_UInt __f0;
    xdc_UInt __f1;
    xdc_runtime_IGateProvider_Handle __f2;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_ipc_gates_GateHWSpinlock_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bool (*query)(xdc_Int qual);
    xdc_IArg (*enter)(ti_sdo_ipc_gates_GateHWSpinlock_Handle __inst);
    xdc_Void (*leave)(ti_sdo_ipc_gates_GateHWSpinlock_Handle __inst, xdc_IArg key);
    xdc_Bits32 *(*getReservedMask)(void);
    xdc_SizeT (*sharedMemReq)(const ti_sdo_ipc_interfaces_IGateMPSupport_Params* params);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__CR

/* Module__FXNS__C */
__extern const ti_sdo_ipc_gates_GateHWSpinlock_Fxns__ ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C;
#else
#define ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C (*(xdcRomConstPtr + ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C_offset))
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_ipc_gates_GateHWSpinlock_Module_startup ti_sdo_ipc_gates_GateHWSpinlock_Module_startup__E
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Module_startup__E, "ti_sdo_ipc_gates_GateHWSpinlock_Module_startup")
__extern xdc_Int ti_sdo_ipc_gates_GateHWSpinlock_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Module_startup__F, "ti_sdo_ipc_gates_GateHWSpinlock_Module_startup")
__extern xdc_Int ti_sdo_ipc_gates_GateHWSpinlock_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Instance_init__E, "ti_sdo_ipc_gates_GateHWSpinlock_Instance_init")
__extern xdc_Void ti_sdo_ipc_gates_GateHWSpinlock_Instance_init__E(ti_sdo_ipc_gates_GateHWSpinlock_Object *__obj, xdc_runtime_IGateProvider_Handle localGate, const ti_sdo_ipc_gates_GateHWSpinlock_Params *__prms);

/* create */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_create, "ti_sdo_ipc_gates_GateHWSpinlock_create")
__extern ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_create( xdc_runtime_IGateProvider_Handle localGate, const ti_sdo_ipc_gates_GateHWSpinlock_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_construct, "ti_sdo_ipc_gates_GateHWSpinlock_construct")
__extern void ti_sdo_ipc_gates_GateHWSpinlock_construct( ti_sdo_ipc_gates_GateHWSpinlock_Struct *__obj, xdc_runtime_IGateProvider_Handle localGate, const ti_sdo_ipc_gates_GateHWSpinlock_Params *__prms );

/* delete */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_delete, "ti_sdo_ipc_gates_GateHWSpinlock_delete")
__extern void ti_sdo_ipc_gates_GateHWSpinlock_delete(ti_sdo_ipc_gates_GateHWSpinlock_Handle *instp);

/* destruct */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_destruct, "ti_sdo_ipc_gates_GateHWSpinlock_destruct")
__extern void ti_sdo_ipc_gates_GateHWSpinlock_destruct(ti_sdo_ipc_gates_GateHWSpinlock_Struct *obj);

/* Handle__label__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Handle__label__S, "ti_sdo_ipc_gates_GateHWSpinlock_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sdo_ipc_gates_GateHWSpinlock_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Module__startupDone__S, "ti_sdo_ipc_gates_GateHWSpinlock_Module__startupDone__S")
__extern xdc_Bool ti_sdo_ipc_gates_GateHWSpinlock_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Object__create__S, "ti_sdo_ipc_gates_GateHWSpinlock_Object__create__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateHWSpinlock_Object__create__S( xdc_CPtr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Object__delete__S, "ti_sdo_ipc_gates_GateHWSpinlock_Object__delete__S")
__extern xdc_Void ti_sdo_ipc_gates_GateHWSpinlock_Object__delete__S( xdc_Ptr instp );

/* Object__get__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Object__get__S, "ti_sdo_ipc_gates_GateHWSpinlock_Object__get__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateHWSpinlock_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Object__first__S, "ti_sdo_ipc_gates_GateHWSpinlock_Object__first__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateHWSpinlock_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Object__next__S, "ti_sdo_ipc_gates_GateHWSpinlock_Object__next__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateHWSpinlock_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_Params__init__S, "ti_sdo_ipc_gates_GateHWSpinlock_Params__init__S")
__extern xdc_Void ti_sdo_ipc_gates_GateHWSpinlock_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* query__E */
#define ti_sdo_ipc_gates_GateHWSpinlock_query ti_sdo_ipc_gates_GateHWSpinlock_query__E
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_query__E, "ti_sdo_ipc_gates_GateHWSpinlock_query")
__extern xdc_Bool ti_sdo_ipc_gates_GateHWSpinlock_query__E( xdc_Int qual );

/* getReservedMask__E */
#define ti_sdo_ipc_gates_GateHWSpinlock_getReservedMask ti_sdo_ipc_gates_GateHWSpinlock_getReservedMask__E
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_getReservedMask__E, "ti_sdo_ipc_gates_GateHWSpinlock_getReservedMask")
__extern xdc_Bits32 *ti_sdo_ipc_gates_GateHWSpinlock_getReservedMask__E( void );

/* sharedMemReq__E */
#define ti_sdo_ipc_gates_GateHWSpinlock_sharedMemReq ti_sdo_ipc_gates_GateHWSpinlock_sharedMemReq__E
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_sharedMemReq__E, "ti_sdo_ipc_gates_GateHWSpinlock_sharedMemReq")
__extern xdc_SizeT ti_sdo_ipc_gates_GateHWSpinlock_sharedMemReq__E( const ti_sdo_ipc_interfaces_IGateMPSupport_Params *params );

/* enter__E */
#define ti_sdo_ipc_gates_GateHWSpinlock_enter ti_sdo_ipc_gates_GateHWSpinlock_enter__E
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_enter__E, "ti_sdo_ipc_gates_GateHWSpinlock_enter")
__extern xdc_IArg ti_sdo_ipc_gates_GateHWSpinlock_enter__E( ti_sdo_ipc_gates_GateHWSpinlock_Handle __inst );

/* leave__E */
#define ti_sdo_ipc_gates_GateHWSpinlock_leave ti_sdo_ipc_gates_GateHWSpinlock_leave__E
xdc__CODESECT(ti_sdo_ipc_gates_GateHWSpinlock_leave__E, "ti_sdo_ipc_gates_GateHWSpinlock_leave")
__extern xdc_Void ti_sdo_ipc_gates_GateHWSpinlock_leave__E( ti_sdo_ipc_gates_GateHWSpinlock_Handle __inst, xdc_IArg key );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Module ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast(void);
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Module ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast(void)
{
    return (ti_sdo_ipc_interfaces_IGateMPSupport_Module)&ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_interfaces_IGateMPSupport */
#define ti_sdo_ipc_gates_GateHWSpinlock_Module_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast

/* Handle_upCast */
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast(ti_sdo_ipc_gates_GateHWSpinlock_Handle i);
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast(ti_sdo_ipc_gates_GateHWSpinlock_Handle i)
{
    return (ti_sdo_ipc_interfaces_IGateMPSupport_Handle)i;
}

/* Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport */
#define ti_sdo_ipc_gates_GateHWSpinlock_Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast

/* Handle_downCast */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast(ti_sdo_ipc_interfaces_IGateMPSupport_Handle i);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast(ti_sdo_ipc_interfaces_IGateMPSupport_Handle i)
{
    ti_sdo_ipc_interfaces_IGateMPSupport_Handle i2 = (ti_sdo_ipc_interfaces_IGateMPSupport_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C ? (ti_sdo_ipc_gates_GateHWSpinlock_Handle)i : (ti_sdo_ipc_gates_GateHWSpinlock_Handle)0;
}

/* Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport */
#define ti_sdo_ipc_gates_GateHWSpinlock_Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast

/* Module_upCast2 */
static inline xdc_runtime_IGateProvider_Module ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast2(void);
static inline xdc_runtime_IGateProvider_Module ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast2(void)
{
    return (xdc_runtime_IGateProvider_Module)&ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IGateProvider */
#define ti_sdo_ipc_gates_GateHWSpinlock_Module_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast2

/* Handle_upCast2 */
static inline xdc_runtime_IGateProvider_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast2(ti_sdo_ipc_gates_GateHWSpinlock_Handle i);
static inline xdc_runtime_IGateProvider_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast2(ti_sdo_ipc_gates_GateHWSpinlock_Handle i)
{
    return (xdc_runtime_IGateProvider_Handle)i;
}

/* Handle_to_xdc_runtime_IGateProvider */
#define ti_sdo_ipc_gates_GateHWSpinlock_Handle_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast2

/* Handle_downCast2 */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast2(xdc_runtime_IGateProvider_Handle i);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast2(xdc_runtime_IGateProvider_Handle i)
{
    xdc_runtime_IGateProvider_Handle i2 = (xdc_runtime_IGateProvider_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_sdo_ipc_gates_GateHWSpinlock_Module__FXNS__C ? (ti_sdo_ipc_gates_GateHWSpinlock_Handle)i : (ti_sdo_ipc_gates_GateHWSpinlock_Handle)0;
}

/* Handle_from_xdc_runtime_IGateProvider */
#define ti_sdo_ipc_gates_GateHWSpinlock_Handle_from_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_ipc_gates_GateHWSpinlock_Module_startupDone() ti_sdo_ipc_gates_GateHWSpinlock_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_ipc_gates_GateHWSpinlock_Object_heap() ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__C

/* Module_heap */
#define ti_sdo_ipc_gates_GateHWSpinlock_Module_heap() ti_sdo_ipc_gates_GateHWSpinlock_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__id ti_sdo_ipc_gates_GateHWSpinlock_Module_id(void);
static inline CT__ti_sdo_ipc_gates_GateHWSpinlock_Module__id ti_sdo_ipc_gates_GateHWSpinlock_Module_id( void ) 
{
    return ti_sdo_ipc_gates_GateHWSpinlock_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_ipc_gates_GateHWSpinlock_Module_hasMask(void);
static inline xdc_Bool ti_sdo_ipc_gates_GateHWSpinlock_Module_hasMask(void) 
{
    return (xdc_Bool)(ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_ipc_gates_GateHWSpinlock_Module_getMask(void);
static inline xdc_Bits16 ti_sdo_ipc_gates_GateHWSpinlock_Module_getMask( void ) 
{
    return ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C != NULL ? *ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_ipc_gates_GateHWSpinlock_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_sdo_ipc_gates_GateHWSpinlock_Module_setMask(xdc_Bits16 mask)
{
    if (ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C != NULL) {
        *ti_sdo_ipc_gates_GateHWSpinlock_Module__diagsMask__C = mask;
    }
}

/* Params_init */
static inline void ti_sdo_ipc_gates_GateHWSpinlock_Params_init(ti_sdo_ipc_gates_GateHWSpinlock_Params *prms);
static inline void ti_sdo_ipc_gates_GateHWSpinlock_Params_init( ti_sdo_ipc_gates_GateHWSpinlock_Params *prms ) 
{
    if (prms) {
        ti_sdo_ipc_gates_GateHWSpinlock_Params__init__S(prms, 0, sizeof(ti_sdo_ipc_gates_GateHWSpinlock_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sdo_ipc_gates_GateHWSpinlock_Params_copy(ti_sdo_ipc_gates_GateHWSpinlock_Params *dst, const ti_sdo_ipc_gates_GateHWSpinlock_Params *src);
static inline void ti_sdo_ipc_gates_GateHWSpinlock_Params_copy(ti_sdo_ipc_gates_GateHWSpinlock_Params *dst, const ti_sdo_ipc_gates_GateHWSpinlock_Params *src) 
{
    if (dst) {
        ti_sdo_ipc_gates_GateHWSpinlock_Params__init__S(dst, (const void *)src, sizeof(ti_sdo_ipc_gates_GateHWSpinlock_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sdo_ipc_gates_GateHWSpinlock_Object_count() ti_sdo_ipc_gates_GateHWSpinlock_Object__count__C

/* Object_sizeof */
#define ti_sdo_ipc_gates_GateHWSpinlock_Object_sizeof() ti_sdo_ipc_gates_GateHWSpinlock_Object__sizeof__C

/* Object_get */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Object_get(ti_sdo_ipc_gates_GateHWSpinlock_Instance_State *oarr, int i);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Object_get(ti_sdo_ipc_gates_GateHWSpinlock_Instance_State *oarr, int i) 
{
    return (ti_sdo_ipc_gates_GateHWSpinlock_Handle)ti_sdo_ipc_gates_GateHWSpinlock_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Object_first(void);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Object_first(void)
{
    return (ti_sdo_ipc_gates_GateHWSpinlock_Handle)ti_sdo_ipc_gates_GateHWSpinlock_Object__first__S();
}

/* Object_next */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Object_next(ti_sdo_ipc_gates_GateHWSpinlock_Object *obj);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Object_next(ti_sdo_ipc_gates_GateHWSpinlock_Object *obj)
{
    return (ti_sdo_ipc_gates_GateHWSpinlock_Handle)ti_sdo_ipc_gates_GateHWSpinlock_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sdo_ipc_gates_GateHWSpinlock_Handle_label(ti_sdo_ipc_gates_GateHWSpinlock_Handle inst, xdc_runtime_Types_Label *lab);
static inline xdc_runtime_Types_Label *ti_sdo_ipc_gates_GateHWSpinlock_Handle_label(ti_sdo_ipc_gates_GateHWSpinlock_Handle inst, xdc_runtime_Types_Label *lab)
{
    return ti_sdo_ipc_gates_GateHWSpinlock_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sdo_ipc_gates_GateHWSpinlock_Handle_name(ti_sdo_ipc_gates_GateHWSpinlock_Handle inst);
static inline xdc_String ti_sdo_ipc_gates_GateHWSpinlock_Handle_name(ti_sdo_ipc_gates_GateHWSpinlock_Handle inst)
{
    xdc_runtime_Types_Label lab;
    return ti_sdo_ipc_gates_GateHWSpinlock_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_handle(ti_sdo_ipc_gates_GateHWSpinlock_Struct *str);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_handle(ti_sdo_ipc_gates_GateHWSpinlock_Struct *str)
{
    return (ti_sdo_ipc_gates_GateHWSpinlock_Handle)str;
}

/* struct */
static inline ti_sdo_ipc_gates_GateHWSpinlock_Struct *ti_sdo_ipc_gates_GateHWSpinlock_struct(ti_sdo_ipc_gates_GateHWSpinlock_Handle inst);
static inline ti_sdo_ipc_gates_GateHWSpinlock_Struct *ti_sdo_ipc_gates_GateHWSpinlock_struct(ti_sdo_ipc_gates_GateHWSpinlock_Handle inst)
{
    return (ti_sdo_ipc_gates_GateHWSpinlock_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_ipc_gates_GateHWSpinlock__top__
#undef __nested__
#endif

#endif /* ti_sdo_ipc_gates_GateHWSpinlock__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_ipc_gates_GateHWSpinlock__internalaccess))

#ifndef ti_sdo_ipc_gates_GateHWSpinlock__include_state
#define ti_sdo_ipc_gates_GateHWSpinlock__include_state

/* Object */
struct ti_sdo_ipc_gates_GateHWSpinlock_Object {
    const ti_sdo_ipc_gates_GateHWSpinlock_Fxns__ *__fxns;
    xdc_UInt lockNum;
    xdc_UInt nested;
    xdc_runtime_IGateProvider_Handle localGate;
};

#endif /* ti_sdo_ipc_gates_GateHWSpinlock__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_ipc_gates_GateHWSpinlock__nolocalnames)

#ifndef ti_sdo_ipc_gates_GateHWSpinlock__localnames__done
#define ti_sdo_ipc_gates_GateHWSpinlock__localnames__done

/* module prefix */
#define GateHWSpinlock_Instance ti_sdo_ipc_gates_GateHWSpinlock_Instance
#define GateHWSpinlock_Handle ti_sdo_ipc_gates_GateHWSpinlock_Handle
#define GateHWSpinlock_Module ti_sdo_ipc_gates_GateHWSpinlock_Module
#define GateHWSpinlock_Object ti_sdo_ipc_gates_GateHWSpinlock_Object
#define GateHWSpinlock_Struct ti_sdo_ipc_gates_GateHWSpinlock_Struct
#define GateHWSpinlock_Q_BLOCKING ti_sdo_ipc_gates_GateHWSpinlock_Q_BLOCKING
#define GateHWSpinlock_Q_PREEMPTING ti_sdo_ipc_gates_GateHWSpinlock_Q_PREEMPTING
#define GateHWSpinlock_Instance_State ti_sdo_ipc_gates_GateHWSpinlock_Instance_State
#define GateHWSpinlock_LM_enter ti_sdo_ipc_gates_GateHWSpinlock_LM_enter
#define GateHWSpinlock_LM_leave ti_sdo_ipc_gates_GateHWSpinlock_LM_leave
#define GateHWSpinlock_LM_create ti_sdo_ipc_gates_GateHWSpinlock_LM_create
#define GateHWSpinlock_LM_open ti_sdo_ipc_gates_GateHWSpinlock_LM_open
#define GateHWSpinlock_LM_delete ti_sdo_ipc_gates_GateHWSpinlock_LM_delete
#define GateHWSpinlock_LM_close ti_sdo_ipc_gates_GateHWSpinlock_LM_close
#define GateHWSpinlock_A_invSpinLockNum ti_sdo_ipc_gates_GateHWSpinlock_A_invSpinLockNum
#define GateHWSpinlock_baseAddr ti_sdo_ipc_gates_GateHWSpinlock_baseAddr
#define GateHWSpinlock_numLocks ti_sdo_ipc_gates_GateHWSpinlock_numLocks
#define GateHWSpinlock_reservedMaskArr ti_sdo_ipc_gates_GateHWSpinlock_reservedMaskArr
#define GateHWSpinlock_Params ti_sdo_ipc_gates_GateHWSpinlock_Params
#define GateHWSpinlock_query ti_sdo_ipc_gates_GateHWSpinlock_query
#define GateHWSpinlock_getReservedMask ti_sdo_ipc_gates_GateHWSpinlock_getReservedMask
#define GateHWSpinlock_sharedMemReq ti_sdo_ipc_gates_GateHWSpinlock_sharedMemReq
#define GateHWSpinlock_enter ti_sdo_ipc_gates_GateHWSpinlock_enter
#define GateHWSpinlock_leave ti_sdo_ipc_gates_GateHWSpinlock_leave
#define GateHWSpinlock_Module_name ti_sdo_ipc_gates_GateHWSpinlock_Module_name
#define GateHWSpinlock_Module_id ti_sdo_ipc_gates_GateHWSpinlock_Module_id
#define GateHWSpinlock_Module_startup ti_sdo_ipc_gates_GateHWSpinlock_Module_startup
#define GateHWSpinlock_Module_startupDone ti_sdo_ipc_gates_GateHWSpinlock_Module_startupDone
#define GateHWSpinlock_Module_hasMask ti_sdo_ipc_gates_GateHWSpinlock_Module_hasMask
#define GateHWSpinlock_Module_getMask ti_sdo_ipc_gates_GateHWSpinlock_Module_getMask
#define GateHWSpinlock_Module_setMask ti_sdo_ipc_gates_GateHWSpinlock_Module_setMask
#define GateHWSpinlock_Object_heap ti_sdo_ipc_gates_GateHWSpinlock_Object_heap
#define GateHWSpinlock_Module_heap ti_sdo_ipc_gates_GateHWSpinlock_Module_heap
#define GateHWSpinlock_construct ti_sdo_ipc_gates_GateHWSpinlock_construct
#define GateHWSpinlock_create ti_sdo_ipc_gates_GateHWSpinlock_create
#define GateHWSpinlock_handle ti_sdo_ipc_gates_GateHWSpinlock_handle
#define GateHWSpinlock_struct ti_sdo_ipc_gates_GateHWSpinlock_struct
#define GateHWSpinlock_Handle_label ti_sdo_ipc_gates_GateHWSpinlock_Handle_label
#define GateHWSpinlock_Handle_name ti_sdo_ipc_gates_GateHWSpinlock_Handle_name
#define GateHWSpinlock_Instance_init ti_sdo_ipc_gates_GateHWSpinlock_Instance_init
#define GateHWSpinlock_Object_count ti_sdo_ipc_gates_GateHWSpinlock_Object_count
#define GateHWSpinlock_Object_get ti_sdo_ipc_gates_GateHWSpinlock_Object_get
#define GateHWSpinlock_Object_first ti_sdo_ipc_gates_GateHWSpinlock_Object_first
#define GateHWSpinlock_Object_next ti_sdo_ipc_gates_GateHWSpinlock_Object_next
#define GateHWSpinlock_Object_sizeof ti_sdo_ipc_gates_GateHWSpinlock_Object_sizeof
#define GateHWSpinlock_Params_copy ti_sdo_ipc_gates_GateHWSpinlock_Params_copy
#define GateHWSpinlock_Params_init ti_sdo_ipc_gates_GateHWSpinlock_Params_init
#define GateHWSpinlock_delete ti_sdo_ipc_gates_GateHWSpinlock_delete
#define GateHWSpinlock_destruct ti_sdo_ipc_gates_GateHWSpinlock_destruct
#define GateHWSpinlock_Module_upCast ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast
#define GateHWSpinlock_Module_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateHWSpinlock_Module_to_ti_sdo_ipc_interfaces_IGateMPSupport
#define GateHWSpinlock_Handle_upCast ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast
#define GateHWSpinlock_Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateHWSpinlock_Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport
#define GateHWSpinlock_Handle_downCast ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast
#define GateHWSpinlock_Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateHWSpinlock_Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport
#define GateHWSpinlock_Module_upCast2 ti_sdo_ipc_gates_GateHWSpinlock_Module_upCast2
#define GateHWSpinlock_Module_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateHWSpinlock_Module_to_xdc_runtime_IGateProvider
#define GateHWSpinlock_Handle_upCast2 ti_sdo_ipc_gates_GateHWSpinlock_Handle_upCast2
#define GateHWSpinlock_Handle_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateHWSpinlock_Handle_to_xdc_runtime_IGateProvider
#define GateHWSpinlock_Handle_downCast2 ti_sdo_ipc_gates_GateHWSpinlock_Handle_downCast2
#define GateHWSpinlock_Handle_from_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateHWSpinlock_Handle_from_xdc_runtime_IGateProvider

#endif /* ti_sdo_ipc_gates_GateHWSpinlock__localnames__done */
#endif
