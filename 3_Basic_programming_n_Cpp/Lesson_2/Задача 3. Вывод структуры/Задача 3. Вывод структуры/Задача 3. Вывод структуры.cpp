#include <iostream>

struct address
{
	std::string city;
	std::string street;
	int house;
	int apartment;
	int index;
};
void output_console(address* array, int x)
{
	for (int i = 0; i < x; i++)
	{
		std::cout << "Город:\t\t" << array[i].city << std::endl;
		std::cout << "Улица:\t\t" << array[i].street << std::endl;
		std::cout << "Номер дома:\t" << array[i].house << std::endl;
		std::cout << "Номер квартиры:\t" << array[i].apartment << std::endl;
		std::cout << "Индекс:\t\t" << array[i].index << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}
int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "rus");
	int ind = 2;
	address* address_array = new address[ind];
	address_array[0] = { "Москва", "Арбат", 12, 8, 123456 };
	address_array[1] = { "Ижевск", "Пушкина", 59, 143, 953769 };
	output_console(address_array, ind);
	delete[] address_array;
	return 0;
}