//jhf5my -- John Fishbein -- Tuesday Februrary 22 2019
//LifeCycle.h
#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <string>
#include <iostream>
using namespace std;

class MyObject {
 public:
  static int numObjs;
  MyObject(const char *n = "--default--"); //what is char *n
  MyObject(const MyObject& rhs);
  ~MyObject();
  string getName() const;
//whats the difference between putting const here or const ine parameters
  void setName(const string newName);
  friend ostream& operator<<(ostream& output, const MyObject& obj);
 private:
  string name;
  int id;
 
};


#endif
