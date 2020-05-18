TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    playergamehistory.cpp \
    player.cpp \
    gamehistory.cpp \
    game.cpp \
    dbtool.cpp \
    dbtable.cpp \
    dbtablegame.cpp \
    dbtableplayer.cpp

HEADERS += \
    playergamehistory.h \
    player.h \
    gamehistory.h \
    game.h \
    dbtool.h \
    dbtable.h \
    dbtablegame.h \
    dbtableplayer.h

LIBS += -l sqlite3
