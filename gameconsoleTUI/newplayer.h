#ifndef NEWPLAYER_H
#define NEWPLAYER_H
#include "additionalscreens.h"
#include <form.h>
#include <string>
#include <iostream>

using namespace std;

class NewPlayer : public AdditionalScreens //inherit from new parent
{
public:
    NewPlayer();
    ~NewPlayer();

    //Methods
    void draw_form();
    void create_new_player(string fN, string lN, string add);

    Player* get_player();
    void call_deconstructor();

private:
    Player* newPlayer;
    FIELD *field[4];
    FORM  *my_form;

};

#endif // NEWPLAYER_H
