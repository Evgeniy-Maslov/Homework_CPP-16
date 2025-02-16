#include"Quadrilateral.h"
#pragma once

class Parallelogram :public Quadrilateral
{
protected:
    Parallelogram(int, int, int, int);
    bool check() override;
    void print_info() override;
public:
    Parallelogram();
};