#pragma once
#include<map>
#include<string>
#include<iostream>
class TreeNode {
private: 
	double weight;
	char character;
	//child1 holds a child that has a lower weight than self
	TreeNode* child1 = nullptr;
	TreeNode* child2 = nullptr;
public:
	TreeNode(double w)
	{
		weight = w;
		character = '\0';
	}
	TreeNode(double w, char c)
	{
		weight = w;
		character = c;
	}
	double getWeight() { return weight; }
	char getCharacter() { return character; }
	void setWeight(double w) { weight = w; }
	void setChar(char c) { character = c; }
	TreeNode* getChild(int pos)
	{
		switch (pos) {
		case 0:
			return child1;
		case 1:
			return child2;
		default:
			std::cout << "Error in TreeNode.getChild() returning child1" << std::endl;
			return child1;
		}
	}
	void setChild(TreeNode* node, int pos)
	{
		switch (pos) {
		case 0:
			child1 = node;
			break;
		case 1:
			child2 = node;
			break;
		default:
			std::cout << "Error in TreeNode.setChild()" << std::endl;
		}

	}
};

class HuffmanTree {
private:
	TreeNode* root{ nullptr };
	int size{ 0 };
	std::map<char, double> weights;
	std::string encodedCharHelper(char c, TreeNode* node)
	{
		std::string code = "";
		if (node->getChild(0) == nullptr && node->getChild(1) == nullptr)
		{
			if (node->getCharacter() == c)
			{
				return " ";
			}
			return code;
		}
		code = encodedCharHelper(c, node->getChild(0));
		if (code != "")
		{
			code.append("0");
			return code;
		}
		code = encodedCharHelper(c, node->getChild(1));
		if (code != "")
		{
			code.append("1");
			return code;
		}
		return "";
	}
public:
	HuffmanTree(double w, char c) 
	{
		root = new TreeNode{ w, c };
	}
	HuffmanTree(TreeNode* node) { root = node; }
	std::string getEncodedChar(char c) 
	{
		return encodedCharHelper(c, root);
	}
	double getRootWeight() { return root->getWeight(); }
	HuffmanTree& operator+(HuffmanTree& obj)
	{
		TreeNode* newRoot = new TreeNode(this->root->getWeight() + obj.root->getWeight(), '\0');
		if (this->root->getWeight() < obj.root->getWeight())
		{
			newRoot->setChild(this->root, 0);
			newRoot->setChild(obj.root, 1);
		}
		else
		{
			newRoot->setChild(obj.root, 0);
			newRoot->setChild(this->root, 1);
		}
		this->root = newRoot;
		return *this;
	}
};