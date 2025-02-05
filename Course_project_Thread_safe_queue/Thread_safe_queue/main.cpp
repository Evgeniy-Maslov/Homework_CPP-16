#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <functional>
#include <queue>


template<class T>
class safe_queue
{
	std::queue<T> data_queue;
	std::mutex mtx;
	std::condition_variable cv;
public:
	safe_queue() {}
	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mtx);
		data_queue.push(new_value);
		cv.notify_one();
	}
	void pop()
	{
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [this] {return !data_queue.empty();});
		data_queue.pop();
		lk.unlock();
	}
	bool empty()
	{
		std::lock_guard<std::mutex> lk(mtx);
		return data_queue.empty();
	}
	T front()
	{
		std::lock_guard<std::mutex> lk(mtx);
		if (!data_queue.empty())
		{
			return data_queue.front();
		}
	}
	~safe_queue() {}
};


template<class T>
class thread_pool
{
	bool done = false;
	std::mutex mtx;
	int n_streams;
	std::vector<std::thread> threads;
	safe_queue<T> work_queue;
public:
	thread_pool(int n) : n_streams(n)
	{
		for (size_t i = 0; i < n_streams; i++)
		{
			threads.push_back(std::thread([&]() {work();}));
		}
	}
	~thread_pool()
	{
		for (size_t i = 0; i < n_streams; i++)
		{
			threads[i].join();
		}
	}
	void  work()
	{
		mtx.lock();
		std::cout << "id : " << std::this_thread::get_id() << std::endl;
		mtx.unlock();
		while (!done)
		{
			std::lock_guard<std::mutex> lk(mtx);
		    T task;
		     if (!work_queue.empty())
		     {
		         task = work_queue.front();
		         task();
				 std::cout << "id : " << std::this_thread::get_id() << std::endl;
		         work_queue.pop();
		     }
		     else
		     {
		         std::this_thread::yield();
		     }
		}
	}
	void submit(T func)
	{
		std::lock_guard<std::mutex> lk(mtx);
		work_queue.push(func);
	}
	void set_done(bool&& x)
	{
		done = x;
	}
};



void func_1()
{
	std::cout << "func_1 - ";
}

void func_2()
{
	std::cout << "func_2 - ";
}


int main()
{
	std::vector<std::jthread> threads;
	int n_streams = std::thread::hardware_concurrency() - 2;
	thread_pool<std::function<void()>> pool(n_streams);
	for (int i = 0; i < n_streams; i++)
	{
		std::jthread T1([&]()
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				return pool.submit(std::function(func_1));
			});
		std::jthread T2([&]()
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				return pool.submit(std::function(func_2));
			});
		
	}
	pool.set_done(true);
	return 0;
}
