#include <iostream>
#include <future>
#include <thread>


template<typename Iterator, typename Func>
Func std_for_each(Iterator begin, Iterator end, Func& fn)
{
	while (begin != end)
	{
		fn(*begin);
		++begin;
	}
	return fn;
}

template<typename Iterator, typename Func>
Func parallel_for_each(Iterator begin, Iterator end, Func& fn)
{
	int size = std::distance(begin, end);
	int n_streams = std::thread::hardware_concurrency();
	if (size <= n_streams)
	{
		return  std_for_each(begin, end, fn);
	}
	else
	{
		Iterator mild_point = begin;
		std::advance(mild_point, size / 2);
		std::future<Func> first_haife = std::async(parallel_for_each<Iterator, Func>, begin, mild_point, std::ref(fn));
		Func second_haif =parallel_for_each<Iterator, Func>(mild_point, end, std::ref(fn));
	}
}

void print(int& i)
{
	std::cout << i << " ";
}
void func(int& i)
{
	i *= 10;
}
void (*ptr_print)(int&) = &print;
void (*ptr_Func)(int&) = &func;


int main()
{
	std::vector<int> V{ 1,2,3,4,5,6,7,8,9,10 };

	for_each(V.begin(), V.end(), ptr_print);
	std::cout << "\n\n";

	parallel_for_each(V.begin(), V.end(), ptr_Func);

	for_each(V.begin(), V.end(), ptr_print);
	std::cout << "\n";

	return 0;
}