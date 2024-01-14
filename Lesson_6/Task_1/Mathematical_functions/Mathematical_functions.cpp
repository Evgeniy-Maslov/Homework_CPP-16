#include <iostream>
#include "Math_functions.h"
#include"print.h"

int main(int argc, char** argv)
{
    double x;
    int y;
    int a;
    std::cout << "Enter the first number: ";
    std::cin >> x;
    std::cout << "Enter the second number: ";
    std::cin >> y;
    std::cout << "Select an operation (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - exponentiation): ";
    std::cin >> a;
    print(static_cast<Select>(a), x, y);
    return 0;
}
