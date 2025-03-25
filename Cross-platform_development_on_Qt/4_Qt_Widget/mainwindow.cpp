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
    ui->progressBar->setRange(0, 10);
    ui->progressBar->setValue(0);

    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, [=](){close();});
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, [=](){MainWindow::onClicked();});
}
void MainWindow::onClicked()
{
    if(ui->pushButton->isChecked())
    {
        (count == 10) ? ui->progressBar->setValue(count = 0) : ui->progressBar->setValue(++count);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
