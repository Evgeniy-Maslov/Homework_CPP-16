#pragma once
#include"Quadrilateral.h"
#include"Header.h"

namespace DynamicFigure
{
    class Parallelogram :public Quadrilateral
    {
    protected:
        Parallelogram(int, int, int, int);
        bool check() override;
        void print_info() override;
    public:
        CLASS_HIERARCHY_API Parallelogram();
    };
}