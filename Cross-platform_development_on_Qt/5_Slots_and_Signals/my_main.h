#ifndef MY_MAIN_H
#define MY_MAIN_H

#include "mainwindow.h"
#include "stopwatch.h"
#include <QObject>


class My_main : public QObject
{
    Q_OBJECT
public:
    explicit My_main(QObject *parent = nullptr);
    void start_main_window();

private:
    MainWindow main_window;
    Stopwatch stop_watcch;


Q_SIGNALS:
    void my_clicked_start();
};

#endif // MY_MAIN_H
