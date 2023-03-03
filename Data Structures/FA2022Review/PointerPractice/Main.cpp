#include<iostream>
#include<vector>
#include "../FA2022Review/Fraction.h"
using namespace std;

void intModif(int* pInt) {
	*pInt *= 2;
}

int main() {
	int x{ 3 };
	int* pX{ &x };

	cout << "x itself: " << x << endl;
	cout << "pX itself: " << pX << endl;
	cout << "value pX points to: " << *pX << endl;
	//when declaring a variable
	//var* means pointer to type var
	//var& means a reference to type var
	//When applied to an object (i.e. not declaring
	//&i means "address of" i
	//*i means "dereference"

	x = 20;
	cout << "value pX points to is now: " << *pX << endl;
	intModif(pX);
	cout << "intModif tested with 20: " << x << endl;

	// comparing pointer
	int second{ 40 };
	int* pSecond{ &second };
	if (pX == pSecond) {
		cout << "pointers are equal" << endl;
	}
	else if (*pX == *pSecond) {
		cout << "pointers are equal 2" << endl;
	}

	// REFERENCES
	//Use non-pointer syntax
	// Never null
	// Address is set at start (instantiation) and never changed
	int& xref{ x };
	cout << "Value of x: " << x << endl;
	cout << "Value of xref: " << xref << endl;
	xref = 6;
	cout << "Value of xref is now: " << xref << endl;
	if (xref == x) {
		cout << "xref and x are equal" << endl;
	}
	cout << "address of x: " << &x << endl;
	cout << "address of xref: " << &xref << endl;
	return 0;

	Fraction f{ 2, 3 };
	Fraction* fPtr{ &f };

	//I want to set the numerator of the fraction fptr points to
	fPtr->setNumerator(5);
	//I want to set the denominator of the Fraction f
	f.setDenominator(10);
	//If I am INSIDE a method of the class, and I want to refer to "me"
	// this.denominator

	//Make a vector of Fracitons and a vector of pointers to fractions
	vector<Fraction> fracVec(4);
	fracVec.at(0) = Fraction{ 1,2 };
	fracVec.at(1) = Fraction{ 2,3 };
	fracVec.at(2) = Fraction{ 3,4 };
	fracVec.at(3) = Fraction{ 4,5 };
	vector<Fraction*> fracPtr(4);
	for (int i = 0; i < fracPtr.size(); i++)
	{
		fracPtr.at(i) = new Fraction{ i , i * 2 };
	}
	//Get the numerator of each of those fractions and print them
	for (Fraction el : fracVec) {
	cout << el.getNumerator() << endl;
	}
	for (Fraction* el : fracPtr) {
		cout << el->getNumerator() << endl;
	}

	for (int i = 0; i < fracPtr.size(); i++)
	{
		delete fracPtr[i];
		fracPtr[i] = nullptr;
	}
}