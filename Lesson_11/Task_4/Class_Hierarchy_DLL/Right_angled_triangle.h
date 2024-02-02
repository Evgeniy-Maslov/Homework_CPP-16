#pragma once
#include"Triangle.h"
#include"Header.h"

namespace DynamicFigure
{
    class Right_angled_triangle :public Triangle
    {
    protected:
        Right_angled_triangle(int, int, int, int, int);
        bool check() override;
        void print_info() override;
    public:
        CLASS_HIERARCHY_API Right_angled_triangle();
    };
}