#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include "database.h"
#include "dialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void ScreenDataFromDB(QTableView *widget, int typeRequest);
    void ReceiveStatusConnectionToDB(bool status);


private slots:
    void on_act_addData_triggered();
    void on_act_connect_triggered();
    void on_pb_request_clicked();


signals:
    void sig_RequestToDb(QString request);

private:

    QVector<QString> dataForConnect; //Данные для подключения к БД.

    Ui::MainWindow *ui;
    Dialog *dataDb;
    DataBase* dataBase;
    QMessageBox* msg;
    QTableView *tableView;


    QString request = "SELECT title, release_year, c.name FROM film f "
                      "JOIN film_category fc on f.film_id = fc.film_id "
                      "JOIN category c on c.category_id  = fc.category_id";

    QString request_comedy = "SELECT title, description FROM film f "
                             "JOIN film_category fc on f.film_id = fc.film_id "
                             "JOIN category c on c.category_id = fc.category_id "
                             "WHERE c.name = 'Comedy'";

    QString request_horrors = "SELECT title, description FROM film f "
                              "JOIN film_category fc on f.film_id = fc.film_id "
                              "JOIN category c on c.category_id = fc.category_id "
                              "WHERE c.name = 'Horror'";

};
#endif // MAINWINDOW_H
