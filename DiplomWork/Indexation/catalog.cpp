#include "catalog.h"


Catalog::Catalog(QString data, DataBase& db, QObject *parent)
    : QObject{parent}, pathSettingsFileINI(data), db_PostgreSQL(&db)
{
    setParametersIndexing();
    FolderBrowsingAndFindFile(nameDirectory);
    qDebug() << "FolderBrowsingAndFindFile - END`";
    db_PostgreSQL->DisconnectFromDataBase(pathSettingsFileINI[dbName]);
}

Catalog::~Catalog()
{
    delete dir;
    delete db_PostgreSQL;
}

void Catalog::setParametersIndexing()
{
    QSettings parametersIndexing(pathSettingsFileINI, QSettings::IniFormat);
    parametersIndexing.beginGroup("PARAMETERS");
    nameDirectory = parametersIndexing.value("Catalog").toString();
    fileFilters = parametersIndexing.value("File_Extensions").toStringList();
    for(int i = 0; i < fileFilters.size(); i++)
    {
        fileFilters[i] = "*." + fileFilters[i];
    }
    parametersIndexing.endGroup();
}

void Catalog::FolderBrowsingAndFindFile(QString nameDir)
{
    dir = new QDir(nameDir);
    if (!dir->exists())
    {
        qWarning("Cannot find the example directory");
    }

//**************************/ поиск подкаталогов /***************************//

    dir->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Readable);
    QFileInfoList listDir = dir->entryInfoList();

//*************************/ поиск текстовых файлов в каталоге /*************//

    dir->setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::Readable);
    dir->setNameFilters(fileFilters);
    // qDebug() << dir->nameFilters();
    QFileInfoList listFile = dir->entryInfoList();

//************************/ перебор и рекурсивный вход в подкаталоги /*******//

    for (int i = 0; i < listDir.size(); ++i)
    {
        QFileInfo dirInfo = listDir.at(i);
        QString path = dir->filePath(dirInfo.fileName());
        FolderBrowsingAndFindFile(path);
        dir->cdUp();
    }

//**********************/ пробежка и чтение текстовых файлов /***************//

    for (int i = 0; i < listFile.size(); ++i)
    {
        QFileInfo fileInfo = listFile.at(i);
        ReadFileAndParsing(fileInfo);
    }
}

void Catalog::ReadFileAndParsing(QFileInfo fileInfo)
{
    QFile file(dir->filePath(fileInfo.fileName()));
    // QFile file("D:\\source\\Homework_CPP-16\\IndexerProgram\\Work\\Documents\\browscap.ini");
    QString nameDoc = fileInfo.fileName().split(".").front();
    // qDebug() << nameDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString buff = in.readAll().toLower();
        file.close();
        buff.replace(QRegularExpression("[^а-яА-ЯёЁa-zA-Z]"), " ").replace(QRegularExpression("\\s+"), " ");

        CalculateWordsAndSavingInDatabase(nameDoc, buff);

//****************************/ тестовая выгрузка файлов /**************************************//

        QFile outFile("D:\\source\\Homework_CPP-16\\DiplomWork\\Work\\"+ nameDoc +".txt");
        if(outFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&outFile);
            out << buff;
            outFile.close();
        }
    }
    else {
        qWarning("Сan't open the file");
    }

}

void Catalog::CalculateWordsAndSavingInDatabase(QString nameDoc, QString textDoc)
{
    QStringList listWords = textDoc.split(" ");
    QMap<QString, uint32_t> words;
    foreach (QString s, listWords) {
        if(s.size() > 2 and s.size() <= 32){
            words[s]++;
        }
    }
    QStringList tableHeaders = db_PostgreSQL->GetTableHeaders();
    bool checkValue;
    checkValue = db_PostgreSQL->CheckingMatchValue(tableHeaders[nameTableDocuments], tableHeaders[nameColumnDocuments], nameDoc);
    if(!checkValue){
        db_PostgreSQL->RequestINSERT(tableHeaders[nameTableDocuments], tableHeaders[nameColumnDocuments], nameDoc);
    }

    QMap<QString, uint32_t>::const_iterator it;
    for( it = words.constBegin(); it != words.constEnd(); ++it)
    {
        checkValue = db_PostgreSQL->CheckingMatchValue(tableHeaders[nameTableWords], tableHeaders[nameColumnWords], it.key());
        if(!checkValue){
            db_PostgreSQL->RequestINSERT(tableHeaders[nameTableWords], tableHeaders[nameColumnWords], it.key());
        }

        QString checkListValues = QString("%1' AND %2 = '%3'; --coment").arg(nameDoc,
                                                                             tableHeaders[nameColumnWords],
                                                                             it.key());

        QString listColumns = QString("%1, %2, %3").arg(tableHeaders[nameColumnDocuments],
                                                        tableHeaders[nameColumnWords],
                                                        tableHeaders[nameColumnNumberOfWords]);

        QString listValues = QString("%1', '%2', %3); --coment").arg(nameDoc,
                                                                     it.key(),
                                                                     QString::number(it.value()));

        checkValue = db_PostgreSQL->CheckingMatchValue(tableHeaders[nameTableNumberOfWords], tableHeaders[nameColumnDocuments], checkListValues);
        if(!checkValue){
            db_PostgreSQL->RequestINSERT(tableHeaders[nameTableNumberOfWords], listColumns, listValues);
        }
    }
}
