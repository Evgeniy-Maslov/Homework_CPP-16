#include "table.h"
#include <iostream>

int main(int argc, char** argv)
{
    auto test = table<int>(2, 3);
    //auto t3 = table<int>(6, 8);
    test[0][0] = 4;
    //t3[1][1] = 10;
    std::cout << test[0][0] << std::endl;  // выводит 4
    std::cout << std::endl;
    std::cout << test.size() << std::endl;
    //test = t3;
    //test.print();
    return 0;
}