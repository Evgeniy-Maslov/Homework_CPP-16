#include"Triangle.h"
#pragma once

class Equilateral_triangle :public Triangle
{
protected:
    Equilateral_triangle(int, int);
    bool check() override;
    void print_info() override;
public:
    Equilateral_triangle();
};
