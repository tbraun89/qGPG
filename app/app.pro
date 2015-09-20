include(../qGPG.pri)

TEMPLATE = app

SOURCES += main.cpp

LIBS += -L../src -lqGPG
