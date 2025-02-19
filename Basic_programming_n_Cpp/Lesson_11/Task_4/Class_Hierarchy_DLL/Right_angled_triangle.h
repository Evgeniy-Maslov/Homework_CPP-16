#pragma once
#include "Triangle.h"
#include "Header.h"

namespace DynamicFigure
{
    class Right_angled_triangle :public Triangle
    {
    protected:
        Right_angled_triangle(int, int, int, int, int);
        bool check() override;
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Right_angled_triangle();
    };
}