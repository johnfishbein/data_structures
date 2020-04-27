//jhf5my -- John Fishbein -- Thursday January 31 2019
//postfixCalculator.cpp

#include "postfixCalculator.h"
#include "Stack.h"
#include <stack>

using namespace std;

Calculator::Calculator(){
}

Calculator::~Calculator(){
  this->makeEmpty();
}

void Calculator::pushNum(int num){
  numbers.push(num);
}

void Calculator::add(){
  if (numbers.size() >= 2){
    int op2 = numbers.top();
    numbers.pop();
    int op1 = numbers.top();
    numbers.pop();
    numbers.push(op1 + op2);
  }
  else{
    cout << "Not enough elements in the stack" << endl;
  }
  
}

void Calculator::subtract(){
  if (numbers.size() >= 2){
    int op2 = numbers.top();
    numbers.pop();
    int op1 = numbers.top();
    numbers.pop();
    numbers.push(op1 - op2);
  }
  else{
    cout << "Not enough elements in the stack" << endl;
  }
}

void Calculator::multiply(){
  if (numbers.size() >= 2){
    int op2 = numbers.top();
    numbers.pop();
    int op1 = numbers.top();
    numbers.pop();
    numbers.push(op1 * op2);
  }
  else{
    cout << "Not enough elements in the stack" << endl;
  }
  
}

void Calculator::divide(){
  if (numbers.size() >= 2){
    int op2 = numbers.top();
    numbers.pop();
    int op1 = numbers.top();
    numbers.pop();
    numbers.push(op1 / op2);
  }
  else{
    cout << "Not enough elements in the stack" << endl;
  }
  
}

void Calculator::negate(){
  if (!numbers.empty()){
    int op = numbers.top();
    numbers.pop();
    numbers.push(op * -1);
  }else{
    cout << "Cannot negate nothing" << endl;
  }
}

void Calculator::makeEmpty(){
  while(!numbers.empty()){
    numbers.pop();
  }
}

int Calculator::getResult(){
  if (!numbers.empty()){
    return numbers.top();
  }else{
    cout << "Nothing on the stack" << endl;
    return 0;
  }

}
