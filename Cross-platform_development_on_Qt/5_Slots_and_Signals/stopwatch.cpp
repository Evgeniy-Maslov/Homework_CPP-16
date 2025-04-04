#include "stopwatch.h"
#include <qtimer.h>



Stopwatch::Stopwatch(QObject *parent) : QObject{parent} , timer(new QTimer)
{
    QObject::connect(timer, &QTimer::timeout, this , &Stopwatch::on_timeout);
}

void Stopwatch::start_stopwatch()
{
    timer->start(100);
}

void Stopwatch::stop_stopwatch()
{
    timer->stop();
}

void Stopwatch::reset_stopwatch()
{
    t = QTime(0,0,0,0);
    emit my_Clicked_reset(t);
    n_circle = 0;
    interval = 0;
}

void Stopwatch::on_timeout()
{
    t = t.addMSecs(timer->interval());
    interval += timer->interval();
    emit my_sygnal_setText(t);
}

void Stopwatch::on_new_Circle()
{
    t_circle = t_circle.addMSecs(interval);
    n_circle++;
    QString text = "Круг ";
    text.append(QString::number(n_circle));
    text.append(", время: ");
    text.append(t_circle.toString("hh:mm:ss.zz"));
    emit new_Circle(text);
    interval = 0;
    t_circle = QTime(0,0,0,0);
}

Stopwatch::~Stopwatch()
{
    delete timer;
}

