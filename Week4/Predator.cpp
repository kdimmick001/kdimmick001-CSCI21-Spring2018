#include "Predator.h"

class Animal{
    private:
        double reproduce_;
        bool die_;
    public:
        Animal();
};

Animal::Animal(){
    reproduce_ = 0;
    die_ = 0;
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

int main(){
    //Making an array grass field.
    int grass[30][30];
    
    //Setting all the sections to 0, 0}
    int i = 0;
    for (int x = 0; x < 30; ++x){
    while (i < 30){
        grass[x][i] = 0;
        ++i;
    }
    }
    
    Wolves wolf_11;
    Wolves wolf_12;
    Wolves wolf_13;
    
    Rabbit rabbit_1;
    Rabbit rabbit_2;
    Rabbit rabbit_3;
    Rabbit rabbit_4;
    Rabbit rabbit_5;
    
    srand(time(0));
    int x;
    int y;
    //To randomly occupy the grass with rabbits
    for (i = 1; i < 6; ++i){
        x = rand() % 30;
        y = rand() % 30;
        if (grass[x][y] == 0){
            grass[x][y] = i;
        } else {
            x = rand() % 30;
            y = rand() % 30;
            if (grass[x][y] == 0){
                grass[x][y] = i;
            }
        }
    }
    //To randomly occupy the grass with wolves
    for (i = 11; i < 14; ++i){
        x = rand() % 30;
        y = rand() % 30;
        if ((grass[x][y] == 0){
            grass[x][y] = i;
        } else {
            x = rand() % 30;
            y = rand() % 30;
            if (grass[x][y] == 0){
                grass[x][y] = i;
            }
        }
    }
    
    //random movement for rabbits
    for ()
    //To generate random diagonal movement.
    int randNum = rand()% 1 + (-1);
    
    
}