#include <iostream>
#include"Figure_error.h"
#pragma once


class Figure
{
protected:
    std::string name;
    int sides_count;
    void get_name(std::string m_name);
    Figure(int sides_count);
public:
    Figure();
    virtual void conductor();
    virtual bool check();
    void get_sides_count();
};