#include <iostream>
#include <sstream>

int main()
{
  using namespace std;

  string s = "1234";
  stringstream ss(s); // Could of course also have done ss("1234") directly.
  
  int i;
  ss >> i;
  cout << i << endl;
  
  return 0;
}

//One big makefile
//To run
//kdimmick001:~/workspace/Luhn (master) $ cd ../Week1
//kdimmick001:~/workspace/Week2 (master) $ make lab2exe
//kdimmick001:~/workspace/Week1 (master) $ ./lab2exe