#include "newplayerdialog.h"
#include "ui_newplayerdialog.h"

//Constructor
NewPlayerDialog::NewPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPlayerDialog)
{
    ui->setupUi(this);
}

//Deconstructor
NewPlayerDialog::~NewPlayerDialog() {
    delete ui;
}

/**
 * @brief NewPlayerDialog::on_buttonBox_accepted Submits the form to create a new player
 */
void NewPlayerDialog::on_buttonBox_accepted() {
    string firstName = ui->firstNameInput->text().toStdString();
    string lastName = ui->lastNameInput->text().toStdString();
    string address = ui->addressInput->text().toStdString();
    create_new_player(firstName, lastName, address);
}

/**
 * @brief NewPlayerDialog::create_new_player Creates a new player from the form
 * @param fN First name
 * @param lN Last name
 * @param add Address
 */
void NewPlayerDialog::create_new_player(string fN, string lN, string add){
    newPlayer = new Player();
    newPlayer->set_first_name(fN);
    newPlayer->set_last_name(lN);
    newPlayer->set_address(add);
}

/**
 * @brief NewPlayerDialog::get_player Retrieves the player
 * @return The player
 */
Player* NewPlayerDialog::get_player(){
    return newPlayer;
}

/**
 * @brief NewPlayerDialog::call_deconstructor Calls the Player deconstructor to add new player to the database
 */
void NewPlayerDialog::call_deconstructor(){
    newPlayer->~Player();
}
