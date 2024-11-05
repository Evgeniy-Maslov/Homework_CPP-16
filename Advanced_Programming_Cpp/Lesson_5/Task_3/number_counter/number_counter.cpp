#include "number_counter.h"
#include <iostream>
#include <algorithm>
#include <vector>

number_counter::number_counter() {}

int number_counter::get_sum() {
	return m_sum;
}

int number_counter::get_count() {
	return m_count;
}

void number_counter::operator()(const int& i) {
	m_value = i;
	if (!(m_value % 3))
	{
		m_sum += m_value;
		m_count += 1;
	}
}

std::ostream& operator << (std::ostream & os, const std::vector<int>&c)
{
	std::for_each(c.begin(), c.end(), [&](int i) { os << i << " "; });
	return os;
}
