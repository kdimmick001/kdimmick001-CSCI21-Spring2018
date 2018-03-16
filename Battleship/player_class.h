#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

#include "rowcol_function.h"
#include "gameboard_class.h"

#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

//The pure virtual base class of Player to set a foundation of functions to use with Human players and Computer players
class Player {
    public:
        virtual int SetAttack(string rowcol){}
        virtual void PushBoard(string file){}
};

//A class that inherits from the Player virtual class to create a class of human players.
class Human : public Player {
    private:
        //Holds an attack record.
        vector<string> attacks_;
        //A counter to track how many turns a player has had.
        int counter_;
        //An gameboard object for the Human Player
        GameBoard human_player_;
        
    public:
        //Constructor to set the tracker board and attacks vector.
        Human();
        //The other functions are declared in the base class of Player as virtual functions.
        //A PushBoard function that will push the file name to the GameBoard class through the created human_player_ object.
        //This will create the competitor's board to compare to the player's tracker_board_ in the GameBoard class.
        void PushBoard(string file);
        //Sets the user guessed attack and stores it into a vector for reference as well as to check with the GameBoard class.
        int SetAttack(string rowcol);
        

};

//A class that inherits from the Player virtual class to create a class of computer players.
class Computer : public Player {
    private:
        //A queue to hold the guesses to pass.
        queue<string> hit_guesses_;        
        //Holds an attack record.
        vector<string> attacks_;
        //A counter to track how many turns a player has had.
        int counter_;
        //An gameboard object for the Human Player
        GameBoard computer_player_;
        
    public:
        Computer();
        //A PushBoard function that will push the file name to the GameBoard class through the created computer_player_ object.
        //This will create the competitor's board to compare to the player's tracker_board_ in the GameBoard class.
        void PushBoard(string file);
        //A function that creates a random coordinate guess.
        int GetAttack();
        //Sets the guesses for the computer from the PlanAttack function randomizer and returns the win condition check.
        void SetAttack(string rowcol);
};

#endif