//   Описание
//Напишите программу, которая все нечётные элементы массива(std::vector) умножает на 3 с помощью лямбда - функции.
//
//Циклы использовать не нужно.
//
//Пример работы программы
//Входные данные : 4 7 9 14 12
//Выходные данные : 4 21 27 14 12


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = { 4, 7, 9, 14, 12 };
    std::for_each(std::begin(v), std::end(v), [](int& value) {
        if (value % 2)
        {
            value *= 3;
        }
        std::cout << value << " ";
        });

    return 0;
}
