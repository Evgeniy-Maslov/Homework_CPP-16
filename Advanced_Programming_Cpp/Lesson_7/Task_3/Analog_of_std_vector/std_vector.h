#pragma once
#include <iostream>


template<class T>
class std_vector {
	unsigned logic_size_;
	unsigned actual_size_;
	T* vector_ptr;

public:
	std_vector(int n = 0) {
		logic_size_ = n;
		actual_size_ = n + 1;
		vector_ptr = new T[actual_size_]();
	}
	std_vector( std_vector& vec)
	{
		logic_size_ = vec.logic_size_;
		actual_size_ = vec.actual_size_;
		vector_ptr = new T[actual_size_];
		for (int i = 0; i < logic_size_; i++) {
			vector_ptr[i] = (vec.vector_ptr[i]);
		}
	}
	std_vector& operator = (std_vector& other) {
		if (this == &other) {
			return *this;
		}
		else{
			delete[] vector_ptr;
			logic_size_ = other.logic_size_;
			actual_size_ = other.actual_size_;
			vector_ptr = new T[actual_size_];
			for (int i = 0; i < logic_size_; i++) {
				vector_ptr[i] = (other.vector_ptr[i]);
			}
			return *this;
		}
	}
	void print_vec() {
		for (int i = 0; i < logic_size_; i++) {
			std::cout << vector_ptr[i] << " ";
		}
		std::cout << std::endl;
	}

	T at(int index) {				// доступ к элементу контейнера по индексу;
		return vector_ptr[index];
	}

	void puch_back(const T& value) {       // размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
		if (logic_size_ < actual_size_) {
			vector_ptr[logic_size_] = value;
			logic_size_++;
		}
		else{
			actual_size_ *= 2;
			std_vector temp_vec(*this);
			temp_vec.puch_back(value);
			logic_size_++;
			*this = temp_vec;
		}		
	}
	auto size() {					// количество элементов в контейнере;
		return logic_size_;
	}

		auto capacity() {				// количество элементов, которое может вместить контейнер до нового выделения памяти.
		return actual_size_;
	}

	~std_vector() {
		delete[] vector_ptr;
	}
};