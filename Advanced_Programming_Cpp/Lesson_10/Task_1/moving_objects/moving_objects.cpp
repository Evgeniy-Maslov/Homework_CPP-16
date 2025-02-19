#include <iostream>
#include <format>
#include <vector>

template <typename T>
void move_vectors(std::vector<T>& lhs, std::vector<T>& rhs) {
    std::vector<T> temp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(temp);
}


int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << std::format("one.size() = {} , two.size() = {}\n", one.size(), two.size());
    move_vectors(one, two);
    std::cout << std::format("one.size() = {} , two.size() = {}\n", one.size(), two.size());

    return 0;
    std::cout << "Hello World!\n";
}