#pragma once
#include <string>

class Figure
{
protected:
    std::string name;
    int sides_count;
    void set_name(std::string m_name);
    Figure(int sides_count);
public:
    Figure();
    virtual void conductor();
    virtual bool check();
    void get_sides_count();
};