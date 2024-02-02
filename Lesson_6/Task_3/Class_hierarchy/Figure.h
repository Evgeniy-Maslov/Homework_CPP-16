#pragma once
#include<string>

class Figure
{
protected:
    std::string name;
    int sides_count;
    void get_name(std::string);
    Figure(int);
public:
    Figure();
    virtual void print_info();
    virtual bool check();
};