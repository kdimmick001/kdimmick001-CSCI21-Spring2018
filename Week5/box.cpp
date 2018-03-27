#include "box.h"

template<typename type>
Box<type>::Box(){
    contents_ = 0;
};

template<typename type>
Box<type>::Box(type newContents){
    contents_ = newContents;
};

template<typename type>
void Box<type>::setContents(type newContents){
    contents_ = newContents;
};

template<typename type>
type Box<type>::getContents(){
    return contents_;
};

template<typename type>
ostream &operator <<(ostream &out, Box<type> const &b){
  out << b.contents_;
  // Return the ostream object to allow for chaining of <<
  return out;
};