#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QMainWindow>
#include "../engines/robots.h"
#include "../engines/engine.h"
#include "../gamecenter/game.h"

namespace Ui {
class robotgui;
}

class robotgui : public QMainWindow
{
    Q_OBJECT

public:
    explicit robotgui(QWidget *parent = nullptr);
    ~robotgui();
    int get_score();
    void set_current_game(Game *g);

private slots:


    void on_nbutton_clicked();

    void on_nebutton_clicked();

    void on_ebutton_clicked();

    void on_sebutton_clicked();

    void on_sbutton_clicked();

    void on_swbutton_clicked();

    void on_wbutton_clicked();

    void on_nwbutton_clicked();

    void on_staybutton_clicked();

    void draw_play_on();

    void draw_gameover();

    void draw_gamewon();

    void on_restart_clicked();

    void on_quit_clicked();

    void on_stbutton_clicked();

    void on_rtbutton_clicked();

    void on_allrobotmove_button_clicked();

    void drawGame();

private:
    Ui::robotgui *ui;
    Robots* r;
    Game* currentgame;
};

#endif // ROBOTGUI_H
