#include "table.h"
#include <iostream>

int main(int argc, char** argv)
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;  // выводит 4
    std::cout << std::endl;
    std::cout << test.size() << std::endl;
    return 0;
}