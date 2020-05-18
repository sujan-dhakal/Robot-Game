#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H
#include <string>
#include "vector"
using namespace std;

#include "player.h"
class Player;
#include "game.h"
class Game;

#include "dbtool.h"
class DBTool;

#include "dbtable.h"
class DBTable;

#include "dbtablegame.h"
class DBTableGame;

#include "dbtableplayer.h"
class DBTablePlayer;

class GameHistory {
public:
    GameHistory();
    GameHistory(Player *p);
    ~GameHistory();


    //Methods
    void add_game(Game *g); //add a new game to history

    //Getters and setters

    Player *get_player();
    void set_player(Player* p);

    Game *get_game(unsigned index);
    int get_num_games();

private:
    Player* player;
    vector<Game*> games;

};

#endif // GAMEHISTORY_H
