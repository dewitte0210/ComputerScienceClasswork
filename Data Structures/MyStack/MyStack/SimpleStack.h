#pragma once

template <typename T>
class StackNode {
private:
	T data{};
	StackNode<T>* next{};
	StackNode(){
		next = nullptr;
	}
	StackNode(T dat) {
		data = dat;
		next = nullptr;
	}
	StackNode(T dat, newNext) {
		data = dat;
		next = newNext;
	}
	void set(T dat) { data = dat; }
	void setNext(StackNode<T>* newNext) { next = newNext; }
	T get() { return data; }
	StackNode<T>* getNext() { return next; }
};

template <typename T>
class SimpleStack {
private:
	int size{};
	StackNode<T>* head{};
public:
	SimpleStack() {
		size = 0;
		head = nullptr;
	}
	void push(T data) {
		StackNode<T>* newNode = new StackNode{ data, head };
		head = newNode;
		size++;
	}
	T peek() { return head->get(); }
	T pop() {
		StackNode<T>* newHead = head->getNext();
		T data = head->get();
		delete head;
		head = newHead;
		return data;
		size--;
	}
	int size() { return size; }
};