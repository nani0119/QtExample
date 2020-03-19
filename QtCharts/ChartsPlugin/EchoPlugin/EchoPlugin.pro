include(../../../build.pri)

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets charts
INCLUDEPATH    += ../../Charts
TARGET          = $$qtLibraryTarget(echoplugin)
DESTDIR         = ../../plugins



HEADERS += \
    echoplugin.h

SOURCES += \
    echoplugin.cpp
