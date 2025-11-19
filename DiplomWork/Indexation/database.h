#ifndef DATABASE_H
#define DATABASE_H

// #include <QTableWidget>
#include <QObject>
#include <QSqlTableModel>
#include <qsqldatabase.h>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <QDebug>
#include <QSettings>

#define POSTGRE_DRIVER "QPSQL"

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    password = 3,
    port = 4
};

// //Типы запросов
// enum requestType{

//     requestCreateTable = 1
//     // requestComedy   = 2,
//     // requestHorrors  = 3

// };

// Перечисление названий таблиц и колонок в БАЗЕ ДАННЫХ
enum namesTablesAndColumns{
    nameTableDocuments = 0,
    nameColumnDocuments,
    nameTableWords,
    nameColumnWords,
    nameTableNumberOfWords,
    nameColumnNumberOfWords
};

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QString data, QObject *parent = nullptr);
    ~DataBase();

    void SetDataForConnect();
    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void ConnectToDataBase(QStringList dataForConnect);
    bool CheckingMatchValue(QString nameTable, QString nameColumn, QString value);
    QStringList GetTableHeaders();
    void RequestINSERT(QString nameTable, QString nameColumn, QString value);

private:
    QSqlError RequestToDB(QString request);


Q_SIGNALS:

private Q_SLOTS:


private:
    QString pathSettingsFileINI;
    QSqlDatabase* dataBase;
    QSqlQuery* simpleQuery;
    QStringList dataForConnect;
    QStringList tableHeaders = {"documents",
                                "name_document",
                                "words",
                                "name_word",
                                "documents_words",
                                "word_counter"};

    QString requestCREATE_TABLE = QString("CREATE TABLE IF NOT EXISTS %1(%2 VARCHAR(60) PRIMARY KEY); "
                                          "CREATE TABLE IF NOT EXISTS %3(%4 VARCHAR(60) PRIMARY KEY); "
                                          "CREATE TABLE IF NOT EXISTS %5(%2 VARCHAR(60) REFERENCES %1 ON DELETE CASCADE, "
                                          "%4 VARCHAR(60) REFERENCES %3 ON DELETE CASCADE, "
                                          "PRIMARY KEY (%2, %4), "
                                          "%6 INTEGER NOT NULL);").arg(tableHeaders[nameTableDocuments],      // 1
                                                                       tableHeaders[nameColumnDocuments],     // 2
                                                                       tableHeaders[nameTableWords],          // 3
                                                                       tableHeaders[nameColumnWords],         // 4
                                                                       tableHeaders[nameTableNumberOfWords],  // 5
                                                                       tableHeaders[nameColumnNumberOfWords]);// 6
};

#endif // DATABASE_H
