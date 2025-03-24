#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    void set_HostName(std::string);
    void set_DbName(std::string);
    void set_Login(std::string);
    void set_Password(std::string);
    void set_Port(uint);
    void print_fields_DB();
signals:


private:
    std::string HostName{};
    std::string DbName{};
    std::string Login{};
    std::string Password{};
    uint port{};
};

#endif // DATABASE_H
