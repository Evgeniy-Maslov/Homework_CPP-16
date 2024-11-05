#pragma once



template<class T>
class std_vector {
	unsigned size_;
	unsigned logic_size_;
	T* vector_ptr;
public:
	std_vector() {
		size_ = 0;
		logic_size_ = 0;
		vector_ptr = new T[logic_size_];
	}
	T& operator =({  }) {
		size_ += 1;
		logic_size_ += 1;
		vector_ptr[size_] = a;
	}
	T at(int index) {   // доступ к элементу контейнера по индексу;

	}
	puch_back() {       // размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;

	}
	size() {            // количество элементов в контейнере;

	}
	capacity() {        // количество элементов, которое может вместить контейнер до нового выделения памяти.

	}

	~std_vector() {

	}
};