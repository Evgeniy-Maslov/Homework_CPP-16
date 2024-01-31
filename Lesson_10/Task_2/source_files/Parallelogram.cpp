#include"Parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B): Quadrilateral(a, b, a, b, A, B, A, B)
{
    get_name("Parallelogram");
}
bool Parallelogram::check()
{
    return (Quadrilateral::check() && a == c && b == d && A == C && B == D);
}
void Parallelogram::print_info()
{
    Quadrilateral::print_info();
}
Parallelogram::Parallelogram() : Parallelogram(20, 30, 30, 40) { }