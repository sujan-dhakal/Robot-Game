#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include <QString>
#include <iostream>
#include <string>
#include "../gamecenter/playergamehistory.h"

using namespace std;


namespace Ui {
class StatsDialog;
}

class StatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatsDialog(QWidget *parent = nullptr);
    ~StatsDialog();
    void draw_details();

private:
    Ui::StatsDialog *ui;
    QString display;
};

#endif // STATSDIALOG_H
