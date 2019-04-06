/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Copyright (c) ARM Limited, 2014
 * Copyright (c) Siemens AG, 2016
 *
 * Authors:
 *  Jean-Philippe Brucker <jean-philippe.brucker@arm.com>
 *  Jan Kiszka <jan.kiszka@siemens.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <jailhouse/control.h>
#include <jailhouse/mmio.h>
#include <jailhouse/printk.h>
#include <asm/control.h>
#include <asm/mach.h>
#include <asm/setup.h>
#include <asm/traps.h>

#define OMAP_WKUPGEN_BASE	0x48281000
#define OMAP_AUX_CORE_BOOT_0	0x800

const unsigned int smp_mmio_regions;

static void *wkupgen_base = NULL;

int mach_init(void)
{
	wkupgen_base = paging_map_device(OMAP_WKUPGEN_BASE, PAGE_SIZE);
	return (wkupgen_base == NULL) ? -ENOMEM : 0;
}

void mach_cell_init(struct cell *cell)
{
}

void mach_cell_exit(struct cell *cell)
{
	unsigned int cpu;
	for_each_cpu(cpu, cell->cpu_set) {
		per_cpu(cpu)->cpu_on_entry =
			mmio_read32(wkupgen_base + OMAP_AUX_CORE_BOOT_0 +
				    cpu * 4);
		per_cpu(cpu)->cpu_on_context = 0;
		arch_suspend_cpu(cpu);
		arch_reset_cpu(cpu);
	}
}

int arch_handle_smc(struct trap_context *ctx)
{
	unsigned long *regs = ctx->regs;

	switch (regs[12]) {
	case 0x102:
		arm_write_banked_reg(ELR_hyp, regs[0]);
		return TRAP_HANDLED;
	case 0x109:
		asm volatile(
			".arch_extension sec\n\t"
			"push {r0-r12, lr}\n\t"
			"mov ip,%0\n\t"
			"mov r0,%1\n\t"
			"smc #0\n\t"
			"pop {r0-r12, lr}\n\t"
			: : "r" (regs[0]), "r" (regs[12]));
		break;
	default:
		panic_printk("FATAL: Invalid SMC\n");
		return TRAP_FORBIDDEN;
	}

	arch_skip_instruction(ctx);

	return TRAP_HANDLED;
}
