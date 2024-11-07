#pragma once
#include <iostream>

template<typename Container>
void print_container(const Container& cont)
{
    auto it = cont.begin();
    while (it != cont.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}