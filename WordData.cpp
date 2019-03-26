// Student Name: Lin Li
// Student ID: 40044486
#include<iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <iomanip>
#include "WordData.h"

//determine whether a line number is in the line number list:
bool WordData::lineNumberExists(int lineNumber) {
	for (int i = 0; i < nl.getSize(); ++i) {
		if (lineNumber == nl.getElement(i)) {
			return true;
		}
	}
	return false;
}

//append a given number to the list of line numbers, only if it is not already there:
void WordData::appendToListofLineNumbers(int number) {
	if (lineNumberExists(number)) {
		return;
	}
	else {
		nl.append(number);
	}
}

//get the frequency count:
int WordData::getFrequency() {
	return frequency;
}

//get a read-only pointer to the stored word:
const char* WordData::getPointerToStoredWord() {
	return list;
}

//get a read-only reference to the NumList object:
const NumList& WordData::getReferenceToNumList() const {
	return nl;
}
/*Determine whether the stored word compares equal to, or comes before or after a given word.
Use case insensitive alphabetical ordering of strings of characters when comparing two words.*/
int WordData::compareWord(const char* givenWord) {
	std::string stored(list);
	std::string given(givenWord);

	std::transform(stored.begin(), stored.end(), stored.begin(), ::tolower);
	std::transform(given.begin(), given.end(), given.begin(), ::tolower);

	return stored.compare(given);	
}

/*print the word together with its frequency count and list of line numbers
to a specified ostream object (like cout):*/
void WordData::print() {
	cout << setfill(' ') << setw(20) << list << " (" << frequency << ") ";
	for (int i = 0; i < nl.getSize(); i++) {
		cout << nl.getElement(i) << " " ;
	}
	cout << endl;
}


//constructor:
WordData::WordData(string word, int lineNumber) : frequency(1)
{
	int length = word.length();
	list = new char[length+1];
	unsigned int wordSize = word.size();
	for (unsigned int i = 0; i < wordSize; i++) {
		list[i] = tolower(word[i]);
	}	
	list[wordSize] = '\0';
	nl.append(lineNumber);
}


//copy constructor:
WordData::WordData(const WordData& n)
{
	list = new char;
	*list = *(n.list);
	frequency = n.frequency;
	nl = n.nl;
}


//copy assignment operator:
WordData & WordData ::operator =(const WordData& n)
{
	return *this;
}


//destructor:
WordData::~WordData()
{
	delete[] list;
}


