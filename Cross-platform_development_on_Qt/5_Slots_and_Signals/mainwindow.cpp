#include "mainwindow.h"
#include "stopwatch.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(/*Stopwatch& m_stop_watch, */QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stop_watch = new Stopwatch(*ui);
    ui->setupUi(this);
    QFont font("Start", 26, QFont::AbsoluteSpacing);
    ui->label->setFont(font);
    ui->label->setText(QTime(0,0,0,0).toString("hh:mm:ss.z"));
    ui->pushButton->setText("Старт");
    QObject::connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::onClicked);
    ui->pushButton_2->setText("Очистить");
    QObject::connect(ui->pushButton_2, &QPushButton::pressed, stop_watch, &Stopwatch::my_Clicked_reset);
    ui->pushButton_3->setText("Круг");
    ui->pushButton_3->setEnabled(false);
    ui->textBrowser->forward();
    QObject::connect(ui->pushButton_3, &QPushButton::pressed, stop_watch, &Stopwatch::new_Circle);
}

void MainWindow::onClicked()
{
    if(ui->pushButton->text() == "Старт")
    {
        QObject::connect(this, &MainWindow::my_clicked_start, stop_watch, &Stopwatch::my_sygnal_start);
        emit my_clicked_start();
        ui->pushButton->setText("Стоп");
        ui->pushButton_3->setEnabled(true);
    }
    else
    {
        QObject::connect(this, &MainWindow::my_clicked_stop, stop_watch, &Stopwatch::my_sygnal_stop);
        emit my_clicked_stop();
        ui->pushButton->setText("Старт");
        ui->pushButton_3->setEnabled(false);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete stop_watch;
}
