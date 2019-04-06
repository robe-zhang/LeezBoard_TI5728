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

#define INTERVAL 1000 // 10 ms
#define RELOAD	 (0xffffffff - INTERVAL)

#define AAA_SHIFT 13
#define AAA_SIZE (1 << AAA_SHIFT)

struct aaa_t {
	int cnt;
	u32 min;
	u32 max;
	u32 lat[AAA_SIZE];
};

static struct aaa_t aaa[2];
static int cur_a = 0;
static bool ready;

static void aaa_init(struct aaa_t *a)
{
	memset(a, 0, sizeof(struct aaa_t));
	a->min = 0xffffffff;
}

static void aaa_show(struct aaa_t *a)
{
	u32 sum;
	u32 j;

	for (sum = 0, j = 0; j < AAA_SIZE; j++)
		sum += a->lat[j];

	sum >>= AAA_SHIFT;

	ti_putsui("min ", a->min, false);
	ti_putsui("; avr ", sum, false);
	ti_putsui("; max ", a->max, true);

	aaa_init(a);
}

static void handle_IRQ(unsigned int irqn)
{
	struct aaa_t *a;
	u32 latency;

	if (irqn != TIMER8_IRQ_N)
		return;

	latency = timer8->tcrr - RELOAD;
	timer8->irqstatus = 0x2;

	a = &aaa[cur_a];
	if (a->min > latency)
		a->min = latency;
	if (a->max < latency)
		a->max = latency;
	a->lat[a->cnt++] = latency;

	if (a->cnt >= AAA_SIZE) {
		ready = true;
		cur_a = (cur_a + 1) & 1;
		aaa_init(&aaa[cur_a]);
	}
}

void inmate_main(void)
{
	u32 l;
	delay(10);
	uart_init();
	ti_puts("Hey, I'm working !!!!!!!!!!!\n\r");

	/* set CROSSBAR_39 to GIC IRQ 134 */
	mmio_write32((void *)0x4a002b44, 39);

	gic_setup(handle_IRQ);

	aaa_init(&aaa[0]);
	aaa_init(&aaa[1]);
	cur_a = 0;
	ready = false;

	ti_putsui("timer id ", timer8->tidr, true);
	timer8->tcrr = RELOAD;
	timer8->tldr = RELOAD;
	timer8->irqstatus = 0x2;
	l = timer8->tclr;
	l &= ~0x1c;
	l |= 0x23;
	timer8->tclr = l;

	ti_putsui("timer value ", timer8->tcrr, false);
	ti_putsui("; irq status ", timer8->irqstatus, false);
	ti_putsui("; raw ", timer8->irqstatus_raw, true);

	timer8->irqenable_set = 0x2;
	gic_enable_irq(TIMER8_IRQ_N);

	for(;;) {
		delay(10);
		if (!ready)
			continue;

		ready = false;
		aaa_show(&aaa[(cur_a + 1) & 1]);
	}
}
