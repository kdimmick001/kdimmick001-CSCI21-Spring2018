#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

#ifndef NODE_H
#define NODE_H

template<typename DT>
class Node {
    private:
        DT thing_;
        Node *next; //Points to the next object from the Node class.
        Node *previous; //Points to the previous object from the Node class.
        Node *last; //Points to the last object.
        Node *first; // Points to the first object.
        
    public:
        //Constructor to set the pointer.
        Node();
        //To set the information being held in the object.
        void set_contents(DT info);
        //To get the information being held in the object.
        DT contents();
        //To set the next node pointer to the next spot. As well as the previous to the previous spot.
        void set_next_node(Node *node2);
        //Returns the next node object pointer.
        Node get_next_node();
        //Sets the previous node to the last node object.
        void set_previous_node(Node *node2);
        //Gets the previous node object.
        Node get_previous_node();
        
};

#endif