#include "screen.h"

// default constructor
Screen::Screen(){
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

// deconstructor
Screen::~Screen(){

}
