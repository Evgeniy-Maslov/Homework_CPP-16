#pragma once
#include <vector>
#include <iostream>

class number_counter
{
	int m_value;
	int m_sum{0};
	int m_count{0};
public:
	int get_sum();
	int get_count();
	number_counter();
	void operator()(const int& i);
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& c);


