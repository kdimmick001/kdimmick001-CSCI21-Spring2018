#include "Class.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;


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
        double spent_;
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

//A function that takes the valid card number from the credit card transaction and associates it with the proper account information
void AccountInfo::SetCardNum(int valid_transaction_location_){
    
    //A for loop to hold a constant transaction card number and compare it to a rotating account inventory.
    for (int account_location_ = 0; account_location_ < card_num_.size(); ++account_location_){
        if (CardTransaction::transaction_card_num_.at(valid_transaction_location_) == card_num_.at(account_location_)){
            
            SetBalance(account_location_); //To get the current balance to then call the GetBanace to return and save
            SetName(account_location_);
            
            //A loop to go through the transaction cards to find the same valid one.
            for(int i =0; i < transaction_card_num_.size(); ++i){
                //Looks for same card number but not at the same location.
                if ((transaction_card_num_.at(valid_transaction_location_) == transaction_card_num_.at(i)) && (i != valid_transaction_location_)){
                    SetMonth(valid_transaction_location_);
                    SetCompMonth(i);
                    //Checks to see if the transactions are in the same month.
                    if(month_ == comparison_month_){
                        double x;
                        x = price_.at(i);
                        spent_ = spent_ + x;
                    }
                }
            }
            double y;
            y = price_.at(valid_transaction_location_);
            spent_ = spent_ + y; 
            
            SetCardTypeValid(valid_transaction_location_);
        }
            
    }
};

void AccountInfo::SetBalance(int account_location_){
    
    curr_balance_ = balance_.at(account_location_);
    
};

double AccountInfo::GetBalance(){
    return curr_balance_;
};

void AccountInfo::SetName(int account_location_){
    //Dummy variables
    string x;
    string y;
    
    x = name_.at(account_location_) + " ";
    y = name_.at(account_location_ + 1);
    
    frst_lst_name_ = x + y;
};

string AccountInfo::GetName(){
    return frst_lst_name_;
};

void AccountInfo::SetCardTypeValid(int valid_transaction_location_){
    //Declaring a variable to return if the card is valid due to credit card limits
    int valid_;
    
    //if curr_balance_ - spent_ == -max...card restrictions may apply
            if ((type_.at(valid_transaction_location_) == "gold") || (type_.at(valid_transaction_location_) == "Gold"){
                CardTypeGold gold;
                gold.SetValid(curr_balance_, spent_);
                valid_ = gold.GetValid;
                //If Valid
                if (valid_ == 0){
                    gold.SetRebate(spent_);
                    rebate_ = GetRebate();
                    balance_.at(account_location_) = (rebate_) + (curr_balance_ - spent_);
                    SetBalance(account_location_);
                    PrintValid(valid_transaction_location_);
                } else {
                    PrintInvalid(valid_transaction_location_); //To print out which transaction is invalid
                }
            }
            if ((type_.at(valid_transaction_location_) == "corporate") || (type_.at(valid_transaction_location_) == "Corporate"){
                CardTypeCorp corp;
                corp.SetValid(curr_balance_, spent_);
                valid_ = corp.GetValid;
                //If Valid
                if (valid_ == 0){
                    corp.SetRebate(spent_);
                    rebate_ = corp.GetRebate();
                    balance_.at(account_location_) = (rebate_) + (curr_balance_ - spent_);
                    SetBalance(account_location_);
                    PrintValid(valid_transaction_location_);
                }
                //Warning message but valid
                if (valid_ == 3){
                    corp.SetRebate(spent_);
                    rebate_ = corp.GetRebate();
                    balance_.at(account_location_) = (rebate_) + (curr_balance_ - spent_);
                    SetBalance(account_location_);
                    PrintWarning(valid_transaction_location_);
                } else {
                    PrintInvalid(valid_transaction_location_); //To print out which transaction is invalid
                }
            }
            if ((type_.at(valid_transaction_location_) == "platinum") || (type_.at(valid_transaction_location_) == "Platinum"){
                CardTypePlat plat;
                plat.SetValid(curr_balance_, spent_);
                valid_ = plat.GetValid();
                //If Valid
                if (valid_ == 0){
                    plat.SetRebate(spent_);
                    rebate_ = plat.GetRebate();
                    balance_.at(account_location_) = (rebate_) + (curr_balance_ - spent_);
                    SetBalance(account_location_);
                    PrintValid(valid_transaction_location_);
                }
                //Warning message but valid
                if (valid_ == 3){
                    plat.SetRebate(spent_);
                    rebate_ = plat.GetRebate();
                    balance_.at(account_location_) = (rebate_) + (curr_balance_ - spent_);
                    SetBalance(account_location_);
                    PrintWarning(valid_transaction_location_);
                } else {
                    PrintInvalid(valid_transaction_location_); //To print out which transaction is invalid
                }
                
            }
};

void AccountInfo::PrintInvalid(int valid_transaction_location_){
    
    cout << "*******************************************************************************************************************" << endl;
    cout << frst_lst_name_ << "'s credit card has been denied due to it being overdrawn from: " << endl;
    cout << "Transaction Number: " << transaction_num_.at(valid_transaction_location_) << " at " << vendor_.at(valid_transaction_location_);
    cout << "*******************************************************************************************************************" << endl;
    
};

void AccountInfo::PrintValid(int valid_transaction_location_){
    
    cout << "*******************************************************************************************************************" << endl;
    cout <<"Credit Card Bill for " << frst_lst_name_ <<endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Transaction Number: " << transaction_num_.at(valid_transaction_location_) << " at " << vendor_.at(valid_transaction_location_);
    cout << " for $" << price_.at(valid_transaction_location_) << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Current Balance: $" << curr_balance_ << endl;
    cout << "Rebate Value: $" << rebate_ << endl;
    cout << "*******************************************************************************************************************" << endl;
    
};

void AccountInfo::PrintWarning(int valid_transaction_location_){
    
    cout << "*******************************************************************************************************************" << endl;
    cout <<"Credit Card Bill for " << frst_lst_name_ <<endl;
    cout << "!!WARNING!!" << " YOU ARE $" << (curr_balance_ - spent_) << " OVERDRAWN!" <<endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Transaction Number: " << transaction_num_.at(valid_transaction_location_) << " at " << vendor_.at(valid_transaction_location_);
    cout << " for $" << price_.at(valid_transaction_location_) << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Current Balance: $" << curr_balance_ << endl;
    cout << "Rebate Value: $" << rebate_ << endl;
    cout << "*******************************************************************************************************************" << endl;
};

//Constructor
AccountInfo::AccountInfo(){
    //Creating an input stream
    ifstream fin;
    
    //To open a text file to get the string information.
    fin.open("accountinfo.txt");
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    
    //Dummy variables to hold the file inputted value to be included in the appropriate vector.
        
    //For card_num_
    string c;
    //For name_
    string n;
    //For type_
    string t;
    //For balance_
    double b;
    
    //While not end of the file.
    while (!fin.eof()){
        
        //Input the file values to each space in the appropriate private vector and ignore the subsequent space or separator.
        fin >> c;
        card_num_.push_back(c);
        fin.ignore(1, ' ');
        
        fin >> n;
        name_.push_back(n);
        fin.ignore(1, ' ');
        fin >> n;
        name_.push_back(n);
        fin.ignore(1, ' ');
        
        fin >> t;
        type_.push_back(t);
        fin.ignore(1, ' ');
        
        fin >> b;
        balance_.push_back(b);
        fin.ignore(1, '\n');
        
    }
    fin.close();
        

};