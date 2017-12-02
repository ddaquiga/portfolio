/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef GRAPH
#define GRAPH

#include <vector>
#include <list>
#include <iostream>
#include "vertex.h"

using namespace std;

class Graph
{
private:
  vector<Vertex> vertices;

public:
  void addEdge( char, char );
  int vertexCount();
  bool vertexExists( char );
  bool pathExists( char, char );
  unsigned getVertexIndex( char );
};

#endif