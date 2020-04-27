//jhf5my -- John Fishbein -- Friday 1 March 2019
//wordPuzzle.cpp
//word search portion big theta(n^2) ---(based on size of table)
/*
 *words.txt
 *3x3 - 0 seconds
 *4x7 - 0 seconds
 *5x8 - 0 seconds
 *50x50 - 0.08 seconds
 *140x70 - 0.296 seconds
 *250x250 - 2.174 seconds
 *
 *words2.txt
 *300x300 - 2.473 seconds
 */

#include <string>
#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <stdlib.h>
#include "timer.h"

using namespace std;
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
vector<string> out;

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols);
int wordsInDict(string filename);
void readInDict(string filename, hashTable &table);
void printCorrect(int row, int col, int dir, string word);



int main(int argc, char* argv[]){
  // cout << argc;
  string gridFile = "";
  string dictFile = "";
  if (argc == 3){
    dictFile = argv[1];
    gridFile = argv[2];
  }
  
  // cout << dictFile << endl;
  //cout << gridFile << endl;
  int numWords = wordsInDict(dictFile);
  // cout <<"NumWords: "<< numWords << endl;
  hashTable table = hashTable(numWords);
  string word;
  ifstream file(dictFile.c_str());
  if (file.is_open()){
    while(getline(file, word)){
    table.put(word);
    }
  file.close();
  }
 // to hold the number of rows and cols in the input file
  int rows, cols;
    // attempt to read in the file
  bool result = readInGrid (gridFile, rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    int maxLen = 23;

    
    //time stuff
    timer t;
    t.start();
    char * x;
    int numFound = 0;
    for (int curRow = 0; curRow < rows; curRow++){
      for (int curCol = 0; curCol < cols; curCol++){
	for (int dir = 0; dir < 8; dir++){
	  for (int len = 3; len < maxLen; len++){
	    x = getWordInGrid(curRow, curCol, dir, len, rows, cols);
	    // cout << x;
	    string curWord(x);
	    //cout << curWord << endl;
 	    if (table.find(curWord) && curWord.length() == len){
	      printCorrect(curRow, curCol, dir, curWord);
	      numFound++;
	    }
	  }
	}
      }
    }
    t.stop();
    for (int i = 0; i < out.size(); i++){
      cout << out[i] << endl;
    }
    
    cout << numFound << " words found"<<endl;
    // cout << t.getTime() *1000<< endl;
    //cout << "Found all words in " << t.getTime() << " seconds" << endl;
    cout <<(int)(t.getTime() * 1000) << endl;
    // cout << "num collisions: " << table.size << endl; 
    return 0;
}


void printCorrect(int row, int col, int dir, string word){
  string direction;
  switch (dir){
  case 0:
    direction = "N"; 
    break;
    
  case 1:
    direction = "NE";
    break;
    
  case 2:
    direction = "E";
    break;
    
  case 3:
    direction = "SE";
    break;
    
  case 4:
    direction = "S";
    break;
    
  case 5:
    direction = "SW";
    break;
    
  case 6:
    direction = "W";
    break;
    
  case 7:
    direction = "NW";
    break;
  }
  if (direction.length() == 1){
    direction += " ";
  }
  
  
  string output = direction + "(" + to_string(row)+ ", " + to_string(col) + "):    " + word;
  //cout << output<< endl;
  out.push_back(output);
}





int wordsInDict(string filename){
  string word;
  int num = 0;
  ifstream file(filename.c_str());
  if (!file.is_open()){
    return 0;
  }
  
  while(getline(file, word)){
    num++;
    //cout << numWords << endl;
    //cout << numWords << word << endl;
  }
  //cout <<"done" << numWords;
  file.close();
  return num;  
}




bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line

    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
  // cout << startRow << startCol << dir << len << numRows << numCols;
  
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}


