#include<string>
using std::string;

class Pet {
    public:
        //default constructor for pet that defaults all values to 0, false or blank.
        Pet();
        //write appropriate overloaded constructors
        void SetNeu(bool neu);
        bool GetNeu();
        void SetName(string name);
        string GetName();
        void SetSpecies(int species);
        int GetSpecies();
        void SetSound(bool sound);
        bool GetSound();
        //write get and set functions for each variable
        void print();

    protected:
        string name_;
        int species_;
        bool nueteredSpayed_;
        bool talks_;

};

Pet::Pet(){
    name_ = "blank";
    species_ = 0;
    nueteredSpayed_ = false;
    talks_ = false;
};

void Pet::SetName(string name){
    name_ = name;
    return;
};

string Pet::GetName(){
    return name_;
};

void Pet::SetSpecies(int species){
    species_ = species;
    return;
};

int Pet::GetSpecies(){
    return species_;
};

void Pet::SetNeu(bool neu){
    nueteredSpayed_ = neu;
    return;
}

bool Pet::GetNeu(){
    return nueteredSpayed_;
};

void Pet::SetSound(bool sound){
    talks_ = sound;
    return;
};

void Pet::print(){
    if (name_ != "blank"){
        cout << "Pet: " << name_ << endl;
    }
    if (species_ != 0 ){
        cout << "How many species: " << species_ << endl;
    }
    cout << "Neutered?: " << nueteredSpayed_ << endl;
    cout << "Talks?: " << talks_ << endl;

}

bool Pet::GetSound(){
    return talks_;
};

class Dog : public Pet{
    public:
        Dog();
        void print();
    
};

Dog::Dog(){
    name_ = "blank";
    species_ = 0;
    nueteredSpayed_ = false;
    talks_ = false;
};

void Dog::print(){
    if (name_ != "blank"){
        cout << "Dog: " << name_ << endl;
    }
    if (species_ != 0 ){
        cout << "How many species: " << species_ << endl;
    }
    cout << "Neutered?: " << nueteredSpayed_ << endl;
    cout << "Talks?: " << talks_ << endl;
};


class Cat : public Pet{
    public:
        Cat();
        void print();
    
};

Cat::Cat(){
    name_ = "blank";
    species_ = 0;
    nueteredSpayed_ = false;
    talks_ = false;
};

void Cat::print(){
    if (name_ != "blank"){
        cout << "Cat: " << name_ << endl;
    }
    if (species_ != 0 ){
        cout << "How many species: " << species_ << endl;
    }
    cout << "Neutered?: " << nueteredSpayed_ << endl;
    cout << "Talks?: " << talks_ << endl;
};

class Bird : public Pet{
    public:
        Bird();
        void print();
};

Bird::Bird(){
    name_ = "blank";
    species_ = 0;
    nueteredSpayed_ = false;
    talks_ = false;
};

void Bird::print(){
    if (name_ != "blank"){
        cout << "Bird: " << name_ << endl;
    }
    if (species_ != 0 ){
        cout << "How many species: " << species_ << endl;
    }
    cout << "Neutered?: " << nueteredSpayed_ << endl;
    cout << "Talks?: " << talks_ << endl;
};

int main(){
    Bird canary;
    
    canary.SetName("Tweety");
    canary.SetSound(true);
    
    Cat black;
    
    black.SetName("Sylvester");
    black.SetNeu(true);
    
    Dog super;
    
    super.SetName("Krypto");
    black.SetNeu(false);
    
}