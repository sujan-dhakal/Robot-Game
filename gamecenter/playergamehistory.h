#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include "vector"
#include "iostream"

#include "dbtool.h"
class DBTool;

#include "dbtable.h"
class DBTable;

#include "dbtablegame.h"
class DBTableGame;

#include "dbtableplayer.h"
class DBTablePlayer;

#include "player.h"
class Player;

#include "game.h"
class Game;

class PlayerGameHistory {
public:
    PlayerGameHistory();
    ~PlayerGameHistory();

    //Methods
    void construct_game(int size, char **data, char **colNames);
    void construct_player(int size, char **data, char **colNames);

    void add_player(Player *p);
    Player* get_player(unsigned i);

    void add_game(Game *g);
    Game* get_game(unsigned i);

    int games_played();
    int num_players();
    float avg_games_per_player();
    int top_score();
    float avg_game_score();
    float avg_score_for_player(Player *p);

private:
    DBTool *dbtool;
    DBTableGame *tablegame;
    DBTablePlayer *tableplayer;
    vector<Player*> players;
    vector<Game*> games;

};

#endif // PLAYERGAMEHISTORY_H
