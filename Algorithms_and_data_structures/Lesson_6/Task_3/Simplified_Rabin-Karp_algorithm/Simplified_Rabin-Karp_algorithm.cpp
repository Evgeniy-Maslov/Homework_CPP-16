#include <iostream>
#include <string>
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

int find_substring_light_rabin_karp(std::string str, std::string substr)
{
    bool logic;
    int h_str;
    int n = substr.size();
    int substr_hash = simple_string_hash(substr);
    for (int i = 0; i < str.size() - n; i++)
    {
        if (i == 0) { h_str = simple_string_hash(str.substr(0, n)); }
        else
        {
            h_str -= static_cast<int>(str[i - 1]);
            h_str += static_cast<int>(str[i + n - 1]);
        }
        if (h_str != substr_hash) 
            { logic = false; }
        else
        {
            logic = true;
            for (int j = 0; j < n; j++)
            {
                if (str[i + j] != substr[j])
                { 
                    logic = false;
                    break;
                }
            }
            if (logic == true)
                return i;
        }
    }
    return -1;
}


int main(int argc, char** argv)
{
    std::string string;
    std::string substring;
    std::cout << "Enter the line in which the search will be performed: ";
    std::cin >> string;
    do
    {
        std::cout << "Enter the substring you want to find: ";
        std::cin >> substring;
        int index = find_substring_light_rabin_karp(string, substring);
        index >= 0 ? std::cout << std::format("Substring {} found by index {}\n", substring, index)
            : std::cout << std::format("Substring {} not found\n", substring);
    } while(substring != "exit");
    return 0;
}
