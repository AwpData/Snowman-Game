#include <iostream> // main, ALL classes 
#include <conio.h> // main
#include <windows.h> // snowman 
#include <cstdlib> // word list 
#include <fstream> // word list 
#include <time.h> // word list
#include <string> // word list 
#include <vector> // words

using namespace std;

class Snowman {
private:
	string head;
	string leftArm;
	string rightArm;
	string body;
	string bottom;

	// For printing the snowman 
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
public:
	Snowman() {
		this->head = "___\n		_|___|_\n	       '=/a a\\='\n		 \\~_ /";
		this->leftArm = "_\\__";
		this->body = "/ '-' \\\n		\\  o  /";
		this->rightArm = "__/_";
		this->bottom = "/ '---' \\\n	      |    o    |\n    -- - .-- - \\   o   / ---- - .-- -\n		'-----'";
	}

	void printSnowman(int lives) { // Prints certain parts of the snowman based on how many guesses the user has next 
		switch (lives) {
		case 5:
			changeCursorPosition(18, 0);
			cout << this->head;
		case 4: // The lower the lives, the less things that print...
			changeCursorPosition(12, 4);
			cout << this->leftArm;
		case 3:
			changeCursorPosition(23, 4);
			cout << this->rightArm;
		case 2:
			changeCursorPosition(16, 4);
			cout << this->body;
		case 1:
			changeCursorPosition(15, 6);
			cout << this->bottom << "\n";
		}
	}
private:
	void changeCursorPosition(int x, int y) { // Changes cursor position in the console so it is easier to draw / maintain where snowman is
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(screen, position);
	}
};

class Wordlist {
private:
	string words[60];
	string nextWord;
	int index = 0;
	unsigned seed = time(0);
public:
	Wordlist() { // Creates the array of words & seeds our RNG 
		ifstream wordList("wordlist.txt");
		while (getline(wordList, nextWord)) {
			words[index] = nextWord;
			index++;
		}
		wordList.close();
		srand(seed);
	}
	string chooseRandomWord() { // Chooses a word from the words array by RNG
		return words[(rand() % 59)];
	}

	string* getWordList() { // DEBUG Method to return the array using pointers
		return words;
	}
	void printWorldList() { // DEBUG Method to print the array list 
		for (int i = 0; i < 60; i++) {
			cout << words[i] << endl;
		}
	}
};

class Word {
private:
	string word;
	int wordLength;
	Wordlist list; // Needs an instance of the word list so that it can choose a random word 
	vector<string> letters; // I used a vector because it is dynamic and doesn't need a constant int value 
public:
	Word() {
		this->word = list.chooseRandomWord();
		this->wordLength = word.length(); // Gets the length of the random word 
		this->letters.resize(wordLength); // Resizes our vector to fit the length of our word 
		makeCharVector(); // Then it makes the underline array that will print in the console 
	}

	//~Word() { cout << "Bye!" << endl; };

	void printCharVector() { // Prints the underline/letter mixed vector to the console 
		for (int i = 0; i < this->letters.size(); i++) {
			cout << this->letters[i] << " ";
		}
		cout << "\n";
	}

	string getWord() { // Accessor to print the word to the screen when user wins/loses 
		return this->word;
	}

private:
	void makeCharVector() { // Just makes the initial underlined string vector that will print on screen to hide the letters 
		for (int i = 0; i < this->letters.size(); i++) {
			this->letters[i] = "_";
		}
	}
};

int main() {
	Snowman man;
	Wordlist words;
	Word word;

	int lives = 5;
	man.printSnowman(lives);

	cout << word.getWord() << endl;
	word.printCharVector();



	//while (lives > 0) {
	//	man.printSnowman(lives);
	//	cout << "Guesses left: " << lives << endl;
	//	lives--;
	//	Sleep(1000);
	//	system("CLS");
	//}
	//cout << "You lost!\n\n\n";

	/*for (int i = 0; i < 10; i++) {
		cout << words.chooseRandomWord() << " ";
	}

	for (int i = 0; i < 60; i++) {
		cout << words.getWordList()[i] << endl;
	}*/
}