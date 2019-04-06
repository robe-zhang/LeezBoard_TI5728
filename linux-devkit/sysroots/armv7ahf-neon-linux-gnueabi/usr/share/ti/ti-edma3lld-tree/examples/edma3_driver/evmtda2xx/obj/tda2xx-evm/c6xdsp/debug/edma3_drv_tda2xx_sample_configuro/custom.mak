## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.oe66

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.xdl
	$(SED) 's"^\"\(package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66cfg.cmd\)\"$""\"/oe/bld/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.05.30C-r0.1/git/examples/edma3_driver/evmtda2xx/obj/tda2xx-evm/c6xdsp/debug/edma3_drv_tda2xx_sample_configuro/\1\""' package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.xdl > $@
	-$(SETDATE) -r:max package/cfg/edma3_drv_bios6_tda2xx_st_sample_pe66.h compiler.opt compiler.opt.defs
