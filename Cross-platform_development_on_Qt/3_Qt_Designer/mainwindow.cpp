#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_1, &QPushButton::clicked, onClick_Ok);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, [=](){this->close();});
}
MainWindow::~MainWindow()
{
    delete ui;
}
void onClick_Ok()
{
    Dialog *dialog = new Dialog();
    dialog->show();
}
