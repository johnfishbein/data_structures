//jhf5my -- John Fishbein -- Saturday February 23 2019
//TreeCalc.cpp

// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  cleanTree(mystack.top());
  if (!mystack.empty()){
    mystack.pop();
  }
  
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr->left){
    cleanTree(ptr->left);
  }
  if (ptr->right){
    cleanTree(ptr->right);
  }
  if (ptr){
  delete ptr;
  }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  TreeNode * node = new TreeNode(val);
  if (val == "+" || val == "-" || val == "*" || val == "/"){
    node->right = mystack.top();
    mystack.pop();
    node->left = mystack.top();
    mystack.pop();
  }
  mystack.push(node);
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if (ptr){
    cout << ptr->value << " ";
    printPrefix(ptr->left);
    printPrefix(ptr->right);
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
  bool op;
  if (ptr){
    op = false;
    if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*" ||ptr->value == "/"){
      op = true;
    }
 
    if (op){
      cout << "(";
    }
    printInfix(ptr->left);
    
    if (op){
      cout  << " " << ptr->value << " ";
    }else{
      cout << ptr->value;
    }
    
    printInfix(ptr->right);
    
    if (op){
      cout << ")";
    }
   
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
  if (ptr){
    printPostfix(ptr->left);
    printPostfix(ptr->right);
    cout << ptr->value << " "; 
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
	printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
	printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
	printPrefix(mystack.top());
	cout << endl;
    } else
        cout<< "Size is 0." << endl;
    
}

//Evaluates tree, returns value
// private calculate() method
bool TreeCalc::isLeaf(TreeNode* ptr) const{
  if (!(ptr->left) && (!(ptr->right))){return true;}
  return false;
}


int TreeCalc::getResult(string oper, int left, int right) const{
  if (oper == "+"){
    return left + right;
  }else if(oper == "-"){
    return left - right;
  }else if(oper == "*"){
    return left * right;
  }else if(oper == "/"){
    return left / right;
  }
  
  cout << "SHOULDNT HAVE GOTTEN HERE " << endl;

  return 0;
}

int TreeCalc::calculate(TreeNode* ptr) const {
  int result;
  int left;
  int right;
  if (!isLeaf(ptr)){
    left = calculate(ptr->left);
    right = calculate(ptr->right);
    result = getResult(ptr->value, left, right);
    
  }else{
    return stoi(ptr->value);
  }
  return result;
}


//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    i = calculate(mystack.top());
    return i;
}
