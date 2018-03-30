#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

#include "node.h"

Node::Node(string in_thing = "none", Node* next_location = NULL){
	this->thing = in_thing;
	this->next_thing = next_location;
	return;
};

