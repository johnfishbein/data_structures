//jhf5my -- John Fishbein -- Tuesday 26 February 2019
//AVLNode.h

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
  AVLNode();
  ~AVLNode();

  string value;
  AVLNode* left;
  AVLNode* right;
  int height;
  int bfactor;

  friend class AVLTree;
};

#endif
