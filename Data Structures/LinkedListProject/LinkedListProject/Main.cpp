#include"CustomLinkedList.h"
#include <string>
#include <iostream>
using namespace std;


int main() {
	/*
	* This was used to test ListNode
	ListNode<string> fourth{ "fouth" };
	ListNode<string> third{ "third", &fourth };
	ListNode<string> second{ "second", &third };
	ListNode<string> first{ "first", &second };
	
	
	ListNode<string>* curr = &first;
	while(curr != nullptr)
	{
		cout << curr->get() << endl;
		curr = curr->getNext();
	}
	*/
	//tests for the big 3 in Linked List
	/*
	LinkedList<string> a{};
	a.prepend("first");
	a.prepend("second");
	a.prepend("third");
	LinkedList<string>b{};
	b = a;
	cout << a.get(0) << ", " << a.get(1) << ", " << a.get(2) << endl;
	for (int i = 0; i < a.getSize(); i++)
	{
		cout << a.get(i) << ", " << b.get(i) << endl;
	}
	b.set(1, "new");
	for (int i = 0; i < a.getSize(); i++)
	{
		cout << a.get(i) << ", " << b.get(i) << endl;
	}
	b.remove(1);
	for (int i = 0; i < b.getSize(); i++)
	{
		cout << a.get(i) << ", " << b.get(i) << endl;
	}
	*/
	LinkedList<int> a{};
	a.prepend(1);
	a.prepend(2);
	a.prepend(3);
	a.append(4);
	a.append(5);
	cout << a.get(3) << endl;
	cout << a.getRecursive(3) << endl;
	a.printBackwards();
	return 0;
}