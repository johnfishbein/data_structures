//jhf5my -- John Fishbein -- 17 Wednesday April 2019
//traveling.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE
    
    string start = dests[0];
    dests.erase(dests.begin());
    float mindist = computeDistance(me, start, dests);
    
    vector<string> finalpath;
    for (int i = 0; i < dests.size(); i++){
      finalpath.push_back(dests[i]);
    }
    sort(dests.begin(), dests.end());
    while(next_permutation(dests.begin(), dests.end())){
      //printRoute(start,dests);
      float curdist = computeDistance(me, start, dests);
      //cout << curdist << endl;
      if (curdist < mindist){
	mindist = curdist;
	finalpath.clear();
	for (int i = 0; i < dests.size(); i++){
	  finalpath.push_back(dests[i]);
	}
      }  
    }
    

    cout << "The fastest route is " << mindist<< endl;
    printRoute(start, finalpath);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float totaldist = me.getDistance(start, dests[0]);
  for (int i = 0; i < dests.size()-1; i++){
    totaldist += me.getDistance(dests[i], dests[i+1]);
  }
  totaldist += me.getDistance(dests[dests.size()-1], start);
  return totaldist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  cout << start;
  for (int i = 0; i < dests.size(); i++){
    cout << " -> " << dests[i];
  }
  cout << " -> " << start << endl;
  
}
