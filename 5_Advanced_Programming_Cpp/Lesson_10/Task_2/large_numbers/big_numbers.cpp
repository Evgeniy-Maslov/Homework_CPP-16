#include <iostream>
#include <string>
#include <vector>
#include "big_integer.h"


int main(int argc, char** argv)
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto number3 = big_integer("110000004575");
 
    auto result = number1 + number2;
    std::cout << result;    // 193099

    result = number1 - number2;
    std::cout << result;    // 36051

    result = number1 * 22;
    std::cout << result;    // 2520650

    result = number1 * number2;
    std::cout << result;    // 8996887300

    std::cout << number3;   // 110000004575
    return 0;
}
