#pragma once
#include <iterator> // forward_iterator_tag
#include <cstddef> // ptrdiff_t

class HiddenArray {
private:
	int data[100]; //Only grant access through iterator!

public:
	struct iterator {
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = int;// change depending on val type
		using pointer = value_type*;
		using reference = value_type&;

		//iterator constructor
		iterator(pointer ptr) :p(ptr) {}

		//Operator overloads
		reference operator*() const { return *p; }
		pointer operator->() { return p; }
		iterator& operator++() {// ++iter
			p++;
			return *this;
		}
		iterator operator++(int) {//iter++
			iterator tmp = *this;
			++(*this);
			return tmp;
		}
		friend bool operator==(const iterator& a, const iterator& b) {
			return a.p == b.p;
		}
		friend bool operator!=(const iterator& a, const iterator& b) {
			return a.p != b.p;
		}
	private:
		pointer p;//point where our iterator is currently
	};
	iterator begin() { return iterator(&data[0]); }
	iterator end() { return iterator(&data[100]); }
};