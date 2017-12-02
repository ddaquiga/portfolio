/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "vertex.h"

Vertex::Vertex( char newLabel ){
  label = newLabel;
}

void Vertex::addEdge( char newEdge ){
  edges.push_back( newEdge );
}

char Vertex::getLabel(){
  return label;
}

const vector<char> Vertex::getEdges(){
  return edges;
}
