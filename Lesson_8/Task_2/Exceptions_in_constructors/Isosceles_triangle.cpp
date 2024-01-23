#include"Isosceles_triangle.h"

Isosceles_triangle::Isosceles_triangle() :Isosceles_triangle(10, 20, 50, 70) { }
Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, A, B)
{
    this->a = a;
    this->b = b;
    c = a;
    this->A = A;
    this->B = B;
    C = A;
    if (!check())
    {
        if (!check_Isosceles_triangle())
        {
            throw Figure_error("the sum of the angles '!=' 180, sides 'a' and 'c' '!=' or the corners 'A' and 'C' '!='\n");
        }
        throw Figure_error("the sum of the angles '!=' 180\n");
    }
    else if (!check_Isosceles_triangle())
    {
        throw Figure_error("sides 'a' and 'c' '!=' or the corners 'A' and 'C' '!='\n");
    }
    get_name("Isosceles_triangle");
}
bool Isosceles_triangle::check()
{
    return (Triangle::check());
}
bool Isosceles_triangle::check_Isosceles_triangle()
{
    return (a == c && A == C);
}