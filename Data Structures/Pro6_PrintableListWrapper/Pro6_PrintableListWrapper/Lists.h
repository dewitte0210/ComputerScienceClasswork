#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include "CustomLinkedList.h"
using namespace std;

template <typename T>
class PrintableIterable {
public:
	PrintableIterable() {}
	virtual void insert(T data, int i) = 0;
	virtual void remove(int i) = 0;
	virtual T get(int i) = 0;
	virtual int size() = 0;
	friend ostream& operator<<(ostream& stream, PrintableIterable print);
};

template<typename T>
class PrintableVector : public PrintableIterable<T> {
private:
	vector<T> vec{};
public:
	PrintableVector() : PrintableIterable<T>() {}
	void insert(T data, int i) { vec.insert(vec.begin() + i, data); }
	void remove(int i) { vec.erase(vec.begin() + i);}
	T get(int i) { return vec.at(i); }
	int size() { return vec.size(); }
	
	friend ostream& operator<<(ostream& stream, PrintableVector vec) {
		for (int i = 0; i < vec.size(); i++)
		{
			stream << vec.get(i) << ", ";
		}
		return stream;
	}
};

template<typename T>
class PrintableList : public PrintableIterable<T> {
private: 
	LinkedList<T> list{};
public:
	PrintableList() : PrintableIterable<T>() {}
	void insert(T data, int i) { list.insert(i, data); }
	void remove(int i) { list.remove(i); }
	T get(int i) { return list.get(i); }
	int size() { return list.getSize(); }
	friend ostream& operator<<(ostream& stream, PrintableList list) {
		for (int i = 0; i < list.size(); i++)
		{
			stream << list.get(i) << ", ";
		}
		return stream;
	}
};