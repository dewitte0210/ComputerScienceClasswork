#pragma once
#include <iostream>
template <typename T>
class ListNode
{
private:
	ListNode<T>* next;
	T data{};
public:
	ListNode() { next = nullptr; }
	ListNode(T data)
	{
		this->data = data;
		this->next = nullptr;
	}
	ListNode(T data, ListNode* next)
	{
		this->data = data;
		this->next = next;
	}
	~ListNode() { delete next; }
	void set(T data) { this->data = data; }
	T get() { return data; }
	void setNext(ListNode<T>* newNext) {next = newNext; }
	ListNode* getNext() { return next; }
};

template <typename T>
class LinkedList {
private:
	int size;
	ListNode<T>* head;
public:
	//Default constructor sets size to 0 and assigns nullpointer to head
	LinkedList() {
		size = 0;
		head = nullptr;
	}
	// deletes all of the data in the linked list
	~LinkedList() {
		ListNode<T>* curr = head;
		ListNode<T>* next{};
		while (curr != nullptr)
		{
			next = curr->getNext();
			delete curr;
			curr = next;
		}
	}
	LinkedList(LinkedList<T>& obj) {
		this->size = obj.size;
		this->head = nullptr;
		
		// uses prepend becaseu prepend is faster than append. so we start at the end of obj and append all the elements in reverse order
		for (int i = size-1; i >= 0; i--)
		{
			this->prepend(obj.get(i));
		}
	}

	// overload of the = operator
	LinkedList* operator =(LinkedList<T>& obj) {
		ListNode<T>* curr = new ListNode<T>;
		ListNode<T>* next = new ListNode<T>;
		curr = head;
		//first deletes all of the elements in the current list
		for (int i = 0; i < size - 1; i++)
		{
			next = curr->getNext();
			delete curr;
			curr = next;
		}
		delete next;
		// now we do the same as the copy constructor.
		for (int i = obj.getSize() - 1; i >= 0; i--)
		{
			this->prepend(obj.get(i));
		}
		return this;
	}
	
	//searches the list for the index that we are looking for
	T get(int index) {
		if (index >= size) { return T{}; }

		ListNode<T>* curr = head;
		for (int i = 0; i < index; i++)
		{
			curr = curr->getNext();
		}
		return curr->get();
	}

	T getRecursive(int index) {
		//Call the recursive helper witht he right starting pointer
		T data = getRecursiveHelper(index, head);
		return data;
	}

	T getRecursiveHelper(int index, ListNode<T>* cur ) {
		//Base case
		if (index <= 0)
		{
			return cur->get();
		}
		//Recursive case
		return getRecursiveHelper(index- 1, cur->getNext());
	}

	//Sets the data at a specified index of the list
	void set(int index, T data) {
		ListNode<T>* curr = head;
		for (int i = 0; i < index; i++)
		{
			curr = curr->getNext();
		}
		curr->set(data);
	}
	int getSize() { return size; }
	
	void insert(int inedx, T data) {

	}

	//Appends a new node onto the list with the passed data
	void append(T item)
	{
		if (size == 0)
		{
			head = new ListNode<T>{ item };
			size++;
			return;
		}
		ListNode<T>* curr = head;
		while (curr != nullptr)
		{
			curr = curr->getNext();
		}
		ListNode<T>* newNode = new ListNode<T>{ item, nullptr };
		curr->setNext(newNode);
		size++;
		
	}
	
	//prepends a new node onto the list with the passed data
	void prepend(T data) {
		ListNode<T>* newNode = new ListNode<T>{data, head};
		head = newNode;
		size++;
	}

	//Removes the data at index
	T remove(int index) {
		ListNode<T>* before = head;
		for(int i = 0; i < index; i++)
		{
			before = before->getNext();
		}
		ListNode<T>* temp = before->getNext();
		T data = temp->get();
		before->setNext(temp->getNext());
		delete temp;
		size --;
		return data;
	}

	void printBackwards() {
		printBackwardsHelper(head);
	}
	void printBackwardsHelper(ListNode<T>* curr)
	{
		if (curr == nullptr){ return; }
		printBackwardsHelper(curr->getNext());
		std::cout << " " << curr->get();
	} 
};