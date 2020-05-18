#include "mainmenugui.h"
#include "ui_mainmenugui.h"

//Constructor
MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    ui->setupUi(this);
    draw_curr_player();
}
//Deconstructor
MainMenuGUI::~MainMenuGUI() {
    delete ui;
}
/**
 * @brief MainMenuGUI::get_current_player Retrieves current player
 * @return The current player
 */
Player* MainMenuGUI::get_current_player(){
    return currentPlayer;
}

/**
 * @brief MainMenuGUI::set_current_player Sets a player to be current player
 * @param The player to be set
 */
void MainMenuGUI::set_current_player(Player *p){
    currentPlayer=p;
}

/**
 * @brief MainMenuGUI::draw_curr_player Prints the information about current player
 */
void MainMenuGUI::draw_curr_player(){
    if (currentPlayer==nullptr){
        QString st= "Current Player: No Player Selected";
        ui->curr_player->setText(st);
    } else {
        QString st= "Current Player: "+ QString::fromStdString(currentPlayer->get_first_name());
        ui->curr_player->setText(st);
    }
}

/**
 * @brief MainMenuGUI::on_actionCreate_New_Player_triggered Opens a dialog for creating a new player
 */
void MainMenuGUI::on_actionCreate_New_Player_triggered(){
    NewPlayerDialog npd;
    npd.setModal(true);
    npd.exec();
    set_current_player(npd.get_player());
    npd.call_deconstructor();
    draw_curr_player();
}

/**
 * @brief MainMenuGUI::on_actionSelect_Existing_Player_triggered Opens a dialog for selecting an existing player
 */
void MainMenuGUI::on_actionSelect_Existing_Player_triggered()
{
    SelectPlayerDialog spd;
    spd.setModal(true);
    spd.exec();
    set_current_player(spd.get_current_player());
    draw_curr_player();

}

/**
 * @brief MainMenuGUI::on_actionGame_Statistics_triggered Shows game stats
 */
void MainMenuGUI::on_actionGame_Statistics_triggered() {
    StatsDialog stats;
    stats.setModal(true);
    stats.exec();

}
/**
 * @brief MainMenuGUI::on_actionTop_3_Players_triggered Shows top 3 players
 */
void MainMenuGUI::on_actionTop_3_Players_triggered() {
    TopThreePlayersDialog topPlayers;
    topPlayers.setModal(true);
    topPlayers.exec();
}

/**
 * @brief MainMenuGUI::on_actionTop_3_Games_triggered Shows top 3 games
 */
void MainMenuGUI::on_actionTop_3_Games_triggered() {
    Topthreegamesdialog tgd;
    tgd.setModal(true);
    tgd.exec();
}

/**
 * @brief MainMenuGUI::on_playRobot_clicked Starts a Robots game
 */
void MainMenuGUI::on_playRobot_clicked()
{
    if (currentPlayer!=nullptr){
        Game* g= new Game(currentPlayer);
        robotgui* rGUI;
        rGUI = new robotgui();
        rGUI->set_current_game(g);
        rGUI->show();
    }
}

/**
 * @brief MainMenuGUI::on_actionExit_triggered Closes the program
 */
void MainMenuGUI::on_actionExit_triggered() {
    close();
}
