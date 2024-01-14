#include"Rhomb.h"

Rhomb::Rhomb(int a)
{
    this->a = a;
    c = a;
    b = a;
    d = a;
    get_name("Rhomb");
}
bool Rhomb::check()
{
    return (Parallelogram::check() && d == c);
}
void Rhomb::print_info()
{
    Parallelogram::print_info();
}
Rhomb::Rhomb() : Rhomb(30) { }