#pragma once
#include<vector>
using namespace std;

class Person {
private:
    vector<int> priority;
    vector<int> times;
    bool matched = false;
    int match = -1;
    int practiceTime = -1;
public:
    vector<int> getPriorityList() { return priority; }
    int getPrio(int index) { return priority[index]; }
    vector<int> getTimesList() { return times; }
    int getPracticeTime() { return practiceTime; }
    void addPrio(int val) { priority.push_back(val); }
    void addTime(int val) { times.push_back(val); }
    bool getMatched() { return matched; }
    void setMatched(bool match) { matched = match; }
    void assignMatch(int newMatch) { match = newMatch; }
    void setPracticeTime(int t) { practiceTime = t; }
    int getMatchedPerson() { return match; }
};
