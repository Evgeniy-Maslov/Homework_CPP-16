#include"Quadrilateral.h"
#pragma once

class Parallelogram :public Quadrilateral
{
public:
    Parallelogram();
protected:
    Parallelogram(int a, int b, int A, int B);
    Parallelogram(int a, int b);
    Parallelogram(int a);
    bool check() override;
    bool check_Parallelogram();
};