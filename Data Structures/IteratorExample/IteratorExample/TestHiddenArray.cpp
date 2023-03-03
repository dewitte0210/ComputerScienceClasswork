#include<iostream>
#include "HiddenArray.h"
using namespace std;

int main() {
	HiddenArray a;
	//make an iterator over a, setting it to begin at a.begin()
	HiddenArray::iterator iter = a.begin();
	while (iter != a.end())
	{
		cout << *iter << endl;
		iter++;
	}
}