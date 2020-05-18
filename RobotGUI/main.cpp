#include "robotgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    robotgui r;
    r.show();

    return a.exec();
}
