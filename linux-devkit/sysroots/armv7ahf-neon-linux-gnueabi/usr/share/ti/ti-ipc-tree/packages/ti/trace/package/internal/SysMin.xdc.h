/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */

#ifndef ti_trace_SysMin__INTERNAL__
#define ti_trace_SysMin__INTERNAL__

#ifndef ti_trace_SysMin__internalaccess
#define ti_trace_SysMin__internalaccess
#endif

#include <ti/trace/SysMin.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* abort */
#undef ti_trace_SysMin_abort
#define ti_trace_SysMin_abort ti_trace_SysMin_abort__E

/* exit */
#undef ti_trace_SysMin_exit
#define ti_trace_SysMin_exit ti_trace_SysMin_exit__E

/* flush */
#undef ti_trace_SysMin_flush
#define ti_trace_SysMin_flush ti_trace_SysMin_flush__E

/* putch */
#undef ti_trace_SysMin_putch
#define ti_trace_SysMin_putch ti_trace_SysMin_putch__E

/* ready */
#undef ti_trace_SysMin_ready
#define ti_trace_SysMin_ready ti_trace_SysMin_ready__E

/* Module_startup */
#undef ti_trace_SysMin_Module_startup
#define ti_trace_SysMin_Module_startup ti_trace_SysMin_Module_startup__E

/* Instance_init */
#undef ti_trace_SysMin_Instance_init
#define ti_trace_SysMin_Instance_init ti_trace_SysMin_Instance_init__E

/* Instance_finalize */
#undef ti_trace_SysMin_Instance_finalize
#define ti_trace_SysMin_Instance_finalize ti_trace_SysMin_Instance_finalize__E

/* module */
#ifdef ti_trace_SysMin_Module__state__VR
#define SysMin_module ((ti_trace_SysMin_Module_State *)(xdcRomStatePtr + ti_trace_SysMin_Module__state__V_offset))
#define module ((ti_trace_SysMin_Module_State *)(xdcRomStatePtr + ti_trace_SysMin_Module__state__V_offset))
#else
#define SysMin_module ((ti_trace_SysMin_Module_State *)(xdc__MODOBJADDR__(ti_trace_SysMin_Module__state__V)))
#if !defined(__cplusplus) ||!defined(ti_trace_SysMin__cplusplus)
#define module ((ti_trace_SysMin_Module_State *)(xdc__MODOBJADDR__(ti_trace_SysMin_Module__state__V)))
#endif
#endif

/* per-module runtime symbols */
#undef Module__MID
#ifdef ti_trace_SysMin_Module__id__CR
#define Module__MID (*((CT__ti_trace_SysMin_Module__id *)(xdcRomConstPtr + ti_trace_SysMin_Module__id__C_offset)))
#else
#define Module__MID ti_trace_SysMin_Module__id__C
#endif

#undef Module__DGSINCL
#ifdef ti_trace_SysMin_Module__diagsIncluded__CR
#define Module__DGSINCL (*((CT__ti_trace_SysMin_Module__diagsIncluded *)(xdcRomConstPtr + ti_trace_SysMin_Module__diagsIncluded__C_offset)))
#else
#define Module__DGSINCL ti_trace_SysMin_Module__diagsIncluded__C
#endif

#undef Module__DGSENAB
#ifdef ti_trace_SysMin_Module__diagsEnabled__CR
#define Module__DGSENAB (*((CT__ti_trace_SysMin_Module__diagsEnabled *)(xdcRomConstPtr + ti_trace_SysMin_Module__diagsEnabled__C_offset)))
#else
#define Module__DGSENAB ti_trace_SysMin_Module__diagsEnabled__C
#endif

#undef Module__DGSMASK
#ifdef ti_trace_SysMin_Module__diagsMask__CR
#define Module__DGSMASK (*((CT__ti_trace_SysMin_Module__diagsMask *)(xdcRomConstPtr + ti_trace_SysMin_Module__diagsMask__C_offset)))
#else
#define Module__DGSMASK ti_trace_SysMin_Module__diagsMask__C
#endif

#undef Module__LOGDEF
#ifdef ti_trace_SysMin_Module__loggerDefined__CR
#define Module__LOGDEF (*((CT__ti_trace_SysMin_Module__loggerDefined *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerDefined__C_offset)))
#else
#define Module__LOGDEF ti_trace_SysMin_Module__loggerDefined__C
#endif

#undef Module__LOGOBJ
#ifdef ti_trace_SysMin_Module__loggerObj__CR
#define Module__LOGOBJ ti_trace_SysMin_Module__loggerObj__R
#define Module__LOGOBJ (*((CT__ti_trace_SysMin_Module__loggerObj *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerObj__C_offset)))
#else
#define Module__LOGOBJ ti_trace_SysMin_Module__loggerObj__C
#endif

#undef Module__LOGFXN0
#ifdef ti_trace_SysMin_Module__loggerFxn0__CR
#define Module__LOGFXN0 (*((CT__ti_trace_SysMin_Module__loggerFxn0 *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerFxn0__C_offset)))
#else
#define Module__LOGFXN0 ti_trace_SysMin_Module__loggerFxn0__C
#endif

#undef Module__LOGFXN1
#ifdef ti_trace_SysMin_Module__loggerFxn1__CR
#define Module__LOGFXN1 (*((CT__ti_trace_SysMin_Module__loggerFxn1 *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerFxn1__C_offset)))
#else
#define Module__LOGFXN1 ti_trace_SysMin_Module__loggerFxn1__C
#endif

#undef Module__LOGFXN2
#ifdef ti_trace_SysMin_Module__loggerFxn2__CR
#define Module__LOGFXN2 (*((CT__ti_trace_SysMin_Module__loggerFxn2 *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerFxn2__C_offset)))
#else
#define Module__LOGFXN2 ti_trace_SysMin_Module__loggerFxn2__C
#endif

#undef Module__LOGFXN4
#ifdef ti_trace_SysMin_Module__loggerFxn4__CR
#define Module__LOGFXN4 (*((CT__ti_trace_SysMin_Module__loggerFxn4 *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerFxn4__C_offset)))
#else
#define Module__LOGFXN4 ti_trace_SysMin_Module__loggerFxn4__C
#endif

#undef Module__LOGFXN8
#ifdef ti_trace_SysMin_Module__loggerFxn8__CR
#define Module__LOGFXN8 (*((CT__ti_trace_SysMin_Module__loggerFxn8 *)(xdcRomConstPtr + ti_trace_SysMin_Module__loggerFxn8__C_offset)))
#else
#define Module__LOGFXN8 ti_trace_SysMin_Module__loggerFxn8__C
#endif

#undef Module__G_OBJ
#ifdef ti_trace_SysMin_Module__gateObj__CR
#define Module__G_OBJ (*((CT__ti_trace_SysMin_Module__gateObj *)(xdcRomConstPtr + ti_trace_SysMin_Module__gateObj__C_offset)))
#else
#define Module__G_OBJ ti_trace_SysMin_Module__gateObj__C
#endif

#undef Module__G_PRMS
#ifdef ti_trace_SysMin_Module__gatePrms__CR
#define Module__G_PRMS (*((CT__ti_trace_SysMin_Module__gatePrms *)(xdcRomConstPtr + ti_trace_SysMin_Module__gatePrms__C_offset)))
#else
#define Module__G_PRMS ti_trace_SysMin_Module__gatePrms__C
#endif

#undef Module__GP_create
#define Module__GP_create ti_trace_SysMin_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_trace_SysMin_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_trace_SysMin_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_trace_SysMin_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_trace_SysMin_Module_GateProxy_query


#endif /* ti_trace_SysMin__INTERNAL____ */
