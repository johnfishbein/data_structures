//jhf5my -- John Fishbein -- 17 Wednesday April 2019
//topological.cpp

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

/**
 *class vertex
 *verticies in a directed graph
 *@field printed - used for topological sort
 *@field name - string representing vertex
 *@field indegree p - how many other verticies have edges pointing to it 
 */
class vertex {
public:
  vertex();
  vertex(string n);
  bool printed;
  string name;
  int indegree; 
  vector<string> edges;
};
vertex::vertex(){}
vertex::vertex(string n){
  indegree = 0;
  name = n;
  printed =false;
}
  
/**
 * class dgraph
 * directed graph
 *@field verts - maps strings to verticies they represent
 *@field size - number of verticies
 *@field allnames - vector of all names in the graph
 *@method insertVertex see insertVertex(string s)
 *@method insertEdge see insertEdge(string v1, string v2)
 */
class dgraph {
public:
  map<string, vertex> verts;
  int size;
  dgraph();
  void insertVertex(string s);
  void insertEdge(string v1, string v2);
  vector<string> allnames;
};
  
dgraph::dgraph(){
  size=0;
}
/*@method insertVertex adds a vertex to the graph
 *@param s name to be inserted into graph
 */
void dgraph::insertVertex(string s){
  vertex v(s);
  verts[s] = v;
  size++;
  allnames.push_back(s);
}
/*@method insertEdge adds edge between two verticies
 *@param v1 base vertex where the edge is pointing from
 *@param v2 ending vertex where the edge points to
 */
void dgraph::insertEdge(string v1, string v2){
  bool v1ingraph = false;
  bool v2ingraph = false;
  
  for (map<string, vertex>::iterator iter = verts.begin(); iter != verts.end(); ++iter){
    string key = iter->first;
    if (key == v1){v1ingraph =true;}
    if (key == v2){v2ingraph =true;}
  }

  if (!v1ingraph){
    insertVertex(v1);
  }
  if (!v2ingraph){
    insertVertex(v2);
  }

  verts[v1].edges.push_back(v2);
  verts[v2].indegree++;
}

void topsort(dgraph d);


int main (int argc, char **argv) {
  if (argc != 2) {
    cout << "ERROR" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);
  if (!file.is_open()){
    cout << "ERROR" << endl;
    exit(2);
  }

  
  string s1, s2;
  dgraph d;
  
  while (true){
  file >> s1;
  file >> s2;

  if (s1 == "0" && s2 == "0")
    break;

  d.insertEdge(s1,s2);
  //cout << s1 << " " << s2 << endl;
  
  }
  
  file.close();

  topsort(d);
  /*
  for (vector<string>::iterator iter = d.allnames.begin(); iter != d.allnames.end(); ++ iter){
    cout << *iter<< endl;
    cout << d.verts[*iter].name << endl;
    cout << d.verts[*iter].indegree << endl;
  }
  */
  return 0;
}


/*@method topsort performs a topological sort on dgraph and prints result
 *@param d graph on which topological sort should be performed
 *
 *
 */
void topsort(dgraph d){
  string s;
  for (int i =0; i < d.size; i++) {
    for (vector<string>::iterator iter = d.allnames.begin(); iter != d.allnames.end(); ++iter){
      if (d.verts[*iter].indegree == 0 && !d.verts[*iter].printed){

	s = *iter;
	
      }
    }

    for (vector<string>::iterator iter = d.verts[s].edges.begin();
	 iter != d.verts[s].edges.end(); ++iter){
      d.verts[*iter].indegree--;
    }
    cout << d.verts[s].name << " ";
    d.verts[s].printed = true;
  }
  cout << endl;
}

