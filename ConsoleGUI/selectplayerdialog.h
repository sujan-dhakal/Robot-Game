#ifndef SELECTPLAYERDIALOG_H
#define SELECTPLAYERDIALOG_H

#include <QDialog>
#include "string"
#include "../gamecenter/playergamehistory.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "QHBoxLayout"


namespace Ui {
class SelectPlayerDialog;
}

class SelectPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectPlayerDialog(QWidget *parent = nullptr);
    ~SelectPlayerDialog();

    void show_all_players();
    void set_current_player(Player* p);
    Player* get_current_player();

private:
    Ui::SelectPlayerDialog *ui;
    PlayerGameHistory *pgh= new PlayerGameHistory();
    Player* currPlayer;
};

#endif // SELECTPLAYERDIALOG_H
