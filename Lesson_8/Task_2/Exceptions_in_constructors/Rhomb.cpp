#include"Rhomb.h"


Rhomb::Rhomb() : Rhomb(30) { }
Rhomb::Rhomb(int a) : Parallelogram(a)
{
    this->a = a;
    c = a;
    b = a;
    d = 7; // Искусственно внесенная ошибка
    //  d = a; // Павильный параметр
    if (!check())
    {
        if (!check_Rhomb())
        {
            throw Figure_error("the sum of the angles '!=' 360, all sides!= or angles 'A', 'C' and 'B', 'D' in pairs '!='\n");
        }
        throw Figure_error("the sum of the angles '!=' 360\n");
    }
    else if (!check_Rhomb())
    {
        throw Figure_error("all sides '!=' or angles 'A', 'C' and 'B', 'D' in pairs '!='\n");
    }
    get_name("Rhomb");
}
bool Rhomb::check()
{
    return (Quadrilateral::check());
}
bool Rhomb::check_Rhomb()
{
    return (d == c && Parallelogram::check_Parallelogram());
}