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
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Equilateral_triangle();
    };
}