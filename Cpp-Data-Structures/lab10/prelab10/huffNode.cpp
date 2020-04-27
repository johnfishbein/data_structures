//jhf5my -- John Fishbein -- 15 Monday April 2019
//huffNode.cpp
#include "huffNode.h"
#include <stddef.h>

using namespace std;


huffNode::huffNode(){
  freq = 0;
  character = (char) '$';
  left = NULL;
  right = NULL;
}

