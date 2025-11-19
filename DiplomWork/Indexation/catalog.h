#ifndef CATALOG_H
#define CATALOG_H

#include "database.h"
#include <QObject>
#include <QDir>
#include <QSettings>
#include <QDebug>
#include <QFile>
#include <QRegularExpression>


class Catalog : public QObject
{
    Q_OBJECT
public:
    explicit Catalog(QString data, DataBase& db, QObject *parent = nullptr);
    ~Catalog();
private:
    void setParametersIndexing();
    void FolderBrowsingAndFindFile(QString nameDir);
    void ReadFileAndParsing(QFileInfo fileInfo);
    void CalculateWordsAndSavingInDatabase(QString nameDoc, QString textDoc);

signals:

private:
    QString pathSettingsFileINI;
    DataBase* db_PostgreSQL;
    QString nameDirectory;
    QStringList fileFilters;
    QDir* dir;
};

#endif // CATALOG_H
