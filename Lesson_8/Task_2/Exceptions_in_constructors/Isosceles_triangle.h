#include"Triangle.h"
#pragma once

class Isosceles_triangle :public Triangle
{
protected:
    Isosceles_triangle(int a, int b, int A, int B);
    bool check() override;
public:
    Isosceles_triangle();
};