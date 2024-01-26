#include <iostream>
#include "bad_length.h"
#include"function.h"

int main()
{
    int forbidden_length;
    std::string str;
    bool cycle{1};
        std::cout << "Enter the forbidden length: ";
        std::cin >> forbidden_length;
    while (cycle)
    {
        std::cout << "Enter the word: ";
        std::cin >> str;
        try
        {
            std::cout << "The length of the word \"" << str << "\" equal to " << function(str, forbidden_length) << std::endl;
        }
        catch (bad_length& bad)
        {
            std::cerr << bad.what() << std::endl;
            cycle = 0;
        }
    }
    return 0;
}