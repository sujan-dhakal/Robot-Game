#ifndef ROBOTS_H
#define ROBOTS_H

//#define ROWS 10         // number of rows
//#define COLS 10         // number of columns

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "engine.h"

using namespace std;

class Robots : public Engine {

public:
    Robots();               // default constructor
    Robots(int r, int c);
    Robots(Robots &obj);    // copy constructor
    void operator=(Robots &obj);        // copy assignment
    ~Robots();          // deconstructor

    //methods
    void initiateGB();          // iniate Game Board
    int getRandomNumber(int i);      // generate random number
    void input(char input);     // method to read the input character from keyboard
    void updatePlayer(int xShift, int yShift);      // update player position
    void steleport();               // method for safe teleportation
    void rteleport();               // method for random teleportation
    void updateRobot();             // update robot position after player moves
    void updateRNB(int x, int y);   // update new gameboard with robots' new position
    void clearNewBoard();           // clear the new gameboard
    void updategameboard();          // update the old gameboard with new gameboard data
    bool gameWon();                 // boolean method for gameWon

    int getPlayerX();               // get player's x position
    void setPlayerX(int x);         // set player's y positon

    int getPlayerY();               // get player's y position
    void setPlayerY(int y);         // set player's y position

    char getOldData(int x, int y);      // get old gameboard data

    char getNewData(int x, int y);      // get new gameboard data

    bool getGameLost();                 // get GameStatus

    int getST();                        // get safe teleports number

    int get_score();

    //variables
    int playerX;                       // player's x position
    int playerY;                       // player'sy position
    //char gameboard [ROWS][COLS];         // old gameboard
    char** newboard;        // new gameboard
    bool gameLost=false;
    int ST;                             // available safe teleportations per game

    private:
    int score=0;;

};

#endif // ROBOTS_H
