#include "SimpleArrayList.h"
using namespace std;

template<typename T>
SimpleArrayList<T>::SimpleArrayList() {
	data = new T[];
	numElements = 0;
	capacity = 0;
}

template<typename T>
SimpleArrayList<T>::~SimpleArrayList() {
	delete data;
}

template<typename T>
bool SimpleArrayList<T>::append(T dat) {

	return false;
}

template<typename T>
bool SimpleArrayList<T>::prepend(T dat) {

	return false;
}

template<typename T>
int SimpleArrayList<T>::getSize() {

	return 0;
}

template<typename T>
int SimpleArrayList<T>::getNumElements() {

}

template<typename T>
bool SimpleArrayList<T>::remove(int index) {

	return false;
}

template<typename T>
bool SimpleArrayList<T>::insert(T dat, int index) {

	return false;
}

template<typename T>
T SimpleArrayList<T>::get(int i) {
	
	return T{};
}

template<typename T>
bool SimpleArrayList<T>::set(T dat) {

	return false;
}
