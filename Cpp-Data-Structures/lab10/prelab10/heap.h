//jhf5my -- John Fishbein -- 15 Monday April 2019
//heap.h
#ifndef H_HEAP
#define H_HEAP
#include <vector>
#include "huffNode.h"

using namespace std;

class huffHeap {
 public:
  huffHeap();
  void insert(huffNode*);
  huffNode* findMin();
  huffNode* deleteMin();
  bool isEmpty();
  void print();

  void percolateUp(int index);
  void percolateDown(int index);
  vector<huffNode*> heap;
  unsigned int size;
  
};


#endif

