#include <QCoreApplication>
#include <QTcpSocket>
#include <QSqlTableModel>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket socket;

    QSqlTableModel Tmod;


    return a.exec();
}


