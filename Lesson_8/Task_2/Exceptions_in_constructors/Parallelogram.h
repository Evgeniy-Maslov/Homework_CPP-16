#include"Quadrilateral.h"
#pragma once

class Parallelogram :public Quadrilateral
{
protected:
    Parallelogram(int a, int b, int A, int B);
    bool check() override;
public:
    Parallelogram();
};