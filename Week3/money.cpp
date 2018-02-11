#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

const Money operator -(const Money& amount1, const Money& amount2){
    //Calls an object (amount1 and amount2) to find the total cents for each
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    //To subtract the values
    int sub_all_cents = all_cents2 - all_cents1;
    //To make sure the value is not negative
    int abs_all_cents = abs(sub_all_cents);
    //Divide by 100 to get the whole dollar amount
    int final_dollars = abs_all_cents / 100;
    //Modulo by 100 to get the remaining cents from the whole dollar amount
    int final_cents = abs_all_cents % 100;
    //To change the initial subtraction value if negative
    if (sub_all_cents < 0) {
        final_dollars = -final_dollars;
        final_cents = -final_cents;
    }
    return Money(final_dollars, final_cents);
}

bool operator ==(const Money& amount1, const Money& amount2){
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    //Checking the comparison between the two amounts in terms of cents
    if (all_cents1 == all_cents2){
        return True;
    }else{
        return False;
    }
}
    
const Money operator -(const Money& amount){
    int all_cents = amount.cents_ + amount.dollars_ * 100;
    //Changes the amount in cents to a negative
    int neg_all_cents = (-all_cents);
    //Changes the cents back to dollars and cents
    int final_dollars = neg_all_cents / 100;
    int final_cents = neg_all_cents % 100;
    
    return Money(final_dollars, final_cents);
}
    
ostream& operator <<(ostream &out, const Money &amount){
    int all _cents = amount.cents_ + amount.dollars_ * 100;
    int final_dollars = all_cents / 100;
    int final_cents = all_cents % 100;
    setw(1);
    setfill($);
    out << final_dollars << "." << final_cents;
    return out;
    
    
}
    
    
    
}