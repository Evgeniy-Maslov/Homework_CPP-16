#include "database.h"
#include <qtimer.h>

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    dataBase = new QSqlDatabase();
    simpleQuery = new QSqlQuery();
    listAirports = new QComboBox();
    tableView = new QTableView();
}

void DataBase::AddDataBase(QString driver, QString nameDB)
{
    *dataBase = QSqlDatabase::addDatabase(POSTGRE_DRIVER, DB_NAME);
    table_model = new QSqlTableModel(this, *dataBase);
    queryModel_FlightSchedule = new QSqlQueryModel();
    queryModel_listAirports = new QSqlQueryModel();
    queryModel_StatisticsForYear = new QSqlQueryModel();
    queryModel_AirportWorkloadByMonth = new QSqlQueryModel();
}

void DataBase::ReadAnswerFromDB(QString &request, int requestType)
{
    switch (requestType)
    {
    case requestListAirports:
    {
        queryModel_listAirports->setQuery(request, *dataBase);
        listAirports->setModel(queryModel_listAirports);
        emit sig_SendListAirportsFromDB(listAirports);
        break;
    }
    case requestFlightSchedule:
    {
        queryModel_FlightSchedule->setQuery(request, *dataBase);
        tableView->setModel(queryModel_FlightSchedule);
        emit sig_SendFlightSchedule(tableView);
        break;
    }
    case requestGeneralStatisticsForYear:
    {
        queryModel_StatisticsForYear->setQuery(request, *dataBase);
        emit sig_SendGeneralStatisticsForYear(queryModel_StatisticsForYear);
        break;
    }
    case requestAirportWorkloadByMonth:
    {
        queryModel_AirportWorkloadByMonth->setQuery(request, *dataBase);
        emit sig_SendAirportWorkloadByMonth(queryModel_AirportWorkloadByMonth);
        break;
    }
    default:
    {
        break;
    }
    }
}

QSqlError DataBase::RequestToDB(QString request)
{
    *simpleQuery = QSqlQuery(*dataBase);
    simpleQuery->exec(request);
    return simpleQuery->lastError( );
}

void DataBase::ConnectToDataBase()
{

    dataBase->setHostName("981757-ca08998.tmweb.ru");
    dataBase->setDatabaseName("demo");
    dataBase->setUserName("netology_usr_cpp");
    dataBase->setPassword("CppNeto3");
    dataBase->setPort(5432);
    bool status = false;
    status = dataBase->open();
    emit sig_SendStatusConnection(status);
}

void DataBase::DisconnectFromDataBase(QString nameDb)
{
    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();
}

QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

DataBase::~DataBase()
{
    DisconnectFromDataBase(DB_NAME);
    delete dataBase;
    delete simpleQuery;
    delete listAirports;
    delete tableView;
    delete table_model;
    delete queryModel_FlightSchedule;
    delete queryModel_listAirports;
    delete queryModel_StatisticsForYear;
}
