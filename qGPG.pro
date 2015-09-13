QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qGPG
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    ui/mainwindow.cpp \
    crypto/keys.cpp \
    ui/encryptwidget.cpp

HEADERS  += \
    ui/mainwindow.h \
    crypto/keys.h \
    ui/encryptwidget.h

FORMS    += \
    ui/mainwindow.ui \
    ui/encryptwidget.ui

unix|win32: LIBS += -lgpgme
