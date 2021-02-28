#include "Snowman.h"

Snowman::Snowman() { // Creates each body part with the ASCII text 
	this->head = "___\n		_|___|_\n	       '=/a a\\='\n		 \\~_ /";
	this->leftArm = "_\\__";
	this->body = "/ '-' \\\n		\\  o  /";
	this->rightArm = "__/_";
	this->bottom = "/ '---' \\\n	      |    o    |\n    -- - .-- - \\   o   / ---- - .-- -\n		'-----'";
}

void Snowman::printSnowman(int lives) { // Prints certain parts of the snowman based on how many guesses the user has next 
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

void Snowman::changeCursorPosition(int x, int y) { // Changes cursor position in the console so it is easier to draw / maintain where snowman is
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(screen, position);
}