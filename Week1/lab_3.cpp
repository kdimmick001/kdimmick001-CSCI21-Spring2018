/*  Kelsey Dimmick
    
    01/30/2018
    
    DESCRIPTION:
    
    Part 1: Create a numeric driven Goldilocks and the Three Bears function program
    Part 2: Switch function rock paper scissors game
    Part 3: Make a function that returns all characters in lowercase
    Part 4: Make a function that returns all characters in uppercase
*/

#include "lab_3.h"

//A function to go through an action in the story of Goldi Locks based on the function arguments of an item and number that corresponds to the story.
void Goldilocks(string item, int number) {
    
    //Declaring a constant integer to hold the array of options for the story.  
    const int ELEMENT_NUM = 3; 
    
    //string item = "none";
    //int number = 0;
    
    //Creating an array of the possible outcomes dependent on the number entered by the user.
    string three_bears_type[ELEMENT_NUM] = {"too hot", "too cold", "just right"};
    
    //Telling a revised story of Goldi Locks.
    cout << "Once upon a time, there was a troublesome girl named Goldi Locks.";
    cout << "A distant cousin of Robin of Loxley. Her last name changing through etymology and heraldry, as well as through several misreputable past generations." << endl;
    cout << "Well this girl was stolling through the forrest, as is wise of such little girls to do on their own.";
    cout << "And she came upon a strange cabin. This was an odd cabin, as it was covered in claw marks and bear droppings.";
    cout << "Which was an open invitation for her to venture inside to rumage through the belongings and take the souveniors of those who had befallen a bear attack." << endl;
    cout << "She opened the door which fell open upon its hinges.";
    cout << "Looking around the cabin, she noticed that it was fairly well kempt.";
    cout << "She went in to explore. 'The people that lived here before her must of had a compusive disorder' she thought.";
    cout << "It was a very odd lone cabin in the woods, because everything in this house cames in groups of three.";
    cout << "There were three doors, three rugs, three windows, three of everything." << endl;
    cout << "She stared at this unusal arrangement wondering who their interior designer could have been.";
    cout << "When she became fairly hungry and tired.";
    cout << "Well she had plenty of choices. She could have one of the three porridges, sit in one of the three chairs, or sleep in one of the three beds." << endl;
    cout << "What should this little home invader do first?" << endl << endl;
    //cout << "Please enter an item for her to use." << endl;
    //cin >> item;
    //cout << endl;
    //cout << "Please enter which one of the three she should try. 1, 2 or 3." << endl;
    //cin >> number;
    //cout << endl;
    
    //Three if statements checking the user's item and if the number matches the unsatisfactory choice in the story.
    if ((item == "bed") && (number <= 2)){
        cout << "Goldi Locks is displeased with her choice." << endl;
        cout << "This " << item << "is " << three_bears_type[number - 1] << endl;
        cout << "She left the house in a pretentious huff, in disbelief that wany one could keep such a " << item << "that was " << three_bears_type[number-1] << endl;
        //An else if statement that if the user choses the best choice.
        }else if (number == 3){
            cout << "Goldi Locks is very content with her choice." << endl;
            cout << "This " << item << "is " << three_bears_type[number - 1] << endl;
            cout << "So she stayed to enjoy in her accomplishment." << endl;
            cout << "Unfortunately this is where her story ends. She was so content that she overstayed her welcome." << endl;
            cout << "A near by family of bears noticed her in the house and came to also explore the cabin.";
            cout << "But for this family, instead of having three choices of everything, had an easy choice of one.";
            cout << "And thus Goldi Locks was no more." << endl;
            
        }
    
    
    if ((item == "chair") && (number <= 2)){
        cout << "Goldi Locks is displeased with her choice." << endl;
        cout << "This " << item << "is " << three_bears_type[number - 1] << endl;
        cout << "She left the house in a pretentious huff, in disbelief that wany one could keep such a " << item << "that was " << three_bears_type[number-1] << endl;
            }else if (number == 3){
            cout << "Goldi Locks is very content with her choice." << endl;
            cout << "This " << item << "is " << three_bears_type[number - 1] << endl;
            cout << "So she stayed to enjoy in her accomplishment." << endl;
            cout << "Unfortunately this is where her story ends. She was so content that she overstayed her welcome." << endl;
            cout << "A near by family of bears noticed her in the house and came to also explore the cabin.";
            cout << "But for this family, instead of having three choices of everything, had an easy choice of one.";
            cout << "And thus Goldi Locks was no more." << endl;

    }

    if ((item == "bed") && (number <= 2)){
        cout << "Goldi Locks is displeased with her choice." << endl;
        cout << "This " << item << "is " << three_bears_type[number - 1] << endl;
        cout << "She left the house in a pretentious huff, in disbelief that wany one could keep such a " << item << "that was " << three_bears_type[number-1] << endl;
        }else if (number == 3){
            cout << "Goldi Locks is very content with her choice." << endl;
            cout << "This " << item << "is " << three_bears_type[number - 1] << endl;
            cout << "So she stayed to enjoy in her accomplishment." << endl;
            cout << "Unfortunately this is where her story ends. She was so content that she overstayed her welcome." << endl;
            cout << "A near by family of bears noticed her in the house and came to also explore the cabin.";
            cout << "But for this family, instead of having three choices of everything, had an easy choice of one.";
            cout << "And thus Goldi Locks was no more." << endl;

    }
    //An else statement to happen if the user enters an invalid number or item.
    else {
        cout << "There wasn't anything of that nature in the house and she left." << endl;
    }
    
};

//A function that takes arguments of player one and player two rock paper scissor letter choices and tells who won the game based on the results.
void RockScissorPaper(char player_one, char player_two){
    
    //A switch function to check the input of player one that accounts for upper and lower case.
    switch (player_one) {
        //To check if player one chose rock.
        case 'R' :
        case 'r' :
            cout << "Player one played: Rock" << endl;
            break;
        //To check if player one chose paper.
        case 'P' :
        case 'p' :
            cout << "Player one played: Paper" << endl;
            break;
        //To check is player one chose scissors.
        case 'S' :
        case 's' :
            cout << "Player one played: Scissors" << endl;
            break;
        //If there was an invalid response.
        default :
            cout << "Player one neglected to play" << endl;
    }
    
    //A switch function to check the input of player two that accounts for upper and lower case.
    switch (player_two) {
        //To check if player two chose rock and if so who won.
        case 'R' :
        case 'r' :
            cout << "Player two played: Rock" << endl;
            if ((player_one == 'P') || (player_one == 'p')){
                cout << "Player One Wins!" << endl;
                }else if ((player_one == 'S') || (player_one == 's')){
                    cout << "Player Two Wins!" << endl;
                }
                else {
                    cout << "Player Two Wins!" << endl;
                }
            break;
        //To check if player two chose paper and if so who won.
        case 'P' :
        case 'p' :
            cout << "Player two played: Paper" << endl;
            if ((player_one == 'S') || (player_one == 's')){
                cout << "Player One Wins!" << endl;
                }else if ((player_one == 'R') || (player_one == 'r')){
                    cout << "Player Two Wins!" << endl;
                }
                else {
                    cout << "Player Two Wins!" << endl;
                }
            
            break;
        //To check is player two chose scissors and if so who won.
        case 'S' :
        case 's' :
            cout << "Player two played: Scissors" << endl;
            if ((player_one == 'R') || (player_one == 'r')){
                cout << "Player One Wins!" << endl;
                }else if ((player_one == 'P') || (player_one == 'p')){
                    cout << "Player Two Wins!" << endl;
                }
                else {
                    cout << "Player Two Wins!" << endl;
                }
   
            break;
        //If there was an invalid response entered and who won if there was.
        default :
            cout << "Player two neglected to play" << endl;
            if ((player_one != 'r') || (player_one != 'R') || (player_one != 'p') || (player_one != 'P') || (player_one != 's') || (player_one != 'S')){
                cout << "No one won." << endl;
            }
            else {
                cout << "Player One Wins!" << endl;
            }
    }
    
};

//A function that takes theargument of a string input to convert the string to all lowercase letters.
string ToLower(string input){
    
    //Initializing a looping variable.
    int i = 0;
    
    //A while loop to loop through each character in the string.
    while ((input[i] >= 65) && (input[i] <= 90)){
        //To add the ASCII number to the upper case to turn it to a lower case letter.
        input[i] = input[i] + 32;
        ++i;
    }
    
    return input;
};

//A function that takes the argument of a string input to convert the string to all uppercase letters.
string ToUpper(string input){
    
    //Initializing a looping variable.
    int i = 0;
    
    //A while loop to loop through each character in the string.
    while ((input[i] >= 97) && (input[i] <= 122)){
        //To subract the ASCII number to the lower case to turn it to a upper case letter.
        input[i] = input[i] - 32;
        ++i;
    }
    
    return input;
};

