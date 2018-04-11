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
        DT contents_;
        Node *next; //Points to the next object from the Node class.
        Node *previous; //Points to the previous object from the Node class.
        Node *last; //Points to the last object.
        Node *first; // Points to the first object.
        
    public:
        //Constructor to set the pointer.
        Node();
        //Overload Constructor.
        Node(DT stuff);
        //To set the information being held in the object.
        void set_contents(DT info);
        //To get the information being held in the object.
        DT contents();
        //To set the next node pointer to the next spot. As well as the previous to the previous spot.
        void set_next_node(Node *node2);
        //Returns the next node object pointer.
        Node* get_next_node();
        //Sets the previous node to the last node object.
        void set_previous_node(Node *node2);
        //Gets the previous node object.
        Node* get_previous_node();
        Node* get_last_node();
        Node* get_first_node();
};
//Move this to .cpp file.
//Constructor.
template<typename DT>
Node<DT>::Node(){
    contents_ = "";
    next = NULL;
    previous = NULL;
};

//Default constructor to add data to the node.
template<typename DT>
Node<DT>::Node(DT stuff){
    contents_ = stuff;
    next = NULL;
    previous = NULL;
};

//To set the thing to the parameter value.
template<typename DT>
void Node<DT>::set_contents(DT info){
    contents_ = info;
    return;
};

//To get the information being held in the object.
template<typename DT>
DT Node<DT>::contents(){
    return contents_;  
};

template<typename DT>
//To set the next pointer.
void Node<DT>::set_next_node(Node * node2){
    //Sets the next object pointer to the node2 object.
    next = node2;
    //If the next for the node2 object is NULL it will be set to last.
    if (node2 != NULL){
        //Sets the previous object pointer of node2 to this object.
        node2->set_previous_node(this);
        
        if(node2->get_next_node() == NULL){
            last = node2;
        }
        //If the previous pointer is NULL then the object will be first.
        if (previous == NULL){
            first = this;
        }
    }
    return;
};
template<typename DT>
Node<DT>* Node<DT>::get_next_node(){
    //Returns the object that the next is pointing to.
    return next;
};
template<typename DT>
void Node<DT>::set_previous_node(Node *node2){
    //To set the previous pointer.
    previous = node2;
    return;
};
template<typename DT>
Node<DT>* Node<DT>::get_previous_node(){
    //Returns the object that the previous is pointing to.
    return previous;
};
template<typename DT>
Node<DT> *Node<DT>::get_last_node(){
    return last;
};
template<typename DT>
Node<DT> *Node<DT>::get_first_node(){
    return first;
};
    
#endif