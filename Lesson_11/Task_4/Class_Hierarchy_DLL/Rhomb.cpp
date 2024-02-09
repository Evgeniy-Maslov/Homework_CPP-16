#include "Rhomb.h"

namespace DynamicFigure
{
    Rhomb::Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
    {
        get_name("Rhomb");
    }
    bool Rhomb::check()
    {
        return (Parallelogram::check() && d == c);
    }
    void Rhomb::print_info()
    {
        Parallelogram::print_info();
    }
    Rhomb::Rhomb() : Rhomb(30, 70, 110) { }
}