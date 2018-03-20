#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "player_class.h"
using namespace std;

int main(int argc, char* argv[]) {
  
    //An introduction to the game program.
    cout << "*********!!PREPARE FOR BATTLE!!**********" << endl;
    cout << "====WELCOME TO THE GAME OF BATTLESHIP====" << endl << endl << endl;
    
    //Declaring a string to hold the human's board file name.
    string human_file = argv[1];
    
    //Declaring a string to hold the computer's board file name.
    string computer_file = argv[2];
    
    //Variable to hold a possible 4th argc.
    string first_player = "none";
    
    if (argc == 4){
      first_player = argv[3];
    }
    
    //If the file string has any while spaces keep asking to enter a valid one for the human board.
    for (int i = 0; i < human_file.length(); ++i) {
        while ((human_file[i] == ' ')){
            cout << "Please enter a valid human board file name to upload." << endl;
            getline(cin, human_file);
        }
    }
    
    //If the file string has any while spaces keep asking to enter a valid one for the computer board.
    for (int i = 0; i < computer_file.length(); ++i) {
        while ((human_file[i] == ' ')){
            cout << "Please enter a valid computer board file name to upload." << endl;
            getline(cin, computer_file);
        }
    }
    
    //Declares a Computer Class object.
    Computer computer_player;
    
    //Declares a Player Class object.
    Human human_player;
    
    //Declares a variable to hold the human win condition variable.
    int human_winner = 0;
    //Dummy variable for the human player to check if it was a hit or not.
    int human_hit = 0;
    
    //Declare a variable to hold the computer win condition variable.
    int computer_winner = 0;
    //Dummy variable for the computer to check if the computer got a hit or not.
    int computer_hit = 0;
    
    //Declares a variable to hold a rowcol guess.
    string rowcol;
    
    //To generate a random turn order if not specified.
    srand(time(NULL));
    
    //Variable to hold who goes first.
    int turn = 0;
    
    //Will only set a random first player if one wasn't declared.
    if (argc < 4){
      //1 will be human player and 2 will be computer.
      turn = rand() % 2 + 1;
    }
    //Uses the human file so that the computer can reference to check guesses.
    computer_player.PushBoard(human_file);
    //Starts the next player's turn by passing the file to be used for the player's competitor's board.
    human_player.PushBoard(computer_file);
    
    //If there is a argv[3] for turn order and the contents are COMPUTER or the randomizer is 2.
    if ((first_player == "COMPUTER") || (turn == 2)){
        cout << "The enemey started firing on us first!" << endl << endl;
        //Calls the Computer Class to give it the first turn.
        computer_winner = computer_player.GetAttack();
        cout << "Computer_winner: " << computer_winner << endl;
        cout << "Computer_hit: " << computer_hit << endl;
        if (computer_hit >= computer_winner){
          cout << "He missed Captain!" << endl << endl;
        } else {
          cout << "A direct hit Captain! We are taking on water!" << endl << endl;
          computer_hit = computer_winner;
          cout << "Computer_hit = computer_winner: " << computer_hit << " = " << computer_winner << endl;
        }
    }
    //If there is a argv[3] for turn order and the contents are HUMAN or the randomizer is 1.
    if ((first_player == "HUMAN") || (turn == 1)){
        cout << "Arm the torpedos Captain! Start the attack!" << endl << endl;
        //Calls the Human Class to give it the first turn.
        human_player.PrintBoard();
        cout << endl;
        cout << "Your Battle Board." << endl << endl;
        computer_player.PrintBoard();
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
        
        human_winner = human_player.SetAttack(rowcol);
        cout << "Human_winner: " << human_winner << endl;
        cout << "Human_hit: " << human_hit << endl;
        if (human_hit >= human_winner){
          cout << "You Missed Captain!" << endl << endl;
        } else {
          cout << "A Hit Captain!" << endl << endl;
          human_hit = human_winner;
          cout << "Human_hit = human_winner: " << human_hit << " = " << human_winner << endl;
        }
        computer_winner = computer_player.GetAttack();
        cout << "Computer_winner: " << computer_winner << endl;
        cout << "Computer_hit: " << computer_hit << endl;
        if (computer_hit >= computer_winner){
          cout << "He missed Captain!" << endl;
        } else {
          cout << "A direct hit Captain! We are taking on water!" << endl;
          computer_hit = computer_winner;
          cout << "Computer_hit = computer_winner: " << computer_hit << " = " << computer_winner << endl;
        }
    }
    
    //While neither player has hit all the ships.
    while ((computer_winner != 17) || (human_winner != 17)){
        //The Human player goes first followed by the computer player.
        human_player.PrintBoard();
        cout << endl;
        cout << "Your Battle Board." << endl << endl;
        computer_player.PrintBoard();
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
        human_winner = human_player.SetAttack(rowcol);
        cout << "Human_winner: " << human_winner << endl;
        cout << "Human_hit: " << human_hit << endl;
        if (human_hit >= human_winner){
          cout << "You Missed Captain!" << endl << endl;
        } else {
          cout << "A Hit Captain!" << endl << endl;
          human_hit = human_winner;
          cout << "Human_hit = human_winner: " << human_hit << " = " << human_winner << endl;
        }
        computer_winner = computer_player.GetAttack();
        cout << "Computer_winner: " << computer_winner << endl;
        cout << "Computer_hit: " << computer_hit << endl;
        if (computer_hit >= computer_winner){
          cout << "He Missed Captain!" << endl << endl;
        } else {
          cout << "A direct hit Captain! We are taking on water!" << endl << endl;
          computer_hit = computer_winner;
          cout << "Computer_hit = computer_winner: " << computer_hit << " = " << computer_winner << endl;
        }
    }
    //Checks if the computer player has hit all 17 spots.
    if (computer_winner == 17){
      human_player.PrintBoard();
      cout << endl;
      cout << "Your Battle Board." << endl << endl;
      computer_player.PrintBoard();
      cout << "Captain we have lost! Abandon ship!" << endl << endl;
      cout << "You Lose." << endl << endl;
    }
    //Checks if the human player has hit all 17 spots.
    if (human_winner == 17){
      human_player.PrintBoard();
      cout << endl;
      cout << "Your Battle Board." << endl << endl;
      computer_player.PrintBoard();
      cout << "Captain you have destroyed all enemy ships!" << endl << endl;
      cout << "YOU WIN CAPTAIN!!!!" << endl << endl;
    }

}
