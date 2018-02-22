/*
* Name          : lab_4.cpp
* Author        : Kelsey Dimmick
* Description   : Using branching statements, looping statements and string
*                   and character functions to complete the functions
*/

#include "lab_4.h"

string MakeString(string label, double value, char separator) {
    
    stringstream ss;
    
    ss >> label >> separator >> value;
    
    string info;
    
    info = ss.str();
    
    return info;
    
};

char StringToChar(string value) {
    
    char value_[1];
    
    if ((value.length() == 0) || (value.length() < 0)) {
        return '\0';
    } else{
        value_[0] = value[1];
        
        return value_[0];
    
    }
};

int StringToInt(string value){
    int ivalue = 0;
    stringstream converter(value);
    converter.exceptions(ios_base::failbit);
    
    try {
        converter >> ivalue;
    } catch (ios_base::failure f){
    }
    return ivalue;
};

double StringToDouble(string value){
    double ivalue = 0;
    stringstream converter(value);
    converter.exceptions(ios_base::failbit);
    
    try {
        converter >> ivalue;
    } catch (ios_base::failure f){
        
    }
    
    return ivalue;
};

bool StringToBool(string value) {
    bool ivalue = false;
    stringstream converter(value);
    converter.exceptions(ios_base::failbit);
    
    try {
        converter >> ivalue;
    } catch (ios_base:: failure f){
    
    }
    
    return ivalue;

};