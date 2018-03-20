#include "player_class.h"

//Constructor.
Human::Human(){
    
    //Sets the attack vector with placeholders for future valid attacks.
    attacks_.resize(100, "Z0");
    //Initializes the counter to 0 to represent the turn number.
    counter_ = 0;

};

//A function that takes the file name input and passes it to the GameBoard class.
//This will fill the competitor's board to then be able to compare to the tracker_board_ for accuracy in guesses.
void Human::PushBoard(string file){
    
    //Calls the GameBoard function SetBoard to populate the opponunt's board.
    human_player_.SetBoard(file);
    
    return;
};

//A set function to populate a vector of user guesses and pass the current guess to the GameBoard class.
int Human::SetAttack(string rowcol){
    
    //Erases the current spot in the turn number and adds the new guess.
    attacks_.erase(attacks_.begin() + counter_);
    attacks_.at(counter_) = rowcol;
    
    //To add the the turn number.
    ++counter_;
    
    //Holds the return value for the ChangeValue function.
    char hit_miss_;
    
    //Calls the GameBoard class function ChangeValue to check the opponent board and update the tracker_board_ as needed.
    hit_miss_ = human_player_.ChangeValue(rowcol);
    
    //Prints the human_player_ tracker_board_.
    //human_player_.PrintBoard();
    
    //A call to the win condition check that returns the win condition.
    return (human_player_.GetVictory());
};

void Human::PrintBoard(){
    //To print the player tracker_board_.
    human_player_.PrintTracker();
    
    return;
}

//Constructor.
Computer::Computer(){
    //Sets the attack vector with placeholders for future valid attacks.
    attacks_.resize(100, "Z0");
    //Initializes the counter to 0 to represent the turn number.
    counter_ = 0;
    //Intializes the seed.
    //Still doesn't fix makes more frequent.
    //srand(time(NULL));
};

//A function that takes the file name input and passes it to the GameBoard class.
//This will fill the competitor's board to then be able to compare to the tracker_board_ for accuracy in guesses.
void Computer::PushBoard(string file){
    
    //Calls the GameBoard function SetBoard to populate the opponunt's board.
    computer_player_.SetBoard(file);
    
    return;
};

//A get function to generate a random guess for the computer player.
//As well as pass it to the Set Attack function to check the guess.
int Computer::GetAttack(){
    
    cout << "Got into the Get Attack function." << endl;
    
    //Dummy variable to hold any popped items from the queue.
    string pop_junk_;
    
    cout << "Declared the string variable pop_junk_" << endl;
    
    //If the queue has contents.
    if (hit_guesses_.size() != 0){
        //Checks if the next in line for the queue has already been guessed.
        //And if so to remove and check the next.
        for (int i = 0; i < attacks_.size(); ++i){
            if (attacks_.at(i) == hit_guesses_.front()){
                cout << "Found a same attack" << endl;
                pop_junk_ = hit_guesses_.front();
                cout << "Saved in pop junk: " << pop_junk_ << endl;
                hit_guesses_.pop();
                cout << "Popped off the front." << endl;
                cout << "Now the front is: " << hit_guesses_.front() << endl;
                //To start the loop over to check for another repeat.
                i = 0;
            }
        }
        //Sets the queue item that is unique from the previous attacks to the dummy variable.
        pop_junk_ = hit_guesses_.front();
        cout << "Saved the non repeating queue guess in pop junk: " << pop_junk_ << endl;
        hit_guesses_.pop();
        //A CHECK
        if (hit_guesses_.size() != 0){
            cout << "Popped the queue front off now the front is: " << hit_guesses_.front() << endl; 
        }
        //Sends the variable to then check to see if it is a hit or not.
        SetAttack(pop_junk_);
        
        //A call to the win condition check that returns the win condition.
        return (computer_player_.GetVictory());
    }
    
    cout << "Went through the queue size check." << endl;
    
    //To create a random seed.
    //FIXME!!! Possible seed to frequently going to move seed to try and fix the infinite loop of same guesses.
    srand(time(NULL));
    
    cout << "Created a random seed value." << endl;
    
    //To generate a random row character between A and J.
    // FIXME!!! char rand_row_ = rand() % 74 + 65;
    char rand_row_ = 65 + rand() % 9;
    //To generate a random col character between 0 and 9.
    int rand_col_ = rand() % 9;
    
    cout << "Created a random row and random col variable." << endl;
    cout << "rand_row_: " << rand_row_ << endl;
    cout << "rand_col_: " << rand_col_ << endl;
    
    //Create a stringstream to be able to pass the rowcol together to the GameBoard class related function.
    stringstream ssin;
    
    //Clears the string stream buffer.
    //TRYING BOTH
    ssin.str("");
    ssin.clear();

    cout << "Created a string stream." << endl;
    
    //Stores rand_row and rand_col into the correct position into a single string stream.
    ssin << rand_row_ << rand_col_;
    
    cout << "Stores the two random variables in the string stream." << endl;
    cout << "String Stream: " << ssin.str() << endl;
    
    //Saves the string stream values.
    string rowcol = ssin.str();
    
    cout << "Stores the string stream string into a variable." << endl;
    cout << "rowcol: " << ssin.str() << endl;
    
    
    //Passes the string stream value to the function to check if it has already been guessed.
    SetAttack(rowcol);
    
    cout << "Called the SetAttack function with the rowcol value." << endl;
    
    //A call to the win condition check that returns the win condition.
    return (computer_player_.GetVictory());

};

//A set function to check a random guess and implement while it has not already been guessed.
//As well as pass it to the GameBoard class.
void Computer::SetAttack(string rowcol){

    for (int i = 0; i < attacks_.size(); ++i){
        if (attacks_.at(i) == rowcol){
            //Call function for rand generation of row and col.
            cout << "Went through the loop to show a repeated guess." << endl;
            GetAttack();
            //i = 0;
        }
    }
    
    //Erases the current spot in the turn number and adds the new guess.
    attacks_.erase(attacks_.begin() + counter_);
    attacks_.at(counter_) = rowcol;
    
    cout << "Added to the attack vector the next guessed." << endl;
    cout << "Next guessed from attacks vector: " << attacks_.at(counter_) << endl;
    
    //A check for what is stored in the attacks vector.
    for (int i = 0; i < 30; ++i){
        cout << "In attacks vector index: " << i << ", The guess: " << attacks_.at(i) << endl;
    }
    //To add the the turn number.
    ++counter_;
    
    //Holds the return value of the ChangeValue function to then either fill the queue or move to the next player's turn.
    char hit_miss_ = 'N';
    
    //Calls the GameBoard.
    hit_miss_ = computer_player_.ChangeValue(rowcol);
    
    cout << "Recorded the hit or miss: " << hit_miss_ << endl;
    
    //Runs through a check for if the guess was a hit or a miss.
    if (hit_miss_ == 'H'){
        //Separate the rowcol into its separate row and col values.
        //Create a stringstream in order to manipulate the string input.
        stringstream ssin;
    
        //Clears the string stream buffer.
        //TRYING BOTH
        ssin.str("");
        ssin.clear();
        //Holds the input argument into the string's buffer.
        ssin.str(rowcol);
        
        cout << "Put the rowcol Hit into the string stream: " << ssin.str() << endl;
    
        //Creates variables to hold the string streams sorted information.
        char row;
        int col;
    
        //Sorts the string streams information into the appropriate variables.
        ssin >> row >> col;
        
        cout << "Sorts the string stream into the separate variables." << endl;
        cout << "Row: " << row << endl;
        cout << "Col: " << col << endl;
        
        //Clears the stream in order to use again to bind the two variables later in the manipulation.
        //TRYING BOTH
        ssin.str("");
        ssin.clear();
        
        //A dummy variable to hold the string from the string stream.
        string queue_guess_;
        
        //Creates dummy int and char variable to check the row and col for validity
        char check_row_;
        int check_col_;
        
        //Move the row one up and same col combine in the string stream and store then clear the string stream.
        //Only if the manipulated variable is valid.
        check_row_ = row - 1;
        
        cout << "Creates a row that is one above the correct guess." << endl;
        cout << "Correct Guess Row: " << row << endl;
        cout << "Queue Row up: (--) " << check_row_ << endl;
        
        if ((check_row_ <= 'J') && (check_row_ >= 'A')){
            ssin << check_row_ << col;
            queue_guess_ = ssin.str();
            cout << "This is the string stream str() before the clear: " << ssin.str() << endl;
            //TRYING BOTH
            ssin.str("");
            ssin.clear();
            cout << "This is the string stream str() after the clear: " << ssin.str() << endl;
            //Store the string in the queue as the first guess the computer will make next.
            hit_guesses_.push(queue_guess_);
            
            cout << "Store the new row to the back of the queue." << endl;
            cout << "Queue Back: " << hit_guesses_.back() << endl;
        }
        cout << "Outside of the end of the 1st loop. The Queue Back is: " << hit_guesses_.back() << endl;
        //Only if the manipulated variable is valid.
        check_col_ = col + 1;
        
        cout << "Creates a col that is one to the right of the correct guess." << endl;
        cout << "Correct Guess Col: " << col << endl;
        cout << "Queue Col right: (++) " << check_col_ << endl;
        
        if ((check_col_ <= 9) && (check_col_ >= 0)){
            //Move the col to the right and have the same original row. Combine in the string stream then clear the string stream.
            ssin << row << check_col_;
            queue_guess_ = ssin.str();
            cout << "This is the string stream str() before the clear: " << ssin.str() << endl;
            //TRYING BOTH
            ssin.str("");
            ssin.clear();
            cout << "This is the string stream str() after the clear: " << ssin.str() << endl;
            cout << "This is what is stored in queue_guess_ : " << queue_guess_ << endl;
            //Store the string in the queue as the second guess the computer will make.
            hit_guesses_.push(queue_guess_);
            
            cout << "Store the new col to the back of the queue." << endl;
            cout << "Queue Back: " << hit_guesses_.back() << endl;
        }
        cout << "Outside of the end of the 2nd loop. The Queue Back is: " << hit_guesses_.back() << endl;
        //Only if the manipulated variable is valid.
        check_row_ = row + 1;
        
        cout << "Creates a row that is one below the correct guess." << endl;
        cout << "Correct Guess Row: " << row << endl;
        cout << "Queue Row down: (++) " << check_row_ << endl;
        
        if ((check_row_ <= 'J') && (check_row_ >= 'A')){
            //Move the row down one and same col combine in the string stream and store then clear the string stream.
            ssin << check_row_ << col;
            queue_guess_ = ssin.str();
            cout << "This is the string stream str() before the clear: " << ssin.str() << endl;
            //TRYING BOTH
            ssin.str("");
            ssin.clear();
            cout << "This is the string stream str() after the clear: " << ssin.str() << endl;
            cout << "This is what is stored in queue_guess_ : " << queue_guess_ << endl;
            //Store the string in the queue as the third guess the computer will make.
            hit_guesses_.push(queue_guess_);
            
            cout << "Store the new row to the back of the queue." << endl;
            cout << "Queue Back: " << hit_guesses_.back() << endl;
        }
        cout << "Outside of the end of the 3rd loop. The Queue Back is: " << hit_guesses_.back() << endl;
        //Only if the manipulated variable is valid.
        check_col_ = col - 1;
        
        cout << "Creates a col that is one to the left of the correct guess." << endl;
        cout << "Correct Guess Col: " << col << endl;
        cout << "Queue Col right: (--) " << check_col_ << endl;
        
        if ((check_col_ <= 9) && (check_col_ >= 0)){
            //Move the col to the left and have the same original row. Combine in the string stream then clear the string stream.
            ssin << row << check_col_;
            queue_guess_ = ssin.str();
            cout << "This is the string stream str() before the clear: " << ssin.str() << endl;
            //TRYING BOTH
            ssin.str("");
            ssin.clear();
            cout << "This is the string stream str() after the clear: " << ssin.str() << endl;
            cout << "This is what is stored in queue_guess_ : " << queue_guess_ << endl;
            //Store the string in the queue as the fourth guess the computer will make.
            hit_guesses_.push(queue_guess_);
            
            cout << "Store the new col to the back of the queue." << endl;
            cout << "Queue Back: " << hit_guesses_.back() << endl;
            
        }
        cout << "Outside of the end of the 4th loop. The Queue Back is: " << hit_guesses_.back() << endl;
        cout << "The size of the queue is now: " << hit_guesses_.size() << endl;
    }
    
    return;
};
//To print the human player's board with the computer's guesses.
void Computer::PrintBoard(){
    
    computer_player_.PrintBoard();
    
    return;
};