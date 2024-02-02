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
        void print_info() override;
        CLASS_HIERARCHY_API Triangle();
    };
}