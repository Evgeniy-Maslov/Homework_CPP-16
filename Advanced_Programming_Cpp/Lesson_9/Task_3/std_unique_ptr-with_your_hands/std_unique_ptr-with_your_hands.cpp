#include <iostream>
#include "memory.h"



int main()
{
    
    std_unique_ptr<int> ptr(new int(5));
    std_unique_ptr<double> ptr_2(new double(10.25));
 ;
    std::cout << *ptr << "\n";
    std::cout << *ptr_2 << "\n";
    
    //ptr = ptr_2;

    auto* p = ptr_2.release();
    std::cout << *p << "\n";

    //std::cout << *ptr_2 << "\n";

    return 0;
   /* std::cout << ptr->xy << "\n";
    ptr2->print();
    std::cout << summa(*ptr) << "\n";
    std::cout << ptr2->xy << "\n";*/
    //std::cout << 

    /*std::vector<int>* A = new std::vector<int>(3, 5);
    std::vector<int>::iterator it = A->begin();
    while (it != A->end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "Hello World!\n";*/
}
