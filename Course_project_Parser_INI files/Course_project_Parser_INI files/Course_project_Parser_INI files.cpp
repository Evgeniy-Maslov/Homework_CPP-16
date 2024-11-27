#include <iostream>
#include "IniParser.h"



int main(int args, char** argv)
{
	try {
		IniParser parser("file.ini");
		std::string arguments;
		std::cout << "Enter the name of the section and variable in format 'section.value' - ";
		std::cin >> arguments;
		auto value = parser.get_value<int>(arguments);
		std::cout << std::format("The value of the variable = {}\n", value);
	}
	catch (std::invalid_argument err) {
		std::cout << err.what();
	}
	catch (std::domain_error err) {
		std::cout << err.what();
	}
	catch (std::runtime_error err) {
		std::cout << err.what();
	}
	catch (...) {
		std::cout << "error";
	}
	return 0;
}