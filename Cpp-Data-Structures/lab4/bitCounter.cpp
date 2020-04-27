//jhf5my -- John Fishbein -- Wednesday February 13 2019
//bitCounter.cpp

#include <iostream>
#include <typeinfo>
using namespace std;


int ones(int n){
  if (n == 0){
    return 0;
  }else if (n == 1){
    return 1;
  }else if (n % 2 == 0){
    return ones(n/2);
  }else{
    return 1 + ones(n/2);
  }
}



int main(int argc, char *argv[]){
  int x;

  if (argc == 1){
    cout << "Please enter a command line parameter" << endl;
  }else{
    cout << argv[1] << " has "<< ones(atoi(argv[1])) << " 1s in its binary representation" << endl;
  } 
  return 0;
}
