#include"Quadrat.h"


Quadrat::Quadrat() : Quadrat(20) { }
Quadrat::Quadrat(int a) : Rectangle(a)
{
    this->a = a;
    this->d = a;
    this->b = a;
    this->c = a;
    if (!check())
    {
        if (!check_Quadrat())
        {
            throw Figure_error("the sum of the angles '!=' 360, all sides '!=' or all corners '!=' 90\n");
        }
        throw Figure_error("the sum of the angles '!=' 360\n");
    }
    else if (!check_Quadrat())
    {
        throw Figure_error("all sides '!=' or all corners '!=' 90\n");
    }
    get_name("Quadrat");
}
bool Quadrat::check()
{
    return (Rectangle::check());
}
bool Quadrat::check_Quadrat()
{
    return (d == c && check_Rectangle());
}