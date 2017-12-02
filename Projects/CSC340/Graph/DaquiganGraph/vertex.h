/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef VERTEX
#define VERTEX

#include <vector>

using namespace std;

class Vertex
{
private:
  vector<char> edges;
  char label;

public:
  Vertex( char );
  void addEdge( char );
  char getLabel();
  const vector<char> getEdges();
};

#endif