include(../../qGPG.pri)

QT -= gui

TARGET = $$qtLibraryTarget(demo-plugin)
TEMPLATE = lib

CONFIG += plugin

SOURCES += \
    demo-plugin.cpp

HEADERS += \
    demo-plugin.h

DESTDIR = ../../app/plugins

LIBS += -L../../src -lqGPG
