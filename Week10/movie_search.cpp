#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <list>
using namespace std;

int main() {
    //Creating an input stream
    ifstream fin;

    //To open a text file to get the string information.
    fin.open(file.c_str());
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    
    //Declaring a movie list.
    list<string> movie_list;
    
    //First movie to compare.
    string first_movie;
    
    //Second movie to compare.
    string second_movie;
    
    while(!fin.eof()){
        
        fin >> first_movie;
        fin >> second_movie;
        
        if (first_movie > second_movie){
            if (movie_list.size() == 0){
                movie_list.push(second_movie);
                movie_list.push(first_movie);
            }
        }
        if (second_movie > first_movie){
            if (movie_list.size() == 0){
                movie_list.push(first_movie);
                movie_list.push(second_movie);
            }
        }
    }
}