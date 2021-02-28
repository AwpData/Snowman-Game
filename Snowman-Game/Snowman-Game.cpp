#include <iostream> 
#include <conio.h> 
#include <cctype>
#include "Snowman.h"
#include "Wordlist.h"
#include "Wordmanager.h"

using namespace std;

Snowman man;
WordManager word;
int lives = 5;
char input;

void printScreen() { // Just prints everything you will see on screen 
	man.printSnowman(lives);
	word.printCharVector();
	word.printGuessedLetterVector();
}

int main() {

	while (lives > 0) {
		system("CLS");
		//cout << word.getWord(); // de-comment if you want to see the word so you can test winning input 
		if (lives == 1) {
			cout << "The snowman is about to melt!" << endl;
		}

		printScreen();

		cout << "\nGuess a letter: ";
		cin >> input; // Gets user character input 
		input = tolower(input); // lowercases input so it can be checked with the words 

		if (word.checkChar(input) == false) { // If the user inputted letter is not in the word, then subtract one from lives 
			lives--;
		}
		else {
			if (word.checkWin()) { // Checks to see if there are any underlines left (if none, then user wins)
				break;
			}
		}
		Sleep(1000); // I briefly pause the program for the user to read my various output 
	}

	system("CLS");

	printScreen();

	if (lives == 0) {
		cout << "\nYou lost! The snowman has melted!" << endl;
		cout << "\nThe word was: " << word.getWord() << "\n";
	}
	else {
		cout << "\nYou won! The snowman survived!" << endl;
	}
}

