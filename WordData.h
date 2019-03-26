// Student Name: Lin Li
// Student ID: 40044486
#pragma once
#include<iostream>
using namespace std;
#include "NumList.h"

class WordData
{
public:
	WordData(string word, int lineNumber);
	WordData(const WordData&);
	WordData & operator =(const WordData&);
	~WordData();

	NumList nl;
	bool lineNumberExists(int lineNumber);
	void appendToListofLineNumbers(int number);
	int getFrequency();
	const char* getPointerToStoredWord();
	const NumList& getReferenceToNumList() const;
	int compareWord(const char* givenWord);
	void print();

	void incrementFrequency() {
		++frequency;
	}

private:
	char *list;
	int frequency;
};