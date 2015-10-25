#include "CommandWords.h"

using namespace std;
/**
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.
 * 
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 * @author  Michael Kölling and David J. Barnes
 * @author  Converted form java to C++ by Patrick Sweeney
 * @version October 3, 2015
 */


    // a constant array that holds all valid command words
    string validCommands[] = { "go", "quit", "help", "get"};

    /**
     * Constructor - initialise the command words.
     */
    CommandWords::CommandWords()
    {
        // nothing to do at the moment...
    }

    /**
     * Check whether a given String is a valid command word. 
     * @return true if it is, false if it isn't.
     */
    bool CommandWords::isCommand(string aString)
    {
        for(int i = 0; i < 4; i++) {
            if(validCommands[i] == aString)
                return true;
        }
        // if we get here, the string was not found in the commands
        return false;
    }

    /**
     * Print all valid commands to System.out.
     */
    void CommandWords::showAll() 
    {
        int x = 0;
        while(x < 4)
        {
            cout << validCommands[x];
            cout << "\n";
            x++;
        }
    }

