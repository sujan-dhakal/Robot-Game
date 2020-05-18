TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += -pthread

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest
                ../gtest/googletest/include/gtest/gtest.h

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

HEADERS += ../engines/robots.h
SOURCES += ../engines/robots.cpp
