#pragma once
#include"Triangle.h"

class Right_angled_triangle :public Triangle
{
protected:
    Right_angled_triangle(int a, int b, int c, int A, int B);
    bool check() override;
public:
    Right_angled_triangle();
};