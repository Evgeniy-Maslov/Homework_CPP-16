#include "database.h"
#include <qsqlquery.h>

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    //Объект QSqlDatabase является основным классом низкого уровня,
    //в котором настраивается подключение к БД.
    dataBase = new QSqlDatabase();

    //Объект QSqlQuery отвечает за формирование запросов к БД
    simpleQuery = new QSqlQuery();

    table_widget = new QTableView();

}

DataBase::~DataBase()
{
    delete dataBase;
    delete table_model;
    delete query_model;
    delete table_widget;
    delete simpleQuery;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{    
    /*  Класс QSqlDatabase представляет из себя интерфейс между
        кодом и БД. Он организует соединение с БД. Для подключения
        в конструктор класса необходимо передать драйвер БД и имя.
        В объекте может храниться несколько подключений, они различаются именами.
    */

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
    table_model = new QSqlTableModel(this, *dataBase);
    query_model = new QSqlQueryModel();
}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    ///Тут должен быть код ДЗ

    bool status;
    status = dataBase->open();
    emit sig_SendStatusConnection(status);
}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{
    //Сначала выбираем имя БД
    *dataBase = QSqlDatabase::database(nameDb);

    //Метод close() закрывает соединение с БД
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
QSqlError DataBase::RequestToDB(QString request)
{
    ///Тут должен быть код ДЗ

    /*  Для фоомирования запроса будем использовать
     *  объект QSqlQuery.
     *  В конструктор передадим адрес объекта QSqlDatabase
    */
    *simpleQuery = QSqlQuery(*dataBase);
    /*
       Выполнение запроса выполняется при помощи
       метода exec. В случае успешного запроса он вернет true.
       Если возникает какая либо ошибка, ее можно посмотреть
       при помощи метода lastError. Этот метод возвращает
       экземпляр класса QSqlError.
    */

    simpleQuery->exec(request);
    return simpleQuery->lastError( );
}

void DataBase::ReadAnswerFromDB(QString &request, int requestType)
{
    /*
     * Используем оператор switch для разделения запросов
    */
    switch (requestType)
    {
        case requestAllFilms:
        {
            table_model->setTable(TABLE_NAME);
            table_model->select();
            table_widget->setModel(table_model);
            emit sig_SendDataFromDB(table_widget, requestType);
            break;
        }
        default:
        {
            query_model->setQuery(request, *dataBase);
            table_widget->setModel(query_model);
            emit sig_SendDataFromDB(table_widget, requestType);
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
