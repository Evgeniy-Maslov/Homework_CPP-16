#include"Equilateral_triangle.h"


Equilateral_triangle::Equilateral_triangle(int a, int A): Triangle(a, a, a, A, A, A)
{
    get_name("Equilateral_triangle");
}
bool Equilateral_triangle::check()
{
    return (Triangle::check() && a == c && a == b && A == 60 && B == 60);
}
void Equilateral_triangle::print_info()
{
    Triangle::print_info();
}
Equilateral_triangle::Equilateral_triangle() :Equilateral_triangle(30, 60) { }