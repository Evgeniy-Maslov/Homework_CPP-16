#include"Parallelogram.h"
#pragma once

class Rectangle :public Parallelogram
{
protected:
    Rectangle(int, int);
    bool check() override;
    void print_info() override;
public:
    Rectangle();
};