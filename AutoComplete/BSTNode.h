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
}


#endif