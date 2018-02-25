#include "box.h"

template<typename type>
class Box {
    private:
        type contents_;
    public: 
        Box();
        Box(type newContents);
        void SetContents(type newContents);
        type GetContents();
        friend &ostream operator <<(ostream &out, const Box &b);
        
};

template<typename type>
Box<type>::Box(){
    contents_ = 0;
};

template<typename type>
Box<type>::Box(type newContents){
    contents_ = newContents;
};

template<typename type>
void Box<type>::SetContents(type newContents){
    contents_ = newContents;
};

template<typename type>
type Box<type>::GetContents(){
    return contents_;
};

template<typename type>
ostream& operator <<(ostream &out, const Box &b){
  out << b.contents_;
  // Return the ostream object to allow for chaining of <<
  return out;
};