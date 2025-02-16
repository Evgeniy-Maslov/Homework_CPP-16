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

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size)
{
    if (actual_size == 1) { arr = 0; logical_size--; }
    else if ((logical_size - 1) > (actual_size / 3))
    {
        logical_size--;
        for (int i = 0; i < logical_size; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[logical_size] = 0;
    }
    else
    {
        actual_size /= 3;
        logical_size--;
        int* temp_arr = new int[actual_size]();
        for (int i = 0; i < logical_size; i++)
        {
            temp_arr[i] = arr[i + 1];
        }
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
    std::string remove;
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
        while (true)
        {
            std::cout << "Delete the first element ? ";
            std::cin >> remove;
            if (remove == "yes")
            {
                if (logical_size == 0)
                {
                    std::cout << "The first element cannot be deleted because the array is empty. Goodbye!";
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    remove_dynamic_array_head(my_space::arr, logical_size, actual_size);
                    std::cout << "Dynamic array: ";
                    print_dynamic_array(my_space::arr, logical_size, actual_size);
                }
            }
            else if(remove == "no")
            {
                std::cout << "Thanks! Your dynamic array: ";
                print_dynamic_array(my_space::arr, logical_size, actual_size);
                break;
            }
        }
        delete[] my_space::arr;
    }
    return 0;
}