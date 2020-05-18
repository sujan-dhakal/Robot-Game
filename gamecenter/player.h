#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

#include "game.h"           // referencing game
class Game;

#include "gamehistory.h"        //referencing gamehistory
class GameHistory;

#include "dbtool.h"
class DBTool;

#include "dbtable.h"
class DBTable;

#include "dbtablegame.h"
class DBTableGame;

#include "dbtableplayer.h"
class DBTablePlayer;

class Player {
public:
    Player();
    Player(Game *g, GameHistory *h);
    Player(Game *g, GameHistory *gh, string fn, string ln, string a);
    ~Player();

    //Add game
    void add_game(Game* g);

    //Geter and setter methods

    string get_first_name();
    void set_first_name(string fName);

    string get_last_name();
    void set_last_name(string lName);

    string get_address();
    void set_address(string add);

    Game* get_game();
    void set_game(Game* g);

    GameHistory* get_game_history();
    void set_game_history(GameHistory* gh);

    int get_db_id();
    void set_db_id(int i);


private:
    int db_id;
    string firstName;
    string lastName;
    string address;
    Game* game;
    GameHistory* gHistory;
};

#endif // PLAYER_H
