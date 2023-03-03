#include "Fraction.h"


Fraction::Fraction() {

}
Fraction::Fraction(int n, int d){
	numerator = n;
	denominator = d;
}
int Fraction::getNumerator() { return numerator; }
int Fraction::getDenominator() { return denominator; }
void Fraction::setNumerator(int numerator) { this->numerator = numerator; }
void Fraction::setDenominator(int denominator) { this->denominator = denominator; }
double Fraction::getDecimal() { return numerator / static_cast<double>(denominator); }

Fraction Fraction::getReciprocal() {
	Fraction rec{};
	rec.setNumerator(denominator * -1);
	return rec;
}