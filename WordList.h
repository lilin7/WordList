// Student Name: Lin Li
// Student ID: 40044486
#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<sstream>
#include "WordData.h"

class WordList
{
public:
	//default constructor
	WordList();
	WordList(const WordList&);
	~WordList();
	//constructor
	WordList(const char*);
	WordList & operator =(const WordList&);
	
	void parseFile(const char* filename);

	int getSizeOfList() const;
	void printList(ostream&) const;
	
private:
	struct WordNode {
	public:
		WordData wd;
		WordNode *next;

		//constructor 1:
		WordNode(std::string word, int lineNumber);

		//constructor 2:
		WordNode(std::string word, int lineNumber, WordNode *ptr);

	};

	void processGivenWord(const char* givenWord, int lineNumber);

	WordNode *ptrFirstNode;
	WordNode *ptrLastNode;
	WordNode *list;
	int size;
	std::string filename;
};