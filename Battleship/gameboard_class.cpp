#include "gameboard_class.h"
#include "rowcol_function.h"

//Constructor.
GameBoard::GameBoard(){
    //Sets a blank battle_board_ vector of 'o' characters.
    battle_board_.resize(100, 'o');
    //Sets a blank tracker_board_ vector of 'o' charcters.
    tracker_board_.resize(100, 'o');
    
};

//Set function to use a file to alter the battle_board_ vector.
void GameBoard::SetBoard(string file){
    
    //Creating an input stream
    ifstream fin;

    //To open a text file to get the string information.
    fin.open(file.c_str());
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    //A counter to keep track of the number of loops till the end of the file.
    int counter = 0;
    
    //A variable to hold a dummy character to check if there is a ship present to then fill the battle_board_ vector with
    //At the appropriate and associated counter index.
    char location = 'o';
    
    //Have a loop to fill the battle_board_ with the appropriate spots where the ships are located.
    //While not end of the file.
    while (!fin.eof()){
        
        fin >> location;
        
        //If the location variable contains an 'S' from the file input.
        if (location == 'S'){
            
            //Erase the contents of the array at that counter location
            //Need to include an iterator to be able to manipulate the vector using the erase function and insert function.
            battle_board_.erase(battle_board_.begin() + counter);
            
            //Inserts the location value 'S' at that just erased index.
            battle_board_.insert(battle_board_.begin() + counter, location);
            
            //To increment the counter to move along the file input association index.
            ++counter;
            
        } else if ((location != '\n') || (location != ' ')){
            
        //only if no spaces will the counter track to be able to be used properly to access the associated vector spot.
        ++counter;
        
        }
        
    }
    
    //Closing the file when done getting all the information.
    fin.close();
    
};
//A function that changes the tracker_board_ whether the rowcol was a hit 'H' or miss 'M' and invoke the PrintBoard() function.
char GameBoard::ChangeValue(string rowcol){
    
    //To store the function return index value.
    int index;
    
    //Calls the function to convert the rowcol string to a useable vector index.
    index = RowColIndex(rowcol);
    
    
    //From the function index will check if there is a ship at the appropriate index and return the apppropriate answer.
    if (battle_board_.at(index) == 'S'){
        
        //Hit.
        tracker_board_.erase(tracker_board_.begin() + index);
        tracker_board_.insert(tracker_board_.begin() + index, 'H');
    
        return 'H';
        
    } else {
        
        //Miss.
        tracker_board_.erase(tracker_board_.begin() + index);
        tracker_board_.insert(tracker_board_.begin() + index, 'M');
        
        return 'M';
    }
     
};

//Checks the tracker_board_ vector for winning condition.
int GameBoard::GetVictory(){
    //Keeps track of how many ships have been hit
    int win_condition_ = 0;
    for (int i = 0; i < tracker_board_.size(); ++i){
        if (tracker_board_.at(i) == 'H'){
            ++win_condition_;
        }
    }
    return win_condition_;
};

//Prints the tracker_board_ vector.
void GameBoard::PrintTracker() {
    //An initializer to loop through and print out the column numbers.
    int col = 0;
    //Outputs a space allowance for the lettered row output
    cout << "  ";
    while (col < 10){
        cout << col << " ";
        ++col;
    }
    cout << endl;
    //Using ASCII numbers to store the appropriate row letter and allows incrementation.
    char row = 65;
    int counter = 1;
    
    while (row < 75) {
        cout << row << " ";
        for (int i = ((counter - 1) * 10); i < (10 * counter); ++i){
            cout << tracker_board_.at(i) << " ";
        }
        cout << endl;
        ++row;
        ++counter;
    }
    return;
};

//Prints the human player's board file with the updates from the computer's guesses.
void GameBoard::PrintBoard(){
    //An initializer to loop through and print out the column numbers.
    int col = 0;
    //Outputs a space allowance for the lettered row output
    cout << "  ";
    while (col < 10){
        cout << col << " ";
        ++col;
    }
    cout << endl;
    //Using ASCII numbers to store the appropriate row letter and allows incrementation.
    char row = 65;
    int counter = 1;
    
    //To update the human battle board.
    for (int i = 0; i < tracker_board_.size(); ++i){
        if ((tracker_board_.at(i) == 'H') || (tracker_board_.at(i) == 'M')){
            battle_board_.erase(battle_board_.begin() + i);
            battle_board_.insert(battle_board_.begin() + i, (tracker_board_.at(i)));
        }
    }
    
    while (row < 75) {
        cout << row << " ";
        for (int i = ((counter - 1) * 10); i < (10 * counter); ++i){
            cout << battle_board_.at(i) << " ";
        }
        cout << endl;
        ++row;
        ++counter;
    }
    return;
};
