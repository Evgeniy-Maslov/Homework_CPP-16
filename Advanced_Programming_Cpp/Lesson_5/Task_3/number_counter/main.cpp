#include "number_counter.h"




int main(int argc, char** argv)
{
    std::vector<int> vector = { 4, 1, 3, 6, 25, 54 };
    number_counter num = vector;
    num();

    return 0;
}


