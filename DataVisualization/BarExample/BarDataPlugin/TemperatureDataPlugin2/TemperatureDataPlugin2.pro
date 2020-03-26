include(../../../../build.pri)

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets charts
INCLUDEPATH    += ../../Bar3D
TARGET          = $$qtLibraryTarget(temperuredataplugin2)
DESTDIR         = ../../plugins

HEADERS += \
    temperaturedata.h

SOURCES += \
    temperaturedata.cpp
