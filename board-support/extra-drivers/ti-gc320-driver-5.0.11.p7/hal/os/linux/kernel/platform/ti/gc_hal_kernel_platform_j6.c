/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2014 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************
*
*    The GPL License (GPL)
*
*    Copyright (C) 2014  Vivante Corporation
*
*    This program is free software; you can redistribute it and/or
*    modify it under the terms of the GNU General Public License
*    as published by the Free Software Foundation; either version 2
*    of the License, or (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*****************************************************************************
*
*    Note: This software is released under dual MIT and GPL licenses. A
*    recipient may use this file under the terms of either the MIT license or
*    GPL License. If you wish to use only one license not the other, you can
*    indicate your decision by deleting one of the above license notices in your
*    version of this file.
*
*****************************************************************************/


#include "gc_hal_kernel_linux.h"
#include "gc_hal_kernel_platform.h"

#include <linux/pm_runtime.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <asm/cacheflush.h>
#include <linux/slab.h>
#include <linux/pagemap.h>
#include <linux/highmem.h>

/*
 * GC320 platform data struct, using the definition as in
 * `linux/platform_data/omap_gcx.h` in k3.8
 *
 * TODO: revisit this and tune it as per latest requirements
 */
struct omap_gcx_platform_data {
    bool is_hw_present;
    void *regbase;
    /*bool (*was_context_lost)(struct device *dev);*/
    int (*get_context_loss_count)(struct device *dev);
    /* device scale */
    int (*scale_dev)(struct device *dev, unsigned long freq);
    /* bandwidth */
    int (*set_bw)(struct device *dev, unsigned long v);
};

static int gcxxx_get_context_loss_count(struct device *dev)
{
    /*
        omap_pm_get_context_loss_count not supported:
        returning with default 1
    */
    return 1;
}
static int gcxxx_scale_dev(struct device *dev, unsigned long val)
{
    /*omap_device_scale(dev, val) is not supported, returning with no-op
    * for now. */
    return 0;
}

static int gcxxx_set_l3_bw(struct device *dev, unsigned long val)
{
    return 0; /*omap_pm_set_min_bus_tput(dev, OCP_INITIATOR_AGENT, val);*/
}
static struct omap_gcx_platform_data omap_gcxxx = {
    .get_context_loss_count = gcxxx_get_context_loss_count,
    .scale_dev = gcxxx_scale_dev,
    .set_bw = gcxxx_set_l3_bw,
};



static const struct of_device_id bb2d_of_match[] = {
    {
        .compatible = "ti,dra7-bb2d",
        .data = &omap_gcxxx,
    },
    {},
};


static gctBOOL
_NeedAddDevice(
    IN gckPLATFORM Platform
    )
{
    /* 
     * platform_device is registered through DTS framework, we dont need to
     * register explicitly, return false here.
     */
    return gcvFALSE;
}

/* override J6 specific fields of `platform_driver` */
static gceSTATUS
_AdjustDriver(
    IN gckPLATFORM Platform
    )
{
    struct platform_driver * driver = Platform->driver;

    /* return DTS match entry */
    driver->driver.of_match_table = bb2d_of_match;

    return gcvSTATUS_TRUE;
}

/* prepare clock and power operations */
static gceSTATUS
_GetPower(
    IN gckPLATFORM Platform
    )
{
    struct platform_device *pdev;
    pdev = Platform->device;

    pm_runtime_enable(&pdev->dev);
    pm_runtime_get_sync(&pdev->dev);

    return gcvSTATUS_TRUE;
}

/* finish clock and power operations */
static gceSTATUS
_PutPower(
    IN gckPLATFORM Platform
    )
{
    struct platform_device *pdev;
    pdev = Platform->device;

    pm_runtime_put_sync(&pdev->dev);
    pm_runtime_disable(&pdev->dev);

    return gcvSTATUS_TRUE;
}

/*
 * AdjustParam - override default/passed in module arguments.
 *
 * Here we modify/update IRQ and register address entries by querying through
 * DTS framework.
 */
static gceSTATUS
_AdjustParam(
    IN gckPLATFORM Platform,
    OUT gcsMODULE_PARAMETERS *Args
    )
{
    struct resource *res_ptr = NULL;

    struct omap_gcx_platform_data *plat;
    struct of_device_id *match;
    struct platform_device *pdev;
    int dev_irq;

    if (Args->registerMemMapped)
        return gcvSTATUS_TRUE;

    pdev = Platform->device;

    match = (struct of_device_id *)of_match_device(of_match_ptr(bb2d_of_match), &pdev->dev);

    if (match) {
        plat = (struct omap_gcx_platform_data *) match->data;
        plat->is_hw_present = (of_machine_is_compatible("ti, omap54xx")	|| of_machine_is_compatible("ti,dra7"));
    } else {
        /* platform_device registration */
        plat = (struct omap_gcx_platform_data *)dev_get_platdata(&pdev->dev);
    }

    if ( !plat->is_hw_present )
        return gcvSTATUS_FALSE;

    res_ptr = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    if (!res_ptr) {
        return gcvSTATUS_FALSE;
    }
    /* map the address space */
    Args->registerMemAddress = (gctPOINTER)devm_ioremap_resource(&pdev->dev, res_ptr);
    Args->registerMemMapped = gcvTRUE;

    /*
     * IRQ line is acquired through commandline argument with unified driver.
     * With k3.14, the MPU IRQ line in J6 is configured dynamically at runtime
     * per dtb configuration and has to be queried through `platform_get_irq()`
     * API.
     */
    dev_irq = platform_get_irq(pdev, 0);
    if (dev_irq < 0) {
        /* TODO: use Vivante debug prints */
        printk(KERN_ERR "%s: platform_get_irq failed (%d)\n",
                __FUNCTION__, -dev_irq);
        return -EINVAL;
    }
    printk(KERN_INFO "GC320 IRQ: %d\n", dev_irq);
    Args->irqLine = dev_irq;
    
    return gcvSTATUS_TRUE;
}

static gceSTATUS
cache_op_on_page(struct page *page, enum dma_data_direction dir)
{
    if (!PageHighMem(page) && page_to_phys(page)) {
        dma_sync_single_for_device(gcvNULL,
                page_to_phys(page),
                PAGE_SIZE,
                dir);
    } else {
        flush_dcache_page(page);
    }

    return gcvSTATUS_OK;
}

static gceSTATUS
cache_op_on_mdl(PLINUX_MDL mdl, enum dma_data_direction dir)
{
    gceSTATUS status = gcvSTATUS_OK;
    uint32_t i = 0;
    uint32_t numPages = mdl->numPages;

    for (i = 0; i < numPages; i++) {
        struct page *page;

        if (mdl->contiguous) {
            page = nth_page(mdl->u.contiguousPages, i);
        } else {
            page = mdl->u.nonContiguousPages[i];
        }

        status = cache_op_on_page(page, dir);
    }
    return status;
}

static gceSTATUS
logical_to_page(gctUINTPTR_T logical, struct page **page)
{
    gceSTATUS status = gcvSTATUS_OK;
    pgd_t *pgd;
    pmd_t *pmd;
    pud_t *pud;
    pte_t *pte;
    spinlock_t *ptl;

    pgd = pgd_offset(current->mm, logical);
    if (pgd_none(*pgd) || pgd_bad(*pgd)) {
        gckOS_DebugTrace(gcvLEVEL_ERROR, "Invalid pgd entry\n");
        gcmkONERROR(gcvSTATUS_INVALID_ADDRESS);
    }

    pud = pud_offset(pgd, logical);
    if (pud_none(*pud) || pud_bad(*pud)) {
        gckOS_DebugTrace(gcvLEVEL_ERROR, "Invalid pud entry\n");
        gcmkONERROR(gcvSTATUS_INVALID_ADDRESS);
    }

    pmd = pmd_offset(pud, logical);
    if (pmd_none(*pmd) || pmd_bad(*pmd)) {
        gckOS_DebugTrace(gcvLEVEL_ERROR, "Invalid pmd entry\n");
        gcmkONERROR(gcvSTATUS_INVALID_ADDRESS);
    }

    pte = pte_offset_map_lock(current->mm, pmd, logical, &ptl);
    if (pte_none(*pte) || !pte_present(*pte) || !pte_write(*pte)) {
            status = gcvSTATUS_INVALID_ADDRESS;
            goto UnLock;
    }
    *page = pte_page(*pte);

UnLock:
    pte_unmap_unlock(pte, ptl);
OnError:
    return status;
}

static gceSTATUS
cache_op_on_logical(gctPOINTER logical, gctSIZE_T bytes,
        enum dma_data_direction dir)
{
    gceSTATUS status = gcvSTATUS_OK;
    gctUINTPTR_T startAddr, endAddr;
    gctUINTPTR_T startAddrAligned, endAddrAligned;
    gctSIZE_T pageCount;
    struct page **pages;
    int numPagesMapped;
    int i;

    startAddr = (gctUINTPTR_T)logical;
    endAddr = startAddr + bytes;

    startAddrAligned = startAddr & PAGE_MASK;
    endAddrAligned = PAGE_ALIGN(endAddr);
    pageCount = (endAddrAligned - startAddrAligned) >> PAGE_SHIFT;

    pages = kmalloc(pageCount * sizeof(struct page *), GFP_KERNEL);
    if (!pages) {
        status = gcvSTATUS_OUT_OF_MEMORY;
        goto OnError;
    }
    memset(pages, 0, sizeof(struct page *) * pageCount);

    /* lock down user memory */
    down_read(&current->mm->mmap_sem);

    numPagesMapped = get_user_pages(
            startAddr, pageCount, FOLL_WRITE, pages, gcvNULL);

    if (numPagesMapped == pageCount) {
        for (i = 0; i < pageCount; i++) {
            status = cache_op_on_page(pages[i], dir);
        }
    } else {
        struct vm_area_struct *vma;

        /* get_user_pages didnt work, release the pages if any and look for
         * the pages in the appropriate memory region of the process. Region
         * might correspond to memory mapped I/O.
         */
        gckOS_DebugTrace(gcvLEVEL_INFO,
                "get_user_pages failed (%d/%d pages), trying to acquire from CPU page table\n",
                numPagesMapped, pageCount);
        if (numPagesMapped > 0) {
            for (i = 0; i < numPagesMapped; i++) {
                if (pages[i] == gcvNULL)
                    break;

                put_page(pages[i]);
                pages[i] = gcvNULL;
            }
            numPagesMapped = 0;
        }

        vma = find_vma(current->mm, startAddr);
        if (!vma) {
            gckOS_DebugTrace(gcvLEVEL_ERROR,
                    "%s: find_vma returned error for start address 0x%lx\n",
                    startAddr);
            status = gcvSTATUS_INVALID_ADDRESS;
            goto OnExit;
        }

        /* find_vma locates a region with an end point past a given virtual
         * address, check if the address is within in the region
         */
        if (startAddr < vma->vm_start) {
            gckOS_DebugTrace(gcvLEVEL_ERROR,
                    "start address 0x%lx is outside the returned vma region\n",
                    startAddr);
            goto OnExit;
        }
        if (endAddr > vma->vm_end) {
            gckOS_DebugTrace(gcvLEVEL_ERROR,
                    "end address 0x%lx is outside the returned vma region\n",
                    endAddr);
            goto OnExit;
        }
        if (!(vma->vm_flags & VM_IO) || !(vma->vm_flags & VM_PFNMAP)) {
            gckOS_DebugTrace(gcvLEVEL_ERROR,
                    "Memory region does not represent IO || PFNMAP region (VMA flags 0x%lx)\n",
                    vma->vm_flags);
            goto OnExit;
        }
        if ((vma->vm_flags & (VM_READ | VM_WRITE)) != (VM_READ | VM_WRITE)) {
            gckOS_DebugTrace(gcvLEVEL_ERROR,
                    "No read/write access to memory region (VMA flags 0x%lx\n",
                    vma->vm_flags);
            goto OnExit;
        }

        for (i = 0; i < pageCount; i++) {
            gctUINTPTR_T logical = startAddr;

            status = logical_to_page(logical, &pages[i]);
            if (status)
                goto OnExit;
            status = cache_op_on_page(pages[i], dir);
            if (status)
                goto OnExit;

            logical += PAGE_SIZE;
        }
    }

OnExit:
    up_read(&current->mm->mmap_sem);

    kfree(pages);

OnError:
    return status;
}

/*
 * cache ops: The driver is using the old `dmac_{flush,clean,inv}_range` API
 * for doing cache ops. This API is no longer available since k4.3 and needed
 * to be updated. Performing cache ops on individual pages here in the platform
 * op. This could have resided in the driver as well as no platform specific
 * changes are in here.
 */
static gceSTATUS
platform_cache(
        IN gckPLATFORM Platform,
        IN gctUINT32 ProcessID,
        IN gctPHYS_ADDR Handle,
        IN gctUINT32 Physical,
        IN gctPOINTER Logical,
        IN gctSIZE_T Bytes,
        IN gceCACHEOPERATION Operation
        )
{
    gceSTATUS status = gcvSTATUS_OK;
    enum dma_data_direction dir;

    switch (Operation) {
    case gcvCACHE_FLUSH:
        dir = DMA_BIDIRECTIONAL;
        break;
    case gcvCACHE_CLEAN:
        dir = DMA_TO_DEVICE;
        break;
    case gcvCACHE_INVALIDATE:
        dir = DMA_FROM_DEVICE;
        break;
    default:
        return gcvSTATUS_INVALID_ARGUMENT;
    }

    /* have access to phys addr, use dma api */
    if (Physical != gcvINVALID_ADDRESS) {
        dma_sync_single_for_device(gcvNULL,
                (dma_addr_t)Physical,
                Bytes,
                dir);
    } else if (Handle != gcvNULL) {
        /* only have access to unified driver `PLINUX_MDL` struct,
         * query page list from this struct and perform cache ops
         * on each page.
         */
        PLINUX_MDL mdl = (PLINUX_MDL)Handle;
        status = cache_op_on_mdl(mdl, dir);
    } else {
        status = cache_op_on_logical(Logical, Bytes, dir);
    }

    return status;
}

gcsPLATFORM_OPERATIONS platformOperations =
{
    .adjustParam   = _AdjustParam,
    .adjustDriver  = _AdjustDriver,
    .needAddDevice = _NeedAddDevice,
    .getPower      = _GetPower,
    .putPower      = _PutPower,
    .cache         = platform_cache,
};

void
gckPLATFORM_QueryOperations(
    IN gcsPLATFORM_OPERATIONS ** Operations
    )
{
     *Operations = &platformOperations;
}
