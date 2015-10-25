#include "Parser.h"

using namespace std;
/**
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 * 
 * This parser reads user input and tries to interpret it as an "Adventure"
 * command. Every time it is called it reads a line from the terminal and
 * tries to interpret the line as a two word command. It returns the command
 * as an object of class Command.
 *
 * The parser has a set of known command words. It checks user input against
 * the known commands, and if the input is not one of the known commands, it
 * returns a command object that is marked as an unknown command.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @author  java to c++ by Patrick Sweeney
 * @version October 3, 2015
 */


    //CommandWords commandWordsObject;  // holds all valid command words
    //no need for scanner because cin does a better job. YAY C++!!!!
    /**
     * Create a parser to read from the terminal window.
     */
    Parser::Parser() 
    {
            //nothing needed. Object created as private variable.
    }

    /**
     * @return The next command from the user.
     */
    Command Parser::getCommand() 
    {
        string inputLine = "";   // will hold the full input line
        string word1 = ""; //apparently "" means a empty string!!!!
        string word2 = "";

        getline(cin, inputLine);
        istringstream iss(inputLine);
        
        int index = 0;
        do //a loop that makes sure at least one loop occurs.
        {
            string sub; //this will be set to the next word in getLine
            iss >> sub;
            if(index == 0) //first word
            {
                word1 = sub;
            }
            if(index == 1) //second word
            {
                word2 = sub;
            }
            index++;
        }while(iss); //continues while there is a next word!


       
        if(commandWordsObject.isCommand(word1) == true) {
            return Command(word1, word2);
        }
        else {
            return Command("", word2); 
        }
    }

    /**
     * Print out a list of valid command words.
     */
    void Parser::showCommands()
    {
        commandWordsObject.showAll();
    }

