#include"Parallelogram.h"


Parallelogram::Parallelogram() : Parallelogram(20, 30, 100, 80) { }
Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, A, B)
{
    this->a = a;
    this->b = b;
    c = a;
    d = b;
    this->A = A;
    this->B = B;
    C = A;
    D = B;
    if (!check())
    {
        if (!check_Parallelogram())
        {
            throw Figure_error("the sum of the angles '!=' 360, sides 'a', 'c' and 'b', 'd' in pairs '!=' or angles 'A', 'C' and 'B', 'D' in pairs '!='\n");
        }
        throw Figure_error("the sum of the angles '!=' 360\n");
    }
    else if (!check_Parallelogram())
    {
        throw Figure_error("sides 'a', 'c' and 'b', 'd' in pairs '!=' or angles 'A', 'C' and 'B', 'D' in pairs '!='\n");
    }
    get_name("Parallelogram");
}
Parallelogram::Parallelogram(int a, int b) : Quadrilateral(a, b)
{
    this->a = a;
    this->b = b;
    get_name("Parallelogram");
}
Parallelogram::Parallelogram(int a) : Quadrilateral(a)
{
    this->a = a;
    A = 100;
    B = 80;
    C = A;
    D = B;
    get_name("Parallelogram");
}
bool Parallelogram::check()
{
    return (Quadrilateral::check());
}
bool Parallelogram::check_Parallelogram()
{
    return (a == c && b == d && A == C && B == D);
}