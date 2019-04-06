/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */

#ifndef ti_ipc_remoteproc_Resource__INTERNAL__
#define ti_ipc_remoteproc_Resource__INTERNAL__

#ifndef ti_ipc_remoteproc_Resource__internalaccess
#define ti_ipc_remoteproc_Resource__internalaccess
#endif

#include <ti/ipc/remoteproc/Resource.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* virtToPhys */
#undef ti_ipc_remoteproc_Resource_virtToPhys
#define ti_ipc_remoteproc_Resource_virtToPhys ti_ipc_remoteproc_Resource_virtToPhys__E

/* physToVirt */
#undef ti_ipc_remoteproc_Resource_physToVirt
#define ti_ipc_remoteproc_Resource_physToVirt ti_ipc_remoteproc_Resource_physToVirt__E

/* getTraceBufPtr */
#undef ti_ipc_remoteproc_Resource_getTraceBufPtr
#define ti_ipc_remoteproc_Resource_getTraceBufPtr ti_ipc_remoteproc_Resource_getTraceBufPtr__E

/* getVdevStatus */
#undef ti_ipc_remoteproc_Resource_getVdevStatus
#define ti_ipc_remoteproc_Resource_getVdevStatus ti_ipc_remoteproc_Resource_getVdevStatus__E

/* getVringDA */
#undef ti_ipc_remoteproc_Resource_getVringDA
#define ti_ipc_remoteproc_Resource_getVringDA ti_ipc_remoteproc_Resource_getVringDA__E

/* init */
#define Resource_init ti_ipc_remoteproc_Resource_init__I

/* getMemEntry */
#define Resource_getMemEntry ti_ipc_remoteproc_Resource_getMemEntry__I

/* Module_startup */
#undef ti_ipc_remoteproc_Resource_Module_startup
#define ti_ipc_remoteproc_Resource_Module_startup ti_ipc_remoteproc_Resource_Module_startup__E

/* Instance_init */
#undef ti_ipc_remoteproc_Resource_Instance_init
#define ti_ipc_remoteproc_Resource_Instance_init ti_ipc_remoteproc_Resource_Instance_init__E

/* Instance_finalize */
#undef ti_ipc_remoteproc_Resource_Instance_finalize
#define ti_ipc_remoteproc_Resource_Instance_finalize ti_ipc_remoteproc_Resource_Instance_finalize__E

/* module */
#ifdef ti_ipc_remoteproc_Resource_Module__state__VR
#define Resource_module ((ti_ipc_remoteproc_Resource_Module_State *)(xdcRomStatePtr + ti_ipc_remoteproc_Resource_Module__state__V_offset))
#define module ((ti_ipc_remoteproc_Resource_Module_State *)(xdcRomStatePtr + ti_ipc_remoteproc_Resource_Module__state__V_offset))
#else
#define Resource_module ((ti_ipc_remoteproc_Resource_Module_State *)(xdc__MODOBJADDR__(ti_ipc_remoteproc_Resource_Module__state__V)))
#if !defined(__cplusplus) ||!defined(ti_ipc_remoteproc_Resource__cplusplus)
#define module ((ti_ipc_remoteproc_Resource_Module_State *)(xdc__MODOBJADDR__(ti_ipc_remoteproc_Resource_Module__state__V)))
#endif
#endif

/* per-module runtime symbols */
#undef Module__MID
#ifdef ti_ipc_remoteproc_Resource_Module__id__CR
#define Module__MID (*((CT__ti_ipc_remoteproc_Resource_Module__id *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__id__C_offset)))
#else
#define Module__MID ti_ipc_remoteproc_Resource_Module__id__C
#endif

#undef Module__DGSINCL
#ifdef ti_ipc_remoteproc_Resource_Module__diagsIncluded__CR
#define Module__DGSINCL (*((CT__ti_ipc_remoteproc_Resource_Module__diagsIncluded *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__diagsIncluded__C_offset)))
#else
#define Module__DGSINCL ti_ipc_remoteproc_Resource_Module__diagsIncluded__C
#endif

#undef Module__DGSENAB
#ifdef ti_ipc_remoteproc_Resource_Module__diagsEnabled__CR
#define Module__DGSENAB (*((CT__ti_ipc_remoteproc_Resource_Module__diagsEnabled *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__diagsEnabled__C_offset)))
#else
#define Module__DGSENAB ti_ipc_remoteproc_Resource_Module__diagsEnabled__C
#endif

#undef Module__DGSMASK
#ifdef ti_ipc_remoteproc_Resource_Module__diagsMask__CR
#define Module__DGSMASK (*((CT__ti_ipc_remoteproc_Resource_Module__diagsMask *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__diagsMask__C_offset)))
#else
#define Module__DGSMASK ti_ipc_remoteproc_Resource_Module__diagsMask__C
#endif

#undef Module__LOGDEF
#ifdef ti_ipc_remoteproc_Resource_Module__loggerDefined__CR
#define Module__LOGDEF (*((CT__ti_ipc_remoteproc_Resource_Module__loggerDefined *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerDefined__C_offset)))
#else
#define Module__LOGDEF ti_ipc_remoteproc_Resource_Module__loggerDefined__C
#endif

#undef Module__LOGOBJ
#ifdef ti_ipc_remoteproc_Resource_Module__loggerObj__CR
#define Module__LOGOBJ ti_ipc_remoteproc_Resource_Module__loggerObj__R
#define Module__LOGOBJ (*((CT__ti_ipc_remoteproc_Resource_Module__loggerObj *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerObj__C_offset)))
#else
#define Module__LOGOBJ ti_ipc_remoteproc_Resource_Module__loggerObj__C
#endif

#undef Module__LOGFXN0
#ifdef ti_ipc_remoteproc_Resource_Module__loggerFxn0__CR
#define Module__LOGFXN0 (*((CT__ti_ipc_remoteproc_Resource_Module__loggerFxn0 *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerFxn0__C_offset)))
#else
#define Module__LOGFXN0 ti_ipc_remoteproc_Resource_Module__loggerFxn0__C
#endif

#undef Module__LOGFXN1
#ifdef ti_ipc_remoteproc_Resource_Module__loggerFxn1__CR
#define Module__LOGFXN1 (*((CT__ti_ipc_remoteproc_Resource_Module__loggerFxn1 *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerFxn1__C_offset)))
#else
#define Module__LOGFXN1 ti_ipc_remoteproc_Resource_Module__loggerFxn1__C
#endif

#undef Module__LOGFXN2
#ifdef ti_ipc_remoteproc_Resource_Module__loggerFxn2__CR
#define Module__LOGFXN2 (*((CT__ti_ipc_remoteproc_Resource_Module__loggerFxn2 *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerFxn2__C_offset)))
#else
#define Module__LOGFXN2 ti_ipc_remoteproc_Resource_Module__loggerFxn2__C
#endif

#undef Module__LOGFXN4
#ifdef ti_ipc_remoteproc_Resource_Module__loggerFxn4__CR
#define Module__LOGFXN4 (*((CT__ti_ipc_remoteproc_Resource_Module__loggerFxn4 *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerFxn4__C_offset)))
#else
#define Module__LOGFXN4 ti_ipc_remoteproc_Resource_Module__loggerFxn4__C
#endif

#undef Module__LOGFXN8
#ifdef ti_ipc_remoteproc_Resource_Module__loggerFxn8__CR
#define Module__LOGFXN8 (*((CT__ti_ipc_remoteproc_Resource_Module__loggerFxn8 *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__loggerFxn8__C_offset)))
#else
#define Module__LOGFXN8 ti_ipc_remoteproc_Resource_Module__loggerFxn8__C
#endif

#undef Module__G_OBJ
#ifdef ti_ipc_remoteproc_Resource_Module__gateObj__CR
#define Module__G_OBJ (*((CT__ti_ipc_remoteproc_Resource_Module__gateObj *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__gateObj__C_offset)))
#else
#define Module__G_OBJ ti_ipc_remoteproc_Resource_Module__gateObj__C
#endif

#undef Module__G_PRMS
#ifdef ti_ipc_remoteproc_Resource_Module__gatePrms__CR
#define Module__G_PRMS (*((CT__ti_ipc_remoteproc_Resource_Module__gatePrms *)(xdcRomConstPtr + ti_ipc_remoteproc_Resource_Module__gatePrms__C_offset)))
#else
#define Module__G_PRMS ti_ipc_remoteproc_Resource_Module__gatePrms__C
#endif

#undef Module__GP_create
#define Module__GP_create ti_ipc_remoteproc_Resource_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_ipc_remoteproc_Resource_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_ipc_remoteproc_Resource_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_ipc_remoteproc_Resource_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_ipc_remoteproc_Resource_Module_GateProxy_query


#endif /* ti_ipc_remoteproc_Resource__INTERNAL____ */
