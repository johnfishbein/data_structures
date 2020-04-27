//jhf5my -- John Fishbein -- Tuesday 26 February 2019
//AVLTree.cpp

#include "AVLTree.h"
#include <string>
#include "AVLNode.h"
#include <iostream>
#include <cmath>
using namespace std;

AVLTree::AVLTree() { root = NULL; totNodes = 0; }

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  //cout << "before inserting " << x << endl << endl; 
  //printTree();
  if (!find(x)){
  insert(root, x);
  totNodes++;
  }
  //cout <<"                                          "<< x << "is the " << totNodes << "Node" <<endl;
  //cout << "after inserting " << x << endl << endl;
  //printTree();
  
}

void AVLTree::insert(AVLNode*& node, const string& x){
  if (node == NULL){
    node = new AVLNode();
    node->value = x;
  }else if (x < node->value){
      insert(node->left, x);
  }else{
      insert(node->right, x);
  }
  setHeights(node);

  balance(node);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  if (find(x)){
    return pathTo(this->root, x);
  }else{
    return "";
  }
}

string AVLTree::pathTo(AVLNode* node, const string& x) const{
  string path;
  if (node->value == x){
    return  x;
  }else if (x < node->value){
    path = node->value + " " + pathTo(node->left, x);
  }else if (x > node->value){
    path = node->value + " " + pathTo(node->right, x);
  }
  return path;
}




// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    return find(this->root, x);
}

bool AVLTree::find(AVLNode* node, const string& x) const {
  if (node == NULL){
    return false;
  }
  if (x == node->value){
    return true;
  }else if (x < node->value){
    return find(node->left, x);
  }else if (x > node->value){
    return find(node->right, x);
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  return totNodes;
}

void AVLTree::setHeights(AVLNode* node){
  if (node == NULL){
    return;
  }else{
    node->height = 1 + max(height(node->left), height(node->right));
    node->bfactor = height(node->right) - height(node->left);
  }
  
}


// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode* & node) {
    //set heights and bfactors
  setHeights(node);
  
    if (fabs(node->bfactor) == 2){
      if (this->root == node){
	this->root = callRotates(node);
      }else{
      node = callRotates(node);
      }
    }
}

AVLNode* AVLTree::callRotates(AVLNode *& node){
  
  if (node->bfactor == -2 && node->left->bfactor != 1){//left left
    // cout << "left left case" << endl;
      return rotateRight(node);
    
  }else if(node->bfactor == 2 && node->right->bfactor != -1){//right right
    
    // cout << "right right case" << node->value << endl;
      return rotateLeft(node);	  

  }else if(node->bfactor == 2 && node->right->bfactor == -1){//right left
	// cout << "right left case" << endl;
      node->right = rotateRight(node->right);
      //setHeights(node->right);
     return rotateLeft(node);
      
  }else {//if(node->bfactor == -2 && node->left->bfactor == 1){//left right
	//cout << "left right case" << endl; 
       node->left = rotateLeft(node->left);
      return rotateRight(node);
   }
}


// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  AVLNode * pivot = n->left;
  n->left = pivot->right;
  pivot->right = n;

  setHeights(n);
  setHeights(pivot);
  return pivot;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode * pivot = n->right;
  n->right = pivot->left;
  pivot->left = n;
  
  setHeights(n);
  setHeights(pivot);
  return pivot;
  
}


// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
  // cout << "Before removing " << root->value<< "   "  << x << endl;
  //printTree();
  root = remove(root, x);
  totNodes--;

  //cout << "after removing "<< root->value << "  " << x << endl;
  //printTree();
}


// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
     
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  //n->height = 1 + max(height(n->left), height(n->right));
  setHeights(n);
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }
