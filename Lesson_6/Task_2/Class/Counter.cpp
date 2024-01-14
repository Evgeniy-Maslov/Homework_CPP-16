#include <iostream>
#include "Counter.h"


Counter::Counter()
{
	count = 1;
}
Counter::Counter(int count)
{
	this->count = count;
}
void Counter::action_Counter()
{
	std::string symbol;
	do
	{
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> symbol;
		calculation_Counter(count, symbol);
	} while (symbol != "x");
	std::cout << "�� ��������!";
	std::cout << std::endl;
}
void Counter::calculation_Counter(int& count, std::string symbol)
{
	if (symbol == "x")
		;
	else if (symbol == "+")
		count++;
	else if (symbol == "-")
		count--;
	else if (symbol == "=")
		std::cout << count << std::endl;
	else
		std::cout << "������� ���������� ������" << std::endl;
}