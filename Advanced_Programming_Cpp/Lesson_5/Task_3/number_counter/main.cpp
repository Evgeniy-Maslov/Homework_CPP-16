#include "number_counter.h"
#include <algorithm>



int main(int argc, char** argv)
{
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: " << numbers << std::endl;
    number_counter counter = std::for_each(numbers.begin(), numbers.end(), number_counter());
    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;
    return 0;
}


