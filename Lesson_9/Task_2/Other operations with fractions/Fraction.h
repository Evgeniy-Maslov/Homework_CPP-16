#include <iostream>
#pragma once

class Fraction
{
private:
	int numerator_;
	int denominator_;
	int k;
	void reduction_fractions(int k);
	int nok(int a, int b);
	int nod(int a, int b);
	int comparing_fractions(Fraction other);
public:
	Fraction(int numerator, int denominator);
	void show();
	bool operator==(Fraction other);
	bool operator!=(Fraction other);
	bool operator<(Fraction other);
	bool operator>(Fraction other);
	bool operator<=(Fraction other);
	bool operator>=(Fraction other);
	Fraction operator+(Fraction other);
	Fraction operator-(Fraction other);
	Fraction operator*(Fraction other);
	Fraction operator/(Fraction other);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
};