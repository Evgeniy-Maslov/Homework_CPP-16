#include <iostream>
#include <windows.h>
#include "Counter.h"
#include"check_number.h"

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string yes_or_no;
	int n{};
	bool a = true;
	do
	{
		std::cout << "Вы хотите указать начальное значение счётчика? Введите 'yes' или 'no': ";
		std::cin >> yes_or_no;
		if (yes_or_no == "yes")
		{
			a = false;
			check_number(n);
			Counter C(n);
			C.action_Counter();
		}
		else if (yes_or_no == "no")
		{
			a = false;
			Counter C;
			C.action_Counter();
		}
	} while (a);
	return 0;
}
