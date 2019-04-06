/*
 * hooks_profiling_hdr.h
 *
 * AET Library public API Definitions 
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  ==========================hooks_profiling_hdr.h=============================
 *  Revision Information
 *   Changed: $LastChangedDate: 2013-01-18 15:47:09 -0600 (Fri, 18 Jan 2013) $
 *   Revision: $LastChangedRevision: 10598 $
 *   Last Update By: $Author: KarthikRamanaSankar $ 
 *  ============================================================================ 
 */
//----------------------------------------------------------------------------
// HOOKS_PROFILING_HDR.H
// Header file that must be included by all the application files.  Contains
// the inline definition of the actual hook functions.
//----------------------------------------------------------------------------

#if !defined(HOOKS_PROFILING_HDR)
#define HOOKS_PROFILING_HDR

#if defined(_TMS320C6X)
   #if __TI_COMPILER_VERSION__ < 6001000
   #error "Must use C6000 Compiler Version 6.1.X or higher"
   #endif
#else
   #warn "Untested target"
#endif

#include <stdint.h>  // for uintptr_t

//----------------------------------------------------------------------------
// Written to when the thread changes
//----------------------------------------------------------------------------
extern far uintptr_t hooks_profiling_watch_thread;

//----------------------------------------------------------------------------
// Names for how the inline functions are DECLared and DEFiNed.  Note _INLINE
// is defined only if the optimizer is used and thus can handle the actual
// inlining of the hook functions.
//----------------------------------------------------------------------------
#ifdef _INLINE
   #define HOOKS_PROFILING_IDECL static __inline
   #define HOOKS_PROFILING_IDEFN static __inline
#else
   #define HOOKS_PROFILING_IDECL extern
   #define HOOKS_PROFILING_IDEFN
#endif

//----------------------------------------------------------------------------
// Declarations of the hooks functions
//----------------------------------------------------------------------------
HOOKS_PROFILING_IDECL void hooks_profiling_entry(void);
HOOKS_PROFILING_IDECL void hooks_profiling_exit(void);

#endif // !defined(HOOKS_PROFILING_HDR)

//----------------------------------------------------------------------------
// Define the hook functions in either of 2 cases.  1. The optimizer is being
// used and the hooks functions are being inlined.  Note the exclusion guarding
// due to HOOKS_PROFILING_HDR_FXNS for this case.  2. The file 
// hooks_profiling_impl.c is including this file a 2nd time so it can get
// an normal out-of-line definition of these functions.  More details in 
// that file.
//----------------------------------------------------------------------------
#if defined(_INLINE) && !defined(HOOKS_PROFILING_HDR_FXNS) || defined(HOOKS_PROFILING_IMPLEMENTATION)
#define HOOKS_PROFILING_HDR_FXNS

//----------------------------------------------------------------------------
// Explaining the nop 5 ...  There is a bug in trace HW that prevents it from
// triggering (starting to capture data) while in the delay slots of a branch.
// When at the start of a function, it is possible to be in the delays slots
// of a branch that is not taken.  If that occurs, trace starts capturing data
// too late, and the MARK instruction is missed.  The nop 5 insures that the
// MARK instruction is not in the delay slots of any branch, and thus will
// always trace will always trigger immediately.
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// HOOKS_PROFILING_ENTRY
//----------------------------------------------------------------------------
HOOKS_PROFILING_IDEFN void hooks_profiling_entry(void)
{
   asm(" nop 5");
   _mark(0);
}

//----------------------------------------------------------------------------
// HOOKS_PROFILING_EXIT
//----------------------------------------------------------------------------
HOOKS_PROFILING_IDEFN void hooks_profiling_exit(void)
{
   asm(" nop 5");
   _mark(1);
}

#endif

