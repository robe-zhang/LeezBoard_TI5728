#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C66_big_endian{1,0,8.2,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e.dep
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e.dep: ;
endif

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e: package/package_ti.sdo.edma3.rm.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se66e: package/package_ti.sdo.edma3.rm.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e.dep
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e.dep: ;
endif

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e: src/configs/edma3_c6678_cfg.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.se66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.se66e: src/configs/edma3_c6678_cfg.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.se66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e.dep
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e.dep: ;
endif

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e: src/edma3resmgr.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.se66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.se66e: src/edma3resmgr.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.se66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e.dep
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e.dep: ;
endif

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e: src/edma3_rm_gbl_data.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se66e: | .interfaces
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se66e: src/edma3_rm_gbl_data.c lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=eabi -eo.oe66e -ea.se66e  -mi10 -mo -me --mem_model:data=far  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_8_2_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se66e: export C_DIR=
package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/:$(PATH)

clean,e66e ::
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.se66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.se66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.se66e
	-$(RM) package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.se66e

lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e: package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.oe66e package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/configs/edma3_c6678_cfg.oe66e package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3resmgr.oe66e package/lib/lib/c6678-evm/66/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.oe66e lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak

clean::
	-$(RM) lib/c6678-evm/66/release/ti.sdo.edma3.rm.ae66e.mak
