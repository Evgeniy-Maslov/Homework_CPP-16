#include"Isosceles_triangle.h"


Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B)
{
    this->a = a;
    this->b = b;
    c = a;
    this->A = A;
    this->B = B;
    C = A;
    get_name("Isosceles_triangle");
}
bool Isosceles_triangle::Isosceles_triangle::check()
{
    return (Triangle::check() && a == c && A == C);
}
void Isosceles_triangle::print_info()
{
    Triangle::print_info();
}
Isosceles_triangle::Isosceles_triangle() :Isosceles_triangle(10, 20, 50, 60) { }
