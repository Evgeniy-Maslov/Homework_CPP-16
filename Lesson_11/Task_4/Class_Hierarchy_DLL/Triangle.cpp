#include<iostream>
#include"Triangle.h"

namespace DynamicFigure
{
    Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        sides_count = 3;
        get_name("Triangle");
    }
    bool Triangle::check()
    {
        return ((A + B + C) == 180 && sides_count == 3);
    }
    void Triangle::print_info()
    {
        std::cout << std::endl;
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
    Triangle::Triangle() : Triangle(10, 20, 30, 50, 60, 70) { }
}