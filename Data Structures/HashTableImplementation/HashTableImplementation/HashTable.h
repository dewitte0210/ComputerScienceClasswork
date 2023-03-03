#pragma once
#include<string>
#include<vector>
using namespace std;

class HashTable {
private:
	vector<string*> data{};
	int load{ 0 };
public:
	HashTable() {
		
	}
	//Hash Function - this will be private after testing
	int h(string x) {
		//Take the characters from x, convert them to their ASCII code values
		int sum = 0;
		for (char c : x)
		{
			sum += int(c);
		}
		return sum;
	}
	void insert(string x) {
		if ((data.size() / static_cast<double>(load)) > 0.5) { data.resize(data.size() * 2); }
		int stringHash = h(x) % data.size();
		if (data.at(stringHash) == nullptr)
		{
			data.at(quadraticProbe(x)) = &x;
		}
		else
		{
			data.at(stringHash) = &x;
		}
		load++;
	}
	int quadraticProbe(string x) {
		int loops = 0;
		int loc = h(x) % data.size();
		bool found = false;
		do
		{
			loops++;
			if(data.at(loc + (loops * loops) % data.size()) == nullptr){found = true;}
			else if (data.at(loc + (loops * loops) % data.size()) == &x) { found = true; }
		} while (!found);
		return (loc + (loops * loops)) % data.size();
	}
	bool lookup(string x) {
		int stringHash = h(x) % data.size();
		if (*data.at(stringHash) == x) { return true; }
		else if (*data.at(quadraticProbe(x)) == x) { return true; }
		return false;
	}
	//Handle collision using quadratic probing
	//Rehash (expand the array) at Load Factor 0.5
	//Challenge: Make the array sizes always primes
	
	//We need
	//Array(field), Insert, Lookup, (optional: Remove)
};