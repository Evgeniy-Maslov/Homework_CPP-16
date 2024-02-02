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
        DYNAMIC_LIBRARY_API Rectangle();
    };
}