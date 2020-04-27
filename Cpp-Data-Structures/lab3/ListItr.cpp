// jhf5my -- John Fishbein -- Friday January 25 2019
// ListItr.cpp

#include "ListItr.h"
#include "ListNode.h"

using namespace std;


ListItr::ListItr(){}
ListItr::ListItr(ListNode * theNode){
  current = theNode;
}

bool ListItr::isPastEnd() const{
  if (!current->next){//if current->next == NULL
    return true;
  }
  return false;
}

bool ListItr::isPastBeginning() const{
  if (!current->previous){ //if current->previous == NULL
    return true;
  }
  return false;
}

void ListItr::moveForward(){
  if (!this->isPastEnd()){
    current = current->next;
  }
}

void ListItr::moveBackward(){
  if (!this->isPastBeginning()){
    current = current->previous;
  }
}

int ListItr::retrieve() const{
  return current->value;
}


