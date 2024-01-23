#include"Right_angled_triangle.h"


Right_angled_triangle::Right_angled_triangle() :Right_angled_triangle(10, 20, 30, 50, 40) { }
Right_angled_triangle::Right_angled_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    B = 50;        // Искусственно внесенная ошибка
    this->B = B;
    // C = 90;
    C = 80;       // Искусственно внесенная ошибка
    if (!check())
    {
        if (!check_Right_angled_triangle())
        {
            throw Figure_error("the sum of the angles '!=' 180, angle 'C' '!=' 90\n");
        }
        throw Figure_error("the sum of the angles '!=' 180\n");
    }
    else if (!check_Right_angled_triangle())
    {
        throw Figure_error("angle 'C' '!=' 90\n");
    }
    get_name("Right_angled_triangle");
}
bool Right_angled_triangle::check()
{
    return (Triangle::check());
}
bool Right_angled_triangle::check_Right_angled_triangle()
{
    return (C == 90);
}