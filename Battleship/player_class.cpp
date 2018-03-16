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
    
    //Calls the GameBoard class function ChangeValue to check the opponent board and update the tracker_board_ as needed.
    human_player_.ChangeValue(rowcol);
    
    //A call to the win condition check that returns the win condition.
    return (human_player_.GetVictory());
};

//Constructor.
Computer::Computer(){
    //Sets the attack vector with placeholders for future valid attacks.
    attacks_.resize(100, "Z0");
    //Initializes the counter to 0 to represent the turn number.
    counter_ = 0;
};

//A set function to generate random guesses and implement while it has not already been guessed.
int Computer::SetAttack(){
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
    
    //Saves the string stream values and passes to the proper function if not already present in the previous computer's guesses.
    //By checking the attacks_ vector for the computer class.
    string rowcol = ssin.str();
    
    //Create the upper part into its own function to then use in a separate this function parameter and then change again.
    //In this bottom function will pass.
    for (int i = 0; i < attacks_.size(); ++i){
        if (attacks_.at(i) == rowcol){
            //Call function for rand generation of row and col.
            i = 0;
        }
    }
};
