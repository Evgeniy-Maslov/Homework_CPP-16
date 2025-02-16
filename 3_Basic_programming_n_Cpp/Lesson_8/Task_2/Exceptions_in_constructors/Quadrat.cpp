#include"Quadrat.h"
#include"Bad_Error.h"
#include "Figure.h"

Quadrat::Quadrat(): Quadrat(20) { }
Quadrat::Quadrat(int a): Rectangle(a, a)
{
    if (!check())
    {
        throw Figure_error("all sides '!='\n");
    }
    set_name("Quadrat");
}
bool Quadrat::check()
{
    return (d == c);
}