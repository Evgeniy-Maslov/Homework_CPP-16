#include <iostream>
#include <windows.h>

enum class months
{
	Ноль,
	Январь,
	Февраль,
	Март,
	Апрель,
	Май,
	Июнь,
	Июль,
	Август,
	Сентябрь,
	Октябрь,
	Ноябрь,
	Декабрь
};

void print_month(int x)
{
	switch (x)
	{
		case static_cast<int>(months::Ноль):
			std::cout << "До свидания\n";
			break;
		case static_cast<int>(months::Январь):
			std::cout << "Январь\n";
			break;
		case static_cast<int>(months::Февраль):
			std::cout << "Февраль\n";
			break;
		case static_cast<int>(months::Март):
			std::cout << "Март\n";
			break;
		case static_cast<int>(months::Апрель):
			std::cout << "Апрель\n";
			break;
		case static_cast<int>(months::Май):
			std::cout << "Май\n";
			break;
		case static_cast<int>(months::Июнь):
			std::cout << "Июнь\n";
			break;
		case static_cast<int>(months::Июль):
			std::cout << "Июль\n";
			break;
		case static_cast<int>(months::Август):
			std::cout << "Август\n";
			break;
		case static_cast<int>(months::Сентябрь):
			std::cout << "Сентябрь\n";
			break;
		case static_cast<int>(months::Октябрь):
			std::cout << "Октябрь\n";
			break;
		case static_cast<int>(months::Ноябрь):
			std::cout << "Ноябрь\n";
			break;
		case static_cast<int>(months::Декабрь):
			std::cout << "Декабрь\n";
			break;
		default:
			std::cout << "Неправильный номер!\n";
			break;
	}
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	do
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> a;
		print_month(a);
	} while (a);
	return 0;
}