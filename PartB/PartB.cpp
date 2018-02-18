#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

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

//A function that takes the valid card number from the credit card transaction and associates it with the proper account information
void AccountInfo::SetCardNum(int valid_transaction_location_){
    
    //A for loop to hold a constant transaction card number and compare it to a rotating account inventory.
    for (int account_location_ = 0; account_location_ < card_num_.size(); ++account_location_){
        if (CardTransaction::transaction_card_num_.at(valid_transaction_location_) == card_num_.at(account_location_)){
            
            SetBalance(account_location_); //To get the current balance to then call the GetBanace to return and save
            SetName(account_location_);
            
            //A loop to go through the transaction cards to find the same valid one.
            for(int i =0; i < CardTransaction::transaction_card_num_.size(); ++i){
                //Looks for same card number but not at the same location.
                if ((CardTransaction::transaction_card_num_.at(valid_transaction_location_) == CardTransaction::transaction_card_num_.at(i)) && (i != valid_transaction_location_)){
                    CardTransaction month;
                    month.SetMonth(valid_transaction_location_);
                    month.SetCompMonth(i);
                    //Checks to see if the transactions are in the same month.
                    if(CardTransaction::month_ == CardTransaction::comparison_month_){
                        double x;
                        x = CardTransaction::price_.at(i);
                        spent_ = spent_ + x;
                    }
                }
            }
            double y;
            y = CardTransaction::price_.at(valid_transaction_location_);
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
    cout << "Transaction Number: " << CardTransaction::transaction_num_.at(valid_transaction_location_) << " at " << CardTransaction::vendor_.at(valid_transaction_location_);
    cout << "*******************************************************************************************************************" << endl;
    
};

void AccountInfo::PrintValid(int valid_transaction_location_){
    
    cout << "*******************************************************************************************************************" << endl;
    cout <<"Credit Card Bill for " << frst_lst_name_ <<endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Transaction Number: " << CardTransaction::transaction_num_.at(valid_transaction_location_) << " at " << CardTransaction::vendor_.at(valid_transaction_location_);
    cout << " for $" << CardTransaction::price_.at(valid_transaction_location_) << endl;
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
    cout << "Transaction Number: " << CardTransaction::transaction_num_.at(valid_transaction_location_) << " at " << CardTransaction::vendor_.at(valid_transaction_location_);
    cout << " for $" << CardTransaction::price_.at(valid_transaction_location_) << endl;
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

//Print Function to Print if the card was invalid because it didn't pass the Luhn Algorithm.
void CardTransaction::PrintLuhn(int invalid_card_){
    
    cout << "Transaction Number: " << transaction_num_.at(i) << endl;
    cout << "On " << date_.at(i) << " was denied." << endl;
    cout << "Due to an invalid credit card number." << endl;
    
};

void CardTransaction::SetMonth(int valid_index_){
    
    //Gets the current valid card's month.
    //dummy variable to make the vector string into a substring.
    string x;
    
    x = date_.at(valid_index_);
    month_ = x.substr(0,2);
};

string CardTransaction::GetMonth(){
    return month_;
};

void CardTransaction::SetCompMonth(int index_){
    
    //Gets the current valid card's month.
    //dummy variable to make the vector string into a substring.
    string x;
    
    x = date_.at(index_);
    comparison_month_ = x.substr(0,2);
};

string CardTransaction::GetCompMonth(){
    return comparison_month_;
};

//Constructor
CardTransaction::CardTransaction(){
    //Creating an input stream
    ifstream fin;
    
    //To open a text file to get the string information.
    fin.open("transactioninfo.txt");
    
    //A check to make sure that the desired file opened.
    if(!fin.is_open()){
        
        cout << "Unable to open file." << endl;
        
    }
    
    //Dummy variables to hold the file inputted value to be included in the appropriate vector.
        
    //For transaction_card_num_
    string tc;
    //For date_
    string d;
    //For transaction_num_
    long long int tn;
    //For vendor_
    string v;
    //For price_
    double p;
    //Character deliminator for the getline function.
    char delim = ':';
    
    //While not end of the file.
    while (!fin.eof()){
        //Input the file values to each space in the appropriate private vector and ignore the subsequent space or separator.
        
        fin >> tc;
        transaction_card_num_.push_back(tc);
        fin.ignore(1, ':');
        
        getline(fin, d, delim);
        date_.push_back(d);
        fin.ignore(1, ':');
        
        fin >> tn;
        transaction_num_.push_back(tn);
        fin.ignore(1, ':');
        
        getline(fin, v, delim);
        vendor_.push_back(v);
        
        fin >> p;
        price_.push_back(p);
        fin.ignore(1, '\n');

    
    }
    
    fin.close();
    
};
class CardTypeGold {
    private:
        const int credit_line_ = 3000;
        int valid_;
        double rebate_;
        double percent_ = 0.01;
    public:
        void SetValid(double balance, double spent){
            if ((balance - spent) == (-credit_line_)){
                //Invalid
                valid_ = 1;
            } else {
                //Valid
                valid_ = 0;
            }
        }
        int GetValid(){
            return valid_;
        }
        void SetRebate(double monthPurch){
            rebate_ = monthPurch * percent_;
        }
        double GetRebate(){
            return rebate_;
        }
    
};

class CardTypePlat : public CardTypeGold {
    private:
        const int credit_line_ = 5000;
        int valid_;
        double rebate_;
        double percent_ = 0.02;
    public:
        void SetValid(double balance, double spent){
            if ((balance - spent) <= ((-credit_line_) - 1000)){
                //Valid with warning
                valid_ = 3;
            } else if ((balance - spent) > ((-credit_line_) - 1000)) {
                //Invalid
                valid_ = 1;
            } else {
                //Valid
                valid_ = 0;
            }
        };
        
};

class CardTypeCorp : public CardTypePlat {
    private: 
        const int credit_line_ = 10000;
        int valid_;
        double rebate_;
        double percent_ = 0.05;
    public:
        void SetValid(double balance, double spent){
            if ((balance - spent) <= ((-credit_line_) - 5000)){
                //Valid with warning
                valid_ = 3;
            } else if ((balance - spent) > ((-credit_line_) - 5000) {
                //Invalid
                valid_ = 1;
            } else {
                //Valid
                valid_ = 0;
            }
        };
    
};
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



int main() {
    
    AccountInfo visa;
    CardTransaction user;
    
}