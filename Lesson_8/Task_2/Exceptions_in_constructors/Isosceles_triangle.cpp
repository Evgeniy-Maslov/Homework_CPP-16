#include"Isosceles_triangle.h"

Isosceles_triangle::Isosceles_triangle() : Isosceles_triangle(10, 20, 50, 60) { }
Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
{
    if (!check())
    {
        throw Figure_error("sides 'a' and 'c' '!=' or the corners 'A' and 'C' '!='\n");
    }
    get_name("Isosceles_triangle");
}
bool Isosceles_triangle::check()
{
    return (a == c && A == C);
}