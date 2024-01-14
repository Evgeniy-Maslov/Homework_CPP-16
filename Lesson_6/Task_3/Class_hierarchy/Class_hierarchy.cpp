#include"Equilateral_triangle.h"
//#include"Figure.h"
#include"Isosceles_triangle.h"
#include"Right_angled_triangle.h"
//#include"Triangle.h"
//#include"Quadrilateral.h"
//#include"Parallelogram.h"
#include"Rhomb.h"
//#include"Rectangle.h"
#include"Quadrat.h"


int main(int argc, char** argv)
{
    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;
    Right_angled_triangle right_angled_triangle;
    Isosceles_triangle isosceles_triangle;
    Equilateral_triangle equilateral_triangle;
    Parallelogram parallelogram;
    Rhomb rhomb;
    Rectangle rectangle;
    Quadrat quadrat;

    Figure* par_figure = &figure;
    Figure* par_triangle = &triangle;
    Figure* par_right_angled_triangle = &right_angled_triangle;
    Figure* par_isosceles_triangle = &isosceles_triangle;
    Figure* par_equilateral_triangle = &equilateral_triangle;
    Figure* par_quadrilateral = &quadrilateral;
    Figure* par_rectangle = &rectangle;
    Figure* par_quadrat = &quadrat;
    Figure* par_parallelogram = &parallelogram;
    Figure* par_rhomb = &rhomb;

    par_figure->print_info();
    par_triangle->print_info();
    par_right_angled_triangle->print_info();
    par_isosceles_triangle->print_info();
    par_equilateral_triangle->print_info();
    par_quadrilateral->print_info();
    par_rectangle->print_info();
    par_quadrat->print_info();
    par_parallelogram->print_info();
    par_rhomb->print_info();

    return 0;
}