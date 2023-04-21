#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include "HuffmanTreePairs.h"

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
HuffmanTree getEncodingTree(std::map<std::string, double> m)
{
	std::vector<HuffmanTree> trees;
	//creat all of our trees from the characters
	for (std::map<std::string, double>::iterator i = m.begin(); i != m.end(); i++)
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
double findWeight(std::string contents, std::string pair) {
	int instances = 0;

	for (int i = 0; i < contents.size(); i+=2)
	{
		if (contents.substr(i,2) == pair)
		{
			instances++;
		}
	}
	double weight = static_cast<double>(instances) / contents.size();
	return weight;
}

int main() {
	std::map<std::string, double> weights;
	std::ifstream input;
	input.open("Text.txt");
	std::string contents((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));
	for (int i = 0; i < contents.size(); i+=2)
	{
		if (weights.find(contents.substr(i,2)) == weights.end())
		{
			double letterWeight = findWeight(contents, contents.substr(i,2));
			weights.emplace(contents.substr(i,2), letterWeight);
		}
	}
	input.close();
	HuffmanTree encodingTree = getEncodingTree(weights);
	input.open("Text.txt");
	std::ofstream output;
	output.open("EncodedText.txt");
	for (std::map<std::string, double>::iterator i = weights.begin(); i != weights.end(); i++)
	{
		output << i->first << ": " << encodingTree.getEncodedChar(i->first) << std::endl;
	}
	while (!input.eof())
	{
		std::string line;
		std::getline(input, line);
		for (int i = 0; i < line.size(); i+=2)
		{
			std::string endcoded = encodingTree.getEncodedChar(line.substr(i,2));
			output << endcoded;
		}
	}
	input.close();
	output.close();

	return 0;
}