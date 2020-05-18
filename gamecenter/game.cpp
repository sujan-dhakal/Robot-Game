#include "game.h"

//Default constructor
Game::Game() {
    player= new Player();
    db_id = -1;
    p_id = -1;
    this->player = nullptr;
    this->name = "";
    this->score = 0;
}
/**
 * @brief Game::Game Overloaded constructor
 * @param p player of the game
 */
Game::Game(Player *p) {
    player = new Player();
    db_id = -1;
    p_id = p->get_db_id();
    this->set_player(p);
    player->add_game(this);
    this->name = "";
    this->score = 0;
}

/**
 * @brief Game::Game Overloaded constructor
 * @param p player of the game
 * @param n name of the game
 * @param s score of the game
 */
Game::Game(Player *p, string n, int s) {
    db_id = -1;
    p_id = p->get_db_id();
    this->set_player(p);
    this->set_name(n);
    this->set_score(s);
    player->add_game(this);
}

/**
 * @brief Game::~Game Deconstructor adds information about Game object to the database
 */
Game::~Game() {
    PlayerGameHistory *pgh= new PlayerGameHistory();
    DBTool *dbtool = new DBTool("LabDB");
    DBTableGame *ext = new DBTableGame(dbtool, "TableGame");
    set_db_id(pgh->games_played()+1);
    ext->add_row(db_id, p_id, name, score);
}

int Game::get_db_id() {
    return db_id;
}

/* Sets the id assigned to the game
 * @param i - new id
 */
void Game::set_db_id(int i) {
    db_id = i;
}

/* Gets the id assigned to the game's player
 * @param i - new id
 */
int Game::get_p_id() {
    return p_id;
}

/* Gets the player assigned to the game
 * @return player on the game
 */
void Game::set_p_id(int i) {
    p_id = i;
}
/**
 * @brief Game::get_player Gets the player of the game
 * @return Player object player
 */
Player* Game::get_player() {
    return this->player;
}
/**
 * @brief Game::set_player Sets the player of the game
 * @param p the player to be set
 */
void Game::set_player(Player *p) {
    this->player = p;
}
/**
 * @brief Game::get_score Gets score of the game
 * @return int final score
 */
int Game::get_score(){
    return this->score;
}

/**
 * @brief Game::set_score Sets score of the game
 * @param s the score to be set
 */
void Game::set_score(int s){
    this->score = s;
}
/**
 * @brief Game::get_name Gets name of the game
 * @return string name
 */
string Game::get_name() {
    return this->name;
}
/**
 * @brief Game::set_name Sets name of the game
 * @param n the name to be set
 */
void Game::set_name(string n) {
    this->name = n;
}
