#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;

#ifndef STRING_H
#define STRING_H

class String {
    private:
        string first_;
        int second_;
        String* next;
    public:
        //Constructor.
        String();
        //Overload constructor to input the associated values.
        String(string word, int weight);
        //Mutator for both the word and the weight.
        void AddWord(string word, int weight);
        //Accessor for the weight based on the prefix for word.
        int WeightIndex(string prefix);
        //Accessor for the string.
        string Word();
        //Accessor for the string prefix.
        string Prefix();
        //Function to put in ascending order by weight.
        virtual int AscendWeight();
        //Function to put in descending order by weight.
        virtual int DescendWeight();
        //Function to put prefix characters in ascending order.
        virtual string AscendPrefix();
    
};

//Constructor
String::String(){
    next = NULL;
};
//Overload constructor.
String::String(string word, int weight){
    first_ = word;
    second_ = weight;
    next = NULL;
};

//Mutator for both the word and the weight since they are both associated with one another done with the same mutator.
void String::AddWord(string word, int weight){
    first_ = word;
    second_ = weight;
    return;
};

//Accessor for the weight based on the prefix for word.
int String::WeightIndex(string prefix){
    //If the word was not long enough to make a prefix.
    if (prefix < 3){
        
    }
};

//Accessor for the string.
string String::Word(){
    return first;
};

//Accessor for the prefix of the string.
string String::Prefix(){
    //If the word is greater than or equal to 3 to make a prefix, return that prefix.
    if (first.size() >= 3){
        return first.substr(0, 3);
    //If the word is less than 3 to make a prefix, return the whole word.
    } else {
        return first;
    }
};


virtual int String::AscendWeight(){
    
};

virtual int String::DescendWeight(){
    
};

virtual int String::AscendPrefix(){
    
};

#endif