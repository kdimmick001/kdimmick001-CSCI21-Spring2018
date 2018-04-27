// string coActors(string name){
    
// }
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

// int main(){
    
//     ifstream fin;
//     fin.open("movies.txt");
//     if (!fin.is_open()){
//         cout << "UnBle to open file." << endl;
//     }

//     //An list to hold all of the movie titles.
//     const int NUM_ELEMENTS = 50;
//     string MoviesHash[NUM_ELEMENTS];
    
//     //Holds what the HashTable is temporarily pointing to.
//     string contents;
    
//     //To hold the contents of the file.
//     string first_name;
//     string last_name;
//     string movie;
    
//     //To initially fill the array.
//     for (int i = 0; i < NUM_ELEMENTS; i++){
//         MoviesHash[i] = "NULL";
//     }
    
//     while(!fin.eof()){
//         fin >> first_name;
//         fin >> last_name;
//         fin >> movie;
        
//         //To check if movie has already been entered.
//         for(int i = 0; i < NUM_ELEMENTS; i++){
//             //If the movie from the file is already in the MoviesHash.
//             if (MoviesHash[i] == movie){
//                 contents = *MoviesHash[i];
//                 if (contents != "NULL"){
//                     *contents = first_name + " " + last_name;
//                 } else{
//                     *MoviesHash[i] = first_name + " " + last_name;
//                 }
//             } else{
//                 for (int i = 0; i < NUM_ELEMENTS; i++){
//                     if (MoviesHash[i] == "NULL"){
//                         MoviesHash[i] = movie;
//                         *MoviesHash[i] = first_name + " " + last_name;
//                     }
//                 }
                
//             }
//         }

//     }
// }

// class Hash{
//     private:
//         //A string to hold the movie information.
//         //Also a string for the bucket in the hash.
//         string info;
//         //A integer variable to hold the position to map to an index.
//         int key;
//     public:
//         //To insert to the hash.
//         void HashInsert(string thing, int position);
// };

// void Hash::HashInsert(string thing, int position){
    
// };

// HashInsert(hashTable, item) {
//   bucketList = hashTable[Hash(item.key)]
//   ListAppend(bucketList, item)
// }
// HashRemove(hashTable, item) {
//   bucketList = hashTable[Hash(item.key)]
//   itemNode = ListSearch(bucketList)
//   if( itemNode is not null ) {
//       ListRemove(bucketList, itemNode)
//   } 
// }
// HashSearch(hashTable, key) {
//   bucketList = hashTable[Hash(key)]
//   return ListSearch(bucketList, key)
// }

// MoviesHash
// Actor, Move1, Movie2, ...etc.
// Movie Array [] if not entered already

// movieArray[0]->actor->actor->actor

class Movie{
    private:
        string name;
        list<string> actors;
        list<string>::iterator itera;
    public:
        Movie(string movie){
            name = movie;
        };
        void SetMovie(string movie){
            name = movie;
            return;
        };
        string GetMovie(){
            return name;
        };
        void SetActor(string actor){
            actors.push_back(actor);
            return;
        };
        void PrintActors(){
            cout << "Movie: " << name << ". Actors: ";
            for(itera = actors.begin(); itera < actors.end(); ++itera){
                cout << *itera << " ";
            }
            cout << endl;
            return;
        };
};

//Have the array point to another 
int main(){
    
    //Starting the file stream.
    ifstream fin;
    //Opening the file.
    fin.open("movies.txt");
    
    //Checking to make sure the file opened.    
    if (!fin.is_open()){
        cout << "UnBle to open file." << endl;
    }
    
    //To create a list of movie objects.
    list<Movie> MovieDatabase;
    //An iterator to iterate through the list.
    list<Movie>::iterator iter;
    
    //To hold the file information
    string info;
    string actor;
    string movie;
    
    //Starting the string stream.
    istringstream ssin;
    
    //While it is not the end of the file,
    while(!fin.eof()){
        //Get the line and store the information in the variable info until the newline is hit.
        getline(fin, info, '\n');
        
        //Holding the information in the string stream to manipulate.
        ssin.str(info);
        ssin >> actor;
        while (ssin.str() != ""){
            ssin >> movie;
            for (iter = MovieDatabase.begin(); iter < MovieDatabase.end(); iter++){
                if (*iter == movie){
                    new Movie *m = *iter;
                    m.SetActor(actor);
                    
                } else {
                    MovieDatabase.push(new Movie *m(movie));
                    m.SetActor(actor);
                }
            }
        }
        
        
    }

}

