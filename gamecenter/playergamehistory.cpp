#include "playergamehistory.h"
/**
 * @brief PlayerGameHistory::PlayerGameHistory Constructor uploads data from database into Game and Player vectors
 */
PlayerGameHistory::PlayerGameHistory() {
    dbtool = new DBTool("LabDB");
    tablegame = new DBTableGame(dbtool, "TableGame");
    tablegame->set_pgh(this);
    tablegame->select_all();
    tableplayer = new DBTablePlayer(dbtool, "TablePlayer");
    tableplayer->set_pgh(this);
    tableplayer->select_all();
    for(unsigned i = 0; i < games.size(); i++) {
        for(unsigned j = 0; j < players.size(); j++) {
            if(games.at(i)->get_p_id() == players.at(j)->get_db_id()) {
                games.at(i)->set_player(players.at(j));
                players.at(j)->add_game(games.at(i));
            }
        }
    }
}

//Destructor
PlayerGameHistory::~PlayerGameHistory(){
    players.clear();
    games.clear();
}
/**
 * @brief PlayerGameHistory::add_player Adds a new player to the history
 * @param p the player to be added
 */
void PlayerGameHistory::add_player(Player *p){
    this->players.push_back(p);
}
/**
 * @brief PlayerGameHistory::get_player Gets a player
 * @param i the index of the wanted player in the vector
 * @return the player to be retrieved
 */
Player* PlayerGameHistory::get_player(unsigned i){
    return this->players.at(i);
}
/**
 * @brief PlayerGameHistory::get_all_players Gets all players
 * @return the vector of players
 */

/**
 * @brief PlayerGameHistory::add_game Adds a new game to the history
 * @param g the game to be added
 */
void PlayerGameHistory::add_game(Game *g){
    this->games.push_back(g);
}
/**
 * @brief PlayerGameHistory::get_game Gets game
 * @param i the index of the wanted game in the vector
 * @return the game to be retrieved
 */
Game* PlayerGameHistory::get_game(unsigned i){
    return this->games.at(i);
}
/**
 * @brief PlayerGameHistory::games_played Calculates the number of games played
 * @return the number of games played
 */
int PlayerGameHistory::games_played(){
    return (int)this->games.size();
}
/**
 * @brief PlayerGameHistory::num_players Calculates the total number of players
 * @return the number of players
 */
int PlayerGameHistory::num_players(){
    return (int)this->players.size();
}
/**
 * @brief PlayerGameHistory::avg_games_per_player Calculates the average number of games played
 * @return avg number of games per player
 */
float PlayerGameHistory::avg_games_per_player(){
    if (num_players()!=0){
        return (games_played()/num_players());
    } else {
        return 0;
    }
}
/**
 * @brief PlayerGameHistory::top_score Gets top score
 * @return the highest score
 */

int PlayerGameHistory::top_score(){
    int max=0;
    for (unsigned i=0; i<games.size(); i++){
        if (games.at(i)->get_score()>max){
            max=games.at(i)->get_score();
        }
    }
    return max;
}
/**
 * @brief PlayerGameHistory::avg_game_score Calculates the average game score
 * @return the average game score
 */
float PlayerGameHistory::avg_game_score(){
    int sum=0;
    for (unsigned i=0; i<games.size(); i++){
        sum +=games.at(i)->get_score();
    }
    if (games_played()!=0){
        return (sum/games_played());
    } else{
        return 0;
    }
}
/**
 * @brief PlayerGameHistory::avg_score_for_player Calculates the average score for a player
 * @param p the targeted player
 * @return the average score of Player p
 */
float PlayerGameHistory::avg_score_for_player(Player *p){
    float totalScore=0;
    int numOfGames=0;
    for (unsigned i=0; i<games.size(); i++){
        if (games.at(i)->get_player()->get_db_id()==p->get_db_id()) {
            totalScore+=games.at(i)->get_score();
            numOfGames +=1;
        }
    }
    if (numOfGames!=0){
        return (totalScore/numOfGames);
    } else {
        return 0;
    }
}

void PlayerGameHistory::construct_game(int size, char **data,
                                       char **colNames) {
    int id = atoi(data[0]);
    int player = atoi(data[1]);
    string name = string(data[2]);
    int score = atoi(data[3]);
    Game *g = new Game();
    g->set_db_id(id);
    g->set_p_id(player);
    g->set_name(name);
    g->set_score(score);
    games.push_back(g);
}

void PlayerGameHistory::construct_player(int size, char **data,
                                         char **colNames) {
    int id = atoi(data[0]);
    string fName = string(data[1]);
    string lName = string(data[2]);
    string address = string(data[3]);
    Player *p = new Player();
    p->set_db_id(id);
    p->set_first_name(fName);
    p->set_last_name(lName);
    p->set_address(address);
    players.push_back(p);
}

