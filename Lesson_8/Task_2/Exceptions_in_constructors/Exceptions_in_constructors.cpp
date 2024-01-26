#include <iostream>
#include"Bad_Error.h"
#include"Figure.h"
#include"Triangle.h"
#include"Right_angled_triangle.h"
#include"Isosceles_triangle.h"
#include"Equilateral_triangle.h"
#include"Quadrilateral.h"
#include"Parallelogram.h"
#include"Rhomb.h"
#include"Rectangle.h"
#include"Quadrat.h"
#include"print_info.h"


int main(int argc, char** argv)
{
    try
    {
        Figure figure;
    }
    catch ( Figure_error& err)
    {
        std::cerr << err.what() << std::endl;
    }
    try
    {
        Triangle triangle;
        Figure* par_triangle = &triangle;
        print_info(par_triangle);
    }
    catch (Figure_error& err)
    {
        std::cerr <<err.getMessage()<< " " << err.what() << std::endl;
    }
    try
    {
        Right_angled_triangle right_angled_triangle;
        Figure* par_right_angled_triangle = &right_angled_triangle;
        print_info(par_right_angled_triangle);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage()<< " " << err.what() << std::endl;
    }
    try
    {
        Isosceles_triangle isosceles_triangle;
        Figure* par_isosceles_triangle = &isosceles_triangle;
        print_info(par_isosceles_triangle);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }
    try
    {
        Equilateral_triangle equilateral_triangle;
        Figure* par_equilateral_triangle = &equilateral_triangle;
        print_info(par_equilateral_triangle);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }
    try
    {
        Quadrilateral quadrilateral;
        Figure* par_quadrilateral = &quadrilateral;
        print_info(par_quadrilateral);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }
    try
    {
        Parallelogram parallelogram;
        Figure* par_parallelogram = &parallelogram;
        print_info(par_parallelogram);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }
    try
    {
        Rhomb rhomb;
        Figure* par_rhomb = &rhomb;
        print_info(par_rhomb);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }
    try
    {
        Rectangle rectangle;
        Figure* par_rectangle = &rectangle;
        print_info(par_rectangle);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }
    try
    {
        Quadrat quadrat;
        Figure* par_quadrat = &quadrat;
        print_info(par_quadrat);
    }
    catch (Figure_error& err)
    {
        std::cerr << err.getMessage() << " " << err.what() << std::endl;
    }

    return 0;
}