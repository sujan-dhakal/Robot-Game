#include <iostream>
#include <string.h>
#include <curses.h>
#include "additionalscreens.h"
#include "mainmenu.h"




using namespace std;

int main() {

    MainMenu mm;

    PlayerGameHistory *pgh= new PlayerGameHistory();
    cout<<"Number of Players in the Databases: " << pgh->num_players()<<endl;
    cout<<"Number of Games in the Databases: " << pgh->games_played()<<endl;
    return 0;
}
