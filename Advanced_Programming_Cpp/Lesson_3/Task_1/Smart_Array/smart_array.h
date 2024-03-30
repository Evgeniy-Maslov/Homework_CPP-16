#pragma once
#include <iostream>

class smart_array {
	int* array_ptr;
	int size_;
	int logical_size;
public:
	smart_array(int);
	smart_array(const smart_array&);
	smart_array& operator=(const smart_array& other);
	void add_element(int);
	int get_element(int);
	void print_logical_arr();
	~smart_array();
};

