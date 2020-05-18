#include "statsdialog.h"
#include "ui_statsdialog.h"

//constructor
StatsDialog::StatsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatsDialog)
{
    ui->setupUi(this);
    draw_details();
}

// deconstructor
StatsDialog::~StatsDialog()
{
    delete ui;
}

/**
 * @brief StatsDialog::draw_details Prints the game statistics
 */
void StatsDialog::draw_details(){
    PlayerGameHistory *pgh;
    pgh = new PlayerGameHistory();

    QString totalGames;
    QString totalPlayers;
    QString avgGames;
    QString topScore;
    QString avgGameScore;
    QString avgScore;

    totalGames = "1. Total number of games played: " + QString::number(pgh->games_played());
    totalPlayers = "2. Total number of players: " + QString::number(pgh->num_players());
    avgGames = "3. Average games played per player: " + QString::number(pgh->avg_games_per_player());
    topScore = "4. Top score: " + QString::number(pgh->top_score());
    avgGameScore = "5. Average game score: " + QString::number(pgh->avg_game_score());
    for (unsigned i = 0; i < (unsigned)pgh->num_players(); i++){
        avgScore += "Average score for " + QString::fromStdString(pgh->get_player(i)->get_first_name()) + " : " + QString::number(pgh->avg_score_for_player(pgh->get_player(i))) + '\n';
    }
    display = totalGames + '\n' + '\n' + totalPlayers + '\n' + '\n' + avgGames + '\n' + '\n' + topScore + '\n' + '\n' + avgGameScore + '\n' +'\n' + avgScore;
    ui->statsLabel->setText(display);
}


