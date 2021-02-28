#ifndef Snowman_h
#define Snowman_h

#pragma once

#include <windows.h>
#include <iostream>
using namespace std;

// Snowman class maintains the snowman that is printed on screen and changes it depending on the number of lives remaining 
class Snowman {
private:
	string head;
	string leftArm;
	string rightArm;
	string body;
	string bottom;

	// For printing the snowman (needed to adjust where the cursor is on screen) 
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
public:
	Snowman();

	void printSnowman(int lives);

private:
	void changeCursorPosition(int x, int y);
};

#endif
