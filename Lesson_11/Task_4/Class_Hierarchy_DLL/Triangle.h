#pragma once
#include"Figure.h"
#include"Header.h"

namespace DynamicFigure
{
    class Triangle : public Figure
    {
    protected:
        int a, b, c, A, B, C;
        Triangle(int, int, int, int, int, int);
        bool check() override;
    public:
        Class_Hierarchy_DLL_API void print_info() override;
        Class_Hierarchy_DLL_API Triangle();
    };
}