#include "robotsscreen.h"

// default constructor
Robotsscreen::Robotsscreen(){
    bool continue_loop=true;
    displayIns();                   // display instructions at the beginning of the game
    while (!r.gameLost && !r.gameWon() && continue_loop) {
        refresh();
        int ch=getch();
        switch(ch){                 // check input character
        case 113:
            r.input('q');
            break;
        case 119:
            r.input('w');
            break;
        case 101:
            r.input('e');
            break;
        case 97:
            r.input('a');
            break;
        case 115:
            r.input('s');
            break;
        case 100:
            r.input('d');
            break;
        case 122:
            r.input('z');
            break;
        case 120:
            r.input('x');
            break;
        case 99:
            r.input('c');
            break;
        case 116:
            r.input('t');
            break;
        case 114:
            r.input('r');
            break;
        case 102:
            r.input('f');
            break;
        case 112:
            continue_loop=false;
            break;
        default:
            break;
        }
        draw_screen(r, 1);
    }

    if (r.gameLost){
        draw_screen(r, 3);
        while (getch()!=10){
           draw_screen(r, 3);
        }
        endwin();
    }

    if (r.gameWon()){
        draw_screen(r, 3);
        while(getch()!=10){
            draw_screen(r, 3);
        }
        endwin();
    }

}


Robotsscreen::~Robotsscreen(){

}


void Robotsscreen::draw_screen(Robots &r, int type) {               // draw screen, draw screen based on the condition
    string display;
    clear();
    if (type==1) {
        displayGame(r);
    }  else if (type==2){
        displayGame(r);
        mvprintw(1,1, "CONGRATULATIONS!!! YOU WON");
        mvprintw(2,1, "THANK YOU FOR PLAYING");
        mvprintw(3,1, "Press <ENTER> to go to the Main Menu.");
        //mvprintw(3,1, "Do you wanna play the next game? Yes-y No-n");

    }  else if (type==3){
        displayGame(r);
        mvprintw(1,1, "SORRY. YOU LOST");
        mvprintw(2,1, "THANK YOU FOR PLAYING");
        mvprintw(3,1, "Press <ENTER> to go to the Main Menu.");
        //mvprintw(3,1, "Do you wanna play the next game? Yes-y No-n");
    }
}

void Robotsscreen::displayGame(Robots &r){          // display gameboard and game characters
    string display;
    clear();
    display = "+";
    for(int i = 0; i < r.getCOLS(); i++) {
        display += "-";
    }
    display += "+";

    mvprintw(4, 5, display.c_str());
    for (int i=0; i<r.getROWS(); i++) {
        display = "|";
        for (int j=0; j<r.getCOLS(); j++){
            display= display+r.getGameboard()[i][j];
        }
        display += "|";
        mvprintw(5+i, 5, display.c_str());
    }
    display = "+";
    for(int i = 0; i < r.getCOLS(); i++) {
        display += "-";
    }
    display += "+";
    mvprintw(5 + r.getROWS(), 5, display.c_str());
    display="Safe Teleports: " + to_string(r.getST());
    mvprintw(7 + r.getROWS(), 2, display.c_str());
    display="Score: "+to_string(r.get_score());
    mvprintw(9+r.getROWS(), 2, display.c_str());
}

void Robotsscreen::displayIns(){            // display instructions
    string display;
    clear();
    mvprintw(2,5, "ROBOT");
    mvprintw(4,2, "q - North West");
    mvprintw(5,2, "w - North");
    mvprintw(6,2, "e - North East");
    mvprintw(7,2, "a - West");
    mvprintw(8,2, "s - Stay in same position");
    mvprintw(9,2, "d - East");
    mvprintw(10,2, "z - South West");
    mvprintw(11,2, "x - South");
    mvprintw(12,2, "c - South East");
    mvprintw(13,2, "t - Safe teleport (only 5 safe teleports allowed)");
    mvprintw(14,2, "r - Random teleport");
    mvprintw(15,2, "f - Robots move until you die or all robots die");
    mvprintw(16, 2, "p - Exit the game");
    mvprintw(18, 5, "Press ENTER to Continue");
}

int Robotsscreen::get_score(){
    return r.get_score();
}
