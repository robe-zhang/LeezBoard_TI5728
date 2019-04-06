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

void inmate_main(void)
{
	void (*entry)(void) = (void (*)(void))0x80000000;
	entry();
}

