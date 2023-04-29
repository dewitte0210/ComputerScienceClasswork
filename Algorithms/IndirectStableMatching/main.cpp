#include<iostream>
#include<fstream>
#include<string>
#include "person.h"
using namespace std;


/*
 * The input file is read as folows
 * Line 1: how many pianist and vocalist
 * Each line after that contains the priority list and times 
 * seperated by a dash(-) EX: 1,2,3,4-4,3,2,1
 * Times are simply integers formatted the same as 1,2,3,4 (in this case)
 */

// To convert char to int take int = char - '0'
void fillTimeAndPrio(Person arr[] , string line, int index)
{
    bool isTime = false;
    for(int i = 0; i < line.size(); i++)
    {
        if(line.at(i) == '-')
        {
           isTime = true; 
        }
        else if(isTime && line.at(i) != ',')
        {
           arr[index].addTime(line.at(i) - '0'); 
        }
        else if(line.at(i) != ',')
        {
            arr[index].addPrio(line.at(i) - '0');
        }
    }
}

bool allMatched(Person arr[])
{
    bool matched = true;
    for(int i = 0; i < arr.size(); i++)
    {
        if(!arr[i].getMatched())
        {
           matched = false; 
        }
    }
    return matched;
}

int main(){
  ifstream input;
  input.open("text.txt");
  int amntPeople = 0;
  input >> amntPeople;
  getline(input);
  string line;
  Person vocalists[amntPeople];
  Person pianists[amntPeople];
  for(int i = 0; i < amntPeople; i++)
  {
      getline(input, line);
      fillTimeAndPrio(vocalists, line, i);
  }
  for(int i = 0; i < amntPeople; i++)
  {
      getline(input, line);
      fillTimeAndPrio(pianists, line, i);
  }
  int voc = 0;
  while(!true)
  {
       
  }
  return 0;
}

