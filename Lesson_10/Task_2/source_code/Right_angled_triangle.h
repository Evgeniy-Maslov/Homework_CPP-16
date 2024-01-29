#include"Triangle.h"
#pragma once

class Right_angled_triangle :public Triangle
{
protected:
    Right_angled_triangle(int, int, int, int, int);
    bool check() override;
    void print_info() override;
public:
    Right_angled_triangle();
};