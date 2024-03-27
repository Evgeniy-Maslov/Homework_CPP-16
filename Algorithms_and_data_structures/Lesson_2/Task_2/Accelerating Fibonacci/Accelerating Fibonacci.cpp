#include <iostream>
#include <format>


int Fibonacci(int n, int *memory)
{
    if (n <= 1) { return n; }
    else if (memory[n -1] == 0)
    {
        memory[n - 1] = Fibonacci(n - 1, memory) + Fibonacci(n - 2, memory);
        return memory[n - 1];
    }
    else { return memory[n - 1]; }
}

int main(int argc, char** argv)
{
    int n;
    std::cout << "Enter the Fibonacci sequence number: ";
    std::cin >> n;
    int* memory = new int[n]();
    memory[0] = 0;
    memory[1] = 1;
    std::cout << std::format("Fibonacci number = {} \n", Fibonacci(n, memory));
    delete[] memory;
    return 0;
}
