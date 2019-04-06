/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */

#ifndef ti_runtime_ompbios_OpenMP__INTERNAL__
#define ti_runtime_ompbios_OpenMP__INTERNAL__

#ifndef ti_runtime_ompbios_OpenMP__internalaccess
#define ti_runtime_ompbios_OpenMP__internalaccess
#endif

#include <ti/runtime/ompbios/OpenMP.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* useSharedHeap */
#undef ti_runtime_ompbios_OpenMP_useSharedHeap
#define ti_runtime_ompbios_OpenMP_useSharedHeap ti_runtime_ompbios_OpenMP_useSharedHeap__F

/* setProcId */
#define OpenMP_setProcId ti_runtime_ompbios_OpenMP_setProcId__I

/* Module_startup */
#undef ti_runtime_ompbios_OpenMP_Module_startup
#define ti_runtime_ompbios_OpenMP_Module_startup ti_runtime_ompbios_OpenMP_Module_startup__E

/* Instance_init */
#undef ti_runtime_ompbios_OpenMP_Instance_init
#define ti_runtime_ompbios_OpenMP_Instance_init ti_runtime_ompbios_OpenMP_Instance_init__E

/* Instance_finalize */
#undef ti_runtime_ompbios_OpenMP_Instance_finalize
#define ti_runtime_ompbios_OpenMP_Instance_finalize ti_runtime_ompbios_OpenMP_Instance_finalize__E

/* module */
#ifdef ti_runtime_ompbios_OpenMP_Module__state__VR
#define OpenMP_module ((ti_runtime_ompbios_OpenMP_Module_State *)(xdcRomStatePtr + ti_runtime_ompbios_OpenMP_Module__state__V_offset))
#define module ((ti_runtime_ompbios_OpenMP_Module_State *)(xdcRomStatePtr + ti_runtime_ompbios_OpenMP_Module__state__V_offset))
#else
#define OpenMP_module ((ti_runtime_ompbios_OpenMP_Module_State *)(xdc__MODOBJADDR__(ti_runtime_ompbios_OpenMP_Module__state__V)))
#if !defined(__cplusplus) ||!defined(ti_runtime_ompbios_OpenMP__cplusplus)
#define module ((ti_runtime_ompbios_OpenMP_Module_State *)(xdc__MODOBJADDR__(ti_runtime_ompbios_OpenMP_Module__state__V)))
#endif
#endif

/* per-module runtime symbols */
#undef Module__MID
#ifdef ti_runtime_ompbios_OpenMP_Module__id__CR
#define Module__MID (*((CT__ti_runtime_ompbios_OpenMP_Module__id *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__id__C_offset)))
#else
#define Module__MID ti_runtime_ompbios_OpenMP_Module__id__C
#endif

#undef Module__DGSINCL
#ifdef ti_runtime_ompbios_OpenMP_Module__diagsIncluded__CR
#define Module__DGSINCL (*((CT__ti_runtime_ompbios_OpenMP_Module__diagsIncluded *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C_offset)))
#else
#define Module__DGSINCL ti_runtime_ompbios_OpenMP_Module__diagsIncluded__C
#endif

#undef Module__DGSENAB
#ifdef ti_runtime_ompbios_OpenMP_Module__diagsEnabled__CR
#define Module__DGSENAB (*((CT__ti_runtime_ompbios_OpenMP_Module__diagsEnabled *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C_offset)))
#else
#define Module__DGSENAB ti_runtime_ompbios_OpenMP_Module__diagsEnabled__C
#endif

#undef Module__DGSMASK
#ifdef ti_runtime_ompbios_OpenMP_Module__diagsMask__CR
#define Module__DGSMASK (*((CT__ti_runtime_ompbios_OpenMP_Module__diagsMask *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__diagsMask__C_offset)))
#else
#define Module__DGSMASK ti_runtime_ompbios_OpenMP_Module__diagsMask__C
#endif

#undef Module__LOGDEF
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerDefined__CR
#define Module__LOGDEF (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerDefined *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerDefined__C_offset)))
#else
#define Module__LOGDEF ti_runtime_ompbios_OpenMP_Module__loggerDefined__C
#endif

#undef Module__LOGOBJ
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerObj__CR
#define Module__LOGOBJ ti_runtime_ompbios_OpenMP_Module__loggerObj__R
#define Module__LOGOBJ (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerObj *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerObj__C_offset)))
#else
#define Module__LOGOBJ ti_runtime_ompbios_OpenMP_Module__loggerObj__C
#endif

#undef Module__LOGFXN0
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn0__CR
#define Module__LOGFXN0 (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn0 *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C_offset)))
#else
#define Module__LOGFXN0 ti_runtime_ompbios_OpenMP_Module__loggerFxn0__C
#endif

#undef Module__LOGFXN1
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn1__CR
#define Module__LOGFXN1 (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn1 *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C_offset)))
#else
#define Module__LOGFXN1 ti_runtime_ompbios_OpenMP_Module__loggerFxn1__C
#endif

#undef Module__LOGFXN2
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn2__CR
#define Module__LOGFXN2 (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn2 *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C_offset)))
#else
#define Module__LOGFXN2 ti_runtime_ompbios_OpenMP_Module__loggerFxn2__C
#endif

#undef Module__LOGFXN4
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn4__CR
#define Module__LOGFXN4 (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn4 *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C_offset)))
#else
#define Module__LOGFXN4 ti_runtime_ompbios_OpenMP_Module__loggerFxn4__C
#endif

#undef Module__LOGFXN8
#ifdef ti_runtime_ompbios_OpenMP_Module__loggerFxn8__CR
#define Module__LOGFXN8 (*((CT__ti_runtime_ompbios_OpenMP_Module__loggerFxn8 *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C_offset)))
#else
#define Module__LOGFXN8 ti_runtime_ompbios_OpenMP_Module__loggerFxn8__C
#endif

#undef Module__G_OBJ
#ifdef ti_runtime_ompbios_OpenMP_Module__gateObj__CR
#define Module__G_OBJ (*((CT__ti_runtime_ompbios_OpenMP_Module__gateObj *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__gateObj__C_offset)))
#else
#define Module__G_OBJ ti_runtime_ompbios_OpenMP_Module__gateObj__C
#endif

#undef Module__G_PRMS
#ifdef ti_runtime_ompbios_OpenMP_Module__gatePrms__CR
#define Module__G_PRMS (*((CT__ti_runtime_ompbios_OpenMP_Module__gatePrms *)(xdcRomConstPtr + ti_runtime_ompbios_OpenMP_Module__gatePrms__C_offset)))
#else
#define Module__G_PRMS ti_runtime_ompbios_OpenMP_Module__gatePrms__C
#endif

#undef Module__GP_create
#define Module__GP_create ti_runtime_ompbios_OpenMP_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_runtime_ompbios_OpenMP_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_runtime_ompbios_OpenMP_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_runtime_ompbios_OpenMP_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_runtime_ompbios_OpenMP_Module_GateProxy_query


#endif /* ti_runtime_ompbios_OpenMP__INTERNAL____ */
