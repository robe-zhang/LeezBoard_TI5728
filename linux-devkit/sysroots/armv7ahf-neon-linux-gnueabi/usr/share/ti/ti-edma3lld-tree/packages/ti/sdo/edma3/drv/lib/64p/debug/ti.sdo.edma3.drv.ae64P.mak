#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C64P{1,0,8.2,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P.dep
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P.dep: ;
endif

package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P: package/package_ti.sdo.edma3.drv.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.se64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.se64P: package/package_ti.sdo.edma3.drv.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.se64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P.dep
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P.dep: ;
endif

package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P: src/edma3_drv_init.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.se64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.se64P: src/edma3_drv_init.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.se64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P.dep
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P.dep: ;
endif

package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P: src/edma3_drv_basic.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.se64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.se64P: src/edma3_drv_basic.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.se64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P.dep
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P.dep: ;
endif

package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P: src/edma3_drv_adv.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.se64P: | .interfaces
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.se64P: src/edma3_drv_adv.c lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_8_2_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src -fr=./package/lib/lib/64p/debug/ti.sdo.edma3.drv/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.se64P: export C_DIR=
package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

clean,e64P ::
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.se64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.se64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.se64P
	-$(RM) package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.se64P

lib/64p/debug/ti.sdo.edma3.drv.ae64P: package/lib/lib/64p/debug/ti.sdo.edma3.drv/package/package_ti.sdo.edma3.drv.oe64P package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_init.oe64P package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_basic.oe64P package/lib/lib/64p/debug/ti.sdo.edma3.drv/src/edma3_drv_adv.oe64P lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak

clean::
	-$(RM) lib/64p/debug/ti.sdo.edma3.drv.ae64P.mak
