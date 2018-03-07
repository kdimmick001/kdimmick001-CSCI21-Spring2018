#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    for (int i = argc; i >= 0; --i){
        cout << argv[i];
    }
    
}