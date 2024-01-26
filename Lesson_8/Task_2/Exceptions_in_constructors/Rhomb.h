#include"Parallelogram.h"
#pragma once

class Rhomb :public Parallelogram
{
protected:
    Rhomb(int a, int A, int B);
    bool check() override;
public:
    Rhomb();
};