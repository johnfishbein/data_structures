//jhf5my -- John Fishbein -- Friday March 1 2019
//hashTable.h

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;


class hashTable{
 public:
  hashTable();
  hashTable(int numWords);
  ~hashTable();
 
  int size;
  int capacity;
  vector<string> htable;
  void put(string s);
  bool find(string s);

 private:
  unsigned int hash(string s);
  unsigned int rehash(string s);
  unsigned int hashThree(string s);
  void resize();

  unsigned int nextPrime(unsigned int n);
  bool isPrime(unsigned int n);



};


#endif
