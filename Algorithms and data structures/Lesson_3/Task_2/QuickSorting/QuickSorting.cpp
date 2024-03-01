#include <iostream>


void swap(int* arr, int left, int right)
{
    int boofer = arr[left];
    arr[left] = arr[right];
    arr[right] = boofer;  
}

void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//int pivoting(int* arr, int pi, int size)
//{
//    int pivot = arr[pi];
//    int left = 0;
//    int right = size - 1;
//    while (true)
//    {
//        while (arr[left] < pivot)
//            ++left;
//        while (arr[right] > pivot)
//            --right;
//        if (left >= right)
//            return left;
//        //break;
//        else
//        {
//            swap(arr, left, right);
//            ++left;
//            --right;
//        }
//
//    }
//}

void quick_sort(int* arr, int size)
{
    if (size < 2)
        return;
    else
    {
        int pi = size / 2;
        //int border = pivoting(arr, pi, size);
        int pivot = arr[pi];
        int left = 0;
        int i = left;
        int right = size - 1;
        int j = right;
        //int right_border = size;

        do
        {
            while (arr[i] <= pivot) { ++i; }
            while (arr[j] > pivot) { --j; }
            if (i <= j)
            {
                swap(arr, i, j);
                ++i;
                --j;
            }
        } while (i <= j);
                //swap(arr, pi, left);
        if (left < j) quick_sort(arr, i );
        if (i < right) quick_sort(arr + i , size - i);
                //break;
        
        
    }
    return;
}

int main(int argc, char** argv)
{
    int arr_0[] = { 3, 43, 38, 29,  72, 18, 57 };
    int arr_1[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr_2[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size_0 = sizeof(arr_0) / sizeof(int);
    int size_1 = sizeof(arr_1) / sizeof(int);
    int size_2 = sizeof(arr_2) / sizeof(int);

    std::cout << "Source array: ";
    print_arr(arr_0, size_0);
    quick_sort(arr_0, size_0);
    std::cout << "Sorted array: ";
    print_arr(arr_0, size_0);
    std::cout << std::endl;
   

    std::cout << "Source array: ";
    print_arr(arr_1, size_1);
    quick_sort(arr_1, size_1);
    std::cout << "Sorted array: ";
    print_arr(arr_1, size_1);
    std::cout << std::endl;

    std::cout << "Source array: ";
    print_arr(arr_2, size_2);
    quick_sort(arr_2, size_2);
    std::cout << "Sorted array: ";
    print_arr(arr_2, size_2);
    std::cout << std::endl;


    

    return 0;
}