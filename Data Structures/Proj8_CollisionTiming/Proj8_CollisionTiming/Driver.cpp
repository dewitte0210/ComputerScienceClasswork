#include<iostream>
#include<cstdlib>
#include<fstream>
#include "ChainedHashTable.h"

using namespace std;

int main() {
	bool firstCollision{ false };
	bool firstlongChain{ false };
	bool fullLoad{ false };
	bool nineLoad{ false };
	int firstCollisionSum{ 0 };
	int longChainSum{ 0 };
	int fullLoadSum{ 0 };
	int nineLoadSum{ 0 };
	int cycles{ 0 };
	HashTable* tab;
	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		tab = new HashTable{};
		cycles = 0;
		do
		{
			int listSize{ 0 };
			if (tab->insert(rand(), listSize) && !firstCollision)
			{
				firstCollision = true;
				firstCollisionSum += cycles;
			}
			//cout << tab->getLoadFactor() << endl;
			if (tab->getLoadFactor() > 0.9 && !nineLoad)
			{
				nineLoad = true;
				nineLoadSum += cycles;
			}
			if (tab->getLoadFactor() == 1 && !fullLoad)
			{
				fullLoad = true;
				fullLoadSum += cycles;
			}
			if (listSize >= 29)
			{
				firstlongChain = true;
				longChainSum += cycles;
			}
			cycles++;
		}while(!firstCollision || !firstlongChain || !fullLoad);
		firstCollision = false;
		nineLoad = false;
		fullLoad = false;
		firstlongChain = false;
	}
	double firstCollisionAvg = firstCollisionSum / 1000.0;
	double nineLoadAvg = nineLoadSum / 1000.0;
	double fullLoadAvg = fullLoadSum / 1000.0;
	double longChainAvg = longChainSum / 1000.0;
	ofstream outFile{"SimulationData.txt"};
	if (outFile.good())
	{
		outFile << "Avg inserts before first collision: " << firstCollisionAvg << endl;
		outFile << "Avg inserts before Load Factor 0.9: " << nineLoadAvg << endl;
		outFile << "Avg inserts before Load Factor 1.0: " << fullLoadAvg << endl;
		outFile << "Avg inserts before first Chain on 29: " << longChainAvg << endl;
	}
	cout << "Avg inserts before first collision: " << firstCollisionAvg << endl;
	cout << "Avg inserts before Load Factor 0.9: " << nineLoadAvg << endl;
	cout << "Avg inserts before Load Factor 1.0: " << fullLoadAvg << endl;
	cout << "Avg inserts before first Chain on 29: " << longChainAvg << endl;
	outFile.close();
	return 0;
}