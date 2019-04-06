#-------------------------------------------------
#
# Project created by QtCreator 2017-07-28T07:51:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = evse_hmi
TEMPLATE = app


SOURCES += main.cpp\
        evse_hmi.cpp

HEADERS  += evse_hmi.h

FORMS    += evse_hmi.ui

target.path += /home/root
INSTALLS += target

RESOURCES += \
    car_image.qrc \
    button.qrc
