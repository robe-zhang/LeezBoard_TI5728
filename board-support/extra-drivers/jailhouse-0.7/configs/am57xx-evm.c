/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Copyright (c) Texas Insturments. Inc, 2016
 *
 * Authors:
 *  Vitaly Andrianov <vitalya@ti.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <jailhouse/types.h>
#include <jailhouse/cell-config.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct {
	struct jailhouse_system header;
	__u64 cpus[1];
	struct jailhouse_memory mem_regions[17];
	struct jailhouse_irqchip irqchips[2];
} __attribute__((packed)) config = {
	.header = {
		.signature = JAILHOUSE_SYSTEM_SIGNATURE,
		.revision = JAILHOUSE_CONFIG_REVISION,
		.hypervisor_memory = {
			.phys_start = 0xef000000,
			.size = 0x1000000,
		},
		.debug_console = {
			.address = 0x48020000,
			.size = 0x1000,
			/* .divider = 26, */
			.flags = JAILHOUSE_CON1_TYPE_8250 |
				JAILHOUSE_CON1_ACCESS_MMIO |
				JAILHOUSE_CON1_REGDIST_4 |
				JAILHOUSE_CON2_TYPE_ROOTPAGE,
		},
		.platform_info.arm = {
			.gicd_base = 0x48211000,
			.gicc_base = 0x48212000,
			.gich_base = 0x48214000,
			.gicv_base = 0x48216000,
			.maintenance_irq = 25,
		},
		.root_cell = {
			.name = "AM57XX-EVM",
			.cpu_set_size = sizeof(config.cpus),
			.num_memory_regions = ARRAY_SIZE(config.mem_regions),
			.num_irqchips = ARRAY_SIZE(config.irqchips),
		},
	},

	.cpus = {
		0x3,
	},

	.mem_regions = {
		/* OCMCRAM */ {
			.phys_start = 0x40300000,
			.virt_start = 0x40300000,
			.size = 0x80000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* 0x40380000 - 0x48020000 */ {
			.phys_start = 0x40380000,
			.virt_start = 0x40380000,
			.size = 0x7ca0000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* UART... */ {
			.phys_start = 0x48020000,
			.virt_start = 0x48020000,
			.size = 0xe0000,//0x00001000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* 0x48100000 - 0x48281000 */ {
			.phys_start = 0x48100000,
			.virt_start = 0x48100000,
			.size = 0x110000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/*
		 * Leave gap for GIC controller 0x48210000 - 0x41220000
		 */
		/* 0x48220000 - 0x48281000 */ {
			.phys_start = 0x48220000,
			.virt_start = 0x48220000,
			.size = 0x610000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* OMAP WakeupGen */ {
			.phys_start = 0x48281000,
			.virt_start = 0x48281000,
			.size = 0x1000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* PRCM MPU */ {
			.phys_start = 0x48243000,
			.virt_start = 0x48243000,
			.size = 0x1000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* 0x48400000 - 0x48424000 */ {
			.phys_start = 0x48400000,
			.virt_start = 0x48400000,
			.size = 0x24000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* UART... */ {
			.phys_start = 0x48424000,
			.virt_start = 0x48424000,
			.size = 0x2000,//0x00001000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},

		/* 0x48426000 - 0x48826000 */ {
			.phys_start = 0x48426000,
			.virt_start = 0x48426000,
			.size = 0x400000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* 0x48826000 - 0x48828000 */ {
			.phys_start = 0x48826000,
			.virt_start = 0x48826000,
			.size = 0x2000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* 0x48828000 - 0x4B300000 */ {
			.phys_start = 0x48828000,
			.virt_start = 0x48828000,
			.size = 0x2ad8000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},

		/* 0x4B500000 - 0x58000000 */ {
			.phys_start = 0x4B500000,
			.virt_start = 0x4B500000,
			.size = 0xCB00000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* Display Subsystem & ...*/ {
			.phys_start = 0x58000000,
			.virt_start = 0x58000000,
			.size = 0x8000000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* RAM */ {
			.phys_start = 0x80000000,
			.virt_start = 0x80000000,
			.size = 0x6EF00000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_EXECUTE,
		},
		/* communication region */ {
			.phys_start = 0xEEF00000,
			.virt_start = 0xEEF00000,
			.size = 0x00100000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO,
		},
		/* Leave hole for hypervisor */

		/* RAM */ {
			.phys_start = 0xF0000000,
			.virt_start = 0xF0000000,
			.size = 0x10000000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_EXECUTE,
		},
	},
	.irqchips = {
		/* GIC */ {
			.address = 0x48211000,
			.pin_base = 32,
			.pin_bitmap = {
				0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
			},
		},
		/* GIC */ {
			.address = 0x48211000,
			.pin_base = 160,
			.pin_bitmap = {
				0xffffffff, 0, 0, 0
			},
		},
	},

};
