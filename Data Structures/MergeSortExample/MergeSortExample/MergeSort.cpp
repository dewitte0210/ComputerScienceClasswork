#include<vector>
#include<iostream>
using namespace std;



void mergeHelper(vector<int>& v, int start, int end) {
	//Phase 1: Divide!
	if (start + 1 >= end) { return; }
	int mid = (end + start) / 2;
	//Left Half
	mergeHelper(v, start, mid);
	//Right Half
	mergeHelper(v, mid, end);

	//Phase 2: Merge!
	int left = start;
	int right = mid;
	vector<int> temp{};
	while (left < mid && right < end) {
		if (v[left] < v[right])
		{
			temp.push_back(v[left]);
			left++;
		}
		else
		{
			temp.push_back(v[right]);
			right++;
		}
	}
	while (left < mid)
	{
		temp.push_back(v[left]);
		left++;
	}
	while (right < end)
	{
		temp.push_back(v[right]);
		right++;
	}
	for (int i = 0; i < temp.size(); i++)
	{
		v[i] = temp[i];
	}
	return;
}

void mergesort(vector<int>& v) {
	mergeHelper(v, 0, v.size());
}

int main() {
	vector<int> sortme = { 4,3,2,1,5,7 };
	mergesort(sortme);
	for (int x : sortme)
	{
		cout << x << " ";
	}
	return 0;
}