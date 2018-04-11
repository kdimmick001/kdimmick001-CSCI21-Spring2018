#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "stack.h"

#ifndef TOURNAMENT_APPLICATION_H
#define TOURNAMENT_APPLICATION_H


int main(int argc, char* argv[]){
    //tourn.exe names.txt STACK
    //tourn.exe names.txt QUEUE
    
    //To begin the file input stream.
    ifstream fin;
    
    //To open the text file.
    fin.open(argv[1]);
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    
    //Initializing a incrementation to go through the index's of the array.
    int i = 0;
    //A dummy variable to hold the string from the file to be added to either the queue or the stack.
    string x;
    //Deliminating character
    //char delim = ' ';
    //Variables to hold the two currently competing players.
    string player_one = " ";
    string player_two = " ";
    //Player marker.
    string marker = " ";
    //To keep track of how many games played
    int game_round; = 0;
    
    //If the the last command line argument was STACK.
    if(argv[2] == "STACK"){
        //Declaring a Stack object stack.
        Stack<string> stack;
        
        //While not the end of file. 
        while (!fin.eof()){
            //getline(fin, x, delim);
            //Hold the userID into the dummy variable x.
            fin >> x;
            //Push the current dummy variable ID info to the stack.
            stack.push(x);
        }
        fin.close();
        
        //Creating an output stream
        ofstream fout;
        //Opening a new file name to hold the Tournament statistics
        fout.open("Tournament Stats");
        
        //If the stack is greater than 1.
        if (stack.size() > 1){
            //Getting the two opponents
            player_one = stack.pop();
            player_two = stack.pop();
            
            //To alter how many games have been played.
            if ((marker == player_one) || (marker == player_two)){
                game_round = game_round + 1;
            }
            
            //If player one is larger than player two.
            if (player_one > player_two){
                //Adding back the winner to the stack.
                stack.push(player_one);
                
                if (marker == " "){
                    //To keep track of how many games played.
                    marker = player_one;
                }
                //If the marker lost this game.
                else if (marker == player_two){
                    marker = player_one;
                }
                //Recording the outcome.
                fout << player_one << "Won: " << (1 + game_round) << "     " << "Number of games played: " << (1 + game_round) << endl;
                fout << player_two << "Lost." << "Number of games played: " << (1 + game_round) << endl;
            }
            //If player two is larger than player one.
            else if (player_one < player_two){
                //Adding back the winner to the stack.
                stack.push(player_two);
                
                if (marker == " "){
                    //To keep track of how many games played
                    marker = player_two;
                }
                //If the marker lost this game.
                else if (marker == player_one){
                    marker = player_two;
                }
                //Recording the outcome.
                fout << player_two << "Won: " << (1 + game_round) << "     " << "Number of games played: " << (1 + game_round) << endl;
                fout << player_one << "Lost." << "Number of games played: " << (1 + game_round) << endl;
                
            }
    }
    //If the last command line argument was QUEUE.
    else if (argv[3] == "QUEUE"){
        //Declaring a Queue object queue.
        Queue<string> queue;
        
        //While not the end of the file.
        while (!fin.eof()){
            //Hold the userId into the dummy variable x.
            fin >> x;
            queue.push(x);
        }
        fin.close();
        
        //Creating an output stream
        ofstream fout;
        //Opening a new file name to hold the Tournament statistics
        fout.open("Tournament Stats");
        
        //If the stack is greater than 1.
        if (queue.size() > 1){
            //Getting the two opponents
            player_one = queue.pop();
            player_two = queue.pop();
            
            //To alter how many games have been played.
            if ((marker == player_one) || (marker == player_two)){
                game_round = game_round + 1;
            }
            
            //If player one is larger than player two.
            if (player_one > player_two){
                //Adding back the winner to the stack.
                queue.push(player_one);
                
                if (marker == " "){
                    //To keep track of how many games played.
                    marker = player_one;
                }
                //If the marker lost this game.
                else if (marker == player_two){
                    marker = player_one;
                }
                //Recording the outcome.
                fout << player_one << "Won: " << (1 + game_round) << "     " << "Number of games played: " << (1 + game_round) << endl;
                fout << player_two << "Lost." << "Number of games played: " << (1 + game_round) << endl;
            }
            //If player two is larger than player one.
            else if (player_one < player_two){
                //Adding back the winner to the stack.
                queue.push(player_two);
                
                if (marker == " "){
                    //To keep track of how many games played
                    marker = player_two;
                }
                //If the marker lost this game.
                else if (marker == player_one){
                    marker = player_two;
                }
                //Recording the outcome.
                fout << player_two << "Won: " << (1 + game_round) << "     " << "Number of games played: " << (1 + game_round) << endl;
                fout << player_one << "Lost." << "Number of games played: " << (1 + game_round) << endl;
                
            }
        
        
        
    }
    
    

    
}