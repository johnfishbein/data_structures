//jhf5my -- John Fishbein -- 15 Monday April 2019
//huffNode.h

#ifndef HUFFNODE_H
#define HUFFNODE_H

class huffNode {
 public:
  huffNode();
  huffNode* right;
  huffNode* left;
  int freq;
  char character;
};

#endif
