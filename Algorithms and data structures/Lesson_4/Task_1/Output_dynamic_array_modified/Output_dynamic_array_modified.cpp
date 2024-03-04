#include <iostream>
#include <format>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; i++)
    {
        if (i < logical_size)
        {
            std::cout << std::format("{} ", arr[i]);
        }
        else { std::cout << "_ "; }
    }
    std::cout << std::endl;
}

int main()
{
    int actual_size;
    int logical_size;
    std::cout << "Enter the actual size of the array: ";
    std::cin >> actual_size;
    std::cout << "Enter the logical size of the array: ";
    std::cin >> logical_size;
    if (logical_size > actual_size)
    {
        std::cout << "Error! The logical size of the array cannot exceed the actual size!";
        std::cout << std::endl;
    }
    else
    {
        int* arr = new int[actual_size]();
        for (int i = 0; i < logical_size; i++)
        {
            std::cout << std::format("Enter arr[{}]: ", i);
            std::cin >> arr[i];
        }
        std::cout << "Dynamic array: ";
        print_dynamic_array(arr, logical_size, actual_size);
        delete[] arr;
    }
    return 0;
}