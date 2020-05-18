#include "selectplayerdialog.h"
#include "ui_selectplayerdialog.h"

SelectPlayerDialog::SelectPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPlayerDialog)
{
    ui->setupUi(this);
    show_all_players();
}

SelectPlayerDialog::~SelectPlayerDialog()
{
    delete ui;
}

/**
 * @brief SelectPlayerDialog::show_all_players Prints list of all existing players
 */
void SelectPlayerDialog::show_all_players(){
    for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
        QPushButton* button= new QPushButton();
        string name= pgh->get_player(i)->get_first_name();
        button->setText(name.c_str());
        ui->vl->addWidget(button);
        connect(button, &QPushButton::clicked, [this, i]{
            this->set_current_player(pgh->get_player(i));
        });
    }
}

/**
 * @brief SelectPlayerDialog::set_current_player Sets the selected player to be the current player of the program
 * @param p The selected player
 */
void SelectPlayerDialog::set_current_player(Player *p){
    this->currPlayer = p;
    close();
}

/**
 * @brief SelectPlayerDialog::get_current_player Retrieves the selected player
 * @return The selected player
 */
Player* SelectPlayerDialog::get_current_player(){
    return this->currPlayer;
}
