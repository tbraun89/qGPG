include(../qGPG.pri)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += main.cpp

LIBS += -L../src -lqGPG
