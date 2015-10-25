#include "Game.h"
/**
 *  This class is the main class of the "World of Zuul" application. 
 *  "World of Zuul" is a very simple, text based adventure game.  Users 
 *  can walk around some scenery. That's all. It should really be extended 
 *  to make it more interesting!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @author Converted from Java to C++ by Patrick Sweeney
 * @version October 11, 2015
 */
       
    /**
     * Create the game and initialise its internal map.
     */
    Game::Game() 
    {
        createRooms();
        //parser = new Parser();
        Parser parser;
    }

    /**
     * Create all the rooms and link their exits together.
     */
    void Game::createRooms()
    {
        //Room outside, theater, pub, lab, office;
      
        // create the rooms
        Room* outside = new Room("outside the main entrance of the university");
        Room* theater = new Room("in a lecture theater");
        Room* pub = new Room("in the campus pub");
        Room* lab = new Room("in a computing lab");
        Room* office = new Room("in the computing admin office");


        // initialise room exits
        outside->setExit("east", theater);
        outside->setExit("south", lab);
        outside->setExit("west", pub);

        theater->setExit("west", outside);

        pub->setExit("east", outside);

        lab->setExit("north", outside);
        lab->setExit("east", office);

        office->setExit("west", lab);

        currentRoom = outside;  // start game outside
    }

    /**
     *  Main play routine.  Loops until end of play.
     */
    void Game::play() 
    {            
        printWelcome(); //prints the Starting info

        keyStatus = false; //at this time you do not have the key!

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
                
        bool finished = false;
        while (! finished) {
            Command command = parser.getCommand();
            finished = processCommand(command);

            if(currentRoom->getShortDescription() == "in the computing admin office")//tests if win condition is being met!
            {
                cout << "You have unlocked the Door and Entered the office. You Win!" << "\n";
                finished = true; //break the game loop
            }

        }
        cout << "Thank you for playing.  Good bye.";
    }

    /**
     * Print out the opening message for the player.
     */
    void Game::printWelcome()
    {
        cout << "\n";
        cout << "Welcome to the World of Zuul!";
        cout << "The Goal of the game is to find a key and unlock the office." << "\n";
        cout << "If you get the key you can enter the office and you win the game!!!" << "\n";
        cout << "Type get to search for and pick up the key";
        cout << "Type 'help' if you need help.";
        cout << "\n";
        cout << currentRoom->getLongDescription();
        cout << "\n";
    }

    /**
     * Given a command, process (that is: execute) the command.
     * @param command The command to be processed.
     * @return true If the command ends the game, false otherwise.
     */
    bool Game::processCommand(Command command) 
    {
        bool wantToQuit = false;

        if(command.isUnknown())//checks if the command is listed
        {
            cout << "I don't know what you mean..." << "\n";
            return false;
        }

        string commandWord = command.getCommandWord();
        if (commandWord == "help") //prints help
        {
            printHelp();
        }
        else if (commandWord == "go") //go to room
        {
            goRoom(command);
        }
        else if (commandWord == "quit") //quits game
        {
            wantToQuit = quit(command);
        }
        else if(commandWord == "get") //used to pick up key
        {   //if you are in the theater and the key is not picked up you can pick it up
            if((keyStatus == false) && (currentRoom->getShortDescription() == "in a lecture theater"))
            {
                keyStatus = true; //you now have the key
                cout << "You find a key and pick it up" << "\n";
            }
            else //you already picked up the key or are in the wrong room to pick it up
            {
                cout << "There is nothing to pick up!" << "\n";
            }
        }
        // else command not recognised.
        return wantToQuit;
    }

    // implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
    void Game::printHelp() 
    {
        cout << "You are lost. You are alone. You wander";
        cout << "around at the university.";
        cout << "\n";
        cout << "Your command words are:";
        parser.showCommands();
        cout << "\n";
    }

    /** 
     * Try to in to one direction. If there is an exit, enter the new
     * room, otherwise print an error message.
     */
    void Game::goRoom(Command command) 
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            cout << "Go where?" << "\n";
            return;
        }

        string direction = command.getSecondWord();

        // Try to leave current room.
        //set current room to entered room
        //check if you have key so you can enter the office
        //if you are in office the game will end!
        if (currentRoom->checkIfReal(direction) == false)
        {//this executes if the enter direction exists
            cout << "There is no door!" << "\n";
        }
        else if(currentRoom->getShortDescription() == "in a computing lab" 
            && keyStatus == false && direction == "east")
        {//this executes if you try to enter the office without the key
         //will not let you in the office without the keyStatus == True
            cout << "The Door is Locked. Look for a key in the other Rooms!";
        }
        else 
        {//updates the currentRoom if its a valid move
            Room* nextRoom = currentRoom->getExit(direction);
            currentRoom = nextRoom;
            cout << currentRoom->getLongDescription();
        }
    }

    /** 
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game.
     * @return true, if this command quits the game, false otherwise.
     */
    bool Game::quit(Command command) 
    {
        if(command.hasSecondWord()) {
            cout << "Quit what?" << "\n";
            return false;
        }
        else {
            return true;  // signal that we want to quit
        }
    }

