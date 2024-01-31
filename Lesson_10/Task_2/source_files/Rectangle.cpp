#include"Rectangle.h"

Rectangle::Rectangle(int a, int b): Parallelogram(a, b, 90, 90)
{
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