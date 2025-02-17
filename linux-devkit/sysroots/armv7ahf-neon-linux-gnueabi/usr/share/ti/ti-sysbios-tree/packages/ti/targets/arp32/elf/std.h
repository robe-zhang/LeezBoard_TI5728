/* 
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 * 
 * */
/*
 *  ======== ti/targets/arp32/elf/std.h ========
 *  Standard types for supported TI compilers for ARP32
 */

#ifndef ti_targets_arp32_elf_STD_
#define ti_targets_arp32_elf_STD_

/*  Define target-specific "portable" macros
 *
 *  The build command-line define xdc_target_name__ to be the value
 *  of the target's name config parameter.  We use this to include the
 *  target-specific definitions for the required target-independent
 *  xdc_target* macros.
 */
#if defined(xdc_target_name__) & !defined(xdc_target_macros_include__)
#include xdc__local_include(xdc_target_name__)
#endif

/* "inherit" (i.e., include) all ti.targets standard types */
#include <ti/targets/std.h>

#endif /* ti_targets_arp32_elf_STD_ */
/*
 *  @(#) ti.targets.arp32.elf; 1, 0, 0,1; 7-27-2017 11:47:41; /db/ztree/library/trees/xdctargets/xdctargets-o04/src/ xlibrary

 */

