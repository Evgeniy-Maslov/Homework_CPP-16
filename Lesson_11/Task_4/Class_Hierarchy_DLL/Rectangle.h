#pragma once
#include "Parallelogram.h"
#include "Header.h"

namespace DynamicFigure
{
    class Rectangle :public Parallelogram
    {
    protected:
        Rectangle(int, int);
        bool check() override;
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Rectangle();
    };
}