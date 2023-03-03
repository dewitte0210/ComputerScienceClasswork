#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "Testing the vector class" << endl;
	vector<char> v(8);
	v.push_back('c');
	for (int i = 1; i < v.size(); i++) {
		cout << "v{" << i << "]:" << v[i] << endl;
	}
	return 0;
}