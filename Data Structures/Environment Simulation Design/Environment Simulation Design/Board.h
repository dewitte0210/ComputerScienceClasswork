#pragma once
#include <vector>
#include "Tree.h"
using namespace std;
class Board {
private:
	vector<vector<Tree>> forest{};
	int windSpeed;
	int windX;
	int windY;
	int chance;
public:
	Board();
	Board(int height, int width);
	Board(int height, int width, int windX, int windY,int windSpeed, int treeChance);
	void createForest(int height, int width);
	Tree getIndex(int x, int y);
	void setWindX(int x);
	void setWindY(int y);
	vector<vector<Tree>> getForest();
	void spreadFire();
};