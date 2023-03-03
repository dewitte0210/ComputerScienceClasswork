#include "item.h"
#include<iostream>
using namespace std;

//lets verify that we can create an Item and call its methods
void first() {
	//Item a{ "someItem", 10, 0 };
	//Item b{ "earth", 20000000, 1 };
	//cout << "Testing getName, Expected: someItem, Actual: " << a.getName() << endl;
	//cout << "Testing isHeavy, Expected: true, Actual: " << b.isHeavy() << endl;
}
void second() {
	Food foo{ "fruit", "apple", 1, 2 };
	cout << "Testing isSpoiled...";
	if (!foo.isSpoiled()) cout << "Success!" << endl; else cout << "Fail" << endl;
	cout << "Testing isHeavy..." << endl;
	if (!foo.isSpoiled()) cout << "Success!" << endl; else cout << "Faile" << endl;
}

 //Thursdays tests
void wideningConversion() {
	Food c{"Dessert", "Ice Cream", 6, 3};
	//Legal Options
	Item& itemref{ c };
	Item* itemptr{ &c };

	//returns 1 is it uses Food.isHeavy() but in this case it will return 0 because we are using Item.isHeavy();
	cout << itemptr->isHeavy() << endl;
}

void narrowingConversion() {
	Food c{ "Dessert", "Ice Cream", 6 , 3 };
	Item* itemptr{ &c };
	//Narrow! this is dangerous.
	Food* foodptr{ dynamic_cast<Food*>(itemptr) };
	cout << "Tesiting is Heavy! \n";
	cout << foodptr->isHeavy() << endl;
	Tool* toolptr{ dynamic_cast<Tool*>(itemptr) };
	cout << "Test isPowerd()... should fail \n";
	cout << toolptr->isPowerd() << endl;
}

void makeASpoon() {
	ChocolateSpoon spoon{ 2, 4 };
	spoon.equip();
}

int main() {
	//wideningConversion();
	//narrowingConversion();
	makeASpoon();
	return 0;
}