//jhf5my -- John Fishbein -- 15 Monday April 2019
//huffmanenc.cpp

#include <iostream>
#include <string>
#include "heap.h"
#include "huffNode.h"
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
string buildTable(huffNode* n, char c);
bool find(huffNode* n, char c);
void p(huffNode*n);
void p1(huffNode*n, int space);

int main(int argc, char **argv){
  if (argc != 2){
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL){
    exit(2);
  }

  int freqArr[256];

  for (int i = 0; i<256; i++){
    freqArr[i] = 0;
  }
  
  char c;
  string filestring = "";
  int numDifChars = 0;

  
  while( (c = fgetc(fp)) != EOF){
    if (((int) c <= 126 ) && ((int)c >= 32))
    freqArr[c]++;
    if (c!= '\n'){
    filestring +=c;
    }
  }

  rewind(fp);
  /* 
  for (int i = 32; i<127; i++){
    if (freqArr[i] != 0) {
      numDifChars++;
    }
    cout << (char) i << " : " << freqArr[i]<< endl;
  }*/



  huffHeap h = huffHeap();
  for (int i = 32; i <= 126; i++){
    if (freqArr[i] != 0){
      numDifChars++;
      c = (char) i;
      huffNode* temp = new huffNode();
      temp->character = c;
      temp->freq = freqArr[i];
      h.insert(temp);
    }
  }
  /*
  for (int i = 1; i <= h.size; i++){
    if (h.heap[i]->character == ' '){
      cout <<"space" << endl;
    }else{
      cout << h.heap[i]->character << endl;
    }
    
    }*/
 
  
  while (h.size > 1){
    huffNode* left = h.deleteMin();
    huffNode* right = h.deleteMin();
    huffNode* tmp = new huffNode();

    tmp->left = left;
    tmp->right = right;
    tmp->character = '$';
    tmp->freq = left->freq + right->freq;

    h.insert(tmp);
    //cout << "-------------------------------------here";
    //p(tmp);
    
  }
  


  
huffNode* node = h.heap[1];
//p(node);
unordered_map<char, string> encoding;
int compressedBits = 0;
 float cost = 0;
 
 for (int i = 32; i <= 126; i++){
    if (freqArr[i] != 0){
      char c = (char) i;
      encoding[c] = buildTable(node, c);
      compressedBits += (freqArr[i] * (encoding[c].size()));
      cost +=  ((float)freqArr[i] * (encoding[c].size()))/filestring.size();
      if (c == ' '){
	cout << "space " << encoding[c]<< endl; 
      }else{
	cout << c << " " << encoding[c] << endl;
      }
    }
 }


  
  cout << "--------------------------------------------------" << endl;
 

  char q;
  while ( (q = fgetc(fp)) != EOF){
    cout << encoding[q] << " ";
    }

  cout << endl;

  fclose(fp);
  /*
  cout << "--------------------------------------------------" << endl;
  cout << "There are a total of " << filestring.size() << " symbols that are encoded." << endl;
  cout << "There are " << numDifChars << " distinct symbols used." << endl;
  cout << "There were " << 8*filestring.size() << " bits in the original file. " << endl;
  cout << "There were " << compressedBits << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " <<((float)8*filestring.size())/compressedBits << "." << endl;
  cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
  // cout << filestring << endl;

  */
 cout << "--------------------------------------------------" << endl;
  
 
 
  
  return 0;

  
}

string buildTable(huffNode* n, char c){
  if (n->character == c){
    return "";
  }else if (find(n->left, c)){
    return "0" + buildTable(n->left, c);
  }else if (find(n->right, c)){
    return "1" + buildTable(n->right, c);
  }else{
    return "";
  }
  
}


bool find(huffNode *n, char c){
  bool l = false;
  bool r = false;
  if (n == NULL){
    return false;
  }else if (n->character == c){
    return true;
  }else{
    l = find(n->left, c);
    r = find(n->right, c);
    return (l || r);
  }
}



void p(huffNode* n){
  if (n!=NULL){
    if(n->character != ' '){

      cout << n->character << " : " << n->freq << endl;
    }else{
      cout << "space : " << n->freq << endl;
    }

    p(n->left);
    p(n->right);
  }

}





