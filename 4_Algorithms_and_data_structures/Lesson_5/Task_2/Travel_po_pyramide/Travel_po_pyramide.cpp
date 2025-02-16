#include <iostream>
#include <format>
#include "Header.h"

int main(int argc, char** argv)
{
    int pyramid_0[] = { 1, 3, 6, 5, 9, 8 };
    int pyramid_1[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int pyramid_2[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size_pyramid_0 = sizeof(pyramid_0) / sizeof(int);
    int size_pyramid_1 = sizeof(pyramid_1) / sizeof(int);
    int size_pyramid_2 = sizeof(pyramid_2) / sizeof(int);
    std::string command;
    int index{};

    Source_array(pyramid_0, size_pyramid_0);
    std::cout << "Pyramid:\n";
    for (int i = 0; i < size_pyramid_0; i++)
    {
        print_pyramid(pyramid_0, i, size_pyramid_0);
    }
    std::cout << std::endl;
    std::cout << "You are here: ";
    print_pyramid(pyramid_0, index, size_pyramid_0);
    while (command != "exit")
    {
        std::cout << "Enter the command: ";
        std::cin >> command;
        Travel_po_pyramide(command, pyramid_0, index, size_pyramid_0);
    }
    
    /*
      // МАССИВ pyramid_1
    index = 0;
    command = " ";
    Source_array(pyramid_1, size_pyramid_1);
    std::cout << "Pyramid:\n";
    for (int i = 0; i < size_pyramid_1; i++)
    {
        print_pyramid(pyramid_1, i, size_pyramid_1);
    }
    std::cout << std::endl;
    std::cout << "You are here: ";
    print_pyramid(pyramid_1, index, size_pyramid_1);
    while (command != "exit")
    {
        std::cout << "Enter the command: ";
        std::cin >> command;
        Travel_po_pyramide(command, pyramid_1, index, size_pyramid_1);
    }
    */


    /*
       // МАССИВ pyramid_2
    index = 0;
    command = " ";
    Source_array(pyramid_2, size_pyramid_2);
    std::cout << "Pyramid:\n";
    for (int i = 0; i < size_pyramid_2; i++)
    {
        print_pyramid(pyramid_2, i, size_pyramid_2);
    }
    std::cout << std::endl;
    std::cout << "You are here: ";
    print_pyramid(pyramid_2, index, size_pyramid_2);
    while (command != "exit")
    {
        std::cout << "Enter the command: ";
        std::cin >> command;
        Travel_po_pyramide(command, pyramid_2, index, size_pyramid_2);
    }
    */

    
    return 0;
}
