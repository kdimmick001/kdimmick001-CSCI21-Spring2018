#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef GAMEBOARD_CLASS_H
#define GAMEBOARD_CLASS_H

//A class GameBoard to make multiple GameBoard objects.
//10 x 10 board of 'o's and 'S's.
//Stores and accesses boards for multiple players.
class GameBoard {
    private:
        //A vector of characters to hold the game board.
        vector<char> battle_board_;
        //Holds the current tracker board.
        vector<char> tracker_board_;
    
    public:
        //Constructor with no parameters to initialize the battle_board_ and tracker_board_ vector to all 'o's.
        GameBoard();
        
        //A Set function that will get a valid file name and will populate the battle_board_vector appropriately.
        void SetBoard(string file);
        
        //A function that has a parameter of rowcol that will check the row and column of the battle_board.
        //This will change the tracker_board_ whether the rowcol was a hit 'H' or miss 'M' and invoke the PrintBoard() function.
        char ChangeValue(string rowcol);
        
        //This will print out the tracker_board_.
        void PrintTracker();
        
        //This will print out the human player's board with the updated computer guesses.
        void PrintBoard();
        
        //To check for victory.
        int GetVictory();
        
        
};

#endif