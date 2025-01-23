#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <list>
#include <random>

void random_generator(std::list<unsigned int>& List, int begin, int end)
{
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> dis(0, 100);
	for (int i = begin; i < end; i++)
	{
		List.push_back(dis(gen));
	}
}

void creating_list(int size_listt, std::promise<std::list<unsigned int>> prom)
{
	std::list<unsigned int> List;
	int n_thread = std::thread::hardware_concurrency();
	int begin = 0;
	int end = size_listt / n_thread + 1;
	std::vector<std::thread> Thread;
	for (int i = 0; i < n_thread; i++)
	{
		if (end > size_listt)
		{
			end = size_listt;
		}
		Thread.push_back(std::thread(random_generator, std::ref(List), begin, end));
		begin += size_listt / n_thread + 1;
		end += size_listt / n_thread + 1;
	}
	for (auto& it : Thread)
	{
		if (it.joinable())
		{
			it.join();
		}
	}
	prom.set_value(List);
}

void sort_list(std::future<std::list<unsigned int>>& fut, std::promise<std::list<unsigned int>> prom)
{
	std::future<std::list<unsigned int>> & List_sort = fut;
	std::list<unsigned int> List = List_sort.get();
	std::list<unsigned int>::iterator it_begin = List.begin();
	std::list<unsigned int>::iterator it_end = List.end();
	do 
	{
		int temp;
		std::list<unsigned int>::iterator it_min = it_begin;
		for (auto iter = it_begin; iter != it_end; iter++)
		{
			if (*iter <= *it_min)
			{
				it_min = iter;
			}
		}
		temp = *it_begin;
		*it_begin = *it_min;
		*it_min = temp;
		++it_begin;
	} while (it_begin != it_end);
	prom.set_value(List);
}

void print_list(std::future<std::list<unsigned int>>& fut, std::promise<std::list<unsigned int>> prom)
{
	std::future <std::list<unsigned int>>& List_pr = fut;
	std::list<unsigned int> List = List_pr.get();
	for (auto it : List)
	{
		std::cout << it << " ";
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	std::cout << "\n\n";
	prom.set_value(List);
}

int main()
{
	int size_listt = 10;
	std::promise<std::list<unsigned int>> prom1;
	std::future<std::list<unsigned int>> fut;
	fut = prom1.get_future();
	auto res = std::async(creating_list, size_listt, std::move(prom1));
	
	std::promise<std::list<unsigned int>> prom2;
	std::future<std::list<unsigned int>> fut2;
	fut2 = prom2.get_future();
	fut.wait();
	std::cout << "list before sorting -  ";
	auto res2 = std::async(print_list, std::ref(fut), std::move(prom2));

	std::promise<std::list<unsigned int>> prom3;
	std::future<std::list<unsigned int>> fut3;
	fut3 = prom3.get_future();
	auto res3 = std::async(sort_list, std::ref(fut2), std::move(prom3));
	
	std::promise<std::list<unsigned int>> prom4;
	std::future<std::list<unsigned int>> fut4;
	fut4 = prom4.get_future();
	fut3.wait();
	std::cout << "list after sorting -  ";
	auto res4 = std::async(print_list, std::ref(fut3), std::move(prom4));
	
	return 0;
}