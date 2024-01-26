#include"Quadrilateral.h"


Quadrilateral::Quadrilateral() :Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80) { }
Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    sides_count = 4;
    if (!check())
    {
        throw Figure_error("the sum of the angles '!=' 360\n");
    }
    get_name("Quadrilateral");
}
void Quadrilateral::conductor()
{
    get_Quadrilateral();
}
void Quadrilateral::get_Quadrilateral()
{
    std::cout << name << " (Sides " << a << ", " << b << ", " << c << ", " << d <<
        "; Corners " << A << ", " << B << ", " << C << ", " << D << ") generated" << std::endl;
    std::cout << std::endl;
}
bool Quadrilateral::check()
{
    return ((A + B + C + D) == 360 && sides_count == 4);
}