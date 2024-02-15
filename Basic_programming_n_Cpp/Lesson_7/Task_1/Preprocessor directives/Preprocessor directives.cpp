#include <iostream>
#define MODE 1
#ifndef MODE
#error it is necessary to define the MODE
#endif
#if MODE ==1
int add(int &x, int &y)
{
	return x + y;
}
#endif
int main()
{
#if MODE == 0
	std::cout << "I work in training mode \n";
#elif MODE == 1
	int one;
	int two;
	std::cout << "I'm working in combat mode \n";
	std::cout << "Enter the number 1: ";
	std::cin >> one;
	std::cout << "Enter the number 2: ";
	std::cin >> two;
	std::cout << "The result of addition: " << add(one, two) << std::endl;
#else
	std::cout << "Unknown mode. Finishing the work \n";
#endif
	return 0;
}

