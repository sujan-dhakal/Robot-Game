#ifndef TOPGAMES_H
#define TOPGAMES_H

#include "additionalscreens.h"
#include <algorithm>

class TopGames : public AdditionalScreens {
public:
    TopGames();
    ~TopGames();

    //methods
    void draw_details();

};

#endif // TOPGAMES_H
