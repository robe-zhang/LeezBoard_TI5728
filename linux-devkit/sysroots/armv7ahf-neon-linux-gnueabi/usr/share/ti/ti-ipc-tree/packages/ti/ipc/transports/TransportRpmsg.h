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

#ifndef ti_ipc_transports_TransportRpmsg__include
#define ti_ipc_transports_TransportRpmsg__include

#ifndef __nested__
#define __nested__
#define ti_ipc_transports_TransportRpmsg__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_ipc_transports_TransportRpmsg___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/ipc/transports/package/package.defs.h>

#include <ti/sdo/ipc/interfaces/IMessageQTransport.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Status */
typedef ti_sdo_ipc_interfaces_IMessageQTransport_Status ti_ipc_transports_TransportRpmsg_Status;

/* Reason */
typedef ti_sdo_ipc_interfaces_IMessageQTransport_Reason ti_ipc_transports_TransportRpmsg_Reason;

/* ErrFxn */
typedef ti_sdo_ipc_interfaces_IMessageQTransport_ErrFxn ti_ipc_transports_TransportRpmsg_ErrFxn;

/* S_SUCCESS */
#define ti_ipc_transports_TransportRpmsg_S_SUCCESS ti_sdo_ipc_interfaces_IMessageQTransport_S_SUCCESS

/* E_FAIL */
#define ti_ipc_transports_TransportRpmsg_E_FAIL ti_sdo_ipc_interfaces_IMessageQTransport_E_FAIL

/* E_ERROR */
#define ti_ipc_transports_TransportRpmsg_E_ERROR ti_sdo_ipc_interfaces_IMessageQTransport_E_ERROR

/* Reason_FAILEDPUT */
#define ti_ipc_transports_TransportRpmsg_Reason_FAILEDPUT ti_sdo_ipc_interfaces_IMessageQTransport_Reason_FAILEDPUT

/* Reason_INTERNALERR */
#define ti_ipc_transports_TransportRpmsg_Reason_INTERNALERR ti_sdo_ipc_interfaces_IMessageQTransport_Reason_INTERNALERR

/* Reason_PHYSICALERR */
#define ti_ipc_transports_TransportRpmsg_Reason_PHYSICALERR ti_sdo_ipc_interfaces_IMessageQTransport_Reason_PHYSICALERR

/* Reason_FAILEDALLOC */
#define ti_ipc_transports_TransportRpmsg_Reason_FAILEDALLOC ti_sdo_ipc_interfaces_IMessageQTransport_Reason_FAILEDALLOC


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_ipc_transports_TransportRpmsg_Args__create {
    xdc_UInt16 procId;
} ti_ipc_transports_TransportRpmsg_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_ipc_transports_TransportRpmsg_Module__diagsEnabled;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__diagsEnabled ti_ipc_transports_TransportRpmsg_Module__diagsEnabled__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__diagsEnabled__CR
#define ti_ipc_transports_TransportRpmsg_Module__diagsEnabled__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__diagsEnabled*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__diagsEnabled__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__diagsEnabled (ti_ipc_transports_TransportRpmsg_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_ipc_transports_TransportRpmsg_Module__diagsIncluded;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__diagsIncluded ti_ipc_transports_TransportRpmsg_Module__diagsIncluded__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__diagsIncluded__CR
#define ti_ipc_transports_TransportRpmsg_Module__diagsIncluded__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__diagsIncluded*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__diagsIncluded__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__diagsIncluded (ti_ipc_transports_TransportRpmsg_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_ipc_transports_TransportRpmsg_Module__diagsMask;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__diagsMask ti_ipc_transports_TransportRpmsg_Module__diagsMask__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__diagsMask__CR
#define ti_ipc_transports_TransportRpmsg_Module__diagsMask__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__diagsMask*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__diagsMask__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__diagsMask (ti_ipc_transports_TransportRpmsg_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_ipc_transports_TransportRpmsg_Module__gateObj;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__gateObj ti_ipc_transports_TransportRpmsg_Module__gateObj__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__gateObj__CR
#define ti_ipc_transports_TransportRpmsg_Module__gateObj__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__gateObj*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__gateObj__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__gateObj (ti_ipc_transports_TransportRpmsg_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_ipc_transports_TransportRpmsg_Module__gatePrms;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__gatePrms ti_ipc_transports_TransportRpmsg_Module__gatePrms__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__gatePrms__CR
#define ti_ipc_transports_TransportRpmsg_Module__gatePrms__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__gatePrms*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__gatePrms__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__gatePrms (ti_ipc_transports_TransportRpmsg_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_ipc_transports_TransportRpmsg_Module__id;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__id ti_ipc_transports_TransportRpmsg_Module__id__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__id__CR
#define ti_ipc_transports_TransportRpmsg_Module__id__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__id*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__id__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__id (ti_ipc_transports_TransportRpmsg_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_ipc_transports_TransportRpmsg_Module__loggerDefined;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerDefined ti_ipc_transports_TransportRpmsg_Module__loggerDefined__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerDefined__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerDefined__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerDefined*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerDefined__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerDefined (ti_ipc_transports_TransportRpmsg_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_ipc_transports_TransportRpmsg_Module__loggerObj;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerObj ti_ipc_transports_TransportRpmsg_Module__loggerObj__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerObj__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerObj__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerObj*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerObj__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerObj (ti_ipc_transports_TransportRpmsg_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn0;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn0 ti_ipc_transports_TransportRpmsg_Module__loggerFxn0__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerFxn0__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn0__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn0*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerFxn0__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn0 (ti_ipc_transports_TransportRpmsg_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn1;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn1 ti_ipc_transports_TransportRpmsg_Module__loggerFxn1__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerFxn1__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn1__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn1*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerFxn1__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn1 (ti_ipc_transports_TransportRpmsg_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn2;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn2 ti_ipc_transports_TransportRpmsg_Module__loggerFxn2__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerFxn2__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn2__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn2*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerFxn2__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn2 (ti_ipc_transports_TransportRpmsg_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn4;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn4 ti_ipc_transports_TransportRpmsg_Module__loggerFxn4__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerFxn4__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn4__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn4*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerFxn4__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn4 (ti_ipc_transports_TransportRpmsg_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn8;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn8 ti_ipc_transports_TransportRpmsg_Module__loggerFxn8__C;
#ifdef ti_ipc_transports_TransportRpmsg_Module__loggerFxn8__CR
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn8__C (*((CT__ti_ipc_transports_TransportRpmsg_Module__loggerFxn8*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__loggerFxn8__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Module__loggerFxn8 (ti_ipc_transports_TransportRpmsg_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_ipc_transports_TransportRpmsg_Object__count;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Object__count ti_ipc_transports_TransportRpmsg_Object__count__C;
#ifdef ti_ipc_transports_TransportRpmsg_Object__count__CR
#define ti_ipc_transports_TransportRpmsg_Object__count__C (*((CT__ti_ipc_transports_TransportRpmsg_Object__count*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Object__count__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Object__count (ti_ipc_transports_TransportRpmsg_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_ipc_transports_TransportRpmsg_Object__heap;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Object__heap ti_ipc_transports_TransportRpmsg_Object__heap__C;
#ifdef ti_ipc_transports_TransportRpmsg_Object__heap__CR
#define ti_ipc_transports_TransportRpmsg_Object__heap__C (*((CT__ti_ipc_transports_TransportRpmsg_Object__heap*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Object__heap__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Object__heap (ti_ipc_transports_TransportRpmsg_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_ipc_transports_TransportRpmsg_Object__sizeof;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Object__sizeof ti_ipc_transports_TransportRpmsg_Object__sizeof__C;
#ifdef ti_ipc_transports_TransportRpmsg_Object__sizeof__CR
#define ti_ipc_transports_TransportRpmsg_Object__sizeof__C (*((CT__ti_ipc_transports_TransportRpmsg_Object__sizeof*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Object__sizeof__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Object__sizeof (ti_ipc_transports_TransportRpmsg_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_ipc_transports_TransportRpmsg_Object__table;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_Object__table ti_ipc_transports_TransportRpmsg_Object__table__C;
#ifdef ti_ipc_transports_TransportRpmsg_Object__table__CR
#define ti_ipc_transports_TransportRpmsg_Object__table__C (*((CT__ti_ipc_transports_TransportRpmsg_Object__table*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Object__table__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_Object__table (ti_ipc_transports_TransportRpmsg_Object__table__C)
#endif

/* errFxn */
typedef ti_sdo_ipc_interfaces_IMessageQTransport_ErrFxn CT__ti_ipc_transports_TransportRpmsg_errFxn;
__extern __FAR__ const CT__ti_ipc_transports_TransportRpmsg_errFxn ti_ipc_transports_TransportRpmsg_errFxn__C;
#ifdef ti_ipc_transports_TransportRpmsg_errFxn__CR
#define ti_ipc_transports_TransportRpmsg_errFxn (*((CT__ti_ipc_transports_TransportRpmsg_errFxn*)(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_errFxn__C_offset)))
#else
#define ti_ipc_transports_TransportRpmsg_errFxn (ti_ipc_transports_TransportRpmsg_errFxn__C)
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_ipc_transports_TransportRpmsg_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_UInt priority;
    xdc_Ptr sharedAddr;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_ipc_transports_TransportRpmsg_Struct {
    const ti_ipc_transports_TransportRpmsg_Fxns__ *__fxns;
    xdc_UInt16 __f0;
    xdc_UInt16 __f1;
    xdc_Ptr __f2;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_ipc_transports_TransportRpmsg_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Void (*setErrFxn)(ti_sdo_ipc_interfaces_IMessageQTransport_ErrFxn errFxn);
    xdc_Int (*getStatus)(ti_ipc_transports_TransportRpmsg_Handle __inst);
    xdc_Bool (*put)(ti_ipc_transports_TransportRpmsg_Handle __inst, xdc_Ptr msg);
    xdc_Bool (*control)(ti_ipc_transports_TransportRpmsg_Handle __inst, xdc_UInt cmd, xdc_UArg cmdArg);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef ti_ipc_transports_TransportRpmsg_Module__FXNS__CR

/* Module__FXNS__C */
__extern const ti_ipc_transports_TransportRpmsg_Fxns__ ti_ipc_transports_TransportRpmsg_Module__FXNS__C;
#else
#define ti_ipc_transports_TransportRpmsg_Module__FXNS__C (*(xdcRomConstPtr + ti_ipc_transports_TransportRpmsg_Module__FXNS__C_offset))
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_ipc_transports_TransportRpmsg_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Instance_init__E, "ti_ipc_transports_TransportRpmsg_Instance_init")
__extern xdc_Int ti_ipc_transports_TransportRpmsg_Instance_init__E(ti_ipc_transports_TransportRpmsg_Object *__obj, xdc_UInt16 procId, const ti_ipc_transports_TransportRpmsg_Params *__prms, xdc_runtime_Error_Block *__eb);

/* Instance_finalize__E */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Instance_finalize__E, "ti_ipc_transports_TransportRpmsg_Instance_finalize")
__extern void ti_ipc_transports_TransportRpmsg_Instance_finalize__E(ti_ipc_transports_TransportRpmsg_Object *__obj, int __ec);

/* create */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_create, "ti_ipc_transports_TransportRpmsg_create")
__extern ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_create( xdc_UInt16 procId, const ti_ipc_transports_TransportRpmsg_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_construct, "ti_ipc_transports_TransportRpmsg_construct")
__extern void ti_ipc_transports_TransportRpmsg_construct( ti_ipc_transports_TransportRpmsg_Struct *__obj, xdc_UInt16 procId, const ti_ipc_transports_TransportRpmsg_Params *__prms, xdc_runtime_Error_Block *__eb );

/* delete */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_delete, "ti_ipc_transports_TransportRpmsg_delete")
__extern void ti_ipc_transports_TransportRpmsg_delete(ti_ipc_transports_TransportRpmsg_Handle *instp);

/* destruct */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_destruct, "ti_ipc_transports_TransportRpmsg_destruct")
__extern void ti_ipc_transports_TransportRpmsg_destruct(ti_ipc_transports_TransportRpmsg_Struct *obj);

/* Handle__label__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Handle__label__S, "ti_ipc_transports_TransportRpmsg_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_ipc_transports_TransportRpmsg_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Module__startupDone__S, "ti_ipc_transports_TransportRpmsg_Module__startupDone__S")
__extern xdc_Bool ti_ipc_transports_TransportRpmsg_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Object__create__S, "ti_ipc_transports_TransportRpmsg_Object__create__S")
__extern xdc_Ptr ti_ipc_transports_TransportRpmsg_Object__create__S( xdc_CPtr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Object__delete__S, "ti_ipc_transports_TransportRpmsg_Object__delete__S")
__extern xdc_Void ti_ipc_transports_TransportRpmsg_Object__delete__S( xdc_Ptr instp );

/* Object__get__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Object__get__S, "ti_ipc_transports_TransportRpmsg_Object__get__S")
__extern xdc_Ptr ti_ipc_transports_TransportRpmsg_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Object__first__S, "ti_ipc_transports_TransportRpmsg_Object__first__S")
__extern xdc_Ptr ti_ipc_transports_TransportRpmsg_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Object__next__S, "ti_ipc_transports_TransportRpmsg_Object__next__S")
__extern xdc_Ptr ti_ipc_transports_TransportRpmsg_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_Params__init__S, "ti_ipc_transports_TransportRpmsg_Params__init__S")
__extern xdc_Void ti_ipc_transports_TransportRpmsg_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* setErrFxn__E */
#define ti_ipc_transports_TransportRpmsg_setErrFxn ti_ipc_transports_TransportRpmsg_setErrFxn__E
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_setErrFxn__E, "ti_ipc_transports_TransportRpmsg_setErrFxn")
__extern xdc_Void ti_ipc_transports_TransportRpmsg_setErrFxn__E( ti_sdo_ipc_interfaces_IMessageQTransport_ErrFxn errFxn );

/* getStatus__E */
#define ti_ipc_transports_TransportRpmsg_getStatus ti_ipc_transports_TransportRpmsg_getStatus__E
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_getStatus__E, "ti_ipc_transports_TransportRpmsg_getStatus")
__extern xdc_Int ti_ipc_transports_TransportRpmsg_getStatus__E( ti_ipc_transports_TransportRpmsg_Handle __inst );

/* put__E */
#define ti_ipc_transports_TransportRpmsg_put ti_ipc_transports_TransportRpmsg_put__E
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_put__E, "ti_ipc_transports_TransportRpmsg_put")
__extern xdc_Bool ti_ipc_transports_TransportRpmsg_put__E( ti_ipc_transports_TransportRpmsg_Handle __inst, xdc_Ptr msg );

/* control__E */
#define ti_ipc_transports_TransportRpmsg_control ti_ipc_transports_TransportRpmsg_control__E
xdc__CODESECT(ti_ipc_transports_TransportRpmsg_control__E, "ti_ipc_transports_TransportRpmsg_control")
__extern xdc_Bool ti_ipc_transports_TransportRpmsg_control__E( ti_ipc_transports_TransportRpmsg_Handle __inst, xdc_UInt cmd, xdc_UArg cmdArg );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_ipc_interfaces_IMessageQTransport_Module ti_ipc_transports_TransportRpmsg_Module_upCast(void);
static inline ti_sdo_ipc_interfaces_IMessageQTransport_Module ti_ipc_transports_TransportRpmsg_Module_upCast(void)
{
    return (ti_sdo_ipc_interfaces_IMessageQTransport_Module)&ti_ipc_transports_TransportRpmsg_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_interfaces_IMessageQTransport */
#define ti_ipc_transports_TransportRpmsg_Module_to_ti_sdo_ipc_interfaces_IMessageQTransport ti_ipc_transports_TransportRpmsg_Module_upCast

/* Handle_upCast */
static inline ti_sdo_ipc_interfaces_IMessageQTransport_Handle ti_ipc_transports_TransportRpmsg_Handle_upCast(ti_ipc_transports_TransportRpmsg_Handle i);
static inline ti_sdo_ipc_interfaces_IMessageQTransport_Handle ti_ipc_transports_TransportRpmsg_Handle_upCast(ti_ipc_transports_TransportRpmsg_Handle i)
{
    return (ti_sdo_ipc_interfaces_IMessageQTransport_Handle)i;
}

/* Handle_to_ti_sdo_ipc_interfaces_IMessageQTransport */
#define ti_ipc_transports_TransportRpmsg_Handle_to_ti_sdo_ipc_interfaces_IMessageQTransport ti_ipc_transports_TransportRpmsg_Handle_upCast

/* Handle_downCast */
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Handle_downCast(ti_sdo_ipc_interfaces_IMessageQTransport_Handle i);
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Handle_downCast(ti_sdo_ipc_interfaces_IMessageQTransport_Handle i)
{
    ti_sdo_ipc_interfaces_IMessageQTransport_Handle i2 = (ti_sdo_ipc_interfaces_IMessageQTransport_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_ipc_transports_TransportRpmsg_Module__FXNS__C ? (ti_ipc_transports_TransportRpmsg_Handle)i : (ti_ipc_transports_TransportRpmsg_Handle)0;
}

/* Handle_from_ti_sdo_ipc_interfaces_IMessageQTransport */
#define ti_ipc_transports_TransportRpmsg_Handle_from_ti_sdo_ipc_interfaces_IMessageQTransport ti_ipc_transports_TransportRpmsg_Handle_downCast

/* Module_upCast2 */
static inline ti_sdo_ipc_interfaces_ITransport_Module ti_ipc_transports_TransportRpmsg_Module_upCast2(void);
static inline ti_sdo_ipc_interfaces_ITransport_Module ti_ipc_transports_TransportRpmsg_Module_upCast2(void)
{
    return (ti_sdo_ipc_interfaces_ITransport_Module)&ti_ipc_transports_TransportRpmsg_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_interfaces_ITransport */
#define ti_ipc_transports_TransportRpmsg_Module_to_ti_sdo_ipc_interfaces_ITransport ti_ipc_transports_TransportRpmsg_Module_upCast2

/* Handle_upCast2 */
static inline ti_sdo_ipc_interfaces_ITransport_Handle ti_ipc_transports_TransportRpmsg_Handle_upCast2(ti_ipc_transports_TransportRpmsg_Handle i);
static inline ti_sdo_ipc_interfaces_ITransport_Handle ti_ipc_transports_TransportRpmsg_Handle_upCast2(ti_ipc_transports_TransportRpmsg_Handle i)
{
    return (ti_sdo_ipc_interfaces_ITransport_Handle)i;
}

/* Handle_to_ti_sdo_ipc_interfaces_ITransport */
#define ti_ipc_transports_TransportRpmsg_Handle_to_ti_sdo_ipc_interfaces_ITransport ti_ipc_transports_TransportRpmsg_Handle_upCast2

/* Handle_downCast2 */
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Handle_downCast2(ti_sdo_ipc_interfaces_ITransport_Handle i);
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Handle_downCast2(ti_sdo_ipc_interfaces_ITransport_Handle i)
{
    ti_sdo_ipc_interfaces_ITransport_Handle i2 = (ti_sdo_ipc_interfaces_ITransport_Handle)i;
    return (const void*)i2->__fxns == (const void*)&ti_ipc_transports_TransportRpmsg_Module__FXNS__C ? (ti_ipc_transports_TransportRpmsg_Handle)i : (ti_ipc_transports_TransportRpmsg_Handle)0;
}

/* Handle_from_ti_sdo_ipc_interfaces_ITransport */
#define ti_ipc_transports_TransportRpmsg_Handle_from_ti_sdo_ipc_interfaces_ITransport ti_ipc_transports_TransportRpmsg_Handle_downCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_ipc_transports_TransportRpmsg_Module_startupDone() ti_ipc_transports_TransportRpmsg_Module__startupDone__S()

/* Object_heap */
#define ti_ipc_transports_TransportRpmsg_Object_heap() ti_ipc_transports_TransportRpmsg_Object__heap__C

/* Module_heap */
#define ti_ipc_transports_TransportRpmsg_Module_heap() ti_ipc_transports_TransportRpmsg_Object__heap__C

/* Module_id */
static inline CT__ti_ipc_transports_TransportRpmsg_Module__id ti_ipc_transports_TransportRpmsg_Module_id(void);
static inline CT__ti_ipc_transports_TransportRpmsg_Module__id ti_ipc_transports_TransportRpmsg_Module_id( void ) 
{
    return ti_ipc_transports_TransportRpmsg_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_ipc_transports_TransportRpmsg_Module_hasMask(void);
static inline xdc_Bool ti_ipc_transports_TransportRpmsg_Module_hasMask(void) 
{
    return (xdc_Bool)(ti_ipc_transports_TransportRpmsg_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_ipc_transports_TransportRpmsg_Module_getMask(void);
static inline xdc_Bits16 ti_ipc_transports_TransportRpmsg_Module_getMask( void ) 
{
    return ti_ipc_transports_TransportRpmsg_Module__diagsMask__C != NULL ? *ti_ipc_transports_TransportRpmsg_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_ipc_transports_TransportRpmsg_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_ipc_transports_TransportRpmsg_Module_setMask(xdc_Bits16 mask)
{
    if (ti_ipc_transports_TransportRpmsg_Module__diagsMask__C != NULL) {
        *ti_ipc_transports_TransportRpmsg_Module__diagsMask__C = mask;
    }
}

/* Params_init */
static inline void ti_ipc_transports_TransportRpmsg_Params_init(ti_ipc_transports_TransportRpmsg_Params *prms);
static inline void ti_ipc_transports_TransportRpmsg_Params_init( ti_ipc_transports_TransportRpmsg_Params *prms ) 
{
    if (prms) {
        ti_ipc_transports_TransportRpmsg_Params__init__S(prms, 0, sizeof(ti_ipc_transports_TransportRpmsg_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_ipc_transports_TransportRpmsg_Params_copy(ti_ipc_transports_TransportRpmsg_Params *dst, const ti_ipc_transports_TransportRpmsg_Params *src);
static inline void ti_ipc_transports_TransportRpmsg_Params_copy(ti_ipc_transports_TransportRpmsg_Params *dst, const ti_ipc_transports_TransportRpmsg_Params *src) 
{
    if (dst) {
        ti_ipc_transports_TransportRpmsg_Params__init__S(dst, (const void *)src, sizeof(ti_ipc_transports_TransportRpmsg_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_ipc_transports_TransportRpmsg_Object_count() ti_ipc_transports_TransportRpmsg_Object__count__C

/* Object_sizeof */
#define ti_ipc_transports_TransportRpmsg_Object_sizeof() ti_ipc_transports_TransportRpmsg_Object__sizeof__C

/* Object_get */
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Object_get(ti_ipc_transports_TransportRpmsg_Instance_State *oarr, int i);
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Object_get(ti_ipc_transports_TransportRpmsg_Instance_State *oarr, int i) 
{
    return (ti_ipc_transports_TransportRpmsg_Handle)ti_ipc_transports_TransportRpmsg_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Object_first(void);
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Object_first(void)
{
    return (ti_ipc_transports_TransportRpmsg_Handle)ti_ipc_transports_TransportRpmsg_Object__first__S();
}

/* Object_next */
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Object_next(ti_ipc_transports_TransportRpmsg_Object *obj);
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Object_next(ti_ipc_transports_TransportRpmsg_Object *obj)
{
    return (ti_ipc_transports_TransportRpmsg_Handle)ti_ipc_transports_TransportRpmsg_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_ipc_transports_TransportRpmsg_Handle_label(ti_ipc_transports_TransportRpmsg_Handle inst, xdc_runtime_Types_Label *lab);
static inline xdc_runtime_Types_Label *ti_ipc_transports_TransportRpmsg_Handle_label(ti_ipc_transports_TransportRpmsg_Handle inst, xdc_runtime_Types_Label *lab)
{
    return ti_ipc_transports_TransportRpmsg_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_ipc_transports_TransportRpmsg_Handle_name(ti_ipc_transports_TransportRpmsg_Handle inst);
static inline xdc_String ti_ipc_transports_TransportRpmsg_Handle_name(ti_ipc_transports_TransportRpmsg_Handle inst)
{
    xdc_runtime_Types_Label lab;
    return ti_ipc_transports_TransportRpmsg_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_handle(ti_ipc_transports_TransportRpmsg_Struct *str);
static inline ti_ipc_transports_TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_handle(ti_ipc_transports_TransportRpmsg_Struct *str)
{
    return (ti_ipc_transports_TransportRpmsg_Handle)str;
}

/* struct */
static inline ti_ipc_transports_TransportRpmsg_Struct *ti_ipc_transports_TransportRpmsg_struct(ti_ipc_transports_TransportRpmsg_Handle inst);
static inline ti_ipc_transports_TransportRpmsg_Struct *ti_ipc_transports_TransportRpmsg_struct(ti_ipc_transports_TransportRpmsg_Handle inst)
{
    return (ti_ipc_transports_TransportRpmsg_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_ipc_transports_TransportRpmsg__top__
#undef __nested__
#endif

#endif /* ti_ipc_transports_TransportRpmsg__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_ipc_transports_TransportRpmsg__internalaccess))

#ifndef ti_ipc_transports_TransportRpmsg__include_state
#define ti_ipc_transports_TransportRpmsg__include_state

/* Object */
struct ti_ipc_transports_TransportRpmsg_Object {
    const ti_ipc_transports_TransportRpmsg_Fxns__ *__fxns;
    xdc_UInt16 priority;
    xdc_UInt16 remoteProcId;
    xdc_Ptr msgqHandle;
};

#endif /* ti_ipc_transports_TransportRpmsg__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_ipc_transports_TransportRpmsg__nolocalnames)

#ifndef ti_ipc_transports_TransportRpmsg__localnames__done
#define ti_ipc_transports_TransportRpmsg__localnames__done

/* module prefix */
#define TransportRpmsg_Instance ti_ipc_transports_TransportRpmsg_Instance
#define TransportRpmsg_Handle ti_ipc_transports_TransportRpmsg_Handle
#define TransportRpmsg_Module ti_ipc_transports_TransportRpmsg_Module
#define TransportRpmsg_Object ti_ipc_transports_TransportRpmsg_Object
#define TransportRpmsg_Struct ti_ipc_transports_TransportRpmsg_Struct
#define TransportRpmsg_Status ti_ipc_transports_TransportRpmsg_Status
#define TransportRpmsg_Reason ti_ipc_transports_TransportRpmsg_Reason
#define TransportRpmsg_ErrFxn ti_ipc_transports_TransportRpmsg_ErrFxn
#define TransportRpmsg_Instance_State ti_ipc_transports_TransportRpmsg_Instance_State
#define TransportRpmsg_S_SUCCESS ti_ipc_transports_TransportRpmsg_S_SUCCESS
#define TransportRpmsg_E_FAIL ti_ipc_transports_TransportRpmsg_E_FAIL
#define TransportRpmsg_E_ERROR ti_ipc_transports_TransportRpmsg_E_ERROR
#define TransportRpmsg_Reason_FAILEDPUT ti_ipc_transports_TransportRpmsg_Reason_FAILEDPUT
#define TransportRpmsg_Reason_INTERNALERR ti_ipc_transports_TransportRpmsg_Reason_INTERNALERR
#define TransportRpmsg_Reason_PHYSICALERR ti_ipc_transports_TransportRpmsg_Reason_PHYSICALERR
#define TransportRpmsg_Reason_FAILEDALLOC ti_ipc_transports_TransportRpmsg_Reason_FAILEDALLOC
#define TransportRpmsg_errFxn ti_ipc_transports_TransportRpmsg_errFxn
#define TransportRpmsg_Params ti_ipc_transports_TransportRpmsg_Params
#define TransportRpmsg_setErrFxn ti_ipc_transports_TransportRpmsg_setErrFxn
#define TransportRpmsg_getStatus ti_ipc_transports_TransportRpmsg_getStatus
#define TransportRpmsg_put ti_ipc_transports_TransportRpmsg_put
#define TransportRpmsg_control ti_ipc_transports_TransportRpmsg_control
#define TransportRpmsg_Module_name ti_ipc_transports_TransportRpmsg_Module_name
#define TransportRpmsg_Module_id ti_ipc_transports_TransportRpmsg_Module_id
#define TransportRpmsg_Module_startup ti_ipc_transports_TransportRpmsg_Module_startup
#define TransportRpmsg_Module_startupDone ti_ipc_transports_TransportRpmsg_Module_startupDone
#define TransportRpmsg_Module_hasMask ti_ipc_transports_TransportRpmsg_Module_hasMask
#define TransportRpmsg_Module_getMask ti_ipc_transports_TransportRpmsg_Module_getMask
#define TransportRpmsg_Module_setMask ti_ipc_transports_TransportRpmsg_Module_setMask
#define TransportRpmsg_Object_heap ti_ipc_transports_TransportRpmsg_Object_heap
#define TransportRpmsg_Module_heap ti_ipc_transports_TransportRpmsg_Module_heap
#define TransportRpmsg_construct ti_ipc_transports_TransportRpmsg_construct
#define TransportRpmsg_create ti_ipc_transports_TransportRpmsg_create
#define TransportRpmsg_handle ti_ipc_transports_TransportRpmsg_handle
#define TransportRpmsg_struct ti_ipc_transports_TransportRpmsg_struct
#define TransportRpmsg_Handle_label ti_ipc_transports_TransportRpmsg_Handle_label
#define TransportRpmsg_Handle_name ti_ipc_transports_TransportRpmsg_Handle_name
#define TransportRpmsg_Instance_init ti_ipc_transports_TransportRpmsg_Instance_init
#define TransportRpmsg_Object_count ti_ipc_transports_TransportRpmsg_Object_count
#define TransportRpmsg_Object_get ti_ipc_transports_TransportRpmsg_Object_get
#define TransportRpmsg_Object_first ti_ipc_transports_TransportRpmsg_Object_first
#define TransportRpmsg_Object_next ti_ipc_transports_TransportRpmsg_Object_next
#define TransportRpmsg_Object_sizeof ti_ipc_transports_TransportRpmsg_Object_sizeof
#define TransportRpmsg_Params_copy ti_ipc_transports_TransportRpmsg_Params_copy
#define TransportRpmsg_Params_init ti_ipc_transports_TransportRpmsg_Params_init
#define TransportRpmsg_Instance_finalize ti_ipc_transports_TransportRpmsg_Instance_finalize
#define TransportRpmsg_delete ti_ipc_transports_TransportRpmsg_delete
#define TransportRpmsg_destruct ti_ipc_transports_TransportRpmsg_destruct
#define TransportRpmsg_Module_upCast ti_ipc_transports_TransportRpmsg_Module_upCast
#define TransportRpmsg_Module_to_ti_sdo_ipc_interfaces_IMessageQTransport ti_ipc_transports_TransportRpmsg_Module_to_ti_sdo_ipc_interfaces_IMessageQTransport
#define TransportRpmsg_Handle_upCast ti_ipc_transports_TransportRpmsg_Handle_upCast
#define TransportRpmsg_Handle_to_ti_sdo_ipc_interfaces_IMessageQTransport ti_ipc_transports_TransportRpmsg_Handle_to_ti_sdo_ipc_interfaces_IMessageQTransport
#define TransportRpmsg_Handle_downCast ti_ipc_transports_TransportRpmsg_Handle_downCast
#define TransportRpmsg_Handle_from_ti_sdo_ipc_interfaces_IMessageQTransport ti_ipc_transports_TransportRpmsg_Handle_from_ti_sdo_ipc_interfaces_IMessageQTransport
#define TransportRpmsg_Module_upCast2 ti_ipc_transports_TransportRpmsg_Module_upCast2
#define TransportRpmsg_Module_to_ti_sdo_ipc_interfaces_ITransport ti_ipc_transports_TransportRpmsg_Module_to_ti_sdo_ipc_interfaces_ITransport
#define TransportRpmsg_Handle_upCast2 ti_ipc_transports_TransportRpmsg_Handle_upCast2
#define TransportRpmsg_Handle_to_ti_sdo_ipc_interfaces_ITransport ti_ipc_transports_TransportRpmsg_Handle_to_ti_sdo_ipc_interfaces_ITransport
#define TransportRpmsg_Handle_downCast2 ti_ipc_transports_TransportRpmsg_Handle_downCast2
#define TransportRpmsg_Handle_from_ti_sdo_ipc_interfaces_ITransport ti_ipc_transports_TransportRpmsg_Handle_from_ti_sdo_ipc_interfaces_ITransport

#endif /* ti_ipc_transports_TransportRpmsg__localnames__done */
#endif
