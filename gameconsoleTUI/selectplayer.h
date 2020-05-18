#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H
#include "additionalscreens.h"
#include "string"
#include "../gamecenter/playergamehistory.h"

using namespace std;

class SelectPlayer : public AdditionalScreens //inherit from new parent
{
public:
    SelectPlayer();
    ~SelectPlayer();

    //Method
    void show_all_players();
    void set_current_player(Player* p);
    Player* get_current_player();


private:
    PlayerGameHistory *pgh = new PlayerGameHistory();
    vector<Player*> players;
    Player* currPlayer;
};

#endif // SELECTPLAYER_H
