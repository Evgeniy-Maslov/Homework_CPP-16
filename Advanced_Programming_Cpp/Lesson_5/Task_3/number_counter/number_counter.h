#pragma once
#include <vector>
#include <iostream>

class number_counter
{
	std::vector<int> m_vec;
	int m_sum;
	int m_count;
	int get_sum();
	int get_count();
public:
	number_counter(std::vector<int>);
	void operator()();
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& c);


