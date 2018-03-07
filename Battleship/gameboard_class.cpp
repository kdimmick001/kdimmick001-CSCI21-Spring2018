#include "gameboard_class.h"
#include "rowcol_function.h"

//Constructor.
GameBoard::GameBoard(){
    battle_board_.resize(100, 'o');
    
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

//Get function that will return the outcome of a rowcol argument.
char GameBoard::GetValue(string rowcol){
    
    //To store the function return index value.
    int index;
    
    //Calls the function to convert the rowcol string to a useable vector index.
    index = RowColIndex(rowcol);
    
    
    //From the function index will check if there is a ship at the appropriate index and return the apppropriate answer.
    if (battle_board_.at(index) == 'S'){
        
        //Hit.
        return 'H';
        
    } else {
        
        //Miss.
        return 'M';
    }
     
};
