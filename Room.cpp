#include "Room.h"
using namespace std;
/**
 * Class Room - a room in an adventure game.
 *
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 *
 * A "Room" represents one location in the scenery of the game.  It is 
 * connected to other rooms via exits.  For each existing exit, the room 
 * stores a reference to the neighboring room.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @author converted from java to c++ by Patrick Sweeney
 * @version October 3, 2015
 */


    /**
     * Create a room described "description". Initially, it has
     * no exits. "description" is something like "a kitchen" or
     * "an open court yard".
     * @param description The room's description.
     */
    Room::Room(string description) 
    {
        descriptionRoom = description;
    }

    /**
     * Define an exit from this room.
     * @param direction The direction of the exit.
     * @param neighbor  The room to which the exit leads.
     */
    void Room::setExit(string direction, Room *neighbor) 
    {
        exits[direction] = neighbor;
    }

    /**
     * @return The short description of the room
     * (the one that was defined in the constructor).
     */
    string Room::getShortDescription()
    {
        return descriptionRoom;
    }

    /**
     * Return a description of the room in the form:
     *     You are in the kitchen.
     *     Exits: north west
     * @return A long description of this room
     */
    string Room::getLongDescription()
    {
        return "You are " + descriptionRoom + ".\n" + getExitString();
    }

    /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * @return Details of the room's exits.
     */
    string Room::getExitString()
    {
        string returnString = "Exits:";
        string exitToAdd = "";

        
        for(map<string, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
            exitToAdd = it-> first;
            returnString = returnString + " " + exitToAdd;
        }
        returnString = returnString + "---";
        return returnString;
    }

    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     * @param direction The exit's direction.
     * @return The room in the given direction.
     */
    Room *Room::getExit(string direction) 
    {
        return exits[direction];
    }
/**called by Game to check if a Exit exists or not. Achieves this by comparing
the second word in the user input to all the exit names in a room. This class I added
because otherwise the game would crash when an invalid direciton was used.
*/
    bool Room::checkIfReal(string check) 
    {
        string nextExit = ""; //this will be set to all the exit names in a loop

        //iterates the directions of the currentRoom in game class.
        for(map<string, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
            nextExit = it-> first;
            if(check == nextExit)
            {
                return true; //it means the entered exit it valid.
            }
            
        }
        return false; //if this is reached, then the exit does not exist.
    }

