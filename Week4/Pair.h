#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std

class Pair(){
    private:
        int num1_;
        int num2_;
    public:
        Pair();
        Pair(int x);
        Pair(int x, int y);
        void SetNumOne(int x);
        int GetNumOne();
        void SetNumTwo(int y);
        int GetNumTwo();
        friend const Pair operator +(const Pair &n1, const Pair &n2);
        friend const Pair operator -(const Pair &n1, const Pair &n2);
        friend const Pair operator *(const Pair &n1, const Pair &n2);
        friend const Pair operator /(const Pair &n1, const Pair &n2);
        Pair operator+(int val);
        Pair operator-(int val);
        Pair operator*(int val);
        Pair operator/(int val);
        
};