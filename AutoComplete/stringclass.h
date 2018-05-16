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
    
    public:
        //Constructor.
        String();
        //Function to put in ascending order by weight.
        virtual int AscendWeight();
        //Function to put in descending order by weight.
        virtual int DescendWeight();
        //Function to put prefix characters in ascending order.
        virtual string AscendPrefix();
    
};

//Constructor
String::String(){
    
};

virtual int String::AscendWeight(){
    
};

virtual int String::DescendWeight(){
    
};

virtual int String::AscendPrefix(){
    
};

#endif