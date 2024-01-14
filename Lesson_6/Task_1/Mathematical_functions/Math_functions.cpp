#include "Math_functions.h"
#include"print.h"


double Addition(double x, int y) { return x + y; }
double Subtraction(double x, int y) { return x - y; }
double Multiplication(double x, int y) { return x * y; }
double Division(double x, int y) { return x / y; }
double Exponentiation(double x, int y)
{
    double result = 1;
    int i;
    for (i = 1; i <= y; i++)
    {
        result = result * x;
    }
    return(result);
}
