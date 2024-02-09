#pragma once
#include "Quadrilateral.h"
#include "Header.h"

namespace DynamicFigure
{
    class Parallelogram :public Quadrilateral
    {
    protected:
        Parallelogram(int, int, int, int);
        bool check() override;
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Parallelogram();
    };
}