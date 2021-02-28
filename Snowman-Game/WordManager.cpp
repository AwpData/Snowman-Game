#include "Wordmanager.h"

WordManager::WordManager() {
	this->word = list.chooseRandomWord();
	this->wordLength = word.length(); // Gets the length of the random word 
	this->letters.resize(wordLength); // Resizes our vector to fit the length of our word 
	makeCharVector(); // Then it makes the underline array that will print in the console 
}

void WordManager::makeCharVector() { // Just makes the initial underlined string vector that will print on screen to hide the letters 
	for (int i = 0; i < this->letters.size(); i++) {
		this->letters[i] = '_';
	} // This is the base vector that will hold all of my correct letters as it fills in 
}

bool WordManager::checkChar(char userCharacter) { // Checks the character the user inputted and whether it is valid or not 
	for (int i = 0; i < this->guessedLetters.size(); i++) { // Makes sure the user hasn't already guessed the letter!
		if (userCharacter == guessedLetters[i]) {
			cout << "Error: you have already entered this letter!" << endl;
			return true; // returns early if the user entered an already guessed letter 
		}
	}

	addLettertoGuess(userCharacter); // Adds the guessed letter to our guessed letter array 
	bool validLetter = false; // This is to check if the letter is actually in the hidden word 
	vector<char> theActualWord(word.begin(), word.end()); // creates a vector of the actual word for comparison 
	for (int i = 0; i < this->letters.size(); i++) {
		if (userCharacter == theActualWord[i]) { // If user character is the same as the letter at some index...
			this->letters[i] = userCharacter; // change the underline to the user character
			validLetter = true;
		}
	}
	// These print depending on the validLetter boolean for user-friendliness 
	if (validLetter == true) {
		cout << "Good answer!" << endl;
		return true;
	}
	else {
		cout << "Bad answer!" << endl;
		return false;
	}
}

bool WordManager::checkWin() { // Checks to see if the user won by seeing if there are anymore underlines in the letters vector 
	for (int i = 0; i < this->letters.size(); i++) {
		if (this->letters[i] == '_') {
			return false; // Not a winner yet, there is still an underline 
		}
	}
	return true; // WINNER!
}

void WordManager::addLettertoGuess(char c) { // Adds the user character to our guessed letters vector 
	for (int i = 0; i < this->guessedLetters.size(); i++) {
		if (c == guessedLetters[i]) {
			return; // This makes sure that I am not adding a letter already in the vector 
		}
	}
	this->guessedLetters.push_back(c); // Else, push the character to the end of the vector 
}

void WordManager::printGuessedLetterVector() { // Prints what characters the user entered to the screen 
	cout << "Guessed Letters: ";
	for (int i = 0; i < this->guessedLetters.size(); i++) {
		cout << guessedLetters[i] << " ";
	}
	cout << "\n";
}

void WordManager::printCharVector() { // Prints the underline/letter mixed vector to the console 
	for (int i = 0; i < this->letters.size(); i++) {
		cout << this->letters[i] << " ";
	}
	cout << "\n\n";
}

string WordManager::getWord() { // Accessor to print the word to the screen when user wins/loses 
	return this->word;
}


