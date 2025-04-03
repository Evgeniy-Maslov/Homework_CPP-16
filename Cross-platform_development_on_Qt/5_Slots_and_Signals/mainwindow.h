#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "stopwatch.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(/*Stopwatch& m_stop_watch,*/ QWidget *parent = nullptr);
    ~MainWindow();

Q_SIGNALS:
    void my_clicked_start();
    void my_clicked_stop();

private Q_SLOTS:
    void onClicked();

private:
    Ui::MainWindow *ui;
    Stopwatch* stop_watch;

};
#endif // MAINWINDOW_H
