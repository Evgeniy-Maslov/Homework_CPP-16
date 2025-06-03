#include "dialog.h"
#include "database.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText("Host Name");
    ui->label_5->setText("DB Name");
    ui->label_4->setText("Login");
    ui->label_2->setText("Password");
    ui->label_3->setText("Port");
    ui->spinBox->setMaximum(65535);

    ui->lineEdit->setText("981757-ca08998.tmweb.ru");
    ui->lineEdit_3->setText("netology_cpp");
    ui->lineEdit_4->setText("netology_usr_cpp");
    ui->lineEdit_2->setText("CppNeto3");
    ui->spinBox->setValue(5432);

    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{

    //Добавляем данные в контейнер и передаем в главное окно
    data[hostName] = ui->lineEdit->text();
    data[dbName] = ui->lineEdit_3->text();
    data[login] = ui->lineEdit_4->text();
    data[pass] = ui->lineEdit_2->text();
    data[port] = ui->spinBox->text();

    emit sig_sendData(data);

}
