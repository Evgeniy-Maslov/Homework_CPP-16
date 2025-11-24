#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include <QMessageBox>
#include <qtextbrowser.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

Q_SIGNALS:


public Q_SLOTS:
    void ReceiveStatusConnectionToDB(bool status);
    void ScreenOutputAllWordsFromDB(QSqlQueryModel *queryModel);
    void ScreanOutputFoundDocumentsTable(QSqlQueryModel* queryModel);
    void ScreanOutputSearchWordsFromDB(QSqlQuery* simpleQuery);


private:
    void CheckRequestAndReadAnswerFromDB(QString request, int typeRequest);
    void ReadSearchBarAndParsing();


    Ui::MainWindow *ui;

    DataBase* dataBase;
    QMessageBox* msg;
    bool statusConnect = false;
    QString tempRequest;
    QString requestAllWords = "SELECT Name_word AS все_слова, SUM(Word_counter ) AS количество "
                              "FROM documents_words "
                              "GROUP BY все_слова ORDER BY все_слова;";

    QString requestSearchWord = QString("SELECT Name_document AS документ, SUM(Word_counter ) AS количество_совпадений "
                                "FROM documents_words "
                                "WHERE Name_word = '%1' OR Name_word = '%2' OR Name_word = '%3' OR  Name_word = '%4' "
                                        "GROUP BY Name_document ORDER BY количество_совпадений DESC;");
};
#endif // MAINWINDOW_H
