#include <iostream>

        //класс "Фигура"

class Figure
{
protected:
    std::string name;
    int sides_count;
    void get_name(std::string m_name)
    {
        name = m_name;
    }
    Figure(int sides_count)
    {
        this->sides_count = sides_count;
        get_name("Figure");
    }
public:
    Figure() :Figure(0) { }
    virtual void conductor() { }
    void get_sides_count()
    {
        std::cout << name << ": " << sides_count << std::endl;
    }
};

        //класс "Треугольник"

class Triangle : public Figure
{
protected:
    int a, b, c, A, B, C;
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        sides_count = 3;
        get_name("Triangle");
    }
    void conductor() override
    {
        get_Triangle();
    }
    void get_Triangle() 
    {
        std::cout << name << ":" << std::endl;
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
public:
    Triangle() :Triangle(10, 20, 30, 50, 60, 70) { }
};

        //класс "Прямоугольный треугольник"

class Right_angled_triangle :public Triangle
{
protected:
    Right_angled_triangle(int a, int b, int c, int A, int B)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        C = 90;
        get_name("Right_angled_triangle");
    }
public:
    Right_angled_triangle() :Right_angled_triangle(10, 20, 30, 50, 60) { }
};

        //класс "Равнобедренный треугольник"

class Isosceles_triangle :public Triangle
{
protected:
    Isosceles_triangle(int a, int b, int A, int B)
    {
        this->a = a;
        this->b = b;
        c = a;
        this->A = A;
        this->B = B;
        C = A;
        get_name("Isosceles_triangle");
    }
public:
    Isosceles_triangle() :Isosceles_triangle(10, 20, 50, 60) { }
}; 

        //класс "Равносторонний треугольник"

class Equilateral_triangle :public Triangle
{
protected:
    Equilateral_triangle(int a, int A)
    {
        this->a = a;
        b = a;
        c = a;
        this->A = A;
        B = A;
        C = A;
        get_name("Equilateral_triangle");
    }
public:
    Equilateral_triangle() :Equilateral_triangle(30, 60) { }
};

        //класс "Четырёхугольник"

class Quadrilateral : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        sides_count = 4;
        get_name("Quadrilateral");
    }
    void conductor() override
    {
        get_Quadrilateral();
    }
    void get_Quadrilateral()
    {
        std::cout << name << ":" <<std::endl;
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
public:
    Quadrilateral():Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80) { }
};

        //класс "Параллелограмм"

class Parallelogram :public Quadrilateral
{
protected:
    Parallelogram(int a, int b, int A, int B)
    {
        this->a = a;
        this->b = b;
        c = a;
        d = b;
        this->A = A;
        this->B = B;
        C = A;
        D = B;
        get_name("Parallelogram");
    }
public:
    Parallelogram() : Parallelogram(20, 30, 30, 40) { }
};

        //класс "Ромб"

class Rhomb :public Parallelogram
{
protected:
    Rhomb(int a)
    {
        this->a = a;
        c = a;
        b = a;
        d = a;
        get_name("Rhomb");
    }
public:
    Rhomb(): Rhomb(30) { }
};

        //класс "Прямоугольник"

class Rectangle :public Parallelogram
{
protected:
    Rectangle(int a, int b)
    {
        this->a = a;
        this->b = b;
        c = a;
        d = b;
        A = B = C = D = 90;
        get_name("Rectangle");
    }
public:
    Rectangle(): Rectangle(10, 20) { }
};

       //класс "Квадрат"

class Quadrat: public Rectangle
{
protected:
    Quadrat(int a)
    {
        this->a = a;
        this->d = a;
        this->b = a;
        this->c = a;
        get_name("Quadrat");
    }
public:
    Quadrat(): Quadrat(20) { }
};

void print_info(Figure* a)
{
    a->conductor();
}

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

    Figure* par_triangle = &triangle;
    Figure* par_right_angled_triangle = &right_angled_triangle;
    Figure* par_isosceles_triangle = &isosceles_triangle;
    Figure* par_equilateral_triangle = &equilateral_triangle;
    Figure* par_quadrilateral = &quadrilateral;
    Figure* par_rectangle = &rectangle;
    Figure* par_quadrat = &quadrat;
    Figure* par_parallelogram = &parallelogram;
    Figure* par_rhomb = &rhomb;
    
    print_info(par_triangle);
    print_info(par_right_angled_triangle);
    print_info(par_isosceles_triangle);
    print_info(par_equilateral_triangle);
    print_info(par_quadrilateral);
    print_info(par_rectangle);
    print_info(par_quadrat);
    print_info(par_parallelogram);
    print_info(par_rhomb);

    return 0;
}