#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <iostream>
#include <string>

#include "../gamecenter/game.h"
#include "../gamecenter/gamehistory.h"
#include "../gamecenter/player.h"
#include "../gamecenter/playergamehistory.h"
#include "../gamecenter/dbtable.h"
#include "../gamecenter/dbtool.h"
#include "../gamecenter/dbtablegame.h"
#include "../gamecenter/dbtableplayer.h"
#include "../RobotGUI/robotgui.h"
#include "newplayerdialog.h"
#include "selectplayerdialog.h"
#include "topthreegamesdialog.h"
#include "topthreeplayersdialog.h"
#include "statsdialog.h"

namespace Ui {
class MainMenuGUI;
}

class MainMenuGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuGUI(QWidget *parent = nullptr);
    ~MainMenuGUI();

    //Method
    Player* get_current_player();
    void set_current_player(Player* p);

    void draw_curr_player();


private slots:
    void on_playRobot_clicked();

    void on_actionExit_triggered();

    void on_actionTop_3_Players_triggered();

    void on_actionTop_3_Games_triggered();

    void on_actionGame_Statistics_triggered();

    void on_actionCreate_New_Player_triggered();

    void on_actionSelect_Existing_Player_triggered();

private:
    Ui::MainMenuGUI *ui;
    Player* currentPlayer=nullptr;
};

#endif // MAINMENUGUI_H
