#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <qcombobox.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qtablewidget.h>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

//Типы запросов
enum requestType{

    requestListAirports = 0,                // запрос на списокк аэропортов
    requestFlightSchedule,                  // запрос на расписание рейсов
    requestGeneralStatisticsForYear,        // Запрос общей статистики за год
    requestAirportWorkloadByMonth           // запрос полетов по месяцм

};


class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void ReadAnswerFromDB(QString &request, int requestType);
    QSqlError RequestToDB(QString request);
    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase();
    void ConnectToDataBase();
    void DisconnectFromDataBase(QString nameDb);
    QSqlError GetLastError(void);

Q_SIGNALS:
    void sig_SendStatusConnection(bool status);
    void sig_SendListAirportsFromDB(QComboBox* comboBox);
    void sig_SendFlightSchedule(QTableView* tableView);
    void sig_SendGeneralStatisticsForYear(QSqlQueryModel* queryModel);
    void sig_SendAirportWorkloadByMonth(QSqlQueryModel* queryModel);

private Q_SLOTS:


private:
    QSqlDatabase* dataBase;
    QSqlQuery* simpleQuery;
    QComboBox* listAirports;
    QTableView* tableView;
    QSqlTableModel *table_model;
    QSqlQueryModel* queryModel_listAirports;
    QSqlQueryModel* queryModel_FlightSchedule;
    QSqlQueryModel* queryModel_StatisticsForYear;
    QSqlQueryModel* queryModel_AirportWorkloadByMonth;
};

#endif // DATABASE_H
