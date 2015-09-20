include(../qGPG.pri)

TEMPLATE = app

SOURCES += \
    tests.cpp

LIBS += -L../src -lqGPG
