#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>


int main(int argc, char** argv)
{
    int num_element;  
    std::set<int, std::greater<int>> my_set;  //"6 1 5 1 3 4 4" ;
    std::cout << "[IN]:\n";
    std::ifstream fin("data.txt");
    if (fin.is_open()) {
        fin >> num_element;
    }
    else {
        std::cout << "failed to open file!\n";
        return 1;
    }
    std::cout << num_element << std::endl;
    while (num_element)
    {
        int value;
        fin >> value;
        std::cout << value << std::endl;
        my_set.insert(value);
        num_element--;
    }
    fin.close();
    std::cout << std::endl;
    std::cout << "[OUT]:\n";
    std::for_each(my_set.begin(), my_set.end(), [](const int& i) {
        std::cout << i << std::endl;
        });
    return 0;
}
