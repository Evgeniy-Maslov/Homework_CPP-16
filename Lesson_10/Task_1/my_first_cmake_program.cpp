#include <iostream>

int main(int argc, char** argv)
{
	std::string name;
	std::cout << "Enter a name: ";
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}