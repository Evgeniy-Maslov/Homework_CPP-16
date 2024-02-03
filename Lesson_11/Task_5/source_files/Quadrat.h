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
        Class_Hierarchy_DLL_API void print_info() override;
    public:
        Class_Hierarchy_DLL_API Quadrat();
    };
}