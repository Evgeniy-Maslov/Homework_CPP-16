#pragma once

enum class Select
{
    addition = 1,
    subtraction,
    multiplication,
    division,
    exponentiation
};

void print(Select a, double &x, int &y );