#include "statistics.h"

Statistics::Statistics() {

    draw_details();

    while (getch()!=10) {
        draw_details();
    }
    endwin();
}

Statistics::~Statistics(){

}
/**
 * @brief Statistics::draw_details Display the statistics
 */
void Statistics::draw_details(){
    PlayerGameHistory *pgh;
    pgh = new PlayerGameHistory();
    string display;
    clear();

    display= "1. Total number of games played: " + to_string(pgh->games_played());
    mvprintw(3,1, display.c_str());

    display= "2. Total number of players: " + to_string(pgh->num_players());
    mvprintw(5, 1, display.c_str());

    display= "3. Average games played per player: "+ to_string(pgh->avg_games_per_player());
    mvprintw(7, 1, display.c_str());

    display= "4. Top Score: "+ to_string(pgh->top_score());
    mvprintw(9, 1, display.c_str());

    display= "5. Average game score: "+ to_string(pgh->avg_game_score());
    mvprintw(11, 1, display.c_str());

    for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
        display= "Average score for "+ pgh->get_player(i)->get_first_name() + " : " + to_string(pgh->avg_score_for_player(pgh->get_player(i)));;
        mvprintw((int)(13+i), 2, display.c_str());
    }

    mvprintw(13+pgh->num_players()+2, 5, "Press Enter to Exit.");
}
