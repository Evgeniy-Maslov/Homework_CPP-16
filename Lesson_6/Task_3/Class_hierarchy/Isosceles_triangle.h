#include"Triangle.h"
#pragma once


class Isosceles_triangle :public Triangle
{
protected:
    Isosceles_triangle(int, int, int, int);
    bool check() override;
    void print_info() override;
public:
    Isosceles_triangle();
};