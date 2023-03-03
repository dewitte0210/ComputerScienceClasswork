#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include"Board.h"
#include"Tree.h"
using namespace std;

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int green = 2;
	int red = 4;
	string windDirection = "empty";
	int windX = 0, windY = 0;
	int windSpeed = 0;
	int boardHeight = 0;
	int boardWidth = 0;
	cout << "Hello and welcom to the Forrest Fire simulator!" << endl << "How wide do you want the board to be? ";
	cin >> boardWidth;
	cout << endl << "How high do you want the board to be? ";
	cin >> boardHeight;
	cout << "What do you want the wind speed to be? ";
	cin >> windSpeed;
	cout << "what direction is the wind blowing in? (N,E,S,W,NE,NW)";
	cin >> windDirection;

	//This handles the variable setting for wind direction
	for (int i = 0; i < windDirection.size(); i++) {
		char temp = tolower(windDirection.at(i));
		if (i == 1 && windDirection.at(0) == windDirection.at(i))
		{
			continue;
		}
		switch (temp)
		{
		case 'n':
			windY = 1;
			break;
		case 'e':
			windX = 1;
			break;
		case 's':
			windY = -1;
			break;
		case 'w':
			windX = -1;
			break;
		default:
			windY = 0;
			windX = 0;
		}
	}
	
	//creates the board
	Board sim{ boardHeight, boardWidth, windX, windY, windSpeed, 70 };
	string input = "y";
	vector<vector<Tree>> board{};
	
	//handles the displaying of the simulation
	do
	{
		board = sim.getForest();
		for (int row = 0; row < board.size(); row++)
		{
			cout << "|";
			for (int col = 0; col < board.at(row).size(); col++)
			{
				if (board.at(row).at(col).getExist() && board.at(row).at(col).getBurning())
				{
					SetConsoleTextAttribute(hConsole, red);
					cout << "B";
					SetConsoleTextAttribute(hConsole, 8)
					);
				}
				else if (board.at(row).at(col).getExist())
				{
					SetConsoleTextAttribute(hConsole, green);
					cout << "T";
					SetConsoleTextAttribute(hConsole, 8);
				}
				else
				{
					cout << " ";
				}
				cout << "|";
			}
			cout << endl;
		}
		cout << "would you like to see the next step of the simulation? (y/n)";
		cin >> input;
		sim.spreadFire();
	} while (input == "y");
	return 0;
}