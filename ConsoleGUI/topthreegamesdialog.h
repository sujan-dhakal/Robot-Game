#ifndef TOPTHREEGAMESDIALOG_H
#define TOPTHREEGAMESDIALOG_H

#include <QDialog>
#include "../gamecenter/playergamehistory.h"
#include "../gamecenter/game.h"
#include <algorithm>

namespace Ui {
class Topthreegamesdialog;
}

class Topthreegamesdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Topthreegamesdialog(QWidget *parent = nullptr);
    ~Topthreegamesdialog();
    void show_top_games();

private:
    Ui::Topthreegamesdialog *ui;
    QString display;
};

#endif // TOPTHREEGAMESDIALOG_H
