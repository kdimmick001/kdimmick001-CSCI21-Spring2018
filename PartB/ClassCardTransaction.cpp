#include "Class.h"
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