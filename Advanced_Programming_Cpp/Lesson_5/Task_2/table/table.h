#pragma once
#include <format>
#include <iostream>


template<class T>
class table
{
	unsigned i_;
	unsigned j_;
	T** table_ptr_;
public:

	table(unsigned i, unsigned j)
	{
		i_ = i;
		j_ = j;
		table_ptr_ = new T * [i_];
		for (unsigned i = 0; i < i_; i++)
		{
			table_ptr_[i] = new T[j_];
		}
	}
	void print()
	{
		for (unsigned i = 0; i < i_; i++)
		{
			for (unsigned j = 0; j < j_; j++)
			{
				std::cout << std::format("{} ", table_ptr_[i][j]);
			}
			std::cout << std::endl;
		}
	}

	T* operator [] (unsigned i) {
		return table_ptr_[i];
	}
	const T* operator [](unsigned i) const {
		return table_ptr_[i];
	}

	T size()
	{
		return i_ * j_ * sizeof(T);
	}

	~table()
	{
		for (unsigned i = 0; i < i_; i++)
		{
			delete[] table_ptr_[i];
		}
		delete[] table_ptr_;
	}	
};

template<class T>
std::ostream& operator << (std::ostream& os, const table<T>& c)
{
	os << c.table_ptr_ << std::endl;
	return os;
}