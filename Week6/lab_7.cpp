/*
 * Name        : lab_7.cpp
 * Author      : FILL IN
 * Description : Working with File I/O
 */

#include "lab_7.h"


// CODE HERE -- FUNCTION DEFINITION FOR ProcessFile()
/*
 * Open and read the contents of a text file. Each line of the
 * file will contain a single integer of possible values 10, 20,
 * 30, 40, or 50. Perform the following operations on the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * DON'T FORGET TO CLOSE YOUR FILE BEFORE YOUR FUNCTION ENDS!!!
 * @param string filename - A string containing the name of the file to
 *                          be processed
 * @return bool - True if filename was successfully opened and processed,
 *                else false
 */
        
 
bool ProcessFile(string filename){
    
    ifstream fin;
    fin.open(filename);
    
    if(!fin.is_open()){
        return true;
    }
    
    return false;
};
void ProcessArguments(int argc, char* argv[]){
    //Storage number
    int number;
    
    string file;
    
    if(argc == 2){
        file = argv[1];
    }
    
    ifstream fin;
    fin.open(file);
 
    while (!fin.eof()){
        fin.getline(100, number);
        fin.ignore('\n');
    
        switch (number){
            case 10:
                onTen();
                break;
            case 20:
                onTwenty();
                break;
            case 30:
                onThirty();
                break;
            case 40:
                onForty();
                break;
            case 50:
                onFifty();
                break;
            default:
                break;
        }
    
    }
    fin.close();
};
