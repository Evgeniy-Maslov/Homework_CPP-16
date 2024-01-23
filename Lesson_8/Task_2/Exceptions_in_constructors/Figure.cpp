#include"Figure.h"


void Figure:: get_name(std::string m_name)
{
    name = m_name;
}
Figure::Figure(int sides_count)
{
    this->sides_count = sides_count;
    if (!check())
        throw Figure_error("Invalid sides_count\n");
    get_name("Figure");
}
Figure::Figure() :Figure(0) { }
void Figure::conductor() { }
bool Figure::check()
{
    return (sides_count == 0);
}
void Figure::get_sides_count()
{
    std::cout << name << ": " << sides_count << std::endl;
}