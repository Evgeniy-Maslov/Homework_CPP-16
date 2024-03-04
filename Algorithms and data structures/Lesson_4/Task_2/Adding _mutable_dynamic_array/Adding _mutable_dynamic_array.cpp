#include <iostream>
#include <format>


namespace my_space
{
    int* arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; i++)
    {
        if (i < logical_size)
        {
            std::cout << std::format("{} ", arr[i]);
        }
        else
        {
            std::cout << std::format("{} ", "_ ");
        }
    }
    std::cout << std::endl;
}
void append_to_dynamic_array(int* &arr, int& logical_size, int& actual_size, int element)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = element;
        logical_size++;
    }
    else
    {
        actual_size *= 2;
        int* temp_arr = new int[actual_size]();
        for (int i = 0; i < logical_size; i++)
        {
            temp_arr[i] = arr[i];
        }
        temp_arr[logical_size] = element;
        logical_size++;
        delete[] arr;
        arr = new int[actual_size]();
        for (int i = 0; i < logical_size; i++)
        {
            arr[i] = temp_arr[i];
        }
        delete[] temp_arr;
    }
}



int main()
{
    int actual_size;
    int logical_size;
    int element{};
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
        my_space::arr = new int[actual_size]();
        for (int i = 0; i < logical_size; i++)
        {
            std::cout << std::format("Enter arr[{}]: ", i);
            std::cin >> my_space::arr[i];
        }
        std::cout << "Dynamic array: ";
        print_dynamic_array(my_space::arr, logical_size, actual_size);
        do
        {
            std::cout << "Enter the element to add: ";
            std::cin >> element;
            if (element)
            {
                append_to_dynamic_array(my_space::arr, logical_size, actual_size, element);
                std::cout << "Dynamic array: ";
                print_dynamic_array(my_space::arr, logical_size, actual_size);
            }
            else
            {
                std::cout << "Thanks! Your array: ";
                print_dynamic_array(my_space::arr, logical_size, actual_size);
            }
        } while (element);
        delete[] my_space::arr;
    }
    return 0;
}