#include<iostream>
#include<string>
#include"SimpleArrayList.h"
using namespace std;

int main() {
	SimpleArrayList<int> testList{};
	cout << "Test Success" << endl;
	cout << "Testing append" << endl;
	testList.append(5);
	for (int i = 0; i < testList.getNumElements(); i++)
	{
		cout << testList.get(i) << endl;
	}
	cout << "Testing prepend" << endl;
	testList.prepend(7);
	for (int i = 0; i < testList.getNumElements(); i++)
	{
		cout << testList.get(i) << endl;
	}

	SimpleArrayList<int> second = testList;

	for (int i = 0; i < second.getNumElements(); i++)
	{
		cout << second.get(i);
	}
	cout << endl;
}