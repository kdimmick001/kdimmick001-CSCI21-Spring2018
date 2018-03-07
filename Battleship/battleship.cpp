#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "gameboard_class.h"
#include "player_class.h"
#include "rowcol_function.h"
using namespace std;

int main() {
    //An introduction to the game program.
    cout << "*********!!PREPARE FOR BATTLE!!*********" << endl;
    cout << "WELCOME TO THE GAME OF BATTLESHIP" << endl;
    
    //Declaring a string to hold the file name.
    string file = "file file";
    
    //Creating a board object from the Game Board class.
    GameBoard board;
    
    //Prompting the user to enter a file name for the game board.
    cout << "Please enter a competitor board file." << endl;
    cin >> file;
    cout << endl;
    
    //If the file string has any while spaces keep asking to enter a valid one.
    for (int i = 0; i < file.length(); ++i) {
        if ((file[i] == ' ') || (file[i] == '\n')){
            cout << "Please enter a valid file name to upload a game board" << endl;
            cin >> file;
        }
    }
    
    //Create a object battleboard from the GameBoard class.
    GameBoard battleboard;
    
    //Call the SetBoard function with the valid file name to create the game board.
    battleboard.SetBoard(file);
    
    //Create a object player from the Human class.
    Human player;
    
    //A string to hold the user's row and column attack.
    string rowcol;

    while (player.GetVictory() != 17){
        //Prints the tracker board.
        player.PrintBoard();
    
        //Prompts the user to make a guess
        cout << "What shall your plan of attack be Captain?" << endl;
        cout << "Enter a Row[letter] and a Column[number] of where you want to strike!" << endl;
        cin >> rowcol;
    
        //Checks the validity of the rowcol
        if (RowColIndex(rowcol) == 101){
            cout << "Please enter a valid attack coordinate. ex. [A1]" << endl;
            cin >> rowcol;
        }
        player.SetAttack(rowcol);
        //player.GetAttack();
    }

    //Checks if all 17 spots have been hit.
    if (player.GetVictory() == 17){
        player.PrintBoard();
        cout << "You have defeated the enemy!" << endl;
        cout << "YOU WIN CAPTAIN!!!" << endl;
    }  

}