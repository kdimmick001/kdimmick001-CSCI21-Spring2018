#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

//header file for all classes and functions

/*
    Kelsey Dimmick
    02/14/2018
    A program to track credit card expenses.
*/

class AccountInfo {
    private:
        //Creating private vectors to hold the card account information.
        //Vector to hold the card number.
        vector<string> card_num_;
        //Vector to hold the card holder's name (first+last)
        vector<string> name_;
        //Vector to hold the card type (g=gold, p=platinum, c=corporate).
        vector<string> type_;
        //Vector to hold the current credit card balance. (- means overdrawn).
        vector<double> balance_;
        //Variables to hold the relevant card information for valid card numbers
        double curr_balance_;
        //A string that holds the first and last name of the account holder.
        string frst_lst_name_;
        //How much was spent for a month.
        double spent_
        //Amount of rebate for the month.
        double rebate_;

    
    public:
        //Constructor to start the file input and fill the vectors automatically with the file input that then the class can manipulate.
        AccountInfo();
        //If card number from account vector equals the same as from transaction vector
        void SetCardNum(int valid_transaction_location_);
        //If the last is true take that item location and get the name
        void SetName(int account_location_);
        //return the name
        string GetName();
        //If the Set proves true get the card tyoe from the item location
        void SetCardTypeValid(int valid_transaction_location_);
        //Get balance if above is true and compare with friend class
        void SetBalance(int account_location_);
        //If does apply get the new balance number
        double GetBalance();
        //Print Functions to print out the various account information based upon the credit limits
        void PrintValid(int valid_transaction_location_);
        void PrintInvalid(int valid_transaction_location_);
        void PrintWarning(int valid_transaction_location_);
        
};

//
class CardTransaction : public AccountInfo {
    private:
        //Creating all the necessary vectors to store the file input into in the constructor.
        vector<string> transaction_card_num_;
        vector<string> date_;
        vector<long long int> transaction_num_;
        vector<string> vendor_;
        vector<double> price_;
        
        string month_;
        string comparison_month_;
        //Creating a friend class so AccountInfo can access the private members of CardTransaction.
        friend class AccountInfo;
        
    public:
        //Constructor
        CardTransaction();
        void TransactionCardNum();
        void PrintLuhn(int invalid_card_);
        void SetMonth(int valid_index_);
        string GetMonth();
        void SetCompMonth(int index_);
        string GetCompMonth();
        
};

//A function to check the Transaction Credit Card Number to make sure the Card Number is valid.
void CardTransaction::TransactionCardNum(){
    //To loop through to check for validity
    for (int i = 0; i < transaction_card_num_.size(); ++i){
        //First test if valid card number.
        if(LuhnAlg(transaction_card_num_.at(i)) == 0){
            //Use the valid card number to call the function to find the associated account information.
            SetCardNum(i);
            SetMonth(i);
        //Test for if the Luhn Algorithm failed.
        } else if (LuhnAlg(transaction_card_num_.at(i)) == 1){
            //Goes to the print function to tell why it failed.
            PrintLuhn(i);
        }
    }
};

class CardTypeGold {
    private:
        const int credit_line_ = 3000;
        int valid_;
        double rebate_;
    public:
        void SetValid(double balance, double spent);
        int GetValid();
        void SetRebate(double monthPurch);
        double GetRebate();
    
};

class CardTypePlat : public CardTypeGold {
    private:
        const int credit_line_ = 5000;
        int valid_;
        double rebate_;
    public:
        void SetValid(double balance, double spent);
        int GetValid();
        void SetRebate(double monthPurch);
        double GetRebate();
};

class CardTypeCorp : public CardTypePlat {
    private: 
        const int credit_line_ = 10000;
        int valid_;
        double rebate_;
    public:
        void SetValid(double balance, double spent);
        int GetValid();
        void SetRebate(double monthPurch);
        double GetRebate();
    
};

//A function to run the Luhn Algorithm on the card number information that has the parameter of the card number as a pass by reference.
int LuhnAlg(string& card_);
