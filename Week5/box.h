#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std

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