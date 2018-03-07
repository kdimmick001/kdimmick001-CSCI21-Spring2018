#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
    private:
        string first_;
        string last_;
    
    public:
        //Constructor.
        Student();
        //Deconstructor.
        ~Student();
        void SetFirst(string first);
        string GetFirst();
        void SetLast(string last);
        string GetLast();
        
};

Student:: Student(){
    first_ = "None";
    last_ = "Last";
};

Student:: ~Student(){
  delete [];  
};


int main(){
    
}