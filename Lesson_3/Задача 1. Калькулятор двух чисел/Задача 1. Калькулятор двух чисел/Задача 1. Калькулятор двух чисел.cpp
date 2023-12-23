#include <iostream>
#include <windows.h>

class Calculator
{
public:
    double num1;
    double num2;

    double add()
    {
        return num1 + num2;
    }
    double multiply()
    {
        return num1 * num2;
    }
    double subtract_1_2()
    {
        return num1 - num2;
    }
    double subtract_2_1()
    {
        return num2 - num1;
    }
    double divide_1_2()
    {
        return num1 / num2;
    }
    double divide_2_1()
    {
        return num2 / num1;
    }
    bool set_num1(double num1)
    {
        if (num1 == 0)
        {
            std::cout << "Неверный ввод!";
            std::cout << std::endl;
            return false;
        }
        else
        {
            this->num1 = num1;
        }
        return true;
    }
    bool set_num2(double num2)
    {
        if (num2 == 0)
        {
            std::cout << "Неверный ввод!";
            std::cout << std::endl;
            return false;
        }
        else
        {
            this->num2 = num2;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double n;
    double m;
    Calculator two_numbers;
    do
    {
        std::cout << "Введите num1: ";
        std::cin >> n;
    } while (two_numbers.set_num1(n) == false);
    do
    {
        std::cout << "Введите num2: ";
        std::cin >> m;
    } while (two_numbers.set_num2(m) == false);

    std::cout << "num1 + num2 = " << two_numbers.add() << "\n";
    std::cout << "num1 - num2 = " << two_numbers.subtract_1_2() << "\n";
    std::cout << "num2 - num1 = " << two_numbers.subtract_2_1() << "\n";
    std::cout << "num1 * num2 = " << two_numbers.multiply() << "\n";
    std::cout << "num1 / num2 = " << two_numbers.divide_1_2() << "\n";
    std::cout << "num2 / num1 = " << two_numbers.divide_2_1() << "\n";
    return 0;
}