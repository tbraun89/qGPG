QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qGPG
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    ui/mainwindow.cpp \
    crypto/keys.cpp \
    ui/encryptwidget.cpp \
    crypto/plainmessage.cpp \
    crypto/encryptedmessage.cpp \
    crypto/message.cpp

HEADERS  += \
    ui/mainwindow.h \
    crypto/keys.h \
    ui/encryptwidget.h \
    crypto/plainmessage.h \
    crypto/encryptedmessage.h \
    crypto/message.h

FORMS    += \
    ui/mainwindow.ui \
    ui/encryptwidget.ui

unix|win32: LIBS += -lgpgme
