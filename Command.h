//Author: Patrick Sweeney
//Date: October 11, 2015
#include <iostream>
#include <string>
using namespace std;

#ifndef COMMAND_H
#define COMMAND_H
class Command
{
private:
		string commandWord;
		string nextWord;
public:
	Command(string firstWord, string secondWord);
	string getCommandWord();
	string getSecondWord();
	bool isUnknown();
	bool hasSecondWord();
};
#endif
//extra line