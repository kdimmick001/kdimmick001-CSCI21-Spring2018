#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

//The pure virtual base class of Player to set a foundation of functions to use with Human players and Computer players
class Player {
    public:
        virtual void SetAttack(string rowcol);
        virtual char GetAttack();
        virtual void PrintBoard();
        virtual int GetVictory();
        
};

//A class that inherits from the Player virtual class to create a class of human players.
class Human : public Player {
    private:
        //Holds an attack record.
        vector<string> attacks_;
        //Holds the current tracker board.
        vector<char> tracker_board_;
        //A counter to track how many turns a player has had.
        int counter_;
        //Keeps track of how many ships have been hit
        int win_condition_;
        
    public:
        //Constructor to set the tracker board and attacks vector.
        Human();
        //The other functions are declared in the base class of Player as virtual functions.
};

//A class that inherits from the Player virtual class to create a class of computer players.
class Computer : public Player {
    
};
