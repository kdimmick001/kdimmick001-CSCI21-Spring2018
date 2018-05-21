#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main(){
    
    //A Mapt to hold the movie title and the associated actors in the movie.
    map<string, vector<string> > Database;
    
   // Database.emplace(movie_title, push_back(actor));
    
    //Starting the file stream.
    ifstream fin;
    //Opening the file.
    fin.open("movie.txt");
    
    //Checking to make sure the file opened.    
    if (!fin.is_open()){
        cout << "UnBle to open file." << endl;
    }
    
    //Declaring variables to hold the stringstream information.
    string info;
    string actor;
    string movie;
    
    //Starting the string stream.
    istringstream ssin;
    
    //While it is not the end of the file,
    while(!fin.eof()){
        //Get the line and store the information in the variable info until the newline is hit.
        getline(fin, info);
        fin.ignore(1, '\n');
        //cout << "Got the next line." << endl;
        //fin >> actor;
        //Holding the information in the string stream to manipulate.
        ssin.str() = "";
        //cout << "Cleared the string stream" << endl;
        ssin.str(info);
        ssin >> actor;
        //cout << "This is what the string stream stored for actor: " << actor << endl;
        
        while (ssin >> movie){
            ssin >> movie;
            //cout << "This is what the string stream stored for movie: " << movie << endl;
            //If the map already contains the movie key.
            if (Database.count(movie) == 1){
                Database[movie].push_back(actor);
                //cout << "Already contains movie." << endl;
            } else {
                //Database.emplace(movie, (Database[movie].push_back(actor)) );
                Database[movie].push_back(actor);
                //cout << "Doesn't contain movie and added with actor." << endl;
            }
            actor = "";
            //cout << "Cleared actor string." << endl;
            //Database.emplace(movie, push_back(actor));
            
        }
        ssin.clear();
        //cout << "Cleared the String Strem." << endl;
    }
}
    

// // }
// //coActors function to print a list of actors with the co-Actor if they are already in out database.
// string coActor(string actor_name){
    
    
// }

// class Pair{
//     private:
//         string movie;
//         vector<string> actor;
//         Pair* next_movie;
//     public:
//         //Constructor.
//         Pair();
//         //Set the movie title.
//         void SetMovie(string title);
//         //Get the movie title.
//         string GetMovie();
//         //Set the actors
//         void SetActor(string title, string person);
        
// }

// Pair::Pair(){
//     movie = NULL;
//     next_movie == NULL;
// };
// void Pair::SetMovie(string title){
//     //If there is no movie title.
//     if (movie == NULL){
//         movie = title;
//     //If there is a movie title but the next movie isn't declared.
//     } else if (next_movie == NULL) {
//         Pair* another_movie = new Pair*;
//         another_movie.SetMovie(title);
//         next_movie = another_movie;
//     //If the next_movie title is declared.
//     } else {
//         Pair* next_title = new Pair*;
//         Pair* curr_title = new Pair*;
//         next_title.SetMovie(title);
        
//         curr_title = next_movie;
//         while (curr_title.next_movie != NULL){
//             curr_title = curr_title.next_movie;
            
//         }
//         curr_title.next_movie = next_title;
//     }
// };

// string Pair::GetMovie(){
//     return movie;
// };

// void Pair::SetActor(string title, string person){
//     //If movie title is the same
//     if (movie == title){
//         actor.push_back(person);
//     //If movie does not equal the title.
//     } else if (movie != title){
//         if (next)
//     }
// };