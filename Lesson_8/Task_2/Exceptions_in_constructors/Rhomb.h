#include"Parallelogram.h"
#pragma once

class Rhomb :public Parallelogram
{
protected:
    Rhomb(int a);
    bool check() override;
    bool check_Rhomb();
public:
    Rhomb();
};