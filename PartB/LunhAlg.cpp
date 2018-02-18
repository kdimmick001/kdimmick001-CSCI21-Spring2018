#include "Class.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

//A function to run the Luhn Algorithm on the card number information that has the parameter of the card number as a pass by reference.
int LuhnAlg(string& card_){
    
    //Creates needed variables to perform the Luhn algorithm.
    int last= 0;
    int total = 0;
    int digit;

    //Sets the last variable to the size of the total card number.
    last = card_.size();

    //A loop adding every other card number that doesn't need to be doubled first to the total accounting for the ascii number change to integer.
    for (int i = (last - 1); i >= 0; (i = i-2)){

        total = total + (card_[i] - 48);
    }
    //A loop looking at the other numbers not added to the total and doubling each one.
    for (int i = (last - 2); i >= 0; (i = i-2)){
  
        digit = (card_[i] -48);
        digit = (digit) * 2; 

        //An if statement checking if the digit is a double digit number and if so adding them separately.
        if (digit >= 10){
            
            digit = (digit - 10) + 1;
        }

        //Adding the total digit amounts.
        total = total + digit;
    }
    
    //Checking if the total amount is divisible by 10 and if it is a valid credit card number.
    if (total % 10 == 0) {
        //Valid Credit card number is 0 and invalid will return as 1.
        return 0;
    }
    else {
        return 1;
    }

}