#include"Rhomb.h"
#include"Bad_Error.h"
#include "Figure.h"

Rhomb::Rhomb() : Rhomb(30, 100, 80) { }
Rhomb::Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
{
    if (!check())
    {
        throw Figure_error("all sides '!=' or angles 'A', 'C' and 'B', 'D' in pairs '!='\n");
    }
    set_name("Rhomb");
}
bool Rhomb::check()
{
    return (d == c);
}