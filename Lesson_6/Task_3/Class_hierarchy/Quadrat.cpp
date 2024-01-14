#include"Quadrat.h"


Quadrat::Quadrat(int a)
{
    this->a = a;
    this->d = a;
    this->b = a;
    this->c = a;
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