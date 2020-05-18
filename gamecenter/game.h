#ifndef GAME_H
#define GAME_H

using namespace std;

#include "string"
#include "player.h"


class Player;

#include "dbtool.h"
class DBTool;

#include "dbtable.h"
class DBTable;

#include "dbtablegame.h"
class DBTableGame;

#include "dbtableplayer.h"
class DBTablePlayer;

class Game {
public:
    Game();
    Game(Player *p);
    Game(Player *p, string n, int s);
    ~Game();

    //Getter and setter methods
    Player* get_player();
    void set_player(Player* p);

    int get_score();
    void set_score(int s);

    string get_name();
    void set_name(string n);

    int get_db_id();
    void set_db_id(int i);
    int get_p_id();
    void set_p_id(int i);
    int score; //Final score


private:
    Player* player;
    string name; //Name of the game
    int db_id;
    int p_id;


};

struct GameV{
    bool operator()(const Game *gamel, const Game *gamer){
        return (*gamel).score>(*gamer).score;
    }
};

#endif // GAME_H
