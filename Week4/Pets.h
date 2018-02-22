#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std

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