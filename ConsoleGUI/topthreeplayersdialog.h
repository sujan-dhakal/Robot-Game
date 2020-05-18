#ifndef TOPTHREEPLAYERSDIALOG_H
#define TOPTHREEPLAYERSDIALOG_H

#include <QDialog>
#include <QString>
#include <iostream>
#include <string>
#include "../gamecenter/playergamehistory.h"

using namespace std;

namespace Ui {
class TopThreePlayersDialog;
}

class TopThreePlayersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TopThreePlayersDialog(QWidget *parent = nullptr);
    ~TopThreePlayersDialog();
     void draw_details();

private:
    Ui::TopThreePlayersDialog *ui;
    QString display;


};

#endif // TOPTHREEPLAYERSDIALOG_H
