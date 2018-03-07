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
    cout << "*********!!PREPARE FOR BATTLE!!**********" << endl;
    cout << "====WELCOME TO THE GAME OF BATTLESHIP====" << endl << endl << endl;
    
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

    //Holds the hit or miss obtained from the GetValue function to then use to call the GetAttack function.
    char ship;
    
    while (player.GetVictory() != 17){
        //Prints the tracker board.
        player.PrintBoard();
    
        //Prompts the user to make a guess
        cout << endl << "What shall your plan of attack be Captain?" << endl << endl ;
        cout << "Enter a Row[letter] and a Column[number] of where you want to strike!" << endl << endl;
        cin >> rowcol;
        cout << endl;
        
        //Checks the validity of the rowcol
        while (RowColIndex(rowcol) == 101){
            cout << endl << "Please enter a valid attack coordinate. ex. [A1]" << endl << endl;
            cin >> rowcol;
            cout << endl;
        }
        
        player.SetAttack(rowcol);
        ship = battleboard.GetValue(rowcol);
        player.GetAttack(ship);
        if (ship == 'M'){
            cout << endl << "You Missed Captain!" << endl << endl;
            
        } else if (ship == 'H'){
            cout << endl << "A Hit Captain!" << endl << endl;
        }
    }

    //Checks if all 17 spots have been hit.
    if (player.GetVictory() == 17){
        player.PrintBoard();
        cout << endl << "You have defeated the enemy!" << endl << endl;
        cout << "YOU WIN CAPTAIN!!!" << endl;
    }  

}