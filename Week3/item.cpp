#include "item.h"

class Item {
    private:
        string name_;
        int value_;
    
    public:
        //Constructor
        Item (string name = "item", int value = 0){
            name_ = name;
            value_ = value;
        }
        //Deconstructor
        ~Item(){
            
        }
        //Accessors and Mutators
        void SetName(string name){
            name_ = name;
        }
        string GetName(){
            return name_;
        }
        void SetValue(int value){
            value_ = value;
        }
        int GetValue(){
            return value_;
        }
}

string ToString(string name, int value){
    
    stringstream ss;
    
    ss << name << ", $" << value;
    
    return ss.str();
    
}