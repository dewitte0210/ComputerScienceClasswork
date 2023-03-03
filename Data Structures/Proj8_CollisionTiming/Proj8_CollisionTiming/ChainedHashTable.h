#pragma once
#include <vector>
#include<string>
#include<forward_list>
using namespace std;

class HashTable {
private:
	vector<forward_list<int>> data{ 29 };
	int Load{ 0 };

	//Hashes the int by multiplying it by 10
	int h(int x) {
		int mult = 0;
		mult = x * 10;
		return mult;
	}
	int countList(int hash) {
		forward_list<int> tempList = data.at(hash);
		int count = 0;
		for (int x : tempList) { count++; }
		return count;
	}
public:
	HashTable() {}

	//Hashes an int and then inserts it based on the hash
	bool insert(int x, int& listSize)
	{
		bool collision = true;
		int hashed = h(x) % data.size();
		if (data.at(hashed).empty()) {
			collision = false;
			Load++;
		}
		data.at(hashed).emplace_front(x);
		listSize = countList(hashed);
		return collision;
	}

	//Hashes int x and then uses the hash to lookup the index
	bool lookup(int x) {
		bool found = false;
		int hashed = h(x) % data.size();
		forward_list<int> tempList = data.at(hashed);
		for (int s : tempList)
		{
			if (s == x)
			{
				found = true;
			}
		}
		return found;
	}

	// returns the current Load Factor ofg the Hash Talbe
	double getLoadFactor() { return static_cast<double>(Load) / data.size(); }
};