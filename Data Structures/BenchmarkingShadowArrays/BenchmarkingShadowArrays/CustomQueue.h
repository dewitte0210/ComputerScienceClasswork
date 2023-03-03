#pragma once
#include <iostream> //For the print method

//Author: Alexi Brooks
//Date: 2022.November.1

//A queue implementation using a circular array but not a shadow array
class CustomArrayQueue {
private:
	//Fields
	int* data{ new int[2] };
	int size{ 0 };
	int capacity{ 2 };
	int frontIndex{ 0 };

public:
	//Constructors
	CustomArrayQueue() {}
	CustomArrayQueue(const CustomArrayQueue& other) {
		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[(i + other.frontIndex) % capacity];
		}
	}
	CustomArrayQueue operator=(const CustomArrayQueue& other) {
		delete data;
		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[(i + other.frontIndex) % capacity];
		}
	}
	//Destructor
	~CustomArrayQueue() {
		delete data;
	}
	//Core Methods
	int dequeue() {
		int x = frontIndex;
		frontIndex = (frontIndex + 1) % capacity;
		size--;
		return data[x];
	}
	void enqueue(int item) {
		if (size >= capacity) { //If out of space, expand
			int* newData = new int[capacity * 2];
			for (int i = 0; i < size; i++) {
				newData[i] = data[(frontIndex + i) % capacity];
			}
			delete data;
			data = newData;
			frontIndex = 0;
			capacity *= 2;
		}
		data[(frontIndex + size) % capacity] = item;
		size++;
	}
	int peek() { return data[frontIndex]; }
	int getSize() { return size; }
	//Helpful methods for testing
	void print() {
		std::cout << "Queue: [";
		for (int i = 0; i < size; i++) {
			std::cout << " " << data[(frontIndex + i) % capacity];
		}
		std::cout << " ]\n";
	}
};