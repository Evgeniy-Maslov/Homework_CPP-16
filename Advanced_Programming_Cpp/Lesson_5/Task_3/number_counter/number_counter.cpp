#include "number_counter.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <format>

number_counter::number_counter(std::vector<int> vec) : m_vec(vec), m_sum{ 0 }, m_count{ 0 }{
	std::cout << "[IN]: " << m_vec << std::endl;
}

int number_counter::get_sum() {
	std::for_each(m_vec.begin(), m_vec.end(), [&](int& i)
		{
			if (!(i % 3))
			{
				m_sum += i;
			}
		});
	return m_sum;
}

int number_counter::get_count() {
	std::for_each(m_vec.begin(), m_vec.end(), [&](int& i)
		{
			if (!(i % 3))
			{
				m_count += 1;
			}
		});
	return m_count;
}

void number_counter::operator()() {
	std::cout << std::format("[OUT]: get_sum() = {}", get_sum()) << std::endl;
	std::cout << std::format("[OUT]: get_count() = {}", get_count()) << std::endl;
	m_sum = m_count = 0;
}

std::ostream& operator << (std::ostream & os, const std::vector<int>&c)
{
	std::for_each(c.begin(), c.end(), [&](int i) { os << i << " "; });
	return os;
}
