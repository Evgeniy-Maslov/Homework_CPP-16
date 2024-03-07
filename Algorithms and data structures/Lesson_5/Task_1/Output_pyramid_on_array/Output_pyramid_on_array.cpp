#include <iostream>
#include <format>


void Source_array(int* pyramid, int size)
{
    std::cout << "Source array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << std::format("{} ", pyramid[i]);
    }
    std::cout << std::endl;
}

int level(int n, int h) // ВЫЧИСЛЕНИЕ УРОВНЯ ПИРАМИДЫ
{
    if (n == 0) { return h; }
    else { h++; level((n - 1) / 2, h); }
}

int parent_index(int n) // ИНДЕКС РОДИТЕЛЯ
{
    return (n - 1) / 2;
}

int child_index(int n) // ИНДЕКС РЕБЁНКА
{
    return  2 * (n - 1) / 2 + 1;
}

void print_pyramid(int* pyramid, int index, int size)
{
    int h{}; // ЗНАЧЕНИЕ УРОВНЯ ПИРАМИДЫ
    if (index == 0)
    {
        std::cout << std::format("{} root {}\n", 0, pyramid[index]);
        index++;
    }
    else if (index < size)
    {
        std::cout << std::format("{} {}({}) {}\n", level(index, h), child_index(index) % 2 ? "left" : "right", pyramid[parent_index(index)], pyramid[child_index(index)]);
        index++;
    }
    else
    {
        std::cout << std::endl;
        return;
    }
    print_pyramid(pyramid, index, size);
}

int main(int argc, char** argv)
{
    int pyramid_0[] = { 1, 3, 6, 5, 9, 8 };
    int pyramid_1[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int pyramid_2[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size_pyramid_0 = sizeof(pyramid_0) / sizeof(int);
    int size_pyramid_1 = sizeof(pyramid_1) / sizeof(int);
    int size_pyramid_2 = sizeof(pyramid_2) / sizeof(int);
    int index{};

    Source_array(pyramid_0, size_pyramid_0);
    std::cout << "Pyramid:\n";
    print_pyramid(pyramid_0, index, size_pyramid_0);

    Source_array(pyramid_1, size_pyramid_1);
    std::cout << "Pyramid:\n";
    print_pyramid(pyramid_1, index, size_pyramid_1);

    Source_array(pyramid_2, size_pyramid_2);
    std::cout << "Pyramid:\n";
    print_pyramid(pyramid_2, index, size_pyramid_2);

    return 0;
}

