#include <iostream>
#include"Greeter.h"

int main(int argc, char** argv)
{
	std::string name;
	Stat_Lib::Greeter Hi;
	std::cout << "Enter a name: ";
	std::cin >> name;
	std::cout << Hi.Greet(name);
	return 0;
}