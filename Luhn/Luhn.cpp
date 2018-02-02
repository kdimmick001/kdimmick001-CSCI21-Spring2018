#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

/* 
Header Comments
Name: Kelsey Dimmick
Date: 02/01/2018
Description: A program that makes use of the Luhn Algorithm.
This program will determine the validity of credit cards.
As well as, if they belong to major companies.
*/

//A function to run the Luhn Algorithm on the card number information that has the parameter of the card number as a pass by reference.
int Luhn(string& card_){
    
    //Creates needed variables to perform the Luhn algorithm.
    int last= 0;
    int total = 0;
    int digit;
    int valid;
    
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
        valid = 0;
    }
    else {
        valid = 1;
    }

    return valid;
}

//Class to hold all the card information.
class CardCheck {
    
    private:
        //Creating a private string to hold the card information.
        string card_;
    
        //Variable to store the Luhn Algorithm answer.
        int luhn_ans_;
        
        //Creating a string input stream.
        istringstream ss;
        
        //Initializer variable.
        int i = 0;
        
        //Buffer variable to transfer over to the stringstream.
        string line;
        
        //To return the type of card.
        int bin = 0;

    public:
        //A function to get the string stream from the text file.
        void SetString(ifstream& fin){

            //Allocating the values from the text file to the stringstream ss and storing into the string.
                getline(fin, line);
                ss.str(line);
        }
        //A function that will store one card number in the string card_.
        string GetString(){
            //Stores the string stream string into card_.
            card_ = ss.str();
        
            //Returns the value of card_.
             return card_;
        }
        //Calls to the Luhn algorithm function using the card information this will return a 0 if card is valid and a 1 if invalid.
        void SetCard(){
            
            //Stores the return from the Luhn Algorithm.    
            luhn_ans_ = Luhn(card_);
        }
        //Returns the Luhn Algorithm answer.
        int GetCard(){
            
            return luhn_ans_;
            
        }
        //To find out what Credit Card Company the card is from.
        void SetBin(int v){
            if (v == 0){
                if ((card_.substr(0,2) == "34") || (card_.substr(0,2) == "37")){
                    //The Credit Card is American Express
                    bin = 1;
                }
                else if (((card_.substr(0,2)) <= "55") && ((card_.substr(0,2) >= "51"))){
                    //The Credit Card is MasterCard
                    bin = 2;
                }
                else if ((card_.substr(0,1)) == "4"){
                    //The Credit Card is Visa
                    bin = 3;
                }
                else if (((card_.substr(0,4)) == "6011") || (((card_.substr(0,6)) <= "622925") && ((card_.substr(0,6)) >= "622126")) || ((card_.substr(0,1)) == "65") || (((card_.substr(0,3)) <= "649" && ((card_.substr(0,3)) >="644")))){
                    //The Credit Card is Discover
                    bin = 4;
                }
                else{
                    //Unknown Card Type
                    bin = 0;
                }
        
            }
        }
        //A function that returns what Credit Card Company the card is from.
        int GetBin(){
            
            return bin;
        }
        
};



//Main function to facilitate the other function and class.
int main() {
    
    //Creating an object card from the class CardCheck.
    CardCheck card;
    
    //Integer to hold the validity of the card.
    int v;
    
    //Integer to hold the bin company relation.
    int bin;
    
    //Begins the file stream.
    ifstream fin;
    
    //Opening the credit card text file.
    fin.open("ccard.txt");
    
    //Checking to see if the credit card file is open.
    if(!fin.is_open()) {
        
        cout << "Unable to open file." << endl;
    }
    //While the end of the file has not been reached run through the steps for the Luhn Algorithm.
    while(!fin.eof()){
        //Calls upon each of the class functions in order.
        card.SetString(fin);
        
        //Outputs the card number in question.
        cout << "Card #: " << card.GetString() << endl;
        
        card.SetCard();

        //Stores the card validity in the variable v.
        v = card.GetCard();
        
        //Outputs if the card is valid or not.
        if (v == 0){
            cout << "Valid Credit Card." << endl;
        }else {
            cout << "Invalid Credit Card." << endl;
        }
        
        //Uses the validity to call upon the SetBin to find out what credit card company the card is from.
        card.SetBin(v);
        //Stores the credit card company name in the bin variable to differentiate between.
        bin = card.GetBin();
    
        if(bin == 1){
            cout << "The Credit Card is American Express." << endl;
        }
        else if (bin == 2){
            cout << "The Credit Card is MasterCard." << endl;
        }
        else if (bin == 3){
            cout << "The Credit Card is Visa." << endl;
        }
        else if (bin == 4){
            cout << "The Credit Card is Discover." << endl;
        }
        else {
            cout << "Unknown Card Type." << endl;
        }
        
        cout << "=======================================" << endl;
}

//Closes the file input.
fin.close();

}
