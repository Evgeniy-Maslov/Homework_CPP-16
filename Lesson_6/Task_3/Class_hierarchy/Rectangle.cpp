#include"Rectangle.h"

Rectangle::Rectangle(int a, int b)
{
    this->a = a;
    this->b = b;
    c = a;
    d = b;
    A = B = C = D = 90;
    get_name("Rectangle");
}
bool Rectangle::check()
{
    return (Parallelogram::check() && A == 90 && B == 90 && C == 90);
}
void Rectangle::print_info()
{
    Parallelogram::print_info();
}
Rectangle::Rectangle() : Rectangle(10, 20) { }