#pragma once
#include "Parallelogram.h"
#include "Header.h"

namespace DynamicFigure
{
    class Rhomb :public Parallelogram
    {
    protected:
        Rhomb(int, int, int);
        bool check() override;
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Rhomb();
    };
}