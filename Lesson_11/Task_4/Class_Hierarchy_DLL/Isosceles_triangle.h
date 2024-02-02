#pragma once
#include"Triangle.h"
#include"Header.h"

namespace DynamicFigure
{
    class Isosceles_triangle :public Triangle
    {
    protected:
        Isosceles_triangle(int, int, int, int);
        bool check() override;
        void print_info() override;
    public:
        CLASS_HIERARCHY_API Isosceles_triangle();
    };
}