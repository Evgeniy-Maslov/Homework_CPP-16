#pragma once
#include<string>
#include"Header.h"


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
        CLASS_HIERARCHY_API Figure();
        virtual void print_info();
        virtual bool check();
    };
}
