#include "engine.h"

// default constructor
Engine::Engine() {
    ROWS=10;
    COLS=10;
    gameboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        gameboard[i] = new char[COLS];
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' ';
        }
    }
}

// constructor that accepts rows and cols as parameters
Engine::Engine(int r, int c){
    ROWS=r;
    COLS=c;
    gameboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        gameboard[i] = new char[COLS];
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = ' ';
        }
    }

}

// deconstructor
Engine::~Engine(){
    delete [] gameboard;
}

// get the number of ROWS
int Engine::getROWS(){
    return ROWS;
}

// get the number of COLS
int Engine::getCOLS(){
    return COLS;
}

// get gameboard
char** Engine::getGameboard() {
    return gameboard;
}

