#-------------------------------------------------
#
# Project created by QtCreator 2014-01-15T08:40:35
#
#-------------------------------------------------

QT       += core gui widgets

lessThan(QT_MAJOR_VERSION, 4): QT += threads

TARGET = dual_camera
TEMPLATE = app
PLATFORM = am57xx-evm

LIBS += -ljpeg -ldrm_omap -ldrm -lticmem

INCLUDEPATH += $(SDK_PATH_TARGET)/usr/include/libdrm $(SDK_PATH_TARGET)/usr/include/omap

SOURCES += main.cpp mainwindow.cpp jpeg.c loopback.c cmem_buf.c
HEADERS  += mainwindow.h  jpeg.h  loopback.h cmem_buf.h
FORMS    += mainwindow.ui
