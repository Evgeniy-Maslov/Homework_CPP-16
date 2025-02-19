#include <iostream>
#include <windows.h>

struct bank_account
{
    std::string name;
    int account_number;
    float balance;
};
void balance(bank_account& x, int a)
{
    x.balance = a;
}
int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    bank_account sber;
    std::cout << "Введите номер счёта: ";
    std::cin >> sber.account_number;
    std::cout << "Введите имя владельца: ";
    std::cin >> sber.name;
    std::cout << "Введите баланс: ";
    std::cin >> sber.balance;
    std::cout << "Введите новый баланс: ";
    std::cin >> a;
    balance(sber, a);
    std::cout << "Ваш счёт: " << sber.name << ", " << sber.account_number << ", " << sber.balance << std::endl;
    return 0;
}