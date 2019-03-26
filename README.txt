// Assignment 1
// Student Name: Lin Li
// Student ID: 40044486


This program uses 3 classes (each has a .h file and a .cpp file) and a driver.cpp file to process a txt file.

WordList class:
It extracts each word from the txt file, puts each word into the WordData of a WordNode and organizing the nodes
in alphabetical order, and connects each WordNode.

WordNode class:
It is a nested class in WordList class. Each WordNode stores a WordData in alphabetical order, and a pointer to 
the next WordNode.

WordData class:
It is a part of a WordNode. It stores a word and its frequency (how many times this word appears in the txt file),
and a NumList class which contains in which line this word appears.

NumList class:
It stores in which line of the txt file a word appears in a dynamically allocated array of integer elements.
Its size and capacity change when reading the txt file.

wordListDriver class:
It reads input txt file, processes, and prints output.