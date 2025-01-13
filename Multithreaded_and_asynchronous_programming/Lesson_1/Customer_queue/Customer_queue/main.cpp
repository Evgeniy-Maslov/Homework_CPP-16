#include <thread>
#include <chrono>
#include <iostream>


using namespace std;

void client(int& n_client)
{
    for (int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(1s);
        cout << "counter increment = " << ++n_client << "\n";
    }
}

void cashier(int& n_client)
{
    for (int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(2s);
        cout << "counter decrement = " << --n_client << "\n";
    }
}

int main()
{
    int n_client{};
    thread t1(client, ref(n_client));
    thread t2(cashier, ref(n_client));
    t1.detach();
    t2.join();
    return 0;
}