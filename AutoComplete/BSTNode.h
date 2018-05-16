#ifndef BSTNode_H
#define BSTNode_H

#include "stringclass.h"

class BSTNode{
    private:
        //A string to hold the prefix.
        string prefix;
        //For values greater than or equal to the parent.
        BSTNode* right_child_;
        //For values less than or equal to the parent.
        BSTNode* left_child_;
    
    public:
        //Constructor to set the pointer nodes to NULL.
        BSTNode();
        //Overloaded Constructor to set the prefix with a starting value.
        BSTNode(string beginning);
        //Mutator for the prefix.
        void SetPrefix(string beginning);
        //Accessor for the prefix.
        string GetPrefix();
        //Mutator for the Right Child pointer.
        void SetRightChild(BSTNode* right);
        //Accessor for the Right Child pointer.
        BSTNode* GetRightChild();
        //Mutator for the Left Child pointer.
        void SetLeftChild(BSTNode* left);
        //Accessor for the Left Child pointer.
        BSTNode* GetLeftChild();
        
        //Mutator for the Node pointers.
        //void SetChildren(BSTNode* child);
};

//Constructor to set the pointers to NULL.
BSTNode::BSTNode(){
    right_child_ = NULL;
    left_child_ = NULL;
};

//Overloaded constructor to set the pointer value as well as the prefix value.
BSTNode::BSTNode(string beginning){
    prefix = beginning;
    right_child_ = NULL;
    left_child_ = NULL;
};

//Mutator to set the prefix value.
void BSTNode::SetPrefix(string beginning){
    prefix = beginning;
    return;
};

//Accessor to get the prefix value.
string BSTNode::GetPrefix(){
    return prefix;
};

//Mutator to set the Right Child pointer value.
void BSTNode::SetRightChild(BSTNode* right){
    right_child_ = right;
    return;
};

//Accessor to get the Right Child pointer value.
BSTNode* BSTNode::GetRightChild(){
    return right_child_;
};

//Mutator to set the Left Child pointer value.
void BSTNode::SetLeftChild(BSTNode* left){
    left_child_ = left;
    return;
};

//Accessor to get the Left Child pointer value.
BSTNode* BSTNode::GetLeftChild(){
    return left_child_;
};




//Mutator for the Node pointers depending on the value to be pointed to.
//void BSTNode::SetChildren(BSTNode* child){
//    if(child)
//};

#endif