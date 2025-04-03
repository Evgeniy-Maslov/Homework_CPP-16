#include "mainwindow.h"
#include <qtimer.h>

Stopwatch::Stopwatch(Ui::MainWindow &m_ui, QObject *parent) : QObject{parent} , timer(new QTimer)
{
    M_ui = &m_ui;
    QObject::connect(timer, &QTimer::timeout, this , &Stopwatch::on_timeout);
    QObject::connect(this, &Stopwatch::my_sygnal_start, this, &Stopwatch::start_stopwatch);
    QObject::connect(this, &Stopwatch::my_sygnal_stop, this, &Stopwatch::stop_stopwatch);
    QObject::connect(this, &Stopwatch::my_Clicked_reset, this, &Stopwatch::reset_stopwatch);
    QObject::connect(this, &Stopwatch::my_Clicked_reset, this, &Stopwatch::reset_stopwatch);
    QObject::connect(this, &Stopwatch::new_Circle, this, &Stopwatch::on_new_Circle);
    QObject::connect(this, &Stopwatch::my_sygnal_stop, this, &Stopwatch::on_new_Circle);
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
    M_ui->label->setText(t.toString("hh:mm:ss.zz"));
    M_ui->textBrowser->clear();
    n_circle = 0;
    interval = 0;
}

void Stopwatch::on_timeout()
{
    t = t.addMSecs(timer->interval());
    interval += timer->interval();
    emit my_sygnal_setText();
    QObject::connect(this, &Stopwatch::my_sygnal_setText, [=](){
        M_ui->label->setText(t.toString("hh:mm:ss.zz"));
    });
    M_ui->textBrowser->clearHistory();
}

void Stopwatch::on_new_Circle()
{
    t_circle = t_circle.addMSecs(interval);
    n_circle++;
    QString text = "Круг ";
    text.append(QString::number(n_circle));
    text.append(", время: ");
    text.append(t_circle.toString("hh:mm:ss.zz"));
    M_ui->textBrowser->append(text);
    interval = 0;
    t_circle = QTime(0,0,0,0);
}

Stopwatch::~Stopwatch()
{
    delete timer;
    delete M_ui;
}

