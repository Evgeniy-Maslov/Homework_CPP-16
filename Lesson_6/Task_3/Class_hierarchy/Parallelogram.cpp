#include"Parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B)
{
    this->a = a;
    this->b = b;
    c = a;
    d = b;
    this->A = A;
    this->B = B;
    C = A;
    D = B;
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