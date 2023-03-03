#include<iostream>
#include "Lists.h"
using namespace std;

int main() {
	PrintableVector<int> vec{};
	PrintableList<int> list{};
	vec.insert(20, 0);
	list.insert(20, 0);
	vec.insert(30, 1);
	list.insert(30, 1);
	cout << vec << endl;
	cout << list << endl;
	return 0;
}