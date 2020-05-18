#include "newplayer.h"


NewPlayer::NewPlayer()
{
    draw_form();

}

NewPlayer::~NewPlayer() {


}

/**
 * @brief NewPlayer::draw_form Makes a form for new players to sign up
 */
void NewPlayer::draw_form() {

    /******** Initialize curses ********/

    /******** Initialize the variables ********/

    // initialize displayed fields

    // The parameters below are as follows:
    //  1. int height    -- The number of rows in the field.
    //  2. int width     -- The row width of the field.
    //  3. int toprow    -- The screen row where the field top is placed.
    //  4. int leftcol   -- The screen col where the field left-side is placed.
    //  5. int offscreen -- Zero shows entire field.
    //  6. int nbuffers  -- Number of additional buffers, use zero.

    field[0] = new_field(1, 12, 4, 27, 0, 0);
    field[1] = new_field(1, 12, 6, 27, 0, 0);
    field[2] = new_field(1, 20, 8, 27, 0, 0);

    // Tag end of array so ncurses knows when there are no
    // more fields.
    field[3] = NULL;

    // Initialize the interaction loop to run.
    bool continue_looping = true;

    /******** Set field options ********/

    // Print a line for the option.
    set_field_back(field[0], A_UNDERLINE);
    set_field_back(field[1], A_UNDERLINE);
    set_field_back(field[2], A_UNDERLINE);

    //  Don't go to next field when this field is filled up.
    field_opts_off(field[0], O_AUTOSKIP);
    field_opts_off(field[1], O_AUTOSKIP);
    field_opts_off(field[2], O_AUTOSKIP);

    /******** Create form. ********/

    // Create the form and post it.
    my_form = new_form(field);
    post_form(my_form);

    // build the form
    refresh();

    // display labels
    mvprintw(4, 10, "First Name:");
    mvprintw(6, 10, "Last Name:");
    mvprintw(8, 10, "Address:");
    mvprintw(12, 3, "Use <UP>/<DOWN> arrow keys to navigate the form");
    mvprintw(13, 3, "Use <DELETE>/<BACKSPACE> key on Mac/Windows to delete previous character");
    mvprintw(14, 3, "Press Enter to save your details.");
    mvprintw(15, 3, "Press Esc to cancel and go to the mainmenu. (No Player will be selected)");


    // perform last refresh
    refresh();

    curs_set(1);

    /******* Loop through to get user requests *******/

    do {
        // obtain character from keyboard
        int ch = getch();

        switch(ch) {
        case KEY_DOWN:

            // go to next field
            form_driver(my_form, REQ_NEXT_FIELD);

            // Go to the end of the present buffer
            // and leave nicely at the last character
            form_driver(my_form, REQ_END_LINE);

            break;

        case KEY_UP:

            // go to previous field
            form_driver(my_form, REQ_PREV_FIELD);

            // Go to the end of the present buffer
            // and leave nicely at the last character
            form_driver(my_form, REQ_END_LINE);

            break;

        case (127):         // delete key
            form_driver(my_form, REQ_PREV_CHAR);
            form_driver(my_form, REQ_DEL_CHAR);
            break;

        case KEY_BACKSPACE:
            form_driver(my_form, REQ_PREV_CHAR);
            form_driver(my_form, REQ_DEL_CHAR);
            break;



        case 27:

            // exit from loop
            continue_looping = false;

            break;

        case 10:

            // exit from loop
            continue_looping = false;

            // stores the buffer on the field it is located
            form_driver(my_form, REQ_END_LINE);
            unpost_form(my_form);
            free_form(my_form);

            //     //store contents of fields before they are freed
            //        string field0_value = field_buffer(field[0],0);
            //        string field1_value = field_buffer(field[1],0);
            create_new_player(field_buffer(field[0],0), field_buffer(field[1],0), field_buffer(field[2],0));

            // free the fields
            free_field(field[0]);
            free_field(field[1]);
            free_field(field[2]);

            break;

        default:
            // If this is a normal character, print it.
            form_driver(my_form, ch);
            break;
        }

    } while (continue_looping);

    // exit ncurses environment
    endwin();
}

/**
 * @brief NewPlayer::create_new_player Creates a new Player object
 * @param fN First name of the player
 * @param lN Last name of the player
 * @param add Address of the player
 */
void NewPlayer::create_new_player(string fN, string lN, string add){
    newPlayer= new Player();
    newPlayer->set_first_name(fN);
    newPlayer->set_last_name(lN);
    newPlayer->set_address(add);
}
/**
 * @brief NewPlayer::get_player Gets a player
 * @return The new player created
 */
Player* NewPlayer::get_player(){
    return newPlayer;
}
/**
 * @brief NewPlayer::call_deconstructor Calls deconstructor to add the new Player to the database
 */
void NewPlayer::call_deconstructor(){
    newPlayer->~Player();
}
