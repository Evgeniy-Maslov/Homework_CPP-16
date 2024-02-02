#pragma once
#include"Rectangle.h"

class Quadrat : public Rectangle
{
protected:
    Quadrat(int);
    bool check() override;
    void print_info() override;
public:
    Quadrat();
};