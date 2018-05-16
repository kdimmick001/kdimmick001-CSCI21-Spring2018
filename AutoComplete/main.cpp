
#include "stringclass.h"

int main(){
    //Creating a file input stream
    ifstream fin;
    //Opening the file to get input from.
    fin.open("words.txt");
    //Checking to make sure file opened properly.
    if (!fin.is_open()){
        cout << "Unable to open file." << endl;
    }
    //To create a map to hold the associated weight and string.
    map<string, int> library;
    
    //Holds the size of the file.
    fin >> size;
    
    //While not the end of the file fill the map library to be used for a check for the autocomplete.
    while (!fin.eof()){
        //Holds the weight of the first string.
        fin >> weight;
        //Holds the string associated with the previous weight.
        fin >> word;
        //To emplace the associated word with the weight into the map library.
        library.emplace(word, weight);
        
    }
    
}