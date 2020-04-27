//jhf5my -- John Fishbein -- 15 Monday April 2019
//huffmandec.cpp



// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.
#include "huffNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

// main(): we want to use parameters
void insertToTree(string prefix, char c, huffNode* node);
huffNode* root;
void print2D(huffNode *root);
void print2DUtil(huffNode *root, int space); 


int main (int argc, char **argv) {
  root = new huffNode();
  // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    while ( true ) {
        char g;
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
	g = character[0];
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '"
	//   << prefix << "'" << endl;

	insertToTree(prefix, g, root);
	
    }
    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    //cout << endl;
    //cout << "-----------------------------------------------------------"<< endl;
    //cout << "DECODED MESSAGE" << endl;
    //cout << endl;
    
    huffNode* current = root;
    string output = "";
    for (int i = 0; i <= allbits.size(); i++){
      if (current->left == NULL){
	output += current->character;
	current = root;
      }

      if (allbits[i] == '0'){
	current = current->left;
      }else{
	current = current->right;
      }
      
    }

    cout << output << endl;

}


void insertToTree(string prefix, char c, huffNode* node){
  for (int i = 0; i < prefix.size()-1; i++){
    if (prefix[i] == '1'){

      if (node->right != NULL){
	node = node->right;
      }else{
	node->right = new huffNode();
	node = node->right;
      }
      

    }else{

      if (node->left != NULL){
	node = node->left;
      }else{
	node->left = new huffNode();
	node = node->left;
      }
    }
  }

  if (prefix[prefix.size()-1] == '1'){
    node->right = new huffNode();
    node->right->character = c;
  }else{
    node->left = new huffNode();
    node->left->character = c;
  }
  
  
}


