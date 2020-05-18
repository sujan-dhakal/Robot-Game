#-------------------------------------------------
#
# Project created by QtCreator 2019-03-14T14:17:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConsoleGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

LIBS += -l sqlite3

SOURCES += \
        main.cpp \
        mainmenugui.cpp \
    newplayerdialog.cpp \
    selectplayerdialog.cpp \
    topthreegamesdialog.cpp \
    topthreeplayersdialog.cpp \
    statsdialog.cpp

HEADERS += \
        mainmenugui.h \
    newplayerdialog.h \
    selectplayerdialog.h \
    topthreegamesdialog.h \
    topthreeplayersdialog.h \
    statsdialog.h

FORMS += \
        mainmenugui.ui \
    newplayerdialog.ui \
    selectplayerdialog.ui \
    topthreegamesdialog.ui \
    topthreeplayersdialog.ui \
    statsdialog.ui

FORMS    += ../RobotGUI/robotgui.ui

HEADERS += ../RobotGUI/robotgui.h
SOURCES += ../RobotGUI/robotgui.cpp

HEADERS += ../engines/engine.h
SOURCES += ../engines/engine.cpp

HEADERS += ../engines/robots.h
SOURCES += ../engines/robots.cpp

HEADERS += ../gamecenter/game.h
SOURCES += ../gamecenter/game.cpp

HEADERS += ../gamecenter/gamehistory.h
SOURCES += ../gamecenter/gamehistory.cpp

HEADERS += ../gamecenter/player.h
SOURCES += ../gamecenter/player.cpp

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
