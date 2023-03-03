#pragma once
#include <vector>
using namespace std;

class TreeNode {
private:
	int data{0};
	vector<TreeNode*> children{};
public:
	TreeNode(int d) {
		data = d;
	}
	int getData() { return data; }
	vector<TreeNode*> getChildren() { return children; }
	void setData(int dat) { data = dat; }
	void addChild(TreeNode* c) { children.push_back(c); }
};

class Tree {
private:
	TreeNode* root{ nullptr };
	int size{ 0 };
public:
	Tree() {}
	int getSize() { return size; }
	TreeNode* getRoot() { return root; }
	void insert(int newData, TreeNode* parent) {
		TreeNode* newNode = new TreeNode{ newData };
		if (size == 0) { root = newNode; }
		else { parent->addChild(newNode); }
		size++;
	}
	// TODO both get and reove require us to figure out some organizations of our nodes.
	// We don't know how to do this yet!
	//void get() {}
	//int remove() {}
	
	TreeNode* getRoot() { return root; }
	int getHeight() {
		return getHeightHelper(root);
	}
	int getHeightHelper(TreeNode* t) {
		if (t == nullptr) { return 0; }
		if (t->getChildren().size() == 0) { return 1; }
		int max{ 0 };
		for (TreeNode* child : t->getChildren())
		{
			int temp = getHeightHelper(child);
			if (max < temp) { max = temp; }
		}
		return max + 1;
	}
};