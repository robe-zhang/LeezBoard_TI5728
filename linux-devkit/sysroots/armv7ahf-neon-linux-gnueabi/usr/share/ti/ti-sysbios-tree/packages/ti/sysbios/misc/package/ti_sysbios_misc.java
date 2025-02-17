/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_sysbios_misc
{
    static final String VERS = "@(#) xdc-D20\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "ti.sysbios.interfaces");
        Global.callFxn("loadPackage", xdcO, "ti.sysbios.family");
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "xdc.runtime");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.sysbios.misc.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sysbios.misc", new Value.Obj("ti.sysbios.misc", pkgP));
    }

    void Stats$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sysbios.misc.Stats.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sysbios.misc.Stats", new Value.Obj("ti.sysbios.misc.Stats", po));
        pkgV.bind("Stats", vo);
        // decls 
        spo = (Proto.Obj)om.bind("ti.sysbios.misc.Stats$$Instance_State", new Proto.Obj());
        om.bind("ti.sysbios.misc.Stats.Instance_State", new Proto.Str(spo, false));
        // insts 
        Object insP = om.bind("ti.sysbios.misc.Stats.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.sysbios.misc.Stats$$Object", new Proto.Obj());
        om.bind("ti.sysbios.misc.Stats.Object", new Proto.Str(po, false));
        po = (Proto.Obj)om.bind("ti.sysbios.misc.Stats$$Params", new Proto.Obj());
        om.bind("ti.sysbios.misc.Stats.Params", new Proto.Str(po, false));
        om.bind("ti.sysbios.misc.Stats.Handle", insP);
        if (isROV) {
            om.bind("ti.sysbios.misc.Stats.Object", om.findStrict("ti.sysbios.misc.Stats.Instance_State", "ti.sysbios.misc"));
        }//isROV
    }

    void Stats$$CONSTS()
    {
        // module Stats
    }

    void Stats$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        if (isCFG) {
            sb = new StringBuilder();
            sb.append("ti$sysbios$misc$Stats$$__initObject = function( inst ) {\n");
                sb.append("if (!this.$used) {\n");
                    sb.append("throw new Error(\"Function ti.sysbios.misc.Stats.create() called before xdc.useModule('ti.sysbios.misc.Stats')\");\n");
                sb.append("}\n");
                sb.append("var name = xdc.module('xdc.runtime.Text').defineRopeCord(inst.instance.name);\n");
                sb.append("inst.$object.$$bind('__name', name);\n");
                sb.append("this.instance$static$init.$fxn.apply(inst, [inst.$object, inst, inst.$module]);\n");
                sb.append("inst.$seal();\n");
            sb.append("};\n");
            Global.eval(sb.toString());
            fxn = (Proto.Fxn)om.bind("ti.sysbios.misc.Stats$$create", new Proto.Fxn(om.findStrict("ti.sysbios.misc.Stats.Module", "ti.sysbios.misc"), om.findStrict("ti.sysbios.misc.Stats.Instance", "ti.sysbios.misc"), 1, 0, false));
                        fxn.addArg(0, "__params", (Proto)om.findStrict("ti.sysbios.misc.Stats.Params", "ti.sysbios.misc"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sysbios$misc$Stats$$create = function( __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sysbios.misc.Stats'];\n");
                sb.append("var __inst = xdc.om['ti.sysbios.misc.Stats.Instance'].$$make();\n");
                sb.append("__inst.$$bind('$package', xdc.om['ti.sysbios.misc']);\n");
                sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
                sb.append("__inst.$$bind('$category', 'Instance');\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$instances.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', new xdc.om['ti.sysbios.misc.Stats'].Instance_State);\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("var save = xdc.om.$curpkg;\n");
                sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
                sb.append("__mod.instance$meta$init.$fxn.apply(__inst, []);\n");
                sb.append("xdc.om.$$bind('$curpkg', save);\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sysbios.misc.Stats'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return __inst;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
        if (isCFG) {
            fxn = (Proto.Fxn)om.bind("ti.sysbios.misc.Stats$$construct", new Proto.Fxn(om.findStrict("ti.sysbios.misc.Stats.Module", "ti.sysbios.misc"), null, 2, 0, false));
                        fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.sysbios.misc.Stats$$Object", "ti.sysbios.misc"), null);
                        fxn.addArg(1, "__params", (Proto)om.findStrict("ti.sysbios.misc.Stats.Params", "ti.sysbios.misc"), Global.newObject());
            sb = new StringBuilder();
            sb.append("ti$sysbios$misc$Stats$$construct = function( __obj, __params ) {\n");
                sb.append("var __mod = xdc.om['ti.sysbios.misc.Stats'];\n");
                sb.append("var __inst = __obj;\n");
                sb.append("__inst.$$bind('$args', {});\n");
                sb.append("__inst.$$bind('$module', __mod);\n");
                sb.append("__mod.$objects.$add(__inst);\n");
                sb.append("__inst.$$bind('$object', xdc.om['ti.sysbios.misc.Stats'].Instance_State.$$make(__inst.$$parent, __inst.$name));\n");
                sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
                sb.append("__inst.$$bless();\n");
                sb.append("if (xdc.om.$$phase >= 5) xdc.om['ti.sysbios.misc.Stats'].__initObject(__inst);\n");
                sb.append("__inst.$$bind('$$phase', xdc.om.$$phase);\n");
                sb.append("return null;\n");
            sb.append("}\n");
            Global.eval(sb.toString());
        }//isCFG
    }

    void Stats$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Stats$$SIZES()
    {
        Proto.Str so;
        Object fxn;

        so = (Proto.Str)om.findStrict("ti.sysbios.misc.Stats.Instance_State", "ti.sysbios.misc");
        sizes.clear();
        sizes.add(Global.newArray("prev", "TInt32"));
        sizes.add(Global.newArray("count", "TInt32"));
        sizes.add(Global.newArray("total", "TInt32"));
        sizes.add(Global.newArray("max", "TInt32"));
        so.bind("$$sizes", Global.newArray(sizes.toArray()));
        fxn = Global.eval("function() { return $$sizeof(xdc.om['ti.sysbios.misc.Stats.Instance_State']); }");
        so.bind("$sizeof", fxn);
        fxn = Global.eval("function() { return $$alignof(xdc.om['ti.sysbios.misc.Stats.Instance_State']); }");
        so.bind("$alignof", fxn);
        fxn = Global.eval("function(fld) { return $$offsetof(xdc.om['ti.sysbios.misc.Stats.Instance_State'], fld); }");
        so.bind("$offsetof", fxn);
    }

    void Stats$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sysbios/misc/Stats.xs");
        om.bind("ti.sysbios.misc.Stats$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats.Module", "ti.sysbios.misc");
        po.init("ti.sysbios.misc.Stats.Module", om.findStrict("xdc.runtime.IModule.Module", "ti.sysbios.misc"));
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
        }//isCFG
        if (isCFG) {
                        po.addFxn("create", (Proto.Fxn)om.findStrict("ti.sysbios.misc.Stats$$create", "ti.sysbios.misc"), Global.get("ti$sysbios$misc$Stats$$create"));
                        po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.sysbios.misc.Stats$$construct", "ti.sysbios.misc"), Global.get("ti$sysbios$misc$Stats$$construct"));
        }//isCFG
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sysbios.misc.Stats$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sysbios.misc.Stats$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.sysbios.misc.Stats$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$static$init");
        if (fxn != null) om.bind("ti.sysbios.misc.Stats$$module$static$init", true);
        if (fxn != null) po.addFxn("module$static$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sysbios.misc.Stats$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$static$init");
        if (fxn != null) om.bind("ti.sysbios.misc.Stats$$instance$static$init", true);
        if (fxn != null) po.addFxn("instance$static$init", $$T_Met, fxn);
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats.Instance", "ti.sysbios.misc");
        po.init("ti.sysbios.misc.Stats.Instance", $$Instance);
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("comment", $$T_Str, "<add comments here>", "wh");
            po.addFld("unitType", $$T_Str, "Not time based", "wh");
            po.addFld("operation", $$T_Str, "Nothing", "wh");
            po.addFld("numA", Proto.Elm.newCNum("(xdc_Int32)"), 1L, "wh");
            po.addFld("numB", Proto.Elm.newCNum("(xdc_Int32)"), 0L, "wh");
            po.addFld("numC", Proto.Elm.newCNum("(xdc_Int32)"), 1L, "wh");
            po.addFld("previousVal", Proto.Elm.newCNum("(xdc_Int32)"), 0L, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sysbios.misc"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats$$Params", "ti.sysbios.misc");
        po.init("ti.sysbios.misc.Stats.Params", $$Params);
                po.addFld("$hostonly", $$T_Num, 0, "r");
        if (isCFG) {
            po.addFld("comment", $$T_Str, "<add comments here>", "wh");
            po.addFld("unitType", $$T_Str, "Not time based", "wh");
            po.addFld("operation", $$T_Str, "Nothing", "wh");
            po.addFld("numA", Proto.Elm.newCNum("(xdc_Int32)"), 1L, "wh");
            po.addFld("numB", Proto.Elm.newCNum("(xdc_Int32)"), 0L, "wh");
            po.addFld("numC", Proto.Elm.newCNum("(xdc_Int32)"), 1L, "wh");
            po.addFld("previousVal", Proto.Elm.newCNum("(xdc_Int32)"), 0L, "w");
                        po.addFld("instance", (Proto)om.findStrict("xdc.runtime.IInstance.Params", "ti.sysbios.misc"), $$UNDEF, "w");
        }//isCFG
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats$$Object", "ti.sysbios.misc");
        po.init("ti.sysbios.misc.Stats.Object", om.findStrict("ti.sysbios.misc.Stats.Instance", "ti.sysbios.misc"));
        // struct Stats.Instance_State
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats$$Instance_State", "ti.sysbios.misc");
        po.init("ti.sysbios.misc.Stats.Instance_State", null);
                po.addFld("$hostonly", $$T_Num, 0, "r");
                po.addFld("prev", Proto.Elm.newCNum("(xdc_Int32)"), $$UNDEF, "w");
                po.addFld("count", Proto.Elm.newCNum("(xdc_Int32)"), $$UNDEF, "w");
                po.addFld("total", Proto.Elm.newCNum("(xdc_Int32)"), $$UNDEF, "w");
                po.addFld("max", Proto.Elm.newCNum("(xdc_Int32)"), $$UNDEF, "w");
    }

    void Stats$$ROV()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sysbios.misc.Stats", "ti.sysbios.misc");
        vo.bind("Instance_State$fetchDesc", Global.newObject("type", "ti.sysbios.misc.Stats.Instance_State", "isScalar", false));
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats$$Instance_State", "ti.sysbios.misc");
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sysbios.misc.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sysbios.misc"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sysbios/misc/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.sysbios.misc"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.sysbios.misc"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.sysbios.misc"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.sysbios.misc"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.sysbios.misc"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.sysbios.misc"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.sysbios.misc", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sysbios.misc");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sysbios.misc.");
        pkgV.bind("$vers", Global.newArray(2, 0, 0, 0));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        imports.add(Global.newArray("ti.sysbios.interfaces", Global.newArray()));
        imports.add(Global.newArray("ti.sysbios.family", Global.newArray()));
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sysbios.misc'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("if ('ti.sysbios.misc$$stat$base' in xdc.om) {\n");
            sb.append("pkg.packageBase = xdc.om['ti.sysbios.misc$$stat$base'];\n");
            sb.append("pkg.packageRepository = xdc.om['ti.sysbios.misc$$stat$root'];\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae28FP',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.a28L',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.a28FP',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae430X',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ar430XS',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae64P',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae674',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae66',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae66e',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aearp32',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aearp32F',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae9',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aea8fnv',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aer5f',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aer4f',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aer4ft',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aem3',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aem4',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aem4f',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.am3g',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.am4g',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.am4fg',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aa8fg',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aa9fg',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aa15fg',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.aa53fg',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.arm3',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.arm4',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.arm4f',\n");
            sb.append("'lib/sysbios/debug/ti.sysbios.misc.ae71',\n");
            sb.append("'lib/smpbios/debug/ti.sysbios.misc.aem3',\n");
            sb.append("'lib/smpbios/debug/ti.sysbios.misc.aem4',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae28FP', {target: 'ti.targets.elf.C28_float', suffix: 'e28FP'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.a28L', {target: 'ti.targets.C28_large', suffix: '28L'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.a28FP', {target: 'ti.targets.C28_float', suffix: '28FP'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae430X', {target: 'ti.targets.msp430.elf.MSP430X', suffix: 'e430X'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ar430XS', {target: 'iar.targets.msp430.MSP430X_small', suffix: 'r430XS'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae64P', {target: 'ti.targets.elf.C64P', suffix: 'e64P'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae66', {target: 'ti.targets.elf.C66', suffix: 'e66'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae66e', {target: 'ti.targets.elf.C66_big_endian', suffix: 'e66e'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aearp32', {target: 'ti.targets.arp32.elf.ARP32', suffix: 'earp32'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aearp32F', {target: 'ti.targets.arp32.elf.ARP32_far', suffix: 'earp32F'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae9', {target: 'ti.targets.arm.elf.Arm9', suffix: 'e9'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aea8fnv', {target: 'ti.targets.arm.elf.A8Fnv', suffix: 'ea8fnv'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aer5f', {target: 'ti.targets.arm.elf.R5F', suffix: 'er5f'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aer4f', {target: 'ti.targets.arm.elf.R4F', suffix: 'er4f'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aer4ft', {target: 'ti.targets.arm.elf.R4Ft', suffix: 'er4ft'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aem4', {target: 'ti.targets.arm.elf.M4', suffix: 'em4'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aem4f', {target: 'ti.targets.arm.elf.M4F', suffix: 'em4f'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.am4g', {target: 'gnu.targets.arm.M4', suffix: 'm4g'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.am4fg', {target: 'gnu.targets.arm.M4F', suffix: 'm4fg'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aa8fg', {target: 'gnu.targets.arm.A8F', suffix: 'a8fg'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aa9fg', {target: 'gnu.targets.arm.A9F', suffix: 'a9fg'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aa15fg', {target: 'gnu.targets.arm.A15F', suffix: 'a15fg'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.aa53fg', {target: 'gnu.targets.arm.A53F', suffix: 'a53fg'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.arm4', {target: 'iar.targets.arm.M4', suffix: 'rm4'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.arm4f', {target: 'iar.targets.arm.M4F', suffix: 'rm4f'}],\n");
            sb.append("['lib/sysbios/debug/ti.sysbios.misc.ae71', {target: 'ti.targets.elf.nda.C71', suffix: 'e71'}],\n");
            sb.append("['lib/smpbios/debug/ti.sysbios.misc.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/smpbios/debug/ti.sysbios.misc.aem4', {target: 'ti.targets.arm.elf.M4', suffix: 'em4'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Stats$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.sysbios.misc.Stats", "ti.sysbios.misc");
        po = (Proto.Obj)om.findStrict("ti.sysbios.misc.Stats.Module", "ti.sysbios.misc");
        vo.init2(po, "ti.sysbios.misc.Stats", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sysbios.misc.Stats$$capsule", "ti.sysbios.misc"));
        vo.bind("Instance", om.findStrict("ti.sysbios.misc.Stats.Instance", "ti.sysbios.misc"));
        vo.bind("Params", om.findStrict("ti.sysbios.misc.Stats.Params", "ti.sysbios.misc"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.sysbios.misc.Stats.Params", "ti.sysbios.misc")).newInstance());
        vo.bind("Handle", om.findStrict("ti.sysbios.misc.Stats.Handle", "ti.sysbios.misc"));
        vo.bind("$package", om.findStrict("ti.sysbios.misc", "ti.sysbios.misc"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        mcfgs.add("Module__diagsEnabled");
        icfgs.add("Module__diagsEnabled");
        mcfgs.add("Module__diagsIncluded");
        icfgs.add("Module__diagsIncluded");
        mcfgs.add("Module__diagsMask");
        icfgs.add("Module__diagsMask");
        mcfgs.add("Module__gateObj");
        icfgs.add("Module__gateObj");
        mcfgs.add("Module__gatePrms");
        icfgs.add("Module__gatePrms");
        mcfgs.add("Module__id");
        icfgs.add("Module__id");
        mcfgs.add("Module__loggerDefined");
        icfgs.add("Module__loggerDefined");
        mcfgs.add("Module__loggerObj");
        icfgs.add("Module__loggerObj");
        mcfgs.add("Module__loggerFxn0");
        icfgs.add("Module__loggerFxn0");
        mcfgs.add("Module__loggerFxn1");
        icfgs.add("Module__loggerFxn1");
        mcfgs.add("Module__loggerFxn2");
        icfgs.add("Module__loggerFxn2");
        mcfgs.add("Module__loggerFxn4");
        icfgs.add("Module__loggerFxn4");
        mcfgs.add("Module__loggerFxn8");
        icfgs.add("Module__loggerFxn8");
        mcfgs.add("Object__count");
        icfgs.add("Object__count");
        mcfgs.add("Object__heap");
        icfgs.add("Object__heap");
        mcfgs.add("Object__sizeof");
        icfgs.add("Object__sizeof");
        mcfgs.add("Object__table");
        icfgs.add("Object__table");
        vo.bind("Instance_State", om.findStrict("ti.sysbios.misc.Stats.Instance_State", "ti.sysbios.misc"));
        tdefs.add(om.findStrict("ti.sysbios.misc.Stats.Instance_State", "ti.sysbios.misc"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.runtime");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sysbios.misc")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        if (isCFG) {
            Proto.Str ps = (Proto.Str)vo.find("Module_State");
            if (ps != null) vo.bind("$object", ps.newInstance());
            vo.bind("$$meta_iobj", om.has("ti.sysbios.misc.Stats$$instance$static$init", null) ? 1 : 0);
            vo.bind("__initObject", Global.get("ti$sysbios$misc$Stats$$__initObject"));
        }//isCFG
        vo.bind("$$fxntab", Global.newArray("ti_sysbios_misc_Stats_Handle__label__E", "ti_sysbios_misc_Stats_Module__startupDone__E", "ti_sysbios_misc_Stats_Object__create__E", "ti_sysbios_misc_Stats_Object__delete__E", "ti_sysbios_misc_Stats_Object__get__E", "ti_sysbios_misc_Stats_Object__first__E", "ti_sysbios_misc_Stats_Object__next__E", "ti_sysbios_misc_Stats_Params__init__E", "ti_sysbios_misc_Stats_add__E", "ti_sysbios_misc_Stats_delta__E", "ti_sysbios_misc_Stats_set__E", "ti_sysbios_misc_Stats_reset__E", "ti_sysbios_misc_Stats_getPrev__E", "ti_sysbios_misc_Stats_getCount__E", "ti_sysbios_misc_Stats_getTotal__E", "ti_sysbios_misc_Stats_getMax__E", "ti_sysbios_misc_Stats_print__E"));
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.setElem("", true);
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.sysbios.misc.Stats.Object", "ti.sysbios.misc"));
        vo.bind("MODULE_STARTUP$", 0);
        vo.bind("PROXY$", 0);
        loggables.clear();
        vo.bind("$$loggables", loggables.toArray());
        pkgV.bind("Stats", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Stats");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
            Object srcP = ((XScriptO)om.findStrict("xdc.runtime.IInstance", "ti.sysbios.misc")).findStrict("PARAMS", "ti.sysbios.misc");
            Scriptable dstP;

            dstP = (Scriptable)((XScriptO)om.findStrict("ti.sysbios.misc.Stats", "ti.sysbios.misc")).findStrict("PARAMS", "ti.sysbios.misc");
            Global.put(dstP, "instance", srcP);
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sysbios.misc.Stats", "ti.sysbios.misc"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sysbios.misc.Stats")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sysbios.misc")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        Stats$$OBJECTS();
        Stats$$CONSTS();
        Stats$$CREATES();
        Stats$$FUNCTIONS();
        Stats$$SIZES();
        Stats$$TYPES();
        if (isROV) {
            Stats$$ROV();
        }//isROV
        $$SINGLETONS();
        Stats$$SINGLETONS();
        $$INITIALIZATION();
    }
}
