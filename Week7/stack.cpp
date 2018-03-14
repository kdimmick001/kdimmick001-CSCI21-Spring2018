#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

//Header guards.
#ifndef STACK_H
#define STACK_H

/*
    Create a new, empty stack theStack.
    Display a prompt for the program.
    Read in inFileName.
    Open inStream (using inFileName), and test that it opened properly.
    Loop:
    Read in word from inStream.
    If inStream is at the end-of-file, terminate the loop.
    Push word onto theStack.
    Close inStream.
    While theStack is not empty:
    Display the top of theStack on the screen (followed by some whitespace).
    Pop the top value from theStack
*/

int main() {
    
    //Declaring a string to hold the file name.
    string file = "file file";
    
    //Prompting the user to enter a file name.
    cout << "Please enter a valid file name." << endl;
    getline(cin, file);
    cout << endl;
    
    //If the file string has any while spaces keep asking to enter a valid one.
    for (int i = 0; i < file.length(); ++i) {
        while ((file[i] == ' ')){
            cout << "Please enter a valid file name to upload a game board" << endl;
            getline(cin, file);
        }
    }

    //Creates a file stream for the file name.
    ifstream fin;
    
    //Opens the file.
    fin.open(file);
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    
    //Create a stack to read int the file words.
    stack<string> sstack;
    
    //Declares an intermediary dummy variable to hold the file string to then push to the stack.
    string word;
    
    //While not the end of the file keep pushing all string values onto the stack.
    while (!fin.eof()){
        //Gets the line of words.
        getline(fin, word);
        //Stores that word in the stack via the push function.
        sstack.push(word);
    }
    
    //Closes the file stream.
    fin.close();
    
    //Creates a counter variable to track the outputs.
    int counter = 1;
    
    //While the stack is not empty.
    while (!sstack.empty()){
        //Get the top value of the stack and cout the number of item and its contents.
        cout << counter << ". " << sstack.top() << endl;
        //Pop off that top value to then loop through again until the stack is empty.
        sstack.pop();
        //To keep track of the items in the stack.
        ++counter;
        
    }
    
}
//Header guards.
#endif