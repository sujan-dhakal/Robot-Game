#include "gamehistory.h"

GameHistory::GameHistory()
{
    this->player = nullptr;
}

GameHistory::GameHistory(Player* p){
    this->set_player(p);
}

GameHistory::~GameHistory() {
    delete player;
    games.clear();
}

/**
 * @brief GameHistory::add_game Adds a new game to game history
 * @param Game g the game to be added
 */
void GameHistory::add_game(Game *g) {
    g->set_player(this->get_player());
    games.push_back(g);
}
/**
 * @brief GameHistory::get_player Gets player assigned to history
 * @return Player player assigned to game history
 */
Player* GameHistory::get_player(){
    return this->player;
}
/**
 * @brief GameHistory::set_player Sets player to history
 * @param Player p the player to be set
 */
void GameHistory::set_player(Player *p){
    this->player = p;
}

/**
 * @brief GameHistory::get_game Gets game
 * @param index
 * @return
 */
Game* GameHistory::get_game(unsigned index){
    return this->games[index];
}

int GameHistory::get_num_games() {
    return (int)this->games.size();
}
