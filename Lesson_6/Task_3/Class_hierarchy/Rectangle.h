#pragma once
#include"Parallelogram.h"

class Rectangle :public Parallelogram
{
protected:
    Rectangle(int, int);
    bool check() override;
    void print_info() override;
public:
    Rectangle();
};