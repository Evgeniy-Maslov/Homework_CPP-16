#include <iostream>
#include <format>

int simple_string_hash(std::string str)
{
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ans += static_cast<int>(str[i]);
    }
    return ans;
}

int main(int argc, char** argv)
{
    std::string str;
    do
    {
        std::cout << "Enter the string: ";
        std::cin >> str;
        std::cout << std::format("Naive hash of a string \"{}\" = {}", str, simple_string_hash(str));
        std::cout << std::endl;
    } while (str != "exit");
    return 0;
}

