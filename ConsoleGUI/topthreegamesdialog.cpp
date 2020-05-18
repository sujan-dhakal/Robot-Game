#include "topthreegamesdialog.h"
#include "ui_topthreegamesdialog.h"

// constructor
Topthreegamesdialog::Topthreegamesdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Topthreegamesdialog)
{
    ui->setupUi(this);
    show_top_games();
}

// deconstructor
Topthreegamesdialog::~Topthreegamesdialog()
{
    delete ui;
}

/**
 * @brief Topthreegamesdialog::show_top_games show top three games
 */

void Topthreegamesdialog::show_top_games(){
    PlayerGameHistory *pgh;
    pgh= new PlayerGameHistory();
    vector<Game*> gamesvector;

    for (unsigned i=0; i<(unsigned)pgh->games_played(); i++){
        gamesvector.push_back(pgh->get_game(i));
    }

    sort(gamesvector.begin(), gamesvector.end(), GameV());

    if (pgh->games_played()==0){
        display= " No Games to Show";
    }

    if (pgh->games_played()==1){
        display= "1. "+ QString::fromStdString(gamesvector.at(0)->get_name())+ "  " + QString::number(gamesvector.at(0)->get_score());
    }

    if (pgh->games_played()==2){
        QString st;
        QString st2;
        st= "1. "+ QString::fromStdString(gamesvector.at(0)->get_name())+ "  " + QString::number(gamesvector.at(0)->get_score());
        st2= "2. "+ QString::fromStdString(gamesvector.at(1)->get_name())+ "  " + QString::number(gamesvector.at(1)->get_score());
        display = st+ '\n' + '\n'+ st2;
    }

    if (pgh->games_played()>=3){
        QString st;
        QString st2;
        QString st3;
        st= "1. "+ QString::fromStdString(gamesvector.at(0)->get_name())+ "  " + QString::number(gamesvector.at(0)->get_score());
        st2= "2. "+ QString::fromStdString(gamesvector.at(1)->get_name())+ "  " + QString::number(gamesvector.at(1)->get_score());
        st3= "3. "+ QString::fromStdString(gamesvector.at(2)->get_name())+ "  " + QString::number(gamesvector.at(2)->get_score());
        display = st+ '\n' + '\n'+ st2 + '\n'+ '\n'+ st3;
    }
    ui->topgamelabel->setText(display);
}
