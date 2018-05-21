#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//Returns the number of moves.
int hanoi(int disks){
    //2^n - 1
//     int moves = 1;
//     while (disks != 0){
//         moves = moves * 2;
//         hanoi(disks - 1);
//     }
//     return (moves-1);
    
// };
    //int moves;
    //int count = 0;
    if (disks == 0){
        return 1;
    } else {
        //++count;
        return (2* hanoi(disks - 1));
    }

};

//Returns the greatest common divisor of the two numbers.
int gcd(int number_a, int number_b){
    if (number_a == 0){
        return number_b;
    } else {
        return gcd(number_b % number_a, number_a);
    }
};

//Returns the least common divisor of the two numbers.
int lcd(int number_a, int number_b){
    int gcd_value;
    gcd_value = gcd(number_a, number_b);
    return ((number_a * number_b) / gcd_value);
};

//Returns true is correct and false if incorrect guess.
bool door(int guess){
    int correct;
    correct = (rand() % 3) + 1;
    if (guess != correct){
        return false;
    } else {
        return true;
    }
};

//Outputs all evens of the inputted number.
void evens(int number){
    //Number is even.
    if (number % 2 == 0){
        if (number >= 0){
            cout << number << " ";
            evens(number - 2);
        }
        
    } else if ((number % 2 != 0) && (number != 0)){
        evens(number - 1);
    }
    
    return;
};


int main(){
    cout << "Door Guess: " << door(2) << endl;
    cout << "GCD Number: " << gcd(10, 18) << endl;
    cout << "LCD Number: " << lcd(3, 19) << endl;
    cout << "Evens Output: " << endl;
    evens(3);
    cout << endl;
    cout << "Hanoi Moves: " << hanoi(3) << endl;
    
}