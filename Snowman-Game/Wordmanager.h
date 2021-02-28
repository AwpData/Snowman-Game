#ifndef Wordmanager_h
#define Wordmanager_h

#pragma once

#include <iostream> 
#include <vector> 
#include "Wordlist.h"

using namespace std;

// WordManager maintains the other vectors including the guessed letters / correct and underline mixed letters

class WordManager {
private:
	string word; // This word will be the random word chosen from the wordlist array 
	int wordLength; // length of the variable word 

	Wordlist list; // Needs an instance of the word list so that it can choose a random word for the word variable 
	vector<char> letters; // Stores the underlines / correct letters the user entered 
	vector<char> guessedLetters; // Stores the user guessed letters 

public:
	WordManager();

	bool checkChar(char userCharacter);
	bool checkWin();

	void printCharVector();
	void printGuessedLetterVector();
	string getWord();

private:
	void makeCharVector();
	void addLettertoGuess(char c);
};

#endif
