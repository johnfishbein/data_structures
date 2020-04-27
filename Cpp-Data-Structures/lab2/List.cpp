// jhf5my -- John Fishbein -- Friday January 25 2019
// List.cpp
//crashes if trying to make a new list after clearing old one

#include "List.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

List::List(){
  count = 0;
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
}

List::List(const List &source){
  count = 0;
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List(){ // not working
  this->makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source){
  if (this == &source){
    return *this;
  }else{
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const{
  return (count == 0);
}

void List::makeEmpty(){ //working but not using delete keyword
  ListItr iter = this->first();
  while(!iter.isPastEnd()){
    iter.moveForward();
    delete iter.current->previous;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

ListItr List::first(){
  ListItr l(this->head->next);
  return l;
  
}

ListItr List::last(){
ListItr l(this->tail->previous);
return l;
}


void List::insertAfter(int x, ListItr position){
  if (!position.isPastEnd()){
    ListNode * node = new ListNode;
    count++;
    node->value = x;
    node->next = position.current->next;
    node->previous = position.current;
    position.current->next->previous = node;
    position.current->next = node;
  }
}

void List::insertBefore(int x, ListItr position){
  if (!position.isPastBeginning()){
    ListNode * node = new ListNode;
    count++;
    node->value = x;
    node->next = position.current;
    node->previous = position.current->previous;
    position.current->previous->next = node;
    position.current->previous = node;
  }
}


void List::insertAtTail(int x){
   ListNode * node = new ListNode;
   count++;
   node->value = x;
   node->next = tail;
   node->previous = tail->previous;
   tail->previous->next = node;
   tail->previous = node;
}


void List::remove(int x){
  ListItr iter = this->first();
  bool found = false;
  while (!iter.isPastEnd() && !found){
    if (iter.current->value == x){
      found = true;
    }else{
      iter.moveForward();
    }
  }

  if (found){
    iter.current->next->previous = iter.current->previous;
    iter.current->previous->next = iter.current->next;
    delete iter.current;
    count--;
  }
  
}

ListItr List::find(int x){
  ListItr iter = this->first();
  bool found = false;
  while(!iter.isPastEnd() && !found){
    if (iter.current->value == x){
      found = true;
    }else{
      iter.moveForward();
    }
  }
  return iter;
}


int List::size() const{
  return count;
}
