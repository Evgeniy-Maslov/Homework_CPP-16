#include "smart_array.h"
#include <format>

smart_array::smart_array(int size) : size_{size}, array_ptr{new int[size]}, logical_size{0} {}

smart_array::smart_array(const smart_array& arr) : size_{arr.size_}, array_ptr{new int[arr.size_]}, logical_size{0}
{
    *array_ptr = *(arr.array_ptr);
}

smart_array& smart_array::operator=(const smart_array& other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] array_ptr;
    size_ = other.size_;
    logical_size = other.logical_size;
    array_ptr = new int[size_];
    for (int i = 0; i < size_; i++)
    {
        array_ptr[i] = other.array_ptr[i];
    }
    return *this;
}

void smart_array::add_element(int x)
{
    if (logical_size < size_) {
        array_ptr[logical_size] = x;
        logical_size++;
    }
    else
    {
        size_ *= 2;
        int* temp_arr = new int[size_]();
        for (int i = 0; i < logical_size; i++)
        {
            temp_arr[i] = array_ptr[i];
        }
        temp_arr[logical_size] = x;
        logical_size++;
        delete[] array_ptr;
        array_ptr = new int[size_]();
        for (int i = 0; i < logical_size; i++)
        {
            array_ptr[i] = temp_arr[i];
        }
        delete[] temp_arr;
    }
}

int smart_array::get_element(int element)
{
    if (element >= 0 and element < logical_size) {
        return array_ptr[element];
    }
    else
        throw std::out_of_range("Attempting to access items outside the allowed range!");
}

void smart_array::print_logical_arr()
{
    for (int i = 0; i < logical_size; i++) {
        std::cout << std::format("{} ", array_ptr[i]);
    }
    std::cout << std::endl;
}

smart_array::~smart_array() 
{
	delete[] array_ptr;
}
