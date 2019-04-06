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

#ifndef ti_sdo_ipc_gates_GateAAMonitor__include
#define ti_sdo_ipc_gates_GateAAMonitor__include

#ifndef __nested__
#define __nested__
#define ti_sdo_ipc_gates_GateAAMonitor__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_ipc_gates_GateAAMonitor___VERS 200


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
#include <ti/sdo/ipc/Ipc.h>
#include <ti/sdo/ipc/interfaces/IGateMPSupport.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define ti_sdo_ipc_gates_GateAAMonitor_Q_BLOCKING (1)

/* Q_PREEMPTING */
#define ti_sdo_ipc_gates_GateAAMonitor_Q_PREEMPTING (2)


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sdo_ipc_gates_GateAAMonitor_Args__create {
    xdc_runtime_IGateProvider_Handle localGate;
} ti_sdo_ipc_gates_GateAAMonitor_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* CACHELINE_SIZE */
#define ti_sdo_ipc_gates_GateAAMonitor_CACHELINE_SIZE (64)

/* SL2_RANGE_BASE */
#define ti_sdo_ipc_gates_GateAAMonitor_SL2_RANGE_BASE (0x00200000)

/* SL2_RANGE_MAX */
#define ti_sdo_ipc_gates_GateAAMonitor_SL2_RANGE_MAX (0x002bffff)


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled (ti_sdo_ipc_gates_GateAAMonitor_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded (ti_sdo_ipc_gates_GateAAMonitor_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask (ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj (ti_sdo_ipc_gates_GateAAMonitor_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms (ti_sdo_ipc_gates_GateAAMonitor_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_ipc_gates_GateAAMonitor_Module__id;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__id ti_sdo_ipc_gates_GateAAMonitor_Module__id__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__id__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__id__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__id*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__id__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__id (ti_sdo_ipc_gates_GateAAMonitor_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0 ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0 (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1 ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1 (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2 ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2 (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4 ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4 (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8 ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8 (ti_sdo_ipc_gates_GateAAMonitor_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_sdo_ipc_gates_GateAAMonitor_Object__count;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Object__count ti_sdo_ipc_gates_GateAAMonitor_Object__count__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Object__count__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Object__count__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Object__count*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Object__count__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Object__count (ti_sdo_ipc_gates_GateAAMonitor_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_ipc_gates_GateAAMonitor_Object__heap;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Object__heap ti_sdo_ipc_gates_GateAAMonitor_Object__heap__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Object__heap__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Object__heap__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Object__heap*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Object__heap__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Object__heap (ti_sdo_ipc_gates_GateAAMonitor_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof (ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_ipc_gates_GateAAMonitor_Object__table;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_Object__table ti_sdo_ipc_gates_GateAAMonitor_Object__table__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_Object__table__CR
#define ti_sdo_ipc_gates_GateAAMonitor_Object__table__C (*((CT__ti_sdo_ipc_gates_GateAAMonitor_Object__table*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Object__table__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Object__table (ti_sdo_ipc_gates_GateAAMonitor_Object__table__C)
#endif

/* A_invSharedAddr */
typedef xdc_runtime_Assert_Id CT__ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr__CR
#define ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr (*((CT__ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr__C_offset)))
#else
#define ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr (ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr__C)
#endif

/* numInstances */
typedef xdc_UInt CT__ti_sdo_ipc_gates_GateAAMonitor_numInstances;
__extern __FAR__ const CT__ti_sdo_ipc_gates_GateAAMonitor_numInstances ti_sdo_ipc_gates_GateAAMonitor_numInstances__C;
#ifdef ti_sdo_ipc_gates_GateAAMonitor_numInstances__CR
#define ti_sdo_ipc_gates_GateAAMonitor_numInstances (*((CT__ti_sdo_ipc_gates_GateAAMonitor_numInstances*)(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_numInstances__C_offset)))
#else
#ifdef ti_sdo_ipc_gates_GateAAMonitor_numInstances__D
#define ti_sdo_ipc_gates_GateAAMonitor_numInstances (ti_sdo_ipc_gates_GateAAMonitor_numInstances__D)
#else
#define ti_sdo_ipc_gates_GateAAMonitor_numInstances (ti_sdo_ipc_gates_GateAAMonitor_numInstances__C)
#endif
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sdo_ipc_gates_GateAAMonitor_Params {
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
struct ti_sdo_ipc_gates_GateAAMonitor_Struct {
    const ti_sdo_ipc_gates_GateAAMonitor_Fxns__ *__fxns;
    volatile xdc_UInt32 *__f0;
    xdc_UInt __f1;
    xdc_runtime_IGateProvider_Handle __f2;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_ipc_gates_GateAAMonitor_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bool (*query)(xdc_Int qual);
    xdc_IArg (*enter)(ti_sdo_ipc_gates_GateAAMonitor_Handle __inst);
    xdc_Void (*leave)(ti_sdo_ipc_gates_GateAAMonitor_Handle __inst, xdc_IArg key);
    xdc_Bits32 *(*getReservedMask)(void);
    xdc_SizeT (*sharedMemReq)(const ti_sdo_ipc_interfaces_IGateMPSupport_Params* params);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__CR

/* Module__FXNS__C */
__extern const ti_sdo_ipc_gates_GateAAMonitor_Fxns__ ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C;
#else
#define ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C (*(xdcRomConstPtr + ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C_offset))
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_ipc_gates_GateAAMonitor_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Instance_init__E, "ti_sdo_ipc_gates_GateAAMonitor_Instance_init")
__extern xdc_Int ti_sdo_ipc_gates_GateAAMonitor_Instance_init__E(ti_sdo_ipc_gates_GateAAMonitor_Object *__obj, xdc_runtime_IGateProvider_Handle localGate, const ti_sdo_ipc_gates_GateAAMonitor_Params *__prms, xdc_runtime_Error_Block *__eb);

/* create */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_create, "ti_sdo_ipc_gates_GateAAMonitor_create")
__extern ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_create( xdc_runtime_IGateProvider_Handle localGate, const ti_sdo_ipc_gates_GateAAMonitor_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_construct, "ti_sdo_ipc_gates_GateAAMonitor_construct")
__extern void ti_sdo_ipc_gates_GateAAMonitor_construct( ti_sdo_ipc_gates_GateAAMonitor_Struct *__obj, xdc_runtime_IGateProvider_Handle localGate, const ti_sdo_ipc_gates_GateAAMonitor_Params *__prms, xdc_runtime_Error_Block *__eb );

/* delete */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_delete, "ti_sdo_ipc_gates_GateAAMonitor_delete")
__extern void ti_sdo_ipc_gates_GateAAMonitor_delete(ti_sdo_ipc_gates_GateAAMonitor_Handle *instp);

/* destruct */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_destruct, "ti_sdo_ipc_gates_GateAAMonitor_destruct")
__extern void ti_sdo_ipc_gates_GateAAMonitor_destruct(ti_sdo_ipc_gates_GateAAMonitor_Struct *obj);

/* Handle__label__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Handle__label__S, "ti_sdo_ipc_gates_GateAAMonitor_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sdo_ipc_gates_GateAAMonitor_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Module__startupDone__S, "ti_sdo_ipc_gates_GateAAMonitor_Module__startupDone__S")
__extern xdc_Bool ti_sdo_ipc_gates_GateAAMonitor_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Object__create__S, "ti_sdo_ipc_gates_GateAAMonitor_Object__create__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateAAMonitor_Object__create__S( xdc_CPtr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Object__delete__S, "ti_sdo_ipc_gates_GateAAMonitor_Object__delete__S")
__extern xdc_Void ti_sdo_ipc_gates_GateAAMonitor_Object__delete__S( xdc_Ptr instp );

/* Object__get__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Object__get__S, "ti_sdo_ipc_gates_GateAAMonitor_Object__get__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateAAMonitor_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Object__first__S, "ti_sdo_ipc_gates_GateAAMonitor_Object__first__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateAAMonitor_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Object__next__S, "ti_sdo_ipc_gates_GateAAMonitor_Object__next__S")
__extern xdc_Ptr ti_sdo_ipc_gates_GateAAMonitor_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_Params__init__S, "ti_sdo_ipc_gates_GateAAMonitor_Params__init__S")
__extern xdc_Void ti_sdo_ipc_gates_GateAAMonitor_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* query__E */
#define ti_sdo_ipc_gates_GateAAMonitor_query ti_sdo_ipc_gates_GateAAMonitor_query__E
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_query__E, "ti_sdo_ipc_gates_GateAAMonitor_query")
__extern xdc_Bool ti_sdo_ipc_gates_GateAAMonitor_query__E( xdc_Int qual );

/* enter__E */
#define ti_sdo_ipc_gates_GateAAMonitor_enter ti_sdo_ipc_gates_GateAAMonitor_enter__E
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_enter__E, "ti_sdo_ipc_gates_GateAAMonitor_enter")
__extern xdc_IArg ti_sdo_ipc_gates_GateAAMonitor_enter__E( ti_sdo_ipc_gates_GateAAMonitor_Handle __inst );

/* leave__E */
#define ti_sdo_ipc_gates_GateAAMonitor_leave ti_sdo_ipc_gates_GateAAMonitor_leave__E
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_leave__E, "ti_sdo_ipc_gates_GateAAMonitor_leave")
__extern xdc_Void ti_sdo_ipc_gates_GateAAMonitor_leave__E( ti_sdo_ipc_gates_GateAAMonitor_Handle __inst, xdc_IArg key );

/* getReservedMask__E */
#define ti_sdo_ipc_gates_GateAAMonitor_getReservedMask ti_sdo_ipc_gates_GateAAMonitor_getReservedMask__E
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_getReservedMask__E, "ti_sdo_ipc_gates_GateAAMonitor_getReservedMask")
__extern xdc_Bits32 *ti_sdo_ipc_gates_GateAAMonitor_getReservedMask__E( void );

/* sharedMemReq__E */
#define ti_sdo_ipc_gates_GateAAMonitor_sharedMemReq ti_sdo_ipc_gates_GateAAMonitor_sharedMemReq__E
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_sharedMemReq__E, "ti_sdo_ipc_gates_GateAAMonitor_sharedMemReq")
__extern xdc_SizeT ti_sdo_ipc_gates_GateAAMonitor_sharedMemReq__E( const ti_sdo_ipc_interfaces_IGateMPSupport_Params *params );

/* getLock__I */
#define ti_sdo_ipc_gates_GateAAMonitor_getLock ti_sdo_ipc_gates_GateAAMonitor_getLock__I
xdc__CODESECT(ti_sdo_ipc_gates_GateAAMonitor_getLock__I, "ti_sdo_ipc_gates_GateAAMonitor_getLock")
__extern xdc_UInt ti_sdo_ipc_gates_GateAAMonitor_getLock__I( xdc_Ptr sharedAddr );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Module ti_sdo_ipc_gates_GateAAMonitor_Module_upCast(void);
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Module ti_sdo_ipc_gates_GateAAMonitor_Module_upCast(void)
{
    return (ti_sdo_ipc_interfaces_IGateMPSupport_Module)&ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_interfaces_IGateMPSupport */
#define ti_sdo_ipc_gates_GateAAMonitor_Module_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateAAMonitor_Module_upCast

/* Handle_upCast */
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast(ti_sdo_ipc_gates_GateAAMonitor_Handle i);
static inline ti_sdo_ipc_interfaces_IGateMPSupport_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast(ti_sdo_ipc_gates_GateAAMonitor_Handle i)
{
    return (ti_sdo_ipc_interfaces_IGateMPSupport_Handle)i;
}

/* Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport */
#define ti_sdo_ipc_gates_GateAAMonitor_Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast

/* Handle_downCast */
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast(ti_sdo_ipc_interfaces_IGateMPSupport_Handle i);
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast(ti_sdo_ipc_interfaces_IGateMPSupport_Handle i)
{
    ti_sdo_ipc_interfaces_IGateMPSupport_Handle i2 = (ti_sdo_ipc_interfaces_IGateMPSupport_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C ? (ti_sdo_ipc_gates_GateAAMonitor_Handle)i : (ti_sdo_ipc_gates_GateAAMonitor_Handle)0;
}

/* Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport */
#define ti_sdo_ipc_gates_GateAAMonitor_Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast

/* Module_upCast2 */
static inline xdc_runtime_IGateProvider_Module ti_sdo_ipc_gates_GateAAMonitor_Module_upCast2(void);
static inline xdc_runtime_IGateProvider_Module ti_sdo_ipc_gates_GateAAMonitor_Module_upCast2(void)
{
    return (xdc_runtime_IGateProvider_Module)&ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IGateProvider */
#define ti_sdo_ipc_gates_GateAAMonitor_Module_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateAAMonitor_Module_upCast2

/* Handle_upCast2 */
static inline xdc_runtime_IGateProvider_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast2(ti_sdo_ipc_gates_GateAAMonitor_Handle i);
static inline xdc_runtime_IGateProvider_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast2(ti_sdo_ipc_gates_GateAAMonitor_Handle i)
{
    return (xdc_runtime_IGateProvider_Handle)i;
}

/* Handle_to_xdc_runtime_IGateProvider */
#define ti_sdo_ipc_gates_GateAAMonitor_Handle_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast2

/* Handle_downCast2 */
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast2(xdc_runtime_IGateProvider_Handle i);
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast2(xdc_runtime_IGateProvider_Handle i)
{
    xdc_runtime_IGateProvider_Handle i2 = (xdc_runtime_IGateProvider_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_sdo_ipc_gates_GateAAMonitor_Module__FXNS__C ? (ti_sdo_ipc_gates_GateAAMonitor_Handle)i : (ti_sdo_ipc_gates_GateAAMonitor_Handle)0;
}

/* Handle_from_xdc_runtime_IGateProvider */
#define ti_sdo_ipc_gates_GateAAMonitor_Handle_from_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_ipc_gates_GateAAMonitor_Module_startupDone() ti_sdo_ipc_gates_GateAAMonitor_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_ipc_gates_GateAAMonitor_Object_heap() ti_sdo_ipc_gates_GateAAMonitor_Object__heap__C

/* Module_heap */
#define ti_sdo_ipc_gates_GateAAMonitor_Module_heap() ti_sdo_ipc_gates_GateAAMonitor_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_ipc_gates_GateAAMonitor_Module__id ti_sdo_ipc_gates_GateAAMonitor_Module_id(void);
static inline CT__ti_sdo_ipc_gates_GateAAMonitor_Module__id ti_sdo_ipc_gates_GateAAMonitor_Module_id( void ) 
{
    return ti_sdo_ipc_gates_GateAAMonitor_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_ipc_gates_GateAAMonitor_Module_hasMask(void);
static inline xdc_Bool ti_sdo_ipc_gates_GateAAMonitor_Module_hasMask(void) 
{
    return (xdc_Bool)(ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_ipc_gates_GateAAMonitor_Module_getMask(void);
static inline xdc_Bits16 ti_sdo_ipc_gates_GateAAMonitor_Module_getMask( void ) 
{
    return ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C != NULL ? *ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_ipc_gates_GateAAMonitor_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_sdo_ipc_gates_GateAAMonitor_Module_setMask(xdc_Bits16 mask)
{
    if (ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C != NULL) {
        *ti_sdo_ipc_gates_GateAAMonitor_Module__diagsMask__C = mask;
    }
}

/* Params_init */
static inline void ti_sdo_ipc_gates_GateAAMonitor_Params_init(ti_sdo_ipc_gates_GateAAMonitor_Params *prms);
static inline void ti_sdo_ipc_gates_GateAAMonitor_Params_init( ti_sdo_ipc_gates_GateAAMonitor_Params *prms ) 
{
    if (prms) {
        ti_sdo_ipc_gates_GateAAMonitor_Params__init__S(prms, 0, sizeof(ti_sdo_ipc_gates_GateAAMonitor_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sdo_ipc_gates_GateAAMonitor_Params_copy(ti_sdo_ipc_gates_GateAAMonitor_Params *dst, const ti_sdo_ipc_gates_GateAAMonitor_Params *src);
static inline void ti_sdo_ipc_gates_GateAAMonitor_Params_copy(ti_sdo_ipc_gates_GateAAMonitor_Params *dst, const ti_sdo_ipc_gates_GateAAMonitor_Params *src) 
{
    if (dst) {
        ti_sdo_ipc_gates_GateAAMonitor_Params__init__S(dst, (const void *)src, sizeof(ti_sdo_ipc_gates_GateAAMonitor_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sdo_ipc_gates_GateAAMonitor_Object_count() ti_sdo_ipc_gates_GateAAMonitor_Object__count__C

/* Object_sizeof */
#define ti_sdo_ipc_gates_GateAAMonitor_Object_sizeof() ti_sdo_ipc_gates_GateAAMonitor_Object__sizeof__C

/* Object_get */
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Object_get(ti_sdo_ipc_gates_GateAAMonitor_Instance_State *oarr, int i);
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Object_get(ti_sdo_ipc_gates_GateAAMonitor_Instance_State *oarr, int i) 
{
    return (ti_sdo_ipc_gates_GateAAMonitor_Handle)ti_sdo_ipc_gates_GateAAMonitor_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Object_first(void);
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Object_first(void)
{
    return (ti_sdo_ipc_gates_GateAAMonitor_Handle)ti_sdo_ipc_gates_GateAAMonitor_Object__first__S();
}

/* Object_next */
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Object_next(ti_sdo_ipc_gates_GateAAMonitor_Object *obj);
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Object_next(ti_sdo_ipc_gates_GateAAMonitor_Object *obj)
{
    return (ti_sdo_ipc_gates_GateAAMonitor_Handle)ti_sdo_ipc_gates_GateAAMonitor_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sdo_ipc_gates_GateAAMonitor_Handle_label(ti_sdo_ipc_gates_GateAAMonitor_Handle inst, xdc_runtime_Types_Label *lab);
static inline xdc_runtime_Types_Label *ti_sdo_ipc_gates_GateAAMonitor_Handle_label(ti_sdo_ipc_gates_GateAAMonitor_Handle inst, xdc_runtime_Types_Label *lab)
{
    return ti_sdo_ipc_gates_GateAAMonitor_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sdo_ipc_gates_GateAAMonitor_Handle_name(ti_sdo_ipc_gates_GateAAMonitor_Handle inst);
static inline xdc_String ti_sdo_ipc_gates_GateAAMonitor_Handle_name(ti_sdo_ipc_gates_GateAAMonitor_Handle inst)
{
    xdc_runtime_Types_Label lab;
    return ti_sdo_ipc_gates_GateAAMonitor_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_handle(ti_sdo_ipc_gates_GateAAMonitor_Struct *str);
static inline ti_sdo_ipc_gates_GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_handle(ti_sdo_ipc_gates_GateAAMonitor_Struct *str)
{
    return (ti_sdo_ipc_gates_GateAAMonitor_Handle)str;
}

/* struct */
static inline ti_sdo_ipc_gates_GateAAMonitor_Struct *ti_sdo_ipc_gates_GateAAMonitor_struct(ti_sdo_ipc_gates_GateAAMonitor_Handle inst);
static inline ti_sdo_ipc_gates_GateAAMonitor_Struct *ti_sdo_ipc_gates_GateAAMonitor_struct(ti_sdo_ipc_gates_GateAAMonitor_Handle inst)
{
    return (ti_sdo_ipc_gates_GateAAMonitor_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_ipc_gates_GateAAMonitor__top__
#undef __nested__
#endif

#endif /* ti_sdo_ipc_gates_GateAAMonitor__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_ipc_gates_GateAAMonitor__internalaccess))

#ifndef ti_sdo_ipc_gates_GateAAMonitor__include_state
#define ti_sdo_ipc_gates_GateAAMonitor__include_state

/* Object */
struct ti_sdo_ipc_gates_GateAAMonitor_Object {
    const ti_sdo_ipc_gates_GateAAMonitor_Fxns__ *__fxns;
    volatile xdc_UInt32 *sharedAddr;
    xdc_UInt nested;
    xdc_runtime_IGateProvider_Handle localGate;
};

#endif /* ti_sdo_ipc_gates_GateAAMonitor__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_ipc_gates_GateAAMonitor__nolocalnames)

#ifndef ti_sdo_ipc_gates_GateAAMonitor__localnames__done
#define ti_sdo_ipc_gates_GateAAMonitor__localnames__done

/* module prefix */
#define GateAAMonitor_Instance ti_sdo_ipc_gates_GateAAMonitor_Instance
#define GateAAMonitor_Handle ti_sdo_ipc_gates_GateAAMonitor_Handle
#define GateAAMonitor_Module ti_sdo_ipc_gates_GateAAMonitor_Module
#define GateAAMonitor_Object ti_sdo_ipc_gates_GateAAMonitor_Object
#define GateAAMonitor_Struct ti_sdo_ipc_gates_GateAAMonitor_Struct
#define GateAAMonitor_Q_BLOCKING ti_sdo_ipc_gates_GateAAMonitor_Q_BLOCKING
#define GateAAMonitor_Q_PREEMPTING ti_sdo_ipc_gates_GateAAMonitor_Q_PREEMPTING
#define GateAAMonitor_CACHELINE_SIZE ti_sdo_ipc_gates_GateAAMonitor_CACHELINE_SIZE
#define GateAAMonitor_SL2_RANGE_BASE ti_sdo_ipc_gates_GateAAMonitor_SL2_RANGE_BASE
#define GateAAMonitor_SL2_RANGE_MAX ti_sdo_ipc_gates_GateAAMonitor_SL2_RANGE_MAX
#define GateAAMonitor_Instance_State ti_sdo_ipc_gates_GateAAMonitor_Instance_State
#define GateAAMonitor_A_invSharedAddr ti_sdo_ipc_gates_GateAAMonitor_A_invSharedAddr
#define GateAAMonitor_numInstances ti_sdo_ipc_gates_GateAAMonitor_numInstances
#define GateAAMonitor_Params ti_sdo_ipc_gates_GateAAMonitor_Params
#define GateAAMonitor_query ti_sdo_ipc_gates_GateAAMonitor_query
#define GateAAMonitor_enter ti_sdo_ipc_gates_GateAAMonitor_enter
#define GateAAMonitor_leave ti_sdo_ipc_gates_GateAAMonitor_leave
#define GateAAMonitor_getReservedMask ti_sdo_ipc_gates_GateAAMonitor_getReservedMask
#define GateAAMonitor_sharedMemReq ti_sdo_ipc_gates_GateAAMonitor_sharedMemReq
#define GateAAMonitor_Module_name ti_sdo_ipc_gates_GateAAMonitor_Module_name
#define GateAAMonitor_Module_id ti_sdo_ipc_gates_GateAAMonitor_Module_id
#define GateAAMonitor_Module_startup ti_sdo_ipc_gates_GateAAMonitor_Module_startup
#define GateAAMonitor_Module_startupDone ti_sdo_ipc_gates_GateAAMonitor_Module_startupDone
#define GateAAMonitor_Module_hasMask ti_sdo_ipc_gates_GateAAMonitor_Module_hasMask
#define GateAAMonitor_Module_getMask ti_sdo_ipc_gates_GateAAMonitor_Module_getMask
#define GateAAMonitor_Module_setMask ti_sdo_ipc_gates_GateAAMonitor_Module_setMask
#define GateAAMonitor_Object_heap ti_sdo_ipc_gates_GateAAMonitor_Object_heap
#define GateAAMonitor_Module_heap ti_sdo_ipc_gates_GateAAMonitor_Module_heap
#define GateAAMonitor_construct ti_sdo_ipc_gates_GateAAMonitor_construct
#define GateAAMonitor_create ti_sdo_ipc_gates_GateAAMonitor_create
#define GateAAMonitor_handle ti_sdo_ipc_gates_GateAAMonitor_handle
#define GateAAMonitor_struct ti_sdo_ipc_gates_GateAAMonitor_struct
#define GateAAMonitor_Handle_label ti_sdo_ipc_gates_GateAAMonitor_Handle_label
#define GateAAMonitor_Handle_name ti_sdo_ipc_gates_GateAAMonitor_Handle_name
#define GateAAMonitor_Instance_init ti_sdo_ipc_gates_GateAAMonitor_Instance_init
#define GateAAMonitor_Object_count ti_sdo_ipc_gates_GateAAMonitor_Object_count
#define GateAAMonitor_Object_get ti_sdo_ipc_gates_GateAAMonitor_Object_get
#define GateAAMonitor_Object_first ti_sdo_ipc_gates_GateAAMonitor_Object_first
#define GateAAMonitor_Object_next ti_sdo_ipc_gates_GateAAMonitor_Object_next
#define GateAAMonitor_Object_sizeof ti_sdo_ipc_gates_GateAAMonitor_Object_sizeof
#define GateAAMonitor_Params_copy ti_sdo_ipc_gates_GateAAMonitor_Params_copy
#define GateAAMonitor_Params_init ti_sdo_ipc_gates_GateAAMonitor_Params_init
#define GateAAMonitor_delete ti_sdo_ipc_gates_GateAAMonitor_delete
#define GateAAMonitor_destruct ti_sdo_ipc_gates_GateAAMonitor_destruct
#define GateAAMonitor_Module_upCast ti_sdo_ipc_gates_GateAAMonitor_Module_upCast
#define GateAAMonitor_Module_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateAAMonitor_Module_to_ti_sdo_ipc_interfaces_IGateMPSupport
#define GateAAMonitor_Handle_upCast ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast
#define GateAAMonitor_Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateAAMonitor_Handle_to_ti_sdo_ipc_interfaces_IGateMPSupport
#define GateAAMonitor_Handle_downCast ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast
#define GateAAMonitor_Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport ti_sdo_ipc_gates_GateAAMonitor_Handle_from_ti_sdo_ipc_interfaces_IGateMPSupport
#define GateAAMonitor_Module_upCast2 ti_sdo_ipc_gates_GateAAMonitor_Module_upCast2
#define GateAAMonitor_Module_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateAAMonitor_Module_to_xdc_runtime_IGateProvider
#define GateAAMonitor_Handle_upCast2 ti_sdo_ipc_gates_GateAAMonitor_Handle_upCast2
#define GateAAMonitor_Handle_to_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateAAMonitor_Handle_to_xdc_runtime_IGateProvider
#define GateAAMonitor_Handle_downCast2 ti_sdo_ipc_gates_GateAAMonitor_Handle_downCast2
#define GateAAMonitor_Handle_from_xdc_runtime_IGateProvider ti_sdo_ipc_gates_GateAAMonitor_Handle_from_xdc_runtime_IGateProvider

#endif /* ti_sdo_ipc_gates_GateAAMonitor__localnames__done */
#endif
