#include"Rectangle.h"
#include"Bad_Error.h"
#include "Figure.h"

Rectangle::Rectangle() : Rectangle(20, 30) { }
Rectangle::Rectangle(int a, int b) : Parallelogram(a, b, 90, 90)
{ 

    if (!check())
    {
        throw Figure_error("all corners '!=' 90\n");
    }
    set_name("Rectangle");
}
bool Rectangle::check()
{
    return (A == 90 && B == 90 && C == 90);
}