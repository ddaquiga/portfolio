#ifndef __GRAPH_TEST_H__
#define __GRAPH_TEST_H__

#include <iostream>
#include <string>
#include <vector>

#include "graph.h"

using namespace std;

class GraphTest {
  public:
    GraphTest();
    ~GraphTest();
    void run_tests();

  private:
    Graph * graph;

    void print_header( string );
    void print_test( bool );

    void check_vertex_add_edge();
    void check_vertex_exists();
    void check_correct_vertex_count();
    void check_if_path_exists_true();
    void check_if_path_exists_false();
};

#endif