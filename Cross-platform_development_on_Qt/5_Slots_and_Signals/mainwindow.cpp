#include "mainwindow.h"
#include "stopwatch.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stop_watch = new Stopwatch();
    ui->setupUi(this);
    QFont font("Start", 26, QFont::AbsoluteSpacing);
    ui->label->setFont(font);
    ui->label->setText("00:00:00.0");
    ui->pushButton->setText("Старт");
    QObject::connect(ui->pushButton, &QPushButton::pressed, this, [this](){onClicked();});
    ui->pushButton_2->setText("Очистить");
    QObject::connect(ui->pushButton_2, &QPushButton::pressed, this, [this](){stop_watch->reset_stopwatch();});
    ui->pushButton_3->setText("Круг");
    ui->pushButton_3->setEnabled(false);
    ui->textBrowser->forward();
    QObject::connect(ui->pushButton_3, &QPushButton::pressed, this, [this](){stop_watch->on_new_Circle();});
    QObject::connect(stop_watch, &Stopwatch::my_sygnal_setText, this, &MainWindow::on_setText);
    QObject::connect(stop_watch, &Stopwatch::my_Clicked_reset, this, &MainWindow::on_reset);
    QObject::connect(stop_watch, &Stopwatch::new_Circle, this, &MainWindow::on_set_textBrowser);
}

void MainWindow::on_reset(QTime& t)
{
    ui->label->setText(t.toString("hh:mm:ss.zz"));
    ui->textBrowser->clear();
}

void MainWindow::on_setText(QTime& t)
{
    ui->label->setText(t.toString("hh:mm:ss.zz"));
}

void MainWindow::on_set_textBrowser(QString& text)
{
    ui->textBrowser->append(text);
}

void MainWindow::onClicked()
{
    if(ui->pushButton->text() == "Старт")
    {
        QObject::connect(this, &MainWindow::my_clicked_start, this, [this](){stop_watch->start_stopwatch();});
        emit my_clicked_start();
        ui->pushButton->setText("Стоп");
        ui->pushButton_3->setEnabled(true);
    }
    else
    {
        QObject::connect(this, &MainWindow::my_clicked_stop, this, [this](){stop_watch->stop_stopwatch();});
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
