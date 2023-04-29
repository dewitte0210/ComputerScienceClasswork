#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "person.h"
using namespace std;


/*
 * The input file is read as folows
 * Line 1: how many pianist and vocalist
 * Each line after that contains the priority list and times
 * seperated by a dash(-) EX: 0,1,2,3-3,2,1,0
 * Times are simply integers formatted the same as 0,1,2,3 (in this case)
 */

 // To convert char to int take int = char - '0'
void fillTimeAndPrio(vector<Person>& arr, string line, int index)
{
	bool isTime = false;
	for (int i = 0; i < line.size(); i++)
	{
		if (line.at(i) == '-')
		{
			isTime = true;
		}
		else if (isTime && line.at(i) != ',')
		{
			arr[index].addTime(line.at(i) - '0');
		}
		else if (line.at(i) != ',')
		{
			arr[index].addPrio(line.at(i) - '0');
		}
	}
}

bool allMatched(vector<Person> arr)
{
	bool matched = true;
	for (int i = 0; i < arr.size(); i++)
	{
		if (!arr[i].getMatched())
		{
			matched = false;
		}
	}
	return matched;
}

int getTimeMatch(Person p1, Person p2)
{
	for (int i = 0; i < p1.getTimesList().size(); i++)
	{
		for (int j = 0; j < p2.getTimesList().size(); j++)
		{
			if (p1.getTimesList().at(i) == p2.getTimesList().at(j))
			{
				return p1.getTimesList().at(i);
			}
		}
	}
	return -1;
}
int getTimeMatch(Person p1, Person p2, int time)
{
	for (int i = 0; i < p1.getTimesList().size(); i++)
	{
		for (int j = 0; j < p2.getTimesList().size(); j++)
		{
			if (p1.getTimesList().at(i) == p2.getTimesList().at(j) && p1.getTimesList().at(i) != time)
			{
				return p1.getTimesList().at(i);
			}
		}
	}
	return -1;
}
bool checkTimeCollision(vector<Person> vec, int time) {
	int accum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).getPracticeTime() == time)
		{
			accum++;
		}
	}
	if (accum > 0)
	{
		return true;
	}
	return false;
}

int findPersonByTimeSlot(vector<Person> vec, int time) {
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).getPracticeTime() == time)
		{
			return i;
		}
	}
	return -1;
}

int getPersonPriority(Person p, int person)
{
	int Priority = -1;
	for (int i = 0; i < p.getPriorityList().size(); i++)
	{
		if (p.getPriorityList().at(i) == person)
		{
			Priority = i;
		}
	}
	return Priority;
}
int main() {
	ifstream input;
	input.open("text.txt");
	string amntPeople;
	getline(input, amntPeople);
	string line;
	int size = amntPeople.at(0) - '0';
	vector<Person> vocalists;
	vector<Person> pianists;
	for (int i = 0; i < size; i++)
	{
		Person p;
		getline(input, line);
		vocalists.push_back(p);
		fillTimeAndPrio(vocalists, line, i);
	}
	for (int i = 0; i < size; i++)
	{
		Person p;
		getline(input, line);
		pianists.push_back(p);
		fillTimeAndPrio(pianists, line, i);
	}
	int voc = 0;
	int p = 0;
	while (!allMatched(vocalists))
	{
		int pian = vocalists.at(voc).getPrio(p % size);
		if (!pianists.at(pian).getMatched())
		{
			int time = getTimeMatch(vocalists.at(voc), pianists.at(pian));
			bool collider = checkTimeCollision(vocalists, time);
			if (time == -1) // both have no matching time
			{
				p++;
			}
			else if (collider) //Handle Collision
			{
				int newTime = getTimeMatch(vocalists.at(voc), pianists.at(pian), time);
				if (newTime == -1) //If there is no new time check if the original occupiers can change
				{
					Person origVoc = vocalists.at(findPersonByTimeSlot(vocalists, time));
					Person origPian = pianists.at(findPersonByTimeSlot(pianists, time));
					newTime = getTimeMatch(origVoc, origPian, time);
					if (newTime == -1) //If that cant happen the highest priority match gets the time slot
					{
						int origPrio = getPersonPriority(origVoc, findPersonByTimeSlot(pianists, time));
						int newPrio = getPersonPriority(vocalists.at(voc), pian);
						if (origPrio == newPrio) // If this is equal then we check in reverse
						{
							origPrio = getPersonPriority(origPian, findPersonByTimeSlot(vocalists, time));
							newPrio = getPersonPriority(pianists.at(pian), voc);
							if (origPrio > newPrio) //Reverse Check
							{
								p++;
							}
							else
							{
								vocalists.at(voc).setPracticeTime(time);
								vocalists.at(voc).setMatched(true);
								vocalists.at(voc).assignMatch(pian);
								pianists.at(pian).setPracticeTime(time);
								pianists.at(pian).setMatched(true);
								pianists.at(pian).assignMatch(voc);
								vocalists.at(findPersonByTimeSlot(vocalists, origVoc.getPracticeTime())).setMatched(false);
								vocalists.at(findPersonByTimeSlot(vocalists, origVoc.getPracticeTime())).assignMatch(-1);
								vocalists.at(findPersonByTimeSlot(vocalists, origVoc.getPracticeTime())).setPracticeTime(-1);
								pianists.at(findPersonByTimeSlot(pianists, origPian.getPracticeTime())).setMatched(false);
								pianists.at(findPersonByTimeSlot(pianists, origPian.getPracticeTime())).assignMatch(-1);
								pianists.at(findPersonByTimeSlot(pianists, origPian.getPracticeTime())).setPracticeTime(-1);
							}
						}
						if (origPrio > newPrio)
						{
							p++;
						}
						else
						{
							vocalists.at(voc).setPracticeTime(time);
							vocalists.at(voc).setMatched(true);
							vocalists.at(voc).assignMatch(pian);
							pianists.at(pian).setPracticeTime(time);
							pianists.at(pian).setMatched(true);
							pianists.at(pian).assignMatch(voc);
							vocalists.at(findPersonByTimeSlot(vocalists, origVoc.getPracticeTime())).setMatched(false);
							vocalists.at(findPersonByTimeSlot(vocalists, origVoc.getPracticeTime())).setPracticeTime(-1);
							pianists.at(findPersonByTimeSlot(pianists, origPian.getPracticeTime())).setMatched(false);
							pianists.at(findPersonByTimeSlot(pianists, origPian.getPracticeTime())).setPracticeTime(-1);
						}
					}
					else
					{
						vocalists.at(findPersonByTimeSlot(vocalists, origVoc.getPracticeTime())).setPracticeTime(newTime);
						pianists.at(findPersonByTimeSlot(pianists, origPian.getPracticeTime())).setPracticeTime(newTime);
						vocalists.at(voc).setPracticeTime(time);
						vocalists.at(voc).setMatched(true);
						vocalists.at(voc).assignMatch(pian);
						pianists.at(pian).setPracticeTime(time);
						pianists.at(pian).setMatched(true);
						pianists.at(pian).assignMatch(voc);
					}
				}
			}
			else //No collision, feel free to set
			{
				vocalists.at(voc).setPracticeTime(time);
				vocalists.at(voc).setMatched(true);
				vocalists.at(voc).assignMatch(pian);
				pianists.at(pian).setPracticeTime(time);
				pianists.at(pian).setMatched(true);
				pianists.at(pian).assignMatch(voc);
			}
		}
		else
		{
			p++;
		}
		if (vocalists.at(voc).getMatched() == true)
		{
			voc = (voc + 1) % size;
		}
	}

	cout << "Vocalists" << endl;
	for (int i = 0; i < vocalists.size(); i++)
	{
		cout << i << " Matched With: " << vocalists.at(i).getMatchedPerson() << " At Time:  " << vocalists.at(i).getPracticeTime() << endl;
	}
	cout << "Pianists" << endl;
	for (int i = 0; i < pianists.size(); i++)
	{
		cout << i << " Matched With: " << pianists.at(i).getMatchedPerson() << " At Time: " << pianists.at(i).getPracticeTime() << endl;
	}
	return 0;
}

