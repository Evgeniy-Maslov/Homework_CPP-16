#pragma once
#include"Parallelogram.h"

class Rhomb :public Parallelogram
{
protected:
    Rhomb(int, int, int);
    bool check() override;
    void print_info() override;
public:
    Rhomb();
};