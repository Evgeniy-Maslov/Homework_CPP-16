#include <thread>
#include <chrono>
#include <iostream>
#include <atomic>



std::atomic_int n_client{};

void client()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "counter increment = " << n_client.fetch_add(1, std::memory_order_seq_cst) << "\n";
    }
}

void cashier()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "counter decrement = " << n_client.fetch_sub(1, std::memory_order_seq_cst) << "\n";
    }
}

int main()
{
    std::thread t1(client);
    std::thread t2(cashier);
    t1.detach();
    t2.join();

    return 0;

}