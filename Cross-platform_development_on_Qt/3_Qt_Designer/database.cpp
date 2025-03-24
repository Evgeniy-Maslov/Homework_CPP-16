#include "database.h"
#include <QDebug>


DataBase::DataBase(QObject *parent)
    : QObject{parent}
{}
void DataBase::set_HostName(std::string NewHostName)
{
    HostName = NewHostName;
}
void DataBase::set_DbName(std::string NewDbName)
{
    DbName = NewDbName;
}
void DataBase::set_Login(std::string NewLogin)
{
    Login = NewLogin;
}
void DataBase::set_Password(std::string NewPassword)
{
    Password = NewPassword;
}
void DataBase::set_Port(uint NewPort)
{
    port = NewPort;
}
void DataBase::print_fields_DB()
{
    qDebug() << "HostName: " << HostName
             << "\nDbName: " << DbName
             << "\nLogin: " << Login
             << "\nPassword: " << Password
             << "\nPort: " << port
             << Qt::endl;

}
