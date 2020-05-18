#include "mainmenu.h"



MainMenu::MainMenu()
{
start:
    refresh();
    draw_screen();
    int ch = getch();

    switch(ch) {

    //a - Create a new player
    case(97):
        create_new_player();
        goto start;

        //b - Select a new player
    case(98):
        select_player();
        goto start;

        //c - Show top 3 players
    case(99):
        show_top_players();
        goto start;

        //d - Show top 3 games
    case(100):
        show_top_games();
        goto start;

        //e - Show statistics
    case(101):
        show_statistics();
        goto start;

        //f - Play robots
    case(102):
        if (current_player==nullptr){
            goto start;
        } else {
            play_robots();
            goto start;
        }

        //q - Exit
    case(113):
        break;

    default:
        goto start;
    }
    endwin();
}


MainMenu::~MainMenu(){

}

/**
 * @brief MainMenu::draw_screen Draws main menu options
 */
void MainMenu::draw_screen() {
    string display;
    clear();

    if (current_player==nullptr){
        mvprintw(1,1, "Current Player: No Player Selected");
    } else {
        display= "Current Player: "+ current_player->get_first_name();
        mvprintw(1,1, display.c_str());
    }

    mvprintw(3, 1, "a. Create a New Player \n "
                   "b. Select an Existing Player \n \n "
                   "c. Display Top Three Players \n "
                   "d. Display Top Three Games Played \n "
                   "e. Display Calculated Statistics \n \n "
                   "f. Play Robots \n "
                   "q. Exit Program ");

    mvprintw(13, 1, "Please select a current player or create a new player before playing");

    refresh();
}
/**
 * @brief MainMenu::get_current_player Gets current player
 * @return The current player of the session
 */
Player* MainMenu::get_current_player(){
    return current_player;
}
/**
 * @brief MainMenu::set_current_player Sets the current player for the session
 * @param p The player to be set
 */
void MainMenu::set_current_player(Player* p){
    current_player=p;
}

/**
 * @brief MainMenu::play_robots Starts a new robots game
 */
void MainMenu::play_robots() {
    Robotsscreen rs;
    Game *g = new Game(current_player);
    g->set_name("Robot");
    g->set_score(rs.get_score());
    g->~Game();
}
/**
 * @brief MainMenu::select_player Creates an instance of the SelectPlayer class
 */
void MainMenu::select_player() {
    SelectPlayer sp;
    set_current_player(sp.get_current_player());
}
/**
 * @brief MainMenu::show_top_games Creates an instance of the TopGame class
 */
void MainMenu::show_top_games(){
    TopGames tg;
}
/**
 * @brief MainMenu::show_statistics Creates an instance of the Statistics class
 */
void MainMenu::show_statistics() {
    Statistics s;
}
/**
 * @brief MainMenu::create_new_player Creates an instance of the NewPlayer class
 */
void MainMenu::create_new_player() {
    NewPlayer np;
    set_current_player(np.get_player());
    if (current_player!=nullptr){
        np.call_deconstructor();
    }
}
/**
 * @brief MainMenu::show_top_players Creates an instance of TopPlayer class
 */
void MainMenu::show_top_players() {
    TopPlayers tp;
}

