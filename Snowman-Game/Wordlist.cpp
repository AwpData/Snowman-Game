#include "Wordlist.h"

Wordlist::Wordlist() { // Creates the array of words & seeds our RNG 
	ifstream wordList("wordlist.txt");
	while (getline(wordList, nextWord)) { // Adds each word in the text file to the array 
		words[index] = nextWord;
		index++;
	}
	wordList.close();
	srand(seed); // seeding RNG 
}

string Wordlist::chooseRandomWord() { // Chooses a word from the words array by RNG
	return words[(rand() % 59)];
}

// DEBUG Functions 

string* Wordlist::getWordList() { // Returns the array using pointers
	return words;
}

void Wordlist::printWorldList() { // Prints the array list with a for loop 
	for (int i = 0; i < 60; i++) {
		cout << words[i] << endl;
	}
}