#include "magic_item.h"

class MagicItem{
    private:
        string description_;
        int mana_required_;
        string name_;
        int value_;
        
    public:
    //Constructor
        MagicItem(string description = "no description", int mana_required = 0, string name = "magicitem", int value = 0){
            description_ = description;
            mana_required_ = mana_required;
            name_ = name;
            value_ = value;
        }
    //Deconstructor
        ~MagicItem(){
            
        }
    //Setters and Getters for description
    void SetDescription(string description){
        description_ = description;
    }
    string GetDescription(){
        return description_;
    }
    //Setters and Getters for mana required
    void SetManaRequired(int mana_required){
        mana_required_ = mana_required;
    }
    int GetManaRequired(){
        return mana_required_;
    }
    
};

string ToString(const MagicItem &description_, const MagicItem &mana_required_, const MagicItem &name_, const MagicItem &value_){
    stringstream ss;
    
    ss << name_ << ", $" << value_ << ", " << description_ << ", requires " << mana_required_ << " mana";
    
    return ss.str();
}