QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qGPG
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    ui/mainwindow.cpp \
    crypto/keys.cpp

HEADERS  += \
    ui/mainwindow.h \
    crypto/keys.h

FORMS    += \
    ui/mainwindow.ui

OTHER_FILES +=

unix|win32: LIBS += -lgpgme
