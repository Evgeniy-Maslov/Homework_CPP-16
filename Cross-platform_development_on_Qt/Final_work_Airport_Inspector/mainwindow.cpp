#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_descriptionConntct->setText("статус подключения к базе данных -");
    ui->lb_statusConnect->setStyleSheet("color:red");
    min.setDate(2016, 8, 15);
    max.setDate(2017, 9, 14);
    LockOrUnlockButtons(status);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDateRange(min, max);
    ui->rb_Arrival->setChecked(true);
    flag_DirectionFlight= true;

    timer = new QTimer();
    dataBase = new DataBase();
    msg = new QMessageBox();
    airportCongestion = new AirportCongestion();
    count_timer = 5;

    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);
    QObject::connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    QObject::connect(timer, &QTimer::timeout, this, [this]{TimerConnectionToDB();});
    QObject::connect(dataBase, &DataBase::sig_SendListAirportsFromDB, this, &MainWindow::ScreenListAirportsFromDB);

    dataBase->ConnectToDataBase();

    QObject::connect(ui->rb_Arrival, &QRadioButton::toggled, this, [&](){flag_DirectionFlight = true;});
    QObject::connect(ui->rb_Departure, &QRadioButton::toggled, this, [&](){flag_DirectionFlight = false;});
    QObject::connect(ui->pb_getListfFights, &QPushButton::clicked, this, [=](){
                airportCode = map_airportCode[ui->cb_Airports->currentText()];
                dateFlight = ui->dateEdit->date().toString(Qt::DateFormat::ISODate);
                if(flag_DirectionFlight)
                    {
                        QString request_ArrivingPlanes = "SELECT flight_no, scheduled_departure, ad.airport_name->>'ru' as \"Name\" "
                                                         "FROM bookings.flights f "
                                                         "JOIN bookings.airports_data ad on ad.airport_code = f.departure_airport "
                                                         "WHERE f.arrival_airport  = '"+ airportCode +"' "
                                                         "AND scheduled_departure::date = date('"+ dateFlight +"') ";

                                                         // "AND to_char(scheduled_arrival, 'DD.MM.YYYY') = '"+ dateFlight +"' ";
                        GetRequestToDatabase(request_ArrivingPlanes, requestFlightSchedule);
                    }
                else{
                        QString request_DepartingPlanes = "SELECT flight_no, scheduled_departure, ad.airport_name->>'ru' as \"Name\" "
                                                          "FROM bookings.flights f "
                                                          "JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport "
                                                          "WHERE f.departure_airport  = '"+ airportCode +"' "
                                                          "AND scheduled_departure::date = date('"+ dateFlight +"') ";

                                                          // "AND to_char(scheduled_departure, 'DD.MM.YYYY') = '"+ dateFlight +"' ";
                        GetRequestToDatabase(request_DepartingPlanes, requestFlightSchedule);
                    }});
    QObject::connect(dataBase, &DataBase::sig_SendFlightSchedule, this, &MainWindow::ScreenTableFlightsFromDB);
    QObject::connect(ui->pb_AirportCongestion, &QPushButton::clicked, this, &MainWindow::RequestGeneralStatisticsForYear);
    QObject::connect(airportCongestion, &AirportCongestion::sig_RequestAirportWorkloadForYear, this, &MainWindow::RequestGeneralStatisticsForYear);
    QObject::connect(this, &MainWindow::SignalSetAirportName, airportCongestion, &AirportCongestion::SetAirportName);
    QObject::connect(dataBase, &DataBase::sig_SendGeneralStatisticsForYear, airportCongestion, &AirportCongestion::ScreenGeneralStatisticsForYear);
    QObject::connect(airportCongestion, &AirportCongestion::sig_RequestAirportWorkloadByMonth, this, &MainWindow::RequestAirportWorkloadByMonth);
    QObject::connect(dataBase, &DataBase::sig_SendAirportWorkloadByMonth, airportCongestion, &AirportCongestion::ParsingDatabase);
}

void MainWindow::TimerConnectionToDB()
{
    --count_timer;
    ui->statusbar->showMessage(QString("Повторное подлючение через %1 секунд").arg(count_timer));
    if(count_timer < 0)
    {
        timer->stop();
        count_timer = 5;
        ui->statusbar->clearMessage();
        dataBase->ConnectToDataBase();
    }
}

void MainWindow::ScreenListAirportsFromDB(QComboBox* listAirports)
{
    ui->cb_Airports->setModel(listAirports->model());

    // ****  создадим словарь кодов аэропортов  ****
    for(int i = 0; i < listAirports->model()->rowCount(); i++){
        map_airportCode[listAirports->model()->data(listAirports->model()->index(i, 0)).toString()] =
            listAirports->model()->data(listAirports->model()->index(i, 1)).toString();
    }
    // **********
    LockOrUnlockButtons(status);
}

void MainWindow::LockOrUnlockButtons(bool status)
{
    ui->rb_Arrival->setEnabled(status);
    ui->rb_Departure->setEnabled(status);
    ui->dateEdit->setEnabled(status);
    ui->pb_getListfFights->setEnabled(status);
    ui->pb_AirportCongestion->setEnabled(status);
}

void MainWindow::ScreenTableFlightsFromDB(QTableView* tableview)
{
    ui->lay_Table->addWidget(tableview);
}


// **** Запрос загруженности аэропорта за год и открытие окна загруженности аэропортов
void MainWindow::RequestGeneralStatisticsForYear()
{
    emit SignalSetAirportName(ui->cb_Airports->currentText());
    airportCode = map_airportCode[ui->cb_Airports->currentText()];
    QString request_GeneralStatisticsForYear = "SELECT count(flight_no), date_trunc('month', scheduled_departure) as \"Month\" "
                                               "FROM bookings.flights f "
                                               "WHERE (scheduled_departure::date > date('2016-08-31') "
                                               "AND scheduled_departure::date <= date('2017-08-31')) "
                                               "AND ( departure_airport = '"+ airportCode +"' or arrival_airport = '"+ airportCode +"') "
                                               "GROUP BY \"Month\" ";
    GetRequestToDatabase(request_GeneralStatisticsForYear, requestGeneralStatisticsForYear);

    airportCongestion->setModal(true);
    airportCongestion->show();
}

// **** запрос загруженности аэропорта по месяцам
void MainWindow::RequestAirportWorkloadByMonth()
{
     QString request_AirportWorkloadByMonth = "SELECT count(flight_no), date_trunc('day', scheduled_departure) as \"Day\" "
                                              "FROM bookings.flights f "
                                              "WHERE(scheduled_departure::date > date('2016-08-31') "
                                              "AND scheduled_departure::date <= date('2017-08-31')) "
                                              "AND ( departure_airport = '"+ airportCode +"' or arrival_airport = '"+ airportCode +"') "
                                              "GROUP BY \"Day\" ";
     GetRequestToDatabase(request_AirportWorkloadByMonth, requestAirportWorkloadByMonth);
}

//**** получение статуса подклячения к базе данных и запрос списка аэропортов
void MainWindow::ReceiveStatusConnectionToDB(bool _status)
{
    status = _status;
    if(status){
        QString request_listAirport = "SELECT airport_name->>'ru' as \"airportName\", airport_code "
                                      "FROM bookings.airports_data";
        GetRequestToDatabase(request_listAirport, requestListAirports);
        ui->lb_statusConnect->setText("Подключено");
        ui->lb_statusConnect->setStyleSheet("color:green");
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        msg->exec();
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        if(msg->button(QMessageBox::Ok))
        {
            timer->setInterval(1000);
            timer->start();
            ui->statusbar->showMessage(QString("Повторное подлючение через %1 секунд").arg(count_timer));
        }
    }
}

void MainWindow::GetRequestToDatabase(QString &request, int requestType)
{
    QSqlError err;
    err = dataBase->RequestToDB(request);
    if(err.isValid( )){
        status = false;
        LockOrUnlockButtons(status);
        msg->setText(err.text());
        msg->exec();
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        if(msg->button(QMessageBox::Ok))
        {
            timer->setInterval(1000);
            timer->start();
            ui->statusbar->showMessage(QString("Повторное подлючение через %1 секунд").arg(count_timer));
        }
    }
    else{
        switch (requestType) {
        case requestListAirports:
        {
            dataBase->ReadAnswerFromDB(request, requestListAirports);
            break;
        }
        case requestFlightSchedule:
        {
            dataBase->ReadAnswerFromDB(request, requestFlightSchedule);
            break;
        }
        case requestGeneralStatisticsForYear:
        {
            dataBase->ReadAnswerFromDB(request, requestGeneralStatisticsForYear);
            break;
        }
        case requestAirportWorkloadByMonth:
        {
            dataBase->ReadAnswerFromDB(request, requestAirportWorkloadByMonth);
        }
        default:
            break;
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataBase;
    delete timer;
}
