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

#ifndef ti_ipc_family_tci6638_Interrupt__include
#define ti_ipc_family_tci6638_Interrupt__include

#ifndef __nested__
#define __nested__
#define ti_ipc_family_tci6638_Interrupt__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_ipc_family_tci6638_Interrupt___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/ipc/family/tci6638/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <ti/sdo/ipc/notifyDrivers/IInterrupt.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* IntInfo */
typedef ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo ti_ipc_family_tci6638_Interrupt_IntInfo;

/* INVALIDPAYLOAD */
#define ti_ipc_family_tci6638_Interrupt_INVALIDPAYLOAD (0xFFFFFFFF)


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* SRCS_BITPOS_CORE0 */
#define ti_ipc_family_tci6638_Interrupt_SRCS_BITPOS_CORE0 (4)

/* SRCS_BITPOS_HOST */
#define ti_ipc_family_tci6638_Interrupt_SRCS_BITPOS_HOST (31)


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled__CR
#define ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled (ti_ipc_family_tci6638_Interrupt_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded__CR
#define ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded (ti_ipc_family_tci6638_Interrupt_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_ipc_family_tci6638_Interrupt_Module__diagsMask;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__diagsMask ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__diagsMask__CR
#define ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__diagsMask*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__diagsMask (ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_Module__gateObj;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__gateObj ti_ipc_family_tci6638_Interrupt_Module__gateObj__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__gateObj__CR
#define ti_ipc_family_tci6638_Interrupt_Module__gateObj__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__gateObj*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__gateObj__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__gateObj (ti_ipc_family_tci6638_Interrupt_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_Module__gatePrms;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__gatePrms ti_ipc_family_tci6638_Interrupt_Module__gatePrms__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__gatePrms__CR
#define ti_ipc_family_tci6638_Interrupt_Module__gatePrms__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__gatePrms*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__gatePrms__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__gatePrms (ti_ipc_family_tci6638_Interrupt_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_ipc_family_tci6638_Interrupt_Module__id;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__id ti_ipc_family_tci6638_Interrupt_Module__id__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__id__CR
#define ti_ipc_family_tci6638_Interrupt_Module__id__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__id*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__id__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__id (ti_ipc_family_tci6638_Interrupt_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_ipc_family_tci6638_Interrupt_Module__loggerDefined;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerDefined ti_ipc_family_tci6638_Interrupt_Module__loggerDefined__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerDefined__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerDefined__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerDefined*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerDefined__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerDefined (ti_ipc_family_tci6638_Interrupt_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_Module__loggerObj;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerObj ti_ipc_family_tci6638_Interrupt_Module__loggerObj__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerObj__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerObj__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerObj*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerObj__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerObj (ti_ipc_family_tci6638_Interrupt_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0 ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0 (ti_ipc_family_tci6638_Interrupt_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1 ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1 (ti_ipc_family_tci6638_Interrupt_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2 ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2 (ti_ipc_family_tci6638_Interrupt_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4 ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4 (ti_ipc_family_tci6638_Interrupt_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8 ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8__CR
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8__C (*((CT__ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8 (ti_ipc_family_tci6638_Interrupt_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_ipc_family_tci6638_Interrupt_Object__count;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Object__count ti_ipc_family_tci6638_Interrupt_Object__count__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Object__count__CR
#define ti_ipc_family_tci6638_Interrupt_Object__count__C (*((CT__ti_ipc_family_tci6638_Interrupt_Object__count*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Object__count__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Object__count (ti_ipc_family_tci6638_Interrupt_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_ipc_family_tci6638_Interrupt_Object__heap;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Object__heap ti_ipc_family_tci6638_Interrupt_Object__heap__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Object__heap__CR
#define ti_ipc_family_tci6638_Interrupt_Object__heap__C (*((CT__ti_ipc_family_tci6638_Interrupt_Object__heap*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Object__heap__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Object__heap (ti_ipc_family_tci6638_Interrupt_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_ipc_family_tci6638_Interrupt_Object__sizeof;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Object__sizeof ti_ipc_family_tci6638_Interrupt_Object__sizeof__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Object__sizeof__CR
#define ti_ipc_family_tci6638_Interrupt_Object__sizeof__C (*((CT__ti_ipc_family_tci6638_Interrupt_Object__sizeof*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Object__sizeof__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Object__sizeof (ti_ipc_family_tci6638_Interrupt_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_Object__table;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_Object__table ti_ipc_family_tci6638_Interrupt_Object__table__C;
#ifdef ti_ipc_family_tci6638_Interrupt_Object__table__CR
#define ti_ipc_family_tci6638_Interrupt_Object__table__C (*((CT__ti_ipc_family_tci6638_Interrupt_Object__table*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Object__table__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_Object__table (ti_ipc_family_tci6638_Interrupt_Object__table__C)
#endif

/* enableKick */
typedef xdc_Bool CT__ti_ipc_family_tci6638_Interrupt_enableKick;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_enableKick ti_ipc_family_tci6638_Interrupt_enableKick__C;
#ifdef ti_ipc_family_tci6638_Interrupt_enableKick__CR
#define ti_ipc_family_tci6638_Interrupt_enableKick (*((CT__ti_ipc_family_tci6638_Interrupt_enableKick*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_enableKick__C_offset)))
#else
#ifdef ti_ipc_family_tci6638_Interrupt_enableKick__D
#define ti_ipc_family_tci6638_Interrupt_enableKick (ti_ipc_family_tci6638_Interrupt_enableKick__D)
#else
#define ti_ipc_family_tci6638_Interrupt_enableKick (ti_ipc_family_tci6638_Interrupt_enableKick__C)
#endif
#endif

/* A_notImplemented */
typedef xdc_runtime_Assert_Id CT__ti_ipc_family_tci6638_Interrupt_A_notImplemented;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_A_notImplemented ti_ipc_family_tci6638_Interrupt_A_notImplemented__C;
#ifdef ti_ipc_family_tci6638_Interrupt_A_notImplemented__CR
#define ti_ipc_family_tci6638_Interrupt_A_notImplemented (*((CT__ti_ipc_family_tci6638_Interrupt_A_notImplemented*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_A_notImplemented__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_A_notImplemented (ti_ipc_family_tci6638_Interrupt_A_notImplemented__C)
#endif

/* IPCGR0 */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_IPCGR0;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_IPCGR0 ti_ipc_family_tci6638_Interrupt_IPCGR0__C;
#ifdef ti_ipc_family_tci6638_Interrupt_IPCGR0__CR
#define ti_ipc_family_tci6638_Interrupt_IPCGR0 (*((CT__ti_ipc_family_tci6638_Interrupt_IPCGR0*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_IPCGR0__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_IPCGR0 (ti_ipc_family_tci6638_Interrupt_IPCGR0__C)
#endif

/* IPCAR0 */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_IPCAR0;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_IPCAR0 ti_ipc_family_tci6638_Interrupt_IPCAR0__C;
#ifdef ti_ipc_family_tci6638_Interrupt_IPCAR0__CR
#define ti_ipc_family_tci6638_Interrupt_IPCAR0 (*((CT__ti_ipc_family_tci6638_Interrupt_IPCAR0*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_IPCAR0__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_IPCAR0 (ti_ipc_family_tci6638_Interrupt_IPCAR0__C)
#endif

/* IPCGRH */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_IPCGRH;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_IPCGRH ti_ipc_family_tci6638_Interrupt_IPCGRH__C;
#ifdef ti_ipc_family_tci6638_Interrupt_IPCGRH__CR
#define ti_ipc_family_tci6638_Interrupt_IPCGRH (*((CT__ti_ipc_family_tci6638_Interrupt_IPCGRH*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_IPCGRH__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_IPCGRH (ti_ipc_family_tci6638_Interrupt_IPCGRH__C)
#endif

/* IPCARH */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_IPCARH;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_IPCARH ti_ipc_family_tci6638_Interrupt_IPCARH__C;
#ifdef ti_ipc_family_tci6638_Interrupt_IPCARH__CR
#define ti_ipc_family_tci6638_Interrupt_IPCARH (*((CT__ti_ipc_family_tci6638_Interrupt_IPCARH*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_IPCARH__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_IPCARH (ti_ipc_family_tci6638_Interrupt_IPCARH__C)
#endif

/* KICK0 */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_KICK0;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_KICK0 ti_ipc_family_tci6638_Interrupt_KICK0__C;
#ifdef ti_ipc_family_tci6638_Interrupt_KICK0__CR
#define ti_ipc_family_tci6638_Interrupt_KICK0 (*((CT__ti_ipc_family_tci6638_Interrupt_KICK0*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_KICK0__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_KICK0 (ti_ipc_family_tci6638_Interrupt_KICK0__C)
#endif

/* KICK1 */
typedef xdc_Ptr CT__ti_ipc_family_tci6638_Interrupt_KICK1;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_KICK1 ti_ipc_family_tci6638_Interrupt_KICK1__C;
#ifdef ti_ipc_family_tci6638_Interrupt_KICK1__CR
#define ti_ipc_family_tci6638_Interrupt_KICK1 (*((CT__ti_ipc_family_tci6638_Interrupt_KICK1*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_KICK1__C_offset)))
#else
#define ti_ipc_family_tci6638_Interrupt_KICK1 (ti_ipc_family_tci6638_Interrupt_KICK1__C)
#endif

/* INTERDSPINT */
typedef xdc_UInt CT__ti_ipc_family_tci6638_Interrupt_INTERDSPINT;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_INTERDSPINT ti_ipc_family_tci6638_Interrupt_INTERDSPINT__C;
#ifdef ti_ipc_family_tci6638_Interrupt_INTERDSPINT__CR
#define ti_ipc_family_tci6638_Interrupt_INTERDSPINT (*((CT__ti_ipc_family_tci6638_Interrupt_INTERDSPINT*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_INTERDSPINT__C_offset)))
#else
#ifdef ti_ipc_family_tci6638_Interrupt_INTERDSPINT__D
#define ti_ipc_family_tci6638_Interrupt_INTERDSPINT (ti_ipc_family_tci6638_Interrupt_INTERDSPINT__D)
#else
#define ti_ipc_family_tci6638_Interrupt_INTERDSPINT (ti_ipc_family_tci6638_Interrupt_INTERDSPINT__C)
#endif
#endif

/* DSPINT */
typedef xdc_UInt CT__ti_ipc_family_tci6638_Interrupt_DSPINT;
__extern __FAR__ const CT__ti_ipc_family_tci6638_Interrupt_DSPINT ti_ipc_family_tci6638_Interrupt_DSPINT__C;
#ifdef ti_ipc_family_tci6638_Interrupt_DSPINT__CR
#define ti_ipc_family_tci6638_Interrupt_DSPINT (*((CT__ti_ipc_family_tci6638_Interrupt_DSPINT*)(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_DSPINT__C_offset)))
#else
#ifdef ti_ipc_family_tci6638_Interrupt_DSPINT__D
#define ti_ipc_family_tci6638_Interrupt_DSPINT (ti_ipc_family_tci6638_Interrupt_DSPINT__D)
#else
#define ti_ipc_family_tci6638_Interrupt_DSPINT (ti_ipc_family_tci6638_Interrupt_DSPINT__C)
#endif
#endif


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_ipc_family_tci6638_Interrupt_Fxns__ {
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
#ifndef ti_ipc_family_tci6638_Interrupt_Module__FXNS__CR

/* Module__FXNS__C */
__extern const ti_ipc_family_tci6638_Interrupt_Fxns__ ti_ipc_family_tci6638_Interrupt_Module__FXNS__C;
#else
#define ti_ipc_family_tci6638_Interrupt_Module__FXNS__C (*(xdcRomConstPtr + ti_ipc_family_tci6638_Interrupt_Module__FXNS__C_offset))
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_ipc_family_tci6638_Interrupt_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_Module__startupDone__S, "ti_ipc_family_tci6638_Interrupt_Module__startupDone__S")
__extern xdc_Bool ti_ipc_family_tci6638_Interrupt_Module__startupDone__S( void );

/* intEnable__E */
#define ti_ipc_family_tci6638_Interrupt_intEnable ti_ipc_family_tci6638_Interrupt_intEnable__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intEnable__E, "ti_ipc_family_tci6638_Interrupt_intEnable")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intEnable__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intDisable__E */
#define ti_ipc_family_tci6638_Interrupt_intDisable ti_ipc_family_tci6638_Interrupt_intDisable__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intDisable__E, "ti_ipc_family_tci6638_Interrupt_intDisable")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intDisable__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intRegister__E */
#define ti_ipc_family_tci6638_Interrupt_intRegister ti_ipc_family_tci6638_Interrupt_intRegister__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intRegister__E, "ti_ipc_family_tci6638_Interrupt_intRegister")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intRegister__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_Fxn func, xdc_UArg arg );

/* intUnregister__E */
#define ti_ipc_family_tci6638_Interrupt_intUnregister ti_ipc_family_tci6638_Interrupt_intUnregister__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intUnregister__E, "ti_ipc_family_tci6638_Interrupt_intUnregister")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intUnregister__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intSend__E */
#define ti_ipc_family_tci6638_Interrupt_intSend ti_ipc_family_tci6638_Interrupt_intSend__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intSend__E, "ti_ipc_family_tci6638_Interrupt_intSend")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intSend__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg );

/* intPost__E */
#define ti_ipc_family_tci6638_Interrupt_intPost ti_ipc_family_tci6638_Interrupt_intPost__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intPost__E, "ti_ipc_family_tci6638_Interrupt_intPost")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intPost__E( xdc_UInt16 srcProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo, xdc_UArg arg );

/* intClear__E */
#define ti_ipc_family_tci6638_Interrupt_intClear ti_ipc_family_tci6638_Interrupt_intClear__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intClear__E, "ti_ipc_family_tci6638_Interrupt_intClear")
__extern xdc_UInt ti_ipc_family_tci6638_Interrupt_intClear__E( xdc_UInt16 remoteProcId, ti_sdo_ipc_notifyDrivers_IInterrupt_IntInfo *intInfo );

/* intClearAll__E */
#define ti_ipc_family_tci6638_Interrupt_intClearAll ti_ipc_family_tci6638_Interrupt_intClearAll__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intClearAll__E, "ti_ipc_family_tci6638_Interrupt_intClearAll")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intClearAll__E( void );
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_intClearAll__F, "ti_ipc_family_tci6638_Interrupt_intClearAll")
__extern xdc_Void ti_ipc_family_tci6638_Interrupt_intClearAll__F( void );

/* checkAndClear__E */
#define ti_ipc_family_tci6638_Interrupt_checkAndClear ti_ipc_family_tci6638_Interrupt_checkAndClear__E
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_checkAndClear__E, "ti_ipc_family_tci6638_Interrupt_checkAndClear")
__extern xdc_UInt ti_ipc_family_tci6638_Interrupt_checkAndClear__E( xdc_UInt16 remoteProcId, ti_ipc_family_tci6638_Interrupt_IntInfo *intInfo );
xdc__CODESECT(ti_ipc_family_tci6638_Interrupt_checkAndClear__F, "ti_ipc_family_tci6638_Interrupt_checkAndClear")
__extern xdc_UInt ti_ipc_family_tci6638_Interrupt_checkAndClear__F( xdc_UInt16 remoteProcId, ti_ipc_family_tci6638_Interrupt_IntInfo *intInfo );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_Module ti_ipc_family_tci6638_Interrupt_Module_upCast(void);
static inline ti_sdo_ipc_notifyDrivers_IInterrupt_Module ti_ipc_family_tci6638_Interrupt_Module_upCast(void)
{
    return (ti_sdo_ipc_notifyDrivers_IInterrupt_Module)&ti_ipc_family_tci6638_Interrupt_Module__FXNS__C;
}

/* Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt */
#define ti_ipc_family_tci6638_Interrupt_Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt ti_ipc_family_tci6638_Interrupt_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_ipc_family_tci6638_Interrupt_Module_startupDone() ti_ipc_family_tci6638_Interrupt_Module__startupDone__S()

/* Object_heap */
#define ti_ipc_family_tci6638_Interrupt_Object_heap() ti_ipc_family_tci6638_Interrupt_Object__heap__C

/* Module_heap */
#define ti_ipc_family_tci6638_Interrupt_Module_heap() ti_ipc_family_tci6638_Interrupt_Object__heap__C

/* Module_id */
static inline CT__ti_ipc_family_tci6638_Interrupt_Module__id ti_ipc_family_tci6638_Interrupt_Module_id(void);
static inline CT__ti_ipc_family_tci6638_Interrupt_Module__id ti_ipc_family_tci6638_Interrupt_Module_id( void ) 
{
    return ti_ipc_family_tci6638_Interrupt_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_ipc_family_tci6638_Interrupt_Module_hasMask(void);
static inline xdc_Bool ti_ipc_family_tci6638_Interrupt_Module_hasMask(void) 
{
    return (xdc_Bool)(ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_ipc_family_tci6638_Interrupt_Module_getMask(void);
static inline xdc_Bits16 ti_ipc_family_tci6638_Interrupt_Module_getMask( void ) 
{
    return ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C != NULL ? *ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_ipc_family_tci6638_Interrupt_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_ipc_family_tci6638_Interrupt_Module_setMask(xdc_Bits16 mask)
{
    if (ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C != NULL) {
        *ti_ipc_family_tci6638_Interrupt_Module__diagsMask__C = mask;
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_ipc_family_tci6638_Interrupt__top__
#undef __nested__
#endif

#endif /* ti_ipc_family_tci6638_Interrupt__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_ipc_family_tci6638_Interrupt__internalaccess))

#ifndef ti_ipc_family_tci6638_Interrupt__include_state
#define ti_ipc_family_tci6638_Interrupt__include_state


#endif /* ti_ipc_family_tci6638_Interrupt__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_ipc_family_tci6638_Interrupt__nolocalnames)

#ifndef ti_ipc_family_tci6638_Interrupt__localnames__done
#define ti_ipc_family_tci6638_Interrupt__localnames__done

/* module prefix */
#define Interrupt_IntInfo ti_ipc_family_tci6638_Interrupt_IntInfo
#define Interrupt_INVALIDPAYLOAD ti_ipc_family_tci6638_Interrupt_INVALIDPAYLOAD
#define Interrupt_SRCS_BITPOS_CORE0 ti_ipc_family_tci6638_Interrupt_SRCS_BITPOS_CORE0
#define Interrupt_SRCS_BITPOS_HOST ti_ipc_family_tci6638_Interrupt_SRCS_BITPOS_HOST
#define Interrupt_enableKick ti_ipc_family_tci6638_Interrupt_enableKick
#define Interrupt_A_notImplemented ti_ipc_family_tci6638_Interrupt_A_notImplemented
#define Interrupt_IPCGR0 ti_ipc_family_tci6638_Interrupt_IPCGR0
#define Interrupt_IPCAR0 ti_ipc_family_tci6638_Interrupt_IPCAR0
#define Interrupt_IPCGRH ti_ipc_family_tci6638_Interrupt_IPCGRH
#define Interrupt_IPCARH ti_ipc_family_tci6638_Interrupt_IPCARH
#define Interrupt_KICK0 ti_ipc_family_tci6638_Interrupt_KICK0
#define Interrupt_KICK1 ti_ipc_family_tci6638_Interrupt_KICK1
#define Interrupt_INTERDSPINT ti_ipc_family_tci6638_Interrupt_INTERDSPINT
#define Interrupt_DSPINT ti_ipc_family_tci6638_Interrupt_DSPINT
#define Interrupt_intEnable ti_ipc_family_tci6638_Interrupt_intEnable
#define Interrupt_intDisable ti_ipc_family_tci6638_Interrupt_intDisable
#define Interrupt_intRegister ti_ipc_family_tci6638_Interrupt_intRegister
#define Interrupt_intUnregister ti_ipc_family_tci6638_Interrupt_intUnregister
#define Interrupt_intSend ti_ipc_family_tci6638_Interrupt_intSend
#define Interrupt_intPost ti_ipc_family_tci6638_Interrupt_intPost
#define Interrupt_intClear ti_ipc_family_tci6638_Interrupt_intClear
#define Interrupt_intClearAll ti_ipc_family_tci6638_Interrupt_intClearAll
#define Interrupt_checkAndClear ti_ipc_family_tci6638_Interrupt_checkAndClear
#define Interrupt_Module_name ti_ipc_family_tci6638_Interrupt_Module_name
#define Interrupt_Module_id ti_ipc_family_tci6638_Interrupt_Module_id
#define Interrupt_Module_startup ti_ipc_family_tci6638_Interrupt_Module_startup
#define Interrupt_Module_startupDone ti_ipc_family_tci6638_Interrupt_Module_startupDone
#define Interrupt_Module_hasMask ti_ipc_family_tci6638_Interrupt_Module_hasMask
#define Interrupt_Module_getMask ti_ipc_family_tci6638_Interrupt_Module_getMask
#define Interrupt_Module_setMask ti_ipc_family_tci6638_Interrupt_Module_setMask
#define Interrupt_Object_heap ti_ipc_family_tci6638_Interrupt_Object_heap
#define Interrupt_Module_heap ti_ipc_family_tci6638_Interrupt_Module_heap
#define Interrupt_Module_upCast ti_ipc_family_tci6638_Interrupt_Module_upCast
#define Interrupt_Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt ti_ipc_family_tci6638_Interrupt_Module_to_ti_sdo_ipc_notifyDrivers_IInterrupt

#endif /* ti_ipc_family_tci6638_Interrupt__localnames__done */
#endif
