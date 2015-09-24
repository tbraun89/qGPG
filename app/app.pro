include(../qGPG.pri)

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    logging.h

LIBS += -L../src -lqGPG
