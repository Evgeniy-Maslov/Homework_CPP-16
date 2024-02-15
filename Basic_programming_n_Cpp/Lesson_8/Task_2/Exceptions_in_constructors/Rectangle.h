#pragma once
#include"Parallelogram.h"

class Rectangle :public Parallelogram
{
protected:
    Rectangle(int a, int b);
    bool check() override;
public:
    Rectangle();
};