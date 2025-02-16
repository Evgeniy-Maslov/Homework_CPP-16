#include <iostream>
#include "Figure.h"

namespace DynamicFigure
{
    Figure::Figure(int sides_count)
    {
        this->sides_count = sides_count;
        get_name("Figure");
    }
    void Figure::get_name(std::string m_name)
    {
        name = m_name;
    }
    Figure::Figure() :Figure(0) { }
    void Figure::print_info()
    {
        std::cout << name << ":" << std::endl;
        std::cout << (check() ? "Correct" : "Wrong") << std::endl;
        std::cout << "Sides count: " << sides_count << std::endl;
    }
    bool Figure::check()
    {
        return (sides_count == 0);
    }
}
