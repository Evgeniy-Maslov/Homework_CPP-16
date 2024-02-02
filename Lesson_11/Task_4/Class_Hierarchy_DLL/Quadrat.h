#pragma once
#include"Rectangle.h"
#include"Header.h"

namespace DynamicFigure
{
    class Quadrat : public Rectangle
    {
    protected:
        Quadrat(int);
        bool check() override;
        void print_info() override;
    public:
        CLASS_HIERARCHY_API Quadrat();
    };
}