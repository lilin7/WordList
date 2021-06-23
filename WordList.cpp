// Lin Li
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<sstream>
#include "WordData.h"
#include "WordList.h"
#include "NumList.h"


//constructor 1 for WordNode:
WordList::WordNode::WordNode(std::string word, int lineNumber) : wd(word, lineNumber), next(nullptr) {
}

//constructor 2 for WordNode::
WordList::WordNode::WordNode(std::string word, int lineNumber, WordNode *ptr): wd(word, lineNumber), next(ptr) {
}

//default constructor:
WordList::WordList() : list(nullptr), size(0) {	
}

//load this list using the words in a specified text file:
WordList::WordList(const char* filename)
{
	parseFile(filename);
}
void WordList::parseFile(const char* filename)
{
	this->filename = filename;
	ifstream fin(filename);
	if (!fin) {
		cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	int linenum = 0;
	string line;
	getline(fin, line); //attempt to read a line
	while (fin) {
		++linenum;
		istringstream sin(line); //convert the line just read into an input stream
		string word;
		while (sin >> word) //extract the words
		{
			//take this opportnity to trim word.
			size_t pos;
		
			while ((pos = word.find(",")) != string::npos || (pos = word.find("+")) != string::npos 
				|| (pos = word.find(".")) != string::npos || (pos = word.find(";")) != string::npos
				|| (pos = word.find("!")) != string::npos || (pos = word.find(")")) != string::npos
				|| (pos = word.find("\"")) != string::npos || (pos = word.find("1")) != string::npos)
			{
				  word.replace(pos, 1, "");
			}
			//your use of C++ string class ends here.
			//back to using C-styly strings
			char * charArrayWord = new char[word.length() + 1];
			strcpy_s(charArrayWord, (word.length() + 1), word.c_str() );
			//std::strcpy(charArrayWord, word.c_str());
			//process charArrayWord and linenum
			//insert method takes a wordnode in parameter, iterate over the list to find the spot to go, then change pointers
			//or if it is already there, increase frequency and line number
			processGivenWord(charArrayWord, linenum);
			delete[] charArrayWord; //clean up
		}
		getline(fin, line);
	}
	fin.close();
}

/*accept both a given word and a line number and then reflect them both into this list as follows:
if the given word is already represented by a wordnode in the list, then simply append the given number to the list of
line numbers of the worddata in the wordnode.
otherwise, creat and insert a new wordnode object to the list at its sorted position.*/
void WordList::processGivenWord(const char* givenWord, int lineNumber) {
	//create new WordData:
	WordData newData(std::string(givenWord), lineNumber);
	//loop from the first existing node (if any), compare the given word with the word stored in every existing node:
	for (WordNode *prev = nullptr,*cur = ptrFirstNode; cur != nullptr; prev = cur, cur = cur->next)
	{
		const int compareResult = newData.compareWord(cur->wd.getPointerToStoredWord());
		//if the given word has already existed in the word list, increase the frequency, and append the line number
		//to the existing list of numberList:
		if (compareResult == 0) {
			cur->wd.incrementFrequency();
			cur->wd.nl.append(lineNumber);
			return;
		}
		//if the given word should be put earlier alphabetically than the existing node:
		else if (compareResult < 0) {
			//make the pointer to the existing node to point to the new given word			
			WordNode *newWn = new WordNode(std::string(givenWord), lineNumber, cur);
			//if the previous pointer not equals to null pointer, means the previous WordNode is not the first Node
			//so make the previsou Node to point to the new given word
			if (prev != nullptr) {
				prev->next = newWn;
			}
			//if the previous WordNode is the first Node, make the pointer to the first node point to the given word:
			else {
				ptrFirstNode = newWn;
			}
			//if the given word alphabetically later than all the existing nodes, return and go to next step:
			return;
		}
	}
	// next step: if the given word alphabetically later than all the existing nodes, insert at the end:
	WordNode *newWn = new WordNode(std::string(givenWord), lineNumber);
	if (ptrLastNode != nullptr) {
		ptrLastNode->next = newWn;
	}
	ptrLastNode = newWn;
	if (ptrFirstNode == nullptr) {
		ptrFirstNode = newWn;
	}

}

//get the size of the list:
int WordList::getSizeOfList() const {
	return size;
}

//print the list formatted as shown on page 4:
void WordList::printList(ostream& out) const {
	out << "WordList Source File: " << filename << endl;
	out << "==========================================" << endl;
	//use for loop to print the format:
	for (char m = 'a', n = 'A'; m <= 'z', n <= 'Z'; m++, n++) {
		//print 26 letter in capital at the left of screen:
		out << "<" << n << ">" << endl;
		//loop each word, print a to z under the corresponding 26 capital letters
		for (WordNode *cur = ptrFirstNode; cur != nullptr; cur = cur->next) {
			char c = cur->wd.getPointerToStoredWord()[0];
			if (c == m) {
				//call print() method in WordNode class to print a line for each word:
				cur->wd.print(); 
			}
		}
	}
	out << "==========================================" << endl;
}

//copy constructor:
WordList::WordList(const WordList& n)
{
	*ptrFirstNode = *(n.ptrFirstNode);
	*ptrLastNode = *(n.ptrLastNode);
	*list = *(n.list);
	size = n.size;
	filename = n.filename;
}

//copy assignment operator:
WordList & WordList ::operator =(const WordList& n)
{
	return *this;
}

//destructor:
WordList::~WordList() {
}
