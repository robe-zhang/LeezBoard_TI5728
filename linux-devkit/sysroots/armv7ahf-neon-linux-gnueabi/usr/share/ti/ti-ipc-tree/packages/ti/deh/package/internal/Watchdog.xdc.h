/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */

#ifndef ti_deh_Watchdog__INTERNAL__
#define ti_deh_Watchdog__INTERNAL__

#ifndef ti_deh_Watchdog__internalaccess
#define ti_deh_Watchdog__internalaccess
#endif

#include <ti/deh/Watchdog.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* init */
#undef ti_deh_Watchdog_init
#define ti_deh_Watchdog_init ti_deh_Watchdog_init__F

/* idleBegin */
#undef ti_deh_Watchdog_idleBegin
#define ti_deh_Watchdog_idleBegin ti_deh_Watchdog_idleBegin__F

/* taskSwitch */
#undef ti_deh_Watchdog_taskSwitch
#define ti_deh_Watchdog_taskSwitch ti_deh_Watchdog_taskSwitch__F

/* swiPrehook */
#undef ti_deh_Watchdog_swiPrehook
#define ti_deh_Watchdog_swiPrehook ti_deh_Watchdog_swiPrehook__F

/* isException */
#undef ti_deh_Watchdog_isException
#define ti_deh_Watchdog_isException ti_deh_Watchdog_isException__F

/* stop */
#define Watchdog_stop ti_deh_Watchdog_stop__I

/* start */
#define Watchdog_start ti_deh_Watchdog_start__I

/* kick */
#define Watchdog_kick ti_deh_Watchdog_kick__I

/* restore */
#define Watchdog_restore ti_deh_Watchdog_restore__I

/* Module_startup */
#undef ti_deh_Watchdog_Module_startup
#define ti_deh_Watchdog_Module_startup ti_deh_Watchdog_Module_startup__E

/* Instance_init */
#undef ti_deh_Watchdog_Instance_init
#define ti_deh_Watchdog_Instance_init ti_deh_Watchdog_Instance_init__E

/* Instance_finalize */
#undef ti_deh_Watchdog_Instance_finalize
#define ti_deh_Watchdog_Instance_finalize ti_deh_Watchdog_Instance_finalize__E

/* module */
#ifdef ti_deh_Watchdog_Module__state__VR
#define Watchdog_module ((ti_deh_Watchdog_Module_State *)(xdcRomStatePtr + ti_deh_Watchdog_Module__state__V_offset))
#define module ((ti_deh_Watchdog_Module_State *)(xdcRomStatePtr + ti_deh_Watchdog_Module__state__V_offset))
#else
#define Watchdog_module ((ti_deh_Watchdog_Module_State *)(xdc__MODOBJADDR__(ti_deh_Watchdog_Module__state__V)))
#if !defined(__cplusplus) ||!defined(ti_deh_Watchdog__cplusplus)
#define module ((ti_deh_Watchdog_Module_State *)(xdc__MODOBJADDR__(ti_deh_Watchdog_Module__state__V)))
#endif
#endif

/* per-module runtime symbols */
#undef Module__MID
#ifdef ti_deh_Watchdog_Module__id__CR
#define Module__MID (*((CT__ti_deh_Watchdog_Module__id *)(xdcRomConstPtr + ti_deh_Watchdog_Module__id__C_offset)))
#else
#define Module__MID ti_deh_Watchdog_Module__id__C
#endif

#undef Module__DGSINCL
#ifdef ti_deh_Watchdog_Module__diagsIncluded__CR
#define Module__DGSINCL (*((CT__ti_deh_Watchdog_Module__diagsIncluded *)(xdcRomConstPtr + ti_deh_Watchdog_Module__diagsIncluded__C_offset)))
#else
#define Module__DGSINCL ti_deh_Watchdog_Module__diagsIncluded__C
#endif

#undef Module__DGSENAB
#ifdef ti_deh_Watchdog_Module__diagsEnabled__CR
#define Module__DGSENAB (*((CT__ti_deh_Watchdog_Module__diagsEnabled *)(xdcRomConstPtr + ti_deh_Watchdog_Module__diagsEnabled__C_offset)))
#else
#define Module__DGSENAB ti_deh_Watchdog_Module__diagsEnabled__C
#endif

#undef Module__DGSMASK
#ifdef ti_deh_Watchdog_Module__diagsMask__CR
#define Module__DGSMASK (*((CT__ti_deh_Watchdog_Module__diagsMask *)(xdcRomConstPtr + ti_deh_Watchdog_Module__diagsMask__C_offset)))
#else
#define Module__DGSMASK ti_deh_Watchdog_Module__diagsMask__C
#endif

#undef Module__LOGDEF
#ifdef ti_deh_Watchdog_Module__loggerDefined__CR
#define Module__LOGDEF (*((CT__ti_deh_Watchdog_Module__loggerDefined *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerDefined__C_offset)))
#else
#define Module__LOGDEF ti_deh_Watchdog_Module__loggerDefined__C
#endif

#undef Module__LOGOBJ
#ifdef ti_deh_Watchdog_Module__loggerObj__CR
#define Module__LOGOBJ ti_deh_Watchdog_Module__loggerObj__R
#define Module__LOGOBJ (*((CT__ti_deh_Watchdog_Module__loggerObj *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerObj__C_offset)))
#else
#define Module__LOGOBJ ti_deh_Watchdog_Module__loggerObj__C
#endif

#undef Module__LOGFXN0
#ifdef ti_deh_Watchdog_Module__loggerFxn0__CR
#define Module__LOGFXN0 (*((CT__ti_deh_Watchdog_Module__loggerFxn0 *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerFxn0__C_offset)))
#else
#define Module__LOGFXN0 ti_deh_Watchdog_Module__loggerFxn0__C
#endif

#undef Module__LOGFXN1
#ifdef ti_deh_Watchdog_Module__loggerFxn1__CR
#define Module__LOGFXN1 (*((CT__ti_deh_Watchdog_Module__loggerFxn1 *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerFxn1__C_offset)))
#else
#define Module__LOGFXN1 ti_deh_Watchdog_Module__loggerFxn1__C
#endif

#undef Module__LOGFXN2
#ifdef ti_deh_Watchdog_Module__loggerFxn2__CR
#define Module__LOGFXN2 (*((CT__ti_deh_Watchdog_Module__loggerFxn2 *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerFxn2__C_offset)))
#else
#define Module__LOGFXN2 ti_deh_Watchdog_Module__loggerFxn2__C
#endif

#undef Module__LOGFXN4
#ifdef ti_deh_Watchdog_Module__loggerFxn4__CR
#define Module__LOGFXN4 (*((CT__ti_deh_Watchdog_Module__loggerFxn4 *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerFxn4__C_offset)))
#else
#define Module__LOGFXN4 ti_deh_Watchdog_Module__loggerFxn4__C
#endif

#undef Module__LOGFXN8
#ifdef ti_deh_Watchdog_Module__loggerFxn8__CR
#define Module__LOGFXN8 (*((CT__ti_deh_Watchdog_Module__loggerFxn8 *)(xdcRomConstPtr + ti_deh_Watchdog_Module__loggerFxn8__C_offset)))
#else
#define Module__LOGFXN8 ti_deh_Watchdog_Module__loggerFxn8__C
#endif

#undef Module__G_OBJ
#ifdef ti_deh_Watchdog_Module__gateObj__CR
#define Module__G_OBJ (*((CT__ti_deh_Watchdog_Module__gateObj *)(xdcRomConstPtr + ti_deh_Watchdog_Module__gateObj__C_offset)))
#else
#define Module__G_OBJ ti_deh_Watchdog_Module__gateObj__C
#endif

#undef Module__G_PRMS
#ifdef ti_deh_Watchdog_Module__gatePrms__CR
#define Module__G_PRMS (*((CT__ti_deh_Watchdog_Module__gatePrms *)(xdcRomConstPtr + ti_deh_Watchdog_Module__gatePrms__C_offset)))
#else
#define Module__G_PRMS ti_deh_Watchdog_Module__gatePrms__C
#endif

#undef Module__GP_create
#define Module__GP_create ti_deh_Watchdog_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_deh_Watchdog_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_deh_Watchdog_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_deh_Watchdog_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_deh_Watchdog_Module_GateProxy_query


#endif /* ti_deh_Watchdog__INTERNAL____ */
