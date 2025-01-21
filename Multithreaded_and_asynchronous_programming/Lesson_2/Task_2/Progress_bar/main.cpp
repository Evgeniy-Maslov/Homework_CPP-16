#include <iostream>
#include <thread>
#include "consol_parameter.h"
#include <random>
#include <mutex>
#include <ctime>

std::mutex mtx;

void Imitation_error()
{
    std::srand(std::time(0));
    int err = std::rand() % 10;
    if (err == 9)
    {
        throw std::exception(" ");
    }
}

void Progress_bar_header(int n) 
{
    std::cout << "#\t" << "id\t" << "Progress Bar\t\t" << "Time\n\n";
    for (int i = 0; i < n; i++) {
        std::cout << i << "\n";
    }
}
std::once_flag flag;


void Progress_bar(int x, int n_streams)
{
    std::call_once(flag, Progress_bar_header, n_streams);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lk(mtx);
    consol_parameter::SetPosition(5, (x + 2));
    std::cout << std::this_thread::get_id();
    lk.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 20; i++)
    {
        lk.lock();
        consol_parameter::SetColor(0, 15);
        consol_parameter::SetPosition(15 + i, 2 + x);
        try {
            Imitation_error();
            std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 200));
            std::cout << " ";
        }
        catch (std::exception& er) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            consol_parameter::SetColor(0, 4);
            std::cout << er.what();
            consol_parameter::SetColor(0, 15);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        lk.unlock();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    lk.lock();
    consol_parameter::SetColor(15, 0);
    consol_parameter::SetPosition(35, 2 + x);
    std::cout << "\t" << elapsed_seconds.count() << "s";
}

void Streams() 
{
    int n_streams = 5;
    std::thread* stream = new std::thread[n_streams];
    for (int i = 0; i < n_streams; i++)
    {
        stream[i] = std::thread(Progress_bar, i, n_streams);
    }
    for (int i = 0; i < n_streams; i++)
    {
        stream[i].join();
    }
    consol_parameter::SetPosition(0, 7);
}

int main()
{
    Streams();  
    return 0;
}

