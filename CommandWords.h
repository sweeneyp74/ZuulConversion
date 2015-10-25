//Author: Patrick Sweeney
//Date: October 11, 2015
#include <iostream>
#include <string>

using namespace std;

#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H
class CommandWords //class name
{
private: //declaring private values
	string stringArray[3];
public:
	CommandWords(); //declaring public functions
	bool isCommand(string aString);
	void showAll();
};
#endif
//extra line