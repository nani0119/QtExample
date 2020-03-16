include(../../../build.pri)

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../../Charts
TARGET          = $$qtLibraryTarget(echoplugin)
DESTDIR         = ../../plugins



HEADERS += \
    echoplugin.h

SOURCES += \
    echoplugin.cpp
