#include"Figure.h"
#pragma once

class Triangle : public Figure
{
protected:
    int a, b, c, A, B, C;
    Triangle(int, int, int, int, int, int);
    bool check() override;
public:
    void print_info() override;
    Triangle();
};