#include "mainwindow.h"
#include <QApplication>
#include "database.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow Mwin;
    Mwin.show();




    return a.exec();
}
