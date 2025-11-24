#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qsqlrecord.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_nameProg->setAlignment(Qt::AlignCenter);
    ui->tabWidget->setTabText(0, "результат поиска");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabText(1, "весь список слов в БД");
    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_foundDoc->setEnabled(statusConnect);
    ui->pb_search->setEnabled(statusConnect);

    dataBase = new DataBase("../../../SettingsPostgreSQL.ini");
    msg = new QMessageBox();

    QObject::connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    QObject::connect(dataBase, &DataBase::sig_SendDataAllWords, this, &MainWindow::ScreenOutputAllWordsFromDB);
    dataBase->ConnectToDataBase();

    QObject::connect(ui->pb_search, &QPushButton::clicked, this, &MainWindow::ReadSearchBarAndParsing);
    QObject::connect(ui->lineEdit_search, &QLineEdit::returnPressed, this, &MainWindow::ReadSearchBarAndParsing);
    QObject::connect(dataBase, &DataBase::sig_SendDataSearchWord, this, &MainWindow::ScreanOutputSearchWordsFromDB);
    QObject::connect(ui->pb_foundDoc, &QPushButton::clicked, this, [=](){CheckRequestAndReadAnswerFromDB(tempRequest, requestFoundDocuments);});
    QObject::connect(dataBase, &DataBase::sig_SendDataFoundDocuments, this, &MainWindow::ScreanOutputFoundDocumentsTable);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataBase;
    delete msg;
}

void MainWindow::CheckRequestAndReadAnswerFromDB(QString request, int typeRequest)
{
    QSqlError err = dataBase->RequestToDB(request);
    if(err.isValid()){
        msg->setIcon(QMessageBox::Critical);
        msg->setText(err.text());
        msg->exec();
    }
    else{
        dataBase->ReadAnswerFromDB(request, typeRequest);
    }
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    statusConnect = status;
    if(statusConnect){
        CheckRequestAndReadAnswerFromDB(requestAllWords, requestTypeAllWords);
        ui->lb_statusConnect->setText("Подключено");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_search->setEnabled(statusConnect);
    }
    else{
        dataBase->DisconnectFromDataBase();
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        msg->exec();
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
    }
}

void MainWindow::ReadSearchBarAndParsing()
{
    QString buff = ui->lineEdit_search->text().toLower();

//************// поиск пробелов в начале строки //*****************//
    if(!buff.isEmpty()){
        uint countEmptySpace = 0;
        while (countEmptySpace < buff.size() and buff.at(countEmptySpace) == " "){
            countEmptySpace++;
        }
        if(countEmptySpace > 0){
            buff.remove(0, countEmptySpace);
        }
    }

    QStringList SearchBar = buff.replace(QRegularExpression("[^а-яА-ЯёЁa-zA-Z]"), " ").replace(QRegularExpression("\\s+"), " ").split(" ");

 //*************// ограничение коичество искомых слов //***************//
    uint countWords = 4;
    if(SearchBar.size() < countWords)
    {
        for(uint i = SearchBar.size(); i < countWords; i++)
        {
            SearchBar.append("");
        }
    }
    tempRequest = requestSearchWord.arg(SearchBar[0], SearchBar[1], SearchBar[2], SearchBar[3]);
    CheckRequestAndReadAnswerFromDB(tempRequest, requestTypeSearchWord);
}

void MainWindow::ScreenOutputAllWordsFromDB(QSqlQueryModel* queryModel)
{
    queryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("все слова в Базе Данных"));
    queryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("количество совпадений\n слов"));
    ui->tb_FileList->setModel(queryModel);
    ui->tb_FileList->resizeColumnsToContents();
    ui->tb_FileList->resizeRowsToContents();
}

void MainWindow::ScreanOutputFoundDocumentsTable(QSqlQueryModel* queryModel)
{
    queryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("найденые документы\n"));
    queryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("количество совпадений\n слов"));
    ui->tb_FileList->setModel(queryModel);
    ui->tb_FileList->resizeColumnsToContents();
    ui->tb_FileList->resizeRowsToContents();
}

void MainWindow::ScreanOutputSearchWordsFromDB(QSqlQuery* simpleQuery)
{
    ui->txtBrSearchWord->clear();
    bool flag = false;
    uint numDoc = 1;
    while (simpleQuery->next() and numDoc <= 10) {
        flag = true;
        QString resultsSearch = QString("%3.  В документе \"%1\" имеется %2 совпадения искомых слов." ).arg(simpleQuery->value(0).toString(),
                                                                                                    simpleQuery->value(1).toString(),
                                                                                                    QString::number(numDoc));
        ui->txtBrSearchWord->append(resultsSearch);
        numDoc++;
    }
    if(!flag){
        ui->txtBrSearchWord->setText("Искомых слов нет ни в одном документе.");
        CheckRequestAndReadAnswerFromDB(requestAllWords, requestTypeAllWords);
    }
     ui->pb_foundDoc->setEnabled(flag);
}
