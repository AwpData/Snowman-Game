#ifndef Snowman_h
#define Snowman_h

#pragma once

#include <windows.h>
#include <iostream>
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
	Snowman();

	void printSnowman(int lives);
private:
	void changeCursorPosition(int x, int y);
};

#endif
