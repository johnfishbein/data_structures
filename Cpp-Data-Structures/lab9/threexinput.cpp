//jhf5my -- John Fishbein -- Wednesday 10 April 2019
//threexinput.cpp
	
#include "timer.h"
#include <iostream>

using namespace std;
extern "C" int collatz(int x);

int main(){
  int x, n;
  cout << "Enter a number: ";
  cin >> x;
  cout << "How many times should I run the function? ";
  cin >> n;

  
  int ans;
  ans = collatz(x);  

  timer t;
  t.start();
  for (int i = 0; i < n; i++){
    collatz(x);
  }
  t.stop();

  float totalTimems = t.getTime() * 1000;
  float avgTimems = totalTimems / n;
  
  
  cout << "An input of '" << x << "' took " << ans << " steps"<< endl;
  cout << "The average runtime of the function was " << avgTimems << " ms"<< endl;
  

  return 0;
}
