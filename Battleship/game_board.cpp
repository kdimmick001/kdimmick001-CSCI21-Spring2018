#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

//A function to open the file and store the input to access as the game board.
vector <char> FileInput(string file, vector <vector<char>> &board_){
    
    //Creating an input stream
    ifstream fin;

    //To open a text file to get the string information.
    fin.open(file);
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    
    //While not end of the file.
    while (!fin.eof()){
        //Have a loop to fill the 10 spaces of the board in both the columns and rows.
        for (int i = 0, i< 10, ++i) {
            for (int j = 0, j < 10, ++j){
                fin >> board_[i][j];
            }
        }    
    }
    
    //Closing the file when done getting all the information.
    fin.close();
    
    return board_;
};

//A class to create and hold and access the board for the battleship game.
class GameBoard{
    private:
        //Variable to hold a valid user file name.
        string file_;
        //Initializing a vector of vectors with 10 rows and columns filled with 'o's.
        vector <vector<char>> board_(10, vector<char> (10, 'o'));
    public:
        //Constructor
        GameBoard();
        //To set the file name to create the game board.
        void SetFile(string file);
        //To set the board that will call the file function to fill up the game board.
        void SetBoard();
        //A function to check the board to see if the there is a ship on the board
        string CheckBoard();
};

void GameBoard::SetFile(string file){
    file_ = file;
    
    SetBoard();
    return;
};

void GameBoard::SetBoard(){
    
    FileInput(file_, board_);
    return;
};

int main() {
    
    //An introduction to the game program.
    cout << "*********!!PREPARE FOR BATTLE!!*********" << endl;
    cout << "WELCOME TO THE GAME OF BATTLESHIP" << endl;
    
    
    //Declaring a string to hold the file name.
    string file = "file file";
    
    //Creating a board object from the Game Board class.
    GameBoard board;
    
    //If the file string has any while spaces keep asking to enter a valid one.
    for (int i = 0, i < file.size(), ++i) {
        if ((file(i) == " ") || (file(i) == '\n')){
            cout << "Please enter a valid file name to upload a game board" << endl;
            cin >> file;
        }
    
    //Calling the set function in the class to start a file input to create the board.
    board.SetFile(file);
    
    
}