#
# Jailhouse, a Linux-based partitioning hypervisor
#
# Copyright (c) ARM Limited, 2014
# Copyright (c) Texas Instruments, Inc. 2017
#
# Authors:
#  Jean-Philippe Brucker <jean-philippe.brucker@arm.com>
#  Vitaly Andrianov <vitalya@ti.com>
#
# This work is licensed under the terms of the GNU GPL, version 2.  See
# the COPYING file in the top-level directory.
#

include $(INMATES_LIB)/Makefile.lib

INMATES := ti-app.bin rtos-loader.bin ti-interrupts-bm.bin

ti-app-y	:= ti-app.o ti-utils.o
rtos-loader-y	:= rtos-loader.o
ti-interrupts-bm-y := ti-interrupts-bm.o ti-utils.o

$(eval $(call DECLARE_TARGETS,$(INMATES)))
