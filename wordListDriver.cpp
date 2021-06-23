// Lin Li

#include <iostream>
using namespace std;
#include <sstream>
#include "NumList.h"
#include "WordData.h"
#include "WordList.h"


int main()
{
	WordList wl("input.txt");	//build a word list from an input file,
	wl.printList(cout);			//write the entire word list to standard output,
	system("pause");
	return 0;					//report success
}

