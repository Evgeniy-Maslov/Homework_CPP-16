#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Исходное состояние виджетов
    ui->setupUi(this);
    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_request->setEnabled(false);

    /*
     * Выделим память под необходимые объекты. Все они наследники
     * QObject, поэтому воспользуемся иерархией.
    */

    dataDb = new Dialog(this);
    dataBase = new DataBase(this);
    tableView = new QTableView();
    msg = new QMessageBox(this);

    // ui->lay_Table->addWidget(tableView);

    /*
     * Добавим БД используя стандартный драйвер PSQL и зададим имя.
    */
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    /*
     * Устанавливаем данные для подключениея к БД.
     * Поскольку метод небольшой используем лямбда-функцию.
     */
    connect(dataDb, &Dialog::sig_sendData, this, [&](QVector<QString> receivData){
                                                            dataForConnect = receivData; });

    /*
     * Соединяем сигнал, который передает ответ от БД с методом, который отображает ответ в ПИ
     */
     connect(dataBase, &DataBase::sig_SendDataFromDB, this, &MainWindow::ScreenDataFromDB);

    /*
     *  Сигнал для подключения к БД
     */
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);

    QObject::connect(ui->pb_clear, &QPushButton::clicked, this, [=](){tableView->setModel(0);});
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataBase;
}

/*!
 * @brief Слот отображает форму для ввода данных подключения к БД
 */
void MainWindow::on_act_addData_triggered()
{
    //Отобразим диалоговое окно. Какой метод нужно использовать?
    dataDb->show();
}

/*!
 * @brief Слот выполняет подключение к БД. И отображает ошибки.
 */

void MainWindow::on_act_connect_triggered()
{
    /*
     * Обработчик кнопки у нас должен подключаться и отключаться от БД.
     * Можно привязаться к надписи лейбла статуса. Если он равен
     * "Отключено" мы осуществляем подключение, если "Подключено" то
     * отключаемся
    */

    if(ui->lb_statusConnect->text() == "Отключено"){
       ui->lb_statusConnect->setText("Подключение");
       ui->lb_statusConnect->setStyleSheet("color : black");
       auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};
       auto res = QtConcurrent::run(conn);
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }

}

/*!
 * \brief Обработчик кнопки "Получить"
 */
void MainWindow::on_pb_request_clicked()
{
    ///Тут должен быть код ДЗ
    tableView->setModel(0);
    QSqlError err;
    err = dataBase->RequestToDB(request);
    if(err.isValid( )){
        msg->setText(err.text());
        msg->exec( );
    }
    else{
        QString my_request;
        switch (ui->cb_category->currentIndex() + 1) {
        case requestAllFilms:
            // my_request = request;
            break;
        case requestComedy:
            my_request = request_comedy;
            break;
        case requestHorrors:
            my_request = request_horrors;
            break;
        default:
            break;
        }
        dataBase->ReadAnswerFromDB(my_request, ui->cb_category->currentIndex() + 1);
    }
}

/*!
 * \brief Слот отображает значение в QTableWidget
 * \param widget
 * \param typeRequest
 */
void MainWindow::ScreenDataFromDB(QTableView *widget, int typeRequest)
{

    ///Тут должен быть код ДЗ
    tableView = widget;
    switch (typeRequest) {
    case requestAllFilms:{
        QString name_colum;
        int iCols = tableView->model()->columnCount();
        for(int i = 0; i < iCols; i++)
        {
            name_colum = tableView->model()->headerData(i, Qt::Horizontal).toString();
            if(name_colum == "title" or name_colum == "description")
            {
                continue;
            }
            else
                tableView->hideColumn(i);
        }
        break;
    }
    default:
        break;
    }
    ui->lay_Table->addWidget(tableView);
}
/*!
 * \brief Метод изменяет стотояние формы в зависимости от статуса подключения к БД
 * \param status
 */
void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        msg->exec();
    }

}



