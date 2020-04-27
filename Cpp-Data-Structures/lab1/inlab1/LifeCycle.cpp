//jhf5my -- John Fishbein -- Tuesday January 22 2019
//LifeCycle.cpp
#include "LifeCycle.h"
#include <iostream>
#include <string>
using namespace std;

// --------------------------------------------------- default constructor
MyObject::MyObject(const char *n) : name(n) {
  id = ++numObjs;
  cout << "MyObject Default constructor: " << *this << endl;
}

// ---------------------------------------------------  copy constructor
MyObject::MyObject(const MyObject& rhs) : name(rhs.name) {
    id = ++numObjs;
    cout << "MyObject Copy constructor:    " << *this << endl;
}

// --------------------------------------------------------  destructor
MyObject::~MyObject() {
    cout << "MyObject Destructor:          " << *this << endl;
}

string MyObject::getName() const {
  return name;
}

void MyObject::setName( const string newName ){
  name = newName;
}

// ----------------------------------------------------------  print out
ostream& operator<<(ostream& output, const MyObject& obj) {
    // output in format:  ("object name",id)
    return output << "(\"" << obj.name << "\"," << obj.id << ")";
}

int MyObject::numObjs = 0;
static MyObject staticObj("I'm static, outside of main");
