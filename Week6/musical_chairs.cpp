#include <string>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    
    stack <string> players_left;
    
    //Number of players for the game.
    int players = 0;
    //Player name.
    string name;
    //Chair number
    int chair_one = 0;
    
    cout << "Welcome to Musical Chairs." << endl;
    cout << "How many will be playing?"<< endl;
    cin >> players;
    cout << endl;
    for (int i = 0; i < players; ++i){
        cout << "Type the name of player " << (i + 1) << endl;
        cin >> name;
        players_left.push(name);
    }
    
    while (players_left.size() > 1){
        int i = 0;
        
        while (i != (players - 1)){
            players_left.swap((chair_one + i), ((players - 1) - i));
            ++i;
        }
        cout << players_left.top() << " is out." << endl;
        players_left.pop();
    }
    
    cout << players_left.top() << " is the winner!" << endl;
        
}