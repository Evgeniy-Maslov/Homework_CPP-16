#include "database.h"
#include <qsqlrecord.h>

DataBase::DataBase(QString data, QObject *parent)
    : QObject{parent}, pathSettingsFileINI(data)
{
    SetDataForConnect();
    //Объект QSqlDatabase является основным классом низкого уровня,
    //в котором настраивается подключение к БД.
    dataBase = new QSqlDatabase();

    //Объект QSqlQuery отвечает за формирование запросов к БД
    simpleQuery = new QSqlQuery();

    AddDataBase(POSTGRE_DRIVER, dataForConnect[dbName]);
    ConnectToDataBase(dataForConnect);
    QSqlError err = RequestToDB(requestCREATE_TABLE);
    if(err.isValid( )){
        qDebug("RequestToDB ERROR");
    }
}

DataBase::~DataBase()
{
    delete dataBase;
    delete simpleQuery;
}

void DataBase::SetDataForConnect()
{
    QSettings settingsPostgreSQL(pathSettingsFileINI, QSettings::IniFormat);
    QStringList nameSQLconnectionSettings = {"hostName",
                                             "dbName",
                                             "login",
                                             "password",
                                             "port"};
    settingsPostgreSQL.beginGroup("CONNECT");
    foreach (auto& var, nameSQLconnectionSettings) {
        dataForConnect.push_back(settingsPostgreSQL.value(var).toString());
    }
    settingsPostgreSQL.endGroup();
}

void DataBase::AddDataBase(QString driver, QString nameDB)
{
    /*  Класс QSqlDatabase представляет из себя интерфейс между
        кодом и БД. Он организует соединение с БД. Для подключения
        в конструктор класса необходимо передать драйвер БД и имя.
        В объекте может храниться несколько подключений, они различаются именами.
    */

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}


void DataBase::ConnectToDataBase(QVector<QString> data)
{
    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[password]);
    dataBase->setPort(data[port].toInt());

    bool statusOpen;
    statusOpen = dataBase->open();
    if(!statusOpen)
    {
        qWarning() << "not OPEN" << dataForConnect[dbName];
    }
    else
        qWarning() << "OPEN" << dataForConnect[dbName];
}

void DataBase::DisconnectFromDataBase(QString nameDb)
{
    //Сначала выбираем имя БД
    *dataBase = QSqlDatabase::database(nameDb);
    //Метод close() закрывает соединение с БД
    dataBase->close();

}

QSqlError DataBase::RequestToDB(QString request)
{
    *simpleQuery = QSqlQuery(*dataBase);
    simpleQuery->exec(request);
    return simpleQuery->lastError( );
}

bool DataBase::CheckingMatchValue(QString nameTable, QString nameColumn, QString value)
{
    bool flag = false;
    QString requestChecking = QString("SELECT %1 FROM %2 WHERE %1 = '%3';").arg(nameColumn,
                                                                                nameTable,
                                                                                value);
    QSqlError err = RequestToDB(requestChecking);
    if(err.isValid()){
        qDebug() << QString("requestChecking %1 ERROR").arg(nameColumn); //<< "requestChecking "+ nameColumn +" ERROR";
    }
    while (simpleQuery->next()) {
        flag = true;
    }
    return flag;
}

 QStringList DataBase::GetTableHeaders()
{
     return tableHeaders;
}

void DataBase::RequestINSERT(QString nameTable, QString nameColumn, QString value)
{
    QString requestInsert = QString("INSERT INTO %1 (%2) VALUES ('%3');").arg(nameTable,
                                                                              nameColumn,
                                                                              value);
    QSqlError err = RequestToDB(requestInsert);
    if(err.isValid()){
        qDebug() << QString("requestINSERT ""%1 - %2"" ERROR.").arg(nameColumn, value);
    }
}
