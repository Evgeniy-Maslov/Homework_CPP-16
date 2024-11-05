#include <iostream>
#include <set>
#include <algorithm>


int main(int argc, char** argv)
{
    int num_element;
    int value;   
    std::set<int, std::greater<int>> my_set;  //"6 1 5 1 3 4 4" ;
    std::cout << "[IN]:\n";
    std::cin >> num_element;
    while (num_element)
    {
        int value;
        std::cin >> value;
        my_set.insert(value);
        num_element--;
    }
    std::cout << "[OUT]:\n";
    std::for_each(my_set.begin(), my_set.end(), [](const int& i) {
        std::cout << i << "\n";
        });
    return 0;
}
