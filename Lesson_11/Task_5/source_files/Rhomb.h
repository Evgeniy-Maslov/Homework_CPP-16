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
        DYNAMIC_LIBRARY_API Rhomb();
    };
}