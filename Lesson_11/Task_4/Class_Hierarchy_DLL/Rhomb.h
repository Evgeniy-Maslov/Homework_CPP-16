#pragma once
#include"Parallelogram.h"
#include"Header.h"

namespace DynamicFigure
{
    class Rhomb :public Parallelogram
    {
    protected:
        Rhomb(int, int, int);
        bool check() override;
        void print_info() override;
    public:
        CLASS_HIERARCHY_API Rhomb();
    };
}