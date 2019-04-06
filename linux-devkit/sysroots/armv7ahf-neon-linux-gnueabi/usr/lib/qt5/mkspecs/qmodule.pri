CONFIG +=  cross_compile compile_examples silent qpa largefile use_gold_linker neon pcre
QT_BUILD_PARTS +=  examples libs tools
QT_NO_DEFINES =  ALSA CUPS EGL_X11 GLIB HARFBUZZ ICONV IMAGEFORMAT_JPEG LIBPROXY MITSHM OPENVG SESSIONMANAGER SHAPE TSLIB XCURSOR XFIXES XKB XRANDR XRENDER XSYNC ZLIB
QT_QCONFIG_PATH = 
host_build {
    QT_CPU_FEATURES.arm =  neon
} else {
    QT_CPU_FEATURES.arm =  neon
}
QT_COORD_TYPE = double
QT_LFLAGS_ODBC   = -lodbc
OE_QMAKE_AR = arm-linux-gnueabihf-ar
OE_QMAKE_CC = arm-linux-gnueabihf-gcc  -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard --sysroot=$$[QT_SYSROOT]
OE_QMAKE_CFLAGS =  -isystem/home/gtbldadm/tools/linaro-2016.11/arm-linux-gnueabihf/include  -O2 -pipe -g -feliminate-unused-debug-types -fdebug-prefix-map=/oe/bld/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/armv7ahf-neon-linux-gnueabi/qtbase/5.7.1+gitAUTOINC+a55f36211e-r0.arago12.tisdk5=/usr/src/debug/qtbase/5.7.1+gitAUTOINC+a55f36211e-r0.arago12.tisdk5 -fdebug-prefix-map=/oe/bld/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux= -fdebug-prefix-map=$$[QT_SYSROOT]= 
OE_QMAKE_COMPILER = arm-linux-gnueabihf-gcc  -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard --sysroot=$$[QT_SYSROOT]
OE_QMAKE_CXX = arm-linux-gnueabihf-g++  -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard --sysroot=$$[QT_SYSROOT]
OE_QMAKE_CXXFLAGS =  -isystem/home/gtbldadm/tools/linaro-2016.11/arm-linux-gnueabihf/include  -O2 -pipe -g -feliminate-unused-debug-types -fdebug-prefix-map=/oe/bld/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/armv7ahf-neon-linux-gnueabi/qtbase/5.7.1+gitAUTOINC+a55f36211e-r0.arago12.tisdk5=/usr/src/debug/qtbase/5.7.1+gitAUTOINC+a55f36211e-r0.arago12.tisdk5 -fdebug-prefix-map=/oe/bld/build-CORTEX_1/arago-tmp-external-linaro-toolchain/sysroots/x86_64-linux= -fdebug-prefix-map=$$[QT_SYSROOT]= 
OE_QMAKE_LDFLAGS =  -L/home/gtbldadm/tools/linaro-2016.11/arm-linux-gnueabihf/lib -Wl,-rpath-link,/home/gtbldadm/tools/linaro-2016.11/arm-linux-gnueabihf/lib -Wl,-O1 -Wl,--hash-style=gnu
OE_QMAKE_LINK = arm-linux-gnueabihf-g++  -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard --sysroot=$$[QT_SYSROOT]
OE_QMAKE_STRIP = echo
styles += mac fusion windows
DEFINES += QT_NO_MTDEV
QT_LIBS_DBUS = -ldbus-1
QT_CFLAGS_DBUS = -I$$[QT_SYSROOT]/usr/include/dbus-1.0 -I$$[QT_SYSROOT]/usr/lib/dbus-1.0/include
QT_HOST_CFLAGS_DBUS = -I$$[QT_HOST_PREFIX]/include/dbus-1.0 -I$$[QT_HOST_PREFIX]/lib/dbus-1.0/include
QT_CFLAGS_PULSEAUDIO = -D_REENTRANT -I$$[QT_SYSROOT]/usr/include/glib-2.0 -I$$[QT_SYSROOT]/usr/lib/glib-2.0/include
QT_LIBS_PULSEAUDIO = -lpulse-mainloop-glib -lpulse -lglib-2.0
QMAKE_INCDIR_OPENGL_ES2 = 
QMAKE_LIBDIR_OPENGL_ES2 = 
QMAKE_LIBS_OPENGL_ES2 =  "-lGLESv2" "-lsrv_um"
QMAKE_CFLAGS_OPENGL_ES2 = 
QMAKE_CFLAGS_FONTCONFIG = -I$$[QT_SYSROOT]/usr/include/freetype2
QMAKE_LIBS_FONTCONFIG = -lfontconfig -lfreetype
QMAKE_INCDIR_LIBUDEV = 
QMAKE_LIBS_LIBUDEV = -ludev
DEFINES += QT_NO_TSLIB
DEFINES += QT_NO_LIBINPUT
QMAKE_INCDIR_EGL = 
QMAKE_LIBS_EGL = -lEGL -lIMGegl -ldrm_omap -lsrv_um
QMAKE_CFLAGS_EGL = 
QMAKE_INCDIR_EGL = 
QMAKE_LIBS_EGL = -lEGL -lIMGegl -ldrm_omap -lsrv_um
QMAKE_CFLAGS_EGL = 
sql-drivers = 
sql-plugins = 
