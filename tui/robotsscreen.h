#ifndef ROBOTSSCREEN_H
#define ROBOTSSCREEN_H
#include "../engines/engine.h"
#include "../engines/robots.h"
#include "screen.h"


class Robotsscreen : public Screen {
public:
    Robotsscreen();                             // default constructor
    ~Robotsscreen();
    void draw_screen(Robots &r, int type);      // draw screen method
    void displayGame(Robots &r);                // display gameboard and chracters
    void displayIns();                          // display instruction
    int get_score();

private:
    Robots r;
};

#endif // ROBOTSSCREEN_H
