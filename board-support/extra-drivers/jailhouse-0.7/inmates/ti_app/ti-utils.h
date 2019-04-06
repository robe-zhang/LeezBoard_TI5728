/*
 * Copyright (c) Texas Instruments, Inc 2016
 *
 * Authors:
 *  Vitaly Andrianov <vitalya@ti.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <inmate.h>
#include <stdarg.h>

#define TIMER8_IRQ_N (134 + 32)

struct timer_regs {
	volatile u32	tidr;
	u32		res1[3];
	volatile u32	tiocp_cfg;
	u32		res2[3];
	volatile u32	irq_eoi;
	volatile u32	irqstatus_raw;
	volatile u32	irqstatus;
	volatile u32	irqenable_set;
	volatile u32	irqenable_clr;
	volatile u32	irqwakeen;
	volatile u32	tclr;
	volatile u32	tcrr;
	volatile u32	tldr;
	volatile u32	ttgr;
	volatile u32	twps;
	volatile u32	tmap;
	volatile u32	tcar1;
	volatile u32	tsicr;
	volatile u32	tcar2;
};


struct uart_regs {
	volatile u32 rbr;		/* 0 */
	volatile u32 ier;		/* 1 */
	volatile u32 fcr;		/* 2 */
	volatile u32 lcr;		/* 3 */
	volatile u32 mcr;		/* 4 */
	volatile u32 lsr;		/* 5 */
	volatile u32 msr;		/* 6 */
	volatile u32 spr;		/* 7 */
	volatile u32 mdr1;		/* 8 */
};

extern struct uart_regs *uart;
extern struct timer_regs *timer8;

void uart_init(void);

inline void ti_putc(unsigned char c)
{
	while((uart->lsr & 0x20) == 0);
	uart->rbr = c;
}

inline void ti_puts(char *str)
{
	for (; *str != '\0'; str++ )
		ti_putc(*str);
}

void ti_putbyte(unsigned char b);
void ti_putui(unsigned int ul);
void ti_putsui(char *msg, u32 ul, bool crlf);
void delay(u32 val);
void mmu_on(void);

