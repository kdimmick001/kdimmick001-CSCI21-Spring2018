#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std

class Animal{
    private:
        double reproduce_;
        bool die_;
    public:
        Animal();
};

class Rabbit:: public Animal{
    private:
        int max_food_capacity_ = 45;
        //metabolism rate = metabolism/age
        int metabolism_ = 3;
        int reproduction_age_ = 10;
        double reproduction_probability_ = 0.50;
        int min_food_reproduce_ = 40;
        int max_age_ = 25;
        int food_value_ = 10;
    
};

class Wolves:: public Animal{
    private:
        int max_food_capacity_ = 200;
        //metabolism rate = metabolism/age
        int metabolism_ = 2;
        int reproduction_age_ = 10;
        double reproduction_probability_ = 0.50;
        int min_food_reproduce_ = 120;
        int max_age_ = 50;
        
};