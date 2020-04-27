#include <iostream>

using namespace std;

int mySum(int a, int b, int c){
  int z = a;
  z += b;
  z += c;

  return z;

  for (int i = 0; i < 10; i++){
    cout << "THIS CODE IS UNREACHABLE" << endl;
  }
 
}



int main(){

  int x;
  x = mySum(1, 2, 3);
  cout << x << endl;
  return 0;
}
