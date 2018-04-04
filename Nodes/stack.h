#ifndef STACK_H
#define STACK_H

#include "node.h"

template<typename DT>
class Stack{
    private:
        DT data;
        Stack *last;
        //To keep track of how big the stack is.
        int count_;
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
};

template<typename DT>
Stack<DT>::Stack(){
    count_ = 0;
    data = "";
    last = NULL;
    return;
};

template<typename DT>
void Stack<DT>::push(DT stuff){
    Node<DT> node3(stuff);
    DT *previous;
    previous = node3.get_previous_node;
    node3.set_next_node(previous);
    if(node3.get_next_node() == NULL){
        last = *node3;
    }
    count_ = count_ + 1;
    return;
};

template<typename DT>
void Stack<DT>::pop(){
    PrintData();
    delete last;
    if (count_ != 0){
        count_ = count_ - 1;
    }
    return;
};

template<typename DT>
int Stack<DT>::size(){
    return count_;
};

template<typename DT>
DT Stack<DT>::PrintData(){
    return data;
};

template<typename DT>
void Stack<DT>::clear(){
    count_ = 0;
    data = "";
    return;
};

#endif