#include <iostream>
#include <string>
#include"check_number.h"

void check_number(int& x)
{
	bool b = true;
	do
	{
		std::string buff;
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> buff;
		if ((buff.find_first_not_of("0123456789") == std::string::npos) == true)
		{
			x = std::stoi(buff);
			b = false;
		}
		else
		{
			std::cout << "�� ����� �� �����!\n";
		}
	} while (b);
}