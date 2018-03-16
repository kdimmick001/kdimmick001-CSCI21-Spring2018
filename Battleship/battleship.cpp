#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "player.h"
using namespace std;

int main(int argc, char* argv[]) {
  
  
    //An introduction to the game program.
    cout << "*********!!PREPARE FOR BATTLE!!**********" << endl;
    cout << "====WELCOME TO THE GAME OF BATTLESHIP====" << endl << endl << endl;
    
    //Declaring a string to hold the human's board file name.
    string human_file = argv[1];
    
    //Declaring a string to hold the computer's board file name.
    string computer_file = argv[2];
    
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
    
    //Declare a variable to hold the computer win condition variable.
    int computer_winner = 0;
    //Dummy variable for the computer to check if the computer got a hit or not.
    int computer_hit = 0;
    
    //Declares a variable to hold a rowcol guess.
    string rowcol;
    
    //To generate a random turn order if not specified.
    srand(time(NULL));
    
    //Variable to hold who goes first.
    int first;
    
    //1 will be human player and 2 will be computer.
    first = rand() % 2 + 1;
    
    //If there is a argv[3] for turn order and the contents are COMPUTER or the randomizer is 2.
    if (((argc == 4) && (argv[3] == "COMPUTER")) || (first == 2)){
        //Calls the Computer Class to give it the first turn.
        //Uses the human file so that the computer can reference to check guesses.
        computer_player.PushBoard(human_file);
        computer_winner = computer_player.GetAttack();
        if (computer_hit <= computer_winner){
          cout << "He missed Captain!" << endl;
        } else {
          cout << "A direct hit Captain!" << endl;
          computer_hit = computer_winner;
        }
        //Starts the next player's turn by passing the file to be used for the player's competitor's board.
        human_player.PushBoard(computer_file);
    }
    //If there is a argv[3] for turn order and the contents are HUMAN or the randomizer is 1.
    if (((argc == 4) && (argv[3] == "HUMAN")) || (first == 1)){
        //Calls the Human Class to give it the first turn.
        //Uses the computer file so that the human can reference to check guesses.
        human_player.PushBoard(computer_file);
        human_player.PrintBoard();
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
        human_winner = human_player_.SetAttack(rowcol);
        //Starts a whole computer turn to make in sync the loop of turn order.
        computer_player(human_file);
        computer_winner = computer_player.GetAttack();
        if (computer_hit <= computer_winner){
          cout << "He missed Captain!" << endl;
        } else {
          cout << "A direct hit Captain!" << endl;
          computer_hit = computer_winner;
        }
    }
    
    while ()

    
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

/*

TEST:
*********!!PREPARE FOR BATTLE!!**********
====WELCOME TO THE GAME OF BATTLESHIP====


Please enter a competitor board file.
board.txt

  0 1 2 3 4 5 6 7 8 9 
A o o o o o o o o o o 
B o o o o o o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o o 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

A1


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M o o o o o o o o 
B o o o o o o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o o 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

A2


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o o o o o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o o 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

Z10


Please enter a valid attack coordinate. ex. [A1]

F9    


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o o o o o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o H 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

J15


Please enter a valid attack coordinate. ex. [A1]

B4


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o o o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o H 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

B2


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o H 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

G6    


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o H 
G o o o o o o H o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

F6


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o H o o H 
G o o o o o o H o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

E6


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F o o o o o o H o o H 
G o o o o o o H o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

B2


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F o o o o o o H o o H 
G o o o o o o H o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

H6


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F o o o o o o H o o H 
G o o o o o o H o o o 
H o o o o o o H o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

F00                                     


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M o o o o o H o o H 
G o o o o o o H o o o 
H o o o o o o H o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

G01


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M o o o o o H o o H 
G o H o o o o H o o o 
H o o o o o o H o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

h1


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M o o o o o H o o H 
G o H o o o o H o o o 
H o M o o o o H o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

f1


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G o H o o o o H o o o 
H o M o o o o H o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

i1


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G o H o o o o H o o o 
H o M o o o o H o o o 
I o M o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

j0


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G o H o o o o H o o o 
H o M o o o o H o o o 
I o M o o o o o o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

i0


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G o H o o o o H o o o 
H o M o o o o H o o o 
I H M o o o o o o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

h0


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G o H o o o o H o o o 
H H M o o o o H o o o 
I H M o o o o o o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

g0


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G H H o o o o H o o o 
H H M o o o o H o o o 
I H M o o o o o o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

g2


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G H H H o o o H o o o 
H H M o o o o H o o o 
I H M o o o o o o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

g3


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G H H H M o o H o o o 
H H M o o o o H o o o 
I H M o o o o o o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

i6


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G H H H M o o H o o o 
H H M o o o o H o o o 
I H M o o o o M o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

g9


You Missed Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o o 
F M M o o o o H o o H 
G H H H M o o H o o M 
H H M o o o o H o o o 
I H M o o o o M o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

e9


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o H o o H 
F M M o o o o H o o H 
G H H H M o o H o o M 
H H M o o o o H o o o 
I H M o o o o M o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

d9


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o H 
E o o o o o o H o o H 
F M M o o o o H o o H 
G H H H M o o H o o M 
H H M o o o o H o o o 
I H M o o o o M o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

c9


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o H 
D o o o o o o o o o H 
E o o o o o o H o o H 
F M M o o o o H o o H 
G H H H M o o H o o M 
H H M o o o o H o o o 
I H M o o o o M o o o 
J H o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!

d6


A Hit Captain!

  0 1 2 3 4 5 6 7 8 9 
A o M H o o o o o o o 
B o o H o M o o o o o 
C o o o o o o o o o H 
D o o o o o o H o o H 
E o o o o o o H o o H 
F M M o o o o H o o H 
G H H H M o o H o o M 
H H M o o o o H o o o 
I H M o o o o M o o o 
J H o o o o o o o o o 

You have defeated the enemy!

YOU WIN CAPTAIN!!!


TEST FOR VALID FILE NAMES:

*********!!PREPARE FOR BATTLE!!**********
====WELCOME TO THE GAME OF BATTLESHIP====


Please enter a competitor board file.
board board me

Please enter a valid file name to upload a game board
board another board
Please enter a valid file name to upload a game board
board.txt
  0 1 2 3 4 5 6 7 8 9 
A o o o o o o o o o o 
B o o o o o o o o o o 
C o o o o o o o o o o 
D o o o o o o o o o o 
E o o o o o o o o o o 
F o o o o o o o o o o 
G o o o o o o o o o o 
H o o o o o o o o o o 
I o o o o o o o o o o 
J o o o o o o o o o o 

What shall your plan of attack be Captain?

Enter a Row[letter] and a Column[number] of where you want to strike!


*/