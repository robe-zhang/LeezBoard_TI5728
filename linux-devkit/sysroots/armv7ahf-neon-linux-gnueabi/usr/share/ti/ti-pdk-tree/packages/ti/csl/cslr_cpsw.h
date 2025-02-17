/********************************************************************
 * Copyright (C) 2013-2017 Texas Instruments Incorporated.
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
*/
/*********************************************************************
* file: cslr_cpsw.h
*
* Brief: This file contains the Register Description for cpsw_5gf
*
*********************************************************************/
#ifndef CSLR_CPSW_TOP_H
#define CSLR_CPSW_TOP_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#if defined(SOC_K2K)

#include <ti/csl/src/ip/cpsw/V0/cslr_cpsw_5gf.h>

#elif defined(SOC_K2H)

#include <ti/csl/src/ip/cpsw/V0/cslr_cpsw_5gf.h>

#elif defined(SOC_K2L)

#include <ti/csl/src/ip/xge/V1/cslr_xge_cpsw.h>

#elif defined(SOC_K2E)

#include <ti/csl/src/ip/xge/V1/cslr_xge_cpsw.h>

#elif defined(SOC_K2G)

#include <ti/csl/src/ip/xge/V2/cslr_xge_cpsw.h>

#elif defined(SOC_C6678)

#include <ti/csl/src/ip/cpsw/V4/cslr_cpsw_3gf.h>

#elif defined(SOC_AM574x) || defined(SOC_AM572x)|| defined(SOC_AM571x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined(SOC_DRA75x) || defined(SOC_TDA2EX) || defined(SOC_DRA72x) || defined(SOC_TDA3XX) || defined (SOC_DRA78x)

#include <ti/csl/src/ip/cpsw/V3/cslr_cpsw_3g.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_cpsw_ss.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_wr.h>
#include <ti/csl/src/ip/cpdma/V0/cslr_cpdma.h>

#endif /* SOC_XXXXX */

#endif
