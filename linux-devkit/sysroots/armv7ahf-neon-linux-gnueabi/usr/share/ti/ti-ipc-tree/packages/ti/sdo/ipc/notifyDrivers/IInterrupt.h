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
 *     VIRTUAL FUNCTIONS
 *     FUNCTION STUBS
 *     FUNCTION SELECTORS
 *
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sdo_ipc_notifyDrivers_IInterrupt__include
#define ti_sdo_ipc_notifyDrivers_IInterrupt__include

#ifndef __nested__
#define __nested__
#define ti_sdo_ipc_notifyDrivers_IInterrupt__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_ipc_notifyDrivers_IInterrupt___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sdo/ipc/notifyDrivers/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* IntInfo */
struct ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo {
    xdc_UInt localIntId;
    xdc_UInt remoteIntId;
    xdc_UInt intVectorId;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_ipc_notifyDrivers_IInterrupt_Fxns__ {
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
#ifndef ti_sdo_ipc_notifyDrivers_IInterrupt_Module__BASE__CR

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sdo_ipc_notifyDrivers_IInterrupt_Interface__BASE__C;
#else
#define ti_sdo_ipc_notifyDrivers_IInterrupt_Interface__BASE__C (*((xdc_runtime_Types_Base *)(xdcRomConstPtr + ti_sdo_ipc_notifyDrivers_IInterrupt_Interface__BASE__C_offset)))
#endif


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sdo_ipc_notifyDrivers_IInterrupt_Module_id(ti_sdo_ipc_notifyDrivers_IInterrupt_Module mod);
static inline xdc_runtime_Types_ModuleId ti_sdo_ipc_notifyDrivers_IInterrupt_Module_id(ti_sdo_ipc_notifyDrivers_IInterrupt_Module mod)
{
    return mod->__sysp->__mid;
}

/* intEnable */
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo);
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo )
{
    __mod->intEnable(remoteProcId, intInfo);
}

/* intDisable */
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo);
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo )
{
    __mod->intDisable(remoteProcId, intInfo);
}

/* intRegister */
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_Fxn func, xdc_UArg arg);
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_Fxn func, xdc_UArg arg )
{
    __mod->intRegister(remoteProcId, intInfo, func, arg);
}

/* intUnregister */
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo);
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo )
{
    __mod->intUnregister(remoteProcId, intInfo);
}

/* intSend */
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intSend(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg);
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intSend( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg )
{
    __mod->intSend(remoteProcId, intInfo, arg);
}

/* intPost */
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intPost(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 srcProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg);
static inline xdc_Void ti_sdo_ipc_notifyDrivers_IInterrupt_intPost( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 srcProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg )
{
    __mod->intPost(srcProcId, intInfo, arg);
}

/* intClear */
static inline xdc_UInt ti_sdo_ipc_notifyDrivers_IInterrupt_intClear(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo);
static inline xdc_UInt ti_sdo_ipc_notifyDrivers_IInterrupt_intClear( ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod, xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo )
{
    return __mod->intClear(remoteProcId, intInfo);
}


/*
 * ======== FUNCTION SELECTORS ========
 */

/* These functions return function pointers for module and instance functions.
 * The functions accept modules and instances declared as types defined in this
 * interface, but they return functions defined for the actual objects passed
 * as parameters. These functions are not invoked by any generated code or
 * XDCtools internal code.
 */

/* intEnable_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_FxnT)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_FxnT)__mod->intEnable;
}

/* intDisable_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_FxnT)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_FxnT)__mod->intDisable;
}

/* intRegister_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_FxnT)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo, xdc_Fxn func, xdc_UArg arg);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_FxnT)__mod->intRegister;
}

/* intUnregister_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_FxnT)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_FxnT)__mod->intUnregister;
}

/* intSend_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_FxnT)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo, xdc_UArg arg);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_FxnT)__mod->intSend;
}

/* intPost_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_FxnT)(xdc_UInt16 srcProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo, xdc_UArg arg);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_FxnT)__mod->intPost;
}

/* intClear_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_FxnT)(xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo* intInfo);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_fxnP(ti_sdo_ipc_notifyDrivers_IInterrupt_Module __mod)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_FxnT)__mod->intClear;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_ipc_notifyDrivers_IInterrupt__top__
#undef __nested__
#endif

#endif /* ti_sdo_ipc_notifyDrivers_IInterrupt__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_ipc_notifyDrivers_IInterrupt__nolocalnames)

#ifndef ti_sdo_ipc_notifyDrivers_IInterrupt__localnames__done
#define ti_sdo_ipc_notifyDrivers_IInterrupt__localnames__done

/* module prefix */
#define IInterrupt_Module ti_sdo_ipc_notifyDrivers_IInterrupt_Module
#define IInterrupt_IntInfo ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo
#define IInterrupt_intEnable ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable
#define IInterrupt_intEnable_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_fxnP
#define IInterrupt_intEnable_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intEnable_FxnT
#define IInterrupt_intDisable ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable
#define IInterrupt_intDisable_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_fxnP
#define IInterrupt_intDisable_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intDisable_FxnT
#define IInterrupt_intRegister ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister
#define IInterrupt_intRegister_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_fxnP
#define IInterrupt_intRegister_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intRegister_FxnT
#define IInterrupt_intUnregister ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister
#define IInterrupt_intUnregister_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_fxnP
#define IInterrupt_intUnregister_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intUnregister_FxnT
#define IInterrupt_intSend ti_sdo_ipc_notifyDrivers_IInterrupt_intSend
#define IInterrupt_intSend_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_fxnP
#define IInterrupt_intSend_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intSend_FxnT
#define IInterrupt_intPost ti_sdo_ipc_notifyDrivers_IInterrupt_intPost
#define IInterrupt_intPost_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_fxnP
#define IInterrupt_intPost_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intPost_FxnT
#define IInterrupt_intClear ti_sdo_ipc_notifyDrivers_IInterrupt_intClear
#define IInterrupt_intClear_fxnP ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_fxnP
#define IInterrupt_intClear_FxnT ti_sdo_ipc_notifyDrivers_IInterrupt_intClear_FxnT
#define IInterrupt_Module_name ti_sdo_ipc_notifyDrivers_IInterrupt_Module_name

#endif /* ti_sdo_ipc_notifyDrivers_IInterrupt__localnames__done */
#endif
