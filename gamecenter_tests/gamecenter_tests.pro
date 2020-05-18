TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += -pthread
LIBS += -l sqlite3

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest          \
                ../gtest/googletest/include/gtest/gtest.h

HEADERS += ../gamecenter/game.h
SOURCES += ../gamecenter/game.cpp

HEADERS += ../gamecenter/player.h
SOURCES += ../gamecenter/player.cpp

HEADERS += ../gamecenter/gamehistory.h
SOURCES += ../gamecenter/gamehistory.cpp

HEADERS += ../gamecenter/playergamehistory.h
SOURCES += ../gamecenter/playergamehistory.cpp

HEADERS += ../gamecenter/dbtool.h
SOURCES += ../gamecenter/dbtool.cpp

HEADERS += ../gamecenter/dbtable.h
SOURCES += ../gamecenter/dbtable.cpp

HEADERS += ../gamecenter/dbtablegame.h
SOURCES += ../gamecenter/dbtablegame.cpp

HEADERS += ../gamecenter/dbtableplayer.h
SOURCES += ../gamecenter/dbtableplayer.cpp
