TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    screen.cpp \
    robotsscreen.cpp

LIBS    += -lncurses

HEADERS += \
    screen.h \
    robotsscreen.h

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

HEADERS += ../engines/robots.h
SOURCES += ../engines/robots.cpp
