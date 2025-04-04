#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>

#include <qdatetime.h>
#include <qtimer.h>



class Stopwatch : public QObject
{
    Q_OBJECT

    QTimer *timer;
    QTime t = QTime(0, 0, 0, 0);
    QTime t_circle = QTime(0, 0, 0, 0);
    int n_circle{};
    int interval{};

public:
    Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    void start_stopwatch();
    void stop_stopwatch();
    void reset_stopwatch();
    void on_timeout();
    void on_new_Circle();

Q_SIGNALS:
    void my_Clicked_reset(QTime& t);
    void my_sygnal_setText(QTime& t);
    void new_Circle(QString& text);
};

#endif // STOPWATCH_H
