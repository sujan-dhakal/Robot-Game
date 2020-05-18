#include "selectplayer.h"

SelectPlayer::SelectPlayer()
{
    refresh();
    show_all_players();
    int ch = getch();
    //List of players
    switch(ch) {
    case(97):
        set_current_player(players.at(0));
        break;
    case(98):
        set_current_player(players.at(1));
        break;
    case(99):
        set_current_player(players.at(2));
        break;
    case(100):
        set_current_player(players.at(3));
        break;
    case(101):
        set_current_player(players.at(4));
        break;
    case(102):
        set_current_player(players.at(5));
        break;
    case(103):
        set_current_player(players.at(6));
        break;
    case(104):
        set_current_player(players.at(7));
        break;
    case(105):
        set_current_player(players.at(8));
        break;
    case(106):
        set_current_player(players.at(9));
        break;
    }

    endwin();
}

SelectPlayer::~SelectPlayer(){

}
/**
 * @brief SelectPlayer::show_all_players Show ten players in the database
 */
void SelectPlayer::show_all_players() {
    int numOfPlayers = pgh->num_players();
    clear();
    char c = 'a';
    int yPos = 3;

    for (unsigned i = 0; i < (unsigned)numOfPlayers; i++) {
        if (numOfPlayers<=10){
            Player *p = pgh->get_player(i);
            players.push_back(p);
            string fName = p->get_first_name();
            string lName = p->get_last_name();
            string display(1, c);
            display += ". " + fName + " " + lName;
            mvprintw(yPos, 1, display.c_str());
            c++;
            yPos++;
        }
    }
    refresh();
}
/**
 * @brief SelectPlayer::set_current_player Sets the chosen player to be current player
 * @param p The player to be set
 */
void SelectPlayer::set_current_player(Player *p) {
    this->currPlayer = p;
}
/**
 * @brief SelectPlayer::get_current_player Gets the player set as current player
 * @return The current player
 */
Player* SelectPlayer::get_current_player(){
    return this->currPlayer;
}
