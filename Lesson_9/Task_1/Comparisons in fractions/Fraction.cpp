#include"Fraction.h"


Fraction::Fraction(int numerator, int denominator)
{
	numerator_ = numerator;
	denominator_ = denominator;
}
int Fraction::comparing_fractions(Fraction other) { return (numerator_ * other.denominator_); }
bool Fraction::operator==(Fraction other) {	return comparing_fractions(other) == other.comparing_fractions(*this); }
bool Fraction::operator!=(Fraction other) {	return !(*this == other); }
bool Fraction::operator<(Fraction other) { return comparing_fractions(other) < other.comparing_fractions(*this); }
bool Fraction::operator>(Fraction other) { return (other < *this); }
bool Fraction::operator<=(Fraction other) { return !(other < *this); }
bool Fraction::operator>=(Fraction other) { return !(*this < other); }