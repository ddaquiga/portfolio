/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "graph.h"

void Graph::addEdge( char src, char dest ){
  if ( !vertexExists( src ) ){
    vertices.push_back( Vertex( src ) );
  }

  if ( !vertexExists( dest ) ){
    vertices.push_back( Vertex( dest ) );
  }

  for ( unsigned i = 0; i < vertices.size(); i++ ){
    if ( vertices[i].getLabel() == src ){
      vertices[i].addEdge( dest );
    }
  }
}

int Graph::vertexCount(){
  return vertices.size();
}

bool Graph::vertexExists( char label ){
  for ( unsigned i=0; i<vertices.size(); i++ ){
    if ( label == vertices[i].getLabel() ){
      return true;
    }
  }
  return false;
}

bool Graph::pathExists( char src, char dest ){
  if ( !vertexExists( src ) | !vertexExists( dest ) ){
    return false;
  }

  if ( src == dest ){
    return true;
  }

  bool *visited = new bool[ vertices.size() ];

  for ( unsigned i = 0; i < vertices.size(); i++ ){
    visited[i] = false;
  }

  list<char> queue;

  visited[ getVertexIndex( src ) ] = true;
  queue.push_back( src);

  while ( !queue.empty() ){
    src = queue.front();
    queue.pop_front();

    for ( unsigned i = 0; i < vertices[ getVertexIndex( src ) ].getEdges().size(); i++ ){
      if ( vertices[ getVertexIndex( src ) ].getEdges()[i] == dest ){
        return true;
      }

      if ( !visited[ getVertexIndex( vertices[ getVertexIndex( src ) ].getEdges()[i] ) ] ){
        
        visited[ getVertexIndex( vertices[ getVertexIndex( src ) ].getEdges()[i] ) ] = true;
        queue.push_back( vertices[ getVertexIndex( src ) ].getEdges()[i] );
      }
    }
  }

  return false;

}

unsigned Graph::getVertexIndex( char label ){
  for ( unsigned i = 0; i < vertices.size(); i++ ){
    if ( vertices[i].getLabel() == label ){
      return i;
    }
  }
  return -1;
}
