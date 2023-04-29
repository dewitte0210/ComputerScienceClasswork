#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include"HuffmanTree.h"

// Things To DO: make it work with the ability to use multiple letters in the codex. analyze the preformance

//finds the min index then erases the entry
HuffmanTree findMin(std::vector<HuffmanTree>& trees)
{
	std::vector<HuffmanTree>::iterator index = trees.begin();
	for (std::vector<HuffmanTree>::iterator i = trees.begin(); i != trees.end(); i++)
	{
		if (i->getRootWeight() < index->getRootWeight())
		{
			index = i;
		}
	}
	HuffmanTree tree = *index;
	trees.erase(index);
	return tree;
}
HuffmanTree getEncodingTree(std::map<char, double> m)
{
	std::vector<HuffmanTree> trees;
	//creat all of our trees from the characters
	for (std::map<char,double>::iterator i = m.begin(); i != m.end();i++)
	{
		trees.push_back(HuffmanTree{ i->second, i->first });
	}
	// consolidate all trees into one
	while (trees.size() > 1)
	{
		HuffmanTree tree1 = findMin(trees);
		HuffmanTree tree2 = findMin(trees);
		trees.push_back(tree1 + tree2);
	}
	return trees.at(0);
}
double findWeight(std::string contents, char Letter) {
	int instances = 0;

	for (int i = 0; i < contents.size(); i++)
	{
		if (contents.at(i) == Letter)
		{
			instances++;
		}
	}
	double weight = static_cast<double>(instances) / contents.size();
	return weight;
}

int main() {
	
	std::map<char, double> weights;
	std::ifstream input;
	input.open("TheQuestForBeans.txt");
	std::string contents((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));
	input.close();
	for (int i = 0; i < contents.size(); i++)
	{
		if (weights.find(contents.at(i)) == weights.end())
		{
			double letterWeight = findWeight(contents, contents.at(i));
			weights.emplace(contents.at(i), letterWeight);
		}
	}
	HuffmanTree encodingTree = getEncodingTree(weights);
	input.open("TheQuestForBeans.txt");
	std::ofstream output;
	output.open("EncodedBeans.txt");
	for (std::map<char,double>::iterator i = weights.begin(); i != weights.end(); i++)
	{
		output << i->first << ": " << encodingTree.getEncodedChar(i->first) << std::endl;
	}
	while (!input.eof())
	{
		std::string line;
		std::getline(input, line);
		for (int i = 0; i < line.size(); i++)
		{
			std::string endcoded = encodingTree.getEncodedChar(line.at(i));
			output << endcoded;
		}
	}
	input.close();
	output.close();
	
	
	return 0;
}