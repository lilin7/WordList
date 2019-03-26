// Student Name: Lin Li
// Student ID: 40044486
#include<iostream>
using namespace std;
#include "NumList.h"

//determine whether the list is empty:
bool NumList::isEmpty() const {
	return(size == 0);
}

//determine whether a given element exists in the list:
bool NumList::elementExists(int x) const {
	for (int i = 0; i < size; i++) {
		if (x == list[i]) {
			return true;
		}
	}
	return false;
}

//append an element to the end of the list
void NumList::append(int x) {
	if (size < capacity) {
		list[size++] = x;
	}
	else {
		helper();
		list[size++] = x;
	}
}

//get an element at a specified position:
int NumList::getElement(int location) {
	if (location < 0 || location >= size){
		cout << "The location is out of range." << endl;
		return -1;
	}
	else {
		return list[location];
	}
}

//set an element at a specified position:
void NumList::setElement(int location, int value) {
	if (location < 0 || location > size) {
		cout << "The location is out of range." << endl;
	}
	else {
		list[location]=value;
	}
}

//get size of the list:
int NumList::getSize() const {
	return size;
}

//get capacity of the list:
int NumList::getCapacity() const {
	return capacity;
}

//get a read-only pointer to the underlying array:
int* const NumList::getPointerToArray() {
	return list;
}

//get size of the NumList:
int NumList::getSize() { 
	return size; 
}

//constructor:
NumList::NumList()
{
	capacity = 1;
	size = 0;
	list = new int[capacity];
}

//copy constructor:
NumList::NumList(const NumList& n)
{
	capacity = n.capacity;
	size = n.size;
	list = new int;
	*list = *(n.list);
	for (int i = 0; i < size; ++i) {
		list[i] = n.list[i];
	}
	
}

//copy assignment operator:
NumList & NumList ::operator =(const NumList& n)
{
	return *this;
}


//destructor:
NumList::~NumList()
{
	delete[] list;
}

//private helper method to implement resizing operation on a dynamically allocated array:
void NumList::helper() {
	int *tmp = new int[capacity * 2];

	for (int i = 0; i < capacity; i++) {
		tmp[i] = list[i];
	}
	list = tmp;
	capacity *= 2;
}
