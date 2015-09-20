INCLUDEPATH += $$PWD/src
SRC_DIR      = $$PWD

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 largefile
QMAKE_CXXFLAGS += -D_FILE_OFFSET_BITS=64
