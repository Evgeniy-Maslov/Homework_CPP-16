#include"Parallelogram.h"
#pragma once

class Rhomb :public Parallelogram
{
protected:
    Rhomb(int);
    bool check() override;
    void print_info() override;
public:
    Rhomb();
};