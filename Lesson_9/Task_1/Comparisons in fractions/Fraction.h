#pragma once

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator);
	int comparing_fractions(Fraction other);
	bool operator==(Fraction other);
	bool operator!=(Fraction other);
	bool operator<(Fraction other);
	bool operator>(Fraction other);
	bool operator<=(Fraction other);
	bool operator>=(Fraction other);
};