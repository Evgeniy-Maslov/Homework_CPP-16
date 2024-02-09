#include <iostream>
#include "Quadrilateral.h"

namespace DynamicFigure
{
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
        get_name("Quadrilateral");
    }
    bool Quadrilateral::check()
    {
        return ((A + B + C + D) == 360 && sides_count == 4);
    }
    Quadrilateral::Quadrilateral() :Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80) { }
    void Quadrilateral::print_info()
    {
        std::cout << std::endl;
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
}