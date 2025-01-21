#include <string>
#include <thread>
#include <mutex>
#include<iostream>

class Data
{
	int num;
	std::string str;
	std::mutex mtx;
	
public:
	Data(int&& a, std::string&& b) : num(a), str(b) {}
	Data() {}
	Data(Data& other)
	{
		num = other.num;
		str = other.str;
	}
	bool operator == (const Data& other) const
	{
		return num == other.num and str == other.str;
	}
	Data& operator = (const Data& other)
	{
		if (*this == other)
		{
			return *this;
		}
		num = other.num;
		str = other.str;
		return *this;
	}
	std::mutex& _mtx()
	{
		return this->mtx; 
	}
	void print() {
		std::cout << " num = " << num << " , str = " << str << std::endl;
	}
	~Data() {}
};

void swap(Data& D1, Data& D2)
{
	D1._mtx().lock();
	D2._mtx().lock();
	Data temp(D1);
	D1 = D2;
	D2 = temp;
	D1._mtx().unlock();
	D2._mtx().unlock();
}

void swap_1(Data& D1, Data& D2)
{
	std::unique_lock<std::mutex> lk1(D1._mtx());
	std::unique_lock<std::mutex> lk2(D2._mtx());
	Data temp(D1);
	D1 = D2;
	D2 = temp;
}

void swap_2(Data& D1, Data& D2)
{
	std::scoped_lock(D1._mtx(), D2._mtx());
	Data temp(D1);
	D1 = D2;
	D2 = temp;
}

int main()
{
	Data D1(25, "abc");
	Data D2(30, "def");
	std::cout << "swap\n";
	std::cout << "object D1: "; 
	D1.print();
	std::cout << "object D2: ";
	D2.print();
	std::cout << "\n";
	std::thread T1(swap, std::ref(D1), std::ref(D2));
	T1.join();
	std::cout << "object D1: ";
	D1.print();
	std::cout << "object D2: ";
	D2.print();
	std::cout << "\n\n";

	std::cout << "swap_1\n";
	std::cout << "object D1: ";
	D1.print();
	std::cout << "object D2: ";
	D2.print();
	std::cout << "\n";
	std::thread T2(swap_1, std::ref(D1), std::ref(D2));
	T2.join();
	std::cout << "object D1: ";
	D1.print();
	std::cout << "object D2: ";
	D2.print();
	std::cout << "\n\n";

	std::cout << "swap_2\n";
	std::cout << "object D1: ";
	D1.print();
	std::cout << "object D2: ";
	D2.print();
	std::cout << "\n";
	std::thread T3(swap_2, std::ref(D1), std::ref(D2));
	T3.join();
	std::cout << "object D1: ";
	D1.print();
	std::cout << "object D2: ";
	D2.print();
	return 0;
}