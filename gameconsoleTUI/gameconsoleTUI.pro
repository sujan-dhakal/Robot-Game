TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lncurses -lform
LIBS += -l sqlite3

SOURCES += \
        main.cpp \
    newplayer.cpp \
    selectplayer.cpp \
    topplayers.cpp \
    topgames.cpp \
    statistics.cpp \
    mainmenu.cpp \
    additionalscreens.cpp

HEADERS += \
    newplayer.h \
    selectplayer.h \
    topplayers.h \
    topgames.h \
    statistics.h \
    mainmenu.h \
    additionalscreens.h

HEADERS += ../tui/screen.h
SOURCES += ../tui/screen.cpp

HEADERS += ../tui/robotsscreen.h
SOURCES += ../tui/robotsscreen.cpp

HEADERS += ../gamecenter/game.h
SOURCES += ../gamecenter/game.cpp

HEADERS += ../gamecenter/gamehistory.h
SOURCES += ../gamecenter/gamehistory.cpp

HEADERS += ../gamecenter/player.h
SOURCES += ../gamecenter/player.cpp

HEADERS += ../gamecenter/playergamehistory.h
SOURCES += ../gamecenter/playergamehistory.cpp

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

HEADERS += ../engines/robots.h
SOURCES += ../engines/robots.cpp

HEADERS += ../gamecenter/dbtool.h
SOURCES += ../gamecenter/dbtool.cpp

HEADERS += ../gamecenter/dbtable.h
SOURCES += ../gamecenter/dbtable.cpp

HEADERS += ../gamecenter/dbtablegame.h
SOURCES += ../gamecenter/dbtablegame.cpp

HEADERS += ../gamecenter/dbtableplayer.h
SOURCES += ../gamecenter/dbtableplayer.cpp
