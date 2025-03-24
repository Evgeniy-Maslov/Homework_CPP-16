#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Color selection");
    ui->radioButton->setText("RED");
    ui->radioButton_2->setText("YELLOW");
    ui->radioButton_3-> setText("GREEN");
    ui->groupBox_2->setTitle("Assortment of elements");
    ui->label->setText("ComboBox");
    ui->label_2->setText("ProgressBar");
    ui->comboBox->addItem("the first line of the list.");
    ui->comboBox->addItem("the second line of the list.");
    ui->comboBox->addItem("the third line of the list.");
    ui->comboBox->addItem("the fourth line of the list.");
    ui->comboBox->addItem("the fifth line of the list.");
    ui->pushButton->setText("next step ProgressBar");
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setText("Exit");
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);
    // ui->progressBar->setFormat("%p");
    ui->progressBar->setValue(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
