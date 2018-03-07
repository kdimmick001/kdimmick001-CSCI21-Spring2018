#include "player_class.h"
#include "rowcol_function.h"
#include "gameboard_class.h"

//Constructor.
Human::Human(){
    
    //Sets a blank tracker board.
    tracker_board_.resize(100, 'o');
    //Sets the attack vector with placeholders for future valid attacks.
    attacks_.resize(100, "Z0");
    //Initializes the counter to 0 to represent the turn number.
    counter_ = 0;
    //Intializes the winning condition variable.
    win_condition_ = 0;
};

//A function to call after checking the validity of the user rowcol guess.
void Human::SetAttack(string rowcol) {
    
    //To check if the guess has already been guessed
    //And if so store it and increase the counter but not call the GetAttack function
    //And instead print the current board.
    for (int i = 0; i <= counter_; ++i){
        
        if (attacks_.at(i) == rowcol){
            
            attacks_.erase(attacks_.begin() + counter_);
            //To differentiate between repeated numbers and not to loop through them more than once.
            //Creates a string stream to store the rowcol repeated and adds the variating counter
            //To then store this into the current guessing position to differentiate between already guessed guesses
            //And not allow an inaccurate counter turn order
            stringstream ssin;
            ssin << rowcol << counter_;
            string repeated_;
            repeated_ = ssin.str();
            
            attacks_.at(counter_) = repeated_;
            
            ++counter_;
            
            //Call the print function to print the current tracker board.
            PrintBoard();
            
            return;
            
        }
    }
    
    //Do need to instead do attacks_.begin() + counter_?
    //Erases the current spot in the turn number and adds the new guess.
    attacks_.erase(attacks_.begin() + counter_);
    attacks_.at(counter_) = rowcol;
    
    //To add the the turn number.
    ++counter_;
    
    return;
};

void Human::GetAttack(char ship){
    //An integer to hold the index returned from the function call.
    int index;
    index = RowColIndex(attacks_.at(counter_));
      
    //To erase the current index value for the new character value
    tracker_board_.erase(tracker_board_.begin() + index);
    tracker_board_.insert(tracker_board_.begin() + index, ship);
  
};

int Human::GetVictory(){
    //Keeps track of how many ships have been hit
    int win_condition_ = 0;
    for (int i = 0; i < tracker_board_.size(); ++i){
        if (tracker_board_.at(i) == 'H'){
            ++win_condition_;
        }
    }
    return win_condition_;
};

void Human::PrintBoard() {
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