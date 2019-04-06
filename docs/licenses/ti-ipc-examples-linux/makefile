#
#   Copyright (c) 2016 Texas Instruments Incorporated - http://www.ti.com
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#   *  Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   *  Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
#   *  Neither the name of Texas Instruments Incorporated nor the names of
#      its contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#
#  ======== makefile ========
#
export XDC_INSTALL_DIR

.examples: $(IPCTOOLS)/packages/ti/ipc/utils/genbundle/package
	@echo "#"
	@echo "# (makefile) Making $@ ..."
	@$(MAKE) -C examples/templates release

$(IPCTOOLS)/packages/ti/ipc/utils/genbundle/package:
	$(XDC_INSTALL_DIR)/xdc XDCPATH="$(XDC_INSTALL_DIR)/packages;$(IPCTOOLS)/packages" release -Pr $(IPCTOOLS)/packages

.clean:
	@$(MAKE) -C examples/templates clobber

extract:
	@$(MAKE) -C examples extract \
	PLATFORM=$(PLATFORM) \
	HOSTOS=$(HOSTOS)

clobber:
	@$(MAKE) -C examples clobber

build:
	@$(MAKE) -C examples all \
	BIOS_INSTALL_DIR=$(BIOS_INSTALL_DIR) \
	IPC_INSTALL_DIR=$(IPC_INSTALL_DIR) \
	gnu.targets.arm.A15=$(gnu.targets.arm.A15) \
	gnu.targets.arm.A15F=$(gnu.targets.arm.A15F) \
	ti.targets.elf.C66=$(ti.targets.elf.C66) \
	ti.targets.arm.elf.M3=$(ti.targets.arm.elf.M3) \
	ti.targets.arm.elf.M4=$(ti.targets.arm.elf.M4) \
	ti.targets.arm.elf.M4F=$(ti.targets.arm.elf.M4F) \
	ti.targets.arp32.elf.ARP32_far=$(ti.targets.arp32.elf.ARP32_far) \
	PLATFORM=$(PLATFORM)

clean:
	@$(MAKE) -C examples clean \
	PLATFORM=$(PLATFORM) \
	HOSTOS=$(HOSTOS)


