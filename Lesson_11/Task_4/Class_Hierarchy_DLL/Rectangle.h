#pragma once
#include"Parallelogram.h"
#include"Header.h"

namespace DynamicFigure
{
    class Rectangle :public Parallelogram
    {
    protected:
        Rectangle(int, int);
        bool check() override;
        void print_info() override;
    public:
        CLASS_HIERARCHY_API Rectangle();
    };
}