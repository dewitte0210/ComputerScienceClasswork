#pragma once
#pragma once
#include<map>
#include<string>
#include<iostream>
class TreeNode {
private:
	double weight;
	std::string pair;
	//child1 holds a child that has a lower weight than self
	TreeNode* child1 = nullptr;
	TreeNode* child2 = nullptr;
public:
	TreeNode(double w)
	{
		weight = w;
		pair = "\0";
	}
	TreeNode(double w, std::string p)
	{
		weight = w;
		pair = p;
	}
	double getWeight() { return weight; }
	std::string getPair() { return pair; }
	void setWeight(double w) { weight = w; }
	void setChar(std::string p) { pair = p; }
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
	std::map<std::string, double> weights;
	std::string encodedCharHelper(std::string p, TreeNode* node)
	{
		std::string code = "";
		if (node->getChild(0) == nullptr && node->getChild(1) == nullptr)
		{
			if (node->getPair() == p)
			{
				return " ";
			}
			return code;
		}
		code = encodedCharHelper(p, node->getChild(0));
		if (code != "")
		{
			code.append("0");
			return code;
		}
		code = encodedCharHelper(p, node->getChild(1));
		if (code != "")
		{
			code.append("1");
			return code;
		}
		return "";
	}
public:
	HuffmanTree(double w, std::string p)
	{
		root = new TreeNode{ w, p };
	}
	HuffmanTree(TreeNode* node) { root = node; }
	std::string getEncodedChar(std::string p)
	{
		return encodedCharHelper(p, root);
	}
	double getRootWeight() { return root->getWeight(); }
	HuffmanTree& operator+(HuffmanTree& obj)
	{
		TreeNode* newRoot = new TreeNode(this->root->getWeight() + obj.root->getWeight(), "\0");
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