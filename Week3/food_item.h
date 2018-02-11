/*
 * Name        : food_item.h
 * Author      : Kelsey Dimmick
 * Description : Class Header File
 */


#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std

class FoodItem {
    
    private:
        int calories_;
        string unit_of_measure_;
        double units_;
        string name_;
        int value_;
        
    public:
    //Constructor
    FoodItem(int calories, string unit_of_measure, double units, int value, name);
    //Deconstructor
    ~FoodItem();
    
    //Accessors and Mutators
    //Setter and Getter for Calories value
    void SetCalories(int calories);
    int GetCalories();
    //Setters and Getters for Unit of Measure
    void SetUom(string uom);
    string GetUom();
    //Setter and Getter for units
    void SetUnit(int unit);
    int GetUnit();
};

string ToString(const Money &name_, const Money &value_, const Money &units_, const Money &calories_);