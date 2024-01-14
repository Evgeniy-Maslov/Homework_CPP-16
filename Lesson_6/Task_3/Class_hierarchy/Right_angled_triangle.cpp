#include"Right_angled_triangle.h"


Right_angled_triangle::Right_angled_triangle(int a, int b, int c, int A, int B)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    C = 90;
    get_name("Right_angled_triangle");
}
bool Right_angled_triangle::check()
    {
        return (Triangle::check() && C == 90);
    }
void Right_angled_triangle::print_info()
{
    Triangle::print_info();
}
Right_angled_triangle::Right_angled_triangle() :Right_angled_triangle(10, 20, 30, 50, 60) { }
//Right_angled_triangle::Right_angled_triangle() :Right_angled_triangle(10, 20, 30, 50, 40) { }