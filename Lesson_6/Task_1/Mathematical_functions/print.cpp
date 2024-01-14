#include <iostream>
#include "Math_functions.h"
#include"print.h"

void print(Select a, double &x, int &y)
{
    switch (a)
    {
    case Select::addition:
        std::cout << x << " + " << y << " = " << Addition(x, y);
        break;
    case Select::subtraction:
        std::cout << x << " - " << y << " = " << Subtraction(x, y);
        break;
    case Select::multiplication:
        std::cout << x << " * " << y << " = " << Multiplication(x, y);
        break;
    case Select::division:
        if (y == 0)
        {
            std::cout << "Division by zero is not possible\n";
            break;
        }
        else
            std::cout << x << " / " << y << " = " << Division(x, y);
            break;
    case Select::exponentiation:
        std::cout << x << " to the power of " << y << " = " << Exponentiation(x, y);
        break;
    default:
        std::cout << "Wrong number!\n";
        break;
    }
}