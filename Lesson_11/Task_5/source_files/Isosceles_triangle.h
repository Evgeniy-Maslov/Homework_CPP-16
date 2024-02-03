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
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Isosceles_triangle();
    };
}