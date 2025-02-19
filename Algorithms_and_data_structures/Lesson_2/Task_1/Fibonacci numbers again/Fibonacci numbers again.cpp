#include <iostream>
#include <format>


int Fibonacci(int n)
{
    if (n <= 1) { return n; }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main(int argc, char** argv)
{
    int n;
    std::cout << "Enter the Fibonacci sequence number: ";
    std::cin >> n;
    std::cout << std::format("Fibonacci number = {} \n", Fibonacci(n));
    return 0;
}

//Каждый раз, когда мы вызываем Fibonacci(n), потенциально будет выполняться еще два вызова Fibonacci. 
// И т.д. до базовых значений n.
//Таким образом сложность работы = О(2^n). сложность использования памяти = О(1), т.к. количество памяти не зависит 
// от количества входных данных.