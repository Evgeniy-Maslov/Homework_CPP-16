#include"Right_angled_triangle.h"
#include "Bad_Error.h"

Right_angled_triangle::Right_angled_triangle() :Right_angled_triangle(10, 20, 30, 50, 60) { }
Right_angled_triangle::Right_angled_triangle(int a, int b, int c, int A,int B) : Triangle(a, b, c, A, B, 90)
{
    if (!check())
    {
        throw Figure_error("angle 'C' '!=' 90\n"); 
    }
    set_name("Right_angled_triangle");
}
bool Right_angled_triangle::check()
{
    return (C == 90);
}