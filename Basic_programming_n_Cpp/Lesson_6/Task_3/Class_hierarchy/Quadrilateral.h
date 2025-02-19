#pragma once
#include"Figure.h"

class Quadrilateral : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;
    Quadrilateral(int, int, int, int, int, int, int, int);
    bool check() override;
public:
    Quadrilateral();
    void print_info() override;
};