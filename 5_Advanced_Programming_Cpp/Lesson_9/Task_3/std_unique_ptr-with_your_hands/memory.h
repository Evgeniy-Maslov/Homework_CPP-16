#pragma once


template <class T>
class std_unique_ptr {
	T* smart_ptr;
public:
	std_unique_ptr() {
		smart_ptr = nullptr;
	}
	std_unique_ptr(T* raw_ptr) {
		smart_ptr = raw_ptr;
	}
	T* release() {
		T* temp = smart_ptr;
		smart_ptr = nullptr;
		return temp;
	}
	std_unique_ptr(std_unique_ptr& other) = delete;

	std_unique_ptr& operator = (std_unique_ptr& other) = delete;

	T* operator ->() {
		return smart_ptr;
	}

	T& operator * () {
		return *smart_ptr;
	}

	~std_unique_ptr() {
		delete smart_ptr;
	}
};
