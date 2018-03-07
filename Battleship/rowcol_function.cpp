#include "rowcol_function.h"

//Reusable function that returns a valid checkable index
int RowColIndex(string rowcol){
    
    //Create a stringstream in order to manipulate the string input.
    stringstream ssin;
    
    //Clears the string stream buffer.
    ssin.clear();
    //Holds the input argument into the string's buffer.
    ssin.str(rowcol);
    
    //Creates variables to hold the string streams sorted information.
    char row;
    int col;
    
    //A index variable that once the row and column are added appropriately will be stored to then access the vector.
    int index;
    
    //Sorts the string streams information into the appropriate variables.
    ssin >> row >> col;
    
    //A switch statement dependent on the alphabetical column input that will translate to a number.
    //To access the convert the rowcol to a proper integer index.
    switch (row) {
        
        case 'A':
        case 'a':
            index = (col) * 1;
            break;
            
        case 'B':
        case 'b':
            index = (col) * 2;
            break;
            
        case 'C':
        case 'c':
            index = (col) * 3;
            break;
            
        case 'D':
        case 'd':
            index = (col) * 4;
            break;
            
        case 'E':
        case 'e':
            index = (col) * 5;
            break;
            
        case 'F':
        case 'f':
            index = (col) * 6;
            break;
            
        case 'G':
        case 'g':
            index = (col) * 7;
            break;
            
        case 'H':
        case 'h':
            index = (col) * 8;
            break;
            
        case 'I':
        case 'i':
            index = (col) * 9;
            break;
            
        case 'J':
        case 'j':
            index = (col) * 10;
            break;
            
        default:
            cout << "Error" << endl;
            //Returns an out of bounds index.
            return 101;
            break;
    }
    
    return index;
};
