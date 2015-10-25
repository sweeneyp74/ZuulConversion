//Author: Patrick Sweeney
//Date: October 11, 2015
#include <iostream>
#include <string>
#include "CommandWords.h"
#include "Command.h"
#include "Room.h"
#include "Parser.h"
using namespace std;

#ifndef GAME_H
#define GAME_H
class Game
{
private:
	bool keyStatus; //this indicates whether you have a key or not
	Parser parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
	bool quit(Command command);
public:
	Game();
	void play();
};
#endif
//extra line