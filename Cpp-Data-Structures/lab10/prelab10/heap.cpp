//jhf5my -- John Fishbein -- 15 Monday April 2019
//heap.cpp

#include <iostream>
#include "heap.h"

using namespace std;


huffHeap::huffHeap(){
  size = 0;
  huffNode * tmp = new huffNode(); 
  heap.push_back(tmp);
}

void huffHeap::insert(huffNode* node){
  heap.push_back(node);
  size++;

  percolateUp(size);
}

void huffHeap::percolateUp(int hole){
  huffNode* x = heap[hole];
  for ( ; (hole > 1) && (x->freq < heap[hole/2]->freq); hole /=2){
    heap[hole] = heap[hole/2];
  }
  heap[hole] = x;
}


huffNode* huffHeap::deleteMin(){
  if (size == 0){
    cout << "ERROR" << endl;
  }
  huffNode* ret = heap[1];
  heap[1] = heap[size];
  size--;
  heap.pop_back();

  percolateDown(1);
  return ret;
}

void huffHeap::percolateDown(int hole){
  huffNode* x = heap[hole];

  while (hole*2 <= size){
    int childIndex = hole*2;

    if ((childIndex+1 <= size) && (heap[childIndex+1]->freq < heap[childIndex]->freq)){
	childIndex++;
    }

    if (x->freq > heap[childIndex]->freq){
      heap[hole] = heap[childIndex];
      hole =childIndex;
    } else{
      break;
    }
  }

  
  heap[hole] = x;
}



huffNode* huffHeap::findMin(){
  if (size == 0){
    cout << "ERROR" << endl;
  }
  return heap[1];
}


bool huffHeap::isEmpty(){
  return size == 0;
}


void huffHeap::print(){
  cout << "(" << heap[0]->character <<  ")" << endl;
  for (int i = 1; i <= size; i++){
    cout << heap[i]->character << " ";
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if(isPow2){
      cout << endl << "\t";
    }
  }
  cout << endl;
  


}
