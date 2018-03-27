#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

template<typename type>
class Box {
    private:
        type contents_;
    public: 
        Box();
        Box(type newContents);
        void setContents(type newContents);
        type getContents();
        friend ostream &operator <<(ostream &out, Box<type> const &b);
        
};