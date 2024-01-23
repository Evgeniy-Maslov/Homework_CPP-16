#include"Parallelogram.h"
#pragma once

class Rectangle :public Parallelogram
{
protected:
    Rectangle(int a, int b);
    Rectangle(int a);
    bool check() override;
    bool check_Rectangle();
public:
    Rectangle();
};
