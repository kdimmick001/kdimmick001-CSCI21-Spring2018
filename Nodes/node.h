#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
    private:
        string thing;
        Node* next; //Points to the next element of the 
        
    public:
        Node();
};

#endif