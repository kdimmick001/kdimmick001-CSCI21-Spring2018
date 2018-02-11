/*
 * Name        : item.h
 * Author      : Kelsey Dimmick
 * Description : Class Header File
 */


#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std


class Item {
    
    private:
        string name_;
        int value_;
    
    public:
        //Constructor
        Item (string name, int value);
        //Deconstructor
        ~Item();
        //Accessors and Mutators
        //To get and set the name
        void SetName(string name);
        string GetName();
        //To get and set the value
        void SetValue(int value);
        int GetValue();
        
};

string ToString(string name, int value);