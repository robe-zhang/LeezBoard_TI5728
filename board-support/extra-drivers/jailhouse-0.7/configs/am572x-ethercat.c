/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Configuration for uart-demo inmate on AM57XX-EVM:
 *
 * Copyright (c) Texas Instruments, Inc.
 *
 * Authors:
 *  Vitaly Andrianiov <vitalya@ti.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <jailhouse/types.h>
#include <jailhouse/cell-config.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct {
	struct jailhouse_cell_desc cell;
	__u64 cpus[1];
	struct jailhouse_memory mem_regions[7];
	struct jailhouse_irqchip irqchips[1];
} __attribute__((packed)) config = {
	.cell = {
		.signature = JAILHOUSE_CELL_DESC_SIGNATURE,
		.revision = JAILHOUSE_CONFIG_REVISION,
		.name = "AM572X-IDK-ETHERCAT",
		.flags = JAILHOUSE_CELL_PASSIVE_COMMREG,
		.num_irqchips = 1,
		.cpu_set_size = sizeof(config.cpus),
		.num_memory_regions = ARRAY_SIZE(config.mem_regions),
	},

	.cpus = {
		0x2,
	},

	.mem_regions = {
		/* UART... */ {
			.phys_start = 0x48020000,
			.virt_start = 0x48020000,
			.size = 0x1000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* ... */ {
			.phys_start = 0x48050000,
			.virt_start = 0x48050000,
			.size = 0x10000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* L4_CFG */ {
			.phys_start = 0x4a000000,
			.virt_start = 0x4a000000,
			.size = 0xE10000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* PRUSS */ {
			.phys_start = 0x4b200000,
			.virt_start = 0x4b200000,
			.size = 0x100000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
		/* RAM loader */ {
			.phys_start = 0xed000000,
			.virt_start = 0x0,
			.size = 0x10000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_EXECUTE | JAILHOUSE_MEM_LOADABLE,
		},
		/* RAM RTOS 224MB*/ {
			.phys_start = 0xe0000000,
			.virt_start = 0x80000000,
			.size = 0xd000000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_EXECUTE | JAILHOUSE_MEM_LOADABLE,
		},
		/* Comminication region */ {
			.phys_start = 0xeef00000,
			.virt_start = 0xeef00000,
			.size = 0x100000,
			.flags = JAILHOUSE_MEM_READ | JAILHOUSE_MEM_WRITE |
				JAILHOUSE_MEM_IO | JAILHOUSE_MEM_ROOTSHARED,
		},
	},
	.irqchips = {
		/* GIC */ {
			.address = 0x48211000,
			.pin_base = 160, // 166, 167, 168 and 169
			.pin_bitmap = {
				1 << 6 | 1 << 7 | 1 << 8 | 1 << 9,
			},
		},
	}
};
