#include "player.h"

/*
//  Contains information about the player.
//  Object references the most recent game played.
//  Object references a GameHistory class that tracks all games played.
//  When Player Object plays a new game, the reference to current game
//      is stored in GameHistory and a reference is stored to the new game.
//  Stores the following information:
//      Player First Name.
//      Player Last Name.
//      Player Address.
*/

//Default constructor
Player::Player() {
    db_id = -1;
    this->game = nullptr;
    this->gHistory = new GameHistory(this);
    this->firstName = "";
    this->lastName = "";
    this->address = "";
}
/**
 * @brief Player::Player Overloaded constructor
 * @param g game to be added for the player
 * @param gh game history to be created the player
 */
Player::Player(Game *g, GameHistory *gh) {
    db_id = -1;
    this->set_game(g);
    game->set_player(this);
    this->set_game_history(gh);
    gHistory->set_player(this);
}
/**
 * @brief Player::Player Overloaded constructor
 * @param g  game to be aded for the player
 * @param gh  game history to be created for the player
 * @param fName first name of the player
 * @param lName last name of the player
 * @param add address of the player
 */
Player::Player(Game *g, GameHistory *gh, string fName, string lName, string add){
    db_id = -1;
    this->set_game(g);
    game->set_player(this);
    this->set_game_history(gh);
    gHistory->set_player(this);
    this->set_first_name(fName);
    this->set_last_name(lName);
    this->set_address(add);
}

/**
 * @brief Game::~Game Deconstructor adds Player object to the database
 */

Player::~Player() {
    PlayerGameHistory *pgh= new PlayerGameHistory();
    DBTool *dbtool = new DBTool("LabDB");
    DBTablePlayer *ext = new DBTablePlayer(dbtool, "TablePlayer");
    set_db_id(pgh->num_players()+1);
    ext->add_row(db_id, this->firstName, this->lastName, this->address);
   delete game;
}

int Player::get_db_id() {
    return db_id;
}

/* Sets the database id
 * @param i - new id
 */
void Player::set_db_id(int i) {
    db_id = i;
}

/**
 * @brief Player::get_first_name Gets first name of player
 * @return string first name
 */
string Player::get_first_name(){
    return this->firstName;
}

/**
 * @brief Player::set_first_name Sets first name of player
 * @param string fName the name to be set
 */
void Player::set_first_name(string fName){
    this->firstName = fName;
}

/**
 * @brief Player::get_last_name Gets last name of player
 * @return string last name
 */
string Player::get_last_name() {
    return this->lastName;
}

/**
* @brief Player::set_last_name Sets last name of player
* @param string lName the name to be set
*/
void Player::set_last_name(string lName){
    this->lastName = lName;
}

/**
 * @brief Player::get_address Gets address of player
 * @return string address assigned
 */
string Player::get_address(){
    return this->address;
}

/**
 * @brief Player::set_address Sets address of player
 * @param string add the address to be set
 */
void Player::set_address(string add) {
    this ->address = add;
}

/**
 * @brief Player::get_game Gets game of player
 * @return Game the game assigned
 */
Game* Player::get_game() {
    return this->game;
}

/**
 * @brief Player::set_game Sets game of player
 * @param Game g the game to be set
 */
void Player::set_game(Game *g) {
    this->game = g;
}

/**
 * @brief Player::get_game_history Gets game history of player
 * @return GameHistory the history of player
 */
GameHistory* Player::get_game_history(){
    return this->gHistory;
}

/**
 * @brief Player::set_game_history Sets game history of player
 * @param GameHistory gh the history of games by a player
 */
void Player::set_game_history(GameHistory *gh){
    this->gHistory = gh;
}

/**
 * @brief Player::add_game Adds a new game to player's game history
 * @param g game to be added
 */
void Player::add_game(Game *g){
    if(this->game !=nullptr) {
        this->gHistory->add_game(g);
    }
    this->set_game(g);
}
