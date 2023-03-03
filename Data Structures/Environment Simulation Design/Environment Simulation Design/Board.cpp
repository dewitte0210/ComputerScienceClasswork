#include "Board.h"
#include "Tree.h"
#include <cstdlib>
#include <iostream>
Board::Board() {
	srand(time(0));
}
Board::Board(int height, int width) {
	createForest(height, width);
	srand(time(0));
}
Board::Board(int height, int width, int windX, int windY,int windSpeed, int treeChance) {
	this->windX = windX;
	this->windY = windY;
	chance = treeChance;
	this->windSpeed = windSpeed;
	srand(time(0));
	createForest(height, width);
	
}

//Handles the creation of the main board
void Board::createForest(int height, int width) {

	//Sets the size of the rows and colums in the board and then populates the cells based off a random chance
	forest.resize(height);
	for (int row = 0; row < forest.size(); row++)
	{
		forest.at(row).resize(width);
		for (int col = 0; col < forest.at(row).size(); col++)
		{
			forest.at(row).at(col) = Tree{ false, false };
			int random = (rand() % 100) + 1;
			if (chance > random)
			{
				forest.at(row).at(col).setExist(true);
			}
		}
	}

	// Starts a fire at a random point
	bool fireStarted = false;
	do
	{
		int randX = rand() % width;
		int randY = rand() % height;
		if (forest.at(randX).at(randY).getExist())
		{
			forest.at(randX).at(randY).setBurning(true);
			fireStarted = true;
		}
	} while (!fireStarted);
}
Tree Board::getIndex(int x, int y) {
	return forest[x][y];
}
vector<vector<Tree>> Board::getForest() {
	return forest;
}
void Board::setWindX(int x) { this->windX = x; }
void Board::setWindY(int y) { this->windY = y; }
void Board::spreadFire() {
	cout << "windSpee: " << windSpeed << ", windX: " << windX << ", windY: " << windY << endl;
	//Nested loop to loop through our entire array
	for (int row = 0; row < forest.size(); row++)
	{
		for (int col = 0; col < forest.at(row).size(); col++)
		{
			//getExist marks if a tree is actually there and getRecent marks if a tree began burning on the current simulation cycle
			//this if statement makes sure that the current tree exists and is burning and that it did not begin burning on the current cycle
			//if this is all true then we can spread fire from this tree
			if (forest.at(row).at(col).getExist() && forest.at(row).at(col).getBurning() && !forest.at(row).at(col).getRecent())
			{
				// for loop calculates fire spread in the X direciton based on wind speed and direction
				for (int i = 1; i <= windSpeed; i ++)
				{
					int x = i * windX;
					if (((x + col) >= 0 && (x + col) < forest.at(row).size()))
					{
						forest.at(row).at(x + col).setBurning(true);
						forest.at(row).at(x + col).setRecent(true);
					}
				}
				//for loop calculates fire spread in the Y direciton based on wind speed and direction
				for (int i = 1; i <= windSpeed; i++)
				{
					int y = -i * windY;
					if ((y + row) >= 0 && (y + row) < forest.size())
					{
						forest.at(y + row).at(col).setBurning(true);
						forest.at(y + row).at(col).setRecent(true);
					}
				}

				//This set of If statements check each square next to the tree and spreads fire to them as long as we are not going to get
				//index out of bounds. There is a little repetitive checking over the wind checks, however that shouldn't cause any issues.
				if (row - 1 >= 0)
				{
					forest.at(row-1).at(col).setBurning(true);
					forest.at(row - 1).at(col).setRecent(true);
				}
				if (row + 1 < forest.size())
				{
					forest.at(row + 1).at(col).setBurning(true);
					forest.at(row + 1).at(col).setRecent(true);
				}
				if (col - 1 >= 0)
				{
					forest.at(row).at(col - 1).setBurning(true);
					forest.at(row).at(col - 1).setRecent(true);
				}
				if (col + 1 < forest.at(row).size())
				{
					forest.at(row).at(col + 1).setBurning(true);
					forest.at(row).at(col + 1).setRecent(true);
				}
			}
		}
	}
	// resets every tree on the board so that they can spread fire in the next simulation cycle
	for (int i = 0; i < forest.size(); i++)
	{
		for (int j = 0; j < forest.at(i).size(); j++)
		{
			forest.at(i).at(j).setRecent(false);
		}
	}

}