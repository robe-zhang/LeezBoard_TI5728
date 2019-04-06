/*
* Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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
*/

/* This file defines the function to program the GC320 IP */

#include <stdint.h>
#include "cmem_buf.h"
#include "gc320.h"
#include "error.h"
#include "cmem_buf.h"

/* Configure one time the source and destination surface context for all buffers 
* as they cost some performance overhead if configured per frame. Since the
* buffer parameters aren't changing in this application run time, we can save the overhead 
*/
Gc320Obj::Gc320Obj(uint32_t num_src_surf, uint32_t num_dst_surf, BufObj *src_bo, BufObj *dst_bo){
    m_dst_width   = dst_bo->m_width;
    m_dst_height  = dst_bo->m_height;
    m_dst_stride  = dst_bo->m_stride; 
    m_dst_format  = gcvSURF_UYVY; 

    m_src_width  = src_bo->m_width;
    m_src_height = src_bo->m_height;
    m_src_stride = src_bo->m_stride;
    m_src_format = gcvSURF_UYVY;

    m_src_surf_ctxt = (surf_context *) malloc(num_src_surf * sizeof(surf_context));
    m_dst_surf_ctxt = (surf_context *) malloc(num_src_surf * sizeof(surf_context));

    init_gc320();

    configure_surface(m_src_surf_ctxt, num_src_surf, src_bo, m_src_format);
    configure_surface(m_dst_surf_ctxt, num_dst_surf, dst_bo, m_dst_format);
}


/*
*  ~Gc320Obj() //Class destructor
* free all resources
*/
Gc320Obj::~Gc320Obj(){
    if (m_hal != gcvNULL){
        gcoHAL_Commit(m_hal, true);
    }

    for(uint32_t i = 0; i < m_num_dst_ctx; i++){
        if (m_dst_surf_ctxt[i].surf != gcvNULL){
            gceHARDWARE_TYPE type;

            gcoHAL_GetHardwareType(gcvNULL, &type);

            gcmVERIFY_OK(gcoSURF_Unlock(m_dst_surf_ctxt[i].surf, gcvNULL));
            gcmVERIFY_OK(gcoSURF_Destroy(m_dst_surf_ctxt[i].surf));
            gcmVERIFY_OK(gcoHAL_Commit(gcvNULL, true));

            gcoHAL_SetHardwareType(gcvNULL, type);
        }
    }

    for(uint32_t i = 0; i < m_num_src_ctx; i++){
        if (m_src_surf_ctxt[i].surf != gcvNULL){
            gceHARDWARE_TYPE type;

            gcoHAL_GetHardwareType(gcvNULL, &type);

            gcmVERIFY_OK(gcoSURF_Unlock(m_src_surf_ctxt[i].surf, gcvNULL));
            gcmVERIFY_OK(gcoSURF_Destroy(m_src_surf_ctxt[i].surf));
            gcmVERIFY_OK(gcoHAL_Commit(gcvNULL, true));

            gcoHAL_SetHardwareType(gcvNULL, type);
        }
    }

    if (m_hal != gcvNULL){
        gcoHAL_Commit(m_hal, true);
        gcoHAL_Destroy(m_hal);
    }

    if (m_os != gcvNULL){
        gcoOS_Destroy(m_os);
    }
}


int Gc320Obj::chip_check(){
    gceSTATUS status;
    uint32_t i;
    int ret = 0;
    gceCHIPMODEL    chip_model;
    uint32_t       chip_revision;
    uint32_t       patch_revision;
    uint32_t       chip_features;
    uint32_t       chip_minor_features_number;
    uint32_t       chip_minor_features[MAX_MINORFEATURE_NUMBER];

    status = gcoHAL_QueryChipIdentity(m_hal, &chip_model, &chip_revision, &chip_features, gcvNULL);
    if (status < 0){
        ERROR("Failed to query chip info (status = 0x%x)\n", status);
        ret = -1;
        goto EXIT;
    }

    status = gcoOS_ReadRegister(m_os, 0x98, &patch_revision);
    if (status < 0){
        ERROR("Failed to read patch version (status = 0x%x)\n", status);
        ret = -2;
        goto EXIT;
    }

    MSG("=================== Chip Information ==================\n");
    MSG("Chip : GC%x\n", chip_model);
    MSG("Chip revision: 0x%08x\n", chip_revision);
    MSG( "Patch revision: 0x%08x\n", patch_revision);
    MSG("Chip Features: 0x%08x\n", chip_features);

    status = gcoHAL_QueryChipMinorFeatures(m_hal, &chip_minor_features_number, gcvNULL);
    if (status < 0){
        ERROR("Failed to query minor feature count (status = 0x%x)\n", status);
        ret = -2;
        goto EXIT;
    }

    if (MAX_MINORFEATURE_NUMBER < chip_minor_features_number){
        ERROR("no enough space for minor features\n");
        ret = -3;
        goto EXIT;
    }

    status = gcoHAL_QueryChipMinorFeatures(m_hal, &chip_minor_features_number, chip_minor_features);
    if (status < 0){
        ERROR("Failed to query minor features (status = 0x%x)\n", status);
        ret = -4;
        goto EXIT;
    }

    for (i = 0; i < chip_minor_features_number; i++){
        MSG("Chip MinorFeatures%d: 0x%08x\n", i, chip_minor_features[i]);
    }

    MSG("=======================================================\n");

EXIT:

    return ret;
}

int Gc320Obj::init_gc320() {

    gceSTATUS status;

    /* Construct the gcoOS object. */
    status = gcoOS_Construct(gcvNULL, &m_os);
    if (status < 0){
        ERROR("Failed to construct OS object (status = %d)\n", status);
        return false;
    }

    /* Construct the gcoHAL object. */
    status = gcoHAL_Construct(gcvNULL, m_os, &m_hal);
    if (status < 0){
        ERROR("Failed to construct GAL object (status = %d)\n", status);
        return false;
    }

    if (!gcoHAL_IsFeatureAvailable(m_hal, gcvFEATURE_2DPE20)){

        switch (m_dst_format){
            /* PE1.0 support. */
        case gcvSURF_X4R4G4B4:
        case gcvSURF_A4R4G4B4:
        case gcvSURF_X1R5G5B5:
        case gcvSURF_A1R5G5B5:
        case gcvSURF_X8R8G8B8:
        case gcvSURF_A8R8G8B8:
        case gcvSURF_R5G6B5:
            break;

        default:
            ERROR("the target format %d is not supported by the hardware.\n",
                m_dst_format);
            return false;
        }
    }

    status = gcoHAL_Get2DEngine(m_hal, &m_engine2d);
    MSG("****GC320 m_engine2d = %x\n", (uint32_t) m_engine2d);
    if (status < 0){
        ERROR("Failed to get 2D engine object (status = %d)\n", status);
        return false;
    }

    if (chip_check() < 0){
        ERROR("Check chip info failed!\n");
        return false;
    }

    return true;
}

int Gc320Obj::configure_surface(surf_context *surf_ctx,
        uint32_t num_ctx, BufObj *bo, gceSURF_FORMAT surf_format) {

    gceSTATUS status;
    gceHARDWARE_TYPE type;
    unsigned long phys = ~0U;

    gcoHAL_GetHardwareType(gcvNULL, &type);

    for(uint32_t i = 0; i < num_ctx; i++){
        if (!bo->m_buf[i]) {
            ERROR("Received null pointer\n");
            return -1;
        }
        /* create a wrapper gcoSURF surface object, because we are mapping the user
        * allocated buffer pool should be gcvPOOL_USER */
        status = gcoSURF_Construct(
            gcvNULL,
            bo->m_width,
            bo->m_height,
            1,
            gcvSURF_BITMAP,
            surf_format,
            gcvPOOL_USER,
            &surf_ctx[i].surf);

        if (status < 0) {
            ERROR(" Failed to create gcoSURF object\n");
            return false;
        }

        /* calculate the size of the buffer needed. Use gcoSURF_QueryFormat API to
        * format parameters descriptor - this contains information on format as
        * needed by the Vivante driver
        */
        uint32_t width, height;
        int stride;
        gcmONERROR(gcoSURF_GetAlignedSize(surf_ctx[i].surf,
            &width,
            &height,
            &stride));

        if((width != bo->m_width) || (height != bo->m_height) || ((uint32_t) stride != bo->m_stride)){
            ERROR("Allocated Surf buffer width %d, height %d and stride %d doesn't meet GC320 aligned requirement on width %d, height %d and stride %d\n", 
            	bo->m_width, bo->m_height, bo->m_stride, width, height, stride);
        }

        uint32_t  p_adr_al;
        gcmONERROR(gcoSURF_GetAlignment(gcvSURF_BITMAP, surf_format,
            &p_adr_al,
			NULL, //&p_x_al,
            NULL //&p_y_al)
			));

		if((uint32_t)bo->m_buf[i] % p_adr_al){
			ERROR("Buffer passed to GC320 doesn't meet the alignment requirement, GC320 alignment need is %x, received buffer with %x aligned address\n", 
				p_adr_al, ((uint32_t)bo->m_buf[i]%p_adr_al));
		}

        /* Buffer provided meets all the requirement from GC320. 
		Go ahead and set the underlying buffer */
        gcmONERROR(gcoSURF_SetBuffer(
            surf_ctx[i].surf,
            gcvSURF_BITMAP,
            surf_format,
            bo->m_stride,
            bo->m_buf[i],
            phys));

        if (status < 0) {
            ERROR("Failed to set buffer for gcoSURF object\n");
            return false;
        }

        /* set window size */
        gcmONERROR(gcoSURF_SetWindow(surf_ctx[i].surf, 0, 0, bo->m_width, bo->m_height));
        if (status < 0) {
            ERROR("Failed to set window for gcoSURF object\n");
            return false;
        }

        /* lock surface */
        gcmONERROR(gcoSURF_Lock(surf_ctx[i].surf, surf_ctx[i].phys_address, &bo->m_buf[i]));
        if (status < 0) {
            ERROR("Failed to lock gcoSURF object\n");
            return false;
        }

        gcoHAL_SetHardwareType(gcvNULL, type);
    }

    return true;

OnError:
    ERROR("Failed: %s\n", gcoOS_DebugStatus2Name(status));

    return false;
}

bool Gc320Obj::rotation_90deg(uint32_t src_surf_indx, uint32_t dst_surf_indx){

    gcsRECT src_rect, dst_rect, clip_rect;
    gceSTATUS status = gcvSTATUS_OK;

    // render to dest surface
    // blit with 90 rotation
    src_rect.left   = 0;
    src_rect.top    = 0;
    src_rect.right  = m_src_width;
    src_rect.bottom = m_src_height;

    // set the clipping according to the rotation
    clip_rect.left 	  = 0;
    clip_rect.top 	  = 0;
    clip_rect.right   = m_dst_height;
    clip_rect.bottom  = m_dst_width;

    gcmONERROR(gco2D_SetClipping(m_engine2d, &clip_rect));

	//Since the buffer is getting rotated 90 degree, make sure the destination buffer width is larger than source buffer height */
    dst_rect.left   = 0;
    dst_rect.top    = (m_dst_width - m_src_height);
    dst_rect.right  = dst_rect.left + m_src_width;
    dst_rect.bottom = dst_rect.top + m_src_height;

    gcmONERROR(gco2D_SetGenericSource(m_engine2d,
        m_src_surf_ctxt[src_surf_indx].phys_address, 1, &m_src_stride, 1,
        gcvLINEAR, m_src_format, gcvSURF_0_DEGREE,
        m_src_width, m_src_height));

    gcmONERROR(gco2D_SetSource(m_engine2d, &src_rect));

    gcmONERROR(gco2D_SetTarget(m_engine2d,
        m_dst_surf_ctxt[dst_surf_indx].phys_address[0],
        m_dst_stride,
        gcvSURF_90_DEGREE,
        m_dst_width));

    gcmONERROR(gco2D_Blit(m_engine2d,
        1,
        &dst_rect,
        0xCC,
        0xCC,
        m_dst_format));
    gcmONERROR(gco2D_Flush(m_engine2d));
    gcmONERROR(gcoHAL_Commit(m_hal, true));

    return true;

OnError:
    ERROR("Failed: %s\n", gcoOS_DebugStatus2Name(status));
	return false;
}
