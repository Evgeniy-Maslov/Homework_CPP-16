#include <iostream>
#include <format>

int  ArraySearch(int* arr, int size, int& point_reference)
{
	int left = 0;
	int right = size - 1;
	int middle;
	if (point_reference >= arr[right])
	{
		return 0;
	}
	else if (point_reference < arr[left])
	{
		return size;
	}
	else
	{
		while (left < right)
		{
			middle = (left + right) / 2;
			if (arr[middle] == point_reference)
				if (arr[middle] == arr[middle + 1])
					left = middle + 1;
				else
				{
					left = middle;
					break;
				}
			if (arr[middle] > point_reference)
			{
				right = middle;
			}
			else if (arr[middle] < point_reference)
			{
				left = middle;
				if (left + 1 == right) { break; }
			}
		}
		return  ((size - 1) - left);
	}
}

int main(int argc, char** argv)
{
	int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int point_reference{};
	std::cout << "Enter a reference point: ";
	std::cin >> point_reference;
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << std::format("The number of elements in the array is greater than {}: {} \n", point_reference, ArraySearch(arr, size, point_reference));
	
	return 0;
}