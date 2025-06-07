#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);
    QObject::connect(udpWorker, &UDPworker::sig_sendInfoToGUI, this, &MainWindow::DisplayDatagram);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;
        bool x = true;
        udpWorker->SendDatagram(dataToSend, x);
        timer->start(TIMER_DELAY);
    });

    QObject::connect(ui->pb_send_data, &QPushButton::clicked, this, [&]{
        QString user_data = ui->le_text_input->displayText();
        QByteArray user_dataToSend;
        QDataStream outStr(&user_dataToSend, QIODevice::WriteOnly);

        outStr << user_data;
        bool x = false;
        udpWorker->SendDatagram(user_dataToSend, x);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}

void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + data.toString() + ". "
                        "Принято пакетов " + QString::number(counterPck));
}

void MainWindow::DisplayDatagram(QString data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Принято сообщение: \"" + data + "\". от " + udpWorker->get_localAddress().toString() +
                          // " " + QString::number(udpWorker->get_localHost()) +
                          ", размер сообщения " + QString::number(udpWorker->get_DatagramSize()));
}

void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}
