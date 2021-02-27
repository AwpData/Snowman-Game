#include <iostream> 
#include <conio.h> 
#include <cctype>
#include "Snowman.h"
#include "Wordlist.h"
#include "Wordmanager.h"

using namespace std;

int main() {
	Snowman man;
	Wordlist words;
	WordManager word;

	int lives = 5;
	char input;

	while (lives > 0) {
		system("CLS");
		//cout << word.getWord(); // de-comment if you want to see the word so you can test winning input :)
		man.printSnowman(lives);

		word.printCharVector();
		word.printGuessedLetterVector();

		cout << "\nPlease guess a letter: ";
		cin >> input;
		input = tolower(input);

		if (word.checkChar(input) == false) {
			lives--;
		}
		else {
			if (word.checkWin()) {
				break;
			}
		}
		Sleep(1000); // I briefly pause the program for the user to read my various output 
	}

	system("CLS");

	man.printSnowman(lives);
	word.printCharVector();
	word.printGuessedLetterVector();

	if (lives == 0) {
		cout << "\nYou lost! The snowman has melted!" << endl;
		cout << "\nThe word was: " << word.getWord() << "\n";
	}
	else {
		cout << "\nYou won! The snowman survived!" << endl;
	}
}