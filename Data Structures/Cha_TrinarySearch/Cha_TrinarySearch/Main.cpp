#include<iostream>
#include<vector>
#include<chrono>
using namespace std;

int trinaryHelper(vector<int> vec, int value, int min, int max) {
	if (min > max) { return -1; }
	int mid = (min + max) / 2;
	int bottomThird = (mid + min) / 2;
	int topThird = (mid + max) / 2;
	if (vec.at(bottomThird) == value) { return bottomThird; }
	if (vec.at(topThird) == value) { return topThird; }
	if (vec.at(bottomThird) > value) { return trinaryHelper(vec, value, min, bottomThird - 1); }
	if (vec.at(topThird) < value) { return trinaryHelper(vec, value, topThird + 1, max); }
	return trinaryHelper(vec, value, bottomThird + 1, topThird - 1);
}
int trinarySearch(vector<int> vec, int value) {
	return trinaryHelper(vec, value, 0, vec.size() - 1);
}

int binaryHelper(vector<int> vec, int value, int min, int max){
	if (min > max) { return -1; }
	int mid = (min + max) / 2;
	if (vec.at(mid) > value) { return binaryHelper(vec, value, min, mid - 1); }
	if (vec.at(mid) < value) { return binaryHelper(vec, value, mid + 1, max); }
	return mid;
}
int binarySearch(vector<int> vec, int value) {
	return binaryHelper(vec, value, 0, vec.size() - 1);
}


int main() {
	vector<int> vec{};
	vec.push_back(0);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(70);
	vec.push_back(80);
	vec.push_back(90);
	vec.push_back(100);
	//for (int i : vec) {cout << i << endl;}
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();
	cout << trinarySearch(vec, 50);
	end = chrono::high_resolution_clock::now();
	chrono::duration<double> trinaryTime = end - start;

	start = chrono::high_resolution_clock::now();
	cout << binarySearch(vec, 50);
	end = chrono::high_resolution_clock::now();
	chrono::duration<double> binaryTime = end - start;
	cout << "Time to complete trinary Search: " << trinaryTime.count() << endl;
	cout << "Time to complete binary Search: " << binaryTime.count() << endl;
	return 0;
}