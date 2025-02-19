#include <thread>
#include <chrono>
#include <iostream>
#include <vector>



void number_cores() {
	unsigned int n = std::thread::hardware_concurrency();
	std::cout << "number of hardware cores - " << n << "\n\n";
}
std::once_flag flag;

void calculation(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& vec3, int begin, int end) {
	std::call_once(flag, number_cores);
	for (int i = begin; i < end; i++) {
		vec3[i] = vec1[i] + vec2[i];
	}
}


int main()
{
	int size = 1000;
	std::vector<int> n_streams;
	std::vector<int> n_size;
	std::vector<std::vector<double>> table_time(5);
	for (int i = 0; i < 4; i++) {
		int n = 1;
		std::vector<int> vec1;
		std::vector<int> vec2;
		std::vector<int> vec3(size);

		for (int i = 0; i < size; i++) {
			vec1.push_back(std::rand() % 100000);
			vec2.push_back(std::rand() % 100000);
		}

		for (int j = 0; j < 5; j++) {
			int begin = 0;
			int end = size / n + 1;

			std::vector<std::thread> streams;
			auto start = std::chrono::system_clock::now();
			for (int i = 0; i < n; i++) {
				if (end > size) {
					end = size;
				}
				streams.push_back(std::thread(calculation, std::ref(vec1), std::ref(vec2), std::ref(vec3), begin, end));
				begin += size / n + 1;
				end += size / n + 1;
			}
			auto stop = std::chrono::system_clock::now();
			std::chrono::duration<double, std::deci> elapsed_seconds = stop - start;
			for (auto& it : streams) {
				if (it.joinable()) {
					it.join();
				}
			}
			table_time[j].push_back(elapsed_seconds.count());
			n_streams.push_back(n);
			n *= 2;
		}
		n_size.push_back(size);
		size *= 10;
	}

	for (int i = 0; i < n_size.size(); i++) {
		if (i == 0) {
			std::cout << "\t\t";
		}
		std::cout << n_size[i] << " \t\t";
	}
	std::cout << "\n";
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				std::cout << n_streams[i] << " streams \t";
			}
			std::cout << table_time[i][j] << " \t";
		}
		std::cout << "\n";
	}
	return 0;
}