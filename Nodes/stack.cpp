template<typename DT>
class Stack{
    private:
        DT data;
        Stack *last;
    public:
        //Constructor.
        Stack();
        //To push to the back of the stack.
        void push(DT stuff);
        //To return the last added item.
        DT pop();
};

Stack::Stack(){
    last = NULL;
    return;
};

template<typename DT>
void Stack::push(DT stuff){
    Node node3(stuff);
    node3.set_next_node(node3);
    if(node3.get_next_node == NULL){
        last = node3;
    }
    return;
};

template<typename DT>
DT Stack::pop(){
    delete last;
};