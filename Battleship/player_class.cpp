#include "player.h"


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
    human_player_.PrintBoard();
    
    //A call to the win condition check that returns the win condition.
    return (human_player_.GetVictory());
};

void Human::PrintBoard(){
    //To print the player tracker_board_.
    human_player_.PrintBoard();
    
    return;
}

//Constructor.
Computer::Computer(){
    //Sets the attack vector with placeholders for future valid attacks.
    attacks_.resize(100, "Z0");
    //Initializes the counter to 0 to represent the turn number.
    counter_ = 0;
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
    
    //Dummy variable to hold any popped items from the queue.
    string pop_junk_;
    
    //If the queue has contents.
    if (hit_guesses_.size() != 0){
        //Checks if the next in line for the queue has already been guessed.
        //And if so to remove and check the next.
        for (int i = 0; i < attacks_.size(); ++i){
            if (attacks_.at(i) == hit_guesses_.front()){
                pop_junk_ = hit_guesses_.pop();
                //To start the loop over to check for another repeat.
                i = 0;
            }
        }
        //Sets the queue item that is unique from the previous attacks to the dummy variable.
        pop_junk_ = hit_guesses_.pop();
        //Sends the variable to then check to see if it is a hit or not.
        SetAttack(pop_junk_);
        
        //A call to the win condition check that returns the win condition.
        return (human_player_.GetVictory());
    }
    
    //To create a random seed.
    srand(time(NULL));
    
    //To generate a random row character between A and J.
    char rand_row_ = rand() % 74 + 65;
    //To generate a random col character between 0 and 9.
    int rand_col_ = rand() % 9;
    
    //Create a stringstream to be able to pass the rowcol together to the GameBoard class related function.
    stringstream ssin;
    
    //Clears the string stream buffer.
    ssin.clear();

    //Stores rand_row and rand_col into the correct position into a single string stream.
    ssin << row << col;
    
    //Saves the string stream values.
    string rowcol = ssin.str();
    
    //Passes the string stream value to the function to check if it has already been guessed.
    SetAttack(rowcol);

    //A call to the win condition check that returns the win condition.
    return (human_player_.GetVictory());

};

//A set function to check a random guess and implement while it has not already been guessed.
//As well as pass it to the GameBoard class.
void Computer::SetAttack(string rowcol){

    for (int i = 0; i < attacks_.size(); ++i){
        if (attacks_.at(i) == rowcol){
            //Call function for rand generation of row and col.
            GetAttack();
            i = 0;
        }
    }
    
    //Holds the return value of the ChangeValue function to then either fill the queue or move to the next player's turn.
    char hit_miss_ = 'N';
    
    //Calls the GameBoard.
    hit_miss_ = computer_player_.ChangeValue(rowcol);
    
    //Runs through a check for if the guess was a hit or a miss.
    if (hit_miss_ == 'H'){
        //Separate the rowcol into its separate row and col values.
        //Create a stringstream in order to manipulate the string input.
        stringstream ssin;
    
        //Clears the string stream buffer.
        ssin.clear();
        //Holds the input argument into the string's buffer.
        ssin.str(rowcol);
    
        //Creates variables to hold the string streams sorted information.
        char row;
        int col;
    
        //Sorts the string streams information into the appropriate variables.
        ssin >> row >> col;
        
        //Clears the stream in order to use again to bind the two variables later in the manipulation.
        ssin.clear();
        
        //A dummy variable to hold the string from the string stream.
        string queue_guess_;
        
        //Creates dummy int and char variable to check the row and col for validity
        char check_row_;
        int check_col_;
        
        //Move the row one up and same col combine in the string stream and store then clear the string stream.
        //Only if the manipulated variable is valid.
        check_row_ = (row--);
        if ((check_row_ <= 'J') && (check_row_ >= 'A'){
            ssin << check_row_ << col;
            queue_guess_ = ssin.str();
            ssin.clear();
            //Store the string in the queue as the first guess the computer will make next.
            hit_guesses_.push(queue_guess_);
        }
        //Only if the manipulated variable is valid.
        check_col_ = (col++);
        if ((check_col_ <= 9) && (check_col_ >= 0)){
            //Move the col to the right and have the same original row. Combine in the string stream then clear the string stream.
            ssin << row << check_col_;
            queue_guess_ = ssin.str();
            ssin.clear();
            //Store the string in the queue as the second guess the computer will make.
            hit_guesses_.push(queue_guess_);
        }
        //Only if the manipulated variable is valid.
        check_row_ = (row++);
        if ((check_row_ <= 'J') && (check_row_ >= 'A')){
            //Move the row down one and same col combine in the string stream and store then clear the string stream.
            ssin << check_row_ << col;
            queue_guess_ = ssin.str();
            ssin.clear();
            //Store the string in the queue as the third guess the computer will make.
            hit_guesses_.push(queue_guess_);
        }
        //Only if the manipulated variable is valid.
        check_col_ = (col--);
        if ((check_col_ <= 9) && (check_col_ >= 0)){
            //Move the col to the left and have the same original row. Combine in the string stream then clear the string stream.
            ssin << row << check_col_;
            queue_guess_ = ssin.str();
            ssin.clear();
            //Store the string in the queue as the fourth guess the computer will make.
            hit_guesses_.push(queue_guess_);
        }
    }
    
    return;
};
