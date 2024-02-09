#pragma once
#include "Figure.h"
#include "Header.h"

namespace DynamicFigure
{
    class Quadrilateral : public Figure
    {
    protected:
        int a, b, c, d;
        int A, B, C, D;
        Quadrilateral(int, int, int, int, int, int, int, int);
        bool check() override;
    public:
        Class_Hierarchy_DLL_API Quadrilateral();
        Class_Hierarchy_DLL_API void print_info() override;
    };
}