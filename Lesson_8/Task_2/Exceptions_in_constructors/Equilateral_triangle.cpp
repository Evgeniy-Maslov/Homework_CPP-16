#include"Equilateral_triangle.h"

Equilateral_triangle::Equilateral_triangle() :Equilateral_triangle(30, 60) { }
Equilateral_triangle::Equilateral_triangle(int a, int A) : Triangle(a, A)
{
    this->a = a;
    b = a;
    c = a;
    this->A = A;
    B = A;
    C = A;
    if (!check())
    {
        if (!check_Equilateral_triangle())
        {
            throw Figure_error("the sum of the angles '!=' 180, sides '!=' or corners '!=' 60\n");
        }
        throw Figure_error("the sum of the angles '!=' 180\n");
    }
    else if (!check_Equilateral_triangle())
    {
        throw Figure_error("sides '!=' or corners '!=' 60\n");
    }
    get_name("Equilateral_triangle");
}
bool Equilateral_triangle::check()
{
    return (Triangle::check());
}
bool Equilateral_triangle::check_Equilateral_triangle()
{
    return (a == c && a == b && A == 60 && B == 60);
}