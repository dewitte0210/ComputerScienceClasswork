#pragma once

class Fraction {
private:
	int numerator{ 1 };
	int denominator{ 1 };
public:
	Fraction();
	Fraction(int n, int d);
	int getNumerator();
	int getDenominator();
	void setNumerator(int numberator);
	void setDenominator(int denominator);
	double getDecimal();
	Fraction getReciprocal();
	bool isUndef();


};