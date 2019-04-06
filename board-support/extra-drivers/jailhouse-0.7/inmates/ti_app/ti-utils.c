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

#if USE_UART9
struct uart_regs *uart = (struct uart_regs *)0x48424000;
#else
struct uart_regs *uart = (struct uart_regs *)0x48020000;
#endif
struct timer_regs *timer8 = (struct timer_regs *)0x48826000;

void uart_init(void)
{
	uart->mdr1 = 7;
	uart->ier = 0;
	uart->mcr = 0x03;
	uart->fcr = 0x7;
	uart->lcr = 0x80;
	uart->rbr = 26;
	uart->ier = 0;
	uart->lcr = 0x03;
	uart->mdr1 = 0;
}

static char dig[] = "0123456789abcdef";
void ti_putbyte(unsigned char b)
{
	ti_putc(dig[(b >> 4) & 0xf]);
	ti_putc(dig[b & 0xf]);
}

void ti_putui(unsigned int ul)
{
	ti_putbyte((ul >> 24) & 0xff);
	ti_putbyte((ul >> 16) & 0xff);
	ti_putbyte((ul >>  8) & 0xff);
	ti_putbyte( ul        & 0xff);
}

void ti_putsui(char *msg, u32 ul, bool crlf)
{
	ti_puts(msg);
	ti_putui(ul);
	if (crlf)
		ti_puts("\n\r");
}

static volatile u32 reg_val;

void delay(u32 val)
{
	int j, k;

	for (j = 0; j < val; j++){
		for (k = 0; k < 0x7fff; k++) {
			reg_val = mmio_read32((void *)0x4a0098f8);
		}
	}
}

/************************************************************************************/
static unsigned long long pgd_table[4] __attribute__((aligned(0x1000)));

void my_v7_inval_tlb(void);
/* Invalidate TLB */
void my_v7_inval_tlb(void)
{
	/* Invalidate entire unified TLB */
	asm volatile ("mcr p15, 0, %0, c8, c7, 0" : : "r" (0));
	/* Invalidate entire data TLB */
	asm volatile ("mcr p15, 0, %0, c8, c6, 0" : : "r" (0));
	/* Invalidate entire instruction TLB */
	asm volatile ("mcr p15, 0, %0, c8, c5, 0" : : "r" (0));
	/* Full system DSB - make sure that the invalidation is complete */
	asm volatile ("mcr p15, 0, %0, c7, c10, 4" : : "r" (0));
	/* Full system ISB - make sure the instruction stream sees it */
	asm volatile ("mcr p15, 0, %0, c7, c5, 4" : : "r" (0));
}

static void set_mair(u32 mair0, u32 mair1)
{
	asm (
	     "mov	r10, %0		\n"
	     "mov	r11, %1		\n"
	     "mcr	p15, 0, r10, c10, c2, 0\n"
	     "mcr	p15, 0, r11, c10, c2, 1\n"
	     :: "r"(mair0), "r"(mair1): "r10", "r11", "cc"
	    );
}

static unsigned long enable_mmu(void *ttbr0)
{
	unsigned long ret; 
	asm (
		"stmfd	r13!, {r10, r11}        \n"
		/* set ttbr0			*/
		"mov	r10, %1	                \n"
		"mov	r11, #0	                \n"
		"mcrr	p15, 0, r10, r11, c2    \n"
		/* ttbcr = 0x80000000		*/
		"mov	r10, #0 \n"
		"orr	r10, r10, #(1 << 31)    \n"
		"mcr	p15, 0, r10, c2, c0, 2   \n"
		/* save current SCTLR value	*/
		"mrc	p15, #0, r10, c1, c0, #0\n"
		"mov	%0, r10                 \n"
		/* disable cache		*/
		"bic	r10, r10,#(1 << 12)	\n"
		"bic	r10, r10,#(1 <<  2)	\n"
		"mcr	p15, #0, r10, c1, c0, #0\n"
		"isb				\n"
		"dsb				\n"
		"bl	invalidate_dcache_all   \n"
		"bl	my_v7_inval_tlb		\n"
		/* enable mmu			*/
		"mrc	p15, #0, r10, c1, c0, #0\n"
		"orr	r10, r10,#1		\n"
		"mcr	p15, #0, r10, c1, c0, #0\n"
		"orr	r10, r10,#(1 << 12)	\n"
		"orr	r10, r10,#(1 <<  2)	\n"
		"mcr	p15, #0, r10, c1, c0, #0\n"
		"ldmfd	r13!, {r10, r11} \n"
		: "=r" (ret) : "r" (ttbr0) : "r10", "r11", "cc"
	);

	return ret;
}

static void pgd_table_init(void)
{
	/*
	 * we create identical mapping for the whole 4GB address range
	 * this table maps 0x0-0xffffffff VA to aliased PA range
	 * 0x0_0000_0000 - 0x0_ffff_ffff;
	 */

	pgd_table[0] = 0x0000000000000709ULL; // cached memory
	pgd_table[1] = 0x0000000040000705ULL; // device memory
	pgd_table[2] = 0x0000000080000709ULL; // cached memory
	pgd_table[3] = 0x00000000c0000709ULL; // cached memory

}

void mmu_on(void)
{
	set_mair(0x00ff0444, 0x00000000);
	pgd_table_init();
	enable_mmu(pgd_table);
}
