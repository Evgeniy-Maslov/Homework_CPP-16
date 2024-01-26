#include"Figure.h"
#pragma once

class Quadrilateral : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    void conductor() override;
    void get_Quadrilateral();
    bool check() override;
public:
    Quadrilateral();
};