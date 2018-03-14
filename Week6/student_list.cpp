#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
    private:
        list<string> first_;
        list<string> last_;
    
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
  delete[] first_;
  delete[] last_;
};

void Student::SetFirst(string first){
    first_.push_back(first);
    return;
};

string Student::GetFirst(){
    return first_.back();
};

void Student::SetLast(string last){
    last_.push_back(last);
    return;
};

string Student::GetLast(){
    return last_.back();
};

Student operator <<(Student const &)
Student operator <(Student const &)

int main(){
    ifstream fin;
    fin.open("input.txt");
    if (!fin.is_open()){
        cout << "Unable to open file." << endl;
    }
    while (!fin.eof()){
        getline(fin, )
    }
    
}