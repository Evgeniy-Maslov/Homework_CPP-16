#include"Quadrat.h"


Quadrat::Quadrat(int a): Rectangle(a, a)
{
    get_name("Quadrat");
}
bool Quadrat::check()
{
    return (Rectangle::check() && d == c);
}
void Quadrat::print_info()
{
    Rectangle::print_info();
}
Quadrat::Quadrat() : Quadrat(20) { }