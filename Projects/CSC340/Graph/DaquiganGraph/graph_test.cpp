#include "graph_test.h"

GraphTest::GraphTest() {
  graph = new Graph();

  graph->addEdge( 'P', 'R' );
  graph->addEdge( 'P', 'W' );
  graph->addEdge( 'Q', 'X' );
  graph->addEdge( 'R', 'X' );
  graph->addEdge( 'S', 'T' );
  graph->addEdge( 'T', 'W' );
  graph->addEdge( 'W', 'S' );
  graph->addEdge( 'W', 'Y' );
  graph->addEdge( 'Y', 'R' );
  graph->addEdge( 'R', 'Z' );
}

GraphTest::~GraphTest() {
  delete graph;
}

void GraphTest::run_tests() {
  check_vertex_add_edge();

  check_vertex_exists();
  check_correct_vertex_count();

  check_if_path_exists_true();
  check_if_path_exists_false();
}

void GraphTest::check_vertex_add_edge() {
  print_header( "Checking add edges to Vertex" );

  Vertex v( 'V' );

  v.addEdge( 'A' );
  v.addEdge( 'B' );

  vector<char> edges = v.getEdges();
  bool hasA = false, hasB = false;

  for( int i = 0; i < edges.size(); i++ ) {
    if( edges[ i ] == 'A' ) {
      hasA = true;
    }
    if( edges[ i ] == 'B' ) {
      hasB = true;
    }
  }

  print_test( edges.size() == 2 && hasA && hasB );
}

void GraphTest::check_vertex_exists() {
  print_header( "Checking if vertices exist" );

  print_header( "Checking for vertex P" );
  print_test( graph->vertexExists( 'P' ) );

  print_header( "Checking for vertex Q" );
  print_test( graph->vertexExists( 'Q' ) );

  print_header( "Checking for vertex R" );
  print_test( graph->vertexExists( 'R' ) );

  print_header( "Checking for vertex S" );
  print_test( graph->vertexExists( 'S' ) );

  print_header( "Checking for vertex T" );
  print_test( graph->vertexExists( 'T' ) );

  print_header( "Checking for vertex W" );
  print_test( graph->vertexExists( 'W' ) );

  print_header( "Checking for vertex X" );
  print_test( graph->vertexExists( 'X' ) );

  print_header( "Checking for vertex Y" );
  print_test( graph->vertexExists( 'Y' ) );

  print_header( "Checking for vertex Z" );
  print_test( graph->vertexExists( 'Z' ) );
}

void GraphTest::check_correct_vertex_count() {
  print_header( "Checking for correct vertex count" );

  print_test( graph->vertexCount() == 9 );
}

void GraphTest::check_if_path_exists_true() {
  print_header( "Checking if path exists from P to T");

  print_test( graph->pathExists( 'P', 'T') );
}

void GraphTest::check_if_path_exists_false() {
  print_header( "Checking if path exists from Q to T");

  // Sort of kludgy, but need to create a failing test, and a zero vertex
  // graph would pass this test
  print_test( ! graph->pathExists( 'Q', 'T') && graph->vertexCount() == 9 );
}

void GraphTest::print_header( string message ) {
  cout << "--- Testing " << message << " ---" << endl;
}

void GraphTest::print_test( bool result ) {
  if( result ) {
    cout << "PASS";
  } else {
    cout << "FAIL";
  }

  cout << endl;
}