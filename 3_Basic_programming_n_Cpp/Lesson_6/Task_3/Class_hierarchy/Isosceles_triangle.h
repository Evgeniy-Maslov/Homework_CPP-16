#pragma once
#include"Triangle.h"


class Isosceles_triangle :public Triangle
{
protected:
    Isosceles_triangle(int, int, int, int);
    bool check() override;
    void print_info() override;
public:
    Isosceles_triangle();
};