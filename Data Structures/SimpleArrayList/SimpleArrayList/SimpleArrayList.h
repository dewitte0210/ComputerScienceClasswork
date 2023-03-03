#pragma once

template <typename T> //Generic class: T is the type variable
class SimpleArrayList {
private:
	int numElements; // how many elements are currently stored
	int capacity; // how many elements can we store without resizing
	T* data; //Array to hold the datta. using a pointer because we don't know the size of the array.
	void resize(int add){
		T* tempArray = new T[capacity + add];
		for (int i = 0; i < numElements -1; i++)
		{
			tempArray[i] = data[i];
		}
		delete data;
		data = tempArray;
		capacity += add;
	}
public:
	SimpleArrayList() {
		data = new T[10];
		numElements = 0;
		capacity = 10;
	}
	SimpleArrayList(const SimpleArrayList<T>& other) {
		this->numElements = other.numElements;
		this->capacity = other.capacity;
		this->data = new T[capacity];
		for (int i = 0; i < numElements - 1; i++)
		{
			data[i] = other.get(i);
		}
	}
	~SimpleArrayList() { // Destructor
		delete[] data;
		data = nullptr;
	}

	//Copy Assignment
	SimpleArrayList<T>& operator = (const SimpleArrayList<T>& other){
		//First, destruct any fields that need destruction
		delete[] data;
		//Second replicate the copy constructor
		this->numElements = other.numElements;
		this->capacity = other.capacity;
		this->data = new T[capacity];
		for (int i = 0; i < numElements - 1; i++)
		{
			data[i] = other.get(i);
		}
		return this;
	}

	bool append(T dat) {
		if (capacity == numElements) 
		{
			resize(1);
			capacity++;
		}
		data[numElements] = dat;
		numElements++;
		return true;
	}
	bool prepend(T dat) {
		// check to make sure we have enough space for a new element
		if (capacity == numElements)
		{
			resize(1);
			capacity++;
		}
		//Shifts every element to the right
		for (int i = numElements; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
		// puts the data in the first spot and increments numElements
		data[0] = dat;
		numElements++;
		return true;
	}
	int getSize() {
		return capacity;
	}
	int getNumElements() {
		return numElements;
	}
	bool remove(int index) {
		return false;
	}
	bool insert(T dat, int index) {
		return false;
	}
	T get(int i) {
		return data[i];
	}
	bool set(T dat) {
		return false;
	}
};

