#ifndef BSTree_H
#define BSTree_H

#include "stringclass.h"

//Inherits from the string class to be able to utilize ascending and descending functions.
class BSTree : public String{
    private:
        //To hold the information for the root as a reference.
        BSTNode* root;
        //To hold to current to sort into the associated left/right child.
        BSTNode* curr;
    
    public:
        //Constructor.
        BSTree();
        //To Insert values into the Tree.
        void Insert();
};

//Constructor to set the root and the current node value to NULL.
BSTree::BSTree(){
    root = NULL;
    //curr = NULL;
};

//To Insert values to progress the tree.
void BST::Insert(string prefix){
    
    //To create a new Node pointer to be able to manipulate the intended insert string.
    BSTNode* leaf = new BSTNode*;
    leaf.SetPrefix(prefix);
    
    //Case for if the Tree is empty.
    if (root == NULL){
        root = leaf;
        
    //Case for if the Tree is not empty.
    }else {
        //If the prefix is smaller than the root's prefix.
        if (prefix < root.GetPrefix()){
            //If the left child is empty.
            if (root.GetLeftChild() == NULL){
                root.SetLeftChild(leaf);
            }
            //If the left child is not empty.
            if (root.GetLeftChild() != NULL){
                curr = GetLeftChild();
                if (prefix < curr.GetPrefix()){
                    
                }
            }
        }
        
    }
};



#endif