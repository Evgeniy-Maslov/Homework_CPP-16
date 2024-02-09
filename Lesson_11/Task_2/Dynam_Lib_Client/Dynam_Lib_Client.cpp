#include <iostream>
#include "Leaver.h"

int main(int argc, char** argv)
{
	std::string name;
	Dynam_Lib::Leaver Le;
	std::cout << "Enter a name: ";
	std::cin >> name;
	std::cout << Le.Leave(name);
	return 0;
}