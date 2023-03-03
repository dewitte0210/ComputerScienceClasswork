#include<iostream>
#include "ShadowQueue.h"
#include"CustomQueue.h"]
#include<vector>
#include<chrono>
using namespace std;
void shadowtenThou() {
	ShadowQueue q{};
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
		q.enqueue(i);
	}
	end = chrono::high_resolution_clock::now();
	chrono::duration<double> secondsElapsed = end - start;
	cout << "enqueue one element took: " << secondsElapsed.count() << endl;
}
void regulartenThou() {
	CustomArrayQueue q{};
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
		q.enqueue(i);
	}
	end = chrono::high_resolution_clock::now();
	chrono::duration<double> secondsElapsed = end - start;
	cout << "enqueue one element took: " << secondsElapsed.count() << endl;
}
void vectortenThou() {
	vector<int> vec{};
	chrono::time_point<chrono::high_resolution_clock> start, end;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
		vec.push_back(i);
	}
	end = chrono::high_resolution_clock::now();
	chrono::duration<double> secondsElapsed = end - start;
	cout << "enqueue one element took: " << secondsElapsed.count() << endl;
}
int main() {
	shadowtenThou();
	regulartenThou();
	vectortenThou();
	return 0;
}