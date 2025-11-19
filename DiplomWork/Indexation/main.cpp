#include "catalog.h"
#include "database.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataBase db_PostgreSQL("../../../SettingsPostgreSQL.ini");
    Catalog cat("../../../ParametersIndexing.ini", db_PostgreSQL);

    return a.exec();
}
