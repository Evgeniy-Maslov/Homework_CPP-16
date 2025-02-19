#pragma once
#include"Triangle.h"

class Equilateral_triangle :public Triangle
{
protected:
    Equilateral_triangle(int a);
    bool check() override;
public:
    Equilateral_triangle();
};