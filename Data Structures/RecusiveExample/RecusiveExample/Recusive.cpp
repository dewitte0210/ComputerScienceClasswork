#include <iostream>
using namespace std;

//three rules for recursino
//1. There mus be at least one BASE CASE.
//2. There must be at tleast on Recursive Call
//3. Every recursive call must make progress toward a base case

void infiniteRecursion() {
	cout << "Message!" << endl;
	infiniteRecursion();
}

void countToTenFake(int i)
{
	//Base Case
	if (i >= 10)
	{
		return;
	}
	//recursive case
	cout << i << endl;
	countToTenFake(i); // this will cause infinite recursion
}
void countToTenReal(int i) {
	if (i > 10){ return; }
	cout << i << endl;
	countToTenReal(i + 1);
}
int main() {
	//infiniteRecursion();
	//countToTenFake(1);
	countToTenReal(1);
	return 0;
}