#include <iostream>
#include "memory.h"



int main()
{
    std_unique_ptr<int> ptr(new int(5));
    std_unique_ptr<double> ptr_2(new double(10.25));
 
    std::cout << *ptr << "\n";
    std::cout << *ptr_2 << "\n";
    
    //ptr = ptr_2;

    auto* p = ptr_2.release();
    std::cout << *p << "\n";

    //std::cout << *ptr_2 << "\n";

    return 0;
<<<<<<< HEAD
}
=======
>>>>>>> ad2c54aae23fa16607031002bf2ebfb63e7f1132
