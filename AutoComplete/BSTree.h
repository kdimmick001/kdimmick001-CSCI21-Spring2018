#ifndef BSTree_H
#define BSTree_H

#include "stringclass.h"

//Inherits from the string class to be able to utilize ascending and descending functions.
class BSTree : public String{
    private:
        //To hold the information for the root as a reference.
        BSTNode* root;
        //To hold to current to sort into the associated left/right child.
        //BSTNode* curr;
    
    public:
        //Constructor.
        BSTree();
        //To Insert values into the Tree.
        void Insert(string prefix);
        //To insert values into the Tree based on the node pointer.
        void PrivateInsert(string prefix, BSTNode* node);
};

//Constructor to set the root and the current node value to NULL.
BSTree::BSTree(){
    root = NULL;
    //curr = NULL;
};
//To call the PrivateInsert Function using the appropriate BSTNode pointer.
void BST::Insert(string prefix){
    //Call the Private function because always want to start searching with the root.
    //But also want the flexibility to change the pointer node being passed to reflect the path the prefix needs to be inserted.
    PrivateInsert(prefix, root);
    return;
};


//To Insert values to progress the tree.
void BST::PrivateInsert(string prefix, BSTNode* node){
    
    //To create a new Node pointer to be able to manipulate the intended insert string.
    BSTNode* leaf = new BSTNode*;
    leaf.SetPrefix(prefix);
    
    //Case for if the Tree is empty.
    if (root == NULL){
        root = leaf;
        
    //Case for if the Tree is not empty.
    }else {
        //If the prefix is smaller than the passed node pointer's prefix.
        if (prefix < node.GetPrefix()){
            //If the left child is empty.
            if (node.GetLeftChild() == NULL){
                node.SetLeftChild(leaf);
            }
            //If the left child is not empty.
            if (node.GetLeftChild() != NULL){
                //Recursive call to the PrivateInsert function.
                PrivateInsert(prefix, node.GetLeftChild());
            }
        }
        //If the prefix is greater than the passed node's pointer prefix.
        if (prefix > node.GetPrefix()){
            //If the right child is empty.
            if (node.GetRightChild() == NULL){
                node.SetRightChild(leaf);
            }
            //If the right child is not empty.
            if (node.GetRightChild() != NULL){
                //Recursive call to the PrivateInsert function.
                PrivateInsert(prefix, node.GetRightChild());
            }
        }
    }
    return;
};



#endif