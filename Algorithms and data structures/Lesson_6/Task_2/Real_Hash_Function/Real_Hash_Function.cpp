#include <iostream>
#include <format>

int real_string_hash(std::string str, int p, int n)
{
    long long ans = 0;
    long long mult = 1;
    for (int i = 0; i < str.size(); i++)
    {
        ans += mult * static_cast<int>(str[i]);
        mult *= p;
    }
    int ans_n = ans % n;
    return ans_n;
}



int main(int argc, char** argv)
{
    int p;
    int n;
    std::string str;
    std::cout << "Enter p: ";
    std::cin >> p;
    std::cout << "Enter n: ";
    std::cin >> n;
    do
    {
        std::cout << "Enter the string: ";
        std::cin >> str;
        std::cout << std::format("Hash of the string \"{}\" = {}", str, real_string_hash(str, p, n));
        std::cout << std::endl;
    } while (str != "exit");
    return 0;
}
