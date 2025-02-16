#include"Equilateral_triangle.h"
#include"Triangle.h"
#include "Bad_Error.h"

Equilateral_triangle::Equilateral_triangle() :Equilateral_triangle(30) { }
Equilateral_triangle::Equilateral_triangle(int a): Triangle(a, a, a, 60, 60, 60)
{
    if (!check())
    {
        throw Figure_error("sides '!=' or corners '!=' 60\n");
    }
    set_name("Equilateral_triangle");
}
bool Equilateral_triangle::check()
{
    return (a == c && a == b && A == 60 && B == 60);
}