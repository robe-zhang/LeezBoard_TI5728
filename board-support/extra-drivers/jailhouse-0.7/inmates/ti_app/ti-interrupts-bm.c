/*
 * Copyright (c) Texas Instruments, Inc 2016
 *
 * Authors:
 *  Vitaly Andrianov <vitalya@ti.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include "ti-utils.h"

/************************************************************************************/


#define INTERVAL 1000 // 0.1 ms
#define RELOAD	 (0xffffffff - INTERVAL)

#define BUCKETS_MAX 33
#define MAX_INTS	1000000

static bool ready;
static int  cnt;
static u32 min = 0xffffffff;
static u32 max = 0;
static u32 bucket[BUCKETS_MAX];

static void handle_IRQ(unsigned int irqn)
{
	u32 llat, lind;

	if (irqn != TIMER8_IRQ_N)
		return;

	cnt++;

	llat = timer8->tcrr - RELOAD;
	asm volatile (
		"clz %0, %1"
		: "=r"(lind) : "r"(llat):);

	if (!ready) {
		if (min > llat)
			min = llat;
		if (max < llat)
			max = llat;
		bucket[32-lind]++;
		if (cnt >= MAX_INTS)
			ready = true;
	}

	timer8->irqstatus = 0x2;
}

void inmate_main(void)
{
	u32 l;
	delay(10);
	uart_init();
	int	j;

	mmu_on();

	ti_puts("Interrupt benchmark app\n\n\r");

	/* set CROSSBAR_39 to GIC IRQ 134 */
	mmio_write32((void *)0x4a002b44, 39);

	for (j = 0; j < BUCKETS_MAX; j++)
		bucket[j] = 0;

	gic_setup(handle_IRQ);

	ready = false;
	cnt   = 0;

	timer8->tcrr = RELOAD;
	timer8->tldr = RELOAD;
	timer8->irqstatus = 0x2;
	l = timer8->tclr;
	l &= ~0x1c;
	l |= 0x23;
	timer8->tclr = l;

	timer8->irqenable_set = 0x2;
	gic_enable_irq(TIMER8_IRQ_N);

	for(;;) {
		delay(10);
		if (!ready)
			continue;

		ti_puts("Array start\r\n");
		for (j = 0; j < BUCKETS_MAX; j++) {
			if (bucket[j] == 0)
				continue;

			ti_putsui("ind - ", j, false);
			ti_putsui(";cnt - ", bucket[j], true);
		}
		ti_puts("Array end ");
		ti_putsui(" - ", min, false);
		ti_putsui("/", max, true);
		break;
	}
}
