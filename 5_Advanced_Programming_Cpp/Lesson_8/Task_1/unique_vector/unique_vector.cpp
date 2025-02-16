#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
void remove_duplicat(std::vector<T>& vector) {
    std::sort(vector.begin(), vector.end());
    auto it = std::unique(vector.begin(), vector.end());
    vector.erase(it, vector.end());
}

template<class T>
void print_vec(const std::vector<T>& vector) {
     auto it = vector.cbegin();
     while (it != vector.cend()) {
         std::cout << *it << " ";
         it++;
     }
     std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::vector<int> numbers = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::vector<std::string> fruits = { "apple", "nectarine", "peach", "peach", "grapefruit", "banana", "mango", "nectarine", "apple", "peach" };
    std::cout << "[IN]: ";
    print_vec(numbers);
    remove_duplicat(numbers);
    std::cout << "[OUT]: ";
    print_vec(numbers);
    std::cout << std::endl;
    std::cout << "[IN]: ";
    print_vec(fruits);
    remove_duplicat(fruits);
    std::cout << "[OUT]: ";
    print_vec(fruits);

    return 0;
}
