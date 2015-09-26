include(../qGPG.pri)

TARGET = qGPG
TEMPLATE = lib

SOURCES += \
    ui/mainwindow.cpp \
    crypto/keys.cpp \
    ui/encryptwidget.cpp \
    crypto/plainmessage.cpp \
    crypto/encryptedmessage.cpp \
    crypto/message.cpp \
    ui/decryptwidget.cpp \
    ui/errorlog.cpp \
    settings/settings.cpp

HEADERS += \
    ui/mainwindow.h \
    crypto/keys.h \
    ui/encryptwidget.h \
    crypto/plainmessage.h \
    crypto/encryptedmessage.h \
    crypto/message.h \
    ui/decryptwidget.h \
    ui/errorlog.h \
    settings/settings.h

FORMS += \
    ui/mainwindow.ui \
    ui/encryptwidget.ui \
    ui/decryptwidget.ui \
    ui/errorlog.ui

RESOURCES += \
    resources.qrc

LIBS += -lgpgme
