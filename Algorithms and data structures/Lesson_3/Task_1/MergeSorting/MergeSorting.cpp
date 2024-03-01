#include <iostream>

void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge_sort(int* arr, int size)
{
    if (size < 2)
        return;
    else
    {
        int mid = size / 2;
        int* left = new int[mid];
        int* right = new int[size - mid];
        for (int i = 0; i < mid; i++)
        {
            left[i] = arr[i];
            right[i] = arr[i + mid];
        }
        if (size % 2 == 1)
            right[mid] = arr[size - 1];
        merge_sort(left, mid);
        merge_sort(right, size - mid);
        int il = 0;
        int ir = 0;
        int ia = 0;
        while (il < mid || ir < size - mid )
        {
            if (ir == size - mid)
            {
                arr[ia] = left[il];
                il++;
            }
            else if (il == mid)
            {
                arr[ia] = right[ir];
                ir++;
            }
            else
                if (left[il] <= right[ir])
                {
                    arr[ia] = left[il];
                    il++;
                }
                else
                {
                    arr[ia] = right[ir];
                    ir++;
                }
                ia++;
        }
        delete[] left;
        delete[] right;
    }
}

int main(int argc, char** argv)
{
    int arr_0[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr_1[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr_2[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size_0 = sizeof(arr_0) / sizeof(int);
    int size_1 = sizeof(arr_1) / sizeof(int);
    int size_2 = sizeof(arr_2) / sizeof(int);

    std::cout << "Source array: ";
    print_arr(arr_0, size_0);
    merge_sort(arr_0, size_0);
    std::cout << "Sorted array: ";
    print_arr(arr_0, size_0);
    std::cout << std::endl;

    std::cout << "Source array: ";
    print_arr(arr_1, size_1);
    merge_sort(arr_1, size_1);
    std::cout << "Sorted array: ";
    print_arr(arr_1, size_1);
    std::cout << std::endl;

    std::cout << "Source array: ";
    print_arr(arr_2, size_2);
    merge_sort(arr_2, size_2);
    std::cout << "Sorted array: ";
    print_arr(arr_2, size_2);
    std::cout << std::endl;

    return 0;
}