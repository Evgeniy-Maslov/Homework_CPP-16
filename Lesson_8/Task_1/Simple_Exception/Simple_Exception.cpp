#include <iostream>

int function(std::string str, int forbidden_length)
{
    if (str.length() != forbidden_length)
        return str.length();
    throw std::string{ "You have entered a word of forbidden length! Goodbye" };
 }

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
        catch (std::string& bad_length)
        {
            std::cerr << bad_length << std::endl;
            cycle = 0;
        }
    }
    return 0;
}