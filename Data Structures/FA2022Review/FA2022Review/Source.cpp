#include <iostream>
#include "Fraction.h"
using namespace std;

void createFrac() {
	Fraction f{};
	cout << "test Success" << endl;
	f.setNumerator(4.5);
}

int main() {

	cout << "Hello World" << endl; // print something
	int x = 2;
	int y = 3;
	y = x;
	// x=2 y=2

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	createFrac();
	return 0; // Not Required
}

//Create a fuction that creates a Function Object and prints test success after doing so
