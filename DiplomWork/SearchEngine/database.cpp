#include "database.h"

DataBase::DataBase(QString data, QObject *parent)
    : QObject{parent}, pathSettingsFileINI(data)
{
    SetDataForConnect();
    dataBase = new QSqlDatabase();
    simpleQuery = new QSqlQuery();
    AddDataBase(POSTGRE_DRIVER, dataForConnect[dbName]);
}

DataBase::~DataBase()
{
    delete dataBase;
    delete simpleQuery;
    delete queryModel_AllWords;
    delete queryModel_FoundDocuments;
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
    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
    queryModel_AllWords = new QSqlQueryModel();
    queryModel_FoundDocuments = new QSqlQueryModel();
}


void DataBase::ConnectToDataBase()
{
    dataBase->setHostName(dataForConnect[hostName]);
    dataBase->setDatabaseName(dataForConnect[dbName]);
    dataBase->setUserName(dataForConnect[login]);
    dataBase->setPassword(dataForConnect[password]);
    dataBase->setPort(dataForConnect[port].toInt());

    bool statusOpen;
    statusOpen = dataBase->open();
    if(!statusOpen) {
        qWarning() << "not OPEN" << dataForConnect[dbName];
    }
    else
        qWarning() << "OPEN" << dataForConnect[dbName];

    emit sig_SendStatusConnection(statusOpen);
}

void DataBase::DisconnectFromDataBase()
{
    //Сначала выбираем имя БД
    *dataBase = QSqlDatabase::database(dataForConnect[dbName]);
    //Метод close() закрывает соединение с БД
    dataBase->close();
}

QSqlError DataBase::RequestToDB(QString request)
{
    *simpleQuery = QSqlQuery(*dataBase);
    simpleQuery->exec(request);
    return simpleQuery->lastError();
}

void DataBase::ReadAnswerFromDB(QString &request, int requestType)
{
    switch (requestType)
    {
        case requestTypeAllWords:
        {
            queryModel_AllWords->setQuery(request, *dataBase);
            emit sig_SendDataAllWords(queryModel_AllWords);
            break;
        }
        case requestTypeSearchWord:
        {
            emit sig_SendDataSearchWord(simpleQuery);
            break;
        }
        case requestFoundDocuments:
        {
            queryModel_FoundDocuments->setQuery(request, *dataBase);
            emit sig_SendDataFoundDocuments(queryModel_FoundDocuments);
            break;
        }
    }
}
/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

QStringList DataBase::GetTableHeaders()
{
    return tableHeaders;
}
