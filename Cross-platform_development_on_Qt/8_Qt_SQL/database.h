#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlTableModel>
#include <qsqldatabase.h>
#include <qsqlerror.h>



#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"
#define TABLE_NAME "film"

//Количество полей данных необходимых для подключения к БД
#define NUM_DATA_FOR_CONNECT_TO_DB 5

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

//Типы запросов
enum requestType{

    requestAllFilms = 1,
    requestComedy   = 2,
    requestHorrors  = 3

};



class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    QSqlError RequestToDB(QString request);
    QSqlError GetLastError(void);
    void ConnectToDataBase(QVector<QString> dataForConnect);
    void ReadAnswerFromDB(QString &request, int answerType );

signals:

    void sig_SendDataFromDB(QTableView *widget, int typeR);
    void sig_SendDataFromDB_select(QSqlQueryModel *model, int typeR);
    void sig_SendStatusConnection(bool);

private slots:
    // void RequestToDB(QString request);

private:

    QSqlDatabase* dataBase;
    QSqlQuery* simpleQuery;
    QSqlTableModel *table_model;
    QSqlQueryModel *query_model;
    QTableView *table_widget;
};

#endif // DATABASE_H
