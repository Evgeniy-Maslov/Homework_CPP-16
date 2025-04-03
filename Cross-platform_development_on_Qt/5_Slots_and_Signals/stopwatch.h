#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "ui_mainwindow.h"
#include <QObject>

#include <qdatetime.h>
#include <qtimer.h>



class Stopwatch : public QObject
{
    Q_OBJECT
public:
    Stopwatch(Ui::MainWindow& m_ui, QObject *parent = nullptr);
    ~Stopwatch();

private:
    QTimer *timer;
    QTime t = QTime(0, 0, 0, 0);
    QTime t_circle = QTime(0, 0, 0, 0);
    int n_circle{};
    int interval{};
    Ui::MainWindow *M_ui = nullptr;

private Q_SLOTS:
    void start_stopwatch();
    void stop_stopwatch();
    void reset_stopwatch();
    void on_timeout();
    void on_new_Circle();


Q_SIGNALS:
    void my_sygnal_start();
    void my_sygnal_stop();
    void my_Clicked_reset();
    void my_sygnal_setText();
    void new_Circle();


};

#endif // STOPWATCH_H
