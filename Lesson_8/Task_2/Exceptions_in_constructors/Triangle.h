#include <iostream>
#include"Figure_error.h"
#include"Figure.h"
#pragma once

class Triangle : public Figure
{
protected:
    int a, b, c, A, B, C;
    Triangle(int a, int b, int c, int A, int B, int C);
    Triangle(int a, int b, int c, int A, int B);
    Triangle(int a, int b, int A, int B);
    Triangle(int a, int A);
    void conductor() override;
    void get_Triangle();
    bool check() override;
public:
    Triangle();
};
