#ifndef STACK_H
#define STACK_H

#include "node.h"

template<typename DT>
class Stack{
    private:
        DT data;
        //Stack *last;
        Node<DT> *first;
        //To keep track of how big the stack is.
        int count_;
        // Stack *temp;
    public:
        //Constructor.
        Stack();
        //To push to the back of the stack.
        void push(DT stuff);
        //To return the last added item.
        void pop();
        //To return the popped data.
        DT PrintData();
        //To return the size value of the stack.
        int size();
        //To clear the stack.
        void clear();
        DT get_data();
};

template<typename DT>
Stack<DT>::Stack(){
    count_ = 0;
    data = "";
    // last = NULL;
    first = NULL;
    // temp = new Stack;
    return;
};

template<typename DT>
void Stack<DT>::push(DT stuff){
    Node<DT> *node_ = new Node<DT>;
    node_->set_contents(stuff);
    if (first == NULL){
        node_->set_next_node(NULL);
        first = node_;
    } else { 
        node_->set_next_node(first);
        first = node_;
    }
    count_ = count_ + 1;
    data += stuff;
    data += " ";
    
    return;
};

template<typename DT>
void Stack<DT>::pop(){
    if (first != NULL){
        PrintData();
        Node<DT> *temp = first;
        temp = first->get_next_node();
        delete first;
        if (count_ != 0){
            count_ = count_ - 1;
        }
        first = temp;
        }
    if (first == NULL){
            data= "";
    }
        // PrintData();
    // delete temp;
    return;
};

template<typename DT>  
int Stack<DT>::size(){
    return count_;
};

template<typename DT>
DT Stack<DT>::PrintData(){
    data = "";
    Node<DT> *curr_node = first;
    while (curr_node != NULL){
        data += curr_node->contents();
        if (curr_node->get_next_node() != NULL){
            data += ", ";
        }
        curr_node = (curr_node->get_next_node());
    }
    return data;
};

template<typename DT>
void Stack<DT>::clear(){
    while (first != NULL){
        pop();
    }
    count_ = 0;
    data = "";
    return;
};
template<typename DT>
DTg Stack<DT>::get_data(){
    return data;
};

#endif