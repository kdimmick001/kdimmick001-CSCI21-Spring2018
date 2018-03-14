#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

//Header guards.
#ifndef QUEUE_H
#define QUEUE_H

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
    
    //Create a queue to read int the file words.
    queue<string> squeue;
    
    //Declares an intermediary dummy variable to hold the file string to then push to the queue.
    string word;
    
    //While not the end of the file keep pushing all string values onto the queue.
    while (!fin.eof()){
        //Gets the line of words.
        getline(fin, word);
        //Stores that word in the queue via the push function.
        squeue.push(word);
    }
    
    //Closes the file stream.
    fin.close();
    
    //Creates a counter variable to track the outputs.
    int counter = 1;
    
    //While the queue is not empty.
    while (!squeue.empty()){
        //Get the head value of the queue and cout the number of item and its contents.
        cout << counter << ". " << squeue.front() << endl;
        //Pop off that head value to then loop through again until the queue is empty.
        squeue.pop();
        //To keep track of the items in the queue.
        ++counter;
        
    }
    
}

//Header guards.
#endif

























