//jhf5my -- John Fishbein -- Sunday February 10 2019
//prelab4.cpp

#include <string>
#include <iostream>
#include <stack>
#include <climits>

using namespace std;

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
  cout << "Size of float: " << sizeof(float) << " bytes" << endl;
  cout << "Size of double: " << sizeof(double) << " bytes" << endl;
  cout << "Size of char: " << sizeof(char) << " bytes" << endl;
  cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
  cout << "Size of int pointer: " << sizeof(int*) << " bytes" << endl;
  cout << "Size of char pointer: " << sizeof(char*) << " bytes" << endl;
  cout << "Size of double pointer: " << sizeof(double*) << " bytes" << endl;
}


void outputBinary(unsigned int n){
  stack<int> s;
  while (n / 2 != 0){
    s.push(n % 2);
    n = n/2;
  }
  s.push(n % 2);
  string output = "";
  for (int i = 0; i < 32; i++){
    if (i % 4 == 0 && i != 0){output += " ";} 
    if (i >= 32 - s.size()){
      output += to_string(s.top());
      s.pop();
    }else {
      output += "0";
    }
  }

  cout << output << endl;
}

void overflow(){
  unsigned int x = UINT_MAX;
  cout << "Largest unsigned int: " << x << endl;
  cout << "adding 1..." << endl;
  x++;
  cout << "Result: " << x << endl;
  cout << "This happens because when you add one to the largest possible value, the extra 1 carries through to every digit. The binary representation of this number should be 1 followed by 32 0s but the unsigned int data type can only hold 32 bits of data." << endl; 
  
}


int main(){
  unsigned int x;
  cin >> x;
  sizeOfTest();
  outputBinary(x);
  //outputBinary(5);
  //outputBinary(1000000);
  //outputBinary(4294967295);
  overflow();
  return 0;
}
