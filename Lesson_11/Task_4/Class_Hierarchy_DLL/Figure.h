#pragma once
#include <string>
#include "Header.h"


namespace DynamicFigure
{
    class Figure
    {
    protected:
        std::string name;
        int sides_count;
        void get_name(std::string);
        Figure(int);
    public:
        Class_Hierarchy_DLL_API Figure();
        Class_Hierarchy_DLL_API virtual void print_info();
        virtual bool check();
    };
}
