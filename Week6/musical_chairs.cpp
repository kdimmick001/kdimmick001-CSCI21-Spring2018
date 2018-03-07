#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    list<string> chairs;
    
    //Number of players for the game.
    int players = 0;
    //Player name.
    string name;
    
    cout << "Welcome to Musical Chairs." << endl;
    cout << "How many will be playing?"<< endl;
    cin >> players;
    cout << endl;
    for (int i = 0; i < players; ++i){
        cout << "Type the name of player " << (i + 1) << endl;
        cin >> name;
        chairs.push_back(name);
    }
    
    
}