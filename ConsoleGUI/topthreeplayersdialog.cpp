#include "topthreeplayersdialog.h"
#include "ui_topthreeplayersdialog.h"

// constructor
TopThreePlayersDialog::TopThreePlayersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TopThreePlayersDialog)
{
    ui->setupUi(this);
    draw_details();
}

// deconstructor
TopThreePlayersDialog::~TopThreePlayersDialog()
{
    delete ui;
}

/**
 * @brief TopThreePlayersDialog::draw_details show top three players based on the average score of a player
 */
void TopThreePlayersDialog::draw_details(){
    PlayerGameHistory *pgh;
    pgh = new PlayerGameHistory();
    vector<float> gameScore;

    for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
        gameScore.push_back(pgh->avg_score_for_player(pgh->get_player(i)));
    }

    sort(gameScore.rbegin(), gameScore.rend());

    if (gameScore.size()==0){

        display = "No Players to Show";
    }

    if(gameScore.size()==1){

        unsigned ind1 = 0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gameScore.at(0)==pgh->avg_score_for_player(pgh->get_player(i))){
                display= "1. "+ QString::fromStdString(pgh->get_player(i)->get_first_name()) + "  " + QString::number(gameScore.at(0));
                ind1 = i;
                break;
            }
        }
    }

    if (gameScore.size()==2){

        QString firstPlayer;
        QString secondPlayer;
        unsigned ind1=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gameScore.at(0)==pgh->avg_score_for_player(pgh->get_player(i))){
                firstPlayer = "1. "+ QString::fromStdString(pgh->get_player(i)->get_first_name()) + "  " + QString::number(gameScore.at(0));
                ind1=i;
                break;
            }
        }

        unsigned ind2=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gameScore.at(1)==pgh->avg_score_for_player(pgh->get_player(i)) && i!=ind1){
                secondPlayer = "2. "+ QString::fromStdString(pgh->get_player(i)->get_first_name()) + "  " + QString::number(gameScore.at(1));
                ind2=i;
                break;
            }
        }
        display = firstPlayer + '\n' + '\n' + secondPlayer;
    }

    if (gameScore.size()>=3) {

        QString firstPlayer;
        QString secondPlayer;
        QString thirdPlayer;
        unsigned ind1=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gameScore.at(0)==pgh->avg_score_for_player(pgh->get_player(i))){
                firstPlayer = "1. "+ QString::fromStdString(pgh->get_player(i)->get_first_name()) + "  " + QString::number(gameScore.at(0));
                ind1=i;
                break;
            }
        }

        unsigned ind2=0;
        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gameScore.at(1)==pgh->avg_score_for_player(pgh->get_player(i)) && i!=ind1){
                secondPlayer = "2. "+ QString::fromStdString(pgh->get_player(i)->get_first_name()) + "  " + QString::number(gameScore.at(1));
                ind2=i;
                break;
            }
        }

        for (unsigned i=0; i<(unsigned)pgh->num_players(); i++){
            if (gameScore.at(2)==pgh->avg_score_for_player(pgh->get_player(i)) && i!=ind1 && i!=ind2){
                thirdPlayer = "3. "+ QString::fromStdString(pgh->get_player(i)->get_first_name()) + "  " + QString::number(gameScore.at(2));
                break;
            }
        }
        display = firstPlayer + '\n' + '\n'+ secondPlayer + '\n'+ '\n'+ thirdPlayer;
    }
    ui->topThreePlayersLabel->setText(display);
}
