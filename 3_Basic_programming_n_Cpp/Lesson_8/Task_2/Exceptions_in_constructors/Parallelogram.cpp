#include"Parallelogram.h"
#include "Bad_Error.h"
#include "Figure.h"

Parallelogram::Parallelogram() : Parallelogram(20, 30, 100, 80) { }
Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B)
{
    if (!check())
    {
        throw Figure_error("sides 'a', 'c' and 'b', 'd' in pairs '!=' or angles 'A', 'C' and 'B', 'D' in pairs '!='\n");
    }
    set_name("Parallelogram");
}
bool Parallelogram::check()
{
    return (a == c && b == d && A == C && B == D);
}