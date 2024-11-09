#include "std_vector.h"
#include <iostream>




int main(int argc, char** argv)
{
    std_vector<std::string> arr;
    arr.puch_back("q");
    arr.puch_back("w");
    arr.puch_back("e");
    arr.puch_back("r");
    arr.puch_back("t");
    std::cout << "arr:  ";
    arr.print_vec();
    std::cout << "arr.size() - " << arr.size() << "\n" << "arr.capacity() - " << arr.capacity() << "\n";
    std::cout << "arr.at(2) - " << arr.at(2) << "\n\n";

    std_vector<int> arr2;
    arr2.puch_back(55);
    arr2.puch_back(88);
    arr2.puch_back(22);
    std::cout << "arr2:  ";
    arr2.print_vec();
    std::cout << "arr2.size() - " << arr2.size() << "\n" << "arr2.capacity() - " << arr2.capacity() << "\n";
    std::cout << "arr2.at(1) - " << arr2.at(1) << "\n\n";

    return 0;
}
