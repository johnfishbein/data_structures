//jhf5my -- John Fishbein -- Tuesday 26 February 2019
//AVLPathTest.cpp

#include "AVLTree.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
  AVLTree avl;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      avl.insert(word);
    } else if (instr == "R") {
      avl.remove(word);
    } else if (instr == "L") {
      cout << "AVL path: " << avl.pathTo(word) << endl;
    }
  }
  //avl.printTree();
  cout << "AVL numNodes: " << avl.numNodes() << endl;
}
