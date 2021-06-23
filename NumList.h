// Lin Li

#pragma once
#include<iostream>
using namespace std;

class NumList
{
public:
	NumList(); 
	NumList(const NumList& n);
	NumList & operator =(const NumList&);
	~NumList();

	bool isEmpty() const;
	bool elementExists(int x) const; 
	void append(int x); 
	int getElement(int location);
	void setElement(int location, int value);
	int getSize() const;
	int getCapacity() const;
	int* const getPointerToArray();
	void helper();
	int getSize();

private:
	int *list;
	int size;
	int capacity;
};
