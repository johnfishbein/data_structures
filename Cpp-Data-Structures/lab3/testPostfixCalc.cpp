//jhf5my -- John Fishbein -- Thursday January 31 2019
//testPostfixCalc.cpp

#include "postfixCalculator.h"
#include <stack>
#include <string>
#include <cstdlib>
#include "Stack.h"
using namespace std;


int main(){
  Calculator c;
  string s;

  while (cin >> s) {
    
    //cout << "Length of " << s << ": " << s.length()  << endl;
    

    if(isdigit(s[0])){
      //cout << "YES " << stoi(s)  << endl;
      c.pushNum(stoi(s));
    }
    else{
      if (s == "+"){
	c.add();
      }

      if (s == "*"){
	c.multiply();
      }

      if (s == "/"){
	c.divide();
      }

      if (s == "-"){
	c.subtract();
      }

      if (s == "~"){
	c.negate();
      }

      if (s.substr(0,1) == "-" && s.length() != 1){
	c.pushNum(-1 * stoi(s.substr(1,s.length()-1)));
      }
      
    }

   
  }
 cout << "RESULT: " << c.getResult() << endl;
  
  /*
  c.pushNum(1);
  c.pushNum(2);
  c.pushNum(3);
  c.add();
  c.add();
  cout << "Result should be 6 and actually is " << c.getResult() << endl;

  c.pushNum(2);
  c.divide();
  cout << "Result should be 3 and actually is " << c.getResult() << endl;

  c.negate();
  cout << "Result should be -3 and actually is " << c.getResult() << endl;

  c.pushNum(-2);
  c.subtract();
  cout << "Result should be -1 and actually is " << c.getResult() << endl;

  c.pushNum(5);
  c.multiply();
  cout << "Result should be -5 and actually is " << c.getResult() << endl;
  c.makeEmpty();
  c.getResult();

  */
  return 0;
}
