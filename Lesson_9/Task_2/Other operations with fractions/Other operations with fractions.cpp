#include <iostream>
#include "Fraction.h"


int main(int argc, char** argv)
{
	int numerator, denominator;
	std::cout << "Enter the numerator of the fraction 1: ";
	std::cin >> numerator;
	std::cout << "Enter the denominator of the fraction 1: ";
	std::cin >> denominator;
	Fraction f1(numerator, denominator);
	std::cout << "Enter the numerator of the fraction 2: ";
	std::cin >> numerator;
	std::cout << "Enter the denominator of the fraction 2: ";
	std::cin >> denominator;
	Fraction f2(numerator, denominator);

	f1.show(), std::cout << " + ", f2.show(), std::cout << " = ", (f1 + f2).show(), std::cout << std::endl;
	f1.show(), std::cout << " - ", f2.show(), std::cout << " = ", (f1 - f2).show(), std::cout << std::endl;
	f1.show(), std::cout << " * ", f2.show(), std::cout << " = ", (f1 * f2).show(), std::cout << std::endl;
	f1.show(), std::cout << " / ", f2.show(), std::cout << " = ", (f1 / f2).show(), std::cout << std::endl;
	std::cout << "++",f1.show(), std::cout << " * ", f2.show(), std::cout << " = ", (++f1 * f2).show(), std::cout << std::endl;
	std::cout << "The value of the fraction is 1 = "; f1.show(); std::cout << std::endl;
	f1.show(), std::cout << "-- * ", f2.show(), std::cout << " = ", (f1-- * f2).show(), std::cout << std::endl;
	std::cout << "The value of the fraction is 1 = "; f1.show(); std::cout << std::endl;

	return 0;
}