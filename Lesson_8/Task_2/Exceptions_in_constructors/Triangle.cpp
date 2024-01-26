#include"Triangle.h"


int a, b, c, A, B, C;
Triangle::Triangle() :Triangle(10, 20, 30, 50, 60, 70) { }
Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    sides_count = 3;
    if (!check())
        throw Figure_error("the sum of the angles '!=' 180\n");
    get_name("Triangle");
}
void Triangle::conductor()
{
    get_Triangle();
}
void Triangle::get_Triangle()
{
    std::cout << name << " (Sides " << a << ", " << b << ", " << c <<
        "; Corners " << A << ", " << B << ", " << C << ") generated" << std::endl;
    std::cout << std::endl;
}
bool Triangle::check()
{
    return ((A + B + C) == 180 && sides_count == 3);
}