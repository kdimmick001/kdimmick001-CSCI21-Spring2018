#include "Class.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;


class CardTypeGold {
    private:
        const int credit_line_ = 3000;
        int valid_;
        double rebate_;
        double percent_ = 0.01;
    public:
        void SetValid(double balance, double spent){
            if ((balance - spent) = (-credit_line_)){
                //Invalid
                valid_ = 1;
            } else {
                //Valid
                valid_ = 0;
            }
        }
        int GetValid(){
            return valid_;
        }
        void SetRebate(double monthPurch){
            rebate_ = monthPurch * percent_;
        }
        double GetRebate(){
            return rebate_;
        }
    
};

class CardTypePlat : public CardTypeGold {
    private:
        const int credit_line_ = 5000;
        int valid_;
        double rebate_;
        double percent_ = 0.02;
    public:
        void SetValid(double balance, double spent){
            if ((balance - spent) <= ((-credit_line_) - 1000)){
                //Valid with warning
                valid_ = 3;
            } else if ((balance - spent) > ((-credit_line_) - 1000) {
                //Invalid
                valid_ = 1;
            } else {
                //Valid
                valid_ = 0;
            }
        }
        
};

class CardTypeCorp : public CardTypePlat {
    private: 
        const int credit_line_ = 10000;
        int valid_;
        double rebate_;
        double percent_ = 0.05;
    public:
        void SetValid(double balance, double spent){
            if ((balance - spent) <= ((-credit_line_) - 5000)){
                //Valid with warning
                valid_ = 3;
            } else if ((balance - spent) > ((-credit_line_) - 5000) {
                //Invalid
                valid_ = 1;
            } else {
                //Valid
                valid_ = 0;
            }
        }
    
};