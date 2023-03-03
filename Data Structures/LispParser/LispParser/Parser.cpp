#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

int main(){
	ifstream file("Lisp.txt");
	queue<int> parentheses{};
	string line{};

	//gets the file line by line and then parses through looking for each ( or )
	while (!file.eof())
	{
		getline(file, line);
		for (int i = 0; i < line.size(); i++)
		{
			//adds 1 or -1 to the queue depending on which character we see
			if (line.at(i) == '(')
			{
				parentheses.push(1);
			}
			else if (line.at(i) == ')')
			{
				parentheses.push(-1);
			}
		}
	}
	int count{ 0 };
	int size = parentheses.size();

	//loop through the queue and add up all the values
	for (int i = 0; i < size; i++)
	{
		count += parentheses.front();
		parentheses.pop();

		//if at any point the total is negative then we know we have encounterd ) that does not have a matching (
		if (count < 0)
		{
			break;
		}
	}

	//final checks for program correctness
	if (count != 0)
	{
		cout << "This program is not correct" << endl;
	}
	else
	{
		cout << "This program is correct" << endl;
	}
	cout << count;
	file.close();
	return 0;
}