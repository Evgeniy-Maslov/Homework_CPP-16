#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlQueryModel>
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

//Типы запросов
enum requestType{
    requestTypeAllWords = 0,
    requestTypeSearchWord,
    requestFoundDocuments
};

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
    void DisconnectFromDataBase();
    QSqlError GetLastError(void);
    void ConnectToDataBase();
    void ReadAnswerFromDB(QString &request, int answerType );
    bool CheckingMatchValue(QString request);
    QStringList GetTableHeaders();
    QSqlError RequestToDB(QString request);


Q_SIGNALS:
    void sig_SendStatusConnection(bool status);
    void sig_SendDataAllWords(QSqlQueryModel* queryModel);
    void sig_SendDataSearchWord(QSqlQuery* simpleQuery);
    void sig_SendDataFoundDocuments(QSqlQueryModel* queryModel);

private Q_SLOTS:


private:
    QString pathSettingsFileINI;
    QSqlDatabase* dataBase;
    QSqlQuery* simpleQuery;
    QSqlQueryModel* queryModel_AllWords;
    QSqlQueryModel* queryModel_FoundDocuments;
    QStringList dataForConnect;
    QStringList tableHeaders = {"documents",
                                "name_document",
                                "words",
                                "name_word",
                                "documents_words",
                                "word_counter"};

};

#endif // DATABASE_H
