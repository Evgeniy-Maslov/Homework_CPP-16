#include "Right_angled_triangle.h"

namespace DynamicFigure
{
    Right_angled_triangle::Right_angled_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
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
}