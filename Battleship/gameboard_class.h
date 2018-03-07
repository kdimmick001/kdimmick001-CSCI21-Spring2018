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
    
    public:
        //Constructor with no parameters to initialize the battle_board_ vector to all 'o's.
        GameBoard();
        
        //A Set function that will get a valid file name and will populate the battle_board_vector appropriately.
        void SetBoard(string file);
        
        //A Get function that has a parameter of rowcol that will check the row and column of the battle_board.
        //This will return whether the rowcol was a hit 'H' or miss 'M'.
        char GetValue(string rowcol);
        
};

#endif