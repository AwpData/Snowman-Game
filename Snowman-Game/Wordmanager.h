#ifndef Wordmanager_h
#define Wordmanager_h

#pragma once

#include <iostream> 
#include <vector> 
#include "Wordlist.h"

using namespace std;

class WordManager {
private:
	string word;
	int wordLength;
	Wordlist list; // Needs an instance of the word list so that it can choose a random word 
	vector<char> letters; // I used a vector because it is dynamic and doesn't need a constant int value 
	vector<char> guessedLetters;

public:
	WordManager();

	void printCharVector();
	bool checkChar(char userCharacter);
	bool checkWin();
	void printGuessedLetterVector();
	string getWord();

private:
	void makeCharVector();
	void addLettertoGuess(char c);
};

#endif
