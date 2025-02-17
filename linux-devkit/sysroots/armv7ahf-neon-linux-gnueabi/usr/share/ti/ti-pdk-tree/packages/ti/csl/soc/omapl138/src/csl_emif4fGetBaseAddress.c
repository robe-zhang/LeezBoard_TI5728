/**
 *   @file  csl_emif4fGetBaseAddress.c
 *
 *   @brief
 *      The file contains routines which are EMIF4F Device specific
 *      and need to be modified for each new device which has the
 *      EMIF4F IP Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */

#include <ti/csl/soc.h>
#include <ti/csl/csl_emif4f.h>

/** ============================================================================
 *   @n@b CSL_EMIF4F_getBaseAddr
 *
 *   @b Description
 *   @n This API gets the EMIF4F instance. This should always be the first call
 *      to the CSL EMIF4F Functional layer. The handle  which is returned from
 *      this call should be passed in all subsequent CSL API's.
 *
 *   <b> Return Value </b>
 *   @n  CSL_Emif4fHandle  - Handle to the EMIF4F Module
 *   @n  0                 - Error.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Affects
 *   @n  None.
 *
 *   @b  Example
 *   @verbatim
        CSL_Emif4fHandle   hEmif4f;
        ...
        hEmif4f = CSL_EMIF4F_getBaseAddr (0);    // Opens EMIF4F Instance 0
        ...
     @endverbatim
 * ===========================================================================
 */
CSL_Emif4fHandle CSL_EMIF4F_getBaseAddr (int32_t instNum);
CSL_Emif4fHandle CSL_EMIF4F_getBaseAddr (int32_t instNum)
{
    CSL_Emif4fHandle ret_val = (CSL_Emif4fHandle) 0;
    switch (instNum)
    {

        case (int32_t)CSL_EMIFA:
        {
            ret_val = (CSL_Emif4fHandle) CSL_EMIFA_0_REGS;
            break;
        }
        default:
        {
            ret_val = (CSL_Emif4fHandle) 0;
            break;
        }
    }
    return(ret_val);
}

