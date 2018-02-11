#include "food_item.h"

class FoodItem {
    
    private:
        int calories_;
        string unit_of_measure_;
        double units_;
        string name_;
        int value_;
        
    public:
    //Constructor
    FoodItem(int calories = 0, string unit_of_measure = "nounits", double units = 0, int value = 0, name = "fooditem"){
        calories_ = calories;
        unit_of_measure_ = unit_of_measure;
        units_ = units;
        value_ = value;
        name_ = name;
    }
    //Deconstructor
    ~FoodItem(){
        
    }
    //Accessors and Mutators
    //Setter and Getter for Calories value
    void SetCalories(int calories){
        calories_ = calories;
    }
    int GetCalories(){
        return calories_;
    }
    //Setters and Getters for Unit of Measure
    void SetUom(string uom){
        unit_of_measure_ = uom;
        
    }
    string GetUom(){
        return unit_of_measure;
    }
    //Setter and Getter for units
    void SetUnit(int unit){
        units_ = unit;
    }
    int GetUnit(){
        return units_;
    }
};

string ToString(const Money &name_, const Money &value_, const Money &units_, const Money &calories_){
    
    stringstream ss;
    
    ss << fixed << setprecision(2) << showpoint;
    ss << name_ << ", " << "$" << value_ << ", " << units_ << ", " << calories_ << " calories";
    
    return ss.str();
}