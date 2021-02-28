#ifndef Wordlist_h
#define Wordlist_h

#pragma once
#include <iostream>
#include <cstdlib> 
#include <fstream> 
#include <time.h> 
#include <string> 
using namespace std;

// Wordlist is the class that manages the array list of all words (invoked in Wordmanager class) 
class Wordlist {
private:
	string words[60];
	string nextWord;
	int index = 0;
	unsigned seed = time(0);
public:
	Wordlist();

	string chooseRandomWord();
	string* getWordList();
	void printWorldList();
};
#endif
