#include <iostream>
#include "smart_array.h"



int main(int argv, char* argc) {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(35);
		arr.add_element(100);
		std::cout << "Solution Task 1. Smart array: ";
		std::cout << arr.get_element(6) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Solution Task 2. Copying Smart arrays: \n";
	std::cout << "Arrays before copying \n";
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	std::cout << "\tarr:\t";
	arr.print_logical_arr();

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);
	std::cout << "  new_array:\t";
	new_array.print_logical_arr();
	std::cout << std::endl;

	arr = new_array;

	std::cout << "Arrays after copying and modification \n";
	arr.add_element(56);
	std::cout << "\tarr:\t";
	arr.print_logical_arr();

	new_array.add_element(22);
	new_array.add_element(3);
	std::cout << "  new_array:\t";
	new_array.print_logical_arr();

	return 0;
}

