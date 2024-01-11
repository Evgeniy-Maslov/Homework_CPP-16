#include <iostream>

class Figure
{
    int sides_count;
    std::string name;
protected:

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
    void get_sides_count()
    {
        std::cout << name << ": " << sides_count << "\n";
    }
};

class Triangle : public Figure
{
    Triangle(int sides_count) : Figure(sides_count)
    {
        get_name("Triangle");
    }
public:
    Triangle() :Triangle(3) { }
};

class Quadrilateral : public Figure
{
    Quadrilateral(int sides_count) : Figure(sides_count)
    {
        get_name("Quadrilateral");
    }
public:
    Quadrilateral() :Quadrilateral(4) { }
};

int main(int argc, char** argv)
{
    std::cout << "Number of sides:\n";
    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;
    figure.get_sides_count();
    triangle.get_sides_count();
    quadrilateral.get_sides_count();

    return 0;
}