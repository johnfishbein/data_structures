//jhf5my -- John Fishbein -- Tuesday February 5 2019
//Stack.h

#ifndef STACK_H
#define STACK_H
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"


class Stack {
 public:
  Stack();\
  ~Stack();
  void push(int val);
  void pop();
  int top();
  bool empty();
  int size() const;

 private:
  List l;
  ListItr topVal;
  

};

#endif
