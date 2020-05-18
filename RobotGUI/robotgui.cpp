#include "robotgui.h"
#include "ui_robotgui.h"

// constructor
robotgui::robotgui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::robotgui)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    r= new Robots(20,50);
    drawGame();
}

// deconstructor
robotgui::~robotgui()
{
    delete ui;
}

/**
 * @brief robotgui::drawGame draw game based on the game status
 */
void robotgui::drawGame(){
    if (!r->gameLost && !r->gameWon()){
        draw_play_on();
    } else if (r->gameLost){
        draw_gameover();
    } else if (r->gameWon()){
        draw_gamewon();
    }
    QString st = "Safe Teleports:  " + QString::number(r->getST());
    ui->safeteleport->setText(st);

    QString st2 = "Score:   " + QString::number(get_score());
    ui->score->setText(st2);
}

/**
 * @brief robotgui::draw_play_on draw game if not lost or not won
 */
void robotgui::draw_play_on(){
    QString temp_board="";
    for (int i=0; i<r->getROWS(); i++){
        for (int j=0; j<r->getCOLS(); j++){
            temp_board +=r->getGameboard()[i][j];
        }
        temp_board += '\n';
    }
    ui->gameboard->clear();
    ui->gameboard->setText(temp_board);
}

/**
 * @brief robotgui::draw_gameover gameover case
 */
void robotgui::draw_gameover(){
    draw_play_on();
    QString gameOver = "GAME OVER";
    ui->gamestatus->clear();
    ui->gamestatus->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gamestatus->setText(gameOver);
}

/**
 * @brief robotgui::draw_gamewon gamewon case
 */
void robotgui:: draw_gamewon(){
    draw_play_on();
    QString gameOver = "GAME WON";
    ui->gamestatus->clear();
    ui->gamestatus->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gamestatus->setText(gameOver);
}

/**
 * @brief robotgui::on_nbutton_clicked north movement
 */
void robotgui::on_nbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('w');
        drawGame();
    }
}

/**
 * @brief robotgui::on_nebutton_clicked north east button
 */
void robotgui::on_nebutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('e');
        drawGame();
    }
}

/**
 * @brief robotgui::on_ebutton_clicked east button
 */
void robotgui::on_ebutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('d');
        drawGame();
    }
}

/**
 * @brief robotgui::on_sebutton_clicked south east button
 */
void robotgui::on_sebutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('c');
        drawGame();
    }
}

/**
 * @brief robotgui::on_sbutton_clicked south button
 */
void robotgui::on_sbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('x');
        drawGame();
    }
}

/**
 * @brief robotgui::on_swbutton_clicked south west button
 */
void robotgui::on_swbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('z');
        drawGame();
    }
}

/**
 * @brief robotgui::on_wbutton_clicked west button
 */
void robotgui::on_wbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('a');
        drawGame();
    }
}

/**
 * @brief robotgui::on_nwbutton_clicked north west button
 */
void robotgui::on_nwbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('q');
        drawGame();
    }
}

/**
 * @brief robotgui::on_staybutton_clicked stay button
 */
void robotgui::on_staybutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('s');
        drawGame();
    }
}

/**
 * @brief robotgui::on_stbutton_clicked safe teleport button
 */
void robotgui::on_stbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('t');
        drawGame();
    }
}

/**
 * @brief robotgui::on_rtbutton_clicked random teleport button
 */
void robotgui::on_rtbutton_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('r');
        drawGame();
    }
}

/**
 * @brief robotgui::on_allrobotmove_button_clicked all robots move until you die or all robots die
 */
void robotgui::on_allrobotmove_button_clicked()
{
    if (!r->gameLost && !r->gameWon()) {
        r->input('f');
        drawGame();
    }
}

/**
 * @brief robotgui::on_restart_clicked game restart button
 */
void robotgui::on_restart_clicked(){
    r= new Robots(20,50);
    drawGame();
    ui->gamestatus->clear();
}

/**
 * @brief robotgui::on_quit_clicked game quit button and add game into the database
 */
void robotgui::on_quit_clicked() {
    currentgame->set_name("Robot");
    currentgame->set_score(get_score());
    currentgame->~Game();
    close();
}

int robotgui::get_score(){
    return r->get_score();
}

void robotgui::set_current_game(Game *g){
    currentgame=g;
}
