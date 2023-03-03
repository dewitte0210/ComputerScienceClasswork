#include <vector>
#include <list>
#include <iostream>
#include <string>
using namespace std;

int main() {
	//Iterators
	//A tool for traversing ListADTs
	//Get access to the data, but NOT to nodes or an underlysing array

	vector<string> vs(5);
	//Create an iterator
	vector<string>::iterator iter = vs.begin();
	string buildme = "OK";
	//Iterate through the vector, setting values as we go
	while (iter != vs.end())
	{	//set data at the current position
		*iter = buildme;
		buildme +="OK";
		//Advance the iterator
		iter++;
	}
	vector<string>::iterator printer = vs.begin();
	while (printer != vs.end())
	{
		cout << *printer << endl;
		printer++;
	}
	return 0;
}