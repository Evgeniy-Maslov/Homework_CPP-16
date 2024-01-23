#include"Rectangle.h"


Rectangle::Rectangle(int a, int b) : Parallelogram(a, b)
{
    this->a = a;
    this->b = b;
    c = a;
    d = b;
    A = B = C = D = 90;
    //  A = B = C = 90;  // Искусственно внесенная ошибка
    //  D = 80;          // 
    if (!check())
    {
        if (!check_Rectangle())
        {
            throw Figure_error("the sum of the angles '!=' 360, all corners '!=' 90\n");
        }
        throw Figure_error("the sum of the angles '!=' 360\n");
    }
    else if (!check_Rectangle())
    {
        throw Figure_error("all corners '!=' 90\n");
    }
    get_name("Rectangle");
}
Rectangle::Rectangle(int a)
{
    this->a = a;
    A = B = C = D = 90;
}
bool Rectangle::check()
{
    return (Quadrilateral::check());
}
bool Rectangle::check_Rectangle()
{
    return (A == 90 && B == 90 && C == 90 && Parallelogram::check_Parallelogram());
}
Rectangle::Rectangle() : Rectangle(10, 20) { }
