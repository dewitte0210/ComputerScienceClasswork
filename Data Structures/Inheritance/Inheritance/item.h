#pragma once
#include <iostream>
#include <string>
using namespace std;

enum foodEnum{veggie, grain, fruit};

class Item {
	//fileds
protected:
	string name;
	int weight;
public:
	const int id;
	Item() : id(0) {
		name = "";
		weight = 0;	
	}
	Item(string s, int w, int i) : id(i) {
		name = s;
		weight = w;
		cout << "Item const named: " << name << endl;
	}
	
	string getName() { return name; }
	int getWeight() { return weight; }
	bool isHeavy() { return weight > 17; }
	virtual void equip() = 0;
};

// Food is and Item
class Food : public virtual Item {
private:
	bool spoiled{ false };
	string foodType;
public:
	Food(string type, string name, int weight, int id) : Item(name, weight, id) {
		foodType = type;
		cout << "Food const" << endl;
	}
	bool isSpoiled(){ return spoiled; }
	//Overidde
	bool isHeavy() { return weight > 1; }
	void equip() { cout << "I eat the " << name << "!\n"; }
};

class Tool : public virtual Item {
private:
	const bool needsPower;
	bool powerd;
	int durability;
public:
	Tool(bool needsPower, int dur, string name, int weight, int id) : needsPower(needsPower) ,Item(name, weight, id){
		durability = dur;
		powerd = !needsPower;
		cout << "Tool const" << endl;
	}
	void flipSwitch() {
		powerd = !powerd;
	}
	bool isPowerd() { return powerd; }
	int getDurability() { return durability; }
	void equip() { cout << "I turn on the " << name << "!\n"; flipSwitch(); }
};

class ChocolateSpoon : public Food, public Tool {
public:
	ChocolateSpoon(int weight, int id) : Food("Candy", "Chocolate Spoon", weight, id), Tool(false, 1, "Chocolate Spoon", weight, id) {
		cout << "Chocolate Spoon csont" << endl;
	}
	void equip(){
		cout << "A chocolate spoon! Tasty!" << endl;
	}
};