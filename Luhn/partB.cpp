#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


struct CreditCardInfo{
    
    int cardNum;
    string firstName;
    string lastName;
    string cardType;
    double currBalance;
    
};

struct CardTransaction{
    
    int cardNumTrans;
    string tactDate;
    int tactNum;
    string vendor;
    double price;
    
};

//A function to run the Luhn Algorithm on the card number information that has the parameter of the card number as a pass by reference.
template <typename Type>
Type Luhn(Type& card_){
    
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

class CardTypeGold {
    private:
        int credit_line_ = 3000;
        int valid_;
        double rebate_;
    public:
        void SetValid(vector<CreditCardInfo> &transactionList, int currBalance){
            int x;
            x = Luhn(transactionList);
            if (x == 0){
                currBalance >= credit_line_;
                //Not valid.
                valid_ = 1;
            } else {
                //Valid.
                valid_ = 0;
            }
        }
        int GetValid(){
            return valid_;
        }
        void SetRebate(int monthPurch){
            rebate_ = monthPurch * 0.01;
        }
        double GetRebate(){
            return rebate_;
        }
    
};

class CardTypePlat : public CardTypeGold {
    private:
        int credit_line_ = 5000;
        int valid_;
        double rebate_;
    public:
        void SetValid(vector<struct> &transactionList, int currBalance){
            int x;
            x = Luhn(transactionList);
            if (x == 0){
                if ((currBalance > credit_line_) && (currBalance <= (credit_line_ + 1000))){
                    PrintWarn();
                    valid_ = 0;
                }
                if (currBalance > (credit_line_ + 1000)){
                    //Not valid.
                    valid_ = 1;
                }
                if (currBalance <= credit_line_) {
                    //Valid
                    valid_ = 0;
                }
            }
        }
        int GetValid(){
            return valid_;
        }        
        void SetRebate(int monthPurch){
            rebate_ = monthPurch * 0.02;
        }
        double GetRebate(){
            return rebate_;
        }
        void PrintWarn(){
            cout << "Warning you are overdrawn by: $" << (currBalance - credit_line_) << endl;
        }
};

class CardTypeCorp : public CardTypePlat {
    private: 
        int credit_line_ = 10000;
        int valid_;
        double rebate_;
    public:
        void SetValid(vector<struct> &transactionList, int currBalance){
            int x;
            x = Luhn(transactionList);
            if (x == 0){
                if ((currBalance > credit_line_) && (currBalance <= (credit_line_ + 5000))){
                    PrintWarn();
                    valid_ = 0;
                }
                if (currBalance > (credit_line_ + 5000)){
                    //Not valid.
                    valid_ = 1;
                }
                if (currBalance <= credit_line_) {
                    //Valid
                    valid_ = 0;
                }
            }
        }
        int GetValid(){
            return valid_;
        }        
        void SetRebate(int monthPurch){
            rebate_ = monthPurch * 0.05;
        }
        double GetRebate(){
            return rebate_;
        }
        void PrintWarn(){
            cout << "Warning you are overdrawn by: $" << (currBalance - credit_line_) << endl;
        }
    
};

int main(){
    ifstream fin;
    
    vector<CreditCardInfo> accountList();
    vector<CardTransaction> transactionList();
    
    fin.open("file1.txt");
    
    if(!fin.is_open){
        cout << "Unable to open the first file." << endl;
    }
    
    while(!fin.eof()){
        
        int i = 0;
        getline(fin, accountList.at(i).cardNum, ' ');
        accountList.push_back(':').cardNum;
        fin.ignore(1, ' ');
        
        getline(fin, accountList.at(i).firstName, ' ');
        accountList.push_back(':').firstName;
        fin.ignore(1, ' ');
        
        getline(fin, accountList.at(i).lastName, ' ');
        accountList.push_back(':').lastName;
        fin.ignore(1, ' ');
        
        getline(fin, accountList.at(i).cardType, ' ');
        accountList.push_back(':').cardType;
        fin.ignore(1, '-');
        fin.ignore(1, ' ');
        
        getline(fin, accountList.at(i).currBalance, '\n')
        accountList.push_back(':').currBalance;
        fin.ignore(100, '\n');
        
        ++i;
        
    }
    
    fin.close();
    
    ifstream fin;
    
    fin.open("file2.txt");
    
    if(!fin.is_open){
        cout << "Unable to open the first file." << endl;
    }   
    
    while(!fin.eof()){
        int i = 0;
        getline(fin, transactionList.at(i).cardNumTrans, ':');
        transactionList.push_back(':'). cardNumTrans;
        fin.ignore(1, ':');

        if (Luhn(transactionList.at(i).cardNumTrans) == 0){
            cout << "The card is Valid: " << transactionList.at(i).cardNumTrans << endl;
        } else if (Luhn(transactionList.at(i).cardNumTrans) == 1){
            cout << "The card is invalid: " << transactionList.at(i).cardNumTrans << endl;
        }
        
        getline(fin, transactionList.at(i).tactDate, ':');
        transactionList.push_back(':').tactDate;
        fin.ignore(1, ':');
        
        getline(fin, transactionList.at(i).tactNum, ':');
        transactionList.push_back(':').tactNum;
        fin.ignore(1, ':');
    
        getline(fin, transactionList.at(i).vendor, ':');
        transactionList.push_back(':').vendor;
        fin.ignore(1, ':');
        
        getline(fin, transactionList.at(i), '\n');
        transactionList.push_back(':').price;
        fin.ignore(100, '\n');
        
        ++i;
    }
    
    fin.close();
    
    
}