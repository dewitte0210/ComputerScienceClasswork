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