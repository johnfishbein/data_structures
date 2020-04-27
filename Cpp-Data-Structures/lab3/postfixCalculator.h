//jhf5my -- John Fishbein -- Thursday January 31 2019
//postfixCalculator.h
#ifndef POSTFIXCALC_H
#define POSTFIXCALC_H

#include <stack>
#include <iostream>
#include "Stack.h"

using namespace std;


class Calculator {
 public:
  Calculator();
  ~Calculator();
  void pushNum(int num);
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  void makeEmpty();
  int getResult();

  //private:
  //stack<int> numbers;
  Stack numbers;
};

#endif
