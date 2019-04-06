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
 *     FUNCTION DECLARATIONS
 *     SYSTEM FUNCTIONS
 *
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_runtime_ompbios_OpenMP__include
#define ti_runtime_ompbios_OpenMP__include

#ifndef __nested__
#define __nested__
#define ti_runtime_ompbios_OpenMP__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_runtime_ompbios_OpenMP___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/runtime/ompbios/package/package.defs.h>

#include <xdc/runtime/Types.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_runtime_ompbios_OpenMP_Module__diagsEnabled;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__diagsEnabled ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__diagsEnabled__CR
#define ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C (*((CT__ti_runtime_ompbios_OpenMP_Module__diagsEnabled*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__diagsEnabled (ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_runtime_ompbios_OpenMP_Module__diagsIncluded;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__diagsIncluded ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__diagsIncluded__CR
#define ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C (*((CT__ti_runtime_ompbios_OpenMP_Module__diagsIncluded*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__diagsIncluded (ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_runtime_ompbios_OpenMP_Module__diagsMask;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__diagsMask ti_runtime_ompbios_OpenMP_Module__diagsMask__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__diagsMask__CR
#define ti_runtime_ompbios_OpenMP_Module__diagsMask__C (*((CT__ti_runtime_ompbios_OpenMP_Module__diagsMask*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__diagsMask__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__diagsMask (ti_runtime_ompbios_OpenMP_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Module__gateObj;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__gateObj ti_runtime_ompbios_OpenMP_Module__gateObj__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__gateObj__CR
#define ti_runtime_ompbios_OpenMP_Module__gateObj__C (*((CT__ti_runtime_ompbios_OpenMP_Module__gateObj*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__gateObj__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__gateObj (ti_runtime_ompbios_OpenMP_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Module__gatePrms;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__gatePrms ti_runtime_ompbios_OpenMP_Module__gatePrms__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__gatePrms__CR
#define ti_runtime_ompbios_OpenMP_Module__gatePrms__C (*((CT__ti_runtime_ompbios_OpenMP_Module__gatePrms*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__gatePrms__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__gatePrms (ti_runtime_ompbios_OpenMP_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_runtime_ompbios_OpenMP_Module__id;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__id ti_runtime_ompbios_OpenMP_Module__id__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__id__CR
#define ti_runtime_ompbios_OpenMP_Module__id__C (*((CT__ti_runtime_ompbios_OpenMP_Module__id*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__id__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__id (ti_runtime_ompbios_OpenMP_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_Module__loggerDefined;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerDefined ti_runtime_ompbios_OpenMP_Module__loggerDefined__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerDefined__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerDefined__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerDefined*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerDefined__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerDefined (ti_runtime_ompbios_OpenMP_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Module__loggerObj;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerObj ti_runtime_ompbios_OpenMP_Module__loggerObj__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerObj__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerObj__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerObj*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerObj__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerObj (ti_runtime_ompbios_OpenMP_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn0;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn0 ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn0__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn0*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn0 (ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn1;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn1 ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn1__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn1*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn1 (ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn2;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn2 ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn2__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn2*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn2 (ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn4;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn4 ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn4__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn4*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn4 (ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn8;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn8 ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C;
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn8__CR
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn8*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Module__loggerFxn8 (ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_runtime_ompbios_OpenMP_Object__count;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__count ti_runtime_ompbios_OpenMP_Object__count__C;
#ifdef ti_runtime_ompbios_OpenMP_Object__count__CR
#define ti_runtime_ompbios_OpenMP_Object__count__C (*((CT__ti_runtime_ompbios_OpenMP_Object__count*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Object__count__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Object__count (ti_runtime_ompbios_OpenMP_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_runtime_ompbios_OpenMP_Object__heap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__heap ti_runtime_ompbios_OpenMP_Object__heap__C;
#ifdef ti_runtime_ompbios_OpenMP_Object__heap__CR
#define ti_runtime_ompbios_OpenMP_Object__heap__C (*((CT__ti_runtime_ompbios_OpenMP_Object__heap*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Object__heap__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Object__heap (ti_runtime_ompbios_OpenMP_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_runtime_ompbios_OpenMP_Object__sizeof;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__sizeof ti_runtime_ompbios_OpenMP_Object__sizeof__C;
#ifdef ti_runtime_ompbios_OpenMP_Object__sizeof__CR
#define ti_runtime_ompbios_OpenMP_Object__sizeof__C (*((CT__ti_runtime_ompbios_OpenMP_Object__sizeof*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Object__sizeof__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Object__sizeof (ti_runtime_ompbios_OpenMP_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_runtime_ompbios_OpenMP_Object__table;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_Object__table ti_runtime_ompbios_OpenMP_Object__table__C;
#ifdef ti_runtime_ompbios_OpenMP_Object__table__CR
#define ti_runtime_ompbios_OpenMP_Object__table__C (*((CT__ti_runtime_ompbios_OpenMP_Object__table*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Object__table__C_offset)))
#else
#define ti_runtime_ompbios_OpenMP_Object__table (ti_runtime_ompbios_OpenMP_Object__table__C)
#endif

/* numCores */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_numCores;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_numCores ti_runtime_ompbios_OpenMP_numCores__C;
#ifdef ti_runtime_ompbios_OpenMP_numCores__CR
#define ti_runtime_ompbios_OpenMP_numCores (*((CT__ti_runtime_ompbios_OpenMP_numCores*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_numCores__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_numCores__D
#define ti_runtime_ompbios_OpenMP_numCores (ti_runtime_ompbios_OpenMP_numCores__D)
#else
#define ti_runtime_ompbios_OpenMP_numCores (ti_runtime_ompbios_OpenMP_numCores__C)
#endif
#endif

/* masterCoreIdx */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_masterCoreIdx;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_masterCoreIdx ti_runtime_ompbios_OpenMP_masterCoreIdx__C;
#ifdef ti_runtime_ompbios_OpenMP_masterCoreIdx__CR
#define ti_runtime_ompbios_OpenMP_masterCoreIdx (*((CT__ti_runtime_ompbios_OpenMP_masterCoreIdx*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_masterCoreIdx__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_masterCoreIdx__D
#define ti_runtime_ompbios_OpenMP_masterCoreIdx (ti_runtime_ompbios_OpenMP_masterCoreIdx__D)
#else
#define ti_runtime_ompbios_OpenMP_masterCoreIdx (ti_runtime_ompbios_OpenMP_masterCoreIdx__C)
#endif
#endif

/* clockFreq */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_clockFreq;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_clockFreq ti_runtime_ompbios_OpenMP_clockFreq__C;
#ifdef ti_runtime_ompbios_OpenMP_clockFreq__CR
#define ti_runtime_ompbios_OpenMP_clockFreq (*((CT__ti_runtime_ompbios_OpenMP_clockFreq*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_clockFreq__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_clockFreq__D
#define ti_runtime_ompbios_OpenMP_clockFreq (ti_runtime_ompbios_OpenMP_clockFreq__D)
#else
#define ti_runtime_ompbios_OpenMP_clockFreq (ti_runtime_ompbios_OpenMP_clockFreq__C)
#endif
#endif

/* hasMsmc */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_hasMsmc;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_hasMsmc ti_runtime_ompbios_OpenMP_hasMsmc__C;
#ifdef ti_runtime_ompbios_OpenMP_hasMsmc__CR
#define ti_runtime_ompbios_OpenMP_hasMsmc (*((CT__ti_runtime_ompbios_OpenMP_hasMsmc*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_hasMsmc__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_hasMsmc__D
#define ti_runtime_ompbios_OpenMP_hasMsmc (ti_runtime_ompbios_OpenMP_hasMsmc__D)
#else
#define ti_runtime_ompbios_OpenMP_hasMsmc (ti_runtime_ompbios_OpenMP_hasMsmc__C)
#endif
#endif

/* msmcBase */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcBase ti_runtime_ompbios_OpenMP_msmcBase__C;
#ifdef ti_runtime_ompbios_OpenMP_msmcBase__CR
#define ti_runtime_ompbios_OpenMP_msmcBase (*((CT__ti_runtime_ompbios_OpenMP_msmcBase*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_msmcBase__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_msmcBase__D
#define ti_runtime_ompbios_OpenMP_msmcBase (ti_runtime_ompbios_OpenMP_msmcBase__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcBase (ti_runtime_ompbios_OpenMP_msmcBase__C)
#endif
#endif

/* msmcSize */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcSize ti_runtime_ompbios_OpenMP_msmcSize__C;
#ifdef ti_runtime_ompbios_OpenMP_msmcSize__CR
#define ti_runtime_ompbios_OpenMP_msmcSize (*((CT__ti_runtime_ompbios_OpenMP_msmcSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_msmcSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_msmcSize__D
#define ti_runtime_ompbios_OpenMP_msmcSize (ti_runtime_ompbios_OpenMP_msmcSize__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcSize (ti_runtime_ompbios_OpenMP_msmcSize__C)
#endif
#endif

/* msmcNoCacheVirtualBase */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__C;
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__CR
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase (*((CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__D
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase__C)
#endif
#endif

/* msmcNoCacheVirtualSize */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__C;
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__CR
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize (*((CT__ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__D
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize (ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize__C)
#endif
#endif

/* msmcNoCachePhysicalBase */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__C;
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__CR
#define ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase (*((CT__ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__D
#define ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase (ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__D)
#else
#define ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase (ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase__C)
#endif
#endif

/* ddrBase */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrBase ti_runtime_ompbios_OpenMP_ddrBase__C;
#ifdef ti_runtime_ompbios_OpenMP_ddrBase__CR
#define ti_runtime_ompbios_OpenMP_ddrBase (*((CT__ti_runtime_ompbios_OpenMP_ddrBase*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_ddrBase__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_ddrBase__D
#define ti_runtime_ompbios_OpenMP_ddrBase (ti_runtime_ompbios_OpenMP_ddrBase__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrBase (ti_runtime_ompbios_OpenMP_ddrBase__C)
#endif
#endif

/* ddrSize */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrSize ti_runtime_ompbios_OpenMP_ddrSize__C;
#ifdef ti_runtime_ompbios_OpenMP_ddrSize__CR
#define ti_runtime_ompbios_OpenMP_ddrSize (*((CT__ti_runtime_ompbios_OpenMP_ddrSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_ddrSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_ddrSize__D
#define ti_runtime_ompbios_OpenMP_ddrSize (ti_runtime_ompbios_OpenMP_ddrSize__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrSize (ti_runtime_ompbios_OpenMP_ddrSize__C)
#endif
#endif

/* ddrNoCacheBase */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrNoCacheBase;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrNoCacheBase ti_runtime_ompbios_OpenMP_ddrNoCacheBase__C;
#ifdef ti_runtime_ompbios_OpenMP_ddrNoCacheBase__CR
#define ti_runtime_ompbios_OpenMP_ddrNoCacheBase (*((CT__ti_runtime_ompbios_OpenMP_ddrNoCacheBase*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_ddrNoCacheBase__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_ddrNoCacheBase__D
#define ti_runtime_ompbios_OpenMP_ddrNoCacheBase (ti_runtime_ompbios_OpenMP_ddrNoCacheBase__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrNoCacheBase (ti_runtime_ompbios_OpenMP_ddrNoCacheBase__C)
#endif
#endif

/* ddrNoCacheSize */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_ddrNoCacheSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_ddrNoCacheSize ti_runtime_ompbios_OpenMP_ddrNoCacheSize__C;
#ifdef ti_runtime_ompbios_OpenMP_ddrNoCacheSize__CR
#define ti_runtime_ompbios_OpenMP_ddrNoCacheSize (*((CT__ti_runtime_ompbios_OpenMP_ddrNoCacheSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_ddrNoCacheSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_ddrNoCacheSize__D
#define ti_runtime_ompbios_OpenMP_ddrNoCacheSize (ti_runtime_ompbios_OpenMP_ddrNoCacheSize__D)
#else
#define ti_runtime_ompbios_OpenMP_ddrNoCacheSize (ti_runtime_ompbios_OpenMP_ddrNoCacheSize__C)
#endif
#endif

/* mpaxForMsmcMapping */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__C;
#ifdef ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__CR
#define ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping (*((CT__ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__D
#define ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping (ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__D)
#else
#define ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping (ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping__C)
#endif
#endif

/* hwSemBaseIdx */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_hwSemBaseIdx;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_hwSemBaseIdx ti_runtime_ompbios_OpenMP_hwSemBaseIdx__C;
#ifdef ti_runtime_ompbios_OpenMP_hwSemBaseIdx__CR
#define ti_runtime_ompbios_OpenMP_hwSemBaseIdx (*((CT__ti_runtime_ompbios_OpenMP_hwSemBaseIdx*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_hwSemBaseIdx__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_hwSemBaseIdx__D
#define ti_runtime_ompbios_OpenMP_hwSemBaseIdx (ti_runtime_ompbios_OpenMP_hwSemBaseIdx__D)
#else
#define ti_runtime_ompbios_OpenMP_hwSemBaseIdx (ti_runtime_ompbios_OpenMP_hwSemBaseIdx__C)
#endif
#endif

/* hwSemCount */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_hwSemCount;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_hwSemCount ti_runtime_ompbios_OpenMP_hwSemCount__C;
#ifdef ti_runtime_ompbios_OpenMP_hwSemCount__CR
#define ti_runtime_ompbios_OpenMP_hwSemCount (*((CT__ti_runtime_ompbios_OpenMP_hwSemCount*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_hwSemCount__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_hwSemCount__D
#define ti_runtime_ompbios_OpenMP_hwSemCount (ti_runtime_ompbios_OpenMP_hwSemCount__D)
#else
#define ti_runtime_ompbios_OpenMP_hwSemCount (ti_runtime_ompbios_OpenMP_hwSemCount__C)
#endif
#endif

/* qmssInit */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_qmssInit;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssInit ti_runtime_ompbios_OpenMP_qmssInit__C;
#ifdef ti_runtime_ompbios_OpenMP_qmssInit__CR
#define ti_runtime_ompbios_OpenMP_qmssInit (*((CT__ti_runtime_ompbios_OpenMP_qmssInit*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_qmssInit__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_qmssInit__D
#define ti_runtime_ompbios_OpenMP_qmssInit (ti_runtime_ompbios_OpenMP_qmssInit__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssInit (ti_runtime_ompbios_OpenMP_qmssInit__C)
#endif
#endif

/* qmssMemRegionIndex */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_qmssMemRegionIndex;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssMemRegionIndex ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__C;
#ifdef ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__CR
#define ti_runtime_ompbios_OpenMP_qmssMemRegionIndex (*((CT__ti_runtime_ompbios_OpenMP_qmssMemRegionIndex*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__D
#define ti_runtime_ompbios_OpenMP_qmssMemRegionIndex (ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssMemRegionIndex (ti_runtime_ompbios_OpenMP_qmssMemRegionIndex__C)
#endif
#endif

/* qmssFirstDescIdxInLinkingRam */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__C;
#ifdef ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__CR
#define ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam (*((CT__ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__D
#define ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam (ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam (ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam__C)
#endif
#endif

/* qmssHwQueueBaseIdx */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__C;
#ifdef ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__CR
#define ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx (*((CT__ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__D
#define ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx (ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__D)
#else
#define ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx (ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx__C)
#endif
#endif

/* useIpcSharedHeap */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_useIpcSharedHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_useIpcSharedHeap ti_runtime_ompbios_OpenMP_useIpcSharedHeap__C;
#ifdef ti_runtime_ompbios_OpenMP_useIpcSharedHeap__CR
#define ti_runtime_ompbios_OpenMP_useIpcSharedHeap (*((CT__ti_runtime_ompbios_OpenMP_useIpcSharedHeap*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_useIpcSharedHeap__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_useIpcSharedHeap__D
#define ti_runtime_ompbios_OpenMP_useIpcSharedHeap (ti_runtime_ompbios_OpenMP_useIpcSharedHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_useIpcSharedHeap (ti_runtime_ompbios_OpenMP_useIpcSharedHeap__C)
#endif
#endif

/* allocateLocalHeap */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_allocateLocalHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateLocalHeap ti_runtime_ompbios_OpenMP_allocateLocalHeap__C;
#ifdef ti_runtime_ompbios_OpenMP_allocateLocalHeap__CR
#define ti_runtime_ompbios_OpenMP_allocateLocalHeap (*((CT__ti_runtime_ompbios_OpenMP_allocateLocalHeap*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_allocateLocalHeap__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_allocateLocalHeap__D
#define ti_runtime_ompbios_OpenMP_allocateLocalHeap (ti_runtime_ompbios_OpenMP_allocateLocalHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateLocalHeap (ti_runtime_ompbios_OpenMP_allocateLocalHeap__C)
#endif
#endif

/* allocateLocalHeapSize */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_allocateLocalHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateLocalHeapSize ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__C;
#ifdef ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__CR
#define ti_runtime_ompbios_OpenMP_allocateLocalHeapSize (*((CT__ti_runtime_ompbios_OpenMP_allocateLocalHeapSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__D
#define ti_runtime_ompbios_OpenMP_allocateLocalHeapSize (ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateLocalHeapSize (ti_runtime_ompbios_OpenMP_allocateLocalHeapSize__C)
#endif
#endif

/* allocateSharedHeap */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_allocateSharedHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateSharedHeap ti_runtime_ompbios_OpenMP_allocateSharedHeap__C;
#ifdef ti_runtime_ompbios_OpenMP_allocateSharedHeap__CR
#define ti_runtime_ompbios_OpenMP_allocateSharedHeap (*((CT__ti_runtime_ompbios_OpenMP_allocateSharedHeap*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_allocateSharedHeap__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_allocateSharedHeap__D
#define ti_runtime_ompbios_OpenMP_allocateSharedHeap (ti_runtime_ompbios_OpenMP_allocateSharedHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateSharedHeap (ti_runtime_ompbios_OpenMP_allocateSharedHeap__C)
#endif
#endif

/* allocateSharedHeapSize */
typedef xdc_UInt32 CT__ti_runtime_ompbios_OpenMP_allocateSharedHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateSharedHeapSize ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__C;
#ifdef ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__CR
#define ti_runtime_ompbios_OpenMP_allocateSharedHeapSize (*((CT__ti_runtime_ompbios_OpenMP_allocateSharedHeapSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__D
#define ti_runtime_ompbios_OpenMP_allocateSharedHeapSize (ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateSharedHeapSize (ti_runtime_ompbios_OpenMP_allocateSharedHeapSize__C)
#endif
#endif

/* allocateStackFromHeap */
typedef xdc_Bool CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeap;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeap ti_runtime_ompbios_OpenMP_allocateStackFromHeap__C;
#ifdef ti_runtime_ompbios_OpenMP_allocateStackFromHeap__CR
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeap (*((CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeap*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_allocateStackFromHeap__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_allocateStackFromHeap__D
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeap (ti_runtime_ompbios_OpenMP_allocateStackFromHeap__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeap (ti_runtime_ompbios_OpenMP_allocateStackFromHeap__C)
#endif
#endif

/* allocateStackFromHeapSize */
typedef xdc_Int32 CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize;
__extern __FAR__ const CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__C;
#ifdef ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__CR
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize (*((CT__ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize*)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__C_offset)))
#else
#ifdef ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__D
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize (ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__D)
#else
#define ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize (ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize__C)
#endif
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_runtime_ompbios_OpenMP_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_runtime_ompbios_OpenMP_Module__startupDone__S, "ti_runtime_ompbios_OpenMP_Module__startupDone__S")
__extern xdc_Bool ti_runtime_ompbios_OpenMP_Module__startupDone__S( void );

/* useSharedHeap__E */
#define ti_runtime_ompbios_OpenMP_useSharedHeap ti_runtime_ompbios_OpenMP_useSharedHeap__E
xdc__CODESECT(ti_runtime_ompbios_OpenMP_useSharedHeap__E, "ti_runtime_ompbios_OpenMP_useSharedHeap")
__extern xdc_Bool ti_runtime_ompbios_OpenMP_useSharedHeap__E( void );
xdc__CODESECT(ti_runtime_ompbios_OpenMP_useSharedHeap__F, "ti_runtime_ompbios_OpenMP_useSharedHeap")
__extern xdc_Bool ti_runtime_ompbios_OpenMP_useSharedHeap__F( void );

/* setProcId__I */
#define ti_runtime_ompbios_OpenMP_setProcId ti_runtime_ompbios_OpenMP_setProcId__I
xdc__CODESECT(ti_runtime_ompbios_OpenMP_setProcId__I, "ti_runtime_ompbios_OpenMP_setProcId")
__extern xdc_Void ti_runtime_ompbios_OpenMP_setProcId__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_runtime_ompbios_OpenMP_Module_startupDone() ti_runtime_ompbios_OpenMP_Module__startupDone__S()

/* Object_heap */
#define ti_runtime_ompbios_OpenMP_Object_heap() ti_runtime_ompbios_OpenMP_Object__heap__C

/* Module_heap */
#define ti_runtime_ompbios_OpenMP_Module_heap() ti_runtime_ompbios_OpenMP_Object__heap__C

/* Module_id */
static inline CT__ti_runtime_ompbios_OpenMP_Module__id ti_runtime_ompbios_OpenMP_Module_id(void);
static inline CT__ti_runtime_ompbios_OpenMP_Module__id ti_runtime_ompbios_OpenMP_Module_id( void ) 
{
    return ti_runtime_ompbios_OpenMP_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_runtime_ompbios_OpenMP_Module_hasMask(void);
static inline xdc_Bool ti_runtime_ompbios_OpenMP_Module_hasMask(void) 
{
    return (xdc_Bool)(ti_runtime_ompbios_OpenMP_Module__diagsMask__C != NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_runtime_ompbios_OpenMP_Module_getMask(void);
static inline xdc_Bits16 ti_runtime_ompbios_OpenMP_Module_getMask( void ) 
{
    return ti_runtime_ompbios_OpenMP_Module__diagsMask__C != NULL ? *ti_runtime_ompbios_OpenMP_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_runtime_ompbios_OpenMP_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_runtime_ompbios_OpenMP_Module_setMask(xdc_Bits16 mask)
{
    if (ti_runtime_ompbios_OpenMP_Module__diagsMask__C != NULL) {
        *ti_runtime_ompbios_OpenMP_Module__diagsMask__C = mask;
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_runtime_ompbios_OpenMP__top__
#undef __nested__
#endif

#endif /* ti_runtime_ompbios_OpenMP__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_runtime_ompbios_OpenMP__internalaccess))

#ifndef ti_runtime_ompbios_OpenMP__include_state
#define ti_runtime_ompbios_OpenMP__include_state

/* Module_State */
struct ti_runtime_ompbios_OpenMP_Module_State {
    xdc_Bool useSharedHeap;
};

/* Module__state__V */
#ifndef ti_runtime_ompbios_OpenMP_Module__state__VR
extern struct ti_runtime_ompbios_OpenMP_Module_State__ ti_runtime_ompbios_OpenMP_Module__state__V;
#else
#define ti_runtime_ompbios_OpenMP_Module__state__V (*((struct ti_runtime_ompbios_OpenMP_Module_State__*)(xdcRomStatePtr + ti_runtime_ompbios_OpenMP_Module__state__V_offset)))
#endif

#endif /* ti_runtime_ompbios_OpenMP__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_runtime_ompbios_OpenMP__nolocalnames)

#ifndef ti_runtime_ompbios_OpenMP__localnames__done
#define ti_runtime_ompbios_OpenMP__localnames__done

/* module prefix */
#define OpenMP_Module_State ti_runtime_ompbios_OpenMP_Module_State
#define OpenMP_numCores ti_runtime_ompbios_OpenMP_numCores
#define OpenMP_masterCoreIdx ti_runtime_ompbios_OpenMP_masterCoreIdx
#define OpenMP_clockFreq ti_runtime_ompbios_OpenMP_clockFreq
#define OpenMP_hasMsmc ti_runtime_ompbios_OpenMP_hasMsmc
#define OpenMP_msmcBase ti_runtime_ompbios_OpenMP_msmcBase
#define OpenMP_msmcSize ti_runtime_ompbios_OpenMP_msmcSize
#define OpenMP_msmcNoCacheVirtualBase ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualBase
#define OpenMP_msmcNoCacheVirtualSize ti_runtime_ompbios_OpenMP_msmcNoCacheVirtualSize
#define OpenMP_msmcNoCachePhysicalBase ti_runtime_ompbios_OpenMP_msmcNoCachePhysicalBase
#define OpenMP_ddrBase ti_runtime_ompbios_OpenMP_ddrBase
#define OpenMP_ddrSize ti_runtime_ompbios_OpenMP_ddrSize
#define OpenMP_ddrNoCacheBase ti_runtime_ompbios_OpenMP_ddrNoCacheBase
#define OpenMP_ddrNoCacheSize ti_runtime_ompbios_OpenMP_ddrNoCacheSize
#define OpenMP_mpaxForMsmcMapping ti_runtime_ompbios_OpenMP_mpaxForMsmcMapping
#define OpenMP_hwSemBaseIdx ti_runtime_ompbios_OpenMP_hwSemBaseIdx
#define OpenMP_hwSemCount ti_runtime_ompbios_OpenMP_hwSemCount
#define OpenMP_qmssInit ti_runtime_ompbios_OpenMP_qmssInit
#define OpenMP_qmssMemRegionIndex ti_runtime_ompbios_OpenMP_qmssMemRegionIndex
#define OpenMP_qmssFirstDescIdxInLinkingRam ti_runtime_ompbios_OpenMP_qmssFirstDescIdxInLinkingRam
#define OpenMP_qmssHwQueueBaseIdx ti_runtime_ompbios_OpenMP_qmssHwQueueBaseIdx
#define OpenMP_useIpcSharedHeap ti_runtime_ompbios_OpenMP_useIpcSharedHeap
#define OpenMP_allocateLocalHeap ti_runtime_ompbios_OpenMP_allocateLocalHeap
#define OpenMP_allocateLocalHeapSize ti_runtime_ompbios_OpenMP_allocateLocalHeapSize
#define OpenMP_allocateSharedHeap ti_runtime_ompbios_OpenMP_allocateSharedHeap
#define OpenMP_allocateSharedHeapSize ti_runtime_ompbios_OpenMP_allocateSharedHeapSize
#define OpenMP_allocateStackFromHeap ti_runtime_ompbios_OpenMP_allocateStackFromHeap
#define OpenMP_allocateStackFromHeapSize ti_runtime_ompbios_OpenMP_allocateStackFromHeapSize
#define OpenMP_useSharedHeap ti_runtime_ompbios_OpenMP_useSharedHeap
#define OpenMP_Module_name ti_runtime_ompbios_OpenMP_Module_name
#define OpenMP_Module_id ti_runtime_ompbios_OpenMP_Module_id
#define OpenMP_Module_startup ti_runtime_ompbios_OpenMP_Module_startup
#define OpenMP_Module_startupDone ti_runtime_ompbios_OpenMP_Module_startupDone
#define OpenMP_Module_hasMask ti_runtime_ompbios_OpenMP_Module_hasMask
#define OpenMP_Module_getMask ti_runtime_ompbios_OpenMP_Module_getMask
#define OpenMP_Module_setMask ti_runtime_ompbios_OpenMP_Module_setMask
#define OpenMP_Object_heap ti_runtime_ompbios_OpenMP_Object_heap
#define OpenMP_Module_heap ti_runtime_ompbios_OpenMP_Module_heap

#endif /* ti_runtime_ompbios_OpenMP__localnames__done */
#endif
