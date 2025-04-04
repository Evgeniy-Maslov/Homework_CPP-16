#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "stopwatch.h"
#include <QMainWindow>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void onClicked();
    Ui::MainWindow *ui;
    Stopwatch* stop_watch;

public:
    MainWindow(/*Stopwatch& m_stop_watch,*/ QWidget *parent = nullptr);
    ~MainWindow();

Q_SIGNALS:
    void my_clicked_start();
    void my_clicked_stop();

private Q_SLOTS:
    void on_setText(QTime& t);
    void on_set_textBrowser(QString& text);
    void on_reset(QTime& t);

};
#endif // MAINWINDOW_H
