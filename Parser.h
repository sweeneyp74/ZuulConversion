//Author: Patrick Sweeney
//Date: October 11, 2015
#include <iostream>
#include <string>
#include <sstream>
#include "Command.h"
#include "CommandWords.h"
using namespace std;

#ifndef PARSER_H
#define PARSER_H
class Parser
{
private:
	CommandWords commandWordsObject;
public:
	Parser();
	Command getCommand();
	void showCommands();
};
#endif
//extra line