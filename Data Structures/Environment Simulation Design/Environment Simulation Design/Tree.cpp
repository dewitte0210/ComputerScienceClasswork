#include "Tree.h"

Tree::Tree() {
	isBurning = false;
}

// constructor 
Tree::Tree(bool fire, bool exists)
{
	isBurning = fire;
	this->exists = exists;
	this->setRecent(false);
}
//setters and getters for all variables
void Tree::setBurning(bool burning) { isBurning = burning; }
bool Tree::getBurning() { return isBurning; }
void Tree::setExist(bool exist) { this->exists = exist; }
bool Tree::getExist() { return exists; }
void Tree::setRecent(bool recent) { this->recent = recent; }
bool Tree::getRecent() { return recent; }