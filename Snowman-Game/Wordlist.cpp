#include "Wordlist.h"

Wordlist::Wordlist() { // Creates the array of words & seeds our RNG 
	ifstream wordList("wordlist.txt");
	while (getline(wordList, nextWord)) {
		words[index] = nextWord;
		index++;
	}
	wordList.close();
	srand(seed);
}

string Wordlist::chooseRandomWord() { // Chooses a word from the words array by RNG
	return words[(rand() % 59)];
}

string* Wordlist::getWordList() { // DEBUG Method to return the array using pointers
	return words;
}

void Wordlist::printWorldList() { // DEBUG Method to print the array list 
	for (int i = 0; i < 60; i++) {
		cout << words[i] << endl;
	}
}