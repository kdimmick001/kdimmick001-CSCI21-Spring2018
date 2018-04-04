#include "node.h"

//Move this to .cpp file.
//Constructor.
Node::Node(){
    next = NULL;
    previous = NULL;
};

//Default constructor to add data to the node.
template<typename DT>
Node::Node(DT stuff){
    thing_ = stuff;
    next = NULL;
    previous = NULL;
};

//To set the thing to the parameter value.
template<typename DT>
void Node::set_contents(DT info){
    thing_ = info;
    return;
};

//To get the information being held in the object.
template<typename DT>
DT Node::contents(){
    return thing_;  
};

//To set the next pointer.
void Node::set_next_node(Node *node2){
    //Sets the next object pointer to the node2 object.
    next = node2;
    //Sets the previous object pointer of node2 to this object.
    node2.set_previous_node(this);
    //If the next for the node2 object is NULL it will be set to last.
    if(node2.get_next_node() == NULL){
        last = node2;
    }
    //If the previous pointer is NULL then the object will be first.
    if (previous == NULL){
        first = this;
    }
    return;
};

Node Node::get_next_node(){
    //Returns the object that the next is pointing to.
    return *next;
};

void Node::set_previous_node(Node *node2){
    //To set the previous pointer.
    previous = node2;
    return;
};

Node Node::get_previous_node(){
    //Returns the object that the previous is pointing to.
    return *previous;
};
    