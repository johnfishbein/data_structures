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
  
  for (int i = 0; i < capacity; i++){
    htable.push_back("");
  }
}

hashTable::~hashTable(){
}

unsigned int hashTable::hash(string s){
  unsigned int sum = 0;
  const char* cs = s.c_str();
  int i = 1;
  for (const char*iter = cs; *iter; iter++){
    sum += int(*iter)*(37^i);
    i++;
  }
  return sum %capacity;
}

unsigned int hashTable::rehash(string s){
  unsigned int sum = 8677;
  const char* cs = s.c_str();
  int i = 1;
  for (const char*iter = cs; *iter; iter++){
    sum += int(*iter)*(119^i);
    i++;
  }
  return sum %capacity;
}

unsigned int hashTable::hashThree(string s){
  unsigned int num = 37^s.length();
  for (int i = 0; i < s.length(); i++){
    num += (int)s[i]*(51^i);
  }
  return num %capacity;
}

void hashTable::put(string s){
  //cout << s << endl;
  unsigned int pos = hash(s);
  //cout << pos << endl;
  if (htable[pos] == ""){
    htable[pos] = s;
    // size++;
  }else{
    pos = rehash(s);
    if (htable[pos] == ""){
      htable[pos] = s;
    }else{
      pos = hashThree(s);
    int i = 1;
    while (htable[pos] != ""){
    pos = (pos + i*i)%capacity;
    i++;
    }
    htable[pos] = s;
    }

    // size++;
  }
  
}

bool hashTable::find(string s){
  unsigned int pos = hash(s);
  if (htable[pos] == s){
    return true;
  }else{
    pos = rehash(s);
    if (htable[pos] == s){
      return true;
    }
    pos = hashThree(s);
    int i = 1;
    while(htable[pos] != ""){
      if (htable[pos] == s){
	return true;
      }
      pos = (pos + i*i)%capacity;
      i++;
    }
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




