#include "Command.h"

using namespace std;
/**
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 *
 * This class holds information about a command that was issued by the user.
 * A command currently consists of two strings: a command word and a second
 * word (for example, if the command was "take map", then the two strings
 * obviously are "take" and "map").
 * 
 * The way this is used is: Commands are already checked for being valid
 * command words. If the user entered an invalid command (a word that is not
 * known) then the command word is <null>.
 *
 * If the command had only one word, then the second word is <null>.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @author  Converted to C++ by Patrick Sweeney
 * @version October 2, 2015
 */
    /**
     * Create a command object. First and second word must be supplied, but
     * either one (or both) can be null.
     * @param firstWord The first word of the command. Null if the command
     *                  was not recognised.
     * @param secondWord The second word of the command.
     */
    Command::Command(string firstWord, string secondWord)
    {
        commandWord = firstWord;
        nextWord = secondWord;
    }

    /**
     * Return the command word (the first word) of this command. If the
     * command was not understood, the result is null.
     * @return The command word.
     */
    string Command::getCommandWord()
    {
        return commandWord;
    }

    /**
     * @return The second word of this command. Returns null if there was no
     * second word.
     */
    string Command::getSecondWord()
    {
        return nextWord;
    }

    /**
     * @return true if this command was not understood.
     */
    bool Command::isUnknown()
    {
        return (commandWord.empty());
    }

    /**
     * @return true if the command has a second word.
     */
    bool Command::hasSecondWord()
    {
        if(nextWord.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }


