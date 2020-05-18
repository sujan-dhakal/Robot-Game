#ifndef MAINMENU_H
#define MAINMENU_H

#include "../tui/screen.h"
#include "../tui/robotsscreen.h"
#include "newplayer.h"
#include "selectplayer.h"
#include "statistics.h"
#include "topgames.h"
#include "topplayers.h"

#include "../gamecenter/game.h"
#include "../gamecenter/gamehistory.h"
#include "../gamecenter/player.h"
#include "../gamecenter/playergamehistory.h"
#include "../gamecenter/dbtable.h"
#include "../gamecenter/dbtool.h"
#include "../gamecenter/dbtablegame.h"
#include "../gamecenter/dbtableplayer.h"



class MainMenu : public Screen //inherit from existing parent Screen class
{
public:
    MainMenu();
    ~MainMenu();

    //Methods
    void draw_screen();

    void select_player();
    void show_top_players();
    void show_top_games();
    void show_statistics();
    void play_robots();
    void create_new_player();

    Player* get_current_player();
    void set_current_player(Player* p);


private:
    Player* current_player=nullptr;
};

#endif // MAINMENU_H
