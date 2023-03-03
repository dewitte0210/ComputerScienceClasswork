#include<iostream>
#include<vector>
using namespace std;

int binaryHelper(vector<int> vec, int min, int max, int toFind) {
	//Base Case if min > max then we don't have toFind
	if (min > max) { return -1; }
	//Calculates the middle index of the vecotr
	int mid = (max + min) / 2;
	//checks the mid index for our value
	if (vec.at(mid) == toFind) { return mid; }
	//if the value at mid index is less than the value we search for then cut the search area to the lower half
	else if (vec.at(mid) < toFind) { return binaryHelper(vec, min, mid - 1, toFind); }
	//if neither of the last two then value @ mid is > toFind so cut the search are to the upper half
	return binaryHelper(vec, mid + 1, max, toFind);
}

//Calls the helper function with the information needed to run the search
int binarySearch(vector<int> vec, int toFind) {
	return binaryHelper(vec, 0, vec.size() - 1, toFind);
}

int main() {

	//A simple test for the binarySearch
	vector<int> vec{};
	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(6);
	vec.push_back(5);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i << ": " << vec.at(i) << ", ";
	}
	cout << endl;
	cout << binarySearch(vec, 7);
	return 0;
}