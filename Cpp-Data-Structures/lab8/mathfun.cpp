//jhf5my -- John Fishbein -- Monday 25 March 2019
//mathfun.cpp
#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);
int  main () {
  long x;
  long y;
  cin >> x;
  cin >> y;

  long prod;
  long pow;
  prod = product(x, y);
  pow = power(x, y);
  cout << prod << endl;
  cout << pow << endl;
  
}
