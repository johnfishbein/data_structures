//jhf5my -- John Fishbein -- Friday March 1 2019
//hashTable.cpp

#include "hashTable.h"
#include <string>
#include <iostream>
#include <iterator>
#include <math.h>


using namespace std;

hashTable::hashTable(){
}

hashTable::hashTable(int numWords){
  size = 0;
  capacity = nextPrime(numWords*2);
  loadFactor = 0;
  
  for (int i = 0; i < capacity; i++){
    htable.push_back("");
  }
}

hashTable::~hashTable(){
}

unsigned int hashTable::hash(string s){
  unsigned int sum = 0;
  int i =0;
  for (char c : s){
    sum += (int)(c)*pow(37,i);
    i++;
  }
  return sum % capacity;
}

void hashTable::put(string s){
  //cout << s << endl;
  unsigned int pos = hash(s);
  //cout << pos << endl;
  if (!find(s)){
  while (htable[pos] != ""){
    pos = (pos + 1)%capacity;
  }
  htable[pos] = s;
  size++;
  loadFactor = (float)size/capacity;
  }
}

bool hashTable::find(string s){
  unsigned int pos = hash(s);
  while (htable[pos] != ""){
    if (htable[pos] == s){
      return true;
    }
    pos = (pos +1)%capacity;
  }
  return false;
}


unsigned int hashTable::nextPrime(unsigned int n){
  while (!isPrime(n)){
    ++n;
  }
  return n;
  
}

bool hashTable::isPrime(unsigned int n){
  if (n <= 1){
    return false;
  }
  if (n == 2){
    return true;
  }
  if (n % 2 == 0){
    return false;
  }
  for (int i = 3; i*i <= n; i += 2){
    if (n % i == 0){
      return false;
    }
  }

  return true;
}




