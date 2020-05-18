#include "topgames.h"
#include <algorithm>
#include "algorithm"

TopGames::TopGames() {
    draw_details();

    while (getch()!=10) {
        draw_details();
    }
    endwin();
}

TopGames::~TopGames(){

}
/**
 * @brief TopGames::draw_details Displays the top three games
 */
void TopGames::draw_details(){
    PlayerGameHistory *pgh;
    pgh = new PlayerGameHistory();
    string display;
    clear();

    vector<Game*> gamesvector;

    for (unsigned i=0; i<(unsigned)pgh->games_played(); i++){
        gamesvector.push_back(pgh->get_game(i));
    }

    sort(gamesvector.begin(), gamesvector.end(), GameV());

    if (pgh->games_played()==0){
        mvprintw(2, 2, "No Games To Show");
    }

    if (pgh->games_played()==1){
        display= "1. "+ gamesvector.at(0)->get_name()+ "  " + to_string(gamesvector.at(0)->get_score());
        mvprintw(2, 2, display.c_str());
    }

    if (pgh->games_played()==2){
        display= "1. "+ gamesvector.at(0)->get_name()+ "  " + to_string(gamesvector.at(0)->get_score());
        mvprintw(2, 2, display.c_str());

        display= "2. "+ gamesvector.at(1)->get_name()+ "  " + to_string(gamesvector.at(1)->get_score());
        mvprintw(4, 2, display.c_str());
    }

    if (pgh->games_played()>=3){
        display= "1. "+ gamesvector.at(0)->get_name()+ "  " + to_string(gamesvector.at(0)->get_score());
        mvprintw(2, 2, display.c_str());

        display= "2. "+ gamesvector.at(1)->get_name()+ "  " + to_string(gamesvector.at(1)->get_score());
        mvprintw(4, 2, display.c_str());

        display= "3. "+ gamesvector.at(2)->get_name()+ "  " + to_string(gamesvector.at(2)->get_score());
        mvprintw(6, 2, display.c_str());
    }
    mvprintw(8, 5, "Press Enter to Exit.");
}
