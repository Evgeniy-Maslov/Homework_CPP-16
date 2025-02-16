#include <iostream>

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
void print_month(months x)
{
	switch (x)
	{
	case months::Ноль:
		std::cout << "До свидания\n";
		break;
	case months::Январь:
		std::cout << "Январь\n";
		break;
	case months::Февраль:
		std::cout << "Февраль\n";
		break;
	case months::Март:
		std::cout << "Март\n";
		break;
	case months::Апрель:
		std::cout << "Апрель\n";
		break;
	case months::Май:
		std::cout << "Май\n";
		break;
	case months::Июнь:
		std::cout << "Июнь\n";
		break;
	case months::Июль:
		std::cout << "Июль\n";
		break;
	case months::Август:
		std::cout << "Август\n";
		break;
	case months::Сентябрь:
		std::cout << "Сентябрь\n";
		break;
	case months::Октябрь:
		std::cout << "Октябрь\n";
		break;
	case months::Ноябрь:
		std::cout << "Ноябрь\n";
		break;
	case months::Декабрь:
		std::cout << "Декабрь\n";
		break;
	default:
		std::cout << "Неправильный номер!\n";
		break;
	}
}
int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "rus");
	int a;
	do
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> a;
		print_month(static_cast<months>(a));
	} while (a);
	return 0;
}