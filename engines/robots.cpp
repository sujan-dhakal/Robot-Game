// Programmer: Sujan Dhakal
// Robot Game Assignmet
// CS205- Software Engineering
// Professor Collins
// Feb 17, 2019

#include "robots.h"

// default constructor
Robots::Robots() {
    srand(time(NULL));
    initiateGB();
    ST=5;
    newboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        newboard[i] = new char[COLS];
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            newboard[i][j] = ' ';
        }
    }
}

Robots::Robots(int r, int c) : Engine::Engine(r, c){
    srand(time(NULL));
    initiateGB();
    ST=5;
    newboard = new char*[ROWS];
    for(int i = 0; i < ROWS; i++) {
        newboard[i] = new char[COLS];
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            newboard[i][j] = ' ';
        }
    }
}
// copy constructor
Robots::Robots(Robots &obj){
    srand(time(NULL));
    playerX=obj.playerX;
    playerY=obj.playerY;
    gameLost=obj.gameLost;
    ST=obj.ST;
}

// copy assignment
void Robots::operator=(Robots &obj) {
    srand(time(NULL));
    playerX=obj.playerX;
    playerY=obj.playerY;
    gameLost=obj.gameLost;
    ST=obj.ST;
}


// deconstructor
Robots::~Robots(){

}

// get player's x position
int Robots::getPlayerX(){
    return playerX;
}

// set player's x position
void Robots::setPlayerX(int x){
    this->playerX=x;
}

// get player's y position
int Robots::getPlayerY(){
    return playerY;
}

// set player's y position
void Robots::setPlayerY(int y){
    this->playerY=y;
}

// get data from old gameboard at the position x,y
char Robots::getOldData(int x, int y){
    return this->gameboard[x][y];
}

// get data from old gameboard at the position x,y
char Robots::getNewData(int x, int y){
    return this->newboard[x][y];
}

// get the game lost status
bool Robots::getGameLost(){
    return this->gameLost;
}

// get safe teleport number
int Robots::getST(){
    return ST;
}

/**
 * @brief Robots::initiateGB Initiate the game board with placing players and robots
 */
void Robots::initiateGB(){
    int noOfRobots=0;
    playerX=ROWS/2;
    playerY=COLS/2;
    gameboard[playerX][playerY]='h';

    while (noOfRobots!=5){
        int x=getRandomNumber(ROWS);
        int y=getRandomNumber(COLS);
        if (gameboard[x][y]==' '){
            gameboard[x][y]='r';
            noOfRobots++;
        }
    }
}

/**
 * @brief Robots::getRandomNumber Generates random number
 * @return random number
 */
int Robots::getRandomNumber(int i){
    int num = rand() % i;
    return num;

}

/**
 * @brief Robots::input Reads the input character by the user and act accordingly
 * @param input Input character by user
 */
void Robots::input(char input){
    clearNewBoard();
    if (input=='q'){
        updatePlayer(-1, -1);
    } else if (input=='w') {
        updatePlayer(-1, 0);
    } else if (input=='e') {
        updatePlayer(-1, 1);
    } else if (input=='a') {
        updatePlayer(0, -1);
    } else if (input=='s') {
        updatePlayer(0, 0);
    } else if (input=='d') {
        updatePlayer(0, 1);
    } else if (input=='z') {
        updatePlayer(1, -1);
    } else if (input=='x') {
        updatePlayer(1, 0);
    } else if (input=='c') {
        updatePlayer(1, 1);
    } else if (input=='t') {
        steleport();
    } else if (input=='r') {
        rteleport();
    } else if (input=='f') {
        while(!gameLost && !gameWon()){
            updateRobot();
            if (newboard[playerX][playerY]=='r' || newboard[playerX][playerY]=='j') {
                newboard[playerX][playerY]='d';
                gameLost=true;
            } else {
                newboard[playerX][playerY]='h';
            }
            updategameboard();
            clearNewBoard();
        }
    } else if (input=='p') {
        exit(0);
    }
    score=score+1;
}

/**
 * @brief Robots::updatePlayer Update the player's position based on the input
 * @param xShift Horizontal Shift of the player's position
 * @param yShift Vertical Shift of the player's position
 */
void Robots::updatePlayer(int xShift, int yShift){
    playerX=playerX+xShift;
    playerY=playerY+yShift;

    if (playerX>=ROWS || playerY>=COLS || playerX<0 || playerY<0) {
        if (gameboard!=NULL) {
            for (int i=0; i<ROWS; i++){
                if (gameboard[i]!=NULL) {
                    for (int j=0; j<COLS; j++){
                        gameboard[i][j]='d';
                    }
                }
            }
        }
        gameLost=true;
        return;
    }

    if (gameboard[playerX][playerY]=='r' || gameboard[playerX][playerY]=='j') {
        gameboard[playerX][playerY]='d';
        gameboard[playerX-xShift][playerY-yShift]=' ';
        gameLost=true;
        return;
    } else {
        updateRobot();
    }

    if (newboard[playerX][playerY]=='r' || newboard[playerX][playerY]=='j') {
        newboard[playerX][playerY]='d';
        gameboard[playerX-xShift][playerY-yShift]=' ';
        gameLost=true;
    } else {
        newboard[playerX][playerY]='h';
    }
    updategameboard();
    clearNewBoard();
}

/**
 * @brief Robots::updateRobot Determine the updated coordinates for all robots and pass it through updateRNB()
 */
void Robots::updateRobot(){
    if (gameboard!=NULL) {
        for (int i=0; i<ROWS; i++){
            if (gameboard[i]!=NULL) {
                for (int j=0; j<COLS; j++){
                    if (gameboard[i][j]=='r') {

                        if (i<playerX && j<playerY) {           // q
                            updateRNB(i+1, j+1);
                        } else if (i<playerX && j==playerY) {   // w
                            updateRNB(i+1, j);
                        } else if (i<playerX && j>playerY) {    //e
                            updateRNB(i+1, j-1);
                        } else if (i==playerX && j<playerY) {    //a
                            updateRNB(i, j+1);
                        } else if (i==playerX && j>playerY) {    //d
                            updateRNB(i, j-1);
                        } else if (i>playerX && j<playerY) {     //z
                            updateRNB(i-1, j+1);
                        } else if (i>playerX && j==playerY) {    //x
                            updateRNB(i-1, j);
                        } else if (i>playerX && j>playerY) {    //c
                            updateRNB(i-1, j-1);
                        }

                    } else if (gameboard[i][j]=='j'){
                        newboard[i][j]='j';
                    }
                }
            }
        }
    }
}

/**
 * @brief Robots::updateRNB update all robots based on the received coordinates
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Robots::updateRNB(int x, int y){
    if (newboard[x][y]==' '){
        newboard[x][y]='r';
    } else if (newboard[x][y]=='j'){
        newboard[x][y]='j';
    } else if (newboard[x][y]=='r'){
        newboard[x][y]='j';
    }
}

/**
 * @brief Robots::clearNewBoard clears the new gameboard
 */
void Robots::clearNewBoard(){
    if (newboard!=NULL) {
        for (int i=0; i<ROWS; i++){
            if (newboard[i]!=NULL) {
                for (int j=0; j<COLS; j++){
                    newboard[i][j]=' ';
                }
            }
        }
    }
}

/**
 * @brief Robots::updategameboard update the data from new gameboard to the old gameboard
 */
void Robots::updategameboard(){
    if (gameboard!=NULL){
        for (int i=0; i<ROWS; i++){
            if (gameboard[i]!=NULL) {
                for (int j=0; j<COLS; j++){
                    gameboard[i][j]=newboard[i][j];
                }
            }
        }
    }
}

/**
 * @brief Robots::steleport safely teleports the player
 */
void Robots::steleport() {
    if (ST>0) {
        gameboard[playerX][playerY]=' ';
        bool placed=false;
        while (!placed) {
            int x = getRandomNumber(ROWS);
            int y = getRandomNumber(COLS);
            if (gameboard[x][y]==' ') {
                gameboard[x][y]='h';
                playerX=x;
                playerY=y;
                placed=true;
            }
        }
        ST--;
    }
}

/**
 * @brief Robots::rteleport randomly teleports the player
 */
void Robots::rteleport() {
    int x = getRandomNumber(ROWS)-playerX;
    int y = getRandomNumber(COLS)-playerY;
    updatePlayer(x,y);
}

/**
 * @brief Robots::gameWon determine if the game is won or not
 * @return true for game won, else false
 */
bool Robots::gameWon(){
    if (gameboard!=NULL) {
        for (int i=0; i<ROWS; i++){
            if (gameboard[i]!=NULL) {
                for (int j=0; j<COLS; j++){
                    if (gameboard[i][j]=='r'){
                        return false;
                    }
                }
            }
        }
    }
    cout<<'\n';
    //cout<<"CONGRATULATIONS!!! YOU WON."<<endl;
    return true;
}

int Robots::get_score(){
    return score;
}
