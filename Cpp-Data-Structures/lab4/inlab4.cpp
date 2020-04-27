//jhf5my -- John Fishbein -- Tuesday February 12 2019
//inlab4.cpp

#include <string>
#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;


int main(){
  int * ip = NULL;
  char * cp = NULL;
  double * dp = NULL;
  float f = 1.0;
  double d = 1.0;
  cout<< "   SIZE IN BYTES:" << endl;
  cout << "int: "<< sizeof(int) << endl;
  cout << "unsigned int: "<< sizeof(unsigned int) << endl;
  cout << "float: "<< sizeof(float) << endl; 
  cout << "double: "<< sizeof(double) << endl;
  cout << "char: "<< sizeof(char) << endl;
  cout << "bool: "<< sizeof(bool) << endl;
  cout << "int*: "<< sizeof(int*) << endl;
  cout << "char*: "<< sizeof(char*) << endl;
  cout << "double*: "<< sizeof(double*) << endl;
  cout << "" <<endl;
  cout << "   MIN VALUE, MAX VALUE" << endl;
  cout << "int: "<< INT_MIN << ", "<< INT_MAX <<  endl;
  cout << "unsigned int: "<< "NONE" << ", " << UINT_MAX  << endl;
  cout << "float: NONE, " << FLT_MAX<< endl;
  cout << "double: NONE, " << DBL_MAX << endl;
  // cout << "           float: "<< "FIGURE IT OUT" << endl; 
  //cout << "           double: "<< "FIGURE IT OUT" << endl;
  cout << "char: "<< CHAR_MIN << ", " << CHAR_MAX << endl;
  cout << "           bool: "<< "FIGURE IT OUT" << endl;
  cout << "           pointers: FIGURE IT OUT" << endl; 
  cout << "" << endl;

  cout << "\n    PRIMITIVE ARRAYS\n" << endl;
  int IntArray[10];
  char CharArray[10];
  int IntArray2D[6][5];
  char CharArray2D[6][5];

  int i;
  int j;

  char c = 'a';
  for (i = 0; i < 10; i++){
    IntArray[i] = i;
    CharArray[i] = c;
    c++;
  }

  c = 'a';
  int x = 0;
  for (i = 0; i < 6; i++){
    for (j = 0; j < 5; j++){
      IntArray2D[i][j] = x;
      CharArray2D[i][j] = c;
      c++;
      x++;
    }
  }
  
  cout << "IntArray: ";
  cout << "{";
  for (i = 0; i < 10; i++){
    cout << IntArray[i];
    if (i != 9){ cout << ", ";}
  }
  cout << "}\n" << endl;

  cout << "CharArray: ";
  cout << "{";
  for (i = 0; i < 10; i++){
    cout << CharArray[i];
    if (i != 9){ cout << ", ";}
  }
  cout << "}\n" << endl;

  cout << "IntArray2D" << endl;
  cout << "{" << endl;

  for (i = 0; i < 6; i++){
    for (j = 0; j < 5; j++){
      cout << IntArray2D[i][j];
      if (j != 4){cout << ", ";}
    }
    if (i != 5) {cout << "" << endl;}
  }
  cout << "\n}" << endl;
  

  cout << "\nCharArray2D" << endl;
  cout << "{" << endl;

  for (i = 0; i < 6; i++){
    for (j = 0; j < 5; j++){
      cout << CharArray2D[i][j];
      if (j != 4){cout << ", ";}
    }
    if (i != 5) {cout << "" << endl;}
  }
  cout << "\n}" << endl;
  
  
  
  return 0;
}
