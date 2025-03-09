#include <QApplication>
#include <qmessagebox.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // i = 0;
    QMessageBox msg;
    msg.setText("Hello Graphic World!");
    msg.setWindowTitle("First app");
    msg.setIcon(QMessageBox::Information);
    msg.setStyleSheet("color : green");
    msg.show();



    return a.exec();
}
