//jhf5my -- John Fishbein -- Tuesday February 5 2019
//Stack.cpp

#include "Stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

using namespace std;

Stack::Stack(){
  topVal = l.last();
}

Stack::~Stack(){
}

void Stack::push(int val){
  l.insertAfter(val, topVal);
}

void Stack::pop(){
  topVal.moveForward();
  l.remove(topVal.retrieve());
  topVal.moveBackward();
}

int Stack::top(){
  topVal.moveForward();
  int val = topVal.retrieve();
  topVal.moveBackward();
  return val;
}

bool Stack::empty(){
  return l.isEmpty();
}

int Stack::size() const{
  return l.size();
}
