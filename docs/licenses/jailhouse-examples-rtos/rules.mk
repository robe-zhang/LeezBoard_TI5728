# /*
#  * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
#  *
#  *  Redistribution and use in source and binary forms, with or without
#  *  modification, are permitted provided that the following conditions
#  *  are met:
#  *
#  *    Redistributions of source code must retain the above copyright
#  *    notice, this list of conditions and the following disclaimer.
#  *
#  *    Redistributions in binary form must reproduce the above copyright
#  *    notice, this list of conditions and the following disclaimer in the
#  *    documentation and/or other materials provided with the
#  *    distribution.
#  *
#  *    Neither the name of Texas Instruments Incorporated nor the names of
#  *    its contributors may be used to endorse or promote products derived
#  *    from this software without specific prior written permission.
#  *
#  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#  *
#  */

.PHONY: all clean

INC_DIRS = -I$(PDK_INSTALL_PATH)

all:

CROSS_COMPILE = $(TOOLCHAIN_PATH_A15)/bin/arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar
BIN=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump
BINFLAGS=-O binary

GCCOPT = -gdwarf-3 -gstrict-dwarf -Wall -mtune=cortex-a15 -march=armv7-a -marm -mfloat-abi=hard -mfpu=neon

CFLAGS = $(GCCOPT) -c -g2 $(INC_DIRS) -DSOC_AM572x
ASFLAGS=$(GCCOPT) -c $(INC_DIRS)
ARFLAGS=-c -r

LDFLAGS=$(GCCOPT) --entry _reset -static -Wl,-T $(LDS) -Wl,-Map,$(EXE).map 

OBJS = $(patsubst %.c,%.o,$(CSRCS))
OBJS += $(patsubst %.S,%.o,$(ASRCS))

%.bin: %.out
	$(BIN) $(BINFLAGS) $< $@

clean:
	rm -rf *.o *.map *.a *.bin *.out

	


