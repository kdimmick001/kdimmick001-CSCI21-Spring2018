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

Pair::Pair(){
    num1_ = 0;
    num2_ = 0;
};

Pair::Pair(int x){
    num1_ = x;
    num2_ = 0;
};

Pair::Pair(int x, int y){
    num1_ = x;
    num2_ = y;
};

void Pair::SetNumOne(int x){
    num1_ = x;
    return;
};

int Pair::GetNumOne(){
    return num1_;
};

void Pair::SetNumTwo(int y){
    num2_ = y;
    return;
};

int Pair::GetNumTwo(){
    return num2_;
};

Pair Pair::operator+(int val){
    Pair total;
    
    total.num1_ = num1_ + val;
    total.num2_ = num2_ + val;
    return total;
};
Pair Pair::operator-(int val){
    Pair total;
    
    total.num1_ = num1_ - val;
    total.num2_ = num2_ - val;
    return total;
};
Pair Pair::operator*(int val){
    Pair total;
    
    total.num1_ = num1_ * val;
    total.num2_ = num2_ * val;
    return total;
};
Pair Pair::operator/(int val){
    Pair total;
    
    total.num1_ = num1_ / val;
    total.num2_ = num2_ / val;
    return total;
};
const Pair::Pair operator+(const Pair &n1, const Pair &n2){
    return Pair(n1.num1_ + n2.num2_);
};
const Pair::Pair operator-(const Pair &n1, const Pair &n2){
    return Pair(n1.num1_ - n2.num2_);
};
const Pair::Pair operator*(const Pair &n1, const Pair &n2){
    return Pair(n1.num1_ * n2.num2_);
};
const Pair::Pair operator/(const Pair &n1, const Pair &n2){
    return Pair(n1.num1_ / n2.num2_);
};

int main(){
  Pair p1(5,10);
  Pair p2(1,2);
  
  // Outputs 5 and 10
  cout << p1.getNum1() << " " << p1.getNum2() << endl;

  // Outputs 1 and 2
  cout << p2.getNum1() << " " << p2.getNum2() << endl;

  Pair p3 = p2 + p1;

  // Outputs 6 and 12
  cout << p3.getNum1() << " " << p3.getNum2() << endl;

  p3 = p3 + 2;

  // Outputs 8 and 14
  cout << p3.getNum1() << " " << p3.getNum2() << endl;

}