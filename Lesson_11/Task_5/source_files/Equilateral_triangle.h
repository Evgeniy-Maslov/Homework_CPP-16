#pragma once
#include"Triangle.h"
#include"Header.h"

namespace DynamicFigure
{
    class Equilateral_triangle :public Triangle
    {
    protected:
        Equilateral_triangle(int, int);
        bool check() override;
        void print_info() override;
    public:
        DYNAMIC_LIBRARY_API Equilateral_triangle();
    };
}