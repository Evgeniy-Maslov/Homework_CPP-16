#include <iostream>
#include <windows.h>
#include <string>

class Counter
{
public:
	int count;
	Counter()
	{
		count = 1;
	}
	Counter(int count)
	{
		this->count = count;
	}
	void action_Counter()
	{
		std::string symbol;
		do
		{
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			std::cin >> symbol;
			calculation_Counter(count, symbol);				
		} while (symbol != "x");
		std::cout << "До свидания!";
		std::cout << std::endl;
	}
private:
	void calculation_Counter(int &count, std::string symbol)
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
			std::cout << "Введите корректный символ" << std::endl;
	}
};

void check_number(int &x)
{
	bool b = true;
	do
	{
		std::string buff;
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> buff;
		if ((buff.find_first_not_of("0123456789") == std::string::npos) == true)
		{
			x = std::stoi(buff);
			b = false;
		}
		else
		{
			std::cout << "Вы ввели не число!\n";
		}
	} while (b);
}

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
