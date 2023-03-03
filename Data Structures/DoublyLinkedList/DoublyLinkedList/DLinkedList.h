#pragma once

template <typename T>
class DListNode {
private:
	T data;
	DListNode<T>* next;
	DListNode<T>* prev;

public:
	void set(T dat) { data = dat; }
	void setNext(DListNode<T>* newNext) { next = newNext; }
	void setPrev(DListNode<T>* newPrev) { prev = newPrev; }
	T get() { return data; }
	DListNode<T>* getNext() { return next; }
	DListNode<T>* getPrev() { return prev; }
};

template <typename T>
class DLinkedList {
private:
	int size{ 0 };
	DListNode<T>* head{ nullptr };

public:
	//TODO: Destructor, Constructors, Copy Assignment

	void insert(T item, int index) {
		//TODO
	}
	T get(int index) {
		//TODO
	}
	int getSize() {return size;}
	void prepend(T item) {

	}
	void append(T item) {

	}
	T remove(int index) {
		DListNode<T>* curr = head;
		for (int i = 0; i < index; i++)
		{
			curr = curr->getNext();
		}
		if (index == 0)
		{
			head = curr->getNext();
			curr->getNext()->setPrev(nullptr);
		}
		else
		{
			curr->getPrev()->setNext(curr->getNext());
			if (index < size - 1)
			{
				curr->getNext()->setPrev(curr->getPrev());
			}
		}	
		T data = curr->get();
		delete curr;
		size--;
		return data;
	}
};