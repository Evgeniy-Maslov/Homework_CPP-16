#include"Parallelogram.h"
#pragma once

class Rhomb :public Parallelogram
{
protected:
    Rhomb(int, int, int);
    bool check() override;
    void print_info() override;
public:
    Rhomb();
};