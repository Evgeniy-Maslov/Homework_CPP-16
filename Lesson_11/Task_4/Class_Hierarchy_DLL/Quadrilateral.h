#pragma once
#include"Figure.h"
#include"Header.h"

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
        CLASS_HIERARCHY_API Quadrilateral();
        void print_info() override;
    };
}