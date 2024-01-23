#include"Triangle.h"
#pragma once

class Equilateral_triangle :public Triangle
{
protected:
    Equilateral_triangle(int a, int A);
    bool check() override;
    bool check_Equilateral_triangle();
public:
    Equilateral_triangle();
};