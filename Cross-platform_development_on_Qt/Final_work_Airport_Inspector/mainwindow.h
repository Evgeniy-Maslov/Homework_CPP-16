#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "airportcongestion.h"
#include "database.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <qdatetime.h>
#include <qtimer.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

Q_SIGNALS:
    void SignalTimerConnectionToDB();
    void SignalSetAirportName(QString name);

public Q_SLOTS:
    void ReceiveStatusConnectionToDB(bool status);


private Q_SLOTS:
    void ScreenListAirportsFromDB(QComboBox* comboBox);
    void ScreenTableFlightsFromDB(QTableView* tableview);
    void RequestGeneralStatisticsForYear();
    void RequestAirportWorkloadByMonth();


private:
    void TimerConnectionToDB();
    void GetRequestToDatabase(QString &request, int requestType);
    void LockOrUnlockButtons(bool _status);


    Ui::MainWindow *ui;
    AirportCongestion* airportCongestion;
    DataBase* dataBase;
    QMessageBox* msg;
    QTimer *timer;
    int count_timer;
    QMap<QString, QString> map_airportCode;
    QString airportCode;
    QString dateFlight;
    bool status = false;
    bool  flag_DirectionFlight;
    QDate min;
    QDate max;

};
#endif // MAINWINDOW_H
