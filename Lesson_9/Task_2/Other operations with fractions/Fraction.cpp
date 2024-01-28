#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator)
{
	numerator_ = numerator;
	denominator_ = denominator;
	k = nod(numerator_, denominator_);       // coefficient for fraction reduction. 
	reduction_fractions(k);
}
void Fraction::reduction_fractions(int k)    // fraction reduction
{
	if (k > 1)
	{ 
		numerator_ /= k;
		denominator_ /= k;
	}
}
int Fraction::nod(int a, int b)              // greatest common divisor
{
	if (a < b) { std::swap(a, b); }
	while (b)
	{
		a %= b;
		std::swap(a, b);
	}
	return a;
}
int Fraction::nok(int a, int b)            // The smallest common multiple
{
	return a / nod(a, b) * b;
}
void Fraction::show()                      // output to the console
{
	std::cout << numerator_ << "/" << denominator_;
}
int Fraction::comparing_fractions(Fraction other) { return (numerator_ * other.denominator_); }
bool Fraction::operator==(Fraction other) { return comparing_fractions(other) == other.comparing_fractions(*this); }
bool Fraction::operator!=(Fraction other) { return !(*this == other); }
bool Fraction::operator<(Fraction other) { return comparing_fractions(other) < other.comparing_fractions(*this); }
bool Fraction::operator>(Fraction other) { return (other < *this); }
bool Fraction::operator<=(Fraction other) { return !(other < *this); }
bool Fraction::operator>=(Fraction other) { return !(*this < other); }
Fraction Fraction::operator+(Fraction other)
{
	int e = nok(denominator_, other.denominator_);
	return Fraction ((numerator_ * e / denominator_) + (other.numerator_ * e / other.denominator_), e);
}
Fraction Fraction::operator-(Fraction other)
{
	int e = nok(denominator_, other.denominator_);
	return Fraction(numerator_ * e / denominator_ - other.numerator_ * e / other.denominator_, e);
}
Fraction Fraction::operator*(Fraction other) 
{
	return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
}
Fraction Fraction::operator/(Fraction other)
{
	return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
}
Fraction Fraction::operator++()
{
	numerator_ += denominator_;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	++(*this);
	return temp;
}
Fraction Fraction::operator--()
{
	numerator_ -= denominator_;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	--(*this);
	return temp;
}