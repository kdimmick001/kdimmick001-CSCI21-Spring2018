#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#include<string>
#include "catch.hpp"
#include "stack.h"
using std::string;

TEST_CASE("Default Constructor for Stack") {
  Stack<string> stack;
  SECTION("Accessor for Size") {
    CHECK(stack.size() == 0);
  }

  SECTION("PrintData()") {
    CHECK(stack.PrintData() == "");
  }

  SECTION("pop() on an Empty List") {
    stack.pop();
    CHECK(stack.size() == 0);
    CHECK(stack.PrintData() == "");
  }
}

TEST_CASE("Building your Linked List") {
  Stack<string> stack;
   stack.push("1");
  SECTION("InsertHead(1)") {
    CHECK(stack.size() == 1);
    CHECK(stack.PrintData() == "1");
  }

  stack.pop();
  SECTION("RemoveHead()") {
    CHECK(stack.size() == 0);
    CHECK(stack.PrintData() == "");
  }

  stack.push("10"), stack.push("20");
  SECTION("push(10), push(20)") {
    CHECK(stack.size() == 2);
    CHECK(stack.PrintData() == "20, 10");
  }

  stack.pop();
  SECTION("pop()") {
    CHECK(stack.size() == 1);
    CHECK(stack.PrintData() == "10");
  }

  stack.push("5");
  SECTION("InsertHead(5)") {
    CHECK(stack.size() == 2);
    CHECK(stack.PrintData() == "5, 10");
  }

  stack.clear();
  SECTION("clear()") {
    CHECK(stack.size() == 0);
    CHECK(stack.PrintData() == "");
  }

  stringstream full_list, half_list;
  for (int i = 999; i > 0; i--) {
    full_list << i << ", ";
    if (i < 500)
      half_list << i << ", ";
  }
  full_list << 0;
  half_list << 0;
  for (unsigned int i = 0; i < 1000; i++){
    stringstream list_;
    list_ << i;
    stack.push(list_.str());
  }
  SECTION("InsertHead() \"HIGH LOAD\"") {
    CHECK(stack.size() == 1000);
    CHECK(stack.PrintData() == full_list.str());
  }

  for (unsigned int i = 0; i < 500; i++) {
    stack.pop();
  }
  SECTION("RemoveHead() \"HIGH LOAD\" 1/2") {
    CHECK(stack.size() == 500);
    CHECK(stack.PrintData() == half_list.str());
  }

  for (unsigned int i = 0; i < 600; i++) {
    stack.pop();
  }
  SECTION("RemoveHead() \"HIGH LOAD\" 2/2") {
    CHECK(stack.size() == 0);
    CHECK(stack.PrintData() == "");
  }
}
#endif