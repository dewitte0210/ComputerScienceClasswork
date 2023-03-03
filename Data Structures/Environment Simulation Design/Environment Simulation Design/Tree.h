#pragma once
class Tree {
private:
	bool isBurning;
	bool exists;
	bool recent;
	char icon;
public:
	Tree();
	Tree(bool fire, bool exists);
	void setBurning(bool burning);
	bool getBurning();
	void setExist(bool exist);
	bool getExist();
	bool getRecent();
	void setRecent(bool recent);
};