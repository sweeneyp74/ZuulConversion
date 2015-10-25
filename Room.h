//Author: Patrick Sweeney
//Date: October 11, 2015
#include <iostream>
#include <string>
#include <map>
using namespace std;

#ifndef ROOM_H
#define ROOM_H
class Room
{
private:
	string descriptionRoom; //string that descibes the room...
	map<string, Room*> exits; //stores exits of this room
	string getExitString();
	
public:
	Room(string description);
	void setExit(string description, Room *neighbor);
	string getShortDescription();
	string getLongDescription();
	Room* getExit(string direction);
	bool checkIfReal(string check);
};
#endif
//extra line