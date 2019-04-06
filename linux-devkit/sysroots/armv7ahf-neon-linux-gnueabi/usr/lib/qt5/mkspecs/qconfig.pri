#configuration
CONFIG +=  cross_compile shared qpa release qt_no_framework
host_build {
    QT_ARCH = arm
    QT_TARGET_ARCH = arm
} else {
    QT_ARCH = arm
}
QT_CONFIG +=  minimal-config small-config medium-config large-config full-config fontconfig libudev evdev gbm linuxfb kms c++11 c++14 c++1z accessibility egl eglfs eglfs_gbm opengl opengles2 shared qpa reduce_exports clock-gettime clock-monotonic posix_fallocate mremap getaddrinfo ipv6ifname getifaddrs inotify eventfd threadsafe-cloexec poll_ppoll system-jpeg system-png png doubleconversion system-freetype no-harfbuzz system-zlib dbus dbus-linked openssl pulseaudio icu concurrent audio-backend release

#versioning
QT_VERSION = 5.7.1
QT_MAJOR_VERSION = 5
QT_MINOR_VERSION = 7
QT_PATCH_VERSION = 1

#namespaces
QT_LIBINFIX = 
QT_NAMESPACE = 

QT_EDITION = OpenSource

# pkgconfig
PKG_CONFIG_SYSROOT_DIR = $$[QT_SYSROOT]
PKG_CONFIG_LIBDIR = $$[QT_SYSROOT]/usr/lib/pkgconfig

QT_COMPILER_STDCXX = 201402
QT_GCC_MAJOR_VERSION = 6
QT_GCC_MINOR_VERSION = 2
QT_GCC_PATCH_VERSION = 1
