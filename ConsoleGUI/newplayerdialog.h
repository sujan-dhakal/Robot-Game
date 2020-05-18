#ifndef NEWPLAYERDIALOG_H
#define NEWPLAYERDIALOG_H

#include <QDialog>
#include "string"
#include <QString>
#include "../gamecenter/player.h"
using namespace std;

namespace Ui {
class NewPlayerDialog;
}

class NewPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPlayerDialog(QWidget *parent = nullptr);
    ~NewPlayerDialog();

    Player* get_player();
    void create_new_player(string fN, string lN, string add);
    void call_deconstructor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewPlayerDialog *ui;
    Player *newPlayer;
};

#endif // NEWPLAYERDIALOG_H
