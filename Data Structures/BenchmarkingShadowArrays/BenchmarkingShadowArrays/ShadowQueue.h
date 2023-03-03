#pragma once
#include<iostream>
class ShadowQueue {
private:
	int* mainArr;
	int* shadow;
	int size{};
	int capacity{};
	int front{};
	int elSwapped{0};
	void swapArrays() {
		capacity *= 2;
		int* temp = mainArr;
		mainArr = shadow;
		shadow = new int[capacity * 2];
		delete[] temp;
		elSwapped = 0;
		front = 0;
	}
public:
	ShadowQueue() {
		size = 0;
		capacity = 10;
		front = 0;
		mainArr = new int[capacity];
		shadow = new int[capacity * 2];
	}
	void enqueue(int data) {
		if (size >= capacity) { swapArrays(); }
		mainArr[(front + size) % capacity] = data;
		shadow[(front + size) % capacity] = data;
		shadow[(front + elSwapped) % capacity] = mainArr[(front + elSwapped) % capacity];
		size++;
		elSwapped++;
	}
	int dequeue() {
		int x = mainArr[front];
		front = (front + 1) % capacity;
		size--;
		return x;
	}
	int peek() { return mainArr[front]; }
	int getSize() { return size; }
	void print() {
		std::cout << "\nprinting mainArr" <<  std::endl;
		for (int i = 0; i < capacity; i++)
		{
			std::cout << mainArr[i]<< ", ";
		}
		std::cout << "\nprinting shadow" << std::endl;
		for (int i = 0; i < capacity; i++)
		{
			std::cout << shadow[i] << ", ";
		}
	}
};