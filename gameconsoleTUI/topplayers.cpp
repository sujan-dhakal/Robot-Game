#include "topplayers.h"

TopPlayers::TopPlayers() {
    draw_details();

    while (getch()!=10) {
        draw_details();
    }
    endwin();
}

TopPlayers::~TopPlayers(){

}
/**
 * @brief TopPlayers::draw_details Displays the top three players
 */
void TopPlayers::draw_details(){
    PlayerGameHistory *pgh;
    pgh = new PlayerGameHistory();
    vector<float> gamescore;
    string display;
    clear();

    for (unsigned i=0; i<(unsigned)pgh->num_players(); i++) {
        gamescore.push_back(pgh->avg_score_for_player(pgh->get_player(i)));
    }

    sort(gamescore.rbegin(), gamescore.rend());


    if (gamescore.size()==0){
        mvprintw(2, 2, "No Games to Show");
    }

    if (gamescore.size()==1){
        unsigned index1=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gamescore.at(0)==pgh->avg_score_for_player(pgh->get_player(i))){
                display= "1. "+ pgh->get_player(i)->get_first_name() + to_string(gamescore.at(0));
                mvprintw(2, 2, display.c_str());
                index1=i;
                break;
            }
        }
    }

    if (gamescore.size()==2){
        unsigned index1=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gamescore.at(0)==pgh->avg_score_for_player(pgh->get_player(i))){
                display= "1. "+ pgh->get_player(i)->get_first_name() + to_string(gamescore.at(0));
                mvprintw(2, 2, display.c_str());
                index1=i;
                break;
            }
        }

        unsigned index2=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gamescore.at(1)==pgh->avg_score_for_player(pgh->get_player(i)) && i!=index1){
                display= "2. "+ pgh->get_player(i)->get_first_name() + to_string(gamescore.at(1));
                mvprintw(4, 2, display.c_str());
                index2=i;
                break;
            }
        }
    }

    if (gamescore.size()>=3) {
        unsigned index1=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gamescore.at(0)==pgh->avg_score_for_player(pgh->get_player(i))){
                display= "1. "+ pgh->get_player(i)->get_first_name() + to_string(gamescore.at(0));
                mvprintw(2, 2, display.c_str());
                index1=i;
                break;
            }
        }

        unsigned index2=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gamescore.at(1)==pgh->avg_score_for_player(pgh->get_player(i)) && i!=index1){
                display= "2. "+ pgh->get_player(i)->get_first_name() + to_string(gamescore.at(1));
                mvprintw(4, 2, display.c_str());
                index2=i;
                break;
            }
        }

        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gamescore.at(2)==pgh->avg_score_for_player(pgh->get_player(i)) && i!=index1 && i!=index2){
                display= "3. "+ pgh->get_player(i)->get_first_name() + to_string(gamescore.at(2));
                mvprintw(6, 2, display.c_str());
                break;
            }
        }
    }
    mvprintw(8, 5, "Press Enter to Exit.");
}
