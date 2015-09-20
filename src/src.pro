include(../qGPG.pri)

TARGET = qGPG
TEMPLATE = lib

CONFIG += c++11 largefile

SOURCES += \
    ui/mainwindow.cpp \
    crypto/keys.cpp \
    ui/encryptwidget.cpp \
    crypto/plainmessage.cpp \
    crypto/encryptedmessage.cpp \
    crypto/message.cpp \
    ui/decryptwidget.cpp \
    errorhandler.cpp

HEADERS += \
    ui/mainwindow.h \
    crypto/keys.h \
    ui/encryptwidget.h \
    crypto/plainmessage.h \
    crypto/encryptedmessage.h \
    crypto/message.h \
    ui/decryptwidget.h \
    errorhandler.h

FORMS += \
    ui/mainwindow.ui \
    ui/encryptwidget.ui \
    ui/decryptwidget.ui

LIBS += -lgpgme
